#pragma once
// MESSAGE SET_MODE PACKING

#include <stdint.h>

#define MAVLINK_MSG_ID_SET_MODE 11


typedef struct __mavlink_set_mode_t {
 uint32_t custom_mode; /*<  The new autopilot-specific mode. This field can be ignored by an autopilot.*/
 uint8_t target_system; /*<  The system setting the mode*/
 uint8_t base_mode; /*<  The new base mode.*/
} mavlink_set_mode_t;

#define MAVLINK_MSG_ID_SET_MODE_LEN 6
#define MAVLINK_MSG_ID_SET_MODE_MIN_LEN 6
#define MAVLINK_MSG_ID_11_LEN 6
#define MAVLINK_MSG_ID_11_MIN_LEN 6

#define MAVLINK_MSG_ID_SET_MODE_CRC 89
#define MAVLINK_MSG_ID_11_CRC 89



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SET_MODE { \
    11, \
    "SET_MODE", \
    3, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_set_mode_t, target_system) }, \
         { "base_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_set_mode_t, base_mode) }, \
         { "custom_mode", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_set_mode_t, custom_mode) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SET_MODE { \
    "SET_MODE", \
    3, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_set_mode_t, target_system) }, \
         { "base_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_set_mode_t, base_mode) }, \
         { "custom_mode", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_set_mode_t, custom_mode) }, \
         } \
}
#endif

/**
 * @brief Pack a set_mode message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  The system setting the mode
 * @param base_mode  The new base mode.
 * @param custom_mode  The new autopilot-specific mode. This field can be ignored by an autopilot.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_mode_pack(uint32_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t target_system, uint8_t base_mode, uint32_t custom_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_MODE_LEN];
    _mav_put_uint32_t(buf, 0, custom_mode);
    _mav_put_uint8_t(buf, 4, mavlink_msg_target_field(target_system));
    _mav_put_uint8_t(buf, 5, base_mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SET_MODE_LEN);
#else
    mavlink_set_mode_t packet;
    packet.custom_mode = custom_mode;
    packet.target_system = mavlink_msg_target_field(target_system);
    packet.base_mode = base_mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SET_MODE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SET_MODE;
    return mavlink_finalize_message_target(msg, system_id, component_id, MAVLINK_MSG_ID_SET_MODE_MIN_LEN, MAVLINK_MSG_ID_SET_MODE_LEN, MAVLINK_MSG_ID_SET_MODE_CRC, target_system);
}

/**
 * @brief Pack a set_mode message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  The system setting the mode
 * @param base_mode  The new base mode.
 * @param custom_mode  The new autopilot-specific mode. This field can be ignored by an autopilot.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_mode_pack_status(uint32_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint32_t target_system, uint8_t base_mode, uint32_t custom_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_MODE_LEN];
    _mav_put_uint32_t(buf, 0, custom_mode);
    _mav_put_uint8_t(buf, 4, mavlink_msg_target_field(target_system));
    _mav_put_uint8_t(buf, 5, base_mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SET_MODE_LEN);
#else
    mavlink_set_mode_t packet;
    packet.custom_mode = custom_mode;
    packet.target_system = mavlink_msg_target_field(target_system);
    packet.base_mode = base_mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SET_MODE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SET_MODE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer_target(msg, system_id, component_id, _status, MAVLINK_MSG_ID_SET_MODE_MIN_LEN, MAVLINK_MSG_ID_SET_MODE_LEN, MAVLINK_MSG_ID_SET_MODE_CRC, target_system);
#else
    return mavlink_finalize_message_buffer_target(msg, system_id, component_id, _status, MAVLINK_MSG_ID_SET_MODE_MIN_LEN, MAVLINK_MSG_ID_SET_MODE_LEN, 0, target_system);
#endif
}

/**
 * @brief Pack a set_mode message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  The system setting the mode
 * @param base_mode  The new base mode.
 * @param custom_mode  The new autopilot-specific mode. This field can be ignored by an autopilot.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_mode_pack_chan(uint32_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t target_system,uint8_t base_mode,uint32_t custom_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_MODE_LEN];
    _mav_put_uint32_t(buf, 0, custom_mode);
    _mav_put_uint8_t(buf, 4, mavlink_msg_target_field(target_system));
    _mav_put_uint8_t(buf, 5, base_mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SET_MODE_LEN);
#else
    mavlink_set_mode_t packet;
    packet.custom_mode = custom_mode;
    packet.target_system = mavlink_msg_target_field(target_system);
    packet.base_mode = base_mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SET_MODE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SET_MODE;
    return mavlink_finalize_message_chan_target(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SET_MODE_MIN_LEN, MAVLINK_MSG_ID_SET_MODE_LEN, MAVLINK_MSG_ID_SET_MODE_CRC, target_system);
}

/**
 * @brief Encode a set_mode struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param set_mode C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_mode_encode(uint32_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_set_mode_t* set_mode)
{
    return mavlink_msg_set_mode_pack(system_id, component_id, msg, set_mode->target_system, set_mode->base_mode, set_mode->custom_mode);
}

/**
 * @brief Encode a set_mode struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param set_mode C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_mode_encode_chan(uint32_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_set_mode_t* set_mode)
{
    return mavlink_msg_set_mode_pack_chan(system_id, component_id, chan, msg, set_mode->target_system, set_mode->base_mode, set_mode->custom_mode);
}

/**
 * @brief Encode a set_mode struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param set_mode C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_mode_encode_status(uint32_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_set_mode_t* set_mode)
{
    return mavlink_msg_set_mode_pack_status(system_id, component_id, _status, msg,  set_mode->target_system, set_mode->base_mode, set_mode->custom_mode);
}

/**
 * @brief Send a set_mode message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system  The system setting the mode
 * @param base_mode  The new base mode.
 * @param custom_mode  The new autopilot-specific mode. This field can be ignored by an autopilot.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_set_mode_send(mavlink_channel_t chan, uint32_t target_system, uint8_t base_mode, uint32_t custom_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_MODE_LEN];
    _mav_put_uint32_t(buf, 0, custom_mode);
    _mav_put_uint8_t(buf, 4, mavlink_msg_target_field(target_system));
    _mav_put_uint8_t(buf, 5, base_mode);

    _mav_finalize_message_chan_send_target(chan, MAVLINK_MSG_ID_SET_MODE, buf, MAVLINK_MSG_ID_SET_MODE_MIN_LEN, MAVLINK_MSG_ID_SET_MODE_LEN, MAVLINK_MSG_ID_SET_MODE_CRC, target_system);
#else
    mavlink_set_mode_t packet;
    packet.custom_mode = custom_mode;
    packet.target_system = mavlink_msg_target_field(target_system);
    packet.base_mode = base_mode;

    _mav_finalize_message_chan_send_target(chan, MAVLINK_MSG_ID_SET_MODE, (const char *)&packet, MAVLINK_MSG_ID_SET_MODE_MIN_LEN, MAVLINK_MSG_ID_SET_MODE_LEN, MAVLINK_MSG_ID_SET_MODE_CRC, target_system);
#endif
}

/**
 * @brief Send a set_mode message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_set_mode_send_struct(mavlink_channel_t chan, const mavlink_set_mode_t* set_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_set_mode_send(chan, set_mode->target_system, set_mode->base_mode, set_mode->custom_mode);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_MODE, (const char *)set_mode, MAVLINK_MSG_ID_SET_MODE_MIN_LEN, MAVLINK_MSG_ID_SET_MODE_LEN, MAVLINK_MSG_ID_SET_MODE_CRC);
#endif
}

#if MAVLINK_MSG_ID_SET_MODE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_set_mode_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t target_system, uint8_t base_mode, uint32_t custom_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, custom_mode);
    _mav_put_uint8_t(buf, 4, mavlink_msg_target_field(target_system));
    _mav_put_uint8_t(buf, 5, base_mode);

    _mav_finalize_message_chan_send_target(chan, MAVLINK_MSG_ID_SET_MODE, buf, MAVLINK_MSG_ID_SET_MODE_MIN_LEN, MAVLINK_MSG_ID_SET_MODE_LEN, MAVLINK_MSG_ID_SET_MODE_CRC, target_system);
#else
    mavlink_set_mode_t *packet = (mavlink_set_mode_t *)msgbuf;
    packet->custom_mode = custom_mode;
    packet->target_system = mavlink_msg_target_field(target_system);
    packet->base_mode = base_mode;

    _mav_finalize_message_chan_send_target(chan, MAVLINK_MSG_ID_SET_MODE, (const char *)packet, MAVLINK_MSG_ID_SET_MODE_MIN_LEN, MAVLINK_MSG_ID_SET_MODE_LEN, MAVLINK_MSG_ID_SET_MODE_CRC, target_system);
#endif
}
#endif

#endif

// MESSAGE SET_MODE UNPACKING


/**
 * @brief Get field base_mode from set_mode message
 *
 * @return  The new base mode.
 */
static inline uint8_t mavlink_msg_set_mode_get_base_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field custom_mode from set_mode message
 *
 * @return  The new autopilot-specific mode. This field can be ignored by an autopilot.
 */
static inline uint32_t mavlink_msg_set_mode_get_custom_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Decode a set_mode message into a struct
 *
 * @param msg The message to decode
 * @param set_mode C-struct to decode the message contents into
 */
static inline void mavlink_msg_set_mode_decode(const mavlink_message_t* msg, mavlink_set_mode_t* set_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    set_mode->custom_mode = mavlink_msg_set_mode_get_custom_mode(msg);
    set_mode->target_system = _MAV_RETURN_uint8_t(msg, 4);
    set_mode->base_mode = mavlink_msg_set_mode_get_base_mode(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SET_MODE_LEN? msg->len : MAVLINK_MSG_ID_SET_MODE_LEN;
        memset(set_mode, 0, MAVLINK_MSG_ID_SET_MODE_LEN);
    memcpy(set_mode, _MAV_PAYLOAD(msg), len);
#endif
    if (msg->incompat_flags & MAVLINK_IFLAG_TARGET32) {
        // This uint8_t field cannot retain a wide target. The sentinel is NOT reserved.
        // For routing use mavlink_msg_get_target_sysid(msg, mavlink_get_msg_entry(msg->msgid)).
        // To relay after edits, pass that full target to _pack*(); _encode*() loses it.
        set_mode->target_system = mavlink_msg_target_field(msg->target_sysid);
    }

}
