#pragma once
// MESSAGE CONTROL_STATUS PACKING

#define MAVLINK_MSG_ID_CONTROL_STATUS 512


typedef struct __mavlink_control_status_t {
 uint8_t flags; /*<  Control status. For example, whether takeover of the `gcs_main` role is allowed, and whether this CONTROL_STATUS instance defines the default controlling GCS for the whole system.*/
 uint8_t gcs_main; /*<  System ID of GCS in control. 0: no GCS in control.*/
 uint8_t gcs_secondary[10]; /*<  System IDs from which the system can recieve state-changing commands/messages in multi-control mode. All values should be zero for single-ower mode.*/
} mavlink_control_status_t;

#define MAVLINK_MSG_ID_CONTROL_STATUS_LEN 12
#define MAVLINK_MSG_ID_CONTROL_STATUS_MIN_LEN 12
#define MAVLINK_MSG_ID_512_LEN 12
#define MAVLINK_MSG_ID_512_MIN_LEN 12

#define MAVLINK_MSG_ID_CONTROL_STATUS_CRC 21
#define MAVLINK_MSG_ID_512_CRC 21

#define MAVLINK_MSG_CONTROL_STATUS_FIELD_GCS_SECONDARY_LEN 10

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CONTROL_STATUS { \
    512, \
    "CONTROL_STATUS", \
    3, \
    {  { "flags", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_control_status_t, flags) }, \
         { "gcs_main", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_control_status_t, gcs_main) }, \
         { "gcs_secondary", NULL, MAVLINK_TYPE_UINT8_T, 10, 2, offsetof(mavlink_control_status_t, gcs_secondary) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CONTROL_STATUS { \
    "CONTROL_STATUS", \
    3, \
    {  { "flags", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_control_status_t, flags) }, \
         { "gcs_main", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_control_status_t, gcs_main) }, \
         { "gcs_secondary", NULL, MAVLINK_TYPE_UINT8_T, 10, 2, offsetof(mavlink_control_status_t, gcs_secondary) }, \
         } \
}
#endif

/**
 * @brief Pack a control_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param flags  Control status. For example, whether takeover of the `gcs_main` role is allowed, and whether this CONTROL_STATUS instance defines the default controlling GCS for the whole system.
 * @param gcs_main  System ID of GCS in control. 0: no GCS in control.
 * @param gcs_secondary  System IDs from which the system can recieve state-changing commands/messages in multi-control mode. All values should be zero for single-ower mode.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_control_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t flags, uint8_t gcs_main, const uint8_t *gcs_secondary)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CONTROL_STATUS_LEN];
    _mav_put_uint8_t(buf, 0, flags);
    _mav_put_uint8_t(buf, 1, gcs_main);
    _mav_put_uint8_t_array(buf, 2, gcs_secondary, 10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CONTROL_STATUS_LEN);
#else
    mavlink_control_status_t packet;
    packet.flags = flags;
    packet.gcs_main = gcs_main;
    mav_array_memcpy(packet.gcs_secondary, gcs_secondary, sizeof(uint8_t)*10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CONTROL_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CONTROL_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CONTROL_STATUS_MIN_LEN, MAVLINK_MSG_ID_CONTROL_STATUS_LEN, MAVLINK_MSG_ID_CONTROL_STATUS_CRC);
}

/**
 * @brief Pack a control_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param flags  Control status. For example, whether takeover of the `gcs_main` role is allowed, and whether this CONTROL_STATUS instance defines the default controlling GCS for the whole system.
 * @param gcs_main  System ID of GCS in control. 0: no GCS in control.
 * @param gcs_secondary  System IDs from which the system can recieve state-changing commands/messages in multi-control mode. All values should be zero for single-ower mode.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_control_status_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t flags, uint8_t gcs_main, const uint8_t *gcs_secondary)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CONTROL_STATUS_LEN];
    _mav_put_uint8_t(buf, 0, flags);
    _mav_put_uint8_t(buf, 1, gcs_main);
    _mav_put_uint8_t_array(buf, 2, gcs_secondary, 10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CONTROL_STATUS_LEN);
#else
    mavlink_control_status_t packet;
    packet.flags = flags;
    packet.gcs_main = gcs_main;
    mav_array_memcpy(packet.gcs_secondary, gcs_secondary, sizeof(uint8_t)*10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CONTROL_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CONTROL_STATUS;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_CONTROL_STATUS_MIN_LEN, MAVLINK_MSG_ID_CONTROL_STATUS_LEN, MAVLINK_MSG_ID_CONTROL_STATUS_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_CONTROL_STATUS_MIN_LEN, MAVLINK_MSG_ID_CONTROL_STATUS_LEN);
#endif
}

/**
 * @brief Pack a control_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param flags  Control status. For example, whether takeover of the `gcs_main` role is allowed, and whether this CONTROL_STATUS instance defines the default controlling GCS for the whole system.
 * @param gcs_main  System ID of GCS in control. 0: no GCS in control.
 * @param gcs_secondary  System IDs from which the system can recieve state-changing commands/messages in multi-control mode. All values should be zero for single-ower mode.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_control_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t flags,uint8_t gcs_main,const uint8_t *gcs_secondary)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CONTROL_STATUS_LEN];
    _mav_put_uint8_t(buf, 0, flags);
    _mav_put_uint8_t(buf, 1, gcs_main);
    _mav_put_uint8_t_array(buf, 2, gcs_secondary, 10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CONTROL_STATUS_LEN);
#else
    mavlink_control_status_t packet;
    packet.flags = flags;
    packet.gcs_main = gcs_main;
    mav_array_memcpy(packet.gcs_secondary, gcs_secondary, sizeof(uint8_t)*10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CONTROL_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CONTROL_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CONTROL_STATUS_MIN_LEN, MAVLINK_MSG_ID_CONTROL_STATUS_LEN, MAVLINK_MSG_ID_CONTROL_STATUS_CRC);
}

/**
 * @brief Encode a control_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param control_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_control_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_control_status_t* control_status)
{
    return mavlink_msg_control_status_pack(system_id, component_id, msg, control_status->flags, control_status->gcs_main, control_status->gcs_secondary);
}

/**
 * @brief Encode a control_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param control_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_control_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_control_status_t* control_status)
{
    return mavlink_msg_control_status_pack_chan(system_id, component_id, chan, msg, control_status->flags, control_status->gcs_main, control_status->gcs_secondary);
}

/**
 * @brief Encode a control_status struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param control_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_control_status_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_control_status_t* control_status)
{
    return mavlink_msg_control_status_pack_status(system_id, component_id, _status, msg,  control_status->flags, control_status->gcs_main, control_status->gcs_secondary);
}

/**
 * @brief Send a control_status message
 * @param chan MAVLink channel to send the message
 *
 * @param flags  Control status. For example, whether takeover of the `gcs_main` role is allowed, and whether this CONTROL_STATUS instance defines the default controlling GCS for the whole system.
 * @param gcs_main  System ID of GCS in control. 0: no GCS in control.
 * @param gcs_secondary  System IDs from which the system can recieve state-changing commands/messages in multi-control mode. All values should be zero for single-ower mode.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_control_status_send(mavlink_channel_t chan, uint8_t flags, uint8_t gcs_main, const uint8_t *gcs_secondary)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CONTROL_STATUS_LEN];
    _mav_put_uint8_t(buf, 0, flags);
    _mav_put_uint8_t(buf, 1, gcs_main);
    _mav_put_uint8_t_array(buf, 2, gcs_secondary, 10);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONTROL_STATUS, buf, MAVLINK_MSG_ID_CONTROL_STATUS_MIN_LEN, MAVLINK_MSG_ID_CONTROL_STATUS_LEN, MAVLINK_MSG_ID_CONTROL_STATUS_CRC);
#else
    mavlink_control_status_t packet;
    packet.flags = flags;
    packet.gcs_main = gcs_main;
    mav_array_memcpy(packet.gcs_secondary, gcs_secondary, sizeof(uint8_t)*10);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONTROL_STATUS, (const char *)&packet, MAVLINK_MSG_ID_CONTROL_STATUS_MIN_LEN, MAVLINK_MSG_ID_CONTROL_STATUS_LEN, MAVLINK_MSG_ID_CONTROL_STATUS_CRC);
#endif
}

/**
 * @brief Send a control_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_control_status_send_struct(mavlink_channel_t chan, const mavlink_control_status_t* control_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_control_status_send(chan, control_status->flags, control_status->gcs_main, control_status->gcs_secondary);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONTROL_STATUS, (const char *)control_status, MAVLINK_MSG_ID_CONTROL_STATUS_MIN_LEN, MAVLINK_MSG_ID_CONTROL_STATUS_LEN, MAVLINK_MSG_ID_CONTROL_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_CONTROL_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_control_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t flags, uint8_t gcs_main, const uint8_t *gcs_secondary)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, flags);
    _mav_put_uint8_t(buf, 1, gcs_main);
    _mav_put_uint8_t_array(buf, 2, gcs_secondary, 10);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONTROL_STATUS, buf, MAVLINK_MSG_ID_CONTROL_STATUS_MIN_LEN, MAVLINK_MSG_ID_CONTROL_STATUS_LEN, MAVLINK_MSG_ID_CONTROL_STATUS_CRC);
#else
    mavlink_control_status_t *packet = (mavlink_control_status_t *)msgbuf;
    packet->flags = flags;
    packet->gcs_main = gcs_main;
    mav_array_memcpy(packet->gcs_secondary, gcs_secondary, sizeof(uint8_t)*10);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONTROL_STATUS, (const char *)packet, MAVLINK_MSG_ID_CONTROL_STATUS_MIN_LEN, MAVLINK_MSG_ID_CONTROL_STATUS_LEN, MAVLINK_MSG_ID_CONTROL_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE CONTROL_STATUS UNPACKING


/**
 * @brief Get field flags from control_status message
 *
 * @return  Control status. For example, whether takeover of the `gcs_main` role is allowed, and whether this CONTROL_STATUS instance defines the default controlling GCS for the whole system.
 */
static inline uint8_t mavlink_msg_control_status_get_flags(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field gcs_main from control_status message
 *
 * @return  System ID of GCS in control. 0: no GCS in control.
 */
static inline uint8_t mavlink_msg_control_status_get_gcs_main(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field gcs_secondary from control_status message
 *
 * @return  System IDs from which the system can recieve state-changing commands/messages in multi-control mode. All values should be zero for single-ower mode.
 */
static inline uint16_t mavlink_msg_control_status_get_gcs_secondary(const mavlink_message_t* msg, uint8_t *gcs_secondary)
{
    return _MAV_RETURN_uint8_t_array(msg, gcs_secondary, 10,  2);
}

/**
 * @brief Decode a control_status message into a struct
 *
 * @param msg The message to decode
 * @param control_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_control_status_decode(const mavlink_message_t* msg, mavlink_control_status_t* control_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    control_status->flags = mavlink_msg_control_status_get_flags(msg);
    control_status->gcs_main = mavlink_msg_control_status_get_gcs_main(msg);
    mavlink_msg_control_status_get_gcs_secondary(msg, control_status->gcs_secondary);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CONTROL_STATUS_LEN? msg->len : MAVLINK_MSG_ID_CONTROL_STATUS_LEN;
        memset(control_status, 0, MAVLINK_MSG_ID_CONTROL_STATUS_LEN);
    memcpy(control_status, _MAV_PAYLOAD(msg), len);
#endif
}
