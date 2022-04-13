#pragma once
// MESSAGE JOYSTICK_STATE PACKING

#define MAVLINK_MSG_ID_JOYSTICK_STATE 513


typedef struct __mavlink_joystick_state_t {
 uint64_t time_usec; /*< [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.*/
 uint16_t axis_value[10]; /*<  Value of each joystick axis*/
 uint8_t type; /*<  Type of the MAV (quadrotor, helicopter, etc.), MAV_TYPE_JOYSTICK = 43*/
 uint8_t button_value[20]; /*<  Value of each joystick button*/
} mavlink_joystick_state_t;

#define MAVLINK_MSG_ID_JOYSTICK_STATE_LEN 49
#define MAVLINK_MSG_ID_JOYSTICK_STATE_MIN_LEN 49
#define MAVLINK_MSG_ID_513_LEN 49
#define MAVLINK_MSG_ID_513_MIN_LEN 49

#define MAVLINK_MSG_ID_JOYSTICK_STATE_CRC 138
#define MAVLINK_MSG_ID_513_CRC 138

#define MAVLINK_MSG_JOYSTICK_STATE_FIELD_AXIS_VALUE_LEN 10
#define MAVLINK_MSG_JOYSTICK_STATE_FIELD_BUTTON_VALUE_LEN 20

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_JOYSTICK_STATE { \
    513, \
    "JOYSTICK_STATE", \
    4, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_joystick_state_t, time_usec) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 28, offsetof(mavlink_joystick_state_t, type) }, \
         { "axis_value", NULL, MAVLINK_TYPE_UINT16_T, 10, 8, offsetof(mavlink_joystick_state_t, axis_value) }, \
         { "button_value", NULL, MAVLINK_TYPE_UINT8_T, 20, 29, offsetof(mavlink_joystick_state_t, button_value) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_JOYSTICK_STATE { \
    "JOYSTICK_STATE", \
    4, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_joystick_state_t, time_usec) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 28, offsetof(mavlink_joystick_state_t, type) }, \
         { "axis_value", NULL, MAVLINK_TYPE_UINT16_T, 10, 8, offsetof(mavlink_joystick_state_t, axis_value) }, \
         { "button_value", NULL, MAVLINK_TYPE_UINT8_T, 20, 29, offsetof(mavlink_joystick_state_t, button_value) }, \
         } \
}
#endif

/**
 * @brief Pack a joystick_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param type  Type of the MAV (quadrotor, helicopter, etc.), MAV_TYPE_JOYSTICK = 43
 * @param axis_value  Value of each joystick axis
 * @param button_value  Value of each joystick button
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_joystick_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, uint8_t type, const uint16_t *axis_value, const uint8_t *button_value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_JOYSTICK_STATE_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint8_t(buf, 28, type);
    _mav_put_uint16_t_array(buf, 8, axis_value, 10);
    _mav_put_uint8_t_array(buf, 29, button_value, 20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_JOYSTICK_STATE_LEN);
#else
    mavlink_joystick_state_t packet;
    packet.time_usec = time_usec;
    packet.type = type;
    mav_array_memcpy(packet.axis_value, axis_value, sizeof(uint16_t)*10);
    mav_array_memcpy(packet.button_value, button_value, sizeof(uint8_t)*20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_JOYSTICK_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_JOYSTICK_STATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_JOYSTICK_STATE_MIN_LEN, MAVLINK_MSG_ID_JOYSTICK_STATE_LEN, MAVLINK_MSG_ID_JOYSTICK_STATE_CRC);
}

/**
 * @brief Pack a joystick_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param type  Type of the MAV (quadrotor, helicopter, etc.), MAV_TYPE_JOYSTICK = 43
 * @param axis_value  Value of each joystick axis
 * @param button_value  Value of each joystick button
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_joystick_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,uint8_t type,const uint16_t *axis_value,const uint8_t *button_value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_JOYSTICK_STATE_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint8_t(buf, 28, type);
    _mav_put_uint16_t_array(buf, 8, axis_value, 10);
    _mav_put_uint8_t_array(buf, 29, button_value, 20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_JOYSTICK_STATE_LEN);
#else
    mavlink_joystick_state_t packet;
    packet.time_usec = time_usec;
    packet.type = type;
    mav_array_memcpy(packet.axis_value, axis_value, sizeof(uint16_t)*10);
    mav_array_memcpy(packet.button_value, button_value, sizeof(uint8_t)*20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_JOYSTICK_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_JOYSTICK_STATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_JOYSTICK_STATE_MIN_LEN, MAVLINK_MSG_ID_JOYSTICK_STATE_LEN, MAVLINK_MSG_ID_JOYSTICK_STATE_CRC);
}

/**
 * @brief Encode a joystick_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param joystick_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_joystick_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_joystick_state_t* joystick_state)
{
    return mavlink_msg_joystick_state_pack(system_id, component_id, msg, joystick_state->time_usec, joystick_state->type, joystick_state->axis_value, joystick_state->button_value);
}

/**
 * @brief Encode a joystick_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param joystick_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_joystick_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_joystick_state_t* joystick_state)
{
    return mavlink_msg_joystick_state_pack_chan(system_id, component_id, chan, msg, joystick_state->time_usec, joystick_state->type, joystick_state->axis_value, joystick_state->button_value);
}

/**
 * @brief Send a joystick_state message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param type  Type of the MAV (quadrotor, helicopter, etc.), MAV_TYPE_JOYSTICK = 43
 * @param axis_value  Value of each joystick axis
 * @param button_value  Value of each joystick button
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_joystick_state_send(mavlink_channel_t chan, uint64_t time_usec, uint8_t type, const uint16_t *axis_value, const uint8_t *button_value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_JOYSTICK_STATE_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint8_t(buf, 28, type);
    _mav_put_uint16_t_array(buf, 8, axis_value, 10);
    _mav_put_uint8_t_array(buf, 29, button_value, 20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_JOYSTICK_STATE, buf, MAVLINK_MSG_ID_JOYSTICK_STATE_MIN_LEN, MAVLINK_MSG_ID_JOYSTICK_STATE_LEN, MAVLINK_MSG_ID_JOYSTICK_STATE_CRC);
#else
    mavlink_joystick_state_t packet;
    packet.time_usec = time_usec;
    packet.type = type;
    mav_array_memcpy(packet.axis_value, axis_value, sizeof(uint16_t)*10);
    mav_array_memcpy(packet.button_value, button_value, sizeof(uint8_t)*20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_JOYSTICK_STATE, (const char *)&packet, MAVLINK_MSG_ID_JOYSTICK_STATE_MIN_LEN, MAVLINK_MSG_ID_JOYSTICK_STATE_LEN, MAVLINK_MSG_ID_JOYSTICK_STATE_CRC);
#endif
}

/**
 * @brief Send a joystick_state message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_joystick_state_send_struct(mavlink_channel_t chan, const mavlink_joystick_state_t* joystick_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_joystick_state_send(chan, joystick_state->time_usec, joystick_state->type, joystick_state->axis_value, joystick_state->button_value);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_JOYSTICK_STATE, (const char *)joystick_state, MAVLINK_MSG_ID_JOYSTICK_STATE_MIN_LEN, MAVLINK_MSG_ID_JOYSTICK_STATE_LEN, MAVLINK_MSG_ID_JOYSTICK_STATE_CRC);
#endif
}

#if MAVLINK_MSG_ID_JOYSTICK_STATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_joystick_state_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, uint8_t type, const uint16_t *axis_value, const uint8_t *button_value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint8_t(buf, 28, type);
    _mav_put_uint16_t_array(buf, 8, axis_value, 10);
    _mav_put_uint8_t_array(buf, 29, button_value, 20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_JOYSTICK_STATE, buf, MAVLINK_MSG_ID_JOYSTICK_STATE_MIN_LEN, MAVLINK_MSG_ID_JOYSTICK_STATE_LEN, MAVLINK_MSG_ID_JOYSTICK_STATE_CRC);
#else
    mavlink_joystick_state_t *packet = (mavlink_joystick_state_t *)msgbuf;
    packet->time_usec = time_usec;
    packet->type = type;
    mav_array_memcpy(packet->axis_value, axis_value, sizeof(uint16_t)*10);
    mav_array_memcpy(packet->button_value, button_value, sizeof(uint8_t)*20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_JOYSTICK_STATE, (const char *)packet, MAVLINK_MSG_ID_JOYSTICK_STATE_MIN_LEN, MAVLINK_MSG_ID_JOYSTICK_STATE_LEN, MAVLINK_MSG_ID_JOYSTICK_STATE_CRC);
#endif
}
#endif

#endif

// MESSAGE JOYSTICK_STATE UNPACKING


/**
 * @brief Get field time_usec from joystick_state message
 *
 * @return [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 */
static inline uint64_t mavlink_msg_joystick_state_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field type from joystick_state message
 *
 * @return  Type of the MAV (quadrotor, helicopter, etc.), MAV_TYPE_JOYSTICK = 43
 */
static inline uint8_t mavlink_msg_joystick_state_get_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  28);
}

/**
 * @brief Get field axis_value from joystick_state message
 *
 * @return  Value of each joystick axis
 */
static inline uint16_t mavlink_msg_joystick_state_get_axis_value(const mavlink_message_t* msg, uint16_t *axis_value)
{
    return _MAV_RETURN_uint16_t_array(msg, axis_value, 10,  8);
}

/**
 * @brief Get field button_value from joystick_state message
 *
 * @return  Value of each joystick button
 */
static inline uint16_t mavlink_msg_joystick_state_get_button_value(const mavlink_message_t* msg, uint8_t *button_value)
{
    return _MAV_RETURN_uint8_t_array(msg, button_value, 20,  29);
}

/**
 * @brief Decode a joystick_state message into a struct
 *
 * @param msg The message to decode
 * @param joystick_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_joystick_state_decode(const mavlink_message_t* msg, mavlink_joystick_state_t* joystick_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    joystick_state->time_usec = mavlink_msg_joystick_state_get_time_usec(msg);
    mavlink_msg_joystick_state_get_axis_value(msg, joystick_state->axis_value);
    joystick_state->type = mavlink_msg_joystick_state_get_type(msg);
    mavlink_msg_joystick_state_get_button_value(msg, joystick_state->button_value);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_JOYSTICK_STATE_LEN? msg->len : MAVLINK_MSG_ID_JOYSTICK_STATE_LEN;
        memset(joystick_state, 0, MAVLINK_MSG_ID_JOYSTICK_STATE_LEN);
    memcpy(joystick_state, _MAV_PAYLOAD(msg), len);
#endif
}
