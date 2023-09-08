#pragma once
// MESSAGE MOTOR_INFO PACKING

#define MAVLINK_MSG_ID_MOTOR_INFO 13000


typedef struct __mavlink_motor_info_t {
 uint64_t total_time; /*< [s]  Total accumulated usage time*/
 int16_t temperature; /*< [cdegC] Temperature of motor. INT16_MAX if unknown.*/
 uint8_t index; /*<   Motor index number starting with index 1. 0 if unknown. */
 uint8_t type; /*<   The type of motor, TODO: define an enum */
} mavlink_motor_info_t;

#define MAVLINK_MSG_ID_MOTOR_INFO_LEN 12
#define MAVLINK_MSG_ID_MOTOR_INFO_MIN_LEN 12
#define MAVLINK_MSG_ID_13000_LEN 12
#define MAVLINK_MSG_ID_13000_MIN_LEN 12

#define MAVLINK_MSG_ID_MOTOR_INFO_CRC 8
#define MAVLINK_MSG_ID_13000_CRC 8



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MOTOR_INFO { \
    13000, \
    "MOTOR_INFO", \
    4, \
    {  { "index", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_motor_info_t, index) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_motor_info_t, type) }, \
         { "total_time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_motor_info_t, total_time) }, \
         { "temperature", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_motor_info_t, temperature) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MOTOR_INFO { \
    "MOTOR_INFO", \
    4, \
    {  { "index", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_motor_info_t, index) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_motor_info_t, type) }, \
         { "total_time", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_motor_info_t, total_time) }, \
         { "temperature", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_motor_info_t, temperature) }, \
         } \
}
#endif

/**
 * @brief Pack a motor_info message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param index   Motor index number starting with index 1. 0 if unknown. 
 * @param type   The type of motor, TODO: define an enum 
 * @param total_time [s]  Total accumulated usage time
 * @param temperature [cdegC] Temperature of motor. INT16_MAX if unknown.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_motor_info_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t index, uint8_t type, uint64_t total_time, int16_t temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MOTOR_INFO_LEN];
    _mav_put_uint64_t(buf, 0, total_time);
    _mav_put_int16_t(buf, 8, temperature);
    _mav_put_uint8_t(buf, 10, index);
    _mav_put_uint8_t(buf, 11, type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MOTOR_INFO_LEN);
#else
    mavlink_motor_info_t packet;
    packet.total_time = total_time;
    packet.temperature = temperature;
    packet.index = index;
    packet.type = type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MOTOR_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MOTOR_INFO;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MOTOR_INFO_MIN_LEN, MAVLINK_MSG_ID_MOTOR_INFO_LEN, MAVLINK_MSG_ID_MOTOR_INFO_CRC);
}

/**
 * @brief Pack a motor_info message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param index   Motor index number starting with index 1. 0 if unknown. 
 * @param type   The type of motor, TODO: define an enum 
 * @param total_time [s]  Total accumulated usage time
 * @param temperature [cdegC] Temperature of motor. INT16_MAX if unknown.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_motor_info_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t index,uint8_t type,uint64_t total_time,int16_t temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MOTOR_INFO_LEN];
    _mav_put_uint64_t(buf, 0, total_time);
    _mav_put_int16_t(buf, 8, temperature);
    _mav_put_uint8_t(buf, 10, index);
    _mav_put_uint8_t(buf, 11, type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MOTOR_INFO_LEN);
#else
    mavlink_motor_info_t packet;
    packet.total_time = total_time;
    packet.temperature = temperature;
    packet.index = index;
    packet.type = type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MOTOR_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MOTOR_INFO;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MOTOR_INFO_MIN_LEN, MAVLINK_MSG_ID_MOTOR_INFO_LEN, MAVLINK_MSG_ID_MOTOR_INFO_CRC);
}

/**
 * @brief Encode a motor_info struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param motor_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_motor_info_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_motor_info_t* motor_info)
{
    return mavlink_msg_motor_info_pack(system_id, component_id, msg, motor_info->index, motor_info->type, motor_info->total_time, motor_info->temperature);
}

/**
 * @brief Encode a motor_info struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param motor_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_motor_info_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_motor_info_t* motor_info)
{
    return mavlink_msg_motor_info_pack_chan(system_id, component_id, chan, msg, motor_info->index, motor_info->type, motor_info->total_time, motor_info->temperature);
}

/**
 * @brief Send a motor_info message
 * @param chan MAVLink channel to send the message
 *
 * @param index   Motor index number starting with index 1. 0 if unknown. 
 * @param type   The type of motor, TODO: define an enum 
 * @param total_time [s]  Total accumulated usage time
 * @param temperature [cdegC] Temperature of motor. INT16_MAX if unknown.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_motor_info_send(mavlink_channel_t chan, uint8_t index, uint8_t type, uint64_t total_time, int16_t temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MOTOR_INFO_LEN];
    _mav_put_uint64_t(buf, 0, total_time);
    _mav_put_int16_t(buf, 8, temperature);
    _mav_put_uint8_t(buf, 10, index);
    _mav_put_uint8_t(buf, 11, type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_INFO, buf, MAVLINK_MSG_ID_MOTOR_INFO_MIN_LEN, MAVLINK_MSG_ID_MOTOR_INFO_LEN, MAVLINK_MSG_ID_MOTOR_INFO_CRC);
#else
    mavlink_motor_info_t packet;
    packet.total_time = total_time;
    packet.temperature = temperature;
    packet.index = index;
    packet.type = type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_INFO, (const char *)&packet, MAVLINK_MSG_ID_MOTOR_INFO_MIN_LEN, MAVLINK_MSG_ID_MOTOR_INFO_LEN, MAVLINK_MSG_ID_MOTOR_INFO_CRC);
#endif
}

/**
 * @brief Send a motor_info message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_motor_info_send_struct(mavlink_channel_t chan, const mavlink_motor_info_t* motor_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_motor_info_send(chan, motor_info->index, motor_info->type, motor_info->total_time, motor_info->temperature);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_INFO, (const char *)motor_info, MAVLINK_MSG_ID_MOTOR_INFO_MIN_LEN, MAVLINK_MSG_ID_MOTOR_INFO_LEN, MAVLINK_MSG_ID_MOTOR_INFO_CRC);
#endif
}

#if MAVLINK_MSG_ID_MOTOR_INFO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_motor_info_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t index, uint8_t type, uint64_t total_time, int16_t temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, total_time);
    _mav_put_int16_t(buf, 8, temperature);
    _mav_put_uint8_t(buf, 10, index);
    _mav_put_uint8_t(buf, 11, type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_INFO, buf, MAVLINK_MSG_ID_MOTOR_INFO_MIN_LEN, MAVLINK_MSG_ID_MOTOR_INFO_LEN, MAVLINK_MSG_ID_MOTOR_INFO_CRC);
#else
    mavlink_motor_info_t *packet = (mavlink_motor_info_t *)msgbuf;
    packet->total_time = total_time;
    packet->temperature = temperature;
    packet->index = index;
    packet->type = type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_INFO, (const char *)packet, MAVLINK_MSG_ID_MOTOR_INFO_MIN_LEN, MAVLINK_MSG_ID_MOTOR_INFO_LEN, MAVLINK_MSG_ID_MOTOR_INFO_CRC);
#endif
}
#endif

#endif

// MESSAGE MOTOR_INFO UNPACKING


/**
 * @brief Get field index from motor_info message
 *
 * @return   Motor index number starting with index 1. 0 if unknown. 
 */
static inline uint8_t mavlink_msg_motor_info_get_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  10);
}

/**
 * @brief Get field type from motor_info message
 *
 * @return   The type of motor, TODO: define an enum 
 */
static inline uint8_t mavlink_msg_motor_info_get_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  11);
}

/**
 * @brief Get field total_time from motor_info message
 *
 * @return [s]  Total accumulated usage time
 */
static inline uint64_t mavlink_msg_motor_info_get_total_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field temperature from motor_info message
 *
 * @return [cdegC] Temperature of motor. INT16_MAX if unknown.
 */
static inline int16_t mavlink_msg_motor_info_get_temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Decode a motor_info message into a struct
 *
 * @param msg The message to decode
 * @param motor_info C-struct to decode the message contents into
 */
static inline void mavlink_msg_motor_info_decode(const mavlink_message_t* msg, mavlink_motor_info_t* motor_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    motor_info->total_time = mavlink_msg_motor_info_get_total_time(msg);
    motor_info->temperature = mavlink_msg_motor_info_get_temperature(msg);
    motor_info->index = mavlink_msg_motor_info_get_index(msg);
    motor_info->type = mavlink_msg_motor_info_get_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MOTOR_INFO_LEN? msg->len : MAVLINK_MSG_ID_MOTOR_INFO_LEN;
        memset(motor_info, 0, MAVLINK_MSG_ID_MOTOR_INFO_LEN);
    memcpy(motor_info, _MAV_PAYLOAD(msg), len);
#endif
}
