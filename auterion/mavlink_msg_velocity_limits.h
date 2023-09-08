#pragma once
// MESSAGE VELOCITY_LIMITS PACKING

#define MAVLINK_MSG_ID_VELOCITY_LIMITS 354


typedef struct __mavlink_velocity_limits_t {
 float horizontal_velocity; /*< [m/s] Limit for horizontal movement in MAV_FRAME LOCAL. NaN: Use vehicle default speed.*/
 float vertical_velocity; /*< [m/s] Limit for vertical movement in MAV_FRAME LOCAL. NaN: Use vehicle default speed.*/
 float yaw_rate; /*< [rad/s] Limit for vehicle turn rate around its yaw axis. NaN: Use vehicle default rate.*/
} mavlink_velocity_limits_t;

#define MAVLINK_MSG_ID_VELOCITY_LIMITS_LEN 12
#define MAVLINK_MSG_ID_VELOCITY_LIMITS_MIN_LEN 12
#define MAVLINK_MSG_ID_354_LEN 12
#define MAVLINK_MSG_ID_354_MIN_LEN 12

#define MAVLINK_MSG_ID_VELOCITY_LIMITS_CRC 69
#define MAVLINK_MSG_ID_354_CRC 69



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_VELOCITY_LIMITS { \
    354, \
    "VELOCITY_LIMITS", \
    3, \
    {  { "horizontal_velocity", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_velocity_limits_t, horizontal_velocity) }, \
         { "vertical_velocity", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_velocity_limits_t, vertical_velocity) }, \
         { "yaw_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_velocity_limits_t, yaw_rate) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_VELOCITY_LIMITS { \
    "VELOCITY_LIMITS", \
    3, \
    {  { "horizontal_velocity", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_velocity_limits_t, horizontal_velocity) }, \
         { "vertical_velocity", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_velocity_limits_t, vertical_velocity) }, \
         { "yaw_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_velocity_limits_t, yaw_rate) }, \
         } \
}
#endif

/**
 * @brief Pack a velocity_limits message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param horizontal_velocity [m/s] Limit for horizontal movement in MAV_FRAME LOCAL. NaN: Use vehicle default speed.
 * @param vertical_velocity [m/s] Limit for vertical movement in MAV_FRAME LOCAL. NaN: Use vehicle default speed.
 * @param yaw_rate [rad/s] Limit for vehicle turn rate around its yaw axis. NaN: Use vehicle default rate.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_velocity_limits_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float horizontal_velocity, float vertical_velocity, float yaw_rate)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VELOCITY_LIMITS_LEN];
    _mav_put_float(buf, 0, horizontal_velocity);
    _mav_put_float(buf, 4, vertical_velocity);
    _mav_put_float(buf, 8, yaw_rate);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VELOCITY_LIMITS_LEN);
#else
    mavlink_velocity_limits_t packet;
    packet.horizontal_velocity = horizontal_velocity;
    packet.vertical_velocity = vertical_velocity;
    packet.yaw_rate = yaw_rate;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VELOCITY_LIMITS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VELOCITY_LIMITS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VELOCITY_LIMITS_MIN_LEN, MAVLINK_MSG_ID_VELOCITY_LIMITS_LEN, MAVLINK_MSG_ID_VELOCITY_LIMITS_CRC);
}

/**
 * @brief Pack a velocity_limits message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param horizontal_velocity [m/s] Limit for horizontal movement in MAV_FRAME LOCAL. NaN: Use vehicle default speed.
 * @param vertical_velocity [m/s] Limit for vertical movement in MAV_FRAME LOCAL. NaN: Use vehicle default speed.
 * @param yaw_rate [rad/s] Limit for vehicle turn rate around its yaw axis. NaN: Use vehicle default rate.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_velocity_limits_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float horizontal_velocity,float vertical_velocity,float yaw_rate)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VELOCITY_LIMITS_LEN];
    _mav_put_float(buf, 0, horizontal_velocity);
    _mav_put_float(buf, 4, vertical_velocity);
    _mav_put_float(buf, 8, yaw_rate);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VELOCITY_LIMITS_LEN);
#else
    mavlink_velocity_limits_t packet;
    packet.horizontal_velocity = horizontal_velocity;
    packet.vertical_velocity = vertical_velocity;
    packet.yaw_rate = yaw_rate;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VELOCITY_LIMITS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VELOCITY_LIMITS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_VELOCITY_LIMITS_MIN_LEN, MAVLINK_MSG_ID_VELOCITY_LIMITS_LEN, MAVLINK_MSG_ID_VELOCITY_LIMITS_CRC);
}

/**
 * @brief Encode a velocity_limits struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param velocity_limits C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_velocity_limits_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_velocity_limits_t* velocity_limits)
{
    return mavlink_msg_velocity_limits_pack(system_id, component_id, msg, velocity_limits->horizontal_velocity, velocity_limits->vertical_velocity, velocity_limits->yaw_rate);
}

/**
 * @brief Encode a velocity_limits struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param velocity_limits C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_velocity_limits_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_velocity_limits_t* velocity_limits)
{
    return mavlink_msg_velocity_limits_pack_chan(system_id, component_id, chan, msg, velocity_limits->horizontal_velocity, velocity_limits->vertical_velocity, velocity_limits->yaw_rate);
}

/**
 * @brief Send a velocity_limits message
 * @param chan MAVLink channel to send the message
 *
 * @param horizontal_velocity [m/s] Limit for horizontal movement in MAV_FRAME LOCAL. NaN: Use vehicle default speed.
 * @param vertical_velocity [m/s] Limit for vertical movement in MAV_FRAME LOCAL. NaN: Use vehicle default speed.
 * @param yaw_rate [rad/s] Limit for vehicle turn rate around its yaw axis. NaN: Use vehicle default rate.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_velocity_limits_send(mavlink_channel_t chan, float horizontal_velocity, float vertical_velocity, float yaw_rate)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VELOCITY_LIMITS_LEN];
    _mav_put_float(buf, 0, horizontal_velocity);
    _mav_put_float(buf, 4, vertical_velocity);
    _mav_put_float(buf, 8, yaw_rate);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VELOCITY_LIMITS, buf, MAVLINK_MSG_ID_VELOCITY_LIMITS_MIN_LEN, MAVLINK_MSG_ID_VELOCITY_LIMITS_LEN, MAVLINK_MSG_ID_VELOCITY_LIMITS_CRC);
#else
    mavlink_velocity_limits_t packet;
    packet.horizontal_velocity = horizontal_velocity;
    packet.vertical_velocity = vertical_velocity;
    packet.yaw_rate = yaw_rate;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VELOCITY_LIMITS, (const char *)&packet, MAVLINK_MSG_ID_VELOCITY_LIMITS_MIN_LEN, MAVLINK_MSG_ID_VELOCITY_LIMITS_LEN, MAVLINK_MSG_ID_VELOCITY_LIMITS_CRC);
#endif
}

/**
 * @brief Send a velocity_limits message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_velocity_limits_send_struct(mavlink_channel_t chan, const mavlink_velocity_limits_t* velocity_limits)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_velocity_limits_send(chan, velocity_limits->horizontal_velocity, velocity_limits->vertical_velocity, velocity_limits->yaw_rate);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VELOCITY_LIMITS, (const char *)velocity_limits, MAVLINK_MSG_ID_VELOCITY_LIMITS_MIN_LEN, MAVLINK_MSG_ID_VELOCITY_LIMITS_LEN, MAVLINK_MSG_ID_VELOCITY_LIMITS_CRC);
#endif
}

#if MAVLINK_MSG_ID_VELOCITY_LIMITS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_velocity_limits_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float horizontal_velocity, float vertical_velocity, float yaw_rate)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, horizontal_velocity);
    _mav_put_float(buf, 4, vertical_velocity);
    _mav_put_float(buf, 8, yaw_rate);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VELOCITY_LIMITS, buf, MAVLINK_MSG_ID_VELOCITY_LIMITS_MIN_LEN, MAVLINK_MSG_ID_VELOCITY_LIMITS_LEN, MAVLINK_MSG_ID_VELOCITY_LIMITS_CRC);
#else
    mavlink_velocity_limits_t *packet = (mavlink_velocity_limits_t *)msgbuf;
    packet->horizontal_velocity = horizontal_velocity;
    packet->vertical_velocity = vertical_velocity;
    packet->yaw_rate = yaw_rate;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VELOCITY_LIMITS, (const char *)packet, MAVLINK_MSG_ID_VELOCITY_LIMITS_MIN_LEN, MAVLINK_MSG_ID_VELOCITY_LIMITS_LEN, MAVLINK_MSG_ID_VELOCITY_LIMITS_CRC);
#endif
}
#endif

#endif

// MESSAGE VELOCITY_LIMITS UNPACKING


/**
 * @brief Get field horizontal_velocity from velocity_limits message
 *
 * @return [m/s] Limit for horizontal movement in MAV_FRAME LOCAL. NaN: Use vehicle default speed.
 */
static inline float mavlink_msg_velocity_limits_get_horizontal_velocity(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field vertical_velocity from velocity_limits message
 *
 * @return [m/s] Limit for vertical movement in MAV_FRAME LOCAL. NaN: Use vehicle default speed.
 */
static inline float mavlink_msg_velocity_limits_get_vertical_velocity(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field yaw_rate from velocity_limits message
 *
 * @return [rad/s] Limit for vehicle turn rate around its yaw axis. NaN: Use vehicle default rate.
 */
static inline float mavlink_msg_velocity_limits_get_yaw_rate(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Decode a velocity_limits message into a struct
 *
 * @param msg The message to decode
 * @param velocity_limits C-struct to decode the message contents into
 */
static inline void mavlink_msg_velocity_limits_decode(const mavlink_message_t* msg, mavlink_velocity_limits_t* velocity_limits)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    velocity_limits->horizontal_velocity = mavlink_msg_velocity_limits_get_horizontal_velocity(msg);
    velocity_limits->vertical_velocity = mavlink_msg_velocity_limits_get_vertical_velocity(msg);
    velocity_limits->yaw_rate = mavlink_msg_velocity_limits_get_yaw_rate(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_VELOCITY_LIMITS_LEN? msg->len : MAVLINK_MSG_ID_VELOCITY_LIMITS_LEN;
        memset(velocity_limits, 0, MAVLINK_MSG_ID_VELOCITY_LIMITS_LEN);
    memcpy(velocity_limits, _MAV_PAYLOAD(msg), len);
#endif
}
