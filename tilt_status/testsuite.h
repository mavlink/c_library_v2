/** @file
 *    @brief MAVLink comm protocol testsuite generated from tilt_status.xml
 *    @see https://mavlink.io/en/
 */
#pragma once
#ifndef TILT_STATUS_TESTSUITE_H
#define TILT_STATUS_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_tilt_status(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_common(system_id, component_id, last_msg);
    mavlink_test_tilt_status(system_id, component_id, last_msg);
}
#endif

#include "../common/testsuite.h"


static void mavlink_test_tilt_status(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TILT_STATUS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_tilt_status_t packet_in = {
        963497464,{ 45.0, 46.0, 47.0, 48.0 },{ 157.0, 158.0, 159.0, 160.0 },{ 269.0, 270.0, 271.0, 272.0 },{ 963500168, 963500169, 963500170, 963500171 },{ 493.0, 494.0, 495.0, 496.0 },{ 21603, 21604, 21605, 21606 },{ 25, 26, 27, 28 }
    };
    mavlink_tilt_status_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_boot_ms = packet_in.time_boot_ms;
        
        mav_array_memcpy(packet1.angle, packet_in.angle, sizeof(float)*4);
        mav_array_memcpy(packet1.angular_vel, packet_in.angular_vel, sizeof(float)*4);
        mav_array_memcpy(packet1.voltage, packet_in.voltage, sizeof(float)*4);
        mav_array_memcpy(packet1.current, packet_in.current, sizeof(int32_t)*4);
        mav_array_memcpy(packet1.temperature, packet_in.temperature, sizeof(float)*4);
        mav_array_memcpy(packet1.realtime_tick, packet_in.realtime_tick, sizeof(uint16_t)*4);
        mav_array_memcpy(packet1.error_status, packet_in.error_status, sizeof(uint8_t)*4);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TILT_STATUS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TILT_STATUS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tilt_status_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_tilt_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tilt_status_pack(system_id, component_id, &msg , packet1.time_boot_ms , packet1.realtime_tick , packet1.error_status , packet1.angle , packet1.angular_vel , packet1.voltage , packet1.current , packet1.temperature );
    mavlink_msg_tilt_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tilt_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_boot_ms , packet1.realtime_tick , packet1.error_status , packet1.angle , packet1.angular_vel , packet1.voltage , packet1.current , packet1.temperature );
    mavlink_msg_tilt_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_tilt_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tilt_status_send(MAVLINK_COMM_1 , packet1.time_boot_ms , packet1.realtime_tick , packet1.error_status , packet1.angle , packet1.angular_vel , packet1.voltage , packet1.current , packet1.temperature );
    mavlink_msg_tilt_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("TILT_STATUS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_TILT_STATUS) != NULL);
#endif
}

static void mavlink_test_tilt_status(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_tilt_status(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // TILT_STATUS_TESTSUITE_H
