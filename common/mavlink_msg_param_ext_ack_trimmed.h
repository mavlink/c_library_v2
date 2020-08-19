#pragma once
// MESSAGE PARAM_EXT_ACK_TRIMMED PACKING

#define MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED 327


typedef struct __mavlink_param_ext_ack_trimmed_t {
 uint8_t param_result; /*<  Result code.*/
 uint8_t param_type; /*<  Parameter type.*/
 char param_id[16]; /*<  Parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string*/
 char param_value[128]; /*<  Parameter value (new value if PARAM_ACK_ACCEPTED, current value otherwise, zeros get trimmed)*/
} mavlink_param_ext_ack_trimmed_t;

#define MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED_LEN 146
#define MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED_MIN_LEN 146
#define MAVLINK_MSG_ID_327_LEN 146
#define MAVLINK_MSG_ID_327_MIN_LEN 146

#define MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED_CRC 129
#define MAVLINK_MSG_ID_327_CRC 129

#define MAVLINK_MSG_PARAM_EXT_ACK_TRIMMED_FIELD_PARAM_ID_LEN 16
#define MAVLINK_MSG_PARAM_EXT_ACK_TRIMMED_FIELD_PARAM_VALUE_LEN 128

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PARAM_EXT_ACK_TRIMMED { \
    327, \
    "PARAM_EXT_ACK_TRIMMED", \
    4, \
    {  { "param_result", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_param_ext_ack_trimmed_t, param_result) }, \
         { "param_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_param_ext_ack_trimmed_t, param_type) }, \
         { "param_id", NULL, MAVLINK_TYPE_CHAR, 16, 2, offsetof(mavlink_param_ext_ack_trimmed_t, param_id) }, \
         { "param_value", NULL, MAVLINK_TYPE_CHAR, 128, 18, offsetof(mavlink_param_ext_ack_trimmed_t, param_value) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PARAM_EXT_ACK_TRIMMED { \
    "PARAM_EXT_ACK_TRIMMED", \
    4, \
    {  { "param_result", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_param_ext_ack_trimmed_t, param_result) }, \
         { "param_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_param_ext_ack_trimmed_t, param_type) }, \
         { "param_id", NULL, MAVLINK_TYPE_CHAR, 16, 2, offsetof(mavlink_param_ext_ack_trimmed_t, param_id) }, \
         { "param_value", NULL, MAVLINK_TYPE_CHAR, 128, 18, offsetof(mavlink_param_ext_ack_trimmed_t, param_value) }, \
         } \
}
#endif

/**
 * @brief Pack a param_ext_ack_trimmed message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param param_result  Result code.
 * @param param_type  Parameter type.
 * @param param_id  Parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string
 * @param param_value  Parameter value (new value if PARAM_ACK_ACCEPTED, current value otherwise, zeros get trimmed)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_param_ext_ack_trimmed_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t param_result, uint8_t param_type, const char *param_id, const char *param_value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED_LEN];
    _mav_put_uint8_t(buf, 0, param_result);
    _mav_put_uint8_t(buf, 1, param_type);
    _mav_put_char_array(buf, 2, param_id, 16);
    _mav_put_char_array(buf, 18, param_value, 128);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED_LEN);
#else
    mavlink_param_ext_ack_trimmed_t packet;
    packet.param_result = param_result;
    packet.param_type = param_type;
    mav_array_memcpy(packet.param_id, param_id, sizeof(char)*16);
    mav_array_memcpy(packet.param_value, param_value, sizeof(char)*128);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED_MIN_LEN, MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED_LEN, MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED_CRC);
}

/**
 * @brief Pack a param_ext_ack_trimmed message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param param_result  Result code.
 * @param param_type  Parameter type.
 * @param param_id  Parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string
 * @param param_value  Parameter value (new value if PARAM_ACK_ACCEPTED, current value otherwise, zeros get trimmed)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_param_ext_ack_trimmed_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t param_result,uint8_t param_type,const char *param_id,const char *param_value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED_LEN];
    _mav_put_uint8_t(buf, 0, param_result);
    _mav_put_uint8_t(buf, 1, param_type);
    _mav_put_char_array(buf, 2, param_id, 16);
    _mav_put_char_array(buf, 18, param_value, 128);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED_LEN);
#else
    mavlink_param_ext_ack_trimmed_t packet;
    packet.param_result = param_result;
    packet.param_type = param_type;
    mav_array_memcpy(packet.param_id, param_id, sizeof(char)*16);
    mav_array_memcpy(packet.param_value, param_value, sizeof(char)*128);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED_MIN_LEN, MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED_LEN, MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED_CRC);
}

/**
 * @brief Encode a param_ext_ack_trimmed struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param param_ext_ack_trimmed C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_param_ext_ack_trimmed_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_param_ext_ack_trimmed_t* param_ext_ack_trimmed)
{
    return mavlink_msg_param_ext_ack_trimmed_pack(system_id, component_id, msg, param_ext_ack_trimmed->param_result, param_ext_ack_trimmed->param_type, param_ext_ack_trimmed->param_id, param_ext_ack_trimmed->param_value);
}

/**
 * @brief Encode a param_ext_ack_trimmed struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param param_ext_ack_trimmed C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_param_ext_ack_trimmed_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_param_ext_ack_trimmed_t* param_ext_ack_trimmed)
{
    return mavlink_msg_param_ext_ack_trimmed_pack_chan(system_id, component_id, chan, msg, param_ext_ack_trimmed->param_result, param_ext_ack_trimmed->param_type, param_ext_ack_trimmed->param_id, param_ext_ack_trimmed->param_value);
}

/**
 * @brief Send a param_ext_ack_trimmed message
 * @param chan MAVLink channel to send the message
 *
 * @param param_result  Result code.
 * @param param_type  Parameter type.
 * @param param_id  Parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string
 * @param param_value  Parameter value (new value if PARAM_ACK_ACCEPTED, current value otherwise, zeros get trimmed)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_param_ext_ack_trimmed_send(mavlink_channel_t chan, uint8_t param_result, uint8_t param_type, const char *param_id, const char *param_value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED_LEN];
    _mav_put_uint8_t(buf, 0, param_result);
    _mav_put_uint8_t(buf, 1, param_type);
    _mav_put_char_array(buf, 2, param_id, 16);
    _mav_put_char_array(buf, 18, param_value, 128);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED, buf, MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED_MIN_LEN, MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED_LEN, MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED_CRC);
#else
    mavlink_param_ext_ack_trimmed_t packet;
    packet.param_result = param_result;
    packet.param_type = param_type;
    mav_array_memcpy(packet.param_id, param_id, sizeof(char)*16);
    mav_array_memcpy(packet.param_value, param_value, sizeof(char)*128);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED, (const char *)&packet, MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED_MIN_LEN, MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED_LEN, MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED_CRC);
#endif
}

/**
 * @brief Send a param_ext_ack_trimmed message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_param_ext_ack_trimmed_send_struct(mavlink_channel_t chan, const mavlink_param_ext_ack_trimmed_t* param_ext_ack_trimmed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_param_ext_ack_trimmed_send(chan, param_ext_ack_trimmed->param_result, param_ext_ack_trimmed->param_type, param_ext_ack_trimmed->param_id, param_ext_ack_trimmed->param_value);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED, (const char *)param_ext_ack_trimmed, MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED_MIN_LEN, MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED_LEN, MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED_CRC);
#endif
}

#if MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_param_ext_ack_trimmed_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t param_result, uint8_t param_type, const char *param_id, const char *param_value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, param_result);
    _mav_put_uint8_t(buf, 1, param_type);
    _mav_put_char_array(buf, 2, param_id, 16);
    _mav_put_char_array(buf, 18, param_value, 128);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED, buf, MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED_MIN_LEN, MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED_LEN, MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED_CRC);
#else
    mavlink_param_ext_ack_trimmed_t *packet = (mavlink_param_ext_ack_trimmed_t *)msgbuf;
    packet->param_result = param_result;
    packet->param_type = param_type;
    mav_array_memcpy(packet->param_id, param_id, sizeof(char)*16);
    mav_array_memcpy(packet->param_value, param_value, sizeof(char)*128);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED, (const char *)packet, MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED_MIN_LEN, MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED_LEN, MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED_CRC);
#endif
}
#endif

#endif

// MESSAGE PARAM_EXT_ACK_TRIMMED UNPACKING


/**
 * @brief Get field param_result from param_ext_ack_trimmed message
 *
 * @return  Result code.
 */
static inline uint8_t mavlink_msg_param_ext_ack_trimmed_get_param_result(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field param_type from param_ext_ack_trimmed message
 *
 * @return  Parameter type.
 */
static inline uint8_t mavlink_msg_param_ext_ack_trimmed_get_param_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field param_id from param_ext_ack_trimmed message
 *
 * @return  Parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string
 */
static inline uint16_t mavlink_msg_param_ext_ack_trimmed_get_param_id(const mavlink_message_t* msg, char *param_id)
{
    return _MAV_RETURN_char_array(msg, param_id, 16,  2);
}

/**
 * @brief Get field param_value from param_ext_ack_trimmed message
 *
 * @return  Parameter value (new value if PARAM_ACK_ACCEPTED, current value otherwise, zeros get trimmed)
 */
static inline uint16_t mavlink_msg_param_ext_ack_trimmed_get_param_value(const mavlink_message_t* msg, char *param_value)
{
    return _MAV_RETURN_char_array(msg, param_value, 128,  18);
}

/**
 * @brief Decode a param_ext_ack_trimmed message into a struct
 *
 * @param msg The message to decode
 * @param param_ext_ack_trimmed C-struct to decode the message contents into
 */
static inline void mavlink_msg_param_ext_ack_trimmed_decode(const mavlink_message_t* msg, mavlink_param_ext_ack_trimmed_t* param_ext_ack_trimmed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    param_ext_ack_trimmed->param_result = mavlink_msg_param_ext_ack_trimmed_get_param_result(msg);
    param_ext_ack_trimmed->param_type = mavlink_msg_param_ext_ack_trimmed_get_param_type(msg);
    mavlink_msg_param_ext_ack_trimmed_get_param_id(msg, param_ext_ack_trimmed->param_id);
    mavlink_msg_param_ext_ack_trimmed_get_param_value(msg, param_ext_ack_trimmed->param_value);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED_LEN? msg->len : MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED_LEN;
        memset(param_ext_ack_trimmed, 0, MAVLINK_MSG_ID_PARAM_EXT_ACK_TRIMMED_LEN);
    memcpy(param_ext_ack_trimmed, _MAV_PAYLOAD(msg), len);
#endif
}
