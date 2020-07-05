#pragma once
// MESSAGE ACTUATOR_CMD PACKING

#define MAVLINK_MSG_ID_ACTUATOR_CMD 20001


typedef struct __mavlink_actuator_cmd_t {
 uint16_t actuator1; /*<  Value for servo Nr 1*/
 uint16_t actuator2; /*<  Value for servo Nr 2*/
 uint16_t actuator3; /*<  Value for servo Nr 3*/
 uint16_t actuator4; /*<  Value for servo Nr 4*/
 uint16_t actuator5; /*<  Value for servo Nr 5*/
 uint16_t actuator6; /*<  Value for servo Nr 6*/
 uint16_t actuator7; /*<  Value for servo Nr 7*/
 uint16_t actuator8; /*<  Value for servo Nr 8*/
} mavlink_actuator_cmd_t;

#define MAVLINK_MSG_ID_ACTUATOR_CMD_LEN 16
#define MAVLINK_MSG_ID_ACTUATOR_CMD_MIN_LEN 16
#define MAVLINK_MSG_ID_20001_LEN 16
#define MAVLINK_MSG_ID_20001_MIN_LEN 16

#define MAVLINK_MSG_ID_ACTUATOR_CMD_CRC 53
#define MAVLINK_MSG_ID_20001_CRC 53



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ACTUATOR_CMD { \
    20001, \
    "ACTUATOR_CMD", \
    8, \
    {  { "actuator1", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_actuator_cmd_t, actuator1) }, \
         { "actuator2", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_actuator_cmd_t, actuator2) }, \
         { "actuator3", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_actuator_cmd_t, actuator3) }, \
         { "actuator4", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_actuator_cmd_t, actuator4) }, \
         { "actuator5", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_actuator_cmd_t, actuator5) }, \
         { "actuator6", NULL, MAVLINK_TYPE_UINT16_T, 0, 10, offsetof(mavlink_actuator_cmd_t, actuator6) }, \
         { "actuator7", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_actuator_cmd_t, actuator7) }, \
         { "actuator8", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_actuator_cmd_t, actuator8) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ACTUATOR_CMD { \
    "ACTUATOR_CMD", \
    8, \
    {  { "actuator1", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_actuator_cmd_t, actuator1) }, \
         { "actuator2", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_actuator_cmd_t, actuator2) }, \
         { "actuator3", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_actuator_cmd_t, actuator3) }, \
         { "actuator4", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_actuator_cmd_t, actuator4) }, \
         { "actuator5", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_actuator_cmd_t, actuator5) }, \
         { "actuator6", NULL, MAVLINK_TYPE_UINT16_T, 0, 10, offsetof(mavlink_actuator_cmd_t, actuator6) }, \
         { "actuator7", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_actuator_cmd_t, actuator7) }, \
         { "actuator8", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_actuator_cmd_t, actuator8) }, \
         } \
}
#endif

/**
 * @brief Pack a actuator_cmd message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param actuator1  Value for servo Nr 1
 * @param actuator2  Value for servo Nr 2
 * @param actuator3  Value for servo Nr 3
 * @param actuator4  Value for servo Nr 4
 * @param actuator5  Value for servo Nr 5
 * @param actuator6  Value for servo Nr 6
 * @param actuator7  Value for servo Nr 7
 * @param actuator8  Value for servo Nr 8
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_actuator_cmd_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t actuator1, uint16_t actuator2, uint16_t actuator3, uint16_t actuator4, uint16_t actuator5, uint16_t actuator6, uint16_t actuator7, uint16_t actuator8)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ACTUATOR_CMD_LEN];
    _mav_put_uint16_t(buf, 0, actuator1);
    _mav_put_uint16_t(buf, 2, actuator2);
    _mav_put_uint16_t(buf, 4, actuator3);
    _mav_put_uint16_t(buf, 6, actuator4);
    _mav_put_uint16_t(buf, 8, actuator5);
    _mav_put_uint16_t(buf, 10, actuator6);
    _mav_put_uint16_t(buf, 12, actuator7);
    _mav_put_uint16_t(buf, 14, actuator8);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ACTUATOR_CMD_LEN);
#else
    mavlink_actuator_cmd_t packet;
    packet.actuator1 = actuator1;
    packet.actuator2 = actuator2;
    packet.actuator3 = actuator3;
    packet.actuator4 = actuator4;
    packet.actuator5 = actuator5;
    packet.actuator6 = actuator6;
    packet.actuator7 = actuator7;
    packet.actuator8 = actuator8;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ACTUATOR_CMD_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ACTUATOR_CMD;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ACTUATOR_CMD_MIN_LEN, MAVLINK_MSG_ID_ACTUATOR_CMD_LEN, MAVLINK_MSG_ID_ACTUATOR_CMD_CRC);
}

/**
 * @brief Pack a actuator_cmd message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param actuator1  Value for servo Nr 1
 * @param actuator2  Value for servo Nr 2
 * @param actuator3  Value for servo Nr 3
 * @param actuator4  Value for servo Nr 4
 * @param actuator5  Value for servo Nr 5
 * @param actuator6  Value for servo Nr 6
 * @param actuator7  Value for servo Nr 7
 * @param actuator8  Value for servo Nr 8
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_actuator_cmd_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t actuator1,uint16_t actuator2,uint16_t actuator3,uint16_t actuator4,uint16_t actuator5,uint16_t actuator6,uint16_t actuator7,uint16_t actuator8)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ACTUATOR_CMD_LEN];
    _mav_put_uint16_t(buf, 0, actuator1);
    _mav_put_uint16_t(buf, 2, actuator2);
    _mav_put_uint16_t(buf, 4, actuator3);
    _mav_put_uint16_t(buf, 6, actuator4);
    _mav_put_uint16_t(buf, 8, actuator5);
    _mav_put_uint16_t(buf, 10, actuator6);
    _mav_put_uint16_t(buf, 12, actuator7);
    _mav_put_uint16_t(buf, 14, actuator8);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ACTUATOR_CMD_LEN);
#else
    mavlink_actuator_cmd_t packet;
    packet.actuator1 = actuator1;
    packet.actuator2 = actuator2;
    packet.actuator3 = actuator3;
    packet.actuator4 = actuator4;
    packet.actuator5 = actuator5;
    packet.actuator6 = actuator6;
    packet.actuator7 = actuator7;
    packet.actuator8 = actuator8;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ACTUATOR_CMD_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ACTUATOR_CMD;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ACTUATOR_CMD_MIN_LEN, MAVLINK_MSG_ID_ACTUATOR_CMD_LEN, MAVLINK_MSG_ID_ACTUATOR_CMD_CRC);
}

/**
 * @brief Encode a actuator_cmd struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param actuator_cmd C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_actuator_cmd_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_actuator_cmd_t* actuator_cmd)
{
    return mavlink_msg_actuator_cmd_pack(system_id, component_id, msg, actuator_cmd->actuator1, actuator_cmd->actuator2, actuator_cmd->actuator3, actuator_cmd->actuator4, actuator_cmd->actuator5, actuator_cmd->actuator6, actuator_cmd->actuator7, actuator_cmd->actuator8);
}

/**
 * @brief Encode a actuator_cmd struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param actuator_cmd C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_actuator_cmd_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_actuator_cmd_t* actuator_cmd)
{
    return mavlink_msg_actuator_cmd_pack_chan(system_id, component_id, chan, msg, actuator_cmd->actuator1, actuator_cmd->actuator2, actuator_cmd->actuator3, actuator_cmd->actuator4, actuator_cmd->actuator5, actuator_cmd->actuator6, actuator_cmd->actuator7, actuator_cmd->actuator8);
}

/**
 * @brief Send a actuator_cmd message
 * @param chan MAVLink channel to send the message
 *
 * @param actuator1  Value for servo Nr 1
 * @param actuator2  Value for servo Nr 2
 * @param actuator3  Value for servo Nr 3
 * @param actuator4  Value for servo Nr 4
 * @param actuator5  Value for servo Nr 5
 * @param actuator6  Value for servo Nr 6
 * @param actuator7  Value for servo Nr 7
 * @param actuator8  Value for servo Nr 8
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_actuator_cmd_send(mavlink_channel_t chan, uint16_t actuator1, uint16_t actuator2, uint16_t actuator3, uint16_t actuator4, uint16_t actuator5, uint16_t actuator6, uint16_t actuator7, uint16_t actuator8)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ACTUATOR_CMD_LEN];
    _mav_put_uint16_t(buf, 0, actuator1);
    _mav_put_uint16_t(buf, 2, actuator2);
    _mav_put_uint16_t(buf, 4, actuator3);
    _mav_put_uint16_t(buf, 6, actuator4);
    _mav_put_uint16_t(buf, 8, actuator5);
    _mav_put_uint16_t(buf, 10, actuator6);
    _mav_put_uint16_t(buf, 12, actuator7);
    _mav_put_uint16_t(buf, 14, actuator8);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ACTUATOR_CMD, buf, MAVLINK_MSG_ID_ACTUATOR_CMD_MIN_LEN, MAVLINK_MSG_ID_ACTUATOR_CMD_LEN, MAVLINK_MSG_ID_ACTUATOR_CMD_CRC);
#else
    mavlink_actuator_cmd_t packet;
    packet.actuator1 = actuator1;
    packet.actuator2 = actuator2;
    packet.actuator3 = actuator3;
    packet.actuator4 = actuator4;
    packet.actuator5 = actuator5;
    packet.actuator6 = actuator6;
    packet.actuator7 = actuator7;
    packet.actuator8 = actuator8;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ACTUATOR_CMD, (const char *)&packet, MAVLINK_MSG_ID_ACTUATOR_CMD_MIN_LEN, MAVLINK_MSG_ID_ACTUATOR_CMD_LEN, MAVLINK_MSG_ID_ACTUATOR_CMD_CRC);
#endif
}

/**
 * @brief Send a actuator_cmd message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_actuator_cmd_send_struct(mavlink_channel_t chan, const mavlink_actuator_cmd_t* actuator_cmd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_actuator_cmd_send(chan, actuator_cmd->actuator1, actuator_cmd->actuator2, actuator_cmd->actuator3, actuator_cmd->actuator4, actuator_cmd->actuator5, actuator_cmd->actuator6, actuator_cmd->actuator7, actuator_cmd->actuator8);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ACTUATOR_CMD, (const char *)actuator_cmd, MAVLINK_MSG_ID_ACTUATOR_CMD_MIN_LEN, MAVLINK_MSG_ID_ACTUATOR_CMD_LEN, MAVLINK_MSG_ID_ACTUATOR_CMD_CRC);
#endif
}

#if MAVLINK_MSG_ID_ACTUATOR_CMD_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_actuator_cmd_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t actuator1, uint16_t actuator2, uint16_t actuator3, uint16_t actuator4, uint16_t actuator5, uint16_t actuator6, uint16_t actuator7, uint16_t actuator8)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, actuator1);
    _mav_put_uint16_t(buf, 2, actuator2);
    _mav_put_uint16_t(buf, 4, actuator3);
    _mav_put_uint16_t(buf, 6, actuator4);
    _mav_put_uint16_t(buf, 8, actuator5);
    _mav_put_uint16_t(buf, 10, actuator6);
    _mav_put_uint16_t(buf, 12, actuator7);
    _mav_put_uint16_t(buf, 14, actuator8);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ACTUATOR_CMD, buf, MAVLINK_MSG_ID_ACTUATOR_CMD_MIN_LEN, MAVLINK_MSG_ID_ACTUATOR_CMD_LEN, MAVLINK_MSG_ID_ACTUATOR_CMD_CRC);
#else
    mavlink_actuator_cmd_t *packet = (mavlink_actuator_cmd_t *)msgbuf;
    packet->actuator1 = actuator1;
    packet->actuator2 = actuator2;
    packet->actuator3 = actuator3;
    packet->actuator4 = actuator4;
    packet->actuator5 = actuator5;
    packet->actuator6 = actuator6;
    packet->actuator7 = actuator7;
    packet->actuator8 = actuator8;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ACTUATOR_CMD, (const char *)packet, MAVLINK_MSG_ID_ACTUATOR_CMD_MIN_LEN, MAVLINK_MSG_ID_ACTUATOR_CMD_LEN, MAVLINK_MSG_ID_ACTUATOR_CMD_CRC);
#endif
}
#endif

#endif

// MESSAGE ACTUATOR_CMD UNPACKING


/**
 * @brief Get field actuator1 from actuator_cmd message
 *
 * @return  Value for servo Nr 1
 */
static inline uint16_t mavlink_msg_actuator_cmd_get_actuator1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field actuator2 from actuator_cmd message
 *
 * @return  Value for servo Nr 2
 */
static inline uint16_t mavlink_msg_actuator_cmd_get_actuator2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  2);
}

/**
 * @brief Get field actuator3 from actuator_cmd message
 *
 * @return  Value for servo Nr 3
 */
static inline uint16_t mavlink_msg_actuator_cmd_get_actuator3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field actuator4 from actuator_cmd message
 *
 * @return  Value for servo Nr 4
 */
static inline uint16_t mavlink_msg_actuator_cmd_get_actuator4(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  6);
}

/**
 * @brief Get field actuator5 from actuator_cmd message
 *
 * @return  Value for servo Nr 5
 */
static inline uint16_t mavlink_msg_actuator_cmd_get_actuator5(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Get field actuator6 from actuator_cmd message
 *
 * @return  Value for servo Nr 6
 */
static inline uint16_t mavlink_msg_actuator_cmd_get_actuator6(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  10);
}

/**
 * @brief Get field actuator7 from actuator_cmd message
 *
 * @return  Value for servo Nr 7
 */
static inline uint16_t mavlink_msg_actuator_cmd_get_actuator7(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  12);
}

/**
 * @brief Get field actuator8 from actuator_cmd message
 *
 * @return  Value for servo Nr 8
 */
static inline uint16_t mavlink_msg_actuator_cmd_get_actuator8(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  14);
}

/**
 * @brief Decode a actuator_cmd message into a struct
 *
 * @param msg The message to decode
 * @param actuator_cmd C-struct to decode the message contents into
 */
static inline void mavlink_msg_actuator_cmd_decode(const mavlink_message_t* msg, mavlink_actuator_cmd_t* actuator_cmd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    actuator_cmd->actuator1 = mavlink_msg_actuator_cmd_get_actuator1(msg);
    actuator_cmd->actuator2 = mavlink_msg_actuator_cmd_get_actuator2(msg);
    actuator_cmd->actuator3 = mavlink_msg_actuator_cmd_get_actuator3(msg);
    actuator_cmd->actuator4 = mavlink_msg_actuator_cmd_get_actuator4(msg);
    actuator_cmd->actuator5 = mavlink_msg_actuator_cmd_get_actuator5(msg);
    actuator_cmd->actuator6 = mavlink_msg_actuator_cmd_get_actuator6(msg);
    actuator_cmd->actuator7 = mavlink_msg_actuator_cmd_get_actuator7(msg);
    actuator_cmd->actuator8 = mavlink_msg_actuator_cmd_get_actuator8(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ACTUATOR_CMD_LEN? msg->len : MAVLINK_MSG_ID_ACTUATOR_CMD_LEN;
        memset(actuator_cmd, 0, MAVLINK_MSG_ID_ACTUATOR_CMD_LEN);
    memcpy(actuator_cmd, _MAV_PAYLOAD(msg), len);
#endif
}
