#pragma once
// MESSAGE RC_CHANNELS_OVERRIDE_V2 PACKING

#define MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2 421


typedef struct __mavlink_rc_channels_override_v2_t {
 uint32_t active_mask; /*<  Bitmap of included channels (bit 0 = CH1). 1: Valid/Override, 0: Ignore.*/
 uint8_t target_system; /*<  System ID.*/
 uint8_t target_component; /*<  Component ID.*/
 int16_t channels[32]; /*<  
        RC channels in centered 13-bit format. Range: -4096 to 4096, Center: 0. 
        Conversion to PWM: (x * 5/32) + 1500. 
        Unused channels must be set to 0 to enable MAVLink 2 trailing-zero trimming.
      */
} mavlink_rc_channels_override_v2_t;

#define MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_LEN 70
#define MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_MIN_LEN 6
#define MAVLINK_MSG_ID_421_LEN 70
#define MAVLINK_MSG_ID_421_MIN_LEN 6

#define MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_CRC 149
#define MAVLINK_MSG_ID_421_CRC 149

#define MAVLINK_MSG_RC_CHANNELS_OVERRIDE_V2_FIELD_CHANNELS_LEN 32

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RC_CHANNELS_OVERRIDE_V2 { \
    421, \
    "RC_CHANNELS_OVERRIDE_V2", \
    4, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_rc_channels_override_v2_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_rc_channels_override_v2_t, target_component) }, \
         { "active_mask", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_rc_channels_override_v2_t, active_mask) }, \
         { "channels", NULL, MAVLINK_TYPE_INT16_T, 32, 6, offsetof(mavlink_rc_channels_override_v2_t, channels) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_RC_CHANNELS_OVERRIDE_V2 { \
    "RC_CHANNELS_OVERRIDE_V2", \
    4, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_rc_channels_override_v2_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_rc_channels_override_v2_t, target_component) }, \
         { "active_mask", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_rc_channels_override_v2_t, active_mask) }, \
         { "channels", NULL, MAVLINK_TYPE_INT16_T, 32, 6, offsetof(mavlink_rc_channels_override_v2_t, channels) }, \
         } \
}
#endif

/**
 * @brief Pack a rc_channels_override_v2 message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID.
 * @param target_component  Component ID.
 * @param active_mask  Bitmap of included channels (bit 0 = CH1). 1: Valid/Override, 0: Ignore.
 * @param channels  
        RC channels in centered 13-bit format. Range: -4096 to 4096, Center: 0. 
        Conversion to PWM: (x * 5/32) + 1500. 
        Unused channels must be set to 0 to enable MAVLink 2 trailing-zero trimming.
      
 * @return length of the message in bytes (excluding serial stream start sign)
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_rc_channels_override_v2_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint32_t active_mask, const int16_t *channels)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_LEN];
    _mav_put_uint32_t(buf, 0, active_mask);
    _mav_put_uint8_t(buf, 4, target_system);
    _mav_put_uint8_t(buf, 5, target_component);
    _mav_put_int16_t_array(buf, 6, channels, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_LEN);
#else
    mavlink_rc_channels_override_v2_t packet;
    packet.active_mask = active_mask;
    packet.target_system = target_system;
    packet.target_component = target_component;
    mav_array_memcpy(packet.channels, channels, sizeof(int16_t)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_MIN_LEN, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_LEN, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_CRC);
}

/**
 * @brief Pack a rc_channels_override_v2 message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID.
 * @param target_component  Component ID.
 * @param active_mask  Bitmap of included channels (bit 0 = CH1). 1: Valid/Override, 0: Ignore.
 * @param channels  
        RC channels in centered 13-bit format. Range: -4096 to 4096, Center: 0. 
        Conversion to PWM: (x * 5/32) + 1500. 
        Unused channels must be set to 0 to enable MAVLink 2 trailing-zero trimming.
      
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_rc_channels_override_v2_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint32_t active_mask, const int16_t *channels)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_LEN];
    _mav_put_uint32_t(buf, 0, active_mask);
    _mav_put_uint8_t(buf, 4, target_system);
    _mav_put_uint8_t(buf, 5, target_component);
    _mav_put_int16_t_array(buf, 6, channels, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_LEN);
#else
    mavlink_rc_channels_override_v2_t packet;
    packet.active_mask = active_mask;
    packet.target_system = target_system;
    packet.target_component = target_component;
    mav_array_memcpy(packet.channels, channels, sizeof(int16_t)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_MIN_LEN, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_LEN, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_MIN_LEN, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_LEN);
#endif
}

/**
 * @brief Pack a rc_channels_override_v2 message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System ID.
 * @param target_component  Component ID.
 * @param active_mask  Bitmap of included channels (bit 0 = CH1). 1: Valid/Override, 0: Ignore.
 * @param channels  
        RC channels in centered 13-bit format. Range: -4096 to 4096, Center: 0. 
        Conversion to PWM: (x * 5/32) + 1500. 
        Unused channels must be set to 0 to enable MAVLink 2 trailing-zero trimming.
      
 * @return length of the message in bytes (excluding serial stream start sign)
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_rc_channels_override_v2_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint32_t active_mask,const int16_t *channels)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_LEN];
    _mav_put_uint32_t(buf, 0, active_mask);
    _mav_put_uint8_t(buf, 4, target_system);
    _mav_put_uint8_t(buf, 5, target_component);
    _mav_put_int16_t_array(buf, 6, channels, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_LEN);
#else
    mavlink_rc_channels_override_v2_t packet;
    packet.active_mask = active_mask;
    packet.target_system = target_system;
    packet.target_component = target_component;
    mav_array_memcpy(packet.channels, channels, sizeof(int16_t)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_MIN_LEN, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_LEN, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_CRC);
}

/**
 * @brief Encode a rc_channels_override_v2 struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param rc_channels_override_v2 C-struct to read the message contents from
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_rc_channels_override_v2_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_rc_channels_override_v2_t* rc_channels_override_v2)
{
    return mavlink_msg_rc_channels_override_v2_pack(system_id, component_id, msg, rc_channels_override_v2->target_system, rc_channels_override_v2->target_component, rc_channels_override_v2->active_mask, rc_channels_override_v2->channels);
}

/**
 * @brief Encode a rc_channels_override_v2 struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param rc_channels_override_v2 C-struct to read the message contents from
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_rc_channels_override_v2_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_rc_channels_override_v2_t* rc_channels_override_v2)
{
    return mavlink_msg_rc_channels_override_v2_pack_chan(system_id, component_id, chan, msg, rc_channels_override_v2->target_system, rc_channels_override_v2->target_component, rc_channels_override_v2->active_mask, rc_channels_override_v2->channels);
}

/**
 * @brief Encode a rc_channels_override_v2 struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param rc_channels_override_v2 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_rc_channels_override_v2_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_rc_channels_override_v2_t* rc_channels_override_v2)
{
    return mavlink_msg_rc_channels_override_v2_pack_status(system_id, component_id, _status, msg,  rc_channels_override_v2->target_system, rc_channels_override_v2->target_component, rc_channels_override_v2->active_mask, rc_channels_override_v2->channels);
}

/**
 * @brief Send a rc_channels_override_v2 message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system  System ID.
 * @param target_component  Component ID.
 * @param active_mask  Bitmap of included channels (bit 0 = CH1). 1: Valid/Override, 0: Ignore.
 * @param channels  
        RC channels in centered 13-bit format. Range: -4096 to 4096, Center: 0. 
        Conversion to PWM: (x * 5/32) + 1500. 
        Unused channels must be set to 0 to enable MAVLink 2 trailing-zero trimming.
      
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

MAVLINK_WIP
static inline void mavlink_msg_rc_channels_override_v2_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint32_t active_mask, const int16_t *channels)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_LEN];
    _mav_put_uint32_t(buf, 0, active_mask);
    _mav_put_uint8_t(buf, 4, target_system);
    _mav_put_uint8_t(buf, 5, target_component);
    _mav_put_int16_t_array(buf, 6, channels, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2, buf, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_MIN_LEN, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_LEN, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_CRC);
#else
    mavlink_rc_channels_override_v2_t packet;
    packet.active_mask = active_mask;
    packet.target_system = target_system;
    packet.target_component = target_component;
    mav_array_memcpy(packet.channels, channels, sizeof(int16_t)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2, (const char *)&packet, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_MIN_LEN, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_LEN, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_CRC);
#endif
}

/**
 * @brief Send a rc_channels_override_v2 message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
MAVLINK_WIP
static inline void mavlink_msg_rc_channels_override_v2_send_struct(mavlink_channel_t chan, const mavlink_rc_channels_override_v2_t* rc_channels_override_v2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_rc_channels_override_v2_send(chan, rc_channels_override_v2->target_system, rc_channels_override_v2->target_component, rc_channels_override_v2->active_mask, rc_channels_override_v2->channels);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2, (const char *)rc_channels_override_v2, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_MIN_LEN, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_LEN, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_CRC);
#endif
}

#if MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
MAVLINK_WIP
static inline void mavlink_msg_rc_channels_override_v2_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint32_t active_mask, const int16_t *channels)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, active_mask);
    _mav_put_uint8_t(buf, 4, target_system);
    _mav_put_uint8_t(buf, 5, target_component);
    _mav_put_int16_t_array(buf, 6, channels, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2, buf, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_MIN_LEN, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_LEN, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_CRC);
#else
    mavlink_rc_channels_override_v2_t *packet = (mavlink_rc_channels_override_v2_t *)msgbuf;
    packet->active_mask = active_mask;
    packet->target_system = target_system;
    packet->target_component = target_component;
    mav_array_memcpy(packet->channels, channels, sizeof(int16_t)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2, (const char *)packet, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_MIN_LEN, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_LEN, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_CRC);
#endif
}
#endif

#endif

// MESSAGE RC_CHANNELS_OVERRIDE_V2 UNPACKING


/**
 * @brief Get field target_system from rc_channels_override_v2 message
 *
 * @return  System ID.
 */
MAVLINK_WIP
static inline uint8_t mavlink_msg_rc_channels_override_v2_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field target_component from rc_channels_override_v2 message
 *
 * @return  Component ID.
 */
MAVLINK_WIP
static inline uint8_t mavlink_msg_rc_channels_override_v2_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field active_mask from rc_channels_override_v2 message
 *
 * @return  Bitmap of included channels (bit 0 = CH1). 1: Valid/Override, 0: Ignore.
 */
MAVLINK_WIP
static inline uint32_t mavlink_msg_rc_channels_override_v2_get_active_mask(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field channels from rc_channels_override_v2 message
 *
 * @return  
        RC channels in centered 13-bit format. Range: -4096 to 4096, Center: 0. 
        Conversion to PWM: (x * 5/32) + 1500. 
        Unused channels must be set to 0 to enable MAVLink 2 trailing-zero trimming.
      
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_rc_channels_override_v2_get_channels(const mavlink_message_t* msg, int16_t *channels)
{
    return _MAV_RETURN_int16_t_array(msg, channels, 32,  6);
}

/**
 * @brief Decode a rc_channels_override_v2 message into a struct
 *
 * @param msg The message to decode
 * @param rc_channels_override_v2 C-struct to decode the message contents into
 */
MAVLINK_WIP
static inline void mavlink_msg_rc_channels_override_v2_decode(const mavlink_message_t* msg, mavlink_rc_channels_override_v2_t* rc_channels_override_v2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    rc_channels_override_v2->active_mask = mavlink_msg_rc_channels_override_v2_get_active_mask(msg);
    rc_channels_override_v2->target_system = mavlink_msg_rc_channels_override_v2_get_target_system(msg);
    rc_channels_override_v2->target_component = mavlink_msg_rc_channels_override_v2_get_target_component(msg);
    mavlink_msg_rc_channels_override_v2_get_channels(msg, rc_channels_override_v2->channels);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_LEN? msg->len : MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_LEN;
        memset(rc_channels_override_v2, 0, MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE_V2_LEN);
    memcpy(rc_channels_override_v2, _MAV_PAYLOAD(msg), len);
#endif
}
