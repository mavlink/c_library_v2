#pragma once
// MESSAGE PIXEL_TO_LLA_ACK PACKING

#define MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK 601


typedef struct __mavlink_pixel_to_lla_ack_t {
 uint64_t uid; /*<   Unique ID of the request.*/
 uint8_t status; /*<  0 = Rejected, 1 = Accepted (with an optional error message).*/
 char error_message[100]; /*<   Optional error message in case of rejection. Max length 100 characters.*/
} mavlink_pixel_to_lla_ack_t;

#define MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_LEN 109
#define MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_MIN_LEN 109
#define MAVLINK_MSG_ID_601_LEN 109
#define MAVLINK_MSG_ID_601_MIN_LEN 109

#define MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_CRC 190
#define MAVLINK_MSG_ID_601_CRC 190

#define MAVLINK_MSG_PIXEL_TO_LLA_ACK_FIELD_ERROR_MESSAGE_LEN 100

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PIXEL_TO_LLA_ACK { \
    601, \
    "PIXEL_TO_LLA_ACK", \
    3, \
    {  { "uid", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_pixel_to_lla_ack_t, uid) }, \
         { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_pixel_to_lla_ack_t, status) }, \
         { "error_message", NULL, MAVLINK_TYPE_CHAR, 100, 9, offsetof(mavlink_pixel_to_lla_ack_t, error_message) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PIXEL_TO_LLA_ACK { \
    "PIXEL_TO_LLA_ACK", \
    3, \
    {  { "uid", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_pixel_to_lla_ack_t, uid) }, \
         { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_pixel_to_lla_ack_t, status) }, \
         { "error_message", NULL, MAVLINK_TYPE_CHAR, 100, 9, offsetof(mavlink_pixel_to_lla_ack_t, error_message) }, \
         } \
}
#endif

/**
 * @brief Pack a pixel_to_lla_ack message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param uid   Unique ID of the request.
 * @param status  0 = Rejected, 1 = Accepted (with an optional error message).
 * @param error_message   Optional error message in case of rejection. Max length 100 characters.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pixel_to_lla_ack_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t uid, uint8_t status, const char *error_message)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_LEN];
    _mav_put_uint64_t(buf, 0, uid);
    _mav_put_uint8_t(buf, 8, status);
    _mav_put_char_array(buf, 9, error_message, 100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_LEN);
#else
    mavlink_pixel_to_lla_ack_t packet;
    packet.uid = uid;
    packet.status = status;
    mav_array_memcpy(packet.error_message, error_message, sizeof(char)*100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_MIN_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_CRC);
}

/**
 * @brief Pack a pixel_to_lla_ack message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param uid   Unique ID of the request.
 * @param status  0 = Rejected, 1 = Accepted (with an optional error message).
 * @param error_message   Optional error message in case of rejection. Max length 100 characters.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pixel_to_lla_ack_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint64_t uid, uint8_t status, const char *error_message)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_LEN];
    _mav_put_uint64_t(buf, 0, uid);
    _mav_put_uint8_t(buf, 8, status);
    _mav_put_char_array(buf, 9, error_message, 100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_LEN);
#else
    mavlink_pixel_to_lla_ack_t packet;
    packet.uid = uid;
    packet.status = status;
    mav_array_memcpy(packet.error_message, error_message, sizeof(char)*100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_MIN_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_MIN_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_LEN);
#endif
}

/**
 * @brief Pack a pixel_to_lla_ack message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param uid   Unique ID of the request.
 * @param status  0 = Rejected, 1 = Accepted (with an optional error message).
 * @param error_message   Optional error message in case of rejection. Max length 100 characters.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pixel_to_lla_ack_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t uid,uint8_t status,const char *error_message)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_LEN];
    _mav_put_uint64_t(buf, 0, uid);
    _mav_put_uint8_t(buf, 8, status);
    _mav_put_char_array(buf, 9, error_message, 100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_LEN);
#else
    mavlink_pixel_to_lla_ack_t packet;
    packet.uid = uid;
    packet.status = status;
    mav_array_memcpy(packet.error_message, error_message, sizeof(char)*100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_MIN_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_CRC);
}

/**
 * @brief Encode a pixel_to_lla_ack struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param pixel_to_lla_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pixel_to_lla_ack_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_pixel_to_lla_ack_t* pixel_to_lla_ack)
{
    return mavlink_msg_pixel_to_lla_ack_pack(system_id, component_id, msg, pixel_to_lla_ack->uid, pixel_to_lla_ack->status, pixel_to_lla_ack->error_message);
}

/**
 * @brief Encode a pixel_to_lla_ack struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param pixel_to_lla_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pixel_to_lla_ack_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_pixel_to_lla_ack_t* pixel_to_lla_ack)
{
    return mavlink_msg_pixel_to_lla_ack_pack_chan(system_id, component_id, chan, msg, pixel_to_lla_ack->uid, pixel_to_lla_ack->status, pixel_to_lla_ack->error_message);
}

/**
 * @brief Encode a pixel_to_lla_ack struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param pixel_to_lla_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pixel_to_lla_ack_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_pixel_to_lla_ack_t* pixel_to_lla_ack)
{
    return mavlink_msg_pixel_to_lla_ack_pack_status(system_id, component_id, _status, msg,  pixel_to_lla_ack->uid, pixel_to_lla_ack->status, pixel_to_lla_ack->error_message);
}

/**
 * @brief Send a pixel_to_lla_ack message
 * @param chan MAVLink channel to send the message
 *
 * @param uid   Unique ID of the request.
 * @param status  0 = Rejected, 1 = Accepted (with an optional error message).
 * @param error_message   Optional error message in case of rejection. Max length 100 characters.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_pixel_to_lla_ack_send(mavlink_channel_t chan, uint64_t uid, uint8_t status, const char *error_message)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_LEN];
    _mav_put_uint64_t(buf, 0, uid);
    _mav_put_uint8_t(buf, 8, status);
    _mav_put_char_array(buf, 9, error_message, 100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK, buf, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_MIN_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_CRC);
#else
    mavlink_pixel_to_lla_ack_t packet;
    packet.uid = uid;
    packet.status = status;
    mav_array_memcpy(packet.error_message, error_message, sizeof(char)*100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK, (const char *)&packet, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_MIN_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_CRC);
#endif
}

/**
 * @brief Send a pixel_to_lla_ack message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_pixel_to_lla_ack_send_struct(mavlink_channel_t chan, const mavlink_pixel_to_lla_ack_t* pixel_to_lla_ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_pixel_to_lla_ack_send(chan, pixel_to_lla_ack->uid, pixel_to_lla_ack->status, pixel_to_lla_ack->error_message);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK, (const char *)pixel_to_lla_ack, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_MIN_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_CRC);
#endif
}

#if MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_pixel_to_lla_ack_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t uid, uint8_t status, const char *error_message)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, uid);
    _mav_put_uint8_t(buf, 8, status);
    _mav_put_char_array(buf, 9, error_message, 100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK, buf, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_MIN_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_CRC);
#else
    mavlink_pixel_to_lla_ack_t *packet = (mavlink_pixel_to_lla_ack_t *)msgbuf;
    packet->uid = uid;
    packet->status = status;
    mav_array_memcpy(packet->error_message, error_message, sizeof(char)*100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK, (const char *)packet, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_MIN_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_CRC);
#endif
}
#endif

#endif

// MESSAGE PIXEL_TO_LLA_ACK UNPACKING


/**
 * @brief Get field uid from pixel_to_lla_ack message
 *
 * @return   Unique ID of the request.
 */
static inline uint64_t mavlink_msg_pixel_to_lla_ack_get_uid(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field status from pixel_to_lla_ack message
 *
 * @return  0 = Rejected, 1 = Accepted (with an optional error message).
 */
static inline uint8_t mavlink_msg_pixel_to_lla_ack_get_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field error_message from pixel_to_lla_ack message
 *
 * @return   Optional error message in case of rejection. Max length 100 characters.
 */
static inline uint16_t mavlink_msg_pixel_to_lla_ack_get_error_message(const mavlink_message_t* msg, char *error_message)
{
    return _MAV_RETURN_char_array(msg, error_message, 100,  9);
}

/**
 * @brief Decode a pixel_to_lla_ack message into a struct
 *
 * @param msg The message to decode
 * @param pixel_to_lla_ack C-struct to decode the message contents into
 */
static inline void mavlink_msg_pixel_to_lla_ack_decode(const mavlink_message_t* msg, mavlink_pixel_to_lla_ack_t* pixel_to_lla_ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    pixel_to_lla_ack->uid = mavlink_msg_pixel_to_lla_ack_get_uid(msg);
    pixel_to_lla_ack->status = mavlink_msg_pixel_to_lla_ack_get_status(msg);
    mavlink_msg_pixel_to_lla_ack_get_error_message(msg, pixel_to_lla_ack->error_message);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_LEN? msg->len : MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_LEN;
        memset(pixel_to_lla_ack, 0, MAVLINK_MSG_ID_PIXEL_TO_LLA_ACK_LEN);
    memcpy(pixel_to_lla_ack, _MAV_PAYLOAD(msg), len);
#endif
}
