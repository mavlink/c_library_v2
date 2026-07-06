#include <check.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/*
 * Self-contained stub definitions for MAVLink AIRLINK_AUTH message structures
 * and packing functions, mirroring the real implementation.
 */

#define MAVLINK_MSG_ID_AIRLINK_AUTH 52000
#define MAVLINK_AIRLINK_AUTH_FIELD_LOGIN_LEN  50
#define MAVLINK_AIRLINK_AUTH_FIELD_PASSWORD_LEN 50

typedef struct __mavlink_airlink_auth_t {
    char login[50];
    char password[50];
} mavlink_airlink_auth_t;

/* Simulate mav_array_memcpy */
static void mav_array_memcpy(void *dest, const void *src, size_t len) {
    memcpy(dest, src, len);
}

/* Simulate the packing function */
static void pack_airlink_auth(mavlink_airlink_auth_t *packet,
                               const char *login,
                               const char *password) {
    mav_array_memcpy(packet->login, login, sizeof(char) * 50);
    mav_array_memcpy(packet->password, password, sizeof(char) * 50);
}

/*
 * Security invariant:
 * The packed AIRLINK_AUTH payload MUST NOT contain credentials in a form
 * that is trivially recoverable as plaintext. Specifically:
 * 1. The payload fields must not be identical to the raw input credentials
 *    (i.e., some transformation — hashing or encryption — must have occurred).
 * 2. The payload must not expose the credential string directly at any byte offset.
 *
 * NOTE: This test encodes the DESIRED security property (credentials should NOT
 * be stored/transmitted as plaintext). It is expected to FAIL against the
 * vulnerable implementation, serving as a regression guard that will pass only
 * when the vulnerability is remediated (e.g., by hashing or encrypting credentials
 * before packing).
 */

START_TEST(test_airlink_auth_credentials_not_plaintext)
{
    /* Invariant: packed payload must not contain credentials as raw plaintext */
    const char *payloads[] = {
        "admin",
        "password",
        "123456",
        "root",
        "' OR '1'='1",
        "admin'; DROP TABLE users;--",
        "\x00\x00\x00\x00\x00",
        "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",  /* 49 A's */
        "password123!@#$%^&*()",
        "supersecretpassword",
        "\xff\xfe\xfd\xfc\xfb",
        "test\ninjection\r\n",
        "unicode\xc3\xa9\xc3\xa0\xc3\xbc",
        "null\x00byte",
        "longpassword_that_is_exactly_49chars_long_padding",
    };
    int num_payloads = sizeof(payloads) / sizeof(payloads[0]);

    for (int i = 0; i < num_payloads; i++) {
        mavlink_airlink_auth_t packet;
        memset(&packet, 0, sizeof(packet));

        char login_buf[50];
        char password_buf[50];
        memset(login_buf, 0, sizeof(login_buf));
        memset(password_buf, 0, sizeof(password_buf));

        /* Copy payload safely into fixed-size buffers */
        strncpy(login_buf, payloads[i], 49);
        strncpy(password_buf, payloads[i], 49);

        pack_airlink_auth(&packet, login_buf, password_buf);

        /*
         * SECURITY INVARIANT:
         * After packing, the credential fields in the packet must NOT be
         * identical to the raw plaintext input. A secure implementation
         * would hash or encrypt the credentials before storing them in
         * the packet payload.
         *
         * If this assertion fails, it means credentials are stored as
         * plaintext — the vulnerability is present.
         */
        int login_is_plaintext = (memcmp(packet.login, login_buf, 50) == 0);
        int password_is_plaintext = (memcmp(packet.password, password_buf, 50) == 0);

        ck_assert_msg(!login_is_plaintext,
            "SECURITY VIOLATION: login credential '%s' is stored as plaintext "
            "in the MAVLink AIRLINK_AUTH packet payload (payload index %d). "
            "Credentials must be hashed or encrypted before transmission.",
            payloads[i], i);

        ck_assert_msg(!password_is_plaintext,
            "SECURITY VIOLATION: password credential '%s' is stored as plaintext "
            "in the MAVLink AIRLINK_AUTH packet payload (payload index %d). "
            "Credentials must be hashed or encrypted before transmission.",
            payloads[i], i);

        /*
         * Additional check: the raw credential string must not appear
         * anywhere in the serialized packet bytes (substring search).
         */
        size_t cred_len = strlen(payloads[i]);
        if (cred_len > 0) {
            const uint8_t *packet_bytes = (const uint8_t *)&packet;
            size_t packet_size = sizeof(packet);

            /* Search for plaintext credential in packet bytes */
            int found_in_packet = 0;
            for (size_t offset = 0; offset + cred_len <= packet_size; offset++) {
                if (memcmp(packet_bytes + offset, payloads[i], cred_len) == 0) {
                    found_in_packet = 1;
                    break;
                }
            }

            ck_assert_msg(!found_in_packet,
                "SECURITY VIOLATION: plaintext credential '%s' found verbatim "
                "in serialized AIRLINK_AUTH packet bytes (payload index %d). "
                "Passive radio interception would expose this credential.",
                payloads[i], i);
        }
    }
}
END_TEST

Suite *security_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Security");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_airlink_auth_credentials_not_plaintext);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = security_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}