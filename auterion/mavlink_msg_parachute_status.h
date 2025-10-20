#pragma once
// MESSAGE PARACHUTE_STATUS PACKING

#define MAVLINK_MSG_ID_PARACHUTE_STATUS 430


typedef struct __mavlink_parachute_status_t {
 uint32_t time_boot_ms; /*< [ms] Uptime in ms*/
 uint32_t error_status; /*<  Errors*/
 uint8_t arm_status; /*<  Parachute arming status*/
 uint8_t deployment_status; /*<  Parachute deployment status*/
 uint8_t safety_status; /*<  Parachute safety status*/
 uint8_t ats_arm_altitude; /*< [m] Parachute Automatic Trigger System (ATS) auto-arming/disarming altitude in meters*/
 char parachute_packed_date[11]; /*<  Parachute packed date (YYYY-MM-DD) in ASCII characters, 0 terminated. All 0: field not provided.*/
} mavlink_parachute_status_t;

#define MAVLINK_MSG_ID_PARACHUTE_STATUS_LEN 23
#define MAVLINK_MSG_ID_PARACHUTE_STATUS_MIN_LEN 23
#define MAVLINK_MSG_ID_430_LEN 23
#define MAVLINK_MSG_ID_430_MIN_LEN 23

#define MAVLINK_MSG_ID_PARACHUTE_STATUS_CRC 85
#define MAVLINK_MSG_ID_430_CRC 85

#define MAVLINK_MSG_PARACHUTE_STATUS_FIELD_PARACHUTE_PACKED_DATE_LEN 11

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PARACHUTE_STATUS { \
    430, \
    "PARACHUTE_STATUS", \
    7, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_parachute_status_t, time_boot_ms) }, \
         { "error_status", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_parachute_status_t, error_status) }, \
         { "arm_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_parachute_status_t, arm_status) }, \
         { "deployment_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_parachute_status_t, deployment_status) }, \
         { "safety_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_parachute_status_t, safety_status) }, \
         { "ats_arm_altitude", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_parachute_status_t, ats_arm_altitude) }, \
         { "parachute_packed_date", NULL, MAVLINK_TYPE_CHAR, 11, 12, offsetof(mavlink_parachute_status_t, parachute_packed_date) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PARACHUTE_STATUS { \
    "PARACHUTE_STATUS", \
    7, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_parachute_status_t, time_boot_ms) }, \
         { "error_status", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_parachute_status_t, error_status) }, \
         { "arm_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_parachute_status_t, arm_status) }, \
         { "deployment_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_parachute_status_t, deployment_status) }, \
         { "safety_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_parachute_status_t, safety_status) }, \
         { "ats_arm_altitude", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_parachute_status_t, ats_arm_altitude) }, \
         { "parachute_packed_date", NULL, MAVLINK_TYPE_CHAR, 11, 12, offsetof(mavlink_parachute_status_t, parachute_packed_date) }, \
         } \
}
#endif

/**
 * @brief Pack a parachute_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Uptime in ms
 * @param error_status  Errors
 * @param arm_status  Parachute arming status
 * @param deployment_status  Parachute deployment status
 * @param safety_status  Parachute safety status
 * @param ats_arm_altitude [m] Parachute Automatic Trigger System (ATS) auto-arming/disarming altitude in meters
 * @param parachute_packed_date  Parachute packed date (YYYY-MM-DD) in ASCII characters, 0 terminated. All 0: field not provided.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_parachute_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, uint32_t error_status, uint8_t arm_status, uint8_t deployment_status, uint8_t safety_status, uint8_t ats_arm_altitude, const char *parachute_packed_date)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PARACHUTE_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint32_t(buf, 4, error_status);
    _mav_put_uint8_t(buf, 8, arm_status);
    _mav_put_uint8_t(buf, 9, deployment_status);
    _mav_put_uint8_t(buf, 10, safety_status);
    _mav_put_uint8_t(buf, 11, ats_arm_altitude);
    _mav_put_char_array(buf, 12, parachute_packed_date, 11);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PARACHUTE_STATUS_LEN);
#else
    mavlink_parachute_status_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.error_status = error_status;
    packet.arm_status = arm_status;
    packet.deployment_status = deployment_status;
    packet.safety_status = safety_status;
    packet.ats_arm_altitude = ats_arm_altitude;
    mav_array_assign_char(packet.parachute_packed_date, parachute_packed_date, 11);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PARACHUTE_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PARACHUTE_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PARACHUTE_STATUS_MIN_LEN, MAVLINK_MSG_ID_PARACHUTE_STATUS_LEN, MAVLINK_MSG_ID_PARACHUTE_STATUS_CRC);
}

/**
 * @brief Pack a parachute_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Uptime in ms
 * @param error_status  Errors
 * @param arm_status  Parachute arming status
 * @param deployment_status  Parachute deployment status
 * @param safety_status  Parachute safety status
 * @param ats_arm_altitude [m] Parachute Automatic Trigger System (ATS) auto-arming/disarming altitude in meters
 * @param parachute_packed_date  Parachute packed date (YYYY-MM-DD) in ASCII characters, 0 terminated. All 0: field not provided.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_parachute_status_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint32_t time_boot_ms, uint32_t error_status, uint8_t arm_status, uint8_t deployment_status, uint8_t safety_status, uint8_t ats_arm_altitude, const char *parachute_packed_date)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PARACHUTE_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint32_t(buf, 4, error_status);
    _mav_put_uint8_t(buf, 8, arm_status);
    _mav_put_uint8_t(buf, 9, deployment_status);
    _mav_put_uint8_t(buf, 10, safety_status);
    _mav_put_uint8_t(buf, 11, ats_arm_altitude);
    _mav_put_char_array(buf, 12, parachute_packed_date, 11);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PARACHUTE_STATUS_LEN);
#else
    mavlink_parachute_status_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.error_status = error_status;
    packet.arm_status = arm_status;
    packet.deployment_status = deployment_status;
    packet.safety_status = safety_status;
    packet.ats_arm_altitude = ats_arm_altitude;
    mav_array_memcpy(packet.parachute_packed_date, parachute_packed_date, sizeof(char)*11);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PARACHUTE_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PARACHUTE_STATUS;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_PARACHUTE_STATUS_MIN_LEN, MAVLINK_MSG_ID_PARACHUTE_STATUS_LEN, MAVLINK_MSG_ID_PARACHUTE_STATUS_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_PARACHUTE_STATUS_MIN_LEN, MAVLINK_MSG_ID_PARACHUTE_STATUS_LEN);
#endif
}

/**
 * @brief Pack a parachute_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms [ms] Uptime in ms
 * @param error_status  Errors
 * @param arm_status  Parachute arming status
 * @param deployment_status  Parachute deployment status
 * @param safety_status  Parachute safety status
 * @param ats_arm_altitude [m] Parachute Automatic Trigger System (ATS) auto-arming/disarming altitude in meters
 * @param parachute_packed_date  Parachute packed date (YYYY-MM-DD) in ASCII characters, 0 terminated. All 0: field not provided.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_parachute_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,uint32_t error_status,uint8_t arm_status,uint8_t deployment_status,uint8_t safety_status,uint8_t ats_arm_altitude,const char *parachute_packed_date)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PARACHUTE_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint32_t(buf, 4, error_status);
    _mav_put_uint8_t(buf, 8, arm_status);
    _mav_put_uint8_t(buf, 9, deployment_status);
    _mav_put_uint8_t(buf, 10, safety_status);
    _mav_put_uint8_t(buf, 11, ats_arm_altitude);
    _mav_put_char_array(buf, 12, parachute_packed_date, 11);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PARACHUTE_STATUS_LEN);
#else
    mavlink_parachute_status_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.error_status = error_status;
    packet.arm_status = arm_status;
    packet.deployment_status = deployment_status;
    packet.safety_status = safety_status;
    packet.ats_arm_altitude = ats_arm_altitude;
    mav_array_assign_char(packet.parachute_packed_date, parachute_packed_date, 11);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PARACHUTE_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PARACHUTE_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PARACHUTE_STATUS_MIN_LEN, MAVLINK_MSG_ID_PARACHUTE_STATUS_LEN, MAVLINK_MSG_ID_PARACHUTE_STATUS_CRC);
}

/**
 * @brief Encode a parachute_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param parachute_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_parachute_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_parachute_status_t* parachute_status)
{
    return mavlink_msg_parachute_status_pack(system_id, component_id, msg, parachute_status->time_boot_ms, parachute_status->error_status, parachute_status->arm_status, parachute_status->deployment_status, parachute_status->safety_status, parachute_status->ats_arm_altitude, parachute_status->parachute_packed_date);
}

/**
 * @brief Encode a parachute_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param parachute_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_parachute_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_parachute_status_t* parachute_status)
{
    return mavlink_msg_parachute_status_pack_chan(system_id, component_id, chan, msg, parachute_status->time_boot_ms, parachute_status->error_status, parachute_status->arm_status, parachute_status->deployment_status, parachute_status->safety_status, parachute_status->ats_arm_altitude, parachute_status->parachute_packed_date);
}

/**
 * @brief Encode a parachute_status struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param parachute_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_parachute_status_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_parachute_status_t* parachute_status)
{
    return mavlink_msg_parachute_status_pack_status(system_id, component_id, _status, msg,  parachute_status->time_boot_ms, parachute_status->error_status, parachute_status->arm_status, parachute_status->deployment_status, parachute_status->safety_status, parachute_status->ats_arm_altitude, parachute_status->parachute_packed_date);
}

/**
 * @brief Send a parachute_status message
 * @param chan MAVLink channel to send the message
 *
 * @param time_boot_ms [ms] Uptime in ms
 * @param error_status  Errors
 * @param arm_status  Parachute arming status
 * @param deployment_status  Parachute deployment status
 * @param safety_status  Parachute safety status
 * @param ats_arm_altitude [m] Parachute Automatic Trigger System (ATS) auto-arming/disarming altitude in meters
 * @param parachute_packed_date  Parachute packed date (YYYY-MM-DD) in ASCII characters, 0 terminated. All 0: field not provided.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_parachute_status_send(mavlink_channel_t chan, uint32_t time_boot_ms, uint32_t error_status, uint8_t arm_status, uint8_t deployment_status, uint8_t safety_status, uint8_t ats_arm_altitude, const char *parachute_packed_date)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PARACHUTE_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint32_t(buf, 4, error_status);
    _mav_put_uint8_t(buf, 8, arm_status);
    _mav_put_uint8_t(buf, 9, deployment_status);
    _mav_put_uint8_t(buf, 10, safety_status);
    _mav_put_uint8_t(buf, 11, ats_arm_altitude);
    _mav_put_char_array(buf, 12, parachute_packed_date, 11);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARACHUTE_STATUS, buf, MAVLINK_MSG_ID_PARACHUTE_STATUS_MIN_LEN, MAVLINK_MSG_ID_PARACHUTE_STATUS_LEN, MAVLINK_MSG_ID_PARACHUTE_STATUS_CRC);
#else
    mavlink_parachute_status_t packet;
    packet.time_boot_ms = time_boot_ms;
    packet.error_status = error_status;
    packet.arm_status = arm_status;
    packet.deployment_status = deployment_status;
    packet.safety_status = safety_status;
    packet.ats_arm_altitude = ats_arm_altitude;
    mav_array_assign_char(packet.parachute_packed_date, parachute_packed_date, 11);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARACHUTE_STATUS, (const char *)&packet, MAVLINK_MSG_ID_PARACHUTE_STATUS_MIN_LEN, MAVLINK_MSG_ID_PARACHUTE_STATUS_LEN, MAVLINK_MSG_ID_PARACHUTE_STATUS_CRC);
#endif
}

/**
 * @brief Send a parachute_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_parachute_status_send_struct(mavlink_channel_t chan, const mavlink_parachute_status_t* parachute_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_parachute_status_send(chan, parachute_status->time_boot_ms, parachute_status->error_status, parachute_status->arm_status, parachute_status->deployment_status, parachute_status->safety_status, parachute_status->ats_arm_altitude, parachute_status->parachute_packed_date);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARACHUTE_STATUS, (const char *)parachute_status, MAVLINK_MSG_ID_PARACHUTE_STATUS_MIN_LEN, MAVLINK_MSG_ID_PARACHUTE_STATUS_LEN, MAVLINK_MSG_ID_PARACHUTE_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_PARACHUTE_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_parachute_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time_boot_ms, uint32_t error_status, uint8_t arm_status, uint8_t deployment_status, uint8_t safety_status, uint8_t ats_arm_altitude, const char *parachute_packed_date)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_uint32_t(buf, 4, error_status);
    _mav_put_uint8_t(buf, 8, arm_status);
    _mav_put_uint8_t(buf, 9, deployment_status);
    _mav_put_uint8_t(buf, 10, safety_status);
    _mav_put_uint8_t(buf, 11, ats_arm_altitude);
    _mav_put_char_array(buf, 12, parachute_packed_date, 11);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARACHUTE_STATUS, buf, MAVLINK_MSG_ID_PARACHUTE_STATUS_MIN_LEN, MAVLINK_MSG_ID_PARACHUTE_STATUS_LEN, MAVLINK_MSG_ID_PARACHUTE_STATUS_CRC);
#else
    mavlink_parachute_status_t *packet = (mavlink_parachute_status_t *)msgbuf;
    packet->time_boot_ms = time_boot_ms;
    packet->error_status = error_status;
    packet->arm_status = arm_status;
    packet->deployment_status = deployment_status;
    packet->safety_status = safety_status;
    packet->ats_arm_altitude = ats_arm_altitude;
    mav_array_assign_char(packet->parachute_packed_date, parachute_packed_date, 11);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARACHUTE_STATUS, (const char *)packet, MAVLINK_MSG_ID_PARACHUTE_STATUS_MIN_LEN, MAVLINK_MSG_ID_PARACHUTE_STATUS_LEN, MAVLINK_MSG_ID_PARACHUTE_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE PARACHUTE_STATUS UNPACKING


/**
 * @brief Get field time_boot_ms from parachute_status message
 *
 * @return [ms] Uptime in ms
 */
static inline uint32_t mavlink_msg_parachute_status_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field error_status from parachute_status message
 *
 * @return  Errors
 */
static inline uint32_t mavlink_msg_parachute_status_get_error_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field arm_status from parachute_status message
 *
 * @return  Parachute arming status
 */
static inline uint8_t mavlink_msg_parachute_status_get_arm_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field deployment_status from parachute_status message
 *
 * @return  Parachute deployment status
 */
static inline uint8_t mavlink_msg_parachute_status_get_deployment_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field safety_status from parachute_status message
 *
 * @return  Parachute safety status
 */
static inline uint8_t mavlink_msg_parachute_status_get_safety_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  10);
}

/**
 * @brief Get field ats_arm_altitude from parachute_status message
 *
 * @return [m] Parachute Automatic Trigger System (ATS) auto-arming/disarming altitude in meters
 */
static inline uint8_t mavlink_msg_parachute_status_get_ats_arm_altitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  11);
}

/**
 * @brief Get field parachute_packed_date from parachute_status message
 *
 * @return  Parachute packed date (YYYY-MM-DD) in ASCII characters, 0 terminated. All 0: field not provided.
 */
static inline uint16_t mavlink_msg_parachute_status_get_parachute_packed_date(const mavlink_message_t* msg, char *parachute_packed_date)
{
    return _MAV_RETURN_char_array(msg, parachute_packed_date, 11,  12);
}

/**
 * @brief Decode a parachute_status message into a struct
 *
 * @param msg The message to decode
 * @param parachute_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_parachute_status_decode(const mavlink_message_t* msg, mavlink_parachute_status_t* parachute_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    parachute_status->time_boot_ms = mavlink_msg_parachute_status_get_time_boot_ms(msg);
    parachute_status->error_status = mavlink_msg_parachute_status_get_error_status(msg);
    parachute_status->arm_status = mavlink_msg_parachute_status_get_arm_status(msg);
    parachute_status->deployment_status = mavlink_msg_parachute_status_get_deployment_status(msg);
    parachute_status->safety_status = mavlink_msg_parachute_status_get_safety_status(msg);
    parachute_status->ats_arm_altitude = mavlink_msg_parachute_status_get_ats_arm_altitude(msg);
    mavlink_msg_parachute_status_get_parachute_packed_date(msg, parachute_status->parachute_packed_date);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_PARACHUTE_STATUS_LEN? msg->len : MAVLINK_MSG_ID_PARACHUTE_STATUS_LEN;
        memset(parachute_status, 0, MAVLINK_MSG_ID_PARACHUTE_STATUS_LEN);
    memcpy(parachute_status, _MAV_PAYLOAD(msg), len);
#endif
}
