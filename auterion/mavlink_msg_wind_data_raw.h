#pragma once
// MESSAGE WIND_DATA_RAW PACKING

#define MAVLINK_MSG_ID_WIND_DATA_RAW 13671


typedef struct __mavlink_wind_data_raw_t {
 uint64_t time_usec; /*< [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.*/
 float wind_speed; /*< [m/s] Wind speed.*/
 float wind_angle; /*< [rad] Wind angle.*/
 uint8_t reference; /*<  Wind reference.*/
} mavlink_wind_data_raw_t;

#define MAVLINK_MSG_ID_WIND_DATA_RAW_LEN 17
#define MAVLINK_MSG_ID_WIND_DATA_RAW_MIN_LEN 17
#define MAVLINK_MSG_ID_13671_LEN 17
#define MAVLINK_MSG_ID_13671_MIN_LEN 17

#define MAVLINK_MSG_ID_WIND_DATA_RAW_CRC 106
#define MAVLINK_MSG_ID_13671_CRC 106



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WIND_DATA_RAW { \
    13671, \
    "WIND_DATA_RAW", \
    4, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_wind_data_raw_t, time_usec) }, \
         { "reference", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_wind_data_raw_t, reference) }, \
         { "wind_speed", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_wind_data_raw_t, wind_speed) }, \
         { "wind_angle", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_wind_data_raw_t, wind_angle) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WIND_DATA_RAW { \
    "WIND_DATA_RAW", \
    4, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_wind_data_raw_t, time_usec) }, \
         { "reference", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_wind_data_raw_t, reference) }, \
         { "wind_speed", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_wind_data_raw_t, wind_speed) }, \
         { "wind_angle", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_wind_data_raw_t, wind_angle) }, \
         } \
}
#endif

/**
 * @brief Pack a wind_data_raw message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param reference  Wind reference.
 * @param wind_speed [m/s] Wind speed.
 * @param wind_angle [rad] Wind angle.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wind_data_raw_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, uint8_t reference, float wind_speed, float wind_angle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WIND_DATA_RAW_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 8, wind_speed);
    _mav_put_float(buf, 12, wind_angle);
    _mav_put_uint8_t(buf, 16, reference);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WIND_DATA_RAW_LEN);
#else
    mavlink_wind_data_raw_t packet;
    packet.time_usec = time_usec;
    packet.wind_speed = wind_speed;
    packet.wind_angle = wind_angle;
    packet.reference = reference;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WIND_DATA_RAW_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WIND_DATA_RAW;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WIND_DATA_RAW_MIN_LEN, MAVLINK_MSG_ID_WIND_DATA_RAW_LEN, MAVLINK_MSG_ID_WIND_DATA_RAW_CRC);
}

/**
 * @brief Pack a wind_data_raw message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param reference  Wind reference.
 * @param wind_speed [m/s] Wind speed.
 * @param wind_angle [rad] Wind angle.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wind_data_raw_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint64_t time_usec, uint8_t reference, float wind_speed, float wind_angle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WIND_DATA_RAW_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 8, wind_speed);
    _mav_put_float(buf, 12, wind_angle);
    _mav_put_uint8_t(buf, 16, reference);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WIND_DATA_RAW_LEN);
#else
    mavlink_wind_data_raw_t packet;
    packet.time_usec = time_usec;
    packet.wind_speed = wind_speed;
    packet.wind_angle = wind_angle;
    packet.reference = reference;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WIND_DATA_RAW_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WIND_DATA_RAW;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_WIND_DATA_RAW_MIN_LEN, MAVLINK_MSG_ID_WIND_DATA_RAW_LEN, MAVLINK_MSG_ID_WIND_DATA_RAW_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_WIND_DATA_RAW_MIN_LEN, MAVLINK_MSG_ID_WIND_DATA_RAW_LEN);
#endif
}

/**
 * @brief Pack a wind_data_raw message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param reference  Wind reference.
 * @param wind_speed [m/s] Wind speed.
 * @param wind_angle [rad] Wind angle.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wind_data_raw_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,uint8_t reference,float wind_speed,float wind_angle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WIND_DATA_RAW_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 8, wind_speed);
    _mav_put_float(buf, 12, wind_angle);
    _mav_put_uint8_t(buf, 16, reference);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WIND_DATA_RAW_LEN);
#else
    mavlink_wind_data_raw_t packet;
    packet.time_usec = time_usec;
    packet.wind_speed = wind_speed;
    packet.wind_angle = wind_angle;
    packet.reference = reference;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WIND_DATA_RAW_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WIND_DATA_RAW;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WIND_DATA_RAW_MIN_LEN, MAVLINK_MSG_ID_WIND_DATA_RAW_LEN, MAVLINK_MSG_ID_WIND_DATA_RAW_CRC);
}

/**
 * @brief Encode a wind_data_raw struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wind_data_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wind_data_raw_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wind_data_raw_t* wind_data_raw)
{
    return mavlink_msg_wind_data_raw_pack(system_id, component_id, msg, wind_data_raw->time_usec, wind_data_raw->reference, wind_data_raw->wind_speed, wind_data_raw->wind_angle);
}

/**
 * @brief Encode a wind_data_raw struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wind_data_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wind_data_raw_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wind_data_raw_t* wind_data_raw)
{
    return mavlink_msg_wind_data_raw_pack_chan(system_id, component_id, chan, msg, wind_data_raw->time_usec, wind_data_raw->reference, wind_data_raw->wind_speed, wind_data_raw->wind_angle);
}

/**
 * @brief Encode a wind_data_raw struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param wind_data_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wind_data_raw_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_wind_data_raw_t* wind_data_raw)
{
    return mavlink_msg_wind_data_raw_pack_status(system_id, component_id, _status, msg,  wind_data_raw->time_usec, wind_data_raw->reference, wind_data_raw->wind_speed, wind_data_raw->wind_angle);
}

/**
 * @brief Send a wind_data_raw message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param reference  Wind reference.
 * @param wind_speed [m/s] Wind speed.
 * @param wind_angle [rad] Wind angle.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wind_data_raw_send(mavlink_channel_t chan, uint64_t time_usec, uint8_t reference, float wind_speed, float wind_angle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WIND_DATA_RAW_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 8, wind_speed);
    _mav_put_float(buf, 12, wind_angle);
    _mav_put_uint8_t(buf, 16, reference);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIND_DATA_RAW, buf, MAVLINK_MSG_ID_WIND_DATA_RAW_MIN_LEN, MAVLINK_MSG_ID_WIND_DATA_RAW_LEN, MAVLINK_MSG_ID_WIND_DATA_RAW_CRC);
#else
    mavlink_wind_data_raw_t packet;
    packet.time_usec = time_usec;
    packet.wind_speed = wind_speed;
    packet.wind_angle = wind_angle;
    packet.reference = reference;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIND_DATA_RAW, (const char *)&packet, MAVLINK_MSG_ID_WIND_DATA_RAW_MIN_LEN, MAVLINK_MSG_ID_WIND_DATA_RAW_LEN, MAVLINK_MSG_ID_WIND_DATA_RAW_CRC);
#endif
}

/**
 * @brief Send a wind_data_raw message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wind_data_raw_send_struct(mavlink_channel_t chan, const mavlink_wind_data_raw_t* wind_data_raw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wind_data_raw_send(chan, wind_data_raw->time_usec, wind_data_raw->reference, wind_data_raw->wind_speed, wind_data_raw->wind_angle);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIND_DATA_RAW, (const char *)wind_data_raw, MAVLINK_MSG_ID_WIND_DATA_RAW_MIN_LEN, MAVLINK_MSG_ID_WIND_DATA_RAW_LEN, MAVLINK_MSG_ID_WIND_DATA_RAW_CRC);
#endif
}

#if MAVLINK_MSG_ID_WIND_DATA_RAW_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wind_data_raw_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, uint8_t reference, float wind_speed, float wind_angle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 8, wind_speed);
    _mav_put_float(buf, 12, wind_angle);
    _mav_put_uint8_t(buf, 16, reference);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIND_DATA_RAW, buf, MAVLINK_MSG_ID_WIND_DATA_RAW_MIN_LEN, MAVLINK_MSG_ID_WIND_DATA_RAW_LEN, MAVLINK_MSG_ID_WIND_DATA_RAW_CRC);
#else
    mavlink_wind_data_raw_t *packet = (mavlink_wind_data_raw_t *)msgbuf;
    packet->time_usec = time_usec;
    packet->wind_speed = wind_speed;
    packet->wind_angle = wind_angle;
    packet->reference = reference;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIND_DATA_RAW, (const char *)packet, MAVLINK_MSG_ID_WIND_DATA_RAW_MIN_LEN, MAVLINK_MSG_ID_WIND_DATA_RAW_LEN, MAVLINK_MSG_ID_WIND_DATA_RAW_CRC);
#endif
}
#endif

#endif

// MESSAGE WIND_DATA_RAW UNPACKING


/**
 * @brief Get field time_usec from wind_data_raw message
 *
 * @return [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 */
static inline uint64_t mavlink_msg_wind_data_raw_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field reference from wind_data_raw message
 *
 * @return  Wind reference.
 */
static inline uint8_t mavlink_msg_wind_data_raw_get_reference(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  16);
}

/**
 * @brief Get field wind_speed from wind_data_raw message
 *
 * @return [m/s] Wind speed.
 */
static inline float mavlink_msg_wind_data_raw_get_wind_speed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field wind_angle from wind_data_raw message
 *
 * @return [rad] Wind angle.
 */
static inline float mavlink_msg_wind_data_raw_get_wind_angle(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Decode a wind_data_raw message into a struct
 *
 * @param msg The message to decode
 * @param wind_data_raw C-struct to decode the message contents into
 */
static inline void mavlink_msg_wind_data_raw_decode(const mavlink_message_t* msg, mavlink_wind_data_raw_t* wind_data_raw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wind_data_raw->time_usec = mavlink_msg_wind_data_raw_get_time_usec(msg);
    wind_data_raw->wind_speed = mavlink_msg_wind_data_raw_get_wind_speed(msg);
    wind_data_raw->wind_angle = mavlink_msg_wind_data_raw_get_wind_angle(msg);
    wind_data_raw->reference = mavlink_msg_wind_data_raw_get_reference(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WIND_DATA_RAW_LEN? msg->len : MAVLINK_MSG_ID_WIND_DATA_RAW_LEN;
        memset(wind_data_raw, 0, MAVLINK_MSG_ID_WIND_DATA_RAW_LEN);
    memcpy(wind_data_raw, _MAV_PAYLOAD(msg), len);
#endif
}
