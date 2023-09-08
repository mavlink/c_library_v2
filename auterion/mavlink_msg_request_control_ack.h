#pragma once
// MESSAGE REQUEST_CONTROL_ACK PACKING

#define MAVLINK_MSG_ID_REQUEST_CONTROL_ACK 443


typedef struct __mavlink_request_control_ack_t {
 uint8_t control_target; /*<  Control target which was processed.*/
 uint8_t error_code; /*<  Error code response.*/
} mavlink_request_control_ack_t;

#define MAVLINK_MSG_ID_REQUEST_CONTROL_ACK_LEN 2
#define MAVLINK_MSG_ID_REQUEST_CONTROL_ACK_MIN_LEN 2
#define MAVLINK_MSG_ID_443_LEN 2
#define MAVLINK_MSG_ID_443_MIN_LEN 2

#define MAVLINK_MSG_ID_REQUEST_CONTROL_ACK_CRC 131
#define MAVLINK_MSG_ID_443_CRC 131



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_REQUEST_CONTROL_ACK { \
    443, \
    "REQUEST_CONTROL_ACK", \
    2, \
    {  { "control_target", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_request_control_ack_t, control_target) }, \
         { "error_code", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_request_control_ack_t, error_code) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_REQUEST_CONTROL_ACK { \
    "REQUEST_CONTROL_ACK", \
    2, \
    {  { "control_target", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_request_control_ack_t, control_target) }, \
         { "error_code", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_request_control_ack_t, error_code) }, \
         } \
}
#endif

/**
 * @brief Pack a request_control_ack message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param control_target  Control target which was processed.
 * @param error_code  Error code response.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_request_control_ack_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t control_target, uint8_t error_code)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_REQUEST_CONTROL_ACK_LEN];
    _mav_put_uint8_t(buf, 0, control_target);
    _mav_put_uint8_t(buf, 1, error_code);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_REQUEST_CONTROL_ACK_LEN);
#else
    mavlink_request_control_ack_t packet;
    packet.control_target = control_target;
    packet.error_code = error_code;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_REQUEST_CONTROL_ACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_REQUEST_CONTROL_ACK;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_REQUEST_CONTROL_ACK_MIN_LEN, MAVLINK_MSG_ID_REQUEST_CONTROL_ACK_LEN, MAVLINK_MSG_ID_REQUEST_CONTROL_ACK_CRC);
}

/**
 * @brief Pack a request_control_ack message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param control_target  Control target which was processed.
 * @param error_code  Error code response.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_request_control_ack_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t control_target,uint8_t error_code)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_REQUEST_CONTROL_ACK_LEN];
    _mav_put_uint8_t(buf, 0, control_target);
    _mav_put_uint8_t(buf, 1, error_code);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_REQUEST_CONTROL_ACK_LEN);
#else
    mavlink_request_control_ack_t packet;
    packet.control_target = control_target;
    packet.error_code = error_code;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_REQUEST_CONTROL_ACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_REQUEST_CONTROL_ACK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_REQUEST_CONTROL_ACK_MIN_LEN, MAVLINK_MSG_ID_REQUEST_CONTROL_ACK_LEN, MAVLINK_MSG_ID_REQUEST_CONTROL_ACK_CRC);
}

/**
 * @brief Encode a request_control_ack struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param request_control_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_request_control_ack_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_request_control_ack_t* request_control_ack)
{
    return mavlink_msg_request_control_ack_pack(system_id, component_id, msg, request_control_ack->control_target, request_control_ack->error_code);
}

/**
 * @brief Encode a request_control_ack struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param request_control_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_request_control_ack_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_request_control_ack_t* request_control_ack)
{
    return mavlink_msg_request_control_ack_pack_chan(system_id, component_id, chan, msg, request_control_ack->control_target, request_control_ack->error_code);
}

/**
 * @brief Send a request_control_ack message
 * @param chan MAVLink channel to send the message
 *
 * @param control_target  Control target which was processed.
 * @param error_code  Error code response.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_request_control_ack_send(mavlink_channel_t chan, uint8_t control_target, uint8_t error_code)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_REQUEST_CONTROL_ACK_LEN];
    _mav_put_uint8_t(buf, 0, control_target);
    _mav_put_uint8_t(buf, 1, error_code);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REQUEST_CONTROL_ACK, buf, MAVLINK_MSG_ID_REQUEST_CONTROL_ACK_MIN_LEN, MAVLINK_MSG_ID_REQUEST_CONTROL_ACK_LEN, MAVLINK_MSG_ID_REQUEST_CONTROL_ACK_CRC);
#else
    mavlink_request_control_ack_t packet;
    packet.control_target = control_target;
    packet.error_code = error_code;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REQUEST_CONTROL_ACK, (const char *)&packet, MAVLINK_MSG_ID_REQUEST_CONTROL_ACK_MIN_LEN, MAVLINK_MSG_ID_REQUEST_CONTROL_ACK_LEN, MAVLINK_MSG_ID_REQUEST_CONTROL_ACK_CRC);
#endif
}

/**
 * @brief Send a request_control_ack message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_request_control_ack_send_struct(mavlink_channel_t chan, const mavlink_request_control_ack_t* request_control_ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_request_control_ack_send(chan, request_control_ack->control_target, request_control_ack->error_code);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REQUEST_CONTROL_ACK, (const char *)request_control_ack, MAVLINK_MSG_ID_REQUEST_CONTROL_ACK_MIN_LEN, MAVLINK_MSG_ID_REQUEST_CONTROL_ACK_LEN, MAVLINK_MSG_ID_REQUEST_CONTROL_ACK_CRC);
#endif
}

#if MAVLINK_MSG_ID_REQUEST_CONTROL_ACK_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_request_control_ack_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t control_target, uint8_t error_code)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, control_target);
    _mav_put_uint8_t(buf, 1, error_code);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REQUEST_CONTROL_ACK, buf, MAVLINK_MSG_ID_REQUEST_CONTROL_ACK_MIN_LEN, MAVLINK_MSG_ID_REQUEST_CONTROL_ACK_LEN, MAVLINK_MSG_ID_REQUEST_CONTROL_ACK_CRC);
#else
    mavlink_request_control_ack_t *packet = (mavlink_request_control_ack_t *)msgbuf;
    packet->control_target = control_target;
    packet->error_code = error_code;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REQUEST_CONTROL_ACK, (const char *)packet, MAVLINK_MSG_ID_REQUEST_CONTROL_ACK_MIN_LEN, MAVLINK_MSG_ID_REQUEST_CONTROL_ACK_LEN, MAVLINK_MSG_ID_REQUEST_CONTROL_ACK_CRC);
#endif
}
#endif

#endif

// MESSAGE REQUEST_CONTROL_ACK UNPACKING


/**
 * @brief Get field control_target from request_control_ack message
 *
 * @return  Control target which was processed.
 */
static inline uint8_t mavlink_msg_request_control_ack_get_control_target(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field error_code from request_control_ack message
 *
 * @return  Error code response.
 */
static inline uint8_t mavlink_msg_request_control_ack_get_error_code(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Decode a request_control_ack message into a struct
 *
 * @param msg The message to decode
 * @param request_control_ack C-struct to decode the message contents into
 */
static inline void mavlink_msg_request_control_ack_decode(const mavlink_message_t* msg, mavlink_request_control_ack_t* request_control_ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    request_control_ack->control_target = mavlink_msg_request_control_ack_get_control_target(msg);
    request_control_ack->error_code = mavlink_msg_request_control_ack_get_error_code(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_REQUEST_CONTROL_ACK_LEN? msg->len : MAVLINK_MSG_ID_REQUEST_CONTROL_ACK_LEN;
        memset(request_control_ack, 0, MAVLINK_MSG_ID_REQUEST_CONTROL_ACK_LEN);
    memcpy(request_control_ack, _MAV_PAYLOAD(msg), len);
#endif
}
