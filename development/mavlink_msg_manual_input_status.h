#pragma once
// MESSAGE MANUAL_INPUT_STATUS PACKING

#include <stdint.h>

#define MAVLINK_MSG_ID_MANUAL_INPUT_STATUS 515


typedef struct __mavlink_manual_input_status_t {
 uint8_t source; /*<  Current manual control source active.*/
 uint8_t sender_system_id; /*<  System ID of the MAVLink enabled input device currently providing manual control. Set whenever a MAVLink enabled input device is contributing, i.e. for both MAV_MANUAL_INPUT_SOURCE_MAVLINK and MAV_MANUAL_INPUT_SOURCE_MIXED. 0 otherwise.*/
 uint8_t sender_component_id; /*<  Component ID of the MAVLink enabled input device currently providing manual control. Set whenever a MAVLink enabled input device is contributing, i.e. for both MAV_MANUAL_INPUT_SOURCE_MAVLINK and MAV_MANUAL_INPUT_SOURCE_MIXED. 0 otherwise.*/
} mavlink_manual_input_status_t;

#define MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_LEN 3
#define MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_MIN_LEN 3
#define MAVLINK_MSG_ID_515_LEN 3
#define MAVLINK_MSG_ID_515_MIN_LEN 3

#define MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_CRC 128
#define MAVLINK_MSG_ID_515_CRC 128



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MANUAL_INPUT_STATUS { \
    515, \
    "MANUAL_INPUT_STATUS", \
    3, \
    {  { "source", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_manual_input_status_t, source) }, \
         { "sender_system_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_manual_input_status_t, sender_system_id) }, \
         { "sender_component_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_manual_input_status_t, sender_component_id) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MANUAL_INPUT_STATUS { \
    "MANUAL_INPUT_STATUS", \
    3, \
    {  { "source", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_manual_input_status_t, source) }, \
         { "sender_system_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_manual_input_status_t, sender_system_id) }, \
         { "sender_component_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_manual_input_status_t, sender_component_id) }, \
         } \
}
#endif

/**
 * @brief Pack a manual_input_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param source  Current manual control source active.
 * @param sender_system_id  System ID of the MAVLink enabled input device currently providing manual control. Set whenever a MAVLink enabled input device is contributing, i.e. for both MAV_MANUAL_INPUT_SOURCE_MAVLINK and MAV_MANUAL_INPUT_SOURCE_MIXED. 0 otherwise.
 * @param sender_component_id  Component ID of the MAVLink enabled input device currently providing manual control. Set whenever a MAVLink enabled input device is contributing, i.e. for both MAV_MANUAL_INPUT_SOURCE_MAVLINK and MAV_MANUAL_INPUT_SOURCE_MIXED. 0 otherwise.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_manual_input_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t source, uint8_t sender_system_id, uint8_t sender_component_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_LEN];
    _mav_put_uint8_t(buf, 0, source);
    _mav_put_uint8_t(buf, 1, sender_system_id);
    _mav_put_uint8_t(buf, 2, sender_component_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_LEN);
#else
    mavlink_manual_input_status_t packet;
    packet.source = source;
    packet.sender_system_id = sender_system_id;
    packet.sender_component_id = sender_component_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MANUAL_INPUT_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_MIN_LEN, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_LEN, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_CRC);
}

/**
 * @brief Pack a manual_input_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param source  Current manual control source active.
 * @param sender_system_id  System ID of the MAVLink enabled input device currently providing manual control. Set whenever a MAVLink enabled input device is contributing, i.e. for both MAV_MANUAL_INPUT_SOURCE_MAVLINK and MAV_MANUAL_INPUT_SOURCE_MIXED. 0 otherwise.
 * @param sender_component_id  Component ID of the MAVLink enabled input device currently providing manual control. Set whenever a MAVLink enabled input device is contributing, i.e. for both MAV_MANUAL_INPUT_SOURCE_MAVLINK and MAV_MANUAL_INPUT_SOURCE_MIXED. 0 otherwise.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_manual_input_status_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t source, uint8_t sender_system_id, uint8_t sender_component_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_LEN];
    _mav_put_uint8_t(buf, 0, source);
    _mav_put_uint8_t(buf, 1, sender_system_id);
    _mav_put_uint8_t(buf, 2, sender_component_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_LEN);
#else
    mavlink_manual_input_status_t packet;
    packet.source = source;
    packet.sender_system_id = sender_system_id;
    packet.sender_component_id = sender_component_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MANUAL_INPUT_STATUS;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_MIN_LEN, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_LEN, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_MIN_LEN, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_LEN);
#endif
}

/**
 * @brief Pack a manual_input_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param source  Current manual control source active.
 * @param sender_system_id  System ID of the MAVLink enabled input device currently providing manual control. Set whenever a MAVLink enabled input device is contributing, i.e. for both MAV_MANUAL_INPUT_SOURCE_MAVLINK and MAV_MANUAL_INPUT_SOURCE_MIXED. 0 otherwise.
 * @param sender_component_id  Component ID of the MAVLink enabled input device currently providing manual control. Set whenever a MAVLink enabled input device is contributing, i.e. for both MAV_MANUAL_INPUT_SOURCE_MAVLINK and MAV_MANUAL_INPUT_SOURCE_MIXED. 0 otherwise.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_manual_input_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t source,uint8_t sender_system_id,uint8_t sender_component_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_LEN];
    _mav_put_uint8_t(buf, 0, source);
    _mav_put_uint8_t(buf, 1, sender_system_id);
    _mav_put_uint8_t(buf, 2, sender_component_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_LEN);
#else
    mavlink_manual_input_status_t packet;
    packet.source = source;
    packet.sender_system_id = sender_system_id;
    packet.sender_component_id = sender_component_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MANUAL_INPUT_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_MIN_LEN, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_LEN, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_CRC);
}

/**
 * @brief Encode a manual_input_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param manual_input_status C-struct to read the message contents from
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_manual_input_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_manual_input_status_t* manual_input_status)
{
    return mavlink_msg_manual_input_status_pack(system_id, component_id, msg, manual_input_status->source, manual_input_status->sender_system_id, manual_input_status->sender_component_id);
}

/**
 * @brief Encode a manual_input_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param manual_input_status C-struct to read the message contents from
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_manual_input_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_manual_input_status_t* manual_input_status)
{
    return mavlink_msg_manual_input_status_pack_chan(system_id, component_id, chan, msg, manual_input_status->source, manual_input_status->sender_system_id, manual_input_status->sender_component_id);
}

/**
 * @brief Encode a manual_input_status struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param manual_input_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_manual_input_status_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_manual_input_status_t* manual_input_status)
{
    return mavlink_msg_manual_input_status_pack_status(system_id, component_id, _status, msg,  manual_input_status->source, manual_input_status->sender_system_id, manual_input_status->sender_component_id);
}

/**
 * @brief Send a manual_input_status message
 * @param chan MAVLink channel to send the message
 *
 * @param source  Current manual control source active.
 * @param sender_system_id  System ID of the MAVLink enabled input device currently providing manual control. Set whenever a MAVLink enabled input device is contributing, i.e. for both MAV_MANUAL_INPUT_SOURCE_MAVLINK and MAV_MANUAL_INPUT_SOURCE_MIXED. 0 otherwise.
 * @param sender_component_id  Component ID of the MAVLink enabled input device currently providing manual control. Set whenever a MAVLink enabled input device is contributing, i.e. for both MAV_MANUAL_INPUT_SOURCE_MAVLINK and MAV_MANUAL_INPUT_SOURCE_MIXED. 0 otherwise.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

MAVLINK_WIP
static inline void mavlink_msg_manual_input_status_send(mavlink_channel_t chan, uint8_t source, uint8_t sender_system_id, uint8_t sender_component_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_LEN];
    _mav_put_uint8_t(buf, 0, source);
    _mav_put_uint8_t(buf, 1, sender_system_id);
    _mav_put_uint8_t(buf, 2, sender_component_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS, buf, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_MIN_LEN, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_LEN, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_CRC);
#else
    mavlink_manual_input_status_t packet;
    packet.source = source;
    packet.sender_system_id = sender_system_id;
    packet.sender_component_id = sender_component_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS, (const char *)&packet, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_MIN_LEN, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_LEN, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_CRC);
#endif
}

/**
 * @brief Send a manual_input_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
MAVLINK_WIP
static inline void mavlink_msg_manual_input_status_send_struct(mavlink_channel_t chan, const mavlink_manual_input_status_t* manual_input_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_manual_input_status_send(chan, manual_input_status->source, manual_input_status->sender_system_id, manual_input_status->sender_component_id);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS, (const char *)manual_input_status, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_MIN_LEN, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_LEN, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
MAVLINK_WIP
static inline void mavlink_msg_manual_input_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t source, uint8_t sender_system_id, uint8_t sender_component_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, source);
    _mav_put_uint8_t(buf, 1, sender_system_id);
    _mav_put_uint8_t(buf, 2, sender_component_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS, buf, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_MIN_LEN, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_LEN, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_CRC);
#else
    mavlink_manual_input_status_t *packet = (mavlink_manual_input_status_t *)msgbuf;
    packet->source = source;
    packet->sender_system_id = sender_system_id;
    packet->sender_component_id = sender_component_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS, (const char *)packet, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_MIN_LEN, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_LEN, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE MANUAL_INPUT_STATUS UNPACKING


/**
 * @brief Get field source from manual_input_status message
 *
 * @return  Current manual control source active.
 */
MAVLINK_WIP
static inline uint8_t mavlink_msg_manual_input_status_get_source(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field sender_system_id from manual_input_status message
 *
 * @return  System ID of the MAVLink enabled input device currently providing manual control. Set whenever a MAVLink enabled input device is contributing, i.e. for both MAV_MANUAL_INPUT_SOURCE_MAVLINK and MAV_MANUAL_INPUT_SOURCE_MIXED. 0 otherwise.
 */
MAVLINK_WIP
static inline uint8_t mavlink_msg_manual_input_status_get_sender_system_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field sender_component_id from manual_input_status message
 *
 * @return  Component ID of the MAVLink enabled input device currently providing manual control. Set whenever a MAVLink enabled input device is contributing, i.e. for both MAV_MANUAL_INPUT_SOURCE_MAVLINK and MAV_MANUAL_INPUT_SOURCE_MIXED. 0 otherwise.
 */
MAVLINK_WIP
static inline uint8_t mavlink_msg_manual_input_status_get_sender_component_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Decode a manual_input_status message into a struct
 *
 * @param msg The message to decode
 * @param manual_input_status C-struct to decode the message contents into
 */
MAVLINK_WIP
static inline void mavlink_msg_manual_input_status_decode(const mavlink_message_t* msg, mavlink_manual_input_status_t* manual_input_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    manual_input_status->source = mavlink_msg_manual_input_status_get_source(msg);
    manual_input_status->sender_system_id = mavlink_msg_manual_input_status_get_sender_system_id(msg);
    manual_input_status->sender_component_id = mavlink_msg_manual_input_status_get_sender_component_id(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_LEN? msg->len : MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_LEN;
        memset(manual_input_status, 0, MAVLINK_MSG_ID_MANUAL_INPUT_STATUS_LEN);
    memcpy(manual_input_status, _MAV_PAYLOAD(msg), len);
#endif
}
