#pragma once
// MESSAGE PIXEL_TO_LLA_REQUEST PACKING

#define MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST 600


typedef struct __mavlink_pixel_to_lla_request_t {
 uint64_t uid; /*<   Unique ID of the request.*/
 uint64_t img_unix_ts; /*< [us]  Unix time stamp of the image.*/
 float img_rel_x; /*<   Relative image x coordinate (left to right axis) in the range of [0.0, 1.0].*/
 float img_rel_y; /*<   Relative image y coordinate (top to bottom axis) in the range of [0.0, 1.0].*/
 uint8_t camera_id; /*<   Camera ID of the image source.*/
} mavlink_pixel_to_lla_request_t;

#define MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_LEN 25
#define MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_MIN_LEN 25
#define MAVLINK_MSG_ID_600_LEN 25
#define MAVLINK_MSG_ID_600_MIN_LEN 25

#define MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_CRC 239
#define MAVLINK_MSG_ID_600_CRC 239



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PIXEL_TO_LLA_REQUEST { \
    600, \
    "PIXEL_TO_LLA_REQUEST", \
    5, \
    {  { "camera_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_pixel_to_lla_request_t, camera_id) }, \
         { "uid", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_pixel_to_lla_request_t, uid) }, \
         { "img_unix_ts", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_pixel_to_lla_request_t, img_unix_ts) }, \
         { "img_rel_x", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_pixel_to_lla_request_t, img_rel_x) }, \
         { "img_rel_y", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_pixel_to_lla_request_t, img_rel_y) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PIXEL_TO_LLA_REQUEST { \
    "PIXEL_TO_LLA_REQUEST", \
    5, \
    {  { "camera_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_pixel_to_lla_request_t, camera_id) }, \
         { "uid", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_pixel_to_lla_request_t, uid) }, \
         { "img_unix_ts", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_pixel_to_lla_request_t, img_unix_ts) }, \
         { "img_rel_x", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_pixel_to_lla_request_t, img_rel_x) }, \
         { "img_rel_y", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_pixel_to_lla_request_t, img_rel_y) }, \
         } \
}
#endif

/**
 * @brief Pack a pixel_to_lla_request message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param camera_id   Camera ID of the image source.
 * @param uid   Unique ID of the request.
 * @param img_unix_ts [us]  Unix time stamp of the image.
 * @param img_rel_x   Relative image x coordinate (left to right axis) in the range of [0.0, 1.0].
 * @param img_rel_y   Relative image y coordinate (top to bottom axis) in the range of [0.0, 1.0].
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pixel_to_lla_request_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t camera_id, uint64_t uid, uint64_t img_unix_ts, float img_rel_x, float img_rel_y)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_LEN];
    _mav_put_uint64_t(buf, 0, uid);
    _mav_put_uint64_t(buf, 8, img_unix_ts);
    _mav_put_float(buf, 16, img_rel_x);
    _mav_put_float(buf, 20, img_rel_y);
    _mav_put_uint8_t(buf, 24, camera_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_LEN);
#else
    mavlink_pixel_to_lla_request_t packet;
    packet.uid = uid;
    packet.img_unix_ts = img_unix_ts;
    packet.img_rel_x = img_rel_x;
    packet.img_rel_y = img_rel_y;
    packet.camera_id = camera_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_MIN_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_CRC);
}

/**
 * @brief Pack a pixel_to_lla_request message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param camera_id   Camera ID of the image source.
 * @param uid   Unique ID of the request.
 * @param img_unix_ts [us]  Unix time stamp of the image.
 * @param img_rel_x   Relative image x coordinate (left to right axis) in the range of [0.0, 1.0].
 * @param img_rel_y   Relative image y coordinate (top to bottom axis) in the range of [0.0, 1.0].
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pixel_to_lla_request_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t camera_id, uint64_t uid, uint64_t img_unix_ts, float img_rel_x, float img_rel_y)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_LEN];
    _mav_put_uint64_t(buf, 0, uid);
    _mav_put_uint64_t(buf, 8, img_unix_ts);
    _mav_put_float(buf, 16, img_rel_x);
    _mav_put_float(buf, 20, img_rel_y);
    _mav_put_uint8_t(buf, 24, camera_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_LEN);
#else
    mavlink_pixel_to_lla_request_t packet;
    packet.uid = uid;
    packet.img_unix_ts = img_unix_ts;
    packet.img_rel_x = img_rel_x;
    packet.img_rel_y = img_rel_y;
    packet.camera_id = camera_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_MIN_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_MIN_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_LEN);
#endif
}

/**
 * @brief Pack a pixel_to_lla_request message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param camera_id   Camera ID of the image source.
 * @param uid   Unique ID of the request.
 * @param img_unix_ts [us]  Unix time stamp of the image.
 * @param img_rel_x   Relative image x coordinate (left to right axis) in the range of [0.0, 1.0].
 * @param img_rel_y   Relative image y coordinate (top to bottom axis) in the range of [0.0, 1.0].
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pixel_to_lla_request_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t camera_id,uint64_t uid,uint64_t img_unix_ts,float img_rel_x,float img_rel_y)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_LEN];
    _mav_put_uint64_t(buf, 0, uid);
    _mav_put_uint64_t(buf, 8, img_unix_ts);
    _mav_put_float(buf, 16, img_rel_x);
    _mav_put_float(buf, 20, img_rel_y);
    _mav_put_uint8_t(buf, 24, camera_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_LEN);
#else
    mavlink_pixel_to_lla_request_t packet;
    packet.uid = uid;
    packet.img_unix_ts = img_unix_ts;
    packet.img_rel_x = img_rel_x;
    packet.img_rel_y = img_rel_y;
    packet.camera_id = camera_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_MIN_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_CRC);
}

/**
 * @brief Encode a pixel_to_lla_request struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param pixel_to_lla_request C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pixel_to_lla_request_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_pixel_to_lla_request_t* pixel_to_lla_request)
{
    return mavlink_msg_pixel_to_lla_request_pack(system_id, component_id, msg, pixel_to_lla_request->camera_id, pixel_to_lla_request->uid, pixel_to_lla_request->img_unix_ts, pixel_to_lla_request->img_rel_x, pixel_to_lla_request->img_rel_y);
}

/**
 * @brief Encode a pixel_to_lla_request struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param pixel_to_lla_request C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pixel_to_lla_request_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_pixel_to_lla_request_t* pixel_to_lla_request)
{
    return mavlink_msg_pixel_to_lla_request_pack_chan(system_id, component_id, chan, msg, pixel_to_lla_request->camera_id, pixel_to_lla_request->uid, pixel_to_lla_request->img_unix_ts, pixel_to_lla_request->img_rel_x, pixel_to_lla_request->img_rel_y);
}

/**
 * @brief Encode a pixel_to_lla_request struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param pixel_to_lla_request C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pixel_to_lla_request_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_pixel_to_lla_request_t* pixel_to_lla_request)
{
    return mavlink_msg_pixel_to_lla_request_pack_status(system_id, component_id, _status, msg,  pixel_to_lla_request->camera_id, pixel_to_lla_request->uid, pixel_to_lla_request->img_unix_ts, pixel_to_lla_request->img_rel_x, pixel_to_lla_request->img_rel_y);
}

/**
 * @brief Send a pixel_to_lla_request message
 * @param chan MAVLink channel to send the message
 *
 * @param camera_id   Camera ID of the image source.
 * @param uid   Unique ID of the request.
 * @param img_unix_ts [us]  Unix time stamp of the image.
 * @param img_rel_x   Relative image x coordinate (left to right axis) in the range of [0.0, 1.0].
 * @param img_rel_y   Relative image y coordinate (top to bottom axis) in the range of [0.0, 1.0].
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_pixel_to_lla_request_send(mavlink_channel_t chan, uint8_t camera_id, uint64_t uid, uint64_t img_unix_ts, float img_rel_x, float img_rel_y)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_LEN];
    _mav_put_uint64_t(buf, 0, uid);
    _mav_put_uint64_t(buf, 8, img_unix_ts);
    _mav_put_float(buf, 16, img_rel_x);
    _mav_put_float(buf, 20, img_rel_y);
    _mav_put_uint8_t(buf, 24, camera_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST, buf, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_MIN_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_CRC);
#else
    mavlink_pixel_to_lla_request_t packet;
    packet.uid = uid;
    packet.img_unix_ts = img_unix_ts;
    packet.img_rel_x = img_rel_x;
    packet.img_rel_y = img_rel_y;
    packet.camera_id = camera_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST, (const char *)&packet, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_MIN_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_CRC);
#endif
}

/**
 * @brief Send a pixel_to_lla_request message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_pixel_to_lla_request_send_struct(mavlink_channel_t chan, const mavlink_pixel_to_lla_request_t* pixel_to_lla_request)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_pixel_to_lla_request_send(chan, pixel_to_lla_request->camera_id, pixel_to_lla_request->uid, pixel_to_lla_request->img_unix_ts, pixel_to_lla_request->img_rel_x, pixel_to_lla_request->img_rel_y);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST, (const char *)pixel_to_lla_request, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_MIN_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_CRC);
#endif
}

#if MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_pixel_to_lla_request_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t camera_id, uint64_t uid, uint64_t img_unix_ts, float img_rel_x, float img_rel_y)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, uid);
    _mav_put_uint64_t(buf, 8, img_unix_ts);
    _mav_put_float(buf, 16, img_rel_x);
    _mav_put_float(buf, 20, img_rel_y);
    _mav_put_uint8_t(buf, 24, camera_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST, buf, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_MIN_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_CRC);
#else
    mavlink_pixel_to_lla_request_t *packet = (mavlink_pixel_to_lla_request_t *)msgbuf;
    packet->uid = uid;
    packet->img_unix_ts = img_unix_ts;
    packet->img_rel_x = img_rel_x;
    packet->img_rel_y = img_rel_y;
    packet->camera_id = camera_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST, (const char *)packet, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_MIN_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_CRC);
#endif
}
#endif

#endif

// MESSAGE PIXEL_TO_LLA_REQUEST UNPACKING


/**
 * @brief Get field camera_id from pixel_to_lla_request message
 *
 * @return   Camera ID of the image source.
 */
static inline uint8_t mavlink_msg_pixel_to_lla_request_get_camera_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  24);
}

/**
 * @brief Get field uid from pixel_to_lla_request message
 *
 * @return   Unique ID of the request.
 */
static inline uint64_t mavlink_msg_pixel_to_lla_request_get_uid(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field img_unix_ts from pixel_to_lla_request message
 *
 * @return [us]  Unix time stamp of the image.
 */
static inline uint64_t mavlink_msg_pixel_to_lla_request_get_img_unix_ts(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  8);
}

/**
 * @brief Get field img_rel_x from pixel_to_lla_request message
 *
 * @return   Relative image x coordinate (left to right axis) in the range of [0.0, 1.0].
 */
static inline float mavlink_msg_pixel_to_lla_request_get_img_rel_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field img_rel_y from pixel_to_lla_request message
 *
 * @return   Relative image y coordinate (top to bottom axis) in the range of [0.0, 1.0].
 */
static inline float mavlink_msg_pixel_to_lla_request_get_img_rel_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Decode a pixel_to_lla_request message into a struct
 *
 * @param msg The message to decode
 * @param pixel_to_lla_request C-struct to decode the message contents into
 */
static inline void mavlink_msg_pixel_to_lla_request_decode(const mavlink_message_t* msg, mavlink_pixel_to_lla_request_t* pixel_to_lla_request)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    pixel_to_lla_request->uid = mavlink_msg_pixel_to_lla_request_get_uid(msg);
    pixel_to_lla_request->img_unix_ts = mavlink_msg_pixel_to_lla_request_get_img_unix_ts(msg);
    pixel_to_lla_request->img_rel_x = mavlink_msg_pixel_to_lla_request_get_img_rel_x(msg);
    pixel_to_lla_request->img_rel_y = mavlink_msg_pixel_to_lla_request_get_img_rel_y(msg);
    pixel_to_lla_request->camera_id = mavlink_msg_pixel_to_lla_request_get_camera_id(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_LEN? msg->len : MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_LEN;
        memset(pixel_to_lla_request, 0, MAVLINK_MSG_ID_PIXEL_TO_LLA_REQUEST_LEN);
    memcpy(pixel_to_lla_request, _MAV_PAYLOAD(msg), len);
#endif
}
