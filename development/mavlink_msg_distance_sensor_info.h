#pragma once
// MESSAGE DISTANCE_SENSOR_INFO PACKING

#include <stdint.h>

#define MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO 516

MAVPACKED(
typedef struct __mavlink_distance_sensor_info_t {
 float min_distance; /*< [m] Minimum distance the sensor can measure.*/
 float max_distance; /*< [m] Maximum distance the sensor can measure.*/
 float horizontal_fov; /*< [rad] Horizontal Field of View (angle) where the distance measurement is valid. NaN if unknown.*/
 float vertical_fov; /*< [rad] Vertical Field of View (angle) where the distance measurement is valid. NaN if unknown.*/
 uint8_t id; /*<  Sensor ID. Matches the id field of DISTANCE_SENSOR_V2.*/
 uint8_t type; /*<  Type of distance sensor.*/
 uint8_t orientation; /*<  Direction the sensor faces.*/
 float quaternion[4]; /*<  Quaternion of the sensor orientation in vehicle body frame (w, x, y, z order, zero-rotation is 1, 0, 0, 0). Zero-rotation is along the vehicle body x-axis. This field is required if orientation is set to MAV_SENSOR_ROTATION_CUSTOM. Set it to 0 if invalid.*/
}) mavlink_distance_sensor_info_t;

#define MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_LEN 35
#define MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_MIN_LEN 19
#define MAVLINK_MSG_ID_516_LEN 35
#define MAVLINK_MSG_ID_516_MIN_LEN 19

#define MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_CRC 125
#define MAVLINK_MSG_ID_516_CRC 125

#define MAVLINK_MSG_DISTANCE_SENSOR_INFO_FIELD_QUATERNION_LEN 4

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DISTANCE_SENSOR_INFO { \
    516, \
    "DISTANCE_SENSOR_INFO", \
    8, \
    {  { "id", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_distance_sensor_info_t, id) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 17, offsetof(mavlink_distance_sensor_info_t, type) }, \
         { "min_distance", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_distance_sensor_info_t, min_distance) }, \
         { "max_distance", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_distance_sensor_info_t, max_distance) }, \
         { "orientation", NULL, MAVLINK_TYPE_UINT8_T, 0, 18, offsetof(mavlink_distance_sensor_info_t, orientation) }, \
         { "horizontal_fov", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_distance_sensor_info_t, horizontal_fov) }, \
         { "vertical_fov", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_distance_sensor_info_t, vertical_fov) }, \
         { "quaternion", NULL, MAVLINK_TYPE_FLOAT, 4, 19, offsetof(mavlink_distance_sensor_info_t, quaternion) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DISTANCE_SENSOR_INFO { \
    "DISTANCE_SENSOR_INFO", \
    8, \
    {  { "id", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_distance_sensor_info_t, id) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 17, offsetof(mavlink_distance_sensor_info_t, type) }, \
         { "min_distance", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_distance_sensor_info_t, min_distance) }, \
         { "max_distance", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_distance_sensor_info_t, max_distance) }, \
         { "orientation", NULL, MAVLINK_TYPE_UINT8_T, 0, 18, offsetof(mavlink_distance_sensor_info_t, orientation) }, \
         { "horizontal_fov", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_distance_sensor_info_t, horizontal_fov) }, \
         { "vertical_fov", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_distance_sensor_info_t, vertical_fov) }, \
         { "quaternion", NULL, MAVLINK_TYPE_FLOAT, 4, 19, offsetof(mavlink_distance_sensor_info_t, quaternion) }, \
         } \
}
#endif

/**
 * @brief Pack a distance_sensor_info message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param id  Sensor ID. Matches the id field of DISTANCE_SENSOR_V2.
 * @param type  Type of distance sensor.
 * @param min_distance [m] Minimum distance the sensor can measure.
 * @param max_distance [m] Maximum distance the sensor can measure.
 * @param orientation  Direction the sensor faces.
 * @param horizontal_fov [rad] Horizontal Field of View (angle) where the distance measurement is valid. NaN if unknown.
 * @param vertical_fov [rad] Vertical Field of View (angle) where the distance measurement is valid. NaN if unknown.
 * @param quaternion  Quaternion of the sensor orientation in vehicle body frame (w, x, y, z order, zero-rotation is 1, 0, 0, 0). Zero-rotation is along the vehicle body x-axis. This field is required if orientation is set to MAV_SENSOR_ROTATION_CUSTOM. Set it to 0 if invalid.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_distance_sensor_info_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t id, uint8_t type, float min_distance, float max_distance, uint8_t orientation, float horizontal_fov, float vertical_fov, const float *quaternion)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_LEN];
    _mav_put_float(buf, 0, min_distance);
    _mav_put_float(buf, 4, max_distance);
    _mav_put_float(buf, 8, horizontal_fov);
    _mav_put_float(buf, 12, vertical_fov);
    _mav_put_uint8_t(buf, 16, id);
    _mav_put_uint8_t(buf, 17, type);
    _mav_put_uint8_t(buf, 18, orientation);
    _mav_put_float_array(buf, 19, quaternion, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_LEN);
#else
    mavlink_distance_sensor_info_t packet;
    packet.min_distance = min_distance;
    packet.max_distance = max_distance;
    packet.horizontal_fov = horizontal_fov;
    packet.vertical_fov = vertical_fov;
    packet.id = id;
    packet.type = type;
    packet.orientation = orientation;
    mav_array_memcpy(packet.quaternion, quaternion, sizeof(float)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_MIN_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_CRC);
}

/**
 * @brief Pack a distance_sensor_info message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param id  Sensor ID. Matches the id field of DISTANCE_SENSOR_V2.
 * @param type  Type of distance sensor.
 * @param min_distance [m] Minimum distance the sensor can measure.
 * @param max_distance [m] Maximum distance the sensor can measure.
 * @param orientation  Direction the sensor faces.
 * @param horizontal_fov [rad] Horizontal Field of View (angle) where the distance measurement is valid. NaN if unknown.
 * @param vertical_fov [rad] Vertical Field of View (angle) where the distance measurement is valid. NaN if unknown.
 * @param quaternion  Quaternion of the sensor orientation in vehicle body frame (w, x, y, z order, zero-rotation is 1, 0, 0, 0). Zero-rotation is along the vehicle body x-axis. This field is required if orientation is set to MAV_SENSOR_ROTATION_CUSTOM. Set it to 0 if invalid.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_distance_sensor_info_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t id, uint8_t type, float min_distance, float max_distance, uint8_t orientation, float horizontal_fov, float vertical_fov, const float *quaternion)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_LEN];
    _mav_put_float(buf, 0, min_distance);
    _mav_put_float(buf, 4, max_distance);
    _mav_put_float(buf, 8, horizontal_fov);
    _mav_put_float(buf, 12, vertical_fov);
    _mav_put_uint8_t(buf, 16, id);
    _mav_put_uint8_t(buf, 17, type);
    _mav_put_uint8_t(buf, 18, orientation);
    _mav_put_float_array(buf, 19, quaternion, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_LEN);
#else
    mavlink_distance_sensor_info_t packet;
    packet.min_distance = min_distance;
    packet.max_distance = max_distance;
    packet.horizontal_fov = horizontal_fov;
    packet.vertical_fov = vertical_fov;
    packet.id = id;
    packet.type = type;
    packet.orientation = orientation;
    mav_array_memcpy(packet.quaternion, quaternion, sizeof(float)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_MIN_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_MIN_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_LEN);
#endif
}

/**
 * @brief Pack a distance_sensor_info message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param id  Sensor ID. Matches the id field of DISTANCE_SENSOR_V2.
 * @param type  Type of distance sensor.
 * @param min_distance [m] Minimum distance the sensor can measure.
 * @param max_distance [m] Maximum distance the sensor can measure.
 * @param orientation  Direction the sensor faces.
 * @param horizontal_fov [rad] Horizontal Field of View (angle) where the distance measurement is valid. NaN if unknown.
 * @param vertical_fov [rad] Vertical Field of View (angle) where the distance measurement is valid. NaN if unknown.
 * @param quaternion  Quaternion of the sensor orientation in vehicle body frame (w, x, y, z order, zero-rotation is 1, 0, 0, 0). Zero-rotation is along the vehicle body x-axis. This field is required if orientation is set to MAV_SENSOR_ROTATION_CUSTOM. Set it to 0 if invalid.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_distance_sensor_info_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t id,uint8_t type,float min_distance,float max_distance,uint8_t orientation,float horizontal_fov,float vertical_fov,const float *quaternion)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_LEN];
    _mav_put_float(buf, 0, min_distance);
    _mav_put_float(buf, 4, max_distance);
    _mav_put_float(buf, 8, horizontal_fov);
    _mav_put_float(buf, 12, vertical_fov);
    _mav_put_uint8_t(buf, 16, id);
    _mav_put_uint8_t(buf, 17, type);
    _mav_put_uint8_t(buf, 18, orientation);
    _mav_put_float_array(buf, 19, quaternion, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_LEN);
#else
    mavlink_distance_sensor_info_t packet;
    packet.min_distance = min_distance;
    packet.max_distance = max_distance;
    packet.horizontal_fov = horizontal_fov;
    packet.vertical_fov = vertical_fov;
    packet.id = id;
    packet.type = type;
    packet.orientation = orientation;
    mav_array_memcpy(packet.quaternion, quaternion, sizeof(float)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_MIN_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_CRC);
}

/**
 * @brief Encode a distance_sensor_info struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param distance_sensor_info C-struct to read the message contents from
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_distance_sensor_info_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_distance_sensor_info_t* distance_sensor_info)
{
    return mavlink_msg_distance_sensor_info_pack(system_id, component_id, msg, distance_sensor_info->id, distance_sensor_info->type, distance_sensor_info->min_distance, distance_sensor_info->max_distance, distance_sensor_info->orientation, distance_sensor_info->horizontal_fov, distance_sensor_info->vertical_fov, distance_sensor_info->quaternion);
}

/**
 * @brief Encode a distance_sensor_info struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param distance_sensor_info C-struct to read the message contents from
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_distance_sensor_info_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_distance_sensor_info_t* distance_sensor_info)
{
    return mavlink_msg_distance_sensor_info_pack_chan(system_id, component_id, chan, msg, distance_sensor_info->id, distance_sensor_info->type, distance_sensor_info->min_distance, distance_sensor_info->max_distance, distance_sensor_info->orientation, distance_sensor_info->horizontal_fov, distance_sensor_info->vertical_fov, distance_sensor_info->quaternion);
}

/**
 * @brief Encode a distance_sensor_info struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param distance_sensor_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_distance_sensor_info_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_distance_sensor_info_t* distance_sensor_info)
{
    return mavlink_msg_distance_sensor_info_pack_status(system_id, component_id, _status, msg,  distance_sensor_info->id, distance_sensor_info->type, distance_sensor_info->min_distance, distance_sensor_info->max_distance, distance_sensor_info->orientation, distance_sensor_info->horizontal_fov, distance_sensor_info->vertical_fov, distance_sensor_info->quaternion);
}

/**
 * @brief Send a distance_sensor_info message
 * @param chan MAVLink channel to send the message
 *
 * @param id  Sensor ID. Matches the id field of DISTANCE_SENSOR_V2.
 * @param type  Type of distance sensor.
 * @param min_distance [m] Minimum distance the sensor can measure.
 * @param max_distance [m] Maximum distance the sensor can measure.
 * @param orientation  Direction the sensor faces.
 * @param horizontal_fov [rad] Horizontal Field of View (angle) where the distance measurement is valid. NaN if unknown.
 * @param vertical_fov [rad] Vertical Field of View (angle) where the distance measurement is valid. NaN if unknown.
 * @param quaternion  Quaternion of the sensor orientation in vehicle body frame (w, x, y, z order, zero-rotation is 1, 0, 0, 0). Zero-rotation is along the vehicle body x-axis. This field is required if orientation is set to MAV_SENSOR_ROTATION_CUSTOM. Set it to 0 if invalid.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

MAVLINK_WIP
static inline void mavlink_msg_distance_sensor_info_send(mavlink_channel_t chan, uint8_t id, uint8_t type, float min_distance, float max_distance, uint8_t orientation, float horizontal_fov, float vertical_fov, const float *quaternion)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_LEN];
    _mav_put_float(buf, 0, min_distance);
    _mav_put_float(buf, 4, max_distance);
    _mav_put_float(buf, 8, horizontal_fov);
    _mav_put_float(buf, 12, vertical_fov);
    _mav_put_uint8_t(buf, 16, id);
    _mav_put_uint8_t(buf, 17, type);
    _mav_put_uint8_t(buf, 18, orientation);
    _mav_put_float_array(buf, 19, quaternion, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO, buf, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_MIN_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_CRC);
#else
    mavlink_distance_sensor_info_t packet;
    packet.min_distance = min_distance;
    packet.max_distance = max_distance;
    packet.horizontal_fov = horizontal_fov;
    packet.vertical_fov = vertical_fov;
    packet.id = id;
    packet.type = type;
    packet.orientation = orientation;
    mav_array_memcpy(packet.quaternion, quaternion, sizeof(float)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO, (const char *)&packet, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_MIN_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_CRC);
#endif
}

/**
 * @brief Send a distance_sensor_info message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
MAVLINK_WIP
static inline void mavlink_msg_distance_sensor_info_send_struct(mavlink_channel_t chan, const mavlink_distance_sensor_info_t* distance_sensor_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_distance_sensor_info_send(chan, distance_sensor_info->id, distance_sensor_info->type, distance_sensor_info->min_distance, distance_sensor_info->max_distance, distance_sensor_info->orientation, distance_sensor_info->horizontal_fov, distance_sensor_info->vertical_fov, distance_sensor_info->quaternion);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO, (const char *)distance_sensor_info, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_MIN_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_CRC);
#endif
}

#if MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
MAVLINK_WIP
static inline void mavlink_msg_distance_sensor_info_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t id, uint8_t type, float min_distance, float max_distance, uint8_t orientation, float horizontal_fov, float vertical_fov, const float *quaternion)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, min_distance);
    _mav_put_float(buf, 4, max_distance);
    _mav_put_float(buf, 8, horizontal_fov);
    _mav_put_float(buf, 12, vertical_fov);
    _mav_put_uint8_t(buf, 16, id);
    _mav_put_uint8_t(buf, 17, type);
    _mav_put_uint8_t(buf, 18, orientation);
    _mav_put_float_array(buf, 19, quaternion, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO, buf, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_MIN_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_CRC);
#else
    mavlink_distance_sensor_info_t *packet = (mavlink_distance_sensor_info_t *)msgbuf;
    packet->min_distance = min_distance;
    packet->max_distance = max_distance;
    packet->horizontal_fov = horizontal_fov;
    packet->vertical_fov = vertical_fov;
    packet->id = id;
    packet->type = type;
    packet->orientation = orientation;
    mav_array_memcpy(packet->quaternion, quaternion, sizeof(float)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO, (const char *)packet, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_MIN_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_CRC);
#endif
}
#endif

#endif

// MESSAGE DISTANCE_SENSOR_INFO UNPACKING


/**
 * @brief Get field id from distance_sensor_info message
 *
 * @return  Sensor ID. Matches the id field of DISTANCE_SENSOR_V2.
 */
MAVLINK_WIP
static inline uint8_t mavlink_msg_distance_sensor_info_get_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  16);
}

/**
 * @brief Get field type from distance_sensor_info message
 *
 * @return  Type of distance sensor.
 */
MAVLINK_WIP
static inline uint8_t mavlink_msg_distance_sensor_info_get_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  17);
}

/**
 * @brief Get field min_distance from distance_sensor_info message
 *
 * @return [m] Minimum distance the sensor can measure.
 */
MAVLINK_WIP
static inline float mavlink_msg_distance_sensor_info_get_min_distance(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field max_distance from distance_sensor_info message
 *
 * @return [m] Maximum distance the sensor can measure.
 */
MAVLINK_WIP
static inline float mavlink_msg_distance_sensor_info_get_max_distance(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field orientation from distance_sensor_info message
 *
 * @return  Direction the sensor faces.
 */
MAVLINK_WIP
static inline uint8_t mavlink_msg_distance_sensor_info_get_orientation(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  18);
}

/**
 * @brief Get field horizontal_fov from distance_sensor_info message
 *
 * @return [rad] Horizontal Field of View (angle) where the distance measurement is valid. NaN if unknown.
 */
MAVLINK_WIP
static inline float mavlink_msg_distance_sensor_info_get_horizontal_fov(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field vertical_fov from distance_sensor_info message
 *
 * @return [rad] Vertical Field of View (angle) where the distance measurement is valid. NaN if unknown.
 */
MAVLINK_WIP
static inline float mavlink_msg_distance_sensor_info_get_vertical_fov(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field quaternion from distance_sensor_info message
 *
 * @return  Quaternion of the sensor orientation in vehicle body frame (w, x, y, z order, zero-rotation is 1, 0, 0, 0). Zero-rotation is along the vehicle body x-axis. This field is required if orientation is set to MAV_SENSOR_ROTATION_CUSTOM. Set it to 0 if invalid.
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_distance_sensor_info_get_quaternion(const mavlink_message_t* msg, float *quaternion)
{
    return _MAV_RETURN_float_array(msg, quaternion, 4,  19);
}

/**
 * @brief Decode a distance_sensor_info message into a struct
 *
 * @param msg The message to decode
 * @param distance_sensor_info C-struct to decode the message contents into
 */
MAVLINK_WIP
static inline void mavlink_msg_distance_sensor_info_decode(const mavlink_message_t* msg, mavlink_distance_sensor_info_t* distance_sensor_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    distance_sensor_info->min_distance = mavlink_msg_distance_sensor_info_get_min_distance(msg);
    distance_sensor_info->max_distance = mavlink_msg_distance_sensor_info_get_max_distance(msg);
    distance_sensor_info->horizontal_fov = mavlink_msg_distance_sensor_info_get_horizontal_fov(msg);
    distance_sensor_info->vertical_fov = mavlink_msg_distance_sensor_info_get_vertical_fov(msg);
    distance_sensor_info->id = mavlink_msg_distance_sensor_info_get_id(msg);
    distance_sensor_info->type = mavlink_msg_distance_sensor_info_get_type(msg);
    distance_sensor_info->orientation = mavlink_msg_distance_sensor_info_get_orientation(msg);
    mavlink_msg_distance_sensor_info_get_quaternion(msg, distance_sensor_info->quaternion);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_LEN? msg->len : MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_LEN;
        memset(distance_sensor_info, 0, MAVLINK_MSG_ID_DISTANCE_SENSOR_INFO_LEN);
    memcpy(distance_sensor_info, _MAV_PAYLOAD(msg), len);
#endif
}
