#pragma once
// MESSAGE SERIAL_UDB_EXTRA_F15 PACKING

#define MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15 179


typedef struct __mavlink_serial_udb_extra_f15_t {
 uint8_t sue_ID_VEHICLE_MODEL_NAME[40]; /*<  Serial UDB Extra Model Name Of Vehicle*/
 uint8_t sue_ID_VEHICLE_REGISTRATION[20]; /*<  Serial UDB Extra Registraton Number of Vehicle*/
} mavlink_serial_udb_extra_f15_t;

#define MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_LEN 60
#define MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_MIN_LEN 60
#define MAVLINK_MSG_ID_179_LEN 60
#define MAVLINK_MSG_ID_179_MIN_LEN 60

#define MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_CRC 7
#define MAVLINK_MSG_ID_179_CRC 7

#define MAVLINK_MSG_SERIAL_UDB_EXTRA_F15_FIELD_SUE_ID_VEHICLE_MODEL_NAME_LEN 40
#define MAVLINK_MSG_SERIAL_UDB_EXTRA_F15_FIELD_SUE_ID_VEHICLE_REGISTRATION_LEN 20

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SERIAL_UDB_EXTRA_F15 { \
    179, \
    "SERIAL_UDB_EXTRA_F15", \
    2, \
    {  { "sue_ID_VEHICLE_MODEL_NAME", NULL, MAVLINK_TYPE_UINT8_T, 40, 0, offsetof(mavlink_serial_udb_extra_f15_t, sue_ID_VEHICLE_MODEL_NAME) }, \
         { "sue_ID_VEHICLE_REGISTRATION", NULL, MAVLINK_TYPE_UINT8_T, 20, 40, offsetof(mavlink_serial_udb_extra_f15_t, sue_ID_VEHICLE_REGISTRATION) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SERIAL_UDB_EXTRA_F15 { \
    "SERIAL_UDB_EXTRA_F15", \
    2, \
    {  { "sue_ID_VEHICLE_MODEL_NAME", NULL, MAVLINK_TYPE_UINT8_T, 40, 0, offsetof(mavlink_serial_udb_extra_f15_t, sue_ID_VEHICLE_MODEL_NAME) }, \
         { "sue_ID_VEHICLE_REGISTRATION", NULL, MAVLINK_TYPE_UINT8_T, 20, 40, offsetof(mavlink_serial_udb_extra_f15_t, sue_ID_VEHICLE_REGISTRATION) }, \
         } \
}
#endif

/**
 * @brief Pack a serial_udb_extra_f15 message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param sue_ID_VEHICLE_MODEL_NAME  Serial UDB Extra Model Name Of Vehicle
 * @param sue_ID_VEHICLE_REGISTRATION  Serial UDB Extra Registraton Number of Vehicle
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_serial_udb_extra_f15_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const uint8_t *sue_ID_VEHICLE_MODEL_NAME, const uint8_t *sue_ID_VEHICLE_REGISTRATION)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_LEN];

    _mav_put_uint8_t_array(buf, 0, sue_ID_VEHICLE_MODEL_NAME, 40);
    _mav_put_uint8_t_array(buf, 40, sue_ID_VEHICLE_REGISTRATION, 20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_LEN);
#else
    mavlink_serial_udb_extra_f15_t packet;

    mav_array_assign_uint8_t(packet.sue_ID_VEHICLE_MODEL_NAME, sue_ID_VEHICLE_MODEL_NAME, 40);
    mav_array_assign_uint8_t(packet.sue_ID_VEHICLE_REGISTRATION, sue_ID_VEHICLE_REGISTRATION, 20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_MIN_LEN, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_LEN, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_CRC);
}

/**
 * @brief Pack a serial_udb_extra_f15 message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param sue_ID_VEHICLE_MODEL_NAME  Serial UDB Extra Model Name Of Vehicle
 * @param sue_ID_VEHICLE_REGISTRATION  Serial UDB Extra Registraton Number of Vehicle
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_serial_udb_extra_f15_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               const uint8_t *sue_ID_VEHICLE_MODEL_NAME, const uint8_t *sue_ID_VEHICLE_REGISTRATION)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_LEN];

    _mav_put_uint8_t_array(buf, 0, sue_ID_VEHICLE_MODEL_NAME, 40);
    _mav_put_uint8_t_array(buf, 40, sue_ID_VEHICLE_REGISTRATION, 20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_LEN);
#else
    mavlink_serial_udb_extra_f15_t packet;

    mav_array_memcpy(packet.sue_ID_VEHICLE_MODEL_NAME, sue_ID_VEHICLE_MODEL_NAME, sizeof(uint8_t)*40);
    mav_array_memcpy(packet.sue_ID_VEHICLE_REGISTRATION, sue_ID_VEHICLE_REGISTRATION, sizeof(uint8_t)*20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_MIN_LEN, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_LEN, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_MIN_LEN, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_LEN);
#endif
}

/**
 * @brief Pack a serial_udb_extra_f15 message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sue_ID_VEHICLE_MODEL_NAME  Serial UDB Extra Model Name Of Vehicle
 * @param sue_ID_VEHICLE_REGISTRATION  Serial UDB Extra Registraton Number of Vehicle
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_serial_udb_extra_f15_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const uint8_t *sue_ID_VEHICLE_MODEL_NAME,const uint8_t *sue_ID_VEHICLE_REGISTRATION)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_LEN];

    _mav_put_uint8_t_array(buf, 0, sue_ID_VEHICLE_MODEL_NAME, 40);
    _mav_put_uint8_t_array(buf, 40, sue_ID_VEHICLE_REGISTRATION, 20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_LEN);
#else
    mavlink_serial_udb_extra_f15_t packet;

    mav_array_assign_uint8_t(packet.sue_ID_VEHICLE_MODEL_NAME, sue_ID_VEHICLE_MODEL_NAME, 40);
    mav_array_assign_uint8_t(packet.sue_ID_VEHICLE_REGISTRATION, sue_ID_VEHICLE_REGISTRATION, 20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_MIN_LEN, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_LEN, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_CRC);
}

/**
 * @brief Encode a serial_udb_extra_f15 struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param serial_udb_extra_f15 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_serial_udb_extra_f15_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_serial_udb_extra_f15_t* serial_udb_extra_f15)
{
    return mavlink_msg_serial_udb_extra_f15_pack(system_id, component_id, msg, serial_udb_extra_f15->sue_ID_VEHICLE_MODEL_NAME, serial_udb_extra_f15->sue_ID_VEHICLE_REGISTRATION);
}

/**
 * @brief Encode a serial_udb_extra_f15 struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param serial_udb_extra_f15 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_serial_udb_extra_f15_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_serial_udb_extra_f15_t* serial_udb_extra_f15)
{
    return mavlink_msg_serial_udb_extra_f15_pack_chan(system_id, component_id, chan, msg, serial_udb_extra_f15->sue_ID_VEHICLE_MODEL_NAME, serial_udb_extra_f15->sue_ID_VEHICLE_REGISTRATION);
}

/**
 * @brief Encode a serial_udb_extra_f15 struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param serial_udb_extra_f15 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_serial_udb_extra_f15_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_serial_udb_extra_f15_t* serial_udb_extra_f15)
{
    return mavlink_msg_serial_udb_extra_f15_pack_status(system_id, component_id, _status, msg,  serial_udb_extra_f15->sue_ID_VEHICLE_MODEL_NAME, serial_udb_extra_f15->sue_ID_VEHICLE_REGISTRATION);
}

/**
 * @brief Send a serial_udb_extra_f15 message
 * @param chan MAVLink channel to send the message
 *
 * @param sue_ID_VEHICLE_MODEL_NAME  Serial UDB Extra Model Name Of Vehicle
 * @param sue_ID_VEHICLE_REGISTRATION  Serial UDB Extra Registraton Number of Vehicle
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_serial_udb_extra_f15_send(mavlink_channel_t chan, const uint8_t *sue_ID_VEHICLE_MODEL_NAME, const uint8_t *sue_ID_VEHICLE_REGISTRATION)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_LEN];

    _mav_put_uint8_t_array(buf, 0, sue_ID_VEHICLE_MODEL_NAME, 40);
    _mav_put_uint8_t_array(buf, 40, sue_ID_VEHICLE_REGISTRATION, 20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15, buf, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_MIN_LEN, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_LEN, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_CRC);
#else
    mavlink_serial_udb_extra_f15_t packet;

    mav_array_assign_uint8_t(packet.sue_ID_VEHICLE_MODEL_NAME, sue_ID_VEHICLE_MODEL_NAME, 40);
    mav_array_assign_uint8_t(packet.sue_ID_VEHICLE_REGISTRATION, sue_ID_VEHICLE_REGISTRATION, 20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15, (const char *)&packet, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_MIN_LEN, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_LEN, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_CRC);
#endif
}

/**
 * @brief Send a serial_udb_extra_f15 message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_serial_udb_extra_f15_send_struct(mavlink_channel_t chan, const mavlink_serial_udb_extra_f15_t* serial_udb_extra_f15)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_serial_udb_extra_f15_send(chan, serial_udb_extra_f15->sue_ID_VEHICLE_MODEL_NAME, serial_udb_extra_f15->sue_ID_VEHICLE_REGISTRATION);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15, (const char *)serial_udb_extra_f15, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_MIN_LEN, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_LEN, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_CRC);
#endif
}

#if MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_serial_udb_extra_f15_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const uint8_t *sue_ID_VEHICLE_MODEL_NAME, const uint8_t *sue_ID_VEHICLE_REGISTRATION)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;

    _mav_put_uint8_t_array(buf, 0, sue_ID_VEHICLE_MODEL_NAME, 40);
    _mav_put_uint8_t_array(buf, 40, sue_ID_VEHICLE_REGISTRATION, 20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15, buf, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_MIN_LEN, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_LEN, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_CRC);
#else
    mavlink_serial_udb_extra_f15_t *packet = (mavlink_serial_udb_extra_f15_t *)msgbuf;

    mav_array_assign_uint8_t(packet->sue_ID_VEHICLE_MODEL_NAME, sue_ID_VEHICLE_MODEL_NAME, 40);
    mav_array_assign_uint8_t(packet->sue_ID_VEHICLE_REGISTRATION, sue_ID_VEHICLE_REGISTRATION, 20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15, (const char *)packet, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_MIN_LEN, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_LEN, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_CRC);
#endif
}
#endif

#endif

// MESSAGE SERIAL_UDB_EXTRA_F15 UNPACKING


/**
 * @brief Get field sue_ID_VEHICLE_MODEL_NAME from serial_udb_extra_f15 message
 *
 * @return  Serial UDB Extra Model Name Of Vehicle
 */
static inline uint16_t mavlink_msg_serial_udb_extra_f15_get_sue_ID_VEHICLE_MODEL_NAME(const mavlink_message_t* msg, uint8_t *sue_ID_VEHICLE_MODEL_NAME)
{
    return _MAV_RETURN_uint8_t_array(msg, sue_ID_VEHICLE_MODEL_NAME, 40,  0);
}

/**
 * @brief Get field sue_ID_VEHICLE_REGISTRATION from serial_udb_extra_f15 message
 *
 * @return  Serial UDB Extra Registraton Number of Vehicle
 */
static inline uint16_t mavlink_msg_serial_udb_extra_f15_get_sue_ID_VEHICLE_REGISTRATION(const mavlink_message_t* msg, uint8_t *sue_ID_VEHICLE_REGISTRATION)
{
    return _MAV_RETURN_uint8_t_array(msg, sue_ID_VEHICLE_REGISTRATION, 20,  40);
}

/**
 * @brief Decode a serial_udb_extra_f15 message into a struct
 *
 * @param msg The message to decode
 * @param serial_udb_extra_f15 C-struct to decode the message contents into
 */
static inline void mavlink_msg_serial_udb_extra_f15_decode(const mavlink_message_t* msg, mavlink_serial_udb_extra_f15_t* serial_udb_extra_f15)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_serial_udb_extra_f15_get_sue_ID_VEHICLE_MODEL_NAME(msg, serial_udb_extra_f15->sue_ID_VEHICLE_MODEL_NAME);
    mavlink_msg_serial_udb_extra_f15_get_sue_ID_VEHICLE_REGISTRATION(msg, serial_udb_extra_f15->sue_ID_VEHICLE_REGISTRATION);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_LEN? msg->len : MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_LEN;
        memset(serial_udb_extra_f15, 0, MAVLINK_MSG_ID_SERIAL_UDB_EXTRA_F15_LEN);
    memcpy(serial_udb_extra_f15, _MAV_PAYLOAD(msg), len);
#endif
}
