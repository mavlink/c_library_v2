#pragma once
// MESSAGE UNIQUE_IDENTIFIER PACKING

#define MAVLINK_MSG_ID_UNIQUE_IDENTIFIER 470


typedef struct __mavlink_unique_identifier_t {
 char uuid[32]; /*<  uuid of the sender.*/
} mavlink_unique_identifier_t;

#define MAVLINK_MSG_ID_UNIQUE_IDENTIFIER_LEN 32
#define MAVLINK_MSG_ID_UNIQUE_IDENTIFIER_MIN_LEN 32
#define MAVLINK_MSG_ID_470_LEN 32
#define MAVLINK_MSG_ID_470_MIN_LEN 32

#define MAVLINK_MSG_ID_UNIQUE_IDENTIFIER_CRC 113
#define MAVLINK_MSG_ID_470_CRC 113

#define MAVLINK_MSG_UNIQUE_IDENTIFIER_FIELD_UUID_LEN 32

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_UNIQUE_IDENTIFIER { \
    470, \
    "UNIQUE_IDENTIFIER", \
    1, \
    {  { "uuid", NULL, MAVLINK_TYPE_CHAR, 32, 0, offsetof(mavlink_unique_identifier_t, uuid) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_UNIQUE_IDENTIFIER { \
    "UNIQUE_IDENTIFIER", \
    1, \
    {  { "uuid", NULL, MAVLINK_TYPE_CHAR, 32, 0, offsetof(mavlink_unique_identifier_t, uuid) }, \
         } \
}
#endif

/**
 * @brief Pack a unique_identifier message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param uuid  uuid of the sender.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_unique_identifier_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const char *uuid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_UNIQUE_IDENTIFIER_LEN];

    _mav_put_char_array(buf, 0, uuid, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_UNIQUE_IDENTIFIER_LEN);
#else
    mavlink_unique_identifier_t packet;

    mav_array_memcpy(packet.uuid, uuid, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_UNIQUE_IDENTIFIER_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_UNIQUE_IDENTIFIER;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_UNIQUE_IDENTIFIER_MIN_LEN, MAVLINK_MSG_ID_UNIQUE_IDENTIFIER_LEN, MAVLINK_MSG_ID_UNIQUE_IDENTIFIER_CRC);
}

/**
 * @brief Pack a unique_identifier message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param uuid  uuid of the sender.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_unique_identifier_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const char *uuid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_UNIQUE_IDENTIFIER_LEN];

    _mav_put_char_array(buf, 0, uuid, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_UNIQUE_IDENTIFIER_LEN);
#else
    mavlink_unique_identifier_t packet;

    mav_array_memcpy(packet.uuid, uuid, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_UNIQUE_IDENTIFIER_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_UNIQUE_IDENTIFIER;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_UNIQUE_IDENTIFIER_MIN_LEN, MAVLINK_MSG_ID_UNIQUE_IDENTIFIER_LEN, MAVLINK_MSG_ID_UNIQUE_IDENTIFIER_CRC);
}

/**
 * @brief Encode a unique_identifier struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param unique_identifier C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_unique_identifier_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_unique_identifier_t* unique_identifier)
{
    return mavlink_msg_unique_identifier_pack(system_id, component_id, msg, unique_identifier->uuid);
}

/**
 * @brief Encode a unique_identifier struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param unique_identifier C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_unique_identifier_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_unique_identifier_t* unique_identifier)
{
    return mavlink_msg_unique_identifier_pack_chan(system_id, component_id, chan, msg, unique_identifier->uuid);
}

/**
 * @brief Send a unique_identifier message
 * @param chan MAVLink channel to send the message
 *
 * @param uuid  uuid of the sender.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_unique_identifier_send(mavlink_channel_t chan, const char *uuid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_UNIQUE_IDENTIFIER_LEN];

    _mav_put_char_array(buf, 0, uuid, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UNIQUE_IDENTIFIER, buf, MAVLINK_MSG_ID_UNIQUE_IDENTIFIER_MIN_LEN, MAVLINK_MSG_ID_UNIQUE_IDENTIFIER_LEN, MAVLINK_MSG_ID_UNIQUE_IDENTIFIER_CRC);
#else
    mavlink_unique_identifier_t packet;

    mav_array_memcpy(packet.uuid, uuid, sizeof(char)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UNIQUE_IDENTIFIER, (const char *)&packet, MAVLINK_MSG_ID_UNIQUE_IDENTIFIER_MIN_LEN, MAVLINK_MSG_ID_UNIQUE_IDENTIFIER_LEN, MAVLINK_MSG_ID_UNIQUE_IDENTIFIER_CRC);
#endif
}

/**
 * @brief Send a unique_identifier message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_unique_identifier_send_struct(mavlink_channel_t chan, const mavlink_unique_identifier_t* unique_identifier)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_unique_identifier_send(chan, unique_identifier->uuid);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UNIQUE_IDENTIFIER, (const char *)unique_identifier, MAVLINK_MSG_ID_UNIQUE_IDENTIFIER_MIN_LEN, MAVLINK_MSG_ID_UNIQUE_IDENTIFIER_LEN, MAVLINK_MSG_ID_UNIQUE_IDENTIFIER_CRC);
#endif
}

#if MAVLINK_MSG_ID_UNIQUE_IDENTIFIER_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_unique_identifier_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const char *uuid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;

    _mav_put_char_array(buf, 0, uuid, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UNIQUE_IDENTIFIER, buf, MAVLINK_MSG_ID_UNIQUE_IDENTIFIER_MIN_LEN, MAVLINK_MSG_ID_UNIQUE_IDENTIFIER_LEN, MAVLINK_MSG_ID_UNIQUE_IDENTIFIER_CRC);
#else
    mavlink_unique_identifier_t *packet = (mavlink_unique_identifier_t *)msgbuf;

    mav_array_memcpy(packet->uuid, uuid, sizeof(char)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_UNIQUE_IDENTIFIER, (const char *)packet, MAVLINK_MSG_ID_UNIQUE_IDENTIFIER_MIN_LEN, MAVLINK_MSG_ID_UNIQUE_IDENTIFIER_LEN, MAVLINK_MSG_ID_UNIQUE_IDENTIFIER_CRC);
#endif
}
#endif

#endif

// MESSAGE UNIQUE_IDENTIFIER UNPACKING


/**
 * @brief Get field uuid from unique_identifier message
 *
 * @return  uuid of the sender.
 */
static inline uint16_t mavlink_msg_unique_identifier_get_uuid(const mavlink_message_t* msg, char *uuid)
{
    return _MAV_RETURN_char_array(msg, uuid, 32,  0);
}

/**
 * @brief Decode a unique_identifier message into a struct
 *
 * @param msg The message to decode
 * @param unique_identifier C-struct to decode the message contents into
 */
static inline void mavlink_msg_unique_identifier_decode(const mavlink_message_t* msg, mavlink_unique_identifier_t* unique_identifier)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_unique_identifier_get_uuid(msg, unique_identifier->uuid);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_UNIQUE_IDENTIFIER_LEN? msg->len : MAVLINK_MSG_ID_UNIQUE_IDENTIFIER_LEN;
        memset(unique_identifier, 0, MAVLINK_MSG_ID_UNIQUE_IDENTIFIER_LEN);
    memcpy(unique_identifier, _MAV_PAYLOAD(msg), len);
#endif
}
