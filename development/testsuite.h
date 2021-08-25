/** @file
 *    @brief MAVLink comm protocol testsuite generated from development.xml
 *    @see http://qgroundcontrol.org/mavlink/
 */
#pragma once
#ifndef DEVELOPMENT_TESTSUITE_H
#define DEVELOPMENT_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_standard(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_development(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_standard(system_id, component_id, last_msg);
    mavlink_test_development(system_id, component_id, last_msg);
}
#endif

#include "../standard/testsuite.h"


static void mavlink_test_mission_checksum(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_MISSION_CHECKSUM >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_mission_checksum_t packet_in = {
        963497464,17
    };
    mavlink_mission_checksum_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.checksum = packet_in.checksum;
        packet1.mission_type = packet_in.mission_type;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_MISSION_CHECKSUM_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_MISSION_CHECKSUM_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mission_checksum_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_mission_checksum_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mission_checksum_pack(system_id, component_id, &msg , packet1.mission_type , packet1.checksum );
    mavlink_msg_mission_checksum_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mission_checksum_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.mission_type , packet1.checksum );
    mavlink_msg_mission_checksum_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_mission_checksum_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mission_checksum_send(MAVLINK_COMM_1 , packet1.mission_type , packet1.checksum );
    mavlink_msg_mission_checksum_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_airspeed(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_AIRSPEED >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_airspeed_t packet_in = {
        17.0,45.0,73.0,101.0,18067,187,254
    };
    mavlink_airspeed_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.airspeed = packet_in.airspeed;
        packet1.press_diff = packet_in.press_diff;
        packet1.press_static = packet_in.press_static;
        packet1.error = packet_in.error;
        packet1.temperature = packet_in.temperature;
        packet1.id = packet_in.id;
        packet1.type = packet_in.type;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_AIRSPEED_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_AIRSPEED_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_airspeed_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_airspeed_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_airspeed_pack(system_id, component_id, &msg , packet1.id , packet1.airspeed , packet1.temperature , packet1.press_diff , packet1.press_static , packet1.error , packet1.type );
    mavlink_msg_airspeed_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_airspeed_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.id , packet1.airspeed , packet1.temperature , packet1.press_diff , packet1.press_static , packet1.error , packet1.type );
    mavlink_msg_airspeed_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_airspeed_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_airspeed_send(MAVLINK_COMM_1 , packet1.id , packet1.airspeed , packet1.temperature , packet1.press_diff , packet1.press_static , packet1.error , packet1.type );
    mavlink_msg_airspeed_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_wifi_network_info(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WIFI_NETWORK_INFO >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wifi_network_info_t packet_in = {
        17235,"CDEFGHIJKLMNOPQRSTUVWXYZABCDEFG",235,46,113
    };
    mavlink_wifi_network_info_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.data_rate = packet_in.data_rate;
        packet1.channel_id = packet_in.channel_id;
        packet1.signal_quality = packet_in.signal_quality;
        packet1.security = packet_in.security;
        
        mav_array_memcpy(packet1.ssid, packet_in.ssid, sizeof(char)*32);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WIFI_NETWORK_INFO_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WIFI_NETWORK_INFO_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wifi_network_info_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wifi_network_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wifi_network_info_pack(system_id, component_id, &msg , packet1.ssid , packet1.channel_id , packet1.signal_quality , packet1.data_rate , packet1.security );
    mavlink_msg_wifi_network_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wifi_network_info_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.ssid , packet1.channel_id , packet1.signal_quality , packet1.data_rate , packet1.security );
    mavlink_msg_wifi_network_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wifi_network_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wifi_network_info_send(MAVLINK_COMM_1 , packet1.ssid , packet1.channel_id , packet1.signal_quality , packet1.data_rate , packet1.security );
    mavlink_msg_wifi_network_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_development(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_mission_checksum(system_id, component_id, last_msg);
    mavlink_test_airspeed(system_id, component_id, last_msg);
    mavlink_test_wifi_network_info(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // DEVELOPMENT_TESTSUITE_H
