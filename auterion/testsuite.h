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
static void mavlink_test_ras_a(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_auterion(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_ras_a(system_id, component_id, last_msg);
    mavlink_test_auterion(system_id, component_id, last_msg);
}
#endif

#include "../ras_a/testsuite.h"


static void mavlink_test_radio_status_extensions(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_radio_status_extensions_t packet_in = {
        5,72,139,206,17,84,17547
    };
    mavlink_radio_status_extensions_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.rssi = packet_in.rssi;
        packet1.snr = packet_in.snr;
        packet1.mcs_index = packet_in.mcs_index;
        packet1.number_spatial_streams = packet_in.number_spatial_streams;
        packet1.queue_size = packet_in.queue_size;
        packet1.air_time = packet_in.air_time;
        packet1.temperature = packet_in.temperature;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_radio_status_extensions_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_radio_status_extensions_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_radio_status_extensions_pack(system_id, component_id, &msg , packet1.rssi , packet1.snr , packet1.mcs_index , packet1.number_spatial_streams , packet1.queue_size , packet1.air_time , packet1.temperature );
    mavlink_msg_radio_status_extensions_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_radio_status_extensions_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.rssi , packet1.snr , packet1.mcs_index , packet1.number_spatial_streams , packet1.queue_size , packet1.air_time , packet1.temperature );
    mavlink_msg_radio_status_extensions_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_radio_status_extensions_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_radio_status_extensions_send(MAVLINK_COMM_1 , packet1.rssi , packet1.snr , packet1.mcs_index , packet1.number_spatial_streams , packet1.queue_size , packet1.air_time , packet1.temperature );
    mavlink_msg_radio_status_extensions_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("RADIO_STATUS_EXTENSIONS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS) != NULL);
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

static void mavlink_test_auterion(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_radio_status_extensions(system_id, component_id, last_msg);
    mavlink_test_radiation_detector_counts(system_id, component_id, last_msg);
    mavlink_test_radiation_detector_spectrum(system_id, component_id, last_msg);
    mavlink_test_radiation_detector_cps(system_id, component_id, last_msg);
    mavlink_test_tracker_status(system_id, component_id, last_msg);
    mavlink_test_tracker_detection_2d(system_id, component_id, last_msg);
    mavlink_test_joystick_state(system_id, component_id, last_msg);
    mavlink_test_motor_info(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // AUTERION_TESTSUITE_H
