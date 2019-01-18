#pragma once
// MESSAGE PACKED_PARAM_VALUES PACKING

#define MAVLINK_MSG_ID_PACKED_PARAM_VALUES 500

MAVPACKED(
typedef struct __mavlink_packed_param_values_t {
 uint16_t parameter_group_id; /*<  ID of the parameter group these belong to. Set to 0 if none.*/
 uint8_t number; /*<  Number of packed parameters contained in this message*/
 uint8_t total_size; /*< [Bytes] Total size of the message*/
 uint8_t buffer[251]; /*<  Buffer of packed parameters*/
}) mavlink_packed_param_values_t;

#define MAVLINK_MSG_ID_PACKED_PARAM_VALUES_LEN 255
#define MAVLINK_MSG_ID_PACKED_PARAM_VALUES_MIN_LEN 255
#define MAVLINK_MSG_ID_500_LEN 255
#define MAVLINK_MSG_ID_500_MIN_LEN 255

#define MAVLINK_MSG_ID_PACKED_PARAM_VALUES_CRC 172
#define MAVLINK_MSG_ID_500_CRC 172

#define MAVLINK_MSG_PACKED_PARAM_VALUES_FIELD_BUFFER_LEN 251

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PACKED_PARAM_VALUES { \
    500, \
    "PACKED_PARAM_VALUES", \
    4, \
    {  { "number", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_packed_param_values_t, number) }, \
         { "total_size", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_packed_param_values_t, total_size) }, \
         { "parameter_group_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_packed_param_values_t, parameter_group_id) }, \
         { "buffer", NULL, MAVLINK_TYPE_UINT8_T, 251, 4, offsetof(mavlink_packed_param_values_t, buffer) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PACKED_PARAM_VALUES { \
    "PACKED_PARAM_VALUES", \
    4, \
    {  { "number", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_packed_param_values_t, number) }, \
         { "total_size", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_packed_param_values_t, total_size) }, \
         { "parameter_group_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_packed_param_values_t, parameter_group_id) }, \
         { "buffer", NULL, MAVLINK_TYPE_UINT8_T, 251, 4, offsetof(mavlink_packed_param_values_t, buffer) }, \
         } \
}
#endif

/**
 * @brief Pack a packed_param_values message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param number  Number of packed parameters contained in this message
 * @param total_size [Bytes] Total size of the message
 * @param parameter_group_id  ID of the parameter group these belong to. Set to 0 if none.
 * @param buffer  Buffer of packed parameters
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_packed_param_values_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t number, uint8_t total_size, uint16_t parameter_group_id, const uint8_t *buffer)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PACKED_PARAM_VALUES_LEN];
    _mav_put_uint16_t(buf, 0, parameter_group_id);
    _mav_put_uint8_t(buf, 2, number);
    _mav_put_uint8_t(buf, 3, total_size);
    _mav_put_uint8_t_array(buf, 4, buffer, 251);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PACKED_PARAM_VALUES_LEN);
#else
    mavlink_packed_param_values_t packet;
    packet.parameter_group_id = parameter_group_id;
    packet.number = number;
    packet.total_size = total_size;
    mav_array_memcpy(packet.buffer, buffer, sizeof(uint8_t)*251);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PACKED_PARAM_VALUES_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PACKED_PARAM_VALUES;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PACKED_PARAM_VALUES_MIN_LEN, MAVLINK_MSG_ID_PACKED_PARAM_VALUES_LEN, MAVLINK_MSG_ID_PACKED_PARAM_VALUES_CRC);
}

/**
 * @brief Pack a packed_param_values message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param number  Number of packed parameters contained in this message
 * @param total_size [Bytes] Total size of the message
 * @param parameter_group_id  ID of the parameter group these belong to. Set to 0 if none.
 * @param buffer  Buffer of packed parameters
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_packed_param_values_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t number,uint8_t total_size,uint16_t parameter_group_id,const uint8_t *buffer)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PACKED_PARAM_VALUES_LEN];
    _mav_put_uint16_t(buf, 0, parameter_group_id);
    _mav_put_uint8_t(buf, 2, number);
    _mav_put_uint8_t(buf, 3, total_size);
    _mav_put_uint8_t_array(buf, 4, buffer, 251);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PACKED_PARAM_VALUES_LEN);
#else
    mavlink_packed_param_values_t packet;
    packet.parameter_group_id = parameter_group_id;
    packet.number = number;
    packet.total_size = total_size;
    mav_array_memcpy(packet.buffer, buffer, sizeof(uint8_t)*251);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PACKED_PARAM_VALUES_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PACKED_PARAM_VALUES;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PACKED_PARAM_VALUES_MIN_LEN, MAVLINK_MSG_ID_PACKED_PARAM_VALUES_LEN, MAVLINK_MSG_ID_PACKED_PARAM_VALUES_CRC);
}

/**
 * @brief Encode a packed_param_values struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param packed_param_values C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_packed_param_values_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_packed_param_values_t* packed_param_values)
{
    return mavlink_msg_packed_param_values_pack(system_id, component_id, msg, packed_param_values->number, packed_param_values->total_size, packed_param_values->parameter_group_id, packed_param_values->buffer);
}

/**
 * @brief Encode a packed_param_values struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param packed_param_values C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_packed_param_values_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_packed_param_values_t* packed_param_values)
{
    return mavlink_msg_packed_param_values_pack_chan(system_id, component_id, chan, msg, packed_param_values->number, packed_param_values->total_size, packed_param_values->parameter_group_id, packed_param_values->buffer);
}

/**
 * @brief Send a packed_param_values message
 * @param chan MAVLink channel to send the message
 *
 * @param number  Number of packed parameters contained in this message
 * @param total_size [Bytes] Total size of the message
 * @param parameter_group_id  ID of the parameter group these belong to. Set to 0 if none.
 * @param buffer  Buffer of packed parameters
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_packed_param_values_send(mavlink_channel_t chan, uint8_t number, uint8_t total_size, uint16_t parameter_group_id, const uint8_t *buffer)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PACKED_PARAM_VALUES_LEN];
    _mav_put_uint16_t(buf, 0, parameter_group_id);
    _mav_put_uint8_t(buf, 2, number);
    _mav_put_uint8_t(buf, 3, total_size);
    _mav_put_uint8_t_array(buf, 4, buffer, 251);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PACKED_PARAM_VALUES, buf, MAVLINK_MSG_ID_PACKED_PARAM_VALUES_MIN_LEN, MAVLINK_MSG_ID_PACKED_PARAM_VALUES_LEN, MAVLINK_MSG_ID_PACKED_PARAM_VALUES_CRC);
#else
    mavlink_packed_param_values_t packet;
    packet.parameter_group_id = parameter_group_id;
    packet.number = number;
    packet.total_size = total_size;
    mav_array_memcpy(packet.buffer, buffer, sizeof(uint8_t)*251);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PACKED_PARAM_VALUES, (const char *)&packet, MAVLINK_MSG_ID_PACKED_PARAM_VALUES_MIN_LEN, MAVLINK_MSG_ID_PACKED_PARAM_VALUES_LEN, MAVLINK_MSG_ID_PACKED_PARAM_VALUES_CRC);
#endif
}

/**
 * @brief Send a packed_param_values message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_packed_param_values_send_struct(mavlink_channel_t chan, const mavlink_packed_param_values_t* packed_param_values)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_packed_param_values_send(chan, packed_param_values->number, packed_param_values->total_size, packed_param_values->parameter_group_id, packed_param_values->buffer);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PACKED_PARAM_VALUES, (const char *)packed_param_values, MAVLINK_MSG_ID_PACKED_PARAM_VALUES_MIN_LEN, MAVLINK_MSG_ID_PACKED_PARAM_VALUES_LEN, MAVLINK_MSG_ID_PACKED_PARAM_VALUES_CRC);
#endif
}

#if MAVLINK_MSG_ID_PACKED_PARAM_VALUES_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_packed_param_values_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t number, uint8_t total_size, uint16_t parameter_group_id, const uint8_t *buffer)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, parameter_group_id);
    _mav_put_uint8_t(buf, 2, number);
    _mav_put_uint8_t(buf, 3, total_size);
    _mav_put_uint8_t_array(buf, 4, buffer, 251);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PACKED_PARAM_VALUES, buf, MAVLINK_MSG_ID_PACKED_PARAM_VALUES_MIN_LEN, MAVLINK_MSG_ID_PACKED_PARAM_VALUES_LEN, MAVLINK_MSG_ID_PACKED_PARAM_VALUES_CRC);
#else
    mavlink_packed_param_values_t *packet = (mavlink_packed_param_values_t *)msgbuf;
    packet->parameter_group_id = parameter_group_id;
    packet->number = number;
    packet->total_size = total_size;
    mav_array_memcpy(packet->buffer, buffer, sizeof(uint8_t)*251);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PACKED_PARAM_VALUES, (const char *)packet, MAVLINK_MSG_ID_PACKED_PARAM_VALUES_MIN_LEN, MAVLINK_MSG_ID_PACKED_PARAM_VALUES_LEN, MAVLINK_MSG_ID_PACKED_PARAM_VALUES_CRC);
#endif
}
#endif

#endif

// MESSAGE PACKED_PARAM_VALUES UNPACKING


/**
 * @brief Get field number from packed_param_values message
 *
 * @return  Number of packed parameters contained in this message
 */
static inline uint8_t mavlink_msg_packed_param_values_get_number(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field total_size from packed_param_values message
 *
 * @return [Bytes] Total size of the message
 */
static inline uint8_t mavlink_msg_packed_param_values_get_total_size(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field parameter_group_id from packed_param_values message
 *
 * @return  ID of the parameter group these belong to. Set to 0 if none.
 */
static inline uint16_t mavlink_msg_packed_param_values_get_parameter_group_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field buffer from packed_param_values message
 *
 * @return  Buffer of packed parameters
 */
static inline uint16_t mavlink_msg_packed_param_values_get_buffer(const mavlink_message_t* msg, uint8_t *buffer)
{
    return _MAV_RETURN_uint8_t_array(msg, buffer, 251,  4);
}

/**
 * @brief Decode a packed_param_values message into a struct
 *
 * @param msg The message to decode
 * @param packed_param_values C-struct to decode the message contents into
 */
static inline void mavlink_msg_packed_param_values_decode(const mavlink_message_t* msg, mavlink_packed_param_values_t* packed_param_values)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    packed_param_values->parameter_group_id = mavlink_msg_packed_param_values_get_parameter_group_id(msg);
    packed_param_values->number = mavlink_msg_packed_param_values_get_number(msg);
    packed_param_values->total_size = mavlink_msg_packed_param_values_get_total_size(msg);
    mavlink_msg_packed_param_values_get_buffer(msg, packed_param_values->buffer);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_PACKED_PARAM_VALUES_LEN? msg->len : MAVLINK_MSG_ID_PACKED_PARAM_VALUES_LEN;
        memset(packed_param_values, 0, MAVLINK_MSG_ID_PACKED_PARAM_VALUES_LEN);
    memcpy(packed_param_values, _MAV_PAYLOAD(msg), len);
#endif
}
