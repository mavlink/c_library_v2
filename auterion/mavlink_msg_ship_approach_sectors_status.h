#pragma once
// MESSAGE SHIP_APPROACH_SECTORS_STATUS PACKING

#define MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS 13680


typedef struct __mavlink_ship_approach_sectors_status_t {
 uint8_t sectors; /*<  Bitmap indicating which ship approach sectors are set. In clockwise order.*/
} mavlink_ship_approach_sectors_status_t;

#define MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_LEN 1
#define MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_MIN_LEN 1
#define MAVLINK_MSG_ID_13680_LEN 1
#define MAVLINK_MSG_ID_13680_MIN_LEN 1

#define MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_CRC 38
#define MAVLINK_MSG_ID_13680_CRC 38



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SHIP_APPROACH_SECTORS_STATUS { \
    13680, \
    "SHIP_APPROACH_SECTORS_STATUS", \
    1, \
    {  { "sectors", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_ship_approach_sectors_status_t, sectors) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SHIP_APPROACH_SECTORS_STATUS { \
    "SHIP_APPROACH_SECTORS_STATUS", \
    1, \
    {  { "sectors", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_ship_approach_sectors_status_t, sectors) }, \
         } \
}
#endif

/**
 * @brief Pack a ship_approach_sectors_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param sectors  Bitmap indicating which ship approach sectors are set. In clockwise order.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ship_approach_sectors_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t sectors)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_LEN];
    _mav_put_uint8_t(buf, 0, sectors);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_LEN);
#else
    mavlink_ship_approach_sectors_status_t packet;
    packet.sectors = sectors;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_MIN_LEN, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_LEN, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_CRC);
}

/**
 * @brief Pack a ship_approach_sectors_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param sectors  Bitmap indicating which ship approach sectors are set. In clockwise order.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ship_approach_sectors_status_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t sectors)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_LEN];
    _mav_put_uint8_t(buf, 0, sectors);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_LEN);
#else
    mavlink_ship_approach_sectors_status_t packet;
    packet.sectors = sectors;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_MIN_LEN, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_LEN, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_MIN_LEN, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_LEN);
#endif
}

/**
 * @brief Pack a ship_approach_sectors_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sectors  Bitmap indicating which ship approach sectors are set. In clockwise order.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ship_approach_sectors_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t sectors)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_LEN];
    _mav_put_uint8_t(buf, 0, sectors);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_LEN);
#else
    mavlink_ship_approach_sectors_status_t packet;
    packet.sectors = sectors;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_MIN_LEN, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_LEN, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_CRC);
}

/**
 * @brief Encode a ship_approach_sectors_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ship_approach_sectors_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ship_approach_sectors_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ship_approach_sectors_status_t* ship_approach_sectors_status)
{
    return mavlink_msg_ship_approach_sectors_status_pack(system_id, component_id, msg, ship_approach_sectors_status->sectors);
}

/**
 * @brief Encode a ship_approach_sectors_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ship_approach_sectors_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ship_approach_sectors_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ship_approach_sectors_status_t* ship_approach_sectors_status)
{
    return mavlink_msg_ship_approach_sectors_status_pack_chan(system_id, component_id, chan, msg, ship_approach_sectors_status->sectors);
}

/**
 * @brief Encode a ship_approach_sectors_status struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param ship_approach_sectors_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ship_approach_sectors_status_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_ship_approach_sectors_status_t* ship_approach_sectors_status)
{
    return mavlink_msg_ship_approach_sectors_status_pack_status(system_id, component_id, _status, msg,  ship_approach_sectors_status->sectors);
}

/**
 * @brief Send a ship_approach_sectors_status message
 * @param chan MAVLink channel to send the message
 *
 * @param sectors  Bitmap indicating which ship approach sectors are set. In clockwise order.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ship_approach_sectors_status_send(mavlink_channel_t chan, uint8_t sectors)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_LEN];
    _mav_put_uint8_t(buf, 0, sectors);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS, buf, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_MIN_LEN, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_LEN, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_CRC);
#else
    mavlink_ship_approach_sectors_status_t packet;
    packet.sectors = sectors;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS, (const char *)&packet, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_MIN_LEN, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_LEN, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_CRC);
#endif
}

/**
 * @brief Send a ship_approach_sectors_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_ship_approach_sectors_status_send_struct(mavlink_channel_t chan, const mavlink_ship_approach_sectors_status_t* ship_approach_sectors_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_ship_approach_sectors_status_send(chan, ship_approach_sectors_status->sectors);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS, (const char *)ship_approach_sectors_status, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_MIN_LEN, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_LEN, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ship_approach_sectors_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t sectors)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, sectors);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS, buf, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_MIN_LEN, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_LEN, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_CRC);
#else
    mavlink_ship_approach_sectors_status_t *packet = (mavlink_ship_approach_sectors_status_t *)msgbuf;
    packet->sectors = sectors;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS, (const char *)packet, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_MIN_LEN, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_LEN, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE SHIP_APPROACH_SECTORS_STATUS UNPACKING


/**
 * @brief Get field sectors from ship_approach_sectors_status message
 *
 * @return  Bitmap indicating which ship approach sectors are set. In clockwise order.
 */
static inline uint8_t mavlink_msg_ship_approach_sectors_status_get_sectors(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Decode a ship_approach_sectors_status message into a struct
 *
 * @param msg The message to decode
 * @param ship_approach_sectors_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_ship_approach_sectors_status_decode(const mavlink_message_t* msg, mavlink_ship_approach_sectors_status_t* ship_approach_sectors_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    ship_approach_sectors_status->sectors = mavlink_msg_ship_approach_sectors_status_get_sectors(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_LEN? msg->len : MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_LEN;
        memset(ship_approach_sectors_status, 0, MAVLINK_MSG_ID_SHIP_APPROACH_SECTORS_STATUS_LEN);
    memcpy(ship_approach_sectors_status, _MAV_PAYLOAD(msg), len);
#endif
}
