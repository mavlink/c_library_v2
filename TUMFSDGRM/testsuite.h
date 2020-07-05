/** @file
 *    @brief MAVLink comm protocol testsuite generated from TUMFSDGRM.xml
 *    @see http://qgroundcontrol.org/mavlink/
 */
#pragma once
#ifndef TUMFSDGRM_TESTSUITE_H
#define TUMFSDGRM_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_TUMFSDGRM(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_common(system_id, component_id, last_msg);
    mavlink_test_TUMFSDGRM(system_id, component_id, last_msg);
}
#endif

#include "../common/testsuite.h"


static void mavlink_test_actuator_cmd(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_ACTUATOR_CMD >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_actuator_cmd_t packet_in = {
        17235,17339,17443,17547,17651,17755,17859,17963
    };
    mavlink_actuator_cmd_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.actuator1 = packet_in.actuator1;
        packet1.actuator2 = packet_in.actuator2;
        packet1.actuator3 = packet_in.actuator3;
        packet1.actuator4 = packet_in.actuator4;
        packet1.actuator5 = packet_in.actuator5;
        packet1.actuator6 = packet_in.actuator6;
        packet1.actuator7 = packet_in.actuator7;
        packet1.actuator8 = packet_in.actuator8;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_ACTUATOR_CMD_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_ACTUATOR_CMD_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_actuator_cmd_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_actuator_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_actuator_cmd_pack(system_id, component_id, &msg , packet1.actuator1 , packet1.actuator2 , packet1.actuator3 , packet1.actuator4 , packet1.actuator5 , packet1.actuator6 , packet1.actuator7 , packet1.actuator8 );
    mavlink_msg_actuator_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_actuator_cmd_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.actuator1 , packet1.actuator2 , packet1.actuator3 , packet1.actuator4 , packet1.actuator5 , packet1.actuator6 , packet1.actuator7 , packet1.actuator8 );
    mavlink_msg_actuator_cmd_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_actuator_cmd_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_actuator_cmd_send(MAVLINK_COMM_1 , packet1.actuator1 , packet1.actuator2 , packet1.actuator3 , packet1.actuator4 , packet1.actuator5 , packet1.actuator6 , packet1.actuator7 , packet1.actuator8 );
    mavlink_msg_actuator_cmd_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_TUMFSDGRM(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_actuator_cmd(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // TUMFSDGRM_TESTSUITE_H
