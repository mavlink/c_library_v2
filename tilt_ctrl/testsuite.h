/** @file
 *    @brief MAVLink comm protocol testsuite generated from tilt_ctrl.xml
 *    @see https://mavlink.io/en/
 */
#pragma once
#ifndef TILT_CTRL_TESTSUITE_H
#define TILT_CTRL_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_tilt_ctrl(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_common(system_id, component_id, last_msg);
    mavlink_test_tilt_ctrl(system_id, component_id, last_msg);
}
#endif

#include "../common/testsuite.h"


static void mavlink_test_tilt_angle(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TILT_ANGLE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_tilt_angle_t packet_in = {
        963497464,45.0,73.0,101.0,129.0
    };
    mavlink_tilt_angle_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_boot_ms = packet_in.time_boot_ms;
        packet1.tilt_fl = packet_in.tilt_fl;
        packet1.tilt_fr = packet_in.tilt_fr;
        packet1.tilt_rl = packet_in.tilt_rl;
        packet1.tilt_rr = packet_in.tilt_rr;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TILT_ANGLE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TILT_ANGLE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tilt_angle_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_tilt_angle_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tilt_angle_pack(system_id, component_id, &msg , packet1.time_boot_ms , packet1.tilt_fl , packet1.tilt_fr , packet1.tilt_rl , packet1.tilt_rr );
    mavlink_msg_tilt_angle_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tilt_angle_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_boot_ms , packet1.tilt_fl , packet1.tilt_fr , packet1.tilt_rl , packet1.tilt_rr );
    mavlink_msg_tilt_angle_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_tilt_angle_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tilt_angle_send(MAVLINK_COMM_1 , packet1.time_boot_ms , packet1.tilt_fl , packet1.tilt_fr , packet1.tilt_rl , packet1.tilt_rr );
    mavlink_msg_tilt_angle_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("TILT_ANGLE") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_TILT_ANGLE) != NULL);
#endif
}

static void mavlink_test_tilt_ctrl(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_tilt_angle(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // TILT_CTRL_TESTSUITE_H
