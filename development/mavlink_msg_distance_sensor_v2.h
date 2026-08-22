#pragma once
// MESSAGE DISTANCE_SENSOR_V2 PACKING

#include <stdint.h>

#define MAVLINK_MSG_ID_DISTANCE_SENSOR_V2 517


typedef struct __mavlink_distance_sensor_v2_t {
 uint32_t time_boot_ms; /*< [ms] Timestamp (time since system boot)*/
 float distance; /*< [m] Current distance reading. NaN if not provided.*/
 uint8_t id; /*<  Sensor ID. Matches the id field of DISTANCE_SENSOR_INFO.*/
 int8_t signal_quality; /*< [%] Signal quality (sensor-type specific). Represents the relation of the signal strength with the target reflectivity, distance, size or aspect, but normalised as a percentage. Values: [0-100], 0 = unusable signal, 100 = perfect signal. INT8_MAX = unknown/not provided.*/
} mavlink_distance_sensor_v2_t;

#define MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_LEN 10
#define MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_MIN_LEN 10
#define MAVLINK_MSG_ID_517_LEN 10
#define MAVLINK_MSG_ID_517_MIN_LEN 10

#define MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_CRC 126
#define MAVLINK_MSG_ID_517_CRC 126



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DISTANCE_SENSOR_V2 { \
    517, \
    "DISTANCE_SENSOR_V2", \
    4, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_distance_sensor_v2_t, time_boot_ms) }, \
         { "id", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_distance_sensor_v2_t, id) }, \
         { "distance", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_distance_sensor_v2_t, distance) }, \
         { "signal_quality", NULL, MAVLINK_TYPE_INT8_T, 0, 9, offsetof(mavlink_distance_sensor_v2_t, signal_quality) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DISTANCE_SENSOR_V2 { \
    "DISTANCE_SENSOR_V2", \
    4, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_distance_sensor_v2_t, time_boot_ms) }, \
         { "id", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_distance_sensor_v2_t, id) }, \
         { "distance", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_distance_sensor_v2_t, distance) }, \
         { "signal_quality", NULL, MAVLINK_TYPE_INT8_T, 0, 9, offsetof(mavlink_distance_sensor_v2_t, signal_quality) }, \
         } \
}
#endif

/**
 * @brief Pack a distance_sensor_v2 message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot)
 * @param id  Sensor ID. Matches the id field of DISTANCE_SENSOR_INFO.
 * @param distance [m] Current distance reading. NaN if not provided.
 * @param signal_quality [%] Signal quality (sensor-type specific). Represents the relation of the signal strength with the target reflectivity, distance, size or aspect, but normalised as a percentage. Values: [0-100], 0 = unusable signal, 100 = perfect signal. INT8_MAX = unknown/not provided.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_distance_sensor_v2_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, uint8_t id, float distance, int8_t signal_quality)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, distance);
    _mav_put_uint8_t(buf, 8, id);
    _mav_put_int8_t(buf, 9, signal_quality);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_LEN);
#else
    mavlink_distance_sensor_v2_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.distance = distance;
    packet.id = id;
    packet.signal_quality = signal_quality;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DISTANCE_SENSOR_V2;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_MIN_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_CRC);
}

/**
 * @brief Pack a distance_sensor_v2 message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot)
 * @param id  Sensor ID. Matches the id field of DISTANCE_SENSOR_INFO.
 * @param distance [m] Current distance reading. NaN if not provided.
 * @param signal_quality [%] Signal quality (sensor-type specific). Represents the relation of the signal strength with the target reflectivity, distance, size or aspect, but normalised as a percentage. Values: [0-100], 0 = unusable signal, 100 = perfect signal. INT8_MAX = unknown/not provided.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_distance_sensor_v2_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint32_t time_boot_ms, uint8_t id, float distance, int8_t signal_quality)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, distance);
    _mav_put_uint8_t(buf, 8, id);
    _mav_put_int8_t(buf, 9, signal_quality);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_LEN);
#else
    mavlink_distance_sensor_v2_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.distance = distance;
    packet.id = id;
    packet.signal_quality = signal_quality;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DISTANCE_SENSOR_V2;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_MIN_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_MIN_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_LEN);
#endif
}

/**
 * @brief Pack a distance_sensor_v2 message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms [ms] Timestamp (time since system boot)
 * @param id  Sensor ID. Matches the id field of DISTANCE_SENSOR_INFO.
 * @param distance [m] Current distance reading. NaN if not provided.
 * @param signal_quality [%] Signal quality (sensor-type specific). Represents the relation of the signal strength with the target reflectivity, distance, size or aspect, but normalised as a percentage. Values: [0-100], 0 = unusable signal, 100 = perfect signal. INT8_MAX = unknown/not provided.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_distance_sensor_v2_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,uint8_t id,float distance,int8_t signal_quality)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, distance);
    _mav_put_uint8_t(buf, 8, id);
    _mav_put_int8_t(buf, 9, signal_quality);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_LEN);
#else
    mavlink_distance_sensor_v2_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.distance = distance;
    packet.id = id;
    packet.signal_quality = signal_quality;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DISTANCE_SENSOR_V2;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_MIN_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_CRC);
}

/**
 * @brief Encode a distance_sensor_v2 struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param distance_sensor_v2 C-struct to read the message contents from
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_distance_sensor_v2_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_distance_sensor_v2_t* distance_sensor_v2)
{
    return mavlink_msg_distance_sensor_v2_pack(system_id, component_id, msg, distance_sensor_v2->time_boot_ms, distance_sensor_v2->id, distance_sensor_v2->distance, distance_sensor_v2->signal_quality);
}

/**
 * @brief Encode a distance_sensor_v2 struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param distance_sensor_v2 C-struct to read the message contents from
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_distance_sensor_v2_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_distance_sensor_v2_t* distance_sensor_v2)
{
    return mavlink_msg_distance_sensor_v2_pack_chan(system_id, component_id, chan, msg, distance_sensor_v2->time_boot_ms, distance_sensor_v2->id, distance_sensor_v2->distance, distance_sensor_v2->signal_quality);
}

/**
 * @brief Encode a distance_sensor_v2 struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param distance_sensor_v2 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_distance_sensor_v2_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_distance_sensor_v2_t* distance_sensor_v2)
{
    return mavlink_msg_distance_sensor_v2_pack_status(system_id, component_id, _status, msg,  distance_sensor_v2->time_boot_ms, distance_sensor_v2->id, distance_sensor_v2->distance, distance_sensor_v2->signal_quality);
}

/**
 * @brief Send a distance_sensor_v2 message
 * @param chan MAVLink channel to send the message
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot)
 * @param id  Sensor ID. Matches the id field of DISTANCE_SENSOR_INFO.
 * @param distance [m] Current distance reading. NaN if not provided.
 * @param signal_quality [%] Signal quality (sensor-type specific). Represents the relation of the signal strength with the target reflectivity, distance, size or aspect, but normalised as a percentage. Values: [0-100], 0 = unusable signal, 100 = perfect signal. INT8_MAX = unknown/not provided.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

MAVLINK_WIP
static inline void mavlink_msg_distance_sensor_v2_send(mavlink_channel_t chan, uint32_t time_boot_ms, uint8_t id, float distance, int8_t signal_quality)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, distance);
    _mav_put_uint8_t(buf, 8, id);
    _mav_put_int8_t(buf, 9, signal_quality);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2, buf, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_MIN_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_CRC);
#else
    mavlink_distance_sensor_v2_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.distance = distance;
    packet.id = id;
    packet.signal_quality = signal_quality;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2, (const char *)&packet, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_MIN_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_CRC);
#endif
}

/**
 * @brief Send a distance_sensor_v2 message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
MAVLINK_WIP
static inline void mavlink_msg_distance_sensor_v2_send_struct(mavlink_channel_t chan, const mavlink_distance_sensor_v2_t* distance_sensor_v2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_distance_sensor_v2_send(chan, distance_sensor_v2->time_boot_ms, distance_sensor_v2->id, distance_sensor_v2->distance, distance_sensor_v2->signal_quality);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2, (const char *)distance_sensor_v2, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_MIN_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_CRC);
#endif
}

#if MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
MAVLINK_WIP
static inline void mavlink_msg_distance_sensor_v2_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time_boot_ms, uint8_t id, float distance, int8_t signal_quality)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float(buf, 4, distance);
    _mav_put_uint8_t(buf, 8, id);
    _mav_put_int8_t(buf, 9, signal_quality);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2, buf, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_MIN_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_CRC);
#else
    mavlink_distance_sensor_v2_t *packet = (mavlink_distance_sensor_v2_t *)msgbuf;
    packet->time_boot_ms = time_boot_ms;
    packet->distance = distance;
    packet->id = id;
    packet->signal_quality = signal_quality;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2, (const char *)packet, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_MIN_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_LEN, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_CRC);
#endif
}
#endif

#endif

// MESSAGE DISTANCE_SENSOR_V2 UNPACKING


/**
 * @brief Get field time_boot_ms from distance_sensor_v2 message
 *
 * @return [ms] Timestamp (time since system boot)
 */
MAVLINK_WIP
static inline uint32_t mavlink_msg_distance_sensor_v2_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field id from distance_sensor_v2 message
 *
 * @return  Sensor ID. Matches the id field of DISTANCE_SENSOR_INFO.
 */
MAVLINK_WIP
static inline uint8_t mavlink_msg_distance_sensor_v2_get_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field distance from distance_sensor_v2 message
 *
 * @return [m] Current distance reading. NaN if not provided.
 */
MAVLINK_WIP
static inline float mavlink_msg_distance_sensor_v2_get_distance(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field signal_quality from distance_sensor_v2 message
 *
 * @return [%] Signal quality (sensor-type specific). Represents the relation of the signal strength with the target reflectivity, distance, size or aspect, but normalised as a percentage. Values: [0-100], 0 = unusable signal, 100 = perfect signal. INT8_MAX = unknown/not provided.
 */
MAVLINK_WIP
static inline int8_t mavlink_msg_distance_sensor_v2_get_signal_quality(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  9);
}

/**
 * @brief Decode a distance_sensor_v2 message into a struct
 *
 * @param msg The message to decode
 * @param distance_sensor_v2 C-struct to decode the message contents into
 */
MAVLINK_WIP
static inline void mavlink_msg_distance_sensor_v2_decode(const mavlink_message_t* msg, mavlink_distance_sensor_v2_t* distance_sensor_v2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    distance_sensor_v2->time_boot_ms = mavlink_msg_distance_sensor_v2_get_time_boot_ms(msg);
    distance_sensor_v2->distance = mavlink_msg_distance_sensor_v2_get_distance(msg);
    distance_sensor_v2->id = mavlink_msg_distance_sensor_v2_get_id(msg);
    distance_sensor_v2->signal_quality = mavlink_msg_distance_sensor_v2_get_signal_quality(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_LEN? msg->len : MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_LEN;
        memset(distance_sensor_v2, 0, MAVLINK_MSG_ID_DISTANCE_SENSOR_V2_LEN);
    memcpy(distance_sensor_v2, _MAV_PAYLOAD(msg), len);
#endif
}
