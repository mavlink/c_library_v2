#pragma once
// MESSAGE ESTIMATOR_SENSOR_FUSION_STATUS PACKING

#define MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS 514


typedef struct __mavlink_estimator_sensor_fusion_status_t {
 float test_ratio[9]; /*<  Per-source normalized innovation test ratio. NaN if not available.*/
 uint8_t intended[9]; /*<  Per-source instance bitmask of sensors the estimator intends to fuse (reflects CTRL params with runtime overrides via MAV_CMD_ESTIMATOR_SENSOR_ENABLE).*/
 uint8_t active[9]; /*<  Per-source instance bitmask of sensors the estimator is actively fusing.*/
} mavlink_estimator_sensor_fusion_status_t;

#define MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_LEN 54
#define MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_MIN_LEN 54
#define MAVLINK_MSG_ID_514_LEN 54
#define MAVLINK_MSG_ID_514_MIN_LEN 54

#define MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_CRC 197
#define MAVLINK_MSG_ID_514_CRC 197

#define MAVLINK_MSG_ESTIMATOR_SENSOR_FUSION_STATUS_FIELD_TEST_RATIO_LEN 9
#define MAVLINK_MSG_ESTIMATOR_SENSOR_FUSION_STATUS_FIELD_INTENDED_LEN 9
#define MAVLINK_MSG_ESTIMATOR_SENSOR_FUSION_STATUS_FIELD_ACTIVE_LEN 9

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ESTIMATOR_SENSOR_FUSION_STATUS { \
    514, \
    "ESTIMATOR_SENSOR_FUSION_STATUS", \
    3, \
    {  { "intended", NULL, MAVLINK_TYPE_UINT8_T, 9, 36, offsetof(mavlink_estimator_sensor_fusion_status_t, intended) }, \
         { "active", NULL, MAVLINK_TYPE_UINT8_T, 9, 45, offsetof(mavlink_estimator_sensor_fusion_status_t, active) }, \
         { "test_ratio", NULL, MAVLINK_TYPE_FLOAT, 9, 0, offsetof(mavlink_estimator_sensor_fusion_status_t, test_ratio) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ESTIMATOR_SENSOR_FUSION_STATUS { \
    "ESTIMATOR_SENSOR_FUSION_STATUS", \
    3, \
    {  { "intended", NULL, MAVLINK_TYPE_UINT8_T, 9, 36, offsetof(mavlink_estimator_sensor_fusion_status_t, intended) }, \
         { "active", NULL, MAVLINK_TYPE_UINT8_T, 9, 45, offsetof(mavlink_estimator_sensor_fusion_status_t, active) }, \
         { "test_ratio", NULL, MAVLINK_TYPE_FLOAT, 9, 0, offsetof(mavlink_estimator_sensor_fusion_status_t, test_ratio) }, \
         } \
}
#endif

/**
 * @brief Pack a estimator_sensor_fusion_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param intended  Per-source instance bitmask of sensors the estimator intends to fuse (reflects CTRL params with runtime overrides via MAV_CMD_ESTIMATOR_SENSOR_ENABLE).
 * @param active  Per-source instance bitmask of sensors the estimator is actively fusing.
 * @param test_ratio  Per-source normalized innovation test ratio. NaN if not available.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_estimator_sensor_fusion_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const uint8_t *intended, const uint8_t *active, const float *test_ratio)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_LEN];

    _mav_put_float_array(buf, 0, test_ratio, 9);
    _mav_put_uint8_t_array(buf, 36, intended, 9);
    _mav_put_uint8_t_array(buf, 45, active, 9);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_LEN);
#else
    mavlink_estimator_sensor_fusion_status_t packet;

    mav_array_memcpy(packet.test_ratio, test_ratio, sizeof(float)*9);
    mav_array_memcpy(packet.intended, intended, sizeof(uint8_t)*9);
    mav_array_memcpy(packet.active, active, sizeof(uint8_t)*9);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_MIN_LEN, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_LEN, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_CRC);
}

/**
 * @brief Pack a estimator_sensor_fusion_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param intended  Per-source instance bitmask of sensors the estimator intends to fuse (reflects CTRL params with runtime overrides via MAV_CMD_ESTIMATOR_SENSOR_ENABLE).
 * @param active  Per-source instance bitmask of sensors the estimator is actively fusing.
 * @param test_ratio  Per-source normalized innovation test ratio. NaN if not available.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_estimator_sensor_fusion_status_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               const uint8_t *intended, const uint8_t *active, const float *test_ratio)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_LEN];

    _mav_put_float_array(buf, 0, test_ratio, 9);
    _mav_put_uint8_t_array(buf, 36, intended, 9);
    _mav_put_uint8_t_array(buf, 45, active, 9);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_LEN);
#else
    mavlink_estimator_sensor_fusion_status_t packet;

    mav_array_memcpy(packet.test_ratio, test_ratio, sizeof(float)*9);
    mav_array_memcpy(packet.intended, intended, sizeof(uint8_t)*9);
    mav_array_memcpy(packet.active, active, sizeof(uint8_t)*9);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_MIN_LEN, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_LEN, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_MIN_LEN, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_LEN);
#endif
}

/**
 * @brief Pack a estimator_sensor_fusion_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param intended  Per-source instance bitmask of sensors the estimator intends to fuse (reflects CTRL params with runtime overrides via MAV_CMD_ESTIMATOR_SENSOR_ENABLE).
 * @param active  Per-source instance bitmask of sensors the estimator is actively fusing.
 * @param test_ratio  Per-source normalized innovation test ratio. NaN if not available.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_estimator_sensor_fusion_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const uint8_t *intended,const uint8_t *active,const float *test_ratio)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_LEN];

    _mav_put_float_array(buf, 0, test_ratio, 9);
    _mav_put_uint8_t_array(buf, 36, intended, 9);
    _mav_put_uint8_t_array(buf, 45, active, 9);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_LEN);
#else
    mavlink_estimator_sensor_fusion_status_t packet;

    mav_array_memcpy(packet.test_ratio, test_ratio, sizeof(float)*9);
    mav_array_memcpy(packet.intended, intended, sizeof(uint8_t)*9);
    mav_array_memcpy(packet.active, active, sizeof(uint8_t)*9);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_MIN_LEN, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_LEN, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_CRC);
}

/**
 * @brief Encode a estimator_sensor_fusion_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param estimator_sensor_fusion_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_estimator_sensor_fusion_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_estimator_sensor_fusion_status_t* estimator_sensor_fusion_status)
{
    return mavlink_msg_estimator_sensor_fusion_status_pack(system_id, component_id, msg, estimator_sensor_fusion_status->intended, estimator_sensor_fusion_status->active, estimator_sensor_fusion_status->test_ratio);
}

/**
 * @brief Encode a estimator_sensor_fusion_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param estimator_sensor_fusion_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_estimator_sensor_fusion_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_estimator_sensor_fusion_status_t* estimator_sensor_fusion_status)
{
    return mavlink_msg_estimator_sensor_fusion_status_pack_chan(system_id, component_id, chan, msg, estimator_sensor_fusion_status->intended, estimator_sensor_fusion_status->active, estimator_sensor_fusion_status->test_ratio);
}

/**
 * @brief Encode a estimator_sensor_fusion_status struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param estimator_sensor_fusion_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_estimator_sensor_fusion_status_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_estimator_sensor_fusion_status_t* estimator_sensor_fusion_status)
{
    return mavlink_msg_estimator_sensor_fusion_status_pack_status(system_id, component_id, _status, msg,  estimator_sensor_fusion_status->intended, estimator_sensor_fusion_status->active, estimator_sensor_fusion_status->test_ratio);
}

/**
 * @brief Send a estimator_sensor_fusion_status message
 * @param chan MAVLink channel to send the message
 *
 * @param intended  Per-source instance bitmask of sensors the estimator intends to fuse (reflects CTRL params with runtime overrides via MAV_CMD_ESTIMATOR_SENSOR_ENABLE).
 * @param active  Per-source instance bitmask of sensors the estimator is actively fusing.
 * @param test_ratio  Per-source normalized innovation test ratio. NaN if not available.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_estimator_sensor_fusion_status_send(mavlink_channel_t chan, const uint8_t *intended, const uint8_t *active, const float *test_ratio)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_LEN];

    _mav_put_float_array(buf, 0, test_ratio, 9);
    _mav_put_uint8_t_array(buf, 36, intended, 9);
    _mav_put_uint8_t_array(buf, 45, active, 9);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS, buf, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_MIN_LEN, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_LEN, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_CRC);
#else
    mavlink_estimator_sensor_fusion_status_t packet;

    mav_array_memcpy(packet.test_ratio, test_ratio, sizeof(float)*9);
    mav_array_memcpy(packet.intended, intended, sizeof(uint8_t)*9);
    mav_array_memcpy(packet.active, active, sizeof(uint8_t)*9);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS, (const char *)&packet, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_MIN_LEN, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_LEN, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_CRC);
#endif
}

/**
 * @brief Send a estimator_sensor_fusion_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_estimator_sensor_fusion_status_send_struct(mavlink_channel_t chan, const mavlink_estimator_sensor_fusion_status_t* estimator_sensor_fusion_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_estimator_sensor_fusion_status_send(chan, estimator_sensor_fusion_status->intended, estimator_sensor_fusion_status->active, estimator_sensor_fusion_status->test_ratio);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS, (const char *)estimator_sensor_fusion_status, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_MIN_LEN, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_LEN, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_estimator_sensor_fusion_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const uint8_t *intended, const uint8_t *active, const float *test_ratio)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;

    _mav_put_float_array(buf, 0, test_ratio, 9);
    _mav_put_uint8_t_array(buf, 36, intended, 9);
    _mav_put_uint8_t_array(buf, 45, active, 9);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS, buf, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_MIN_LEN, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_LEN, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_CRC);
#else
    mavlink_estimator_sensor_fusion_status_t *packet = (mavlink_estimator_sensor_fusion_status_t *)msgbuf;

    mav_array_memcpy(packet->test_ratio, test_ratio, sizeof(float)*9);
    mav_array_memcpy(packet->intended, intended, sizeof(uint8_t)*9);
    mav_array_memcpy(packet->active, active, sizeof(uint8_t)*9);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS, (const char *)packet, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_MIN_LEN, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_LEN, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE ESTIMATOR_SENSOR_FUSION_STATUS UNPACKING


/**
 * @brief Get field intended from estimator_sensor_fusion_status message
 *
 * @return  Per-source instance bitmask of sensors the estimator intends to fuse (reflects CTRL params with runtime overrides via MAV_CMD_ESTIMATOR_SENSOR_ENABLE).
 */
static inline uint16_t mavlink_msg_estimator_sensor_fusion_status_get_intended(const mavlink_message_t* msg, uint8_t *intended)
{
    return _MAV_RETURN_uint8_t_array(msg, intended, 9,  36);
}

/**
 * @brief Get field active from estimator_sensor_fusion_status message
 *
 * @return  Per-source instance bitmask of sensors the estimator is actively fusing.
 */
static inline uint16_t mavlink_msg_estimator_sensor_fusion_status_get_active(const mavlink_message_t* msg, uint8_t *active)
{
    return _MAV_RETURN_uint8_t_array(msg, active, 9,  45);
}

/**
 * @brief Get field test_ratio from estimator_sensor_fusion_status message
 *
 * @return  Per-source normalized innovation test ratio. NaN if not available.
 */
static inline uint16_t mavlink_msg_estimator_sensor_fusion_status_get_test_ratio(const mavlink_message_t* msg, float *test_ratio)
{
    return _MAV_RETURN_float_array(msg, test_ratio, 9,  0);
}

/**
 * @brief Decode a estimator_sensor_fusion_status message into a struct
 *
 * @param msg The message to decode
 * @param estimator_sensor_fusion_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_estimator_sensor_fusion_status_decode(const mavlink_message_t* msg, mavlink_estimator_sensor_fusion_status_t* estimator_sensor_fusion_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_estimator_sensor_fusion_status_get_test_ratio(msg, estimator_sensor_fusion_status->test_ratio);
    mavlink_msg_estimator_sensor_fusion_status_get_intended(msg, estimator_sensor_fusion_status->intended);
    mavlink_msg_estimator_sensor_fusion_status_get_active(msg, estimator_sensor_fusion_status->active);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_LEN? msg->len : MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_LEN;
        memset(estimator_sensor_fusion_status, 0, MAVLINK_MSG_ID_ESTIMATOR_SENSOR_FUSION_STATUS_LEN);
    memcpy(estimator_sensor_fusion_status, _MAV_PAYLOAD(msg), len);
#endif
}
