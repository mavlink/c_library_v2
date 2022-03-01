/** @file
 *    @brief MAVLink comm protocol testsuite generated from ras_a.xml
 *    @see https://mavlink.io/en/
 */
#pragma once
#ifndef RAS_A_TESTSUITE_H
#define RAS_A_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_development(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_ras_a(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_development(system_id, component_id, last_msg);
    mavlink_test_ras_a(system_id, component_id, last_msg);
}
#endif

#include "../development/testsuite.h"


static void mavlink_test_poi_report(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_POI_REPORT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_poi_report_t packet_in = {
        93372036854775807ULL,93372036854776311ULL,93372036854776815ULL,963498712,963498920,963499128,269.0,297.0,325.0,963499960,381.0,409.0,437.0,{ 465.0, 466.0, 467.0, 468.0 },577.0,605.0,633.0,661.0,689.0,717.0,745.0,773.0,{ 801.0, 802.0, 803.0 },{ 885.0, 886.0, 887.0 },{ 969.0, 970.0, 971.0 },24931,71,138,205,16,83,150,"ABCDEFGHIJKLMNOPQRSTUVWXYZABCDE","GHIJKLMNOPQRSTUVWXYZABCDEFGHIJ"
    };
    mavlink_poi_report_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.uid = packet_in.uid;
        packet1.time_utc_detected = packet_in.time_utc_detected;
        packet1.time_utc_updated = packet_in.time_utc_updated;
        packet1.time_boot_ms = packet_in.time_boot_ms;
        packet1.latitude = packet_in.latitude;
        packet1.longitude = packet_in.longitude;
        packet1.alt_msl = packet_in.alt_msl;
        packet1.alt_ellip = packet_in.alt_ellip;
        packet1.alt_ground = packet_in.alt_ground;
        packet1.classification = packet_in.classification;
        packet1.x = packet_in.x;
        packet1.y = packet_in.y;
        packet1.z = packet_in.z;
        packet1.dist = packet_in.dist;
        packet1.vel_n = packet_in.vel_n;
        packet1.vel_e = packet_in.vel_e;
        packet1.vel_d = packet_in.vel_d;
        packet1.hdg = packet_in.hdg;
        packet1.height = packet_in.height;
        packet1.width = packet_in.width;
        packet1.depth = packet_in.depth;
        packet1.ttl = packet_in.ttl;
        packet1.confidence_overall = packet_in.confidence_overall;
        packet1.confidence_detection = packet_in.confidence_detection;
        packet1.confidence_classification = packet_in.confidence_classification;
        packet1.confidence_localization = packet_in.confidence_localization;
        packet1.status_flags = packet_in.status_flags;
        packet1.geometry = packet_in.geometry;
        
        mav_array_memcpy(packet1.q, packet_in.q, sizeof(float)*4);
        mav_array_memcpy(packet1.approach_vector_start, packet_in.approach_vector_start, sizeof(float)*3);
        mav_array_memcpy(packet1.approach_vector_end, packet_in.approach_vector_end, sizeof(float)*3);
        mav_array_memcpy(packet1.approach_velocity, packet_in.approach_velocity, sizeof(float)*3);
        mav_array_memcpy(packet1.name, packet_in.name, sizeof(char)*32);
        mav_array_memcpy(packet1.app6_symbol, packet_in.app6_symbol, sizeof(char)*31);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_POI_REPORT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_POI_REPORT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_poi_report_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_poi_report_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_poi_report_pack(system_id, component_id, &msg , packet1.uid , packet1.time_boot_ms , packet1.time_utc_detected , packet1.time_utc_updated , packet1.confidence_overall , packet1.confidence_detection , packet1.confidence_classification , packet1.confidence_localization , packet1.ttl , packet1.status_flags , packet1.latitude , packet1.longitude , packet1.alt_msl , packet1.alt_ellip , packet1.alt_ground , packet1.classification , packet1.x , packet1.y , packet1.z , packet1.q , packet1.dist , packet1.vel_n , packet1.vel_e , packet1.vel_d , packet1.hdg , packet1.height , packet1.width , packet1.depth , packet1.geometry , packet1.approach_vector_start , packet1.approach_vector_end , packet1.approach_velocity , packet1.name , packet1.app6_symbol );
    mavlink_msg_poi_report_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_poi_report_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.uid , packet1.time_boot_ms , packet1.time_utc_detected , packet1.time_utc_updated , packet1.confidence_overall , packet1.confidence_detection , packet1.confidence_classification , packet1.confidence_localization , packet1.ttl , packet1.status_flags , packet1.latitude , packet1.longitude , packet1.alt_msl , packet1.alt_ellip , packet1.alt_ground , packet1.classification , packet1.x , packet1.y , packet1.z , packet1.q , packet1.dist , packet1.vel_n , packet1.vel_e , packet1.vel_d , packet1.hdg , packet1.height , packet1.width , packet1.depth , packet1.geometry , packet1.approach_vector_start , packet1.approach_vector_end , packet1.approach_velocity , packet1.name , packet1.app6_symbol );
    mavlink_msg_poi_report_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_poi_report_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_poi_report_send(MAVLINK_COMM_1 , packet1.uid , packet1.time_boot_ms , packet1.time_utc_detected , packet1.time_utc_updated , packet1.confidence_overall , packet1.confidence_detection , packet1.confidence_classification , packet1.confidence_localization , packet1.ttl , packet1.status_flags , packet1.latitude , packet1.longitude , packet1.alt_msl , packet1.alt_ellip , packet1.alt_ground , packet1.classification , packet1.x , packet1.y , packet1.z , packet1.q , packet1.dist , packet1.vel_n , packet1.vel_e , packet1.vel_d , packet1.hdg , packet1.height , packet1.width , packet1.depth , packet1.geometry , packet1.approach_vector_start , packet1.approach_vector_end , packet1.approach_velocity , packet1.name , packet1.app6_symbol );
    mavlink_msg_poi_report_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("POI_REPORT") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_POI_REPORT) != NULL);
#endif
}

static void mavlink_test_ras_a(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_poi_report(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // RAS_A_TESTSUITE_H
