#pragma once
// MESSAGE POI_REPORT PACKING

#define MAVLINK_MSG_ID_POI_REPORT 51000


typedef struct __mavlink_poi_report_t {
 uint64_t time_utc_detected; /*< [ms] Timestamp (time since UNIX epoch) of the POI detection, in UTC. 0 for unknown.*/
 uint64_t time_utc_updated; /*< [ms] Timestamp (time since UNIX epoch) of the last POI update, in UTC. 0 for unknown.*/
 uint32_t uid; /*<  Unique ID for a given POI. Updates to a POIs information should use the same uid. Maximum integer to use is 2,147,483,647 (for the purposes of type-safety when converting back and forth to floating-point fields). 0 means unknown.*/
 uint32_t time_boot_ms; /*< [ms] Timestamp (time since system boot).*/
 int32_t latitude; /*< [degE7] Latitude (WGS84) of the POI. If unknown: INT32_MAX (both Lat/Lon).*/
 int32_t longitude; /*< [degE7] Longitude (WGS84) of the POI. If unknown: INT32_MAX (both Lat/Lon).*/
 float alt_msl; /*< [m] Altitude of the POI with respect to the MSL. Positive for up. NaN if unknown.*/
 float alt_ellip; /*< [m] Altitude of the POI with respect to the EGM96 ellipsoid. Positive for up. NaN if unknown.*/
 float alt_ground; /*< [m] Altitude of the POI with respect to the ground level. Positive for up. NaN if unknown.*/
 uint32_t classification; /*<  Classification of the POI. Can either used the POI_CLASSIFICATION enumeration (0x0 - 0x7FFFFFFF reserved), or use the reserved range for implementation specific classifications (0x80000000 - UINT32_MAX).*/
 float x; /*< [m] X position of the POI in the local NED frame. The local frame might either be the vehicle navigation frame or a common reference frame to multiple systems. NAN if unknown.*/
 float y; /*< [m] Y position of the POI in the local NED frame. The local frame might either be the vehicle navigation frame or a common reference frame to multiple systems. NAN if unknown.*/
 float z; /*< [m] Z position of the POI in the local NED frame. The local frame might either be the vehicle navigation frame or a common reference frame to multiple systems. NAN if unknown.*/
 float q[4]; /*<  Orientation quaternion (w, x, y, z order) of the POI in the NED frame. Zero-rotation is 1, 0, 0, 0. Unknown is NAN, NAN, NAN, NAN.*/
 float dist; /*< [m] Distance from the aircraft sensor/camera focal point to the POI. NAN if unknown.*/
 float vel_n; /*< [m/s] North velocity of the POI. NAN if unknown.*/
 float vel_e; /*< [m/s] East velocity of the POI. NAN if unknown.*/
 float vel_d; /*< [m/s] Down velocity of the POI. NAN if unknown.*/
 float hdg; /*< [rad] Heading of the POI in the NED frame. NAN if unknown.*/
 uint16_t ttl; /*< [s] Time to live: If this time has elapsed since last update, the POI should be deleted on the receiver side. A value of 0 should indicate no timeout.*/
 uint8_t confidence_overall; /*< [%] Generic confidence level. Can be used for an implementation specific confidence level. 0..100, UINT8_MAX when unknown.*/
 uint8_t confidence_detection; /*< [%] Confidence level of the POI detection. 0..100, UINT8_MAX when unknown.*/
 uint8_t confidence_classification; /*< [%] Confidence level of the POI classification. 0..100, UINT8_MAX when unknown.*/
 uint8_t confidence_localization; /*< [%] Confidence level of the POI localization. 0..100, UINT8_MAX when unknown.*/
 uint8_t status_flags; /*<  Bitmask for POI status. Bit 1: POI is in focus on camera, Bit 8: POI has been cleared and should be deleted.*/
} mavlink_poi_report_t;

#define MAVLINK_MSG_ID_POI_REPORT_LEN 103
#define MAVLINK_MSG_ID_POI_REPORT_MIN_LEN 103
#define MAVLINK_MSG_ID_51000_LEN 103
#define MAVLINK_MSG_ID_51000_MIN_LEN 103

#define MAVLINK_MSG_ID_POI_REPORT_CRC 91
#define MAVLINK_MSG_ID_51000_CRC 91

#define MAVLINK_MSG_POI_REPORT_FIELD_Q_LEN 4

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_POI_REPORT { \
    51000, \
    "POI_REPORT", \
    25, \
    {  { "uid", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_poi_report_t, uid) }, \
         { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 20, offsetof(mavlink_poi_report_t, time_boot_ms) }, \
         { "time_utc_detected", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_poi_report_t, time_utc_detected) }, \
         { "time_utc_updated", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_poi_report_t, time_utc_updated) }, \
         { "confidence_overall", NULL, MAVLINK_TYPE_UINT8_T, 0, 98, offsetof(mavlink_poi_report_t, confidence_overall) }, \
         { "confidence_detection", NULL, MAVLINK_TYPE_UINT8_T, 0, 99, offsetof(mavlink_poi_report_t, confidence_detection) }, \
         { "confidence_classification", NULL, MAVLINK_TYPE_UINT8_T, 0, 100, offsetof(mavlink_poi_report_t, confidence_classification) }, \
         { "confidence_localization", NULL, MAVLINK_TYPE_UINT8_T, 0, 101, offsetof(mavlink_poi_report_t, confidence_localization) }, \
         { "ttl", NULL, MAVLINK_TYPE_UINT16_T, 0, 96, offsetof(mavlink_poi_report_t, ttl) }, \
         { "status_flags", NULL, MAVLINK_TYPE_UINT8_T, 0, 102, offsetof(mavlink_poi_report_t, status_flags) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 24, offsetof(mavlink_poi_report_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 28, offsetof(mavlink_poi_report_t, longitude) }, \
         { "alt_msl", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_poi_report_t, alt_msl) }, \
         { "alt_ellip", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_poi_report_t, alt_ellip) }, \
         { "alt_ground", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_poi_report_t, alt_ground) }, \
         { "classification", NULL, MAVLINK_TYPE_UINT32_T, 0, 44, offsetof(mavlink_poi_report_t, classification) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_poi_report_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_poi_report_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_poi_report_t, z) }, \
         { "q", NULL, MAVLINK_TYPE_FLOAT, 4, 60, offsetof(mavlink_poi_report_t, q) }, \
         { "dist", NULL, MAVLINK_TYPE_FLOAT, 0, 76, offsetof(mavlink_poi_report_t, dist) }, \
         { "vel_n", NULL, MAVLINK_TYPE_FLOAT, 0, 80, offsetof(mavlink_poi_report_t, vel_n) }, \
         { "vel_e", NULL, MAVLINK_TYPE_FLOAT, 0, 84, offsetof(mavlink_poi_report_t, vel_e) }, \
         { "vel_d", NULL, MAVLINK_TYPE_FLOAT, 0, 88, offsetof(mavlink_poi_report_t, vel_d) }, \
         { "hdg", NULL, MAVLINK_TYPE_FLOAT, 0, 92, offsetof(mavlink_poi_report_t, hdg) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_POI_REPORT { \
    "POI_REPORT", \
    25, \
    {  { "uid", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_poi_report_t, uid) }, \
         { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 20, offsetof(mavlink_poi_report_t, time_boot_ms) }, \
         { "time_utc_detected", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_poi_report_t, time_utc_detected) }, \
         { "time_utc_updated", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_poi_report_t, time_utc_updated) }, \
         { "confidence_overall", NULL, MAVLINK_TYPE_UINT8_T, 0, 98, offsetof(mavlink_poi_report_t, confidence_overall) }, \
         { "confidence_detection", NULL, MAVLINK_TYPE_UINT8_T, 0, 99, offsetof(mavlink_poi_report_t, confidence_detection) }, \
         { "confidence_classification", NULL, MAVLINK_TYPE_UINT8_T, 0, 100, offsetof(mavlink_poi_report_t, confidence_classification) }, \
         { "confidence_localization", NULL, MAVLINK_TYPE_UINT8_T, 0, 101, offsetof(mavlink_poi_report_t, confidence_localization) }, \
         { "ttl", NULL, MAVLINK_TYPE_UINT16_T, 0, 96, offsetof(mavlink_poi_report_t, ttl) }, \
         { "status_flags", NULL, MAVLINK_TYPE_UINT8_T, 0, 102, offsetof(mavlink_poi_report_t, status_flags) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 24, offsetof(mavlink_poi_report_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 28, offsetof(mavlink_poi_report_t, longitude) }, \
         { "alt_msl", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_poi_report_t, alt_msl) }, \
         { "alt_ellip", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_poi_report_t, alt_ellip) }, \
         { "alt_ground", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_poi_report_t, alt_ground) }, \
         { "classification", NULL, MAVLINK_TYPE_UINT32_T, 0, 44, offsetof(mavlink_poi_report_t, classification) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_poi_report_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_poi_report_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_poi_report_t, z) }, \
         { "q", NULL, MAVLINK_TYPE_FLOAT, 4, 60, offsetof(mavlink_poi_report_t, q) }, \
         { "dist", NULL, MAVLINK_TYPE_FLOAT, 0, 76, offsetof(mavlink_poi_report_t, dist) }, \
         { "vel_n", NULL, MAVLINK_TYPE_FLOAT, 0, 80, offsetof(mavlink_poi_report_t, vel_n) }, \
         { "vel_e", NULL, MAVLINK_TYPE_FLOAT, 0, 84, offsetof(mavlink_poi_report_t, vel_e) }, \
         { "vel_d", NULL, MAVLINK_TYPE_FLOAT, 0, 88, offsetof(mavlink_poi_report_t, vel_d) }, \
         { "hdg", NULL, MAVLINK_TYPE_FLOAT, 0, 92, offsetof(mavlink_poi_report_t, hdg) }, \
         } \
}
#endif

/**
 * @brief Pack a poi_report message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param uid  Unique ID for a given POI. Updates to a POIs information should use the same uid. Maximum integer to use is 2,147,483,647 (for the purposes of type-safety when converting back and forth to floating-point fields). 0 means unknown.
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param time_utc_detected [ms] Timestamp (time since UNIX epoch) of the POI detection, in UTC. 0 for unknown.
 * @param time_utc_updated [ms] Timestamp (time since UNIX epoch) of the last POI update, in UTC. 0 for unknown.
 * @param confidence_overall [%] Generic confidence level. Can be used for an implementation specific confidence level. 0..100, UINT8_MAX when unknown.
 * @param confidence_detection [%] Confidence level of the POI detection. 0..100, UINT8_MAX when unknown.
 * @param confidence_classification [%] Confidence level of the POI classification. 0..100, UINT8_MAX when unknown.
 * @param confidence_localization [%] Confidence level of the POI localization. 0..100, UINT8_MAX when unknown.
 * @param ttl [s] Time to live: If this time has elapsed since last update, the POI should be deleted on the receiver side. A value of 0 should indicate no timeout.
 * @param status_flags  Bitmask for POI status. Bit 1: POI is in focus on camera, Bit 8: POI has been cleared and should be deleted.
 * @param latitude [degE7] Latitude (WGS84) of the POI. If unknown: INT32_MAX (both Lat/Lon).
 * @param longitude [degE7] Longitude (WGS84) of the POI. If unknown: INT32_MAX (both Lat/Lon).
 * @param alt_msl [m] Altitude of the POI with respect to the MSL. Positive for up. NaN if unknown.
 * @param alt_ellip [m] Altitude of the POI with respect to the EGM96 ellipsoid. Positive for up. NaN if unknown.
 * @param alt_ground [m] Altitude of the POI with respect to the ground level. Positive for up. NaN if unknown.
 * @param classification  Classification of the POI. Can either used the POI_CLASSIFICATION enumeration (0x0 - 0x7FFFFFFF reserved), or use the reserved range for implementation specific classifications (0x80000000 - UINT32_MAX).
 * @param x [m] X position of the POI in the local NED frame. The local frame might either be the vehicle navigation frame or a common reference frame to multiple systems. NAN if unknown.
 * @param y [m] Y position of the POI in the local NED frame. The local frame might either be the vehicle navigation frame or a common reference frame to multiple systems. NAN if unknown.
 * @param z [m] Z position of the POI in the local NED frame. The local frame might either be the vehicle navigation frame or a common reference frame to multiple systems. NAN if unknown.
 * @param q  Orientation quaternion (w, x, y, z order) of the POI in the NED frame. Zero-rotation is 1, 0, 0, 0. Unknown is NAN, NAN, NAN, NAN.
 * @param dist [m] Distance from the aircraft sensor/camera focal point to the POI. NAN if unknown.
 * @param vel_n [m/s] North velocity of the POI. NAN if unknown.
 * @param vel_e [m/s] East velocity of the POI. NAN if unknown.
 * @param vel_d [m/s] Down velocity of the POI. NAN if unknown.
 * @param hdg [rad] Heading of the POI in the NED frame. NAN if unknown.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_poi_report_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t uid, uint32_t time_boot_ms, uint64_t time_utc_detected, uint64_t time_utc_updated, uint8_t confidence_overall, uint8_t confidence_detection, uint8_t confidence_classification, uint8_t confidence_localization, uint16_t ttl, uint8_t status_flags, int32_t latitude, int32_t longitude, float alt_msl, float alt_ellip, float alt_ground, uint32_t classification, float x, float y, float z, const float *q, float dist, float vel_n, float vel_e, float vel_d, float hdg)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_POI_REPORT_LEN];
    _mav_put_uint64_t(buf, 0, time_utc_detected);
    _mav_put_uint64_t(buf, 8, time_utc_updated);
    _mav_put_uint32_t(buf, 16, uid);
    _mav_put_uint32_t(buf, 20, time_boot_ms);
    _mav_put_int32_t(buf, 24, latitude);
    _mav_put_int32_t(buf, 28, longitude);
    _mav_put_float(buf, 32, alt_msl);
    _mav_put_float(buf, 36, alt_ellip);
    _mav_put_float(buf, 40, alt_ground);
    _mav_put_uint32_t(buf, 44, classification);
    _mav_put_float(buf, 48, x);
    _mav_put_float(buf, 52, y);
    _mav_put_float(buf, 56, z);
    _mav_put_float(buf, 76, dist);
    _mav_put_float(buf, 80, vel_n);
    _mav_put_float(buf, 84, vel_e);
    _mav_put_float(buf, 88, vel_d);
    _mav_put_float(buf, 92, hdg);
    _mav_put_uint16_t(buf, 96, ttl);
    _mav_put_uint8_t(buf, 98, confidence_overall);
    _mav_put_uint8_t(buf, 99, confidence_detection);
    _mav_put_uint8_t(buf, 100, confidence_classification);
    _mav_put_uint8_t(buf, 101, confidence_localization);
    _mav_put_uint8_t(buf, 102, status_flags);
    _mav_put_float_array(buf, 60, q, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_POI_REPORT_LEN);
#else
    mavlink_poi_report_t packet;
    packet.time_utc_detected = time_utc_detected;
    packet.time_utc_updated = time_utc_updated;
    packet.uid = uid;
    packet.time_boot_ms = time_boot_ms;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.alt_msl = alt_msl;
    packet.alt_ellip = alt_ellip;
    packet.alt_ground = alt_ground;
    packet.classification = classification;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.dist = dist;
    packet.vel_n = vel_n;
    packet.vel_e = vel_e;
    packet.vel_d = vel_d;
    packet.hdg = hdg;
    packet.ttl = ttl;
    packet.confidence_overall = confidence_overall;
    packet.confidence_detection = confidence_detection;
    packet.confidence_classification = confidence_classification;
    packet.confidence_localization = confidence_localization;
    packet.status_flags = status_flags;
    mav_array_memcpy(packet.q, q, sizeof(float)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_POI_REPORT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_POI_REPORT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_POI_REPORT_MIN_LEN, MAVLINK_MSG_ID_POI_REPORT_LEN, MAVLINK_MSG_ID_POI_REPORT_CRC);
}

/**
 * @brief Pack a poi_report message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param uid  Unique ID for a given POI. Updates to a POIs information should use the same uid. Maximum integer to use is 2,147,483,647 (for the purposes of type-safety when converting back and forth to floating-point fields). 0 means unknown.
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param time_utc_detected [ms] Timestamp (time since UNIX epoch) of the POI detection, in UTC. 0 for unknown.
 * @param time_utc_updated [ms] Timestamp (time since UNIX epoch) of the last POI update, in UTC. 0 for unknown.
 * @param confidence_overall [%] Generic confidence level. Can be used for an implementation specific confidence level. 0..100, UINT8_MAX when unknown.
 * @param confidence_detection [%] Confidence level of the POI detection. 0..100, UINT8_MAX when unknown.
 * @param confidence_classification [%] Confidence level of the POI classification. 0..100, UINT8_MAX when unknown.
 * @param confidence_localization [%] Confidence level of the POI localization. 0..100, UINT8_MAX when unknown.
 * @param ttl [s] Time to live: If this time has elapsed since last update, the POI should be deleted on the receiver side. A value of 0 should indicate no timeout.
 * @param status_flags  Bitmask for POI status. Bit 1: POI is in focus on camera, Bit 8: POI has been cleared and should be deleted.
 * @param latitude [degE7] Latitude (WGS84) of the POI. If unknown: INT32_MAX (both Lat/Lon).
 * @param longitude [degE7] Longitude (WGS84) of the POI. If unknown: INT32_MAX (both Lat/Lon).
 * @param alt_msl [m] Altitude of the POI with respect to the MSL. Positive for up. NaN if unknown.
 * @param alt_ellip [m] Altitude of the POI with respect to the EGM96 ellipsoid. Positive for up. NaN if unknown.
 * @param alt_ground [m] Altitude of the POI with respect to the ground level. Positive for up. NaN if unknown.
 * @param classification  Classification of the POI. Can either used the POI_CLASSIFICATION enumeration (0x0 - 0x7FFFFFFF reserved), or use the reserved range for implementation specific classifications (0x80000000 - UINT32_MAX).
 * @param x [m] X position of the POI in the local NED frame. The local frame might either be the vehicle navigation frame or a common reference frame to multiple systems. NAN if unknown.
 * @param y [m] Y position of the POI in the local NED frame. The local frame might either be the vehicle navigation frame or a common reference frame to multiple systems. NAN if unknown.
 * @param z [m] Z position of the POI in the local NED frame. The local frame might either be the vehicle navigation frame or a common reference frame to multiple systems. NAN if unknown.
 * @param q  Orientation quaternion (w, x, y, z order) of the POI in the NED frame. Zero-rotation is 1, 0, 0, 0. Unknown is NAN, NAN, NAN, NAN.
 * @param dist [m] Distance from the aircraft sensor/camera focal point to the POI. NAN if unknown.
 * @param vel_n [m/s] North velocity of the POI. NAN if unknown.
 * @param vel_e [m/s] East velocity of the POI. NAN if unknown.
 * @param vel_d [m/s] Down velocity of the POI. NAN if unknown.
 * @param hdg [rad] Heading of the POI in the NED frame. NAN if unknown.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_poi_report_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t uid,uint32_t time_boot_ms,uint64_t time_utc_detected,uint64_t time_utc_updated,uint8_t confidence_overall,uint8_t confidence_detection,uint8_t confidence_classification,uint8_t confidence_localization,uint16_t ttl,uint8_t status_flags,int32_t latitude,int32_t longitude,float alt_msl,float alt_ellip,float alt_ground,uint32_t classification,float x,float y,float z,const float *q,float dist,float vel_n,float vel_e,float vel_d,float hdg)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_POI_REPORT_LEN];
    _mav_put_uint64_t(buf, 0, time_utc_detected);
    _mav_put_uint64_t(buf, 8, time_utc_updated);
    _mav_put_uint32_t(buf, 16, uid);
    _mav_put_uint32_t(buf, 20, time_boot_ms);
    _mav_put_int32_t(buf, 24, latitude);
    _mav_put_int32_t(buf, 28, longitude);
    _mav_put_float(buf, 32, alt_msl);
    _mav_put_float(buf, 36, alt_ellip);
    _mav_put_float(buf, 40, alt_ground);
    _mav_put_uint32_t(buf, 44, classification);
    _mav_put_float(buf, 48, x);
    _mav_put_float(buf, 52, y);
    _mav_put_float(buf, 56, z);
    _mav_put_float(buf, 76, dist);
    _mav_put_float(buf, 80, vel_n);
    _mav_put_float(buf, 84, vel_e);
    _mav_put_float(buf, 88, vel_d);
    _mav_put_float(buf, 92, hdg);
    _mav_put_uint16_t(buf, 96, ttl);
    _mav_put_uint8_t(buf, 98, confidence_overall);
    _mav_put_uint8_t(buf, 99, confidence_detection);
    _mav_put_uint8_t(buf, 100, confidence_classification);
    _mav_put_uint8_t(buf, 101, confidence_localization);
    _mav_put_uint8_t(buf, 102, status_flags);
    _mav_put_float_array(buf, 60, q, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_POI_REPORT_LEN);
#else
    mavlink_poi_report_t packet;
    packet.time_utc_detected = time_utc_detected;
    packet.time_utc_updated = time_utc_updated;
    packet.uid = uid;
    packet.time_boot_ms = time_boot_ms;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.alt_msl = alt_msl;
    packet.alt_ellip = alt_ellip;
    packet.alt_ground = alt_ground;
    packet.classification = classification;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.dist = dist;
    packet.vel_n = vel_n;
    packet.vel_e = vel_e;
    packet.vel_d = vel_d;
    packet.hdg = hdg;
    packet.ttl = ttl;
    packet.confidence_overall = confidence_overall;
    packet.confidence_detection = confidence_detection;
    packet.confidence_classification = confidence_classification;
    packet.confidence_localization = confidence_localization;
    packet.status_flags = status_flags;
    mav_array_memcpy(packet.q, q, sizeof(float)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_POI_REPORT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_POI_REPORT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_POI_REPORT_MIN_LEN, MAVLINK_MSG_ID_POI_REPORT_LEN, MAVLINK_MSG_ID_POI_REPORT_CRC);
}

/**
 * @brief Encode a poi_report struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param poi_report C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_poi_report_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_poi_report_t* poi_report)
{
    return mavlink_msg_poi_report_pack(system_id, component_id, msg, poi_report->uid, poi_report->time_boot_ms, poi_report->time_utc_detected, poi_report->time_utc_updated, poi_report->confidence_overall, poi_report->confidence_detection, poi_report->confidence_classification, poi_report->confidence_localization, poi_report->ttl, poi_report->status_flags, poi_report->latitude, poi_report->longitude, poi_report->alt_msl, poi_report->alt_ellip, poi_report->alt_ground, poi_report->classification, poi_report->x, poi_report->y, poi_report->z, poi_report->q, poi_report->dist, poi_report->vel_n, poi_report->vel_e, poi_report->vel_d, poi_report->hdg);
}

/**
 * @brief Encode a poi_report struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param poi_report C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_poi_report_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_poi_report_t* poi_report)
{
    return mavlink_msg_poi_report_pack_chan(system_id, component_id, chan, msg, poi_report->uid, poi_report->time_boot_ms, poi_report->time_utc_detected, poi_report->time_utc_updated, poi_report->confidence_overall, poi_report->confidence_detection, poi_report->confidence_classification, poi_report->confidence_localization, poi_report->ttl, poi_report->status_flags, poi_report->latitude, poi_report->longitude, poi_report->alt_msl, poi_report->alt_ellip, poi_report->alt_ground, poi_report->classification, poi_report->x, poi_report->y, poi_report->z, poi_report->q, poi_report->dist, poi_report->vel_n, poi_report->vel_e, poi_report->vel_d, poi_report->hdg);
}

/**
 * @brief Send a poi_report message
 * @param chan MAVLink channel to send the message
 *
 * @param uid  Unique ID for a given POI. Updates to a POIs information should use the same uid. Maximum integer to use is 2,147,483,647 (for the purposes of type-safety when converting back and forth to floating-point fields). 0 means unknown.
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param time_utc_detected [ms] Timestamp (time since UNIX epoch) of the POI detection, in UTC. 0 for unknown.
 * @param time_utc_updated [ms] Timestamp (time since UNIX epoch) of the last POI update, in UTC. 0 for unknown.
 * @param confidence_overall [%] Generic confidence level. Can be used for an implementation specific confidence level. 0..100, UINT8_MAX when unknown.
 * @param confidence_detection [%] Confidence level of the POI detection. 0..100, UINT8_MAX when unknown.
 * @param confidence_classification [%] Confidence level of the POI classification. 0..100, UINT8_MAX when unknown.
 * @param confidence_localization [%] Confidence level of the POI localization. 0..100, UINT8_MAX when unknown.
 * @param ttl [s] Time to live: If this time has elapsed since last update, the POI should be deleted on the receiver side. A value of 0 should indicate no timeout.
 * @param status_flags  Bitmask for POI status. Bit 1: POI is in focus on camera, Bit 8: POI has been cleared and should be deleted.
 * @param latitude [degE7] Latitude (WGS84) of the POI. If unknown: INT32_MAX (both Lat/Lon).
 * @param longitude [degE7] Longitude (WGS84) of the POI. If unknown: INT32_MAX (both Lat/Lon).
 * @param alt_msl [m] Altitude of the POI with respect to the MSL. Positive for up. NaN if unknown.
 * @param alt_ellip [m] Altitude of the POI with respect to the EGM96 ellipsoid. Positive for up. NaN if unknown.
 * @param alt_ground [m] Altitude of the POI with respect to the ground level. Positive for up. NaN if unknown.
 * @param classification  Classification of the POI. Can either used the POI_CLASSIFICATION enumeration (0x0 - 0x7FFFFFFF reserved), or use the reserved range for implementation specific classifications (0x80000000 - UINT32_MAX).
 * @param x [m] X position of the POI in the local NED frame. The local frame might either be the vehicle navigation frame or a common reference frame to multiple systems. NAN if unknown.
 * @param y [m] Y position of the POI in the local NED frame. The local frame might either be the vehicle navigation frame or a common reference frame to multiple systems. NAN if unknown.
 * @param z [m] Z position of the POI in the local NED frame. The local frame might either be the vehicle navigation frame or a common reference frame to multiple systems. NAN if unknown.
 * @param q  Orientation quaternion (w, x, y, z order) of the POI in the NED frame. Zero-rotation is 1, 0, 0, 0. Unknown is NAN, NAN, NAN, NAN.
 * @param dist [m] Distance from the aircraft sensor/camera focal point to the POI. NAN if unknown.
 * @param vel_n [m/s] North velocity of the POI. NAN if unknown.
 * @param vel_e [m/s] East velocity of the POI. NAN if unknown.
 * @param vel_d [m/s] Down velocity of the POI. NAN if unknown.
 * @param hdg [rad] Heading of the POI in the NED frame. NAN if unknown.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_poi_report_send(mavlink_channel_t chan, uint32_t uid, uint32_t time_boot_ms, uint64_t time_utc_detected, uint64_t time_utc_updated, uint8_t confidence_overall, uint8_t confidence_detection, uint8_t confidence_classification, uint8_t confidence_localization, uint16_t ttl, uint8_t status_flags, int32_t latitude, int32_t longitude, float alt_msl, float alt_ellip, float alt_ground, uint32_t classification, float x, float y, float z, const float *q, float dist, float vel_n, float vel_e, float vel_d, float hdg)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_POI_REPORT_LEN];
    _mav_put_uint64_t(buf, 0, time_utc_detected);
    _mav_put_uint64_t(buf, 8, time_utc_updated);
    _mav_put_uint32_t(buf, 16, uid);
    _mav_put_uint32_t(buf, 20, time_boot_ms);
    _mav_put_int32_t(buf, 24, latitude);
    _mav_put_int32_t(buf, 28, longitude);
    _mav_put_float(buf, 32, alt_msl);
    _mav_put_float(buf, 36, alt_ellip);
    _mav_put_float(buf, 40, alt_ground);
    _mav_put_uint32_t(buf, 44, classification);
    _mav_put_float(buf, 48, x);
    _mav_put_float(buf, 52, y);
    _mav_put_float(buf, 56, z);
    _mav_put_float(buf, 76, dist);
    _mav_put_float(buf, 80, vel_n);
    _mav_put_float(buf, 84, vel_e);
    _mav_put_float(buf, 88, vel_d);
    _mav_put_float(buf, 92, hdg);
    _mav_put_uint16_t(buf, 96, ttl);
    _mav_put_uint8_t(buf, 98, confidence_overall);
    _mav_put_uint8_t(buf, 99, confidence_detection);
    _mav_put_uint8_t(buf, 100, confidence_classification);
    _mav_put_uint8_t(buf, 101, confidence_localization);
    _mav_put_uint8_t(buf, 102, status_flags);
    _mav_put_float_array(buf, 60, q, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POI_REPORT, buf, MAVLINK_MSG_ID_POI_REPORT_MIN_LEN, MAVLINK_MSG_ID_POI_REPORT_LEN, MAVLINK_MSG_ID_POI_REPORT_CRC);
#else
    mavlink_poi_report_t packet;
    packet.time_utc_detected = time_utc_detected;
    packet.time_utc_updated = time_utc_updated;
    packet.uid = uid;
    packet.time_boot_ms = time_boot_ms;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.alt_msl = alt_msl;
    packet.alt_ellip = alt_ellip;
    packet.alt_ground = alt_ground;
    packet.classification = classification;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.dist = dist;
    packet.vel_n = vel_n;
    packet.vel_e = vel_e;
    packet.vel_d = vel_d;
    packet.hdg = hdg;
    packet.ttl = ttl;
    packet.confidence_overall = confidence_overall;
    packet.confidence_detection = confidence_detection;
    packet.confidence_classification = confidence_classification;
    packet.confidence_localization = confidence_localization;
    packet.status_flags = status_flags;
    mav_array_memcpy(packet.q, q, sizeof(float)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POI_REPORT, (const char *)&packet, MAVLINK_MSG_ID_POI_REPORT_MIN_LEN, MAVLINK_MSG_ID_POI_REPORT_LEN, MAVLINK_MSG_ID_POI_REPORT_CRC);
#endif
}

/**
 * @brief Send a poi_report message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_poi_report_send_struct(mavlink_channel_t chan, const mavlink_poi_report_t* poi_report)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_poi_report_send(chan, poi_report->uid, poi_report->time_boot_ms, poi_report->time_utc_detected, poi_report->time_utc_updated, poi_report->confidence_overall, poi_report->confidence_detection, poi_report->confidence_classification, poi_report->confidence_localization, poi_report->ttl, poi_report->status_flags, poi_report->latitude, poi_report->longitude, poi_report->alt_msl, poi_report->alt_ellip, poi_report->alt_ground, poi_report->classification, poi_report->x, poi_report->y, poi_report->z, poi_report->q, poi_report->dist, poi_report->vel_n, poi_report->vel_e, poi_report->vel_d, poi_report->hdg);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POI_REPORT, (const char *)poi_report, MAVLINK_MSG_ID_POI_REPORT_MIN_LEN, MAVLINK_MSG_ID_POI_REPORT_LEN, MAVLINK_MSG_ID_POI_REPORT_CRC);
#endif
}

#if MAVLINK_MSG_ID_POI_REPORT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_poi_report_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t uid, uint32_t time_boot_ms, uint64_t time_utc_detected, uint64_t time_utc_updated, uint8_t confidence_overall, uint8_t confidence_detection, uint8_t confidence_classification, uint8_t confidence_localization, uint16_t ttl, uint8_t status_flags, int32_t latitude, int32_t longitude, float alt_msl, float alt_ellip, float alt_ground, uint32_t classification, float x, float y, float z, const float *q, float dist, float vel_n, float vel_e, float vel_d, float hdg)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_utc_detected);
    _mav_put_uint64_t(buf, 8, time_utc_updated);
    _mav_put_uint32_t(buf, 16, uid);
    _mav_put_uint32_t(buf, 20, time_boot_ms);
    _mav_put_int32_t(buf, 24, latitude);
    _mav_put_int32_t(buf, 28, longitude);
    _mav_put_float(buf, 32, alt_msl);
    _mav_put_float(buf, 36, alt_ellip);
    _mav_put_float(buf, 40, alt_ground);
    _mav_put_uint32_t(buf, 44, classification);
    _mav_put_float(buf, 48, x);
    _mav_put_float(buf, 52, y);
    _mav_put_float(buf, 56, z);
    _mav_put_float(buf, 76, dist);
    _mav_put_float(buf, 80, vel_n);
    _mav_put_float(buf, 84, vel_e);
    _mav_put_float(buf, 88, vel_d);
    _mav_put_float(buf, 92, hdg);
    _mav_put_uint16_t(buf, 96, ttl);
    _mav_put_uint8_t(buf, 98, confidence_overall);
    _mav_put_uint8_t(buf, 99, confidence_detection);
    _mav_put_uint8_t(buf, 100, confidence_classification);
    _mav_put_uint8_t(buf, 101, confidence_localization);
    _mav_put_uint8_t(buf, 102, status_flags);
    _mav_put_float_array(buf, 60, q, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POI_REPORT, buf, MAVLINK_MSG_ID_POI_REPORT_MIN_LEN, MAVLINK_MSG_ID_POI_REPORT_LEN, MAVLINK_MSG_ID_POI_REPORT_CRC);
#else
    mavlink_poi_report_t *packet = (mavlink_poi_report_t *)msgbuf;
    packet->time_utc_detected = time_utc_detected;
    packet->time_utc_updated = time_utc_updated;
    packet->uid = uid;
    packet->time_boot_ms = time_boot_ms;
    packet->latitude = latitude;
    packet->longitude = longitude;
    packet->alt_msl = alt_msl;
    packet->alt_ellip = alt_ellip;
    packet->alt_ground = alt_ground;
    packet->classification = classification;
    packet->x = x;
    packet->y = y;
    packet->z = z;
    packet->dist = dist;
    packet->vel_n = vel_n;
    packet->vel_e = vel_e;
    packet->vel_d = vel_d;
    packet->hdg = hdg;
    packet->ttl = ttl;
    packet->confidence_overall = confidence_overall;
    packet->confidence_detection = confidence_detection;
    packet->confidence_classification = confidence_classification;
    packet->confidence_localization = confidence_localization;
    packet->status_flags = status_flags;
    mav_array_memcpy(packet->q, q, sizeof(float)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POI_REPORT, (const char *)packet, MAVLINK_MSG_ID_POI_REPORT_MIN_LEN, MAVLINK_MSG_ID_POI_REPORT_LEN, MAVLINK_MSG_ID_POI_REPORT_CRC);
#endif
}
#endif

#endif

// MESSAGE POI_REPORT UNPACKING


/**
 * @brief Get field uid from poi_report message
 *
 * @return  Unique ID for a given POI. Updates to a POIs information should use the same uid. Maximum integer to use is 2,147,483,647 (for the purposes of type-safety when converting back and forth to floating-point fields). 0 means unknown.
 */
static inline uint32_t mavlink_msg_poi_report_get_uid(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  16);
}

/**
 * @brief Get field time_boot_ms from poi_report message
 *
 * @return [ms] Timestamp (time since system boot).
 */
static inline uint32_t mavlink_msg_poi_report_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  20);
}

/**
 * @brief Get field time_utc_detected from poi_report message
 *
 * @return [ms] Timestamp (time since UNIX epoch) of the POI detection, in UTC. 0 for unknown.
 */
static inline uint64_t mavlink_msg_poi_report_get_time_utc_detected(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field time_utc_updated from poi_report message
 *
 * @return [ms] Timestamp (time since UNIX epoch) of the last POI update, in UTC. 0 for unknown.
 */
static inline uint64_t mavlink_msg_poi_report_get_time_utc_updated(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  8);
}

/**
 * @brief Get field confidence_overall from poi_report message
 *
 * @return [%] Generic confidence level. Can be used for an implementation specific confidence level. 0..100, UINT8_MAX when unknown.
 */
static inline uint8_t mavlink_msg_poi_report_get_confidence_overall(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  98);
}

/**
 * @brief Get field confidence_detection from poi_report message
 *
 * @return [%] Confidence level of the POI detection. 0..100, UINT8_MAX when unknown.
 */
static inline uint8_t mavlink_msg_poi_report_get_confidence_detection(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  99);
}

/**
 * @brief Get field confidence_classification from poi_report message
 *
 * @return [%] Confidence level of the POI classification. 0..100, UINT8_MAX when unknown.
 */
static inline uint8_t mavlink_msg_poi_report_get_confidence_classification(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  100);
}

/**
 * @brief Get field confidence_localization from poi_report message
 *
 * @return [%] Confidence level of the POI localization. 0..100, UINT8_MAX when unknown.
 */
static inline uint8_t mavlink_msg_poi_report_get_confidence_localization(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  101);
}

/**
 * @brief Get field ttl from poi_report message
 *
 * @return [s] Time to live: If this time has elapsed since last update, the POI should be deleted on the receiver side. A value of 0 should indicate no timeout.
 */
static inline uint16_t mavlink_msg_poi_report_get_ttl(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  96);
}

/**
 * @brief Get field status_flags from poi_report message
 *
 * @return  Bitmask for POI status. Bit 1: POI is in focus on camera, Bit 8: POI has been cleared and should be deleted.
 */
static inline uint8_t mavlink_msg_poi_report_get_status_flags(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  102);
}

/**
 * @brief Get field latitude from poi_report message
 *
 * @return [degE7] Latitude (WGS84) of the POI. If unknown: INT32_MAX (both Lat/Lon).
 */
static inline int32_t mavlink_msg_poi_report_get_latitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  24);
}

/**
 * @brief Get field longitude from poi_report message
 *
 * @return [degE7] Longitude (WGS84) of the POI. If unknown: INT32_MAX (both Lat/Lon).
 */
static inline int32_t mavlink_msg_poi_report_get_longitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  28);
}

/**
 * @brief Get field alt_msl from poi_report message
 *
 * @return [m] Altitude of the POI with respect to the MSL. Positive for up. NaN if unknown.
 */
static inline float mavlink_msg_poi_report_get_alt_msl(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field alt_ellip from poi_report message
 *
 * @return [m] Altitude of the POI with respect to the EGM96 ellipsoid. Positive for up. NaN if unknown.
 */
static inline float mavlink_msg_poi_report_get_alt_ellip(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field alt_ground from poi_report message
 *
 * @return [m] Altitude of the POI with respect to the ground level. Positive for up. NaN if unknown.
 */
static inline float mavlink_msg_poi_report_get_alt_ground(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field classification from poi_report message
 *
 * @return  Classification of the POI. Can either used the POI_CLASSIFICATION enumeration (0x0 - 0x7FFFFFFF reserved), or use the reserved range for implementation specific classifications (0x80000000 - UINT32_MAX).
 */
static inline uint32_t mavlink_msg_poi_report_get_classification(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  44);
}

/**
 * @brief Get field x from poi_report message
 *
 * @return [m] X position of the POI in the local NED frame. The local frame might either be the vehicle navigation frame or a common reference frame to multiple systems. NAN if unknown.
 */
static inline float mavlink_msg_poi_report_get_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field y from poi_report message
 *
 * @return [m] Y position of the POI in the local NED frame. The local frame might either be the vehicle navigation frame or a common reference frame to multiple systems. NAN if unknown.
 */
static inline float mavlink_msg_poi_report_get_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Get field z from poi_report message
 *
 * @return [m] Z position of the POI in the local NED frame. The local frame might either be the vehicle navigation frame or a common reference frame to multiple systems. NAN if unknown.
 */
static inline float mavlink_msg_poi_report_get_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  56);
}

/**
 * @brief Get field q from poi_report message
 *
 * @return  Orientation quaternion (w, x, y, z order) of the POI in the NED frame. Zero-rotation is 1, 0, 0, 0. Unknown is NAN, NAN, NAN, NAN.
 */
static inline uint16_t mavlink_msg_poi_report_get_q(const mavlink_message_t* msg, float *q)
{
    return _MAV_RETURN_float_array(msg, q, 4,  60);
}

/**
 * @brief Get field dist from poi_report message
 *
 * @return [m] Distance from the aircraft sensor/camera focal point to the POI. NAN if unknown.
 */
static inline float mavlink_msg_poi_report_get_dist(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  76);
}

/**
 * @brief Get field vel_n from poi_report message
 *
 * @return [m/s] North velocity of the POI. NAN if unknown.
 */
static inline float mavlink_msg_poi_report_get_vel_n(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  80);
}

/**
 * @brief Get field vel_e from poi_report message
 *
 * @return [m/s] East velocity of the POI. NAN if unknown.
 */
static inline float mavlink_msg_poi_report_get_vel_e(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  84);
}

/**
 * @brief Get field vel_d from poi_report message
 *
 * @return [m/s] Down velocity of the POI. NAN if unknown.
 */
static inline float mavlink_msg_poi_report_get_vel_d(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  88);
}

/**
 * @brief Get field hdg from poi_report message
 *
 * @return [rad] Heading of the POI in the NED frame. NAN if unknown.
 */
static inline float mavlink_msg_poi_report_get_hdg(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  92);
}

/**
 * @brief Decode a poi_report message into a struct
 *
 * @param msg The message to decode
 * @param poi_report C-struct to decode the message contents into
 */
static inline void mavlink_msg_poi_report_decode(const mavlink_message_t* msg, mavlink_poi_report_t* poi_report)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    poi_report->time_utc_detected = mavlink_msg_poi_report_get_time_utc_detected(msg);
    poi_report->time_utc_updated = mavlink_msg_poi_report_get_time_utc_updated(msg);
    poi_report->uid = mavlink_msg_poi_report_get_uid(msg);
    poi_report->time_boot_ms = mavlink_msg_poi_report_get_time_boot_ms(msg);
    poi_report->latitude = mavlink_msg_poi_report_get_latitude(msg);
    poi_report->longitude = mavlink_msg_poi_report_get_longitude(msg);
    poi_report->alt_msl = mavlink_msg_poi_report_get_alt_msl(msg);
    poi_report->alt_ellip = mavlink_msg_poi_report_get_alt_ellip(msg);
    poi_report->alt_ground = mavlink_msg_poi_report_get_alt_ground(msg);
    poi_report->classification = mavlink_msg_poi_report_get_classification(msg);
    poi_report->x = mavlink_msg_poi_report_get_x(msg);
    poi_report->y = mavlink_msg_poi_report_get_y(msg);
    poi_report->z = mavlink_msg_poi_report_get_z(msg);
    mavlink_msg_poi_report_get_q(msg, poi_report->q);
    poi_report->dist = mavlink_msg_poi_report_get_dist(msg);
    poi_report->vel_n = mavlink_msg_poi_report_get_vel_n(msg);
    poi_report->vel_e = mavlink_msg_poi_report_get_vel_e(msg);
    poi_report->vel_d = mavlink_msg_poi_report_get_vel_d(msg);
    poi_report->hdg = mavlink_msg_poi_report_get_hdg(msg);
    poi_report->ttl = mavlink_msg_poi_report_get_ttl(msg);
    poi_report->confidence_overall = mavlink_msg_poi_report_get_confidence_overall(msg);
    poi_report->confidence_detection = mavlink_msg_poi_report_get_confidence_detection(msg);
    poi_report->confidence_classification = mavlink_msg_poi_report_get_confidence_classification(msg);
    poi_report->confidence_localization = mavlink_msg_poi_report_get_confidence_localization(msg);
    poi_report->status_flags = mavlink_msg_poi_report_get_status_flags(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_POI_REPORT_LEN? msg->len : MAVLINK_MSG_ID_POI_REPORT_LEN;
        memset(poi_report, 0, MAVLINK_MSG_ID_POI_REPORT_LEN);
    memcpy(poi_report, _MAV_PAYLOAD(msg), len);
#endif
}
