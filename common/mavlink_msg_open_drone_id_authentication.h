#pragma once
// MESSAGE OPEN_DRONE_ID_AUTHENTICATION PACKING

#define MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION 12902

MAVPACKED(
typedef struct __mavlink_open_drone_id_authentication_t {
 uint8_t authentication_type; /*<  Indicates the type of authentication.*/
 uint8_t data_page; /*<  Allowed range is 0 - 15.*/
 uint8_t authentication_data[23]; /*<  Opaque authentication data. Sixteen pages are supported for a total of 16 * 23 = 368 bytes. Shall be filled with nulls in the unused portion of the field.*/
}) mavlink_open_drone_id_authentication_t;

#define MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION_LEN 25
#define MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION_MIN_LEN 25
#define MAVLINK_MSG_ID_12902_LEN 25
#define MAVLINK_MSG_ID_12902_MIN_LEN 25

#define MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION_CRC 254
#define MAVLINK_MSG_ID_12902_CRC 254

#define MAVLINK_MSG_OPEN_DRONE_ID_AUTHENTICATION_FIELD_AUTHENTICATION_DATA_LEN 23

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_OPEN_DRONE_ID_AUTHENTICATION { \
    12902, \
    "OPEN_DRONE_ID_AUTHENTICATION", \
    3, \
    {  { "authentication_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_open_drone_id_authentication_t, authentication_type) }, \
         { "data_page", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_open_drone_id_authentication_t, data_page) }, \
         { "authentication_data", NULL, MAVLINK_TYPE_UINT8_T, 23, 2, offsetof(mavlink_open_drone_id_authentication_t, authentication_data) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_OPEN_DRONE_ID_AUTHENTICATION { \
    "OPEN_DRONE_ID_AUTHENTICATION", \
    3, \
    {  { "authentication_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_open_drone_id_authentication_t, authentication_type) }, \
         { "data_page", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_open_drone_id_authentication_t, data_page) }, \
         { "authentication_data", NULL, MAVLINK_TYPE_UINT8_T, 23, 2, offsetof(mavlink_open_drone_id_authentication_t, authentication_data) }, \
         } \
}
#endif

/**
 * @brief Pack a open_drone_id_authentication message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param authentication_type  Indicates the type of authentication.
 * @param data_page  Allowed range is 0 - 15.
 * @param authentication_data  Opaque authentication data. Sixteen pages are supported for a total of 16 * 23 = 368 bytes. Shall be filled with nulls in the unused portion of the field.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_open_drone_id_authentication_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t authentication_type, uint8_t data_page, const uint8_t *authentication_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION_LEN];
    _mav_put_uint8_t(buf, 0, authentication_type);
    _mav_put_uint8_t(buf, 1, data_page);
    _mav_put_uint8_t_array(buf, 2, authentication_data, 23);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION_LEN);
#else
    mavlink_open_drone_id_authentication_t packet;
    packet.authentication_type = authentication_type;
    packet.data_page = data_page;
    mav_array_memcpy(packet.authentication_data, authentication_data, sizeof(uint8_t)*23);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION_MIN_LEN, MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION_LEN, MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION_CRC);
}

/**
 * @brief Pack a open_drone_id_authentication message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param authentication_type  Indicates the type of authentication.
 * @param data_page  Allowed range is 0 - 15.
 * @param authentication_data  Opaque authentication data. Sixteen pages are supported for a total of 16 * 23 = 368 bytes. Shall be filled with nulls in the unused portion of the field.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_open_drone_id_authentication_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t authentication_type,uint8_t data_page,const uint8_t *authentication_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION_LEN];
    _mav_put_uint8_t(buf, 0, authentication_type);
    _mav_put_uint8_t(buf, 1, data_page);
    _mav_put_uint8_t_array(buf, 2, authentication_data, 23);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION_LEN);
#else
    mavlink_open_drone_id_authentication_t packet;
    packet.authentication_type = authentication_type;
    packet.data_page = data_page;
    mav_array_memcpy(packet.authentication_data, authentication_data, sizeof(uint8_t)*23);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION_MIN_LEN, MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION_LEN, MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION_CRC);
}

/**
 * @brief Encode a open_drone_id_authentication struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param open_drone_id_authentication C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_open_drone_id_authentication_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_open_drone_id_authentication_t* open_drone_id_authentication)
{
    return mavlink_msg_open_drone_id_authentication_pack(system_id, component_id, msg, open_drone_id_authentication->authentication_type, open_drone_id_authentication->data_page, open_drone_id_authentication->authentication_data);
}

/**
 * @brief Encode a open_drone_id_authentication struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param open_drone_id_authentication C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_open_drone_id_authentication_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_open_drone_id_authentication_t* open_drone_id_authentication)
{
    return mavlink_msg_open_drone_id_authentication_pack_chan(system_id, component_id, chan, msg, open_drone_id_authentication->authentication_type, open_drone_id_authentication->data_page, open_drone_id_authentication->authentication_data);
}

/**
 * @brief Send a open_drone_id_authentication message
 * @param chan MAVLink channel to send the message
 *
 * @param authentication_type  Indicates the type of authentication.
 * @param data_page  Allowed range is 0 - 15.
 * @param authentication_data  Opaque authentication data. Sixteen pages are supported for a total of 16 * 23 = 368 bytes. Shall be filled with nulls in the unused portion of the field.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_open_drone_id_authentication_send(mavlink_channel_t chan, uint8_t authentication_type, uint8_t data_page, const uint8_t *authentication_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION_LEN];
    _mav_put_uint8_t(buf, 0, authentication_type);
    _mav_put_uint8_t(buf, 1, data_page);
    _mav_put_uint8_t_array(buf, 2, authentication_data, 23);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION, buf, MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION_MIN_LEN, MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION_LEN, MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION_CRC);
#else
    mavlink_open_drone_id_authentication_t packet;
    packet.authentication_type = authentication_type;
    packet.data_page = data_page;
    mav_array_memcpy(packet.authentication_data, authentication_data, sizeof(uint8_t)*23);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION, (const char *)&packet, MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION_MIN_LEN, MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION_LEN, MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION_CRC);
#endif
}

/**
 * @brief Send a open_drone_id_authentication message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_open_drone_id_authentication_send_struct(mavlink_channel_t chan, const mavlink_open_drone_id_authentication_t* open_drone_id_authentication)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_open_drone_id_authentication_send(chan, open_drone_id_authentication->authentication_type, open_drone_id_authentication->data_page, open_drone_id_authentication->authentication_data);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION, (const char *)open_drone_id_authentication, MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION_MIN_LEN, MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION_LEN, MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION_CRC);
#endif
}

#if MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_open_drone_id_authentication_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t authentication_type, uint8_t data_page, const uint8_t *authentication_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, authentication_type);
    _mav_put_uint8_t(buf, 1, data_page);
    _mav_put_uint8_t_array(buf, 2, authentication_data, 23);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION, buf, MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION_MIN_LEN, MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION_LEN, MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION_CRC);
#else
    mavlink_open_drone_id_authentication_t *packet = (mavlink_open_drone_id_authentication_t *)msgbuf;
    packet->authentication_type = authentication_type;
    packet->data_page = data_page;
    mav_array_memcpy(packet->authentication_data, authentication_data, sizeof(uint8_t)*23);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION, (const char *)packet, MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION_MIN_LEN, MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION_LEN, MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION_CRC);
#endif
}
#endif

#endif

// MESSAGE OPEN_DRONE_ID_AUTHENTICATION UNPACKING


/**
 * @brief Get field authentication_type from open_drone_id_authentication message
 *
 * @return  Indicates the type of authentication.
 */
static inline uint8_t mavlink_msg_open_drone_id_authentication_get_authentication_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field data_page from open_drone_id_authentication message
 *
 * @return  Allowed range is 0 - 15.
 */
static inline uint8_t mavlink_msg_open_drone_id_authentication_get_data_page(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field authentication_data from open_drone_id_authentication message
 *
 * @return  Opaque authentication data. Sixteen pages are supported for a total of 16 * 23 = 368 bytes. Shall be filled with nulls in the unused portion of the field.
 */
static inline uint16_t mavlink_msg_open_drone_id_authentication_get_authentication_data(const mavlink_message_t* msg, uint8_t *authentication_data)
{
    return _MAV_RETURN_uint8_t_array(msg, authentication_data, 23,  2);
}

/**
 * @brief Decode a open_drone_id_authentication message into a struct
 *
 * @param msg The message to decode
 * @param open_drone_id_authentication C-struct to decode the message contents into
 */
static inline void mavlink_msg_open_drone_id_authentication_decode(const mavlink_message_t* msg, mavlink_open_drone_id_authentication_t* open_drone_id_authentication)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    open_drone_id_authentication->authentication_type = mavlink_msg_open_drone_id_authentication_get_authentication_type(msg);
    open_drone_id_authentication->data_page = mavlink_msg_open_drone_id_authentication_get_data_page(msg);
    mavlink_msg_open_drone_id_authentication_get_authentication_data(msg, open_drone_id_authentication->authentication_data);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION_LEN? msg->len : MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION_LEN;
        memset(open_drone_id_authentication, 0, MAVLINK_MSG_ID_OPEN_DRONE_ID_AUTHENTICATION_LEN);
    memcpy(open_drone_id_authentication, _MAV_PAYLOAD(msg), len);
#endif
}
