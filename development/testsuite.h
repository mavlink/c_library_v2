/** @file
 *    @brief MAVLink comm protocol testsuite generated from development.xml
 *    @see https://mavlink.io/en/
 */
#pragma once
#ifndef DEVELOPMENT_TESTSUITE_H
#define DEVELOPMENT_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_development(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_common(system_id, component_id, last_msg);
    mavlink_test_development(system_id, component_id, last_msg);
}
#endif

#include "../common/testsuite.h"


static void mavlink_test_param_ack_transaction(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_PARAM_ACK_TRANSACTION >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_param_ack_transaction_t packet_in = {
        17.0,17,84,"GHIJKLMNOPQRSTU",199,10
    };
    mavlink_param_ack_transaction_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.param_value = packet_in.param_value;
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        packet1.param_type = packet_in.param_type;
        packet1.param_result = packet_in.param_result;
        
        mav_array_memcpy(packet1.param_id, packet_in.param_id, sizeof(char)*16);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_PARAM_ACK_TRANSACTION_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_PARAM_ACK_TRANSACTION_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_param_ack_transaction_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_param_ack_transaction_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_param_ack_transaction_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.param_id , packet1.param_value , packet1.param_type , packet1.param_result );
    mavlink_msg_param_ack_transaction_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_param_ack_transaction_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.param_id , packet1.param_value , packet1.param_type , packet1.param_result );
    mavlink_msg_param_ack_transaction_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_param_ack_transaction_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_param_ack_transaction_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.param_id , packet1.param_value , packet1.param_type , packet1.param_result );
    mavlink_msg_param_ack_transaction_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("PARAM_ACK_TRANSACTION") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_PARAM_ACK_TRANSACTION) != NULL);
#endif
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
        17.0,45.0,17651,163,230
    };
    mavlink_airspeed_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.airspeed = packet_in.airspeed;
        packet1.raw_press = packet_in.raw_press;
        packet1.temperature = packet_in.temperature;
        packet1.id = packet_in.id;
        packet1.flags = packet_in.flags;
        
        
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
    mavlink_msg_airspeed_pack(system_id, component_id, &msg , packet1.id , packet1.airspeed , packet1.temperature , packet1.raw_press , packet1.flags );
    mavlink_msg_airspeed_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_airspeed_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.id , packet1.airspeed , packet1.temperature , packet1.raw_press , packet1.flags );
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
    mavlink_msg_airspeed_send(MAVLINK_COMM_1 , packet1.id , packet1.airspeed , packet1.temperature , packet1.raw_press , packet1.flags );
    mavlink_msg_airspeed_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("AIRSPEED") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_AIRSPEED) != NULL);
#endif
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

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("WIFI_NETWORK_INFO") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_WIFI_NETWORK_INFO) != NULL);
#endif
}

static void mavlink_test_set_velocity_limits(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_SET_VELOCITY_LIMITS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_set_velocity_limits_t packet_in = {
        17.0,45.0,73.0,41,108
    };
    mavlink_set_velocity_limits_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.horizontal_speed_limit = packet_in.horizontal_speed_limit;
        packet1.vertical_speed_limit = packet_in.vertical_speed_limit;
        packet1.yaw_rate_limit = packet_in.yaw_rate_limit;
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_SET_VELOCITY_LIMITS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_SET_VELOCITY_LIMITS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_set_velocity_limits_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_set_velocity_limits_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_set_velocity_limits_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.horizontal_speed_limit , packet1.vertical_speed_limit , packet1.yaw_rate_limit );
    mavlink_msg_set_velocity_limits_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_set_velocity_limits_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.horizontal_speed_limit , packet1.vertical_speed_limit , packet1.yaw_rate_limit );
    mavlink_msg_set_velocity_limits_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_set_velocity_limits_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_set_velocity_limits_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.horizontal_speed_limit , packet1.vertical_speed_limit , packet1.yaw_rate_limit );
    mavlink_msg_set_velocity_limits_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("SET_VELOCITY_LIMITS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_SET_VELOCITY_LIMITS) != NULL);
#endif
}

static void mavlink_test_velocity_limits(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_VELOCITY_LIMITS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_velocity_limits_t packet_in = {
        17.0,45.0,73.0
    };
    mavlink_velocity_limits_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.horizontal_speed_limit = packet_in.horizontal_speed_limit;
        packet1.vertical_speed_limit = packet_in.vertical_speed_limit;
        packet1.yaw_rate_limit = packet_in.yaw_rate_limit;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_VELOCITY_LIMITS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_VELOCITY_LIMITS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_velocity_limits_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_velocity_limits_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_velocity_limits_pack(system_id, component_id, &msg , packet1.horizontal_speed_limit , packet1.vertical_speed_limit , packet1.yaw_rate_limit );
    mavlink_msg_velocity_limits_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_velocity_limits_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.horizontal_speed_limit , packet1.vertical_speed_limit , packet1.yaw_rate_limit );
    mavlink_msg_velocity_limits_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_velocity_limits_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_velocity_limits_send(MAVLINK_COMM_1 , packet1.horizontal_speed_limit , packet1.vertical_speed_limit , packet1.yaw_rate_limit );
    mavlink_msg_velocity_limits_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("VELOCITY_LIMITS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_VELOCITY_LIMITS) != NULL);
#endif
}

static void mavlink_test_figure_eight_execution_status(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_FIGURE_EIGHT_EXECUTION_STATUS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_figure_eight_execution_status_t packet_in = {
        93372036854775807ULL,73.0,101.0,129.0,963498504,963498712,213.0,101
    };
    mavlink_figure_eight_execution_status_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_usec = packet_in.time_usec;
        packet1.major_radius = packet_in.major_radius;
        packet1.minor_radius = packet_in.minor_radius;
        packet1.orientation = packet_in.orientation;
        packet1.x = packet_in.x;
        packet1.y = packet_in.y;
        packet1.z = packet_in.z;
        packet1.frame = packet_in.frame;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_FIGURE_EIGHT_EXECUTION_STATUS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_FIGURE_EIGHT_EXECUTION_STATUS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_figure_eight_execution_status_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_figure_eight_execution_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_figure_eight_execution_status_pack(system_id, component_id, &msg , packet1.time_usec , packet1.major_radius , packet1.minor_radius , packet1.orientation , packet1.frame , packet1.x , packet1.y , packet1.z );
    mavlink_msg_figure_eight_execution_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_figure_eight_execution_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_usec , packet1.major_radius , packet1.minor_radius , packet1.orientation , packet1.frame , packet1.x , packet1.y , packet1.z );
    mavlink_msg_figure_eight_execution_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_figure_eight_execution_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_figure_eight_execution_status_send(MAVLINK_COMM_1 , packet1.time_usec , packet1.major_radius , packet1.minor_radius , packet1.orientation , packet1.frame , packet1.x , packet1.y , packet1.z );
    mavlink_msg_figure_eight_execution_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("FIGURE_EIGHT_EXECUTION_STATUS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_FIGURE_EIGHT_EXECUTION_STATUS) != NULL);
#endif
}

static void mavlink_test_battery_status_v2(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_BATTERY_STATUS_V2 >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_battery_status_v2_t packet_in = {
        17.0,45.0,73.0,101.0,963498296,18275,199,10
    };
    mavlink_battery_status_v2_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.voltage = packet_in.voltage;
        packet1.current = packet_in.current;
        packet1.capacity_consumed = packet_in.capacity_consumed;
        packet1.capacity_remaining = packet_in.capacity_remaining;
        packet1.status_flags = packet_in.status_flags;
        packet1.temperature = packet_in.temperature;
        packet1.id = packet_in.id;
        packet1.percent_remaining = packet_in.percent_remaining;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_BATTERY_STATUS_V2_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_BATTERY_STATUS_V2_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_battery_status_v2_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_battery_status_v2_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_battery_status_v2_pack(system_id, component_id, &msg , packet1.id , packet1.temperature , packet1.voltage , packet1.current , packet1.capacity_consumed , packet1.capacity_remaining , packet1.percent_remaining , packet1.status_flags );
    mavlink_msg_battery_status_v2_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_battery_status_v2_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.id , packet1.temperature , packet1.voltage , packet1.current , packet1.capacity_consumed , packet1.capacity_remaining , packet1.percent_remaining , packet1.status_flags );
    mavlink_msg_battery_status_v2_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_battery_status_v2_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_battery_status_v2_send(MAVLINK_COMM_1 , packet1.id , packet1.temperature , packet1.voltage , packet1.current , packet1.capacity_consumed , packet1.capacity_remaining , packet1.percent_remaining , packet1.status_flags );
    mavlink_msg_battery_status_v2_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("BATTERY_STATUS_V2") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_BATTERY_STATUS_V2) != NULL);
#endif
}

static void mavlink_test_fuel_status(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_FUEL_STATUS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_fuel_status_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,963498504,77,144
    };
    mavlink_fuel_status_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.maximum_fuel = packet_in.maximum_fuel;
        packet1.consumed_fuel = packet_in.consumed_fuel;
        packet1.remaining_fuel = packet_in.remaining_fuel;
        packet1.flow_rate = packet_in.flow_rate;
        packet1.temperature = packet_in.temperature;
        packet1.fuel_type = packet_in.fuel_type;
        packet1.id = packet_in.id;
        packet1.percent_remaining = packet_in.percent_remaining;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_FUEL_STATUS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_FUEL_STATUS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fuel_status_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_fuel_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fuel_status_pack(system_id, component_id, &msg , packet1.id , packet1.maximum_fuel , packet1.consumed_fuel , packet1.remaining_fuel , packet1.percent_remaining , packet1.flow_rate , packet1.temperature , packet1.fuel_type );
    mavlink_msg_fuel_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fuel_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.id , packet1.maximum_fuel , packet1.consumed_fuel , packet1.remaining_fuel , packet1.percent_remaining , packet1.flow_rate , packet1.temperature , packet1.fuel_type );
    mavlink_msg_fuel_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_fuel_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fuel_status_send(MAVLINK_COMM_1 , packet1.id , packet1.maximum_fuel , packet1.consumed_fuel , packet1.remaining_fuel , packet1.percent_remaining , packet1.flow_rate , packet1.temperature , packet1.fuel_type );
    mavlink_msg_fuel_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("FUEL_STATUS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_FUEL_STATUS) != NULL);
#endif
}

static void mavlink_test_group_start(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_GROUP_START >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_group_start_t packet_in = {
        93372036854775807ULL,963497880,963498088
    };
    mavlink_group_start_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_usec = packet_in.time_usec;
        packet1.group_id = packet_in.group_id;
        packet1.mission_checksum = packet_in.mission_checksum;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_GROUP_START_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_GROUP_START_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_group_start_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_group_start_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_group_start_pack(system_id, component_id, &msg , packet1.group_id , packet1.mission_checksum , packet1.time_usec );
    mavlink_msg_group_start_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_group_start_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.group_id , packet1.mission_checksum , packet1.time_usec );
    mavlink_msg_group_start_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_group_start_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_group_start_send(MAVLINK_COMM_1 , packet1.group_id , packet1.mission_checksum , packet1.time_usec );
    mavlink_msg_group_start_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("GROUP_START") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_GROUP_START) != NULL);
#endif
}

static void mavlink_test_group_end(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_GROUP_END >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_group_end_t packet_in = {
        93372036854775807ULL,963497880,963498088
    };
    mavlink_group_end_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_usec = packet_in.time_usec;
        packet1.group_id = packet_in.group_id;
        packet1.mission_checksum = packet_in.mission_checksum;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_GROUP_END_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_GROUP_END_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_group_end_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_group_end_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_group_end_pack(system_id, component_id, &msg , packet1.group_id , packet1.mission_checksum , packet1.time_usec );
    mavlink_msg_group_end_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_group_end_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.group_id , packet1.mission_checksum , packet1.time_usec );
    mavlink_msg_group_end_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_group_end_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_group_end_send(MAVLINK_COMM_1 , packet1.group_id , packet1.mission_checksum , packet1.time_usec );
    mavlink_msg_group_end_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("GROUP_END") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_GROUP_END) != NULL);
#endif
}

static void mavlink_test_radio_rc_channels(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_RADIO_RC_CHANNELS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_radio_rc_channels_t packet_in = {
        963497464,17443,151,218,29,{ 17703, 17704, 17705, 17706, 17707, 17708, 17709, 17710, 17711, 17712, 17713, 17714, 17715, 17716, 17717, 17718, 17719, 17720, 17721, 17722, 17723, 17724, 17725, 17726, 17727, 17728, 17729, 17730, 17731, 17732, 17733, 17734 }
    };
    mavlink_radio_rc_channels_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_last_update_ms = packet_in.time_last_update_ms;
        packet1.flags = packet_in.flags;
        packet1.target_system = packet_in.target_system;
        packet1.target_component = packet_in.target_component;
        packet1.count = packet_in.count;
        
        mav_array_memcpy(packet1.channels, packet_in.channels, sizeof(int16_t)*32);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_RADIO_RC_CHANNELS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_RADIO_RC_CHANNELS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_radio_rc_channels_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_radio_rc_channels_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_radio_rc_channels_pack(system_id, component_id, &msg , packet1.target_system , packet1.target_component , packet1.time_last_update_ms , packet1.flags , packet1.count , packet1.channels );
    mavlink_msg_radio_rc_channels_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_radio_rc_channels_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.target_component , packet1.time_last_update_ms , packet1.flags , packet1.count , packet1.channels );
    mavlink_msg_radio_rc_channels_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_radio_rc_channels_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_radio_rc_channels_send(MAVLINK_COMM_1 , packet1.target_system , packet1.target_component , packet1.time_last_update_ms , packet1.flags , packet1.count , packet1.channels );
    mavlink_msg_radio_rc_channels_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("RADIO_RC_CHANNELS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_RADIO_RC_CHANNELS) != NULL);
#endif
}

static void mavlink_test_available_modes(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_AVAILABLE_MODES >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_available_modes_t packet_in = {
        963497464,963497672,29,96,163,"LMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRS"
    };
    mavlink_available_modes_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.custom_mode = packet_in.custom_mode;
        packet1.properties = packet_in.properties;
        packet1.number_modes = packet_in.number_modes;
        packet1.mode_index = packet_in.mode_index;
        packet1.standard_mode = packet_in.standard_mode;
        
        mav_array_memcpy(packet1.mode_name, packet_in.mode_name, sizeof(char)*35);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_AVAILABLE_MODES_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_AVAILABLE_MODES_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_available_modes_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_available_modes_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_available_modes_pack(system_id, component_id, &msg , packet1.number_modes , packet1.mode_index , packet1.standard_mode , packet1.custom_mode , packet1.properties , packet1.mode_name );
    mavlink_msg_available_modes_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_available_modes_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.number_modes , packet1.mode_index , packet1.standard_mode , packet1.custom_mode , packet1.properties , packet1.mode_name );
    mavlink_msg_available_modes_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_available_modes_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_available_modes_send(MAVLINK_COMM_1 , packet1.number_modes , packet1.mode_index , packet1.standard_mode , packet1.custom_mode , packet1.properties , packet1.mode_name );
    mavlink_msg_available_modes_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("AVAILABLE_MODES") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_AVAILABLE_MODES) != NULL);
#endif
}

static void mavlink_test_current_mode(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_CURRENT_MODE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_current_mode_t packet_in = {
        963497464,963497672,29
    };
    mavlink_current_mode_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.custom_mode = packet_in.custom_mode;
        packet1.intended_custom_mode = packet_in.intended_custom_mode;
        packet1.standard_mode = packet_in.standard_mode;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_CURRENT_MODE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_CURRENT_MODE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_current_mode_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_current_mode_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_current_mode_pack(system_id, component_id, &msg , packet1.standard_mode , packet1.custom_mode , packet1.intended_custom_mode );
    mavlink_msg_current_mode_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_current_mode_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.standard_mode , packet1.custom_mode , packet1.intended_custom_mode );
    mavlink_msg_current_mode_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_current_mode_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_current_mode_send(MAVLINK_COMM_1 , packet1.standard_mode , packet1.custom_mode , packet1.intended_custom_mode );
    mavlink_msg_current_mode_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("CURRENT_MODE") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_CURRENT_MODE) != NULL);
#endif
}

static void mavlink_test_available_modes_monitor(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_AVAILABLE_MODES_MONITOR >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_available_modes_monitor_t packet_in = {
        5
    };
    mavlink_available_modes_monitor_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.seq = packet_in.seq;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_AVAILABLE_MODES_MONITOR_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_AVAILABLE_MODES_MONITOR_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_available_modes_monitor_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_available_modes_monitor_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_available_modes_monitor_pack(system_id, component_id, &msg , packet1.seq );
    mavlink_msg_available_modes_monitor_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_available_modes_monitor_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.seq );
    mavlink_msg_available_modes_monitor_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_available_modes_monitor_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_available_modes_monitor_send(MAVLINK_COMM_1 , packet1.seq );
    mavlink_msg_available_modes_monitor_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("AVAILABLE_MODES_MONITOR") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_AVAILABLE_MODES_MONITOR) != NULL);
#endif
}

static void mavlink_test_gnss_integrity(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_GNSS_INTEGRITY >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_gnss_integrity_t packet_in = {
        963497464,17443,17547,29,96,163,230,41,108,175,242,53
    };
    mavlink_gnss_integrity_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.system_errors = packet_in.system_errors;
        packet1.raim_hfom = packet_in.raim_hfom;
        packet1.raim_vfom = packet_in.raim_vfom;
        packet1.id = packet_in.id;
        packet1.authentication_state = packet_in.authentication_state;
        packet1.jamming_state = packet_in.jamming_state;
        packet1.spoofing_state = packet_in.spoofing_state;
        packet1.raim_state = packet_in.raim_state;
        packet1.corrections_quality = packet_in.corrections_quality;
        packet1.system_status_summary = packet_in.system_status_summary;
        packet1.gnss_signal_quality = packet_in.gnss_signal_quality;
        packet1.post_processing_quality = packet_in.post_processing_quality;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_GNSS_INTEGRITY_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_GNSS_INTEGRITY_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gnss_integrity_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_gnss_integrity_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gnss_integrity_pack(system_id, component_id, &msg , packet1.id , packet1.system_errors , packet1.authentication_state , packet1.jamming_state , packet1.spoofing_state , packet1.raim_state , packet1.raim_hfom , packet1.raim_vfom , packet1.corrections_quality , packet1.system_status_summary , packet1.gnss_signal_quality , packet1.post_processing_quality );
    mavlink_msg_gnss_integrity_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gnss_integrity_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.id , packet1.system_errors , packet1.authentication_state , packet1.jamming_state , packet1.spoofing_state , packet1.raim_state , packet1.raim_hfom , packet1.raim_vfom , packet1.corrections_quality , packet1.system_status_summary , packet1.gnss_signal_quality , packet1.post_processing_quality );
    mavlink_msg_gnss_integrity_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_gnss_integrity_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gnss_integrity_send(MAVLINK_COMM_1 , packet1.id , packet1.system_errors , packet1.authentication_state , packet1.jamming_state , packet1.spoofing_state , packet1.raim_state , packet1.raim_hfom , packet1.raim_vfom , packet1.corrections_quality , packet1.system_status_summary , packet1.gnss_signal_quality , packet1.post_processing_quality );
    mavlink_msg_gnss_integrity_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("GNSS_INTEGRITY") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_GNSS_INTEGRITY) != NULL);
#endif
}

static void mavlink_test_target_absolute(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TARGET_ABSOLUTE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_target_absolute_t packet_in = {
        93372036854775807ULL,963497880,963498088,129.0,{ 157.0, 158.0, 159.0 },{ 241.0, 242.0, 243.0 },{ 325.0, 326.0, 327.0, 328.0 },{ 437.0, 438.0, 439.0 },{ 521.0, 522.0 },{ 577.0, 578.0, 579.0 },{ 661.0, 662.0, 663.0 },61,128
    };
    mavlink_target_absolute_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        packet1.lat = packet_in.lat;
        packet1.lon = packet_in.lon;
        packet1.alt = packet_in.alt;
        packet1.id = packet_in.id;
        packet1.sensor_capabilities = packet_in.sensor_capabilities;
        
        mav_array_memcpy(packet1.vel, packet_in.vel, sizeof(float)*3);
        mav_array_memcpy(packet1.acc, packet_in.acc, sizeof(float)*3);
        mav_array_memcpy(packet1.q_target, packet_in.q_target, sizeof(float)*4);
        mav_array_memcpy(packet1.rates, packet_in.rates, sizeof(float)*3);
        mav_array_memcpy(packet1.position_std, packet_in.position_std, sizeof(float)*2);
        mav_array_memcpy(packet1.vel_std, packet_in.vel_std, sizeof(float)*3);
        mav_array_memcpy(packet1.acc_std, packet_in.acc_std, sizeof(float)*3);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TARGET_ABSOLUTE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TARGET_ABSOLUTE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_target_absolute_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_target_absolute_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_target_absolute_pack(system_id, component_id, &msg , packet1.timestamp , packet1.id , packet1.sensor_capabilities , packet1.lat , packet1.lon , packet1.alt , packet1.vel , packet1.acc , packet1.q_target , packet1.rates , packet1.position_std , packet1.vel_std , packet1.acc_std );
    mavlink_msg_target_absolute_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_target_absolute_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.timestamp , packet1.id , packet1.sensor_capabilities , packet1.lat , packet1.lon , packet1.alt , packet1.vel , packet1.acc , packet1.q_target , packet1.rates , packet1.position_std , packet1.vel_std , packet1.acc_std );
    mavlink_msg_target_absolute_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_target_absolute_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_target_absolute_send(MAVLINK_COMM_1 , packet1.timestamp , packet1.id , packet1.sensor_capabilities , packet1.lat , packet1.lon , packet1.alt , packet1.vel , packet1.acc , packet1.q_target , packet1.rates , packet1.position_std , packet1.vel_std , packet1.acc_std );
    mavlink_msg_target_absolute_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("TARGET_ABSOLUTE") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_TARGET_ABSOLUTE) != NULL);
#endif
}

static void mavlink_test_target_relative(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TARGET_RELATIVE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_target_relative_t packet_in = {
        93372036854775807ULL,73.0,101.0,129.0,{ 157.0, 158.0, 159.0 },241.0,{ 269.0, 270.0, 271.0, 272.0 },{ 381.0, 382.0, 383.0, 384.0 },209,20,87
    };
    mavlink_target_relative_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        packet1.x = packet_in.x;
        packet1.y = packet_in.y;
        packet1.z = packet_in.z;
        packet1.yaw_std = packet_in.yaw_std;
        packet1.id = packet_in.id;
        packet1.frame = packet_in.frame;
        packet1.type = packet_in.type;
        
        mav_array_memcpy(packet1.pos_std, packet_in.pos_std, sizeof(float)*3);
        mav_array_memcpy(packet1.q_target, packet_in.q_target, sizeof(float)*4);
        mav_array_memcpy(packet1.q_sensor, packet_in.q_sensor, sizeof(float)*4);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TARGET_RELATIVE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TARGET_RELATIVE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_target_relative_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_target_relative_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_target_relative_pack(system_id, component_id, &msg , packet1.timestamp , packet1.id , packet1.frame , packet1.x , packet1.y , packet1.z , packet1.pos_std , packet1.yaw_std , packet1.q_target , packet1.q_sensor , packet1.type );
    mavlink_msg_target_relative_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_target_relative_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.timestamp , packet1.id , packet1.frame , packet1.x , packet1.y , packet1.z , packet1.pos_std , packet1.yaw_std , packet1.q_target , packet1.q_sensor , packet1.type );
    mavlink_msg_target_relative_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_target_relative_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_target_relative_send(MAVLINK_COMM_1 , packet1.timestamp , packet1.id , packet1.frame , packet1.x , packet1.y , packet1.z , packet1.pos_std , packet1.yaw_std , packet1.q_target , packet1.q_sensor , packet1.type );
    mavlink_msg_target_relative_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("TARGET_RELATIVE") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_TARGET_RELATIVE) != NULL);
#endif
}

static void mavlink_test_development(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_param_ack_transaction(system_id, component_id, last_msg);
    mavlink_test_airspeed(system_id, component_id, last_msg);
    mavlink_test_wifi_network_info(system_id, component_id, last_msg);
    mavlink_test_set_velocity_limits(system_id, component_id, last_msg);
    mavlink_test_velocity_limits(system_id, component_id, last_msg);
    mavlink_test_figure_eight_execution_status(system_id, component_id, last_msg);
    mavlink_test_battery_status_v2(system_id, component_id, last_msg);
    mavlink_test_fuel_status(system_id, component_id, last_msg);
    mavlink_test_group_start(system_id, component_id, last_msg);
    mavlink_test_group_end(system_id, component_id, last_msg);
    mavlink_test_radio_rc_channels(system_id, component_id, last_msg);
    mavlink_test_available_modes(system_id, component_id, last_msg);
    mavlink_test_current_mode(system_id, component_id, last_msg);
    mavlink_test_available_modes_monitor(system_id, component_id, last_msg);
    mavlink_test_gnss_integrity(system_id, component_id, last_msg);
    mavlink_test_target_absolute(system_id, component_id, last_msg);
    mavlink_test_target_relative(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // DEVELOPMENT_TESTSUITE_H
