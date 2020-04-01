#pragma once
// MESSAGE RAW_RPM PACKING

#define MAVLINK_MSG_ID_RAW_RPM 336

MAVPACKED(
typedef struct __mavlink_raw_rpm_t {
 uint64_t timestamp; /*< [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.*/
 float indicated_frequency_rpm; /*<  indicated rotor Frequency in Revolution per minute.*/
 float estimated_accurancy_rpm; /*<  estimated accurancy in Revolution per minute.*/
}) mavlink_raw_rpm_t;

#define MAVLINK_MSG_ID_RAW_RPM_LEN 16
#define MAVLINK_MSG_ID_RAW_RPM_MIN_LEN 16
#define MAVLINK_MSG_ID_336_LEN 16
#define MAVLINK_MSG_ID_336_MIN_LEN 16

#define MAVLINK_MSG_ID_RAW_RPM_CRC 92
#define MAVLINK_MSG_ID_336_CRC 92



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RAW_RPM { \
    336, \
    "RAW_RPM", \
    3, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_raw_rpm_t, timestamp) }, \
         { "indicated_frequency_rpm", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_raw_rpm_t, indicated_frequency_rpm) }, \
         { "estimated_accurancy_rpm", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_raw_rpm_t, estimated_accurancy_rpm) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_RAW_RPM { \
    "RAW_RPM", \
    3, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_raw_rpm_t, timestamp) }, \
         { "indicated_frequency_rpm", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_raw_rpm_t, indicated_frequency_rpm) }, \
         { "estimated_accurancy_rpm", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_raw_rpm_t, estimated_accurancy_rpm) }, \
         } \
}
#endif

/**
 * @brief Pack a raw_rpm message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param indicated_frequency_rpm  indicated rotor Frequency in Revolution per minute.
 * @param estimated_accurancy_rpm  estimated accurancy in Revolution per minute.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_raw_rpm_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t timestamp, float indicated_frequency_rpm, float estimated_accurancy_rpm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RAW_RPM_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float(buf, 8, indicated_frequency_rpm);
    _mav_put_float(buf, 12, estimated_accurancy_rpm);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RAW_RPM_LEN);
#else
    mavlink_raw_rpm_t packet;
    packet.timestamp = timestamp;
    packet.indicated_frequency_rpm = indicated_frequency_rpm;
    packet.estimated_accurancy_rpm = estimated_accurancy_rpm;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RAW_RPM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RAW_RPM;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RAW_RPM_MIN_LEN, MAVLINK_MSG_ID_RAW_RPM_LEN, MAVLINK_MSG_ID_RAW_RPM_CRC);
}

/**
 * @brief Pack a raw_rpm message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param indicated_frequency_rpm  indicated rotor Frequency in Revolution per minute.
 * @param estimated_accurancy_rpm  estimated accurancy in Revolution per minute.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_raw_rpm_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t timestamp,float indicated_frequency_rpm,float estimated_accurancy_rpm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RAW_RPM_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float(buf, 8, indicated_frequency_rpm);
    _mav_put_float(buf, 12, estimated_accurancy_rpm);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RAW_RPM_LEN);
#else
    mavlink_raw_rpm_t packet;
    packet.timestamp = timestamp;
    packet.indicated_frequency_rpm = indicated_frequency_rpm;
    packet.estimated_accurancy_rpm = estimated_accurancy_rpm;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RAW_RPM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RAW_RPM;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RAW_RPM_MIN_LEN, MAVLINK_MSG_ID_RAW_RPM_LEN, MAVLINK_MSG_ID_RAW_RPM_CRC);
}

/**
 * @brief Encode a raw_rpm struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param raw_rpm C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_raw_rpm_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_raw_rpm_t* raw_rpm)
{
    return mavlink_msg_raw_rpm_pack(system_id, component_id, msg, raw_rpm->timestamp, raw_rpm->indicated_frequency_rpm, raw_rpm->estimated_accurancy_rpm);
}

/**
 * @brief Encode a raw_rpm struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param raw_rpm C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_raw_rpm_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_raw_rpm_t* raw_rpm)
{
    return mavlink_msg_raw_rpm_pack_chan(system_id, component_id, chan, msg, raw_rpm->timestamp, raw_rpm->indicated_frequency_rpm, raw_rpm->estimated_accurancy_rpm);
}

/**
 * @brief Send a raw_rpm message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param indicated_frequency_rpm  indicated rotor Frequency in Revolution per minute.
 * @param estimated_accurancy_rpm  estimated accurancy in Revolution per minute.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_raw_rpm_send(mavlink_channel_t chan, uint64_t timestamp, float indicated_frequency_rpm, float estimated_accurancy_rpm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RAW_RPM_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float(buf, 8, indicated_frequency_rpm);
    _mav_put_float(buf, 12, estimated_accurancy_rpm);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RAW_RPM, buf, MAVLINK_MSG_ID_RAW_RPM_MIN_LEN, MAVLINK_MSG_ID_RAW_RPM_LEN, MAVLINK_MSG_ID_RAW_RPM_CRC);
#else
    mavlink_raw_rpm_t packet;
    packet.timestamp = timestamp;
    packet.indicated_frequency_rpm = indicated_frequency_rpm;
    packet.estimated_accurancy_rpm = estimated_accurancy_rpm;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RAW_RPM, (const char *)&packet, MAVLINK_MSG_ID_RAW_RPM_MIN_LEN, MAVLINK_MSG_ID_RAW_RPM_LEN, MAVLINK_MSG_ID_RAW_RPM_CRC);
#endif
}

/**
 * @brief Send a raw_rpm message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_raw_rpm_send_struct(mavlink_channel_t chan, const mavlink_raw_rpm_t* raw_rpm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_raw_rpm_send(chan, raw_rpm->timestamp, raw_rpm->indicated_frequency_rpm, raw_rpm->estimated_accurancy_rpm);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RAW_RPM, (const char *)raw_rpm, MAVLINK_MSG_ID_RAW_RPM_MIN_LEN, MAVLINK_MSG_ID_RAW_RPM_LEN, MAVLINK_MSG_ID_RAW_RPM_CRC);
#endif
}

#if MAVLINK_MSG_ID_RAW_RPM_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_raw_rpm_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t timestamp, float indicated_frequency_rpm, float estimated_accurancy_rpm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float(buf, 8, indicated_frequency_rpm);
    _mav_put_float(buf, 12, estimated_accurancy_rpm);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RAW_RPM, buf, MAVLINK_MSG_ID_RAW_RPM_MIN_LEN, MAVLINK_MSG_ID_RAW_RPM_LEN, MAVLINK_MSG_ID_RAW_RPM_CRC);
#else
    mavlink_raw_rpm_t *packet = (mavlink_raw_rpm_t *)msgbuf;
    packet->timestamp = timestamp;
    packet->indicated_frequency_rpm = indicated_frequency_rpm;
    packet->estimated_accurancy_rpm = estimated_accurancy_rpm;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RAW_RPM, (const char *)packet, MAVLINK_MSG_ID_RAW_RPM_MIN_LEN, MAVLINK_MSG_ID_RAW_RPM_LEN, MAVLINK_MSG_ID_RAW_RPM_CRC);
#endif
}
#endif

#endif

// MESSAGE RAW_RPM UNPACKING


/**
 * @brief Get field timestamp from raw_rpm message
 *
 * @return [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 */
static inline uint64_t mavlink_msg_raw_rpm_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field indicated_frequency_rpm from raw_rpm message
 *
 * @return  indicated rotor Frequency in Revolution per minute.
 */
static inline float mavlink_msg_raw_rpm_get_indicated_frequency_rpm(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field estimated_accurancy_rpm from raw_rpm message
 *
 * @return  estimated accurancy in Revolution per minute.
 */
static inline float mavlink_msg_raw_rpm_get_estimated_accurancy_rpm(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Decode a raw_rpm message into a struct
 *
 * @param msg The message to decode
 * @param raw_rpm C-struct to decode the message contents into
 */
static inline void mavlink_msg_raw_rpm_decode(const mavlink_message_t* msg, mavlink_raw_rpm_t* raw_rpm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    raw_rpm->timestamp = mavlink_msg_raw_rpm_get_timestamp(msg);
    raw_rpm->indicated_frequency_rpm = mavlink_msg_raw_rpm_get_indicated_frequency_rpm(msg);
    raw_rpm->estimated_accurancy_rpm = mavlink_msg_raw_rpm_get_estimated_accurancy_rpm(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_RAW_RPM_LEN? msg->len : MAVLINK_MSG_ID_RAW_RPM_LEN;
        memset(raw_rpm, 0, MAVLINK_MSG_ID_RAW_RPM_LEN);
    memcpy(raw_rpm, _MAV_PAYLOAD(msg), len);
#endif
}
