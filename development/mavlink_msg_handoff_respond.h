#pragma once
// MESSAGE HANDOFF_RESPOND PACKING

#define MAVLINK_MSG_ID_HANDOFF_RESPOND 446


typedef struct __mavlink_handoff_respond_t {
 uint8_t control_target; /*<  Control target to handoff.*/
 uint8_t handoff_decision; /*<  Control target decision.*/
} mavlink_handoff_respond_t;

#define MAVLINK_MSG_ID_HANDOFF_RESPOND_LEN 2
#define MAVLINK_MSG_ID_HANDOFF_RESPOND_MIN_LEN 2
#define MAVLINK_MSG_ID_446_LEN 2
#define MAVLINK_MSG_ID_446_MIN_LEN 2

#define MAVLINK_MSG_ID_HANDOFF_RESPOND_CRC 47
#define MAVLINK_MSG_ID_446_CRC 47



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_HANDOFF_RESPOND { \
    446, \
    "HANDOFF_RESPOND", \
    2, \
    {  { "control_target", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_handoff_respond_t, control_target) }, \
         { "handoff_decision", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_handoff_respond_t, handoff_decision) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_HANDOFF_RESPOND { \
    "HANDOFF_RESPOND", \
    2, \
    {  { "control_target", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_handoff_respond_t, control_target) }, \
         { "handoff_decision", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_handoff_respond_t, handoff_decision) }, \
         } \
}
#endif

/**
 * @brief Pack a handoff_respond message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param control_target  Control target to handoff.
 * @param handoff_decision  Control target decision.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_handoff_respond_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t control_target, uint8_t handoff_decision)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HANDOFF_RESPOND_LEN];
    _mav_put_uint8_t(buf, 0, control_target);
    _mav_put_uint8_t(buf, 1, handoff_decision);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HANDOFF_RESPOND_LEN);
#else
    mavlink_handoff_respond_t packet;
    packet.control_target = control_target;
    packet.handoff_decision = handoff_decision;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HANDOFF_RESPOND_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_HANDOFF_RESPOND;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_HANDOFF_RESPOND_MIN_LEN, MAVLINK_MSG_ID_HANDOFF_RESPOND_LEN, MAVLINK_MSG_ID_HANDOFF_RESPOND_CRC);
}

/**
 * @brief Pack a handoff_respond message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param control_target  Control target to handoff.
 * @param handoff_decision  Control target decision.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_handoff_respond_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t control_target,uint8_t handoff_decision)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HANDOFF_RESPOND_LEN];
    _mav_put_uint8_t(buf, 0, control_target);
    _mav_put_uint8_t(buf, 1, handoff_decision);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HANDOFF_RESPOND_LEN);
#else
    mavlink_handoff_respond_t packet;
    packet.control_target = control_target;
    packet.handoff_decision = handoff_decision;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HANDOFF_RESPOND_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_HANDOFF_RESPOND;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_HANDOFF_RESPOND_MIN_LEN, MAVLINK_MSG_ID_HANDOFF_RESPOND_LEN, MAVLINK_MSG_ID_HANDOFF_RESPOND_CRC);
}

/**
 * @brief Encode a handoff_respond struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param handoff_respond C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_handoff_respond_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_handoff_respond_t* handoff_respond)
{
    return mavlink_msg_handoff_respond_pack(system_id, component_id, msg, handoff_respond->control_target, handoff_respond->handoff_decision);
}

/**
 * @brief Encode a handoff_respond struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param handoff_respond C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_handoff_respond_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_handoff_respond_t* handoff_respond)
{
    return mavlink_msg_handoff_respond_pack_chan(system_id, component_id, chan, msg, handoff_respond->control_target, handoff_respond->handoff_decision);
}

/**
 * @brief Send a handoff_respond message
 * @param chan MAVLink channel to send the message
 *
 * @param control_target  Control target to handoff.
 * @param handoff_decision  Control target decision.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_handoff_respond_send(mavlink_channel_t chan, uint8_t control_target, uint8_t handoff_decision)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HANDOFF_RESPOND_LEN];
    _mav_put_uint8_t(buf, 0, control_target);
    _mav_put_uint8_t(buf, 1, handoff_decision);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HANDOFF_RESPOND, buf, MAVLINK_MSG_ID_HANDOFF_RESPOND_MIN_LEN, MAVLINK_MSG_ID_HANDOFF_RESPOND_LEN, MAVLINK_MSG_ID_HANDOFF_RESPOND_CRC);
#else
    mavlink_handoff_respond_t packet;
    packet.control_target = control_target;
    packet.handoff_decision = handoff_decision;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HANDOFF_RESPOND, (const char *)&packet, MAVLINK_MSG_ID_HANDOFF_RESPOND_MIN_LEN, MAVLINK_MSG_ID_HANDOFF_RESPOND_LEN, MAVLINK_MSG_ID_HANDOFF_RESPOND_CRC);
#endif
}

/**
 * @brief Send a handoff_respond message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_handoff_respond_send_struct(mavlink_channel_t chan, const mavlink_handoff_respond_t* handoff_respond)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_handoff_respond_send(chan, handoff_respond->control_target, handoff_respond->handoff_decision);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HANDOFF_RESPOND, (const char *)handoff_respond, MAVLINK_MSG_ID_HANDOFF_RESPOND_MIN_LEN, MAVLINK_MSG_ID_HANDOFF_RESPOND_LEN, MAVLINK_MSG_ID_HANDOFF_RESPOND_CRC);
#endif
}

#if MAVLINK_MSG_ID_HANDOFF_RESPOND_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_handoff_respond_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t control_target, uint8_t handoff_decision)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, control_target);
    _mav_put_uint8_t(buf, 1, handoff_decision);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HANDOFF_RESPOND, buf, MAVLINK_MSG_ID_HANDOFF_RESPOND_MIN_LEN, MAVLINK_MSG_ID_HANDOFF_RESPOND_LEN, MAVLINK_MSG_ID_HANDOFF_RESPOND_CRC);
#else
    mavlink_handoff_respond_t *packet = (mavlink_handoff_respond_t *)msgbuf;
    packet->control_target = control_target;
    packet->handoff_decision = handoff_decision;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HANDOFF_RESPOND, (const char *)packet, MAVLINK_MSG_ID_HANDOFF_RESPOND_MIN_LEN, MAVLINK_MSG_ID_HANDOFF_RESPOND_LEN, MAVLINK_MSG_ID_HANDOFF_RESPOND_CRC);
#endif
}
#endif

#endif

// MESSAGE HANDOFF_RESPOND UNPACKING


/**
 * @brief Get field control_target from handoff_respond message
 *
 * @return  Control target to handoff.
 */
static inline uint8_t mavlink_msg_handoff_respond_get_control_target(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field handoff_decision from handoff_respond message
 *
 * @return  Control target decision.
 */
static inline uint8_t mavlink_msg_handoff_respond_get_handoff_decision(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Decode a handoff_respond message into a struct
 *
 * @param msg The message to decode
 * @param handoff_respond C-struct to decode the message contents into
 */
static inline void mavlink_msg_handoff_respond_decode(const mavlink_message_t* msg, mavlink_handoff_respond_t* handoff_respond)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    handoff_respond->control_target = mavlink_msg_handoff_respond_get_control_target(msg);
    handoff_respond->handoff_decision = mavlink_msg_handoff_respond_get_handoff_decision(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_HANDOFF_RESPOND_LEN? msg->len : MAVLINK_MSG_ID_HANDOFF_RESPOND_LEN;
        memset(handoff_respond, 0, MAVLINK_MSG_ID_HANDOFF_RESPOND_LEN);
    memcpy(handoff_respond, _MAV_PAYLOAD(msg), len);
#endif
}
