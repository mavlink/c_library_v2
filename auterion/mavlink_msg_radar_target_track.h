#pragma once
// MESSAGE RADAR_TARGET_TRACK PACKING

#define MAVLINK_MSG_ID_RADAR_TARGET_TRACK 13672


typedef struct __mavlink_radar_target_track_t {
 uint64_t time_usec; /*< [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.*/
 float distance_to_target; /*< [m]  Distance of the vehicle to the target in meters.*/
 float bearing_to_target; /*< [deg]  Bearing of the target in degrees. See bearing_type field for reference frame.*/
 float target_speed; /*< [m/s]  Target's absolute speed over ground. Measured in meters per second. */
 float target_course; /*< [deg]  Target's course. Measured in degrees. See course_type field for reference frame.*/
 float distance_to_closest_point_of_approach; /*< [m]  Distance to the closest point of approach. Measured in meters.*/
 float time_to_closest_point_of_approach; /*< [s]  Time to the closest point of approach. Measured in seconds.*/
 uint16_t target_number; /*<   Numeric ID of a particular target. Each target has a unique numeric ID.*/
 uint8_t bearing_type; /*<   Type of bearing measurement.*/
 uint8_t course_type; /*<   Type of course measurement.*/
 char target_name[20]; /*<   Name of the target.*/
 uint8_t target_track_status; /*<   Status of the target track.*/
 uint8_t target_track_acquisition_type; /*<   Type of target acquisition.*/
} mavlink_radar_target_track_t;

#define MAVLINK_MSG_ID_RADAR_TARGET_TRACK_LEN 58
#define MAVLINK_MSG_ID_RADAR_TARGET_TRACK_MIN_LEN 58
#define MAVLINK_MSG_ID_13672_LEN 58
#define MAVLINK_MSG_ID_13672_MIN_LEN 58

#define MAVLINK_MSG_ID_RADAR_TARGET_TRACK_CRC 130
#define MAVLINK_MSG_ID_13672_CRC 130

#define MAVLINK_MSG_RADAR_TARGET_TRACK_FIELD_TARGET_NAME_LEN 20

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RADAR_TARGET_TRACK { \
    13672, \
    "RADAR_TARGET_TRACK", \
    13, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_radar_target_track_t, time_usec) }, \
         { "target_number", NULL, MAVLINK_TYPE_UINT16_T, 0, 32, offsetof(mavlink_radar_target_track_t, target_number) }, \
         { "distance_to_target", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_radar_target_track_t, distance_to_target) }, \
         { "bearing_to_target", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_radar_target_track_t, bearing_to_target) }, \
         { "bearing_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 34, offsetof(mavlink_radar_target_track_t, bearing_type) }, \
         { "target_speed", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_radar_target_track_t, target_speed) }, \
         { "target_course", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_radar_target_track_t, target_course) }, \
         { "course_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 35, offsetof(mavlink_radar_target_track_t, course_type) }, \
         { "distance_to_closest_point_of_approach", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_radar_target_track_t, distance_to_closest_point_of_approach) }, \
         { "time_to_closest_point_of_approach", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_radar_target_track_t, time_to_closest_point_of_approach) }, \
         { "target_name", NULL, MAVLINK_TYPE_CHAR, 20, 36, offsetof(mavlink_radar_target_track_t, target_name) }, \
         { "target_track_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 56, offsetof(mavlink_radar_target_track_t, target_track_status) }, \
         { "target_track_acquisition_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 57, offsetof(mavlink_radar_target_track_t, target_track_acquisition_type) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_RADAR_TARGET_TRACK { \
    "RADAR_TARGET_TRACK", \
    13, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_radar_target_track_t, time_usec) }, \
         { "target_number", NULL, MAVLINK_TYPE_UINT16_T, 0, 32, offsetof(mavlink_radar_target_track_t, target_number) }, \
         { "distance_to_target", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_radar_target_track_t, distance_to_target) }, \
         { "bearing_to_target", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_radar_target_track_t, bearing_to_target) }, \
         { "bearing_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 34, offsetof(mavlink_radar_target_track_t, bearing_type) }, \
         { "target_speed", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_radar_target_track_t, target_speed) }, \
         { "target_course", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_radar_target_track_t, target_course) }, \
         { "course_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 35, offsetof(mavlink_radar_target_track_t, course_type) }, \
         { "distance_to_closest_point_of_approach", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_radar_target_track_t, distance_to_closest_point_of_approach) }, \
         { "time_to_closest_point_of_approach", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_radar_target_track_t, time_to_closest_point_of_approach) }, \
         { "target_name", NULL, MAVLINK_TYPE_CHAR, 20, 36, offsetof(mavlink_radar_target_track_t, target_name) }, \
         { "target_track_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 56, offsetof(mavlink_radar_target_track_t, target_track_status) }, \
         { "target_track_acquisition_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 57, offsetof(mavlink_radar_target_track_t, target_track_acquisition_type) }, \
         } \
}
#endif

/**
 * @brief Pack a radar_target_track message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param target_number   Numeric ID of a particular target. Each target has a unique numeric ID.
 * @param distance_to_target [m]  Distance of the vehicle to the target in meters.
 * @param bearing_to_target [deg]  Bearing of the target in degrees. See bearing_type field for reference frame.
 * @param bearing_type   Type of bearing measurement.
 * @param target_speed [m/s]  Target's absolute speed over ground. Measured in meters per second. 
 * @param target_course [deg]  Target's course. Measured in degrees. See course_type field for reference frame.
 * @param course_type   Type of course measurement.
 * @param distance_to_closest_point_of_approach [m]  Distance to the closest point of approach. Measured in meters.
 * @param time_to_closest_point_of_approach [s]  Time to the closest point of approach. Measured in seconds.
 * @param target_name   Name of the target.
 * @param target_track_status   Status of the target track.
 * @param target_track_acquisition_type   Type of target acquisition.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_radar_target_track_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, uint16_t target_number, float distance_to_target, float bearing_to_target, uint8_t bearing_type, float target_speed, float target_course, uint8_t course_type, float distance_to_closest_point_of_approach, float time_to_closest_point_of_approach, const char *target_name, uint8_t target_track_status, uint8_t target_track_acquisition_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RADAR_TARGET_TRACK_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 8, distance_to_target);
    _mav_put_float(buf, 12, bearing_to_target);
    _mav_put_float(buf, 16, target_speed);
    _mav_put_float(buf, 20, target_course);
    _mav_put_float(buf, 24, distance_to_closest_point_of_approach);
    _mav_put_float(buf, 28, time_to_closest_point_of_approach);
    _mav_put_uint16_t(buf, 32, target_number);
    _mav_put_uint8_t(buf, 34, bearing_type);
    _mav_put_uint8_t(buf, 35, course_type);
    _mav_put_uint8_t(buf, 56, target_track_status);
    _mav_put_uint8_t(buf, 57, target_track_acquisition_type);
    _mav_put_char_array(buf, 36, target_name, 20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RADAR_TARGET_TRACK_LEN);
#else
    mavlink_radar_target_track_t packet;
    packet.time_usec = time_usec;
    packet.distance_to_target = distance_to_target;
    packet.bearing_to_target = bearing_to_target;
    packet.target_speed = target_speed;
    packet.target_course = target_course;
    packet.distance_to_closest_point_of_approach = distance_to_closest_point_of_approach;
    packet.time_to_closest_point_of_approach = time_to_closest_point_of_approach;
    packet.target_number = target_number;
    packet.bearing_type = bearing_type;
    packet.course_type = course_type;
    packet.target_track_status = target_track_status;
    packet.target_track_acquisition_type = target_track_acquisition_type;
    mav_array_assign_char(packet.target_name, target_name, 20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RADAR_TARGET_TRACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RADAR_TARGET_TRACK;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RADAR_TARGET_TRACK_MIN_LEN, MAVLINK_MSG_ID_RADAR_TARGET_TRACK_LEN, MAVLINK_MSG_ID_RADAR_TARGET_TRACK_CRC);
}

/**
 * @brief Pack a radar_target_track message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param target_number   Numeric ID of a particular target. Each target has a unique numeric ID.
 * @param distance_to_target [m]  Distance of the vehicle to the target in meters.
 * @param bearing_to_target [deg]  Bearing of the target in degrees. See bearing_type field for reference frame.
 * @param bearing_type   Type of bearing measurement.
 * @param target_speed [m/s]  Target's absolute speed over ground. Measured in meters per second. 
 * @param target_course [deg]  Target's course. Measured in degrees. See course_type field for reference frame.
 * @param course_type   Type of course measurement.
 * @param distance_to_closest_point_of_approach [m]  Distance to the closest point of approach. Measured in meters.
 * @param time_to_closest_point_of_approach [s]  Time to the closest point of approach. Measured in seconds.
 * @param target_name   Name of the target.
 * @param target_track_status   Status of the target track.
 * @param target_track_acquisition_type   Type of target acquisition.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_radar_target_track_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint64_t time_usec, uint16_t target_number, float distance_to_target, float bearing_to_target, uint8_t bearing_type, float target_speed, float target_course, uint8_t course_type, float distance_to_closest_point_of_approach, float time_to_closest_point_of_approach, const char *target_name, uint8_t target_track_status, uint8_t target_track_acquisition_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RADAR_TARGET_TRACK_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 8, distance_to_target);
    _mav_put_float(buf, 12, bearing_to_target);
    _mav_put_float(buf, 16, target_speed);
    _mav_put_float(buf, 20, target_course);
    _mav_put_float(buf, 24, distance_to_closest_point_of_approach);
    _mav_put_float(buf, 28, time_to_closest_point_of_approach);
    _mav_put_uint16_t(buf, 32, target_number);
    _mav_put_uint8_t(buf, 34, bearing_type);
    _mav_put_uint8_t(buf, 35, course_type);
    _mav_put_uint8_t(buf, 56, target_track_status);
    _mav_put_uint8_t(buf, 57, target_track_acquisition_type);
    _mav_put_char_array(buf, 36, target_name, 20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RADAR_TARGET_TRACK_LEN);
#else
    mavlink_radar_target_track_t packet;
    packet.time_usec = time_usec;
    packet.distance_to_target = distance_to_target;
    packet.bearing_to_target = bearing_to_target;
    packet.target_speed = target_speed;
    packet.target_course = target_course;
    packet.distance_to_closest_point_of_approach = distance_to_closest_point_of_approach;
    packet.time_to_closest_point_of_approach = time_to_closest_point_of_approach;
    packet.target_number = target_number;
    packet.bearing_type = bearing_type;
    packet.course_type = course_type;
    packet.target_track_status = target_track_status;
    packet.target_track_acquisition_type = target_track_acquisition_type;
    mav_array_memcpy(packet.target_name, target_name, sizeof(char)*20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RADAR_TARGET_TRACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RADAR_TARGET_TRACK;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_RADAR_TARGET_TRACK_MIN_LEN, MAVLINK_MSG_ID_RADAR_TARGET_TRACK_LEN, MAVLINK_MSG_ID_RADAR_TARGET_TRACK_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_RADAR_TARGET_TRACK_MIN_LEN, MAVLINK_MSG_ID_RADAR_TARGET_TRACK_LEN);
#endif
}

/**
 * @brief Pack a radar_target_track message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param target_number   Numeric ID of a particular target. Each target has a unique numeric ID.
 * @param distance_to_target [m]  Distance of the vehicle to the target in meters.
 * @param bearing_to_target [deg]  Bearing of the target in degrees. See bearing_type field for reference frame.
 * @param bearing_type   Type of bearing measurement.
 * @param target_speed [m/s]  Target's absolute speed over ground. Measured in meters per second. 
 * @param target_course [deg]  Target's course. Measured in degrees. See course_type field for reference frame.
 * @param course_type   Type of course measurement.
 * @param distance_to_closest_point_of_approach [m]  Distance to the closest point of approach. Measured in meters.
 * @param time_to_closest_point_of_approach [s]  Time to the closest point of approach. Measured in seconds.
 * @param target_name   Name of the target.
 * @param target_track_status   Status of the target track.
 * @param target_track_acquisition_type   Type of target acquisition.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_radar_target_track_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,uint16_t target_number,float distance_to_target,float bearing_to_target,uint8_t bearing_type,float target_speed,float target_course,uint8_t course_type,float distance_to_closest_point_of_approach,float time_to_closest_point_of_approach,const char *target_name,uint8_t target_track_status,uint8_t target_track_acquisition_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RADAR_TARGET_TRACK_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 8, distance_to_target);
    _mav_put_float(buf, 12, bearing_to_target);
    _mav_put_float(buf, 16, target_speed);
    _mav_put_float(buf, 20, target_course);
    _mav_put_float(buf, 24, distance_to_closest_point_of_approach);
    _mav_put_float(buf, 28, time_to_closest_point_of_approach);
    _mav_put_uint16_t(buf, 32, target_number);
    _mav_put_uint8_t(buf, 34, bearing_type);
    _mav_put_uint8_t(buf, 35, course_type);
    _mav_put_uint8_t(buf, 56, target_track_status);
    _mav_put_uint8_t(buf, 57, target_track_acquisition_type);
    _mav_put_char_array(buf, 36, target_name, 20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RADAR_TARGET_TRACK_LEN);
#else
    mavlink_radar_target_track_t packet;
    packet.time_usec = time_usec;
    packet.distance_to_target = distance_to_target;
    packet.bearing_to_target = bearing_to_target;
    packet.target_speed = target_speed;
    packet.target_course = target_course;
    packet.distance_to_closest_point_of_approach = distance_to_closest_point_of_approach;
    packet.time_to_closest_point_of_approach = time_to_closest_point_of_approach;
    packet.target_number = target_number;
    packet.bearing_type = bearing_type;
    packet.course_type = course_type;
    packet.target_track_status = target_track_status;
    packet.target_track_acquisition_type = target_track_acquisition_type;
    mav_array_assign_char(packet.target_name, target_name, 20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RADAR_TARGET_TRACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RADAR_TARGET_TRACK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RADAR_TARGET_TRACK_MIN_LEN, MAVLINK_MSG_ID_RADAR_TARGET_TRACK_LEN, MAVLINK_MSG_ID_RADAR_TARGET_TRACK_CRC);
}

/**
 * @brief Encode a radar_target_track struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param radar_target_track C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_radar_target_track_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_radar_target_track_t* radar_target_track)
{
    return mavlink_msg_radar_target_track_pack(system_id, component_id, msg, radar_target_track->time_usec, radar_target_track->target_number, radar_target_track->distance_to_target, radar_target_track->bearing_to_target, radar_target_track->bearing_type, radar_target_track->target_speed, radar_target_track->target_course, radar_target_track->course_type, radar_target_track->distance_to_closest_point_of_approach, radar_target_track->time_to_closest_point_of_approach, radar_target_track->target_name, radar_target_track->target_track_status, radar_target_track->target_track_acquisition_type);
}

/**
 * @brief Encode a radar_target_track struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param radar_target_track C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_radar_target_track_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_radar_target_track_t* radar_target_track)
{
    return mavlink_msg_radar_target_track_pack_chan(system_id, component_id, chan, msg, radar_target_track->time_usec, radar_target_track->target_number, radar_target_track->distance_to_target, radar_target_track->bearing_to_target, radar_target_track->bearing_type, radar_target_track->target_speed, radar_target_track->target_course, radar_target_track->course_type, radar_target_track->distance_to_closest_point_of_approach, radar_target_track->time_to_closest_point_of_approach, radar_target_track->target_name, radar_target_track->target_track_status, radar_target_track->target_track_acquisition_type);
}

/**
 * @brief Encode a radar_target_track struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param radar_target_track C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_radar_target_track_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_radar_target_track_t* radar_target_track)
{
    return mavlink_msg_radar_target_track_pack_status(system_id, component_id, _status, msg,  radar_target_track->time_usec, radar_target_track->target_number, radar_target_track->distance_to_target, radar_target_track->bearing_to_target, radar_target_track->bearing_type, radar_target_track->target_speed, radar_target_track->target_course, radar_target_track->course_type, radar_target_track->distance_to_closest_point_of_approach, radar_target_track->time_to_closest_point_of_approach, radar_target_track->target_name, radar_target_track->target_track_status, radar_target_track->target_track_acquisition_type);
}

/**
 * @brief Send a radar_target_track message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param target_number   Numeric ID of a particular target. Each target has a unique numeric ID.
 * @param distance_to_target [m]  Distance of the vehicle to the target in meters.
 * @param bearing_to_target [deg]  Bearing of the target in degrees. See bearing_type field for reference frame.
 * @param bearing_type   Type of bearing measurement.
 * @param target_speed [m/s]  Target's absolute speed over ground. Measured in meters per second. 
 * @param target_course [deg]  Target's course. Measured in degrees. See course_type field for reference frame.
 * @param course_type   Type of course measurement.
 * @param distance_to_closest_point_of_approach [m]  Distance to the closest point of approach. Measured in meters.
 * @param time_to_closest_point_of_approach [s]  Time to the closest point of approach. Measured in seconds.
 * @param target_name   Name of the target.
 * @param target_track_status   Status of the target track.
 * @param target_track_acquisition_type   Type of target acquisition.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_radar_target_track_send(mavlink_channel_t chan, uint64_t time_usec, uint16_t target_number, float distance_to_target, float bearing_to_target, uint8_t bearing_type, float target_speed, float target_course, uint8_t course_type, float distance_to_closest_point_of_approach, float time_to_closest_point_of_approach, const char *target_name, uint8_t target_track_status, uint8_t target_track_acquisition_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RADAR_TARGET_TRACK_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 8, distance_to_target);
    _mav_put_float(buf, 12, bearing_to_target);
    _mav_put_float(buf, 16, target_speed);
    _mav_put_float(buf, 20, target_course);
    _mav_put_float(buf, 24, distance_to_closest_point_of_approach);
    _mav_put_float(buf, 28, time_to_closest_point_of_approach);
    _mav_put_uint16_t(buf, 32, target_number);
    _mav_put_uint8_t(buf, 34, bearing_type);
    _mav_put_uint8_t(buf, 35, course_type);
    _mav_put_uint8_t(buf, 56, target_track_status);
    _mav_put_uint8_t(buf, 57, target_track_acquisition_type);
    _mav_put_char_array(buf, 36, target_name, 20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADAR_TARGET_TRACK, buf, MAVLINK_MSG_ID_RADAR_TARGET_TRACK_MIN_LEN, MAVLINK_MSG_ID_RADAR_TARGET_TRACK_LEN, MAVLINK_MSG_ID_RADAR_TARGET_TRACK_CRC);
#else
    mavlink_radar_target_track_t packet;
    packet.time_usec = time_usec;
    packet.distance_to_target = distance_to_target;
    packet.bearing_to_target = bearing_to_target;
    packet.target_speed = target_speed;
    packet.target_course = target_course;
    packet.distance_to_closest_point_of_approach = distance_to_closest_point_of_approach;
    packet.time_to_closest_point_of_approach = time_to_closest_point_of_approach;
    packet.target_number = target_number;
    packet.bearing_type = bearing_type;
    packet.course_type = course_type;
    packet.target_track_status = target_track_status;
    packet.target_track_acquisition_type = target_track_acquisition_type;
    mav_array_assign_char(packet.target_name, target_name, 20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADAR_TARGET_TRACK, (const char *)&packet, MAVLINK_MSG_ID_RADAR_TARGET_TRACK_MIN_LEN, MAVLINK_MSG_ID_RADAR_TARGET_TRACK_LEN, MAVLINK_MSG_ID_RADAR_TARGET_TRACK_CRC);
#endif
}

/**
 * @brief Send a radar_target_track message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_radar_target_track_send_struct(mavlink_channel_t chan, const mavlink_radar_target_track_t* radar_target_track)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_radar_target_track_send(chan, radar_target_track->time_usec, radar_target_track->target_number, radar_target_track->distance_to_target, radar_target_track->bearing_to_target, radar_target_track->bearing_type, radar_target_track->target_speed, radar_target_track->target_course, radar_target_track->course_type, radar_target_track->distance_to_closest_point_of_approach, radar_target_track->time_to_closest_point_of_approach, radar_target_track->target_name, radar_target_track->target_track_status, radar_target_track->target_track_acquisition_type);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADAR_TARGET_TRACK, (const char *)radar_target_track, MAVLINK_MSG_ID_RADAR_TARGET_TRACK_MIN_LEN, MAVLINK_MSG_ID_RADAR_TARGET_TRACK_LEN, MAVLINK_MSG_ID_RADAR_TARGET_TRACK_CRC);
#endif
}

#if MAVLINK_MSG_ID_RADAR_TARGET_TRACK_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_radar_target_track_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, uint16_t target_number, float distance_to_target, float bearing_to_target, uint8_t bearing_type, float target_speed, float target_course, uint8_t course_type, float distance_to_closest_point_of_approach, float time_to_closest_point_of_approach, const char *target_name, uint8_t target_track_status, uint8_t target_track_acquisition_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 8, distance_to_target);
    _mav_put_float(buf, 12, bearing_to_target);
    _mav_put_float(buf, 16, target_speed);
    _mav_put_float(buf, 20, target_course);
    _mav_put_float(buf, 24, distance_to_closest_point_of_approach);
    _mav_put_float(buf, 28, time_to_closest_point_of_approach);
    _mav_put_uint16_t(buf, 32, target_number);
    _mav_put_uint8_t(buf, 34, bearing_type);
    _mav_put_uint8_t(buf, 35, course_type);
    _mav_put_uint8_t(buf, 56, target_track_status);
    _mav_put_uint8_t(buf, 57, target_track_acquisition_type);
    _mav_put_char_array(buf, 36, target_name, 20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADAR_TARGET_TRACK, buf, MAVLINK_MSG_ID_RADAR_TARGET_TRACK_MIN_LEN, MAVLINK_MSG_ID_RADAR_TARGET_TRACK_LEN, MAVLINK_MSG_ID_RADAR_TARGET_TRACK_CRC);
#else
    mavlink_radar_target_track_t *packet = (mavlink_radar_target_track_t *)msgbuf;
    packet->time_usec = time_usec;
    packet->distance_to_target = distance_to_target;
    packet->bearing_to_target = bearing_to_target;
    packet->target_speed = target_speed;
    packet->target_course = target_course;
    packet->distance_to_closest_point_of_approach = distance_to_closest_point_of_approach;
    packet->time_to_closest_point_of_approach = time_to_closest_point_of_approach;
    packet->target_number = target_number;
    packet->bearing_type = bearing_type;
    packet->course_type = course_type;
    packet->target_track_status = target_track_status;
    packet->target_track_acquisition_type = target_track_acquisition_type;
    mav_array_assign_char(packet->target_name, target_name, 20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADAR_TARGET_TRACK, (const char *)packet, MAVLINK_MSG_ID_RADAR_TARGET_TRACK_MIN_LEN, MAVLINK_MSG_ID_RADAR_TARGET_TRACK_LEN, MAVLINK_MSG_ID_RADAR_TARGET_TRACK_CRC);
#endif
}
#endif

#endif

// MESSAGE RADAR_TARGET_TRACK UNPACKING


/**
 * @brief Get field time_usec from radar_target_track message
 *
 * @return [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 */
static inline uint64_t mavlink_msg_radar_target_track_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field target_number from radar_target_track message
 *
 * @return   Numeric ID of a particular target. Each target has a unique numeric ID.
 */
static inline uint16_t mavlink_msg_radar_target_track_get_target_number(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  32);
}

/**
 * @brief Get field distance_to_target from radar_target_track message
 *
 * @return [m]  Distance of the vehicle to the target in meters.
 */
static inline float mavlink_msg_radar_target_track_get_distance_to_target(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field bearing_to_target from radar_target_track message
 *
 * @return [deg]  Bearing of the target in degrees. See bearing_type field for reference frame.
 */
static inline float mavlink_msg_radar_target_track_get_bearing_to_target(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field bearing_type from radar_target_track message
 *
 * @return   Type of bearing measurement.
 */
static inline uint8_t mavlink_msg_radar_target_track_get_bearing_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  34);
}

/**
 * @brief Get field target_speed from radar_target_track message
 *
 * @return [m/s]  Target's absolute speed over ground. Measured in meters per second. 
 */
static inline float mavlink_msg_radar_target_track_get_target_speed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field target_course from radar_target_track message
 *
 * @return [deg]  Target's course. Measured in degrees. See course_type field for reference frame.
 */
static inline float mavlink_msg_radar_target_track_get_target_course(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field course_type from radar_target_track message
 *
 * @return   Type of course measurement.
 */
static inline uint8_t mavlink_msg_radar_target_track_get_course_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  35);
}

/**
 * @brief Get field distance_to_closest_point_of_approach from radar_target_track message
 *
 * @return [m]  Distance to the closest point of approach. Measured in meters.
 */
static inline float mavlink_msg_radar_target_track_get_distance_to_closest_point_of_approach(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field time_to_closest_point_of_approach from radar_target_track message
 *
 * @return [s]  Time to the closest point of approach. Measured in seconds.
 */
static inline float mavlink_msg_radar_target_track_get_time_to_closest_point_of_approach(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field target_name from radar_target_track message
 *
 * @return   Name of the target.
 */
static inline uint16_t mavlink_msg_radar_target_track_get_target_name(const mavlink_message_t* msg, char *target_name)
{
    return _MAV_RETURN_char_array(msg, target_name, 20,  36);
}

/**
 * @brief Get field target_track_status from radar_target_track message
 *
 * @return   Status of the target track.
 */
static inline uint8_t mavlink_msg_radar_target_track_get_target_track_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  56);
}

/**
 * @brief Get field target_track_acquisition_type from radar_target_track message
 *
 * @return   Type of target acquisition.
 */
static inline uint8_t mavlink_msg_radar_target_track_get_target_track_acquisition_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  57);
}

/**
 * @brief Decode a radar_target_track message into a struct
 *
 * @param msg The message to decode
 * @param radar_target_track C-struct to decode the message contents into
 */
static inline void mavlink_msg_radar_target_track_decode(const mavlink_message_t* msg, mavlink_radar_target_track_t* radar_target_track)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    radar_target_track->time_usec = mavlink_msg_radar_target_track_get_time_usec(msg);
    radar_target_track->distance_to_target = mavlink_msg_radar_target_track_get_distance_to_target(msg);
    radar_target_track->bearing_to_target = mavlink_msg_radar_target_track_get_bearing_to_target(msg);
    radar_target_track->target_speed = mavlink_msg_radar_target_track_get_target_speed(msg);
    radar_target_track->target_course = mavlink_msg_radar_target_track_get_target_course(msg);
    radar_target_track->distance_to_closest_point_of_approach = mavlink_msg_radar_target_track_get_distance_to_closest_point_of_approach(msg);
    radar_target_track->time_to_closest_point_of_approach = mavlink_msg_radar_target_track_get_time_to_closest_point_of_approach(msg);
    radar_target_track->target_number = mavlink_msg_radar_target_track_get_target_number(msg);
    radar_target_track->bearing_type = mavlink_msg_radar_target_track_get_bearing_type(msg);
    radar_target_track->course_type = mavlink_msg_radar_target_track_get_course_type(msg);
    mavlink_msg_radar_target_track_get_target_name(msg, radar_target_track->target_name);
    radar_target_track->target_track_status = mavlink_msg_radar_target_track_get_target_track_status(msg);
    radar_target_track->target_track_acquisition_type = mavlink_msg_radar_target_track_get_target_track_acquisition_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_RADAR_TARGET_TRACK_LEN? msg->len : MAVLINK_MSG_ID_RADAR_TARGET_TRACK_LEN;
        memset(radar_target_track, 0, MAVLINK_MSG_ID_RADAR_TARGET_TRACK_LEN);
    memcpy(radar_target_track, _MAV_PAYLOAD(msg), len);
#endif
}
