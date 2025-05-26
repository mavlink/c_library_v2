/** @file
 *    @brief MAVLink comm protocol testsuite generated from auterion.xml
 *    @see https://mavlink.io/en/
 */
#pragma once
#ifndef AUTERION_TESTSUITE_H
#define AUTERION_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_development(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_auterion(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_development(system_id, component_id, last_msg);
    mavlink_test_auterion(system_id, component_id, last_msg);
}
#endif

#include "../development/testsuite.h"


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

static void mavlink_test_beacon_position(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_BEACON_POSITION >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_beacon_position_t packet_in = {
        963497464,963497672,963497880,101.0,129.0,963498504,963498712,89
    };
    mavlink_beacon_position_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.beacon_id = packet_in.beacon_id;
        packet1.latitude = packet_in.latitude;
        packet1.longitude = packet_in.longitude;
        packet1.altitude = packet_in.altitude;
        packet1.distance = packet_in.distance;
        packet1.delay = packet_in.delay;
        packet1.link_quality = packet_in.link_quality;
        packet1.gps_status = packet_in.gps_status;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_BEACON_POSITION_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_BEACON_POSITION_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_beacon_position_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_beacon_position_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_beacon_position_pack(system_id, component_id, &msg , packet1.beacon_id , packet1.latitude , packet1.longitude , packet1.altitude , packet1.distance , packet1.delay , packet1.gps_status , packet1.link_quality );
    mavlink_msg_beacon_position_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_beacon_position_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.beacon_id , packet1.latitude , packet1.longitude , packet1.altitude , packet1.distance , packet1.delay , packet1.gps_status , packet1.link_quality );
    mavlink_msg_beacon_position_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_beacon_position_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_beacon_position_send(MAVLINK_COMM_1 , packet1.beacon_id , packet1.latitude , packet1.longitude , packet1.altitude , packet1.distance , packet1.delay , packet1.gps_status , packet1.link_quality );
    mavlink_msg_beacon_position_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("BEACON_POSITION") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_BEACON_POSITION) != NULL);
#endif
}

static void mavlink_test_radiation_detector_counts(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_radiation_detector_counts_t packet_in = {
        123.0,93372036854776311ULL,93372036854776815ULL,963498712,963498920
    };
    mavlink_radiation_detector_counts_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        packet1.counts = packet_in.counts;
        packet1.integration_time_usec = packet_in.integration_time_usec;
        packet1.serial_no = packet_in.serial_no;
        packet1.rate = packet_in.rate;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_radiation_detector_counts_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_radiation_detector_counts_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_radiation_detector_counts_pack(system_id, component_id, &msg , packet1.serial_no , packet1.timestamp , packet1.counts , packet1.rate , packet1.integration_time_usec );
    mavlink_msg_radiation_detector_counts_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_radiation_detector_counts_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.serial_no , packet1.timestamp , packet1.counts , packet1.rate , packet1.integration_time_usec );
    mavlink_msg_radiation_detector_counts_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_radiation_detector_counts_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_radiation_detector_counts_send(MAVLINK_COMM_1 , packet1.serial_no , packet1.timestamp , packet1.counts , packet1.rate , packet1.integration_time_usec );
    mavlink_msg_radiation_detector_counts_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("RADIATION_DETECTOR_COUNTS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS) != NULL);
#endif
}

static void mavlink_test_radiation_detector_spectrum(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_radiation_detector_spectrum_t packet_in = {
        963497464,17,84,{ 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143 }
    };
    mavlink_radiation_detector_spectrum_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.serial_no = packet_in.serial_no;
        packet1.msg_no = packet_in.msg_no;
        packet1.seq_no = packet_in.seq_no;
        
        mav_array_memcpy(packet1.segment, packet_in.segment, sizeof(uint8_t)*249);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_radiation_detector_spectrum_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_radiation_detector_spectrum_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_radiation_detector_spectrum_pack(system_id, component_id, &msg , packet1.serial_no , packet1.msg_no , packet1.seq_no , packet1.segment );
    mavlink_msg_radiation_detector_spectrum_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_radiation_detector_spectrum_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.serial_no , packet1.msg_no , packet1.seq_no , packet1.segment );
    mavlink_msg_radiation_detector_spectrum_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_radiation_detector_spectrum_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_radiation_detector_spectrum_send(MAVLINK_COMM_1 , packet1.serial_no , packet1.msg_no , packet1.seq_no , packet1.segment );
    mavlink_msg_radiation_detector_spectrum_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("RADIATION_DETECTOR_SPECTRUM") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM) != NULL);
#endif
}

static void mavlink_test_radiation_detector_cps(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_radiation_detector_cps_t packet_in = {
        123.0,963497880,963498088,129.0
    };
    mavlink_radiation_detector_cps_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        packet1.serial_no = packet_in.serial_no;
        packet1.cps = packet_in.cps;
        packet1.dt = packet_in.dt;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_radiation_detector_cps_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_radiation_detector_cps_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_radiation_detector_cps_pack(system_id, component_id, &msg , packet1.serial_no , packet1.timestamp , packet1.cps , packet1.dt );
    mavlink_msg_radiation_detector_cps_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_radiation_detector_cps_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.serial_no , packet1.timestamp , packet1.cps , packet1.dt );
    mavlink_msg_radiation_detector_cps_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_radiation_detector_cps_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_radiation_detector_cps_send(MAVLINK_COMM_1 , packet1.serial_no , packet1.timestamp , packet1.cps , packet1.dt );
    mavlink_msg_radiation_detector_cps_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("RADIATION_DETECTOR_CPS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS) != NULL);
#endif
}

static void mavlink_test_tracker_status(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TRACKER_STATUS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_tracker_status_t packet_in = {
        963497464,17443,151
    };
    mavlink_tracker_status_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.tracked_object_id = packet_in.tracked_object_id;
        packet1.number_objects_detected = packet_in.number_objects_detected;
        packet1.tracker_status = packet_in.tracker_status;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TRACKER_STATUS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TRACKER_STATUS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tracker_status_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_tracker_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tracker_status_pack(system_id, component_id, &msg , packet1.tracker_status , packet1.number_objects_detected , packet1.tracked_object_id );
    mavlink_msg_tracker_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tracker_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.tracker_status , packet1.number_objects_detected , packet1.tracked_object_id );
    mavlink_msg_tracker_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_tracker_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tracker_status_send(MAVLINK_COMM_1 , packet1.tracker_status , packet1.number_objects_detected , packet1.tracked_object_id );
    mavlink_msg_tracker_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("TRACKER_STATUS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_TRACKER_STATUS) != NULL);
#endif
}

static void mavlink_test_tracker_detection_2d(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TRACKER_DETECTION_2D >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_tracker_detection_2d_t packet_in = {
        93372036854775807ULL,93372036854776311ULL,963498296,963498504,963498712,963498920,241.0,269.0,297.0,325.0,19731,19835,19939,20043,173,240
    };
    mavlink_tracker_detection_2d_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.img_ts = packet_in.img_ts;
        packet1.img_id = packet_in.img_id;
        packet1.object_id = packet_in.object_id;
        packet1.class_id = packet_in.class_id;
        packet1.lat = packet_in.lat;
        packet1.lon = packet_in.lon;
        packet1.alt = packet_in.alt;
        packet1.vel_n = packet_in.vel_n;
        packet1.vel_e = packet_in.vel_e;
        packet1.vel_up = packet_in.vel_up;
        packet1.bbox_top_left_x = packet_in.bbox_top_left_x;
        packet1.bbox_top_left_y = packet_in.bbox_top_left_y;
        packet1.bbox_bot_right_x = packet_in.bbox_bot_right_x;
        packet1.bbox_bot_right_y = packet_in.bbox_bot_right_y;
        packet1.tracking_status = packet_in.tracking_status;
        packet1.confidence = packet_in.confidence;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TRACKER_DETECTION_2D_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TRACKER_DETECTION_2D_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tracker_detection_2d_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_tracker_detection_2d_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tracker_detection_2d_pack(system_id, component_id, &msg , packet1.img_ts , packet1.img_id , packet1.object_id , packet1.class_id , packet1.tracking_status , packet1.confidence , packet1.bbox_top_left_x , packet1.bbox_top_left_y , packet1.bbox_bot_right_x , packet1.bbox_bot_right_y , packet1.lat , packet1.lon , packet1.alt , packet1.vel_n , packet1.vel_e , packet1.vel_up );
    mavlink_msg_tracker_detection_2d_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tracker_detection_2d_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.img_ts , packet1.img_id , packet1.object_id , packet1.class_id , packet1.tracking_status , packet1.confidence , packet1.bbox_top_left_x , packet1.bbox_top_left_y , packet1.bbox_bot_right_x , packet1.bbox_bot_right_y , packet1.lat , packet1.lon , packet1.alt , packet1.vel_n , packet1.vel_e , packet1.vel_up );
    mavlink_msg_tracker_detection_2d_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_tracker_detection_2d_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tracker_detection_2d_send(MAVLINK_COMM_1 , packet1.img_ts , packet1.img_id , packet1.object_id , packet1.class_id , packet1.tracking_status , packet1.confidence , packet1.bbox_top_left_x , packet1.bbox_top_left_y , packet1.bbox_bot_right_x , packet1.bbox_bot_right_y , packet1.lat , packet1.lon , packet1.alt , packet1.vel_n , packet1.vel_e , packet1.vel_up );
    mavlink_msg_tracker_detection_2d_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("TRACKER_DETECTION_2D") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_TRACKER_DETECTION_2D) != NULL);
#endif
}

static void mavlink_test_joystick_state(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_JOYSTICK_STATE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_joystick_state_t packet_in = {
        93372036854775807ULL,{ 17651, 17652, 17653, 17654, 17655, 17656, 17657, 17658, 17659, 17660 },89,{ 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175 }
    };
    mavlink_joystick_state_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_usec = packet_in.time_usec;
        packet1.type = packet_in.type;
        
        mav_array_memcpy(packet1.axis_value, packet_in.axis_value, sizeof(uint16_t)*10);
        mav_array_memcpy(packet1.button_value, packet_in.button_value, sizeof(uint8_t)*20);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_JOYSTICK_STATE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_JOYSTICK_STATE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_joystick_state_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_joystick_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_joystick_state_pack(system_id, component_id, &msg , packet1.time_usec , packet1.type , packet1.axis_value , packet1.button_value );
    mavlink_msg_joystick_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_joystick_state_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_usec , packet1.type , packet1.axis_value , packet1.button_value );
    mavlink_msg_joystick_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_joystick_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_joystick_state_send(MAVLINK_COMM_1 , packet1.time_usec , packet1.type , packet1.axis_value , packet1.button_value );
    mavlink_msg_joystick_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("JOYSTICK_STATE") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_JOYSTICK_STATE) != NULL);
#endif
}

static void mavlink_test_pixel_to_lla_request(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_pixel_to_lla_request_t packet_in = {
        93372036854775807ULL,93372036854776311ULL,129.0,157.0,77
    };
    mavlink_pixel_to_lla_request_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.uid = packet_in.uid;
        packet1.img_unix_ts = packet_in.img_unix_ts;
        packet1.img_rel_x = packet_in.img_rel_x;
        packet1.img_rel_y = packet_in.img_rel_y;
        packet1.camera_id = packet_in.camera_id;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_pixel_to_lla_request_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_pixel_to_lla_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_pixel_to_lla_request_pack(system_id, component_id, &msg , packet1.camera_id , packet1.uid , packet1.img_unix_ts , packet1.img_rel_x , packet1.img_rel_y );
    mavlink_msg_pixel_to_lla_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_pixel_to_lla_request_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.camera_id , packet1.uid , packet1.img_unix_ts , packet1.img_rel_x , packet1.img_rel_y );
    mavlink_msg_pixel_to_lla_request_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_pixel_to_lla_request_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_pixel_to_lla_request_send(MAVLINK_COMM_1 , packet1.camera_id , packet1.uid , packet1.img_unix_ts , packet1.img_rel_x , packet1.img_rel_y );
    mavlink_msg_pixel_to_lla_request_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("PIXEL_TO_LLA_REQUEST") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST) != NULL);
#endif
}

static void mavlink_test_pixel_to_lla_ack(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_pixel_to_lla_ack_t packet_in = {
        93372036854775807ULL,29,"JKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCD"
    };
    mavlink_pixel_to_lla_ack_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.uid = packet_in.uid;
        packet1.status = packet_in.status;
        
        mav_array_memcpy(packet1.error_message, packet_in.error_message, sizeof(char)*100);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_pixel_to_lla_ack_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_pixel_to_lla_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_pixel_to_lla_ack_pack(system_id, component_id, &msg , packet1.uid , packet1.status , packet1.error_message );
    mavlink_msg_pixel_to_lla_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_pixel_to_lla_ack_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.uid , packet1.status , packet1.error_message );
    mavlink_msg_pixel_to_lla_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_pixel_to_lla_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_pixel_to_lla_ack_send(MAVLINK_COMM_1 , packet1.uid , packet1.status , packet1.error_message );
    mavlink_msg_pixel_to_lla_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("PIXEL_TO_LLA_ACK") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK) != NULL);
#endif
}

static void mavlink_test_pixel_to_lla_result(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_pixel_to_lla_result_t packet_in = {
        93372036854775807ULL,179.0,235.0,291.0,{ 241.0, 242.0, 243.0, 244.0, 245.0, 246.0, 247.0, 248.0, 249.0 },209,"RSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKL"
    };
    mavlink_pixel_to_lla_result_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.uid = packet_in.uid;
        packet1.latitude = packet_in.latitude;
        packet1.longitude = packet_in.longitude;
        packet1.altitude = packet_in.altitude;
        packet1.status = packet_in.status;
        
        mav_array_memcpy(packet1.ned_homography_matrix, packet_in.ned_homography_matrix, sizeof(float)*9);
        mav_array_memcpy(packet1.error_message, packet_in.error_message, sizeof(char)*100);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_pixel_to_lla_result_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_pixel_to_lla_result_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_pixel_to_lla_result_pack(system_id, component_id, &msg , packet1.uid , packet1.status , packet1.latitude , packet1.longitude , packet1.altitude , packet1.ned_homography_matrix , packet1.error_message );
    mavlink_msg_pixel_to_lla_result_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_pixel_to_lla_result_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.uid , packet1.status , packet1.latitude , packet1.longitude , packet1.altitude , packet1.ned_homography_matrix , packet1.error_message );
    mavlink_msg_pixel_to_lla_result_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_pixel_to_lla_result_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_pixel_to_lla_result_send(MAVLINK_COMM_1 , packet1.uid , packet1.status , packet1.latitude , packet1.longitude , packet1.altitude , packet1.ned_homography_matrix , packet1.error_message );
    mavlink_msg_pixel_to_lla_result_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("PIXEL_TO_LLA_RESULT") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT) != NULL);
#endif
}

static void mavlink_test_motor_info(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_MOTOR_INFO >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_motor_info_t packet_in = {
        93372036854775807ULL,17651,163,230
    };
    mavlink_motor_info_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.total_time = packet_in.total_time;
        packet1.temperature = packet_in.temperature;
        packet1.index = packet_in.index;
        packet1.type = packet_in.type;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_MOTOR_INFO_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_MOTOR_INFO_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_motor_info_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_motor_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_motor_info_pack(system_id, component_id, &msg , packet1.index , packet1.type , packet1.total_time , packet1.temperature );
    mavlink_msg_motor_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_motor_info_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.index , packet1.type , packet1.total_time , packet1.temperature );
    mavlink_msg_motor_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_motor_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_motor_info_send(MAVLINK_COMM_1 , packet1.index , packet1.type , packet1.total_time , packet1.temperature );
    mavlink_msg_motor_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("MOTOR_INFO") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_MOTOR_INFO) != NULL);
#endif
}

static void mavlink_test_control_status_report(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_CONTROL_STATUS_REPORT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_control_status_report_t packet_in = {
        5,72
    };
    mavlink_control_status_report_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.current_flight_controller = packet_in.current_flight_controller;
        packet1.current_payload_controller = packet_in.current_payload_controller;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_control_status_report_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_control_status_report_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_control_status_report_pack(system_id, component_id, &msg , packet1.current_flight_controller , packet1.current_payload_controller );
    mavlink_msg_control_status_report_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_control_status_report_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.current_flight_controller , packet1.current_payload_controller );
    mavlink_msg_control_status_report_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_control_status_report_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_control_status_report_send(MAVLINK_COMM_1 , packet1.current_flight_controller , packet1.current_payload_controller );
    mavlink_msg_control_status_report_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("CONTROL_STATUS_REPORT") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_CONTROL_STATUS_REPORT) != NULL);
#endif
}

static void mavlink_test_request_control(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_REQUEST_CONTROL >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_request_control_t packet_in = {
        5,72,"CDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNO","QRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJK"
    };
    mavlink_request_control_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.control_target = packet_in.control_target;
        packet1.request_priority = packet_in.request_priority;
        
        mav_array_memcpy(packet1.requester_id, packet_in.requester_id, sizeof(char)*40);
        mav_array_memcpy(packet1.reason, packet_in.reason, sizeof(char)*100);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_REQUEST_CONTROL_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_REQUEST_CONTROL_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_request_control_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_request_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_request_control_pack(system_id, component_id, &msg , packet1.control_target , packet1.request_priority , packet1.requester_id , packet1.reason );
    mavlink_msg_request_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_request_control_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.control_target , packet1.request_priority , packet1.requester_id , packet1.reason );
    mavlink_msg_request_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_request_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_request_control_send(MAVLINK_COMM_1 , packet1.control_target , packet1.request_priority , packet1.requester_id , packet1.reason );
    mavlink_msg_request_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("REQUEST_CONTROL") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_REQUEST_CONTROL) != NULL);
#endif
}

static void mavlink_test_request_control_ack(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_REQUEST_CONTROL_ACK >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_request_control_ack_t packet_in = {
        5,72
    };
    mavlink_request_control_ack_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.control_target = packet_in.control_target;
        packet1.error_code = packet_in.error_code;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_REQUEST_CONTROL_ACK_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_REQUEST_CONTROL_ACK_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_request_control_ack_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_request_control_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_request_control_ack_pack(system_id, component_id, &msg , packet1.control_target , packet1.error_code );
    mavlink_msg_request_control_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_request_control_ack_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.control_target , packet1.error_code );
    mavlink_msg_request_control_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_request_control_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_request_control_ack_send(MAVLINK_COMM_1 , packet1.control_target , packet1.error_code );
    mavlink_msg_request_control_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("REQUEST_CONTROL_ACK") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_REQUEST_CONTROL_ACK) != NULL);
#endif
}

static void mavlink_test_release_control(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_RELEASE_CONTROL >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_release_control_t packet_in = {
        5
    };
    mavlink_release_control_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.control_target = packet_in.control_target;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_RELEASE_CONTROL_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_RELEASE_CONTROL_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_release_control_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_release_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_release_control_pack(system_id, component_id, &msg , packet1.control_target );
    mavlink_msg_release_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_release_control_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.control_target );
    mavlink_msg_release_control_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_release_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_release_control_send(MAVLINK_COMM_1 , packet1.control_target );
    mavlink_msg_release_control_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("RELEASE_CONTROL") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_RELEASE_CONTROL) != NULL);
#endif
}

static void mavlink_test_request_handoff(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_REQUEST_HANDOFF >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_request_handoff_t packet_in = {
        5,"BCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMN","PQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJ"
    };
    mavlink_request_handoff_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.control_target = packet_in.control_target;
        
        mav_array_memcpy(packet1.requester_id, packet_in.requester_id, sizeof(char)*40);
        mav_array_memcpy(packet1.reason, packet_in.reason, sizeof(char)*100);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_REQUEST_HANDOFF_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_REQUEST_HANDOFF_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_request_handoff_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_request_handoff_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_request_handoff_pack(system_id, component_id, &msg , packet1.control_target , packet1.requester_id , packet1.reason );
    mavlink_msg_request_handoff_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_request_handoff_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.control_target , packet1.requester_id , packet1.reason );
    mavlink_msg_request_handoff_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_request_handoff_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_request_handoff_send(MAVLINK_COMM_1 , packet1.control_target , packet1.requester_id , packet1.reason );
    mavlink_msg_request_handoff_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("REQUEST_HANDOFF") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_REQUEST_HANDOFF) != NULL);
#endif
}

static void mavlink_test_handoff_respond(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_HANDOFF_RESPOND >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_handoff_respond_t packet_in = {
        5,72
    };
    mavlink_handoff_respond_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.control_target = packet_in.control_target;
        packet1.handoff_decision = packet_in.handoff_decision;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_HANDOFF_RESPOND_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_HANDOFF_RESPOND_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_handoff_respond_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_handoff_respond_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_handoff_respond_pack(system_id, component_id, &msg , packet1.control_target , packet1.handoff_decision );
    mavlink_msg_handoff_respond_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_handoff_respond_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.control_target , packet1.handoff_decision );
    mavlink_msg_handoff_respond_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_handoff_respond_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_handoff_respond_send(MAVLINK_COMM_1 , packet1.control_target , packet1.handoff_decision );
    mavlink_msg_handoff_respond_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("HANDOFF_RESPOND") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_HANDOFF_RESPOND) != NULL);
#endif
}

static void mavlink_test_unique_identifier(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_UNIQUE_IDENTIFIER >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_unique_identifier_t packet_in = {
        "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDE"
    };
    mavlink_unique_identifier_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        
        mav_array_memcpy(packet1.uuid, packet_in.uuid, sizeof(char)*32);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_UNIQUE_IDENTIFIER_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_UNIQUE_IDENTIFIER_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_unique_identifier_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_unique_identifier_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_unique_identifier_pack(system_id, component_id, &msg , packet1.uuid );
    mavlink_msg_unique_identifier_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_unique_identifier_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.uuid );
    mavlink_msg_unique_identifier_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_unique_identifier_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_unique_identifier_send(MAVLINK_COMM_1 , packet1.uuid );
    mavlink_msg_unique_identifier_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("UNIQUE_IDENTIFIER") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_UNIQUE_IDENTIFIER) != NULL);
#endif
}

static void mavlink_test_boat_actuator_status(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_boat_actuator_status_t packet_in = {
        93372036854775807ULL,{ 73.0, 74.0, 75.0, 76.0, 77.0, 78.0 },{ 241.0, 242.0, 243.0, 244.0, 245.0, 246.0 },{ 173, 174, 175, 176, 177, 178 },{ 63, 64, 65, 66, 67, 68 }
    };
    mavlink_boat_actuator_status_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_usec = packet_in.time_usec;
        
        mav_array_memcpy(packet1.engine_leg_trim_position, packet_in.engine_leg_trim_position, sizeof(float)*6);
        mav_array_memcpy(packet1.rudder_position, packet_in.rudder_position, sizeof(float)*6);
        mav_array_memcpy(packet1.engine_leg_trim_state, packet_in.engine_leg_trim_state, sizeof(uint8_t)*6);
        mav_array_memcpy(packet1.rudder_state, packet_in.rudder_state, sizeof(uint8_t)*6);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_boat_actuator_status_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_boat_actuator_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_boat_actuator_status_pack(system_id, component_id, &msg , packet1.time_usec , packet1.engine_leg_trim_state , packet1.engine_leg_trim_position , packet1.rudder_state , packet1.rudder_position );
    mavlink_msg_boat_actuator_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_boat_actuator_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_usec , packet1.engine_leg_trim_state , packet1.engine_leg_trim_position , packet1.rudder_state , packet1.rudder_position );
    mavlink_msg_boat_actuator_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_boat_actuator_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_boat_actuator_status_send(MAVLINK_COMM_1 , packet1.time_usec , packet1.engine_leg_trim_state , packet1.engine_leg_trim_position , packet1.rudder_state , packet1.rudder_position );
    mavlink_msg_boat_actuator_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("BOAT_ACTUATOR_STATUS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS) != NULL);
#endif
}

static void mavlink_test_boat_engine_status(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_BOAT_ENGINE_STATUS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_boat_engine_status_t packet_in = {
        93372036854775807ULL,73.0,{ 101.0, 102.0, 103.0, 104.0, 105.0, 106.0 },{ 269.0, 270.0, 271.0, 272.0, 273.0, 274.0 },{ 20355, 20356, 20357, 20358, 20359, 20360 },{ 221, 222, 223, 224, 225, 226 },{ 111, 112, 113, 114, 115, 116 },{ 1, 2, 3, 4, 5, 6 },{ 147, 148, 149, 150, 151, 152 }
    };
    mavlink_boat_engine_status_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_usec = packet_in.time_usec;
        packet1.fuel_consumption_rate = packet_in.fuel_consumption_rate;
        
        mav_array_memcpy(packet1.oil_pressure, packet_in.oil_pressure, sizeof(float)*6);
        mav_array_memcpy(packet1.engine_coolant_temperature, packet_in.engine_coolant_temperature, sizeof(float)*6);
        mav_array_memcpy(packet1.engine_rpm, packet_in.engine_rpm, sizeof(uint16_t)*6);
        mav_array_memcpy(packet1.engine_state, packet_in.engine_state, sizeof(uint8_t)*6);
        mav_array_memcpy(packet1.engine_load, packet_in.engine_load, sizeof(uint8_t)*6);
        mav_array_memcpy(packet1.throttle_position, packet_in.throttle_position, sizeof(uint8_t)*6);
        mav_array_memcpy(packet1.transmission_state, packet_in.transmission_state, sizeof(uint8_t)*6);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_boat_engine_status_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_boat_engine_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_boat_engine_status_pack(system_id, component_id, &msg , packet1.time_usec , packet1.engine_state , packet1.engine_load , packet1.engine_rpm , packet1.fuel_consumption_rate , packet1.oil_pressure , packet1.throttle_position , packet1.engine_coolant_temperature , packet1.transmission_state );
    mavlink_msg_boat_engine_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_boat_engine_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_usec , packet1.engine_state , packet1.engine_load , packet1.engine_rpm , packet1.fuel_consumption_rate , packet1.oil_pressure , packet1.throttle_position , packet1.engine_coolant_temperature , packet1.transmission_state );
    mavlink_msg_boat_engine_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_boat_engine_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_boat_engine_status_send(MAVLINK_COMM_1 , packet1.time_usec , packet1.engine_state , packet1.engine_load , packet1.engine_rpm , packet1.fuel_consumption_rate , packet1.oil_pressure , packet1.throttle_position , packet1.engine_coolant_temperature , packet1.transmission_state );
    mavlink_msg_boat_engine_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("BOAT_ENGINE_STATUS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_BOAT_ENGINE_STATUS) != NULL);
#endif
}

static void mavlink_test_fluid_level(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_FLUID_LEVEL >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_fluid_level_t packet_in = {
        93372036854775807ULL,73.0,101.0,53,120
    };
    mavlink_fluid_level_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_usec = packet_in.time_usec;
        packet1.level = packet_in.level;
        packet1.capacity = packet_in.capacity;
        packet1.instance = packet_in.instance;
        packet1.type = packet_in.type;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_FLUID_LEVEL_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_FLUID_LEVEL_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fluid_level_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_fluid_level_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fluid_level_pack(system_id, component_id, &msg , packet1.time_usec , packet1.instance , packet1.type , packet1.level , packet1.capacity );
    mavlink_msg_fluid_level_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fluid_level_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_usec , packet1.instance , packet1.type , packet1.level , packet1.capacity );
    mavlink_msg_fluid_level_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_fluid_level_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_fluid_level_send(MAVLINK_COMM_1 , packet1.time_usec , packet1.instance , packet1.type , packet1.level , packet1.capacity );
    mavlink_msg_fluid_level_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("FLUID_LEVEL") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_FLUID_LEVEL) != NULL);
#endif
}

static void mavlink_test_vessel_speed(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_VESSEL_SPEED >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_vessel_speed_t packet_in = {
        93372036854775807ULL,73.0,101.0,53,120
    };
    mavlink_vessel_speed_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_usec = packet_in.time_usec;
        packet1.speed_water_referenced = packet_in.speed_water_referenced;
        packet1.speed_ground_referenced = packet_in.speed_ground_referenced;
        packet1.speed_water_referenced_type = packet_in.speed_water_referenced_type;
        packet1.speed_direction = packet_in.speed_direction;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_VESSEL_SPEED_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_VESSEL_SPEED_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_vessel_speed_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_vessel_speed_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_vessel_speed_pack(system_id, component_id, &msg , packet1.time_usec , packet1.speed_water_referenced , packet1.speed_ground_referenced , packet1.speed_water_referenced_type , packet1.speed_direction );
    mavlink_msg_vessel_speed_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_vessel_speed_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_usec , packet1.speed_water_referenced , packet1.speed_ground_referenced , packet1.speed_water_referenced_type , packet1.speed_direction );
    mavlink_msg_vessel_speed_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_vessel_speed_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_vessel_speed_send(MAVLINK_COMM_1 , packet1.time_usec , packet1.speed_water_referenced , packet1.speed_ground_referenced , packet1.speed_water_referenced_type , packet1.speed_direction );
    mavlink_msg_vessel_speed_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("VESSEL_SPEED") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_VESSEL_SPEED) != NULL);
#endif
}

static void mavlink_test_water_depth_raw(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WATER_DEPTH_RAW >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_water_depth_raw_t packet_in = {
        93372036854775807ULL,73.0,101.0,129.0
    };
    mavlink_water_depth_raw_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_usec = packet_in.time_usec;
        packet1.depth = packet_in.depth;
        packet1.offset = packet_in.offset;
        packet1.range = packet_in.range;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WATER_DEPTH_RAW_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WATER_DEPTH_RAW_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_water_depth_raw_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_water_depth_raw_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_water_depth_raw_pack(system_id, component_id, &msg , packet1.time_usec , packet1.depth , packet1.offset , packet1.range );
    mavlink_msg_water_depth_raw_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_water_depth_raw_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_usec , packet1.depth , packet1.offset , packet1.range );
    mavlink_msg_water_depth_raw_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_water_depth_raw_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_water_depth_raw_send(MAVLINK_COMM_1 , packet1.time_usec , packet1.depth , packet1.offset , packet1.range );
    mavlink_msg_water_depth_raw_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("WATER_DEPTH_RAW") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_WATER_DEPTH_RAW) != NULL);
#endif
}

static void mavlink_test_wind_data_raw(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_WIND_DATA_RAW >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_wind_data_raw_t packet_in = {
        93372036854775807ULL,73.0,101.0,53
    };
    mavlink_wind_data_raw_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_usec = packet_in.time_usec;
        packet1.wind_speed = packet_in.wind_speed;
        packet1.wind_angle = packet_in.wind_angle;
        packet1.reference = packet_in.reference;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_WIND_DATA_RAW_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_WIND_DATA_RAW_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wind_data_raw_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_wind_data_raw_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wind_data_raw_pack(system_id, component_id, &msg , packet1.time_usec , packet1.reference , packet1.wind_speed , packet1.wind_angle );
    mavlink_msg_wind_data_raw_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wind_data_raw_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_usec , packet1.reference , packet1.wind_speed , packet1.wind_angle );
    mavlink_msg_wind_data_raw_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_wind_data_raw_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_wind_data_raw_send(MAVLINK_COMM_1 , packet1.time_usec , packet1.reference , packet1.wind_speed , packet1.wind_angle );
    mavlink_msg_wind_data_raw_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("WIND_DATA_RAW") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_WIND_DATA_RAW) != NULL);
#endif
}

static void mavlink_test_auterion(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_param_ack_transaction(system_id, component_id, last_msg);
    mavlink_test_beacon_position(system_id, component_id, last_msg);
    mavlink_test_radiation_detector_counts(system_id, component_id, last_msg);
    mavlink_test_radiation_detector_spectrum(system_id, component_id, last_msg);
    mavlink_test_radiation_detector_cps(system_id, component_id, last_msg);
    mavlink_test_tracker_status(system_id, component_id, last_msg);
    mavlink_test_tracker_detection_2d(system_id, component_id, last_msg);
    mavlink_test_joystick_state(system_id, component_id, last_msg);
    mavlink_test_pixel_to_lla_request(system_id, component_id, last_msg);
    mavlink_test_pixel_to_lla_ack(system_id, component_id, last_msg);
    mavlink_test_pixel_to_lla_result(system_id, component_id, last_msg);
    mavlink_test_motor_info(system_id, component_id, last_msg);
    mavlink_test_control_status_report(system_id, component_id, last_msg);
    mavlink_test_request_control(system_id, component_id, last_msg);
    mavlink_test_request_control_ack(system_id, component_id, last_msg);
    mavlink_test_release_control(system_id, component_id, last_msg);
    mavlink_test_request_handoff(system_id, component_id, last_msg);
    mavlink_test_handoff_respond(system_id, component_id, last_msg);
    mavlink_test_unique_identifier(system_id, component_id, last_msg);
    mavlink_test_boat_actuator_status(system_id, component_id, last_msg);
    mavlink_test_boat_engine_status(system_id, component_id, last_msg);
    mavlink_test_fluid_level(system_id, component_id, last_msg);
    mavlink_test_vessel_speed(system_id, component_id, last_msg);
    mavlink_test_water_depth_raw(system_id, component_id, last_msg);
    mavlink_test_wind_data_raw(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // AUTERION_TESTSUITE_H
