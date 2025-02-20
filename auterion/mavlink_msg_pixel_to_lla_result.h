#pragma once
// MESSAGE PIXEL_TO_LLA_RESULT PACKING

#define MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT 602


typedef struct __mavlink_pixel_to_lla_result_t {
 uint64_t uid; /*<   Unique ID of the request.*/
 double latitude; /*< [deg] Latitude of the requested pixel (degrees, WGS84).*/
 double longitude; /*< [deg] Longitude of the requested pixel (degrees, WGS84).*/
 double altitude; /*< [m] Altitude of the requested pixel (meters, WGS84 ellipsoid).*/
 float ned_homography_matrix[9]; /*<  3x3 matrix for NED (North-East-Down) homography transform of the image. Row-major order.*/
 uint8_t status; /*<  0 = Success, 1 = Failure. If failure, error_message will provide details.*/
 char error_message[100]; /*<  Optional error message in case of failure. Max length 100 characters.*/
} mavlink_pixel_to_lla_result_t;

#define MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_LEN 169
#define MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_MIN_LEN 169
#define MAVLINK_MSG_ID_602_LEN 169
#define MAVLINK_MSG_ID_602_MIN_LEN 169

#define MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_CRC 202
#define MAVLINK_MSG_ID_602_CRC 202

#define MAVLINK_MSG_PIXEL_TO_LLA_RESULT_FIELD_NED_HOMOGRAPHY_MATRIX_LEN 9
#define MAVLINK_MSG_PIXEL_TO_LLA_RESULT_FIELD_ERROR_MESSAGE_LEN 100

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PIXEL_TO_LLA_RESULT { \
    602, \
    "PIXEL_TO_LLA_RESULT", \
    7, \
    {  { "uid", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_pixel_to_lla_result_t, uid) }, \
         { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 68, offsetof(mavlink_pixel_to_lla_result_t, status) }, \
         { "latitude", NULL, MAVLINK_TYPE_DOUBLE, 0, 8, offsetof(mavlink_pixel_to_lla_result_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_DOUBLE, 0, 16, offsetof(mavlink_pixel_to_lla_result_t, longitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_DOUBLE, 0, 24, offsetof(mavlink_pixel_to_lla_result_t, altitude) }, \
         { "ned_homography_matrix", NULL, MAVLINK_TYPE_FLOAT, 9, 32, offsetof(mavlink_pixel_to_lla_result_t, ned_homography_matrix) }, \
         { "error_message", NULL, MAVLINK_TYPE_CHAR, 100, 69, offsetof(mavlink_pixel_to_lla_result_t, error_message) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PIXEL_TO_LLA_RESULT { \
    "PIXEL_TO_LLA_RESULT", \
    7, \
    {  { "uid", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_pixel_to_lla_result_t, uid) }, \
         { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 68, offsetof(mavlink_pixel_to_lla_result_t, status) }, \
         { "latitude", NULL, MAVLINK_TYPE_DOUBLE, 0, 8, offsetof(mavlink_pixel_to_lla_result_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_DOUBLE, 0, 16, offsetof(mavlink_pixel_to_lla_result_t, longitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_DOUBLE, 0, 24, offsetof(mavlink_pixel_to_lla_result_t, altitude) }, \
         { "ned_homography_matrix", NULL, MAVLINK_TYPE_FLOAT, 9, 32, offsetof(mavlink_pixel_to_lla_result_t, ned_homography_matrix) }, \
         { "error_message", NULL, MAVLINK_TYPE_CHAR, 100, 69, offsetof(mavlink_pixel_to_lla_result_t, error_message) }, \
         } \
}
#endif

/**
 * @brief Pack a pixel_to_lla_result message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param uid   Unique ID of the request.
 * @param status  0 = Success, 1 = Failure. If failure, error_message will provide details.
 * @param latitude [deg] Latitude of the requested pixel (degrees, WGS84).
 * @param longitude [deg] Longitude of the requested pixel (degrees, WGS84).
 * @param altitude [m] Altitude of the requested pixel (meters, WGS84 ellipsoid).
 * @param ned_homography_matrix  3x3 matrix for NED (North-East-Down) homography transform of the image. Row-major order.
 * @param error_message  Optional error message in case of failure. Max length 100 characters.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pixel_to_lla_result_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t uid, uint8_t status, double latitude, double longitude, double altitude, const float *ned_homography_matrix, const char *error_message)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_LEN];
    _mav_put_uint64_t(buf, 0, uid);
    _mav_put_double(buf, 8, latitude);
    _mav_put_double(buf, 16, longitude);
    _mav_put_double(buf, 24, altitude);
    _mav_put_uint8_t(buf, 68, status);
    _mav_put_float_array(buf, 32, ned_homography_matrix, 9);
    _mav_put_char_array(buf, 69, error_message, 100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_LEN);
#else
    mavlink_pixel_to_lla_result_t packet;
    packet.uid = uid;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.altitude = altitude;
    packet.status = status;
    mav_array_memcpy(packet.ned_homography_matrix, ned_homography_matrix, sizeof(float)*9);
    mav_array_memcpy(packet.error_message, error_message, sizeof(char)*100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_MIN_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_CRC);
}

/**
 * @brief Pack a pixel_to_lla_result message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param uid   Unique ID of the request.
 * @param status  0 = Success, 1 = Failure. If failure, error_message will provide details.
 * @param latitude [deg] Latitude of the requested pixel (degrees, WGS84).
 * @param longitude [deg] Longitude of the requested pixel (degrees, WGS84).
 * @param altitude [m] Altitude of the requested pixel (meters, WGS84 ellipsoid).
 * @param ned_homography_matrix  3x3 matrix for NED (North-East-Down) homography transform of the image. Row-major order.
 * @param error_message  Optional error message in case of failure. Max length 100 characters.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pixel_to_lla_result_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint64_t uid, uint8_t status, double latitude, double longitude, double altitude, const float *ned_homography_matrix, const char *error_message)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_LEN];
    _mav_put_uint64_t(buf, 0, uid);
    _mav_put_double(buf, 8, latitude);
    _mav_put_double(buf, 16, longitude);
    _mav_put_double(buf, 24, altitude);
    _mav_put_uint8_t(buf, 68, status);
    _mav_put_float_array(buf, 32, ned_homography_matrix, 9);
    _mav_put_char_array(buf, 69, error_message, 100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_LEN);
#else
    mavlink_pixel_to_lla_result_t packet;
    packet.uid = uid;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.altitude = altitude;
    packet.status = status;
    mav_array_memcpy(packet.ned_homography_matrix, ned_homography_matrix, sizeof(float)*9);
    mav_array_memcpy(packet.error_message, error_message, sizeof(char)*100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_MIN_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_MIN_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_LEN);
#endif
}

/**
 * @brief Pack a pixel_to_lla_result message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param uid   Unique ID of the request.
 * @param status  0 = Success, 1 = Failure. If failure, error_message will provide details.
 * @param latitude [deg] Latitude of the requested pixel (degrees, WGS84).
 * @param longitude [deg] Longitude of the requested pixel (degrees, WGS84).
 * @param altitude [m] Altitude of the requested pixel (meters, WGS84 ellipsoid).
 * @param ned_homography_matrix  3x3 matrix for NED (North-East-Down) homography transform of the image. Row-major order.
 * @param error_message  Optional error message in case of failure. Max length 100 characters.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pixel_to_lla_result_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t uid,uint8_t status,double latitude,double longitude,double altitude,const float *ned_homography_matrix,const char *error_message)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_LEN];
    _mav_put_uint64_t(buf, 0, uid);
    _mav_put_double(buf, 8, latitude);
    _mav_put_double(buf, 16, longitude);
    _mav_put_double(buf, 24, altitude);
    _mav_put_uint8_t(buf, 68, status);
    _mav_put_float_array(buf, 32, ned_homography_matrix, 9);
    _mav_put_char_array(buf, 69, error_message, 100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_LEN);
#else
    mavlink_pixel_to_lla_result_t packet;
    packet.uid = uid;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.altitude = altitude;
    packet.status = status;
    mav_array_memcpy(packet.ned_homography_matrix, ned_homography_matrix, sizeof(float)*9);
    mav_array_memcpy(packet.error_message, error_message, sizeof(char)*100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_MIN_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_CRC);
}

/**
 * @brief Encode a pixel_to_lla_result struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param pixel_to_lla_result C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pixel_to_lla_result_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_pixel_to_lla_result_t* pixel_to_lla_result)
{
    return mavlink_msg_pixel_to_lla_result_pack(system_id, component_id, msg, pixel_to_lla_result->uid, pixel_to_lla_result->status, pixel_to_lla_result->latitude, pixel_to_lla_result->longitude, pixel_to_lla_result->altitude, pixel_to_lla_result->ned_homography_matrix, pixel_to_lla_result->error_message);
}

/**
 * @brief Encode a pixel_to_lla_result struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param pixel_to_lla_result C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pixel_to_lla_result_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_pixel_to_lla_result_t* pixel_to_lla_result)
{
    return mavlink_msg_pixel_to_lla_result_pack_chan(system_id, component_id, chan, msg, pixel_to_lla_result->uid, pixel_to_lla_result->status, pixel_to_lla_result->latitude, pixel_to_lla_result->longitude, pixel_to_lla_result->altitude, pixel_to_lla_result->ned_homography_matrix, pixel_to_lla_result->error_message);
}

/**
 * @brief Encode a pixel_to_lla_result struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param pixel_to_lla_result C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pixel_to_lla_result_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_pixel_to_lla_result_t* pixel_to_lla_result)
{
    return mavlink_msg_pixel_to_lla_result_pack_status(system_id, component_id, _status, msg,  pixel_to_lla_result->uid, pixel_to_lla_result->status, pixel_to_lla_result->latitude, pixel_to_lla_result->longitude, pixel_to_lla_result->altitude, pixel_to_lla_result->ned_homography_matrix, pixel_to_lla_result->error_message);
}

/**
 * @brief Send a pixel_to_lla_result message
 * @param chan MAVLink channel to send the message
 *
 * @param uid   Unique ID of the request.
 * @param status  0 = Success, 1 = Failure. If failure, error_message will provide details.
 * @param latitude [deg] Latitude of the requested pixel (degrees, WGS84).
 * @param longitude [deg] Longitude of the requested pixel (degrees, WGS84).
 * @param altitude [m] Altitude of the requested pixel (meters, WGS84 ellipsoid).
 * @param ned_homography_matrix  3x3 matrix for NED (North-East-Down) homography transform of the image. Row-major order.
 * @param error_message  Optional error message in case of failure. Max length 100 characters.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_pixel_to_lla_result_send(mavlink_channel_t chan, uint64_t uid, uint8_t status, double latitude, double longitude, double altitude, const float *ned_homography_matrix, const char *error_message)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_LEN];
    _mav_put_uint64_t(buf, 0, uid);
    _mav_put_double(buf, 8, latitude);
    _mav_put_double(buf, 16, longitude);
    _mav_put_double(buf, 24, altitude);
    _mav_put_uint8_t(buf, 68, status);
    _mav_put_float_array(buf, 32, ned_homography_matrix, 9);
    _mav_put_char_array(buf, 69, error_message, 100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT, buf, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_MIN_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_CRC);
#else
    mavlink_pixel_to_lla_result_t packet;
    packet.uid = uid;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.altitude = altitude;
    packet.status = status;
    mav_array_memcpy(packet.ned_homography_matrix, ned_homography_matrix, sizeof(float)*9);
    mav_array_memcpy(packet.error_message, error_message, sizeof(char)*100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT, (const char *)&packet, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_MIN_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_CRC);
#endif
}

/**
 * @brief Send a pixel_to_lla_result message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_pixel_to_lla_result_send_struct(mavlink_channel_t chan, const mavlink_pixel_to_lla_result_t* pixel_to_lla_result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_pixel_to_lla_result_send(chan, pixel_to_lla_result->uid, pixel_to_lla_result->status, pixel_to_lla_result->latitude, pixel_to_lla_result->longitude, pixel_to_lla_result->altitude, pixel_to_lla_result->ned_homography_matrix, pixel_to_lla_result->error_message);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT, (const char *)pixel_to_lla_result, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_MIN_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_CRC);
#endif
}

#if MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_pixel_to_lla_result_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t uid, uint8_t status, double latitude, double longitude, double altitude, const float *ned_homography_matrix, const char *error_message)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, uid);
    _mav_put_double(buf, 8, latitude);
    _mav_put_double(buf, 16, longitude);
    _mav_put_double(buf, 24, altitude);
    _mav_put_uint8_t(buf, 68, status);
    _mav_put_float_array(buf, 32, ned_homography_matrix, 9);
    _mav_put_char_array(buf, 69, error_message, 100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT, buf, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_MIN_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_CRC);
#else
    mavlink_pixel_to_lla_result_t *packet = (mavlink_pixel_to_lla_result_t *)msgbuf;
    packet->uid = uid;
    packet->latitude = latitude;
    packet->longitude = longitude;
    packet->altitude = altitude;
    packet->status = status;
    mav_array_memcpy(packet->ned_homography_matrix, ned_homography_matrix, sizeof(float)*9);
    mav_array_memcpy(packet->error_message, error_message, sizeof(char)*100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT, (const char *)packet, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_MIN_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_LEN, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_CRC);
#endif
}
#endif

#endif

// MESSAGE PIXEL_TO_LLA_RESULT UNPACKING


/**
 * @brief Get field uid from pixel_to_lla_result message
 *
 * @return   Unique ID of the request.
 */
static inline uint64_t mavlink_msg_pixel_to_lla_result_get_uid(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field status from pixel_to_lla_result message
 *
 * @return  0 = Success, 1 = Failure. If failure, error_message will provide details.
 */
static inline uint8_t mavlink_msg_pixel_to_lla_result_get_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  68);
}

/**
 * @brief Get field latitude from pixel_to_lla_result message
 *
 * @return [deg] Latitude of the requested pixel (degrees, WGS84).
 */
static inline double mavlink_msg_pixel_to_lla_result_get_latitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_double(msg,  8);
}

/**
 * @brief Get field longitude from pixel_to_lla_result message
 *
 * @return [deg] Longitude of the requested pixel (degrees, WGS84).
 */
static inline double mavlink_msg_pixel_to_lla_result_get_longitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_double(msg,  16);
}

/**
 * @brief Get field altitude from pixel_to_lla_result message
 *
 * @return [m] Altitude of the requested pixel (meters, WGS84 ellipsoid).
 */
static inline double mavlink_msg_pixel_to_lla_result_get_altitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_double(msg,  24);
}

/**
 * @brief Get field ned_homography_matrix from pixel_to_lla_result message
 *
 * @return  3x3 matrix for NED (North-East-Down) homography transform of the image. Row-major order.
 */
static inline uint16_t mavlink_msg_pixel_to_lla_result_get_ned_homography_matrix(const mavlink_message_t* msg, float *ned_homography_matrix)
{
    return _MAV_RETURN_float_array(msg, ned_homography_matrix, 9,  32);
}

/**
 * @brief Get field error_message from pixel_to_lla_result message
 *
 * @return  Optional error message in case of failure. Max length 100 characters.
 */
static inline uint16_t mavlink_msg_pixel_to_lla_result_get_error_message(const mavlink_message_t* msg, char *error_message)
{
    return _MAV_RETURN_char_array(msg, error_message, 100,  69);
}

/**
 * @brief Decode a pixel_to_lla_result message into a struct
 *
 * @param msg The message to decode
 * @param pixel_to_lla_result C-struct to decode the message contents into
 */
static inline void mavlink_msg_pixel_to_lla_result_decode(const mavlink_message_t* msg, mavlink_pixel_to_lla_result_t* pixel_to_lla_result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    pixel_to_lla_result->uid = mavlink_msg_pixel_to_lla_result_get_uid(msg);
    pixel_to_lla_result->latitude = mavlink_msg_pixel_to_lla_result_get_latitude(msg);
    pixel_to_lla_result->longitude = mavlink_msg_pixel_to_lla_result_get_longitude(msg);
    pixel_to_lla_result->altitude = mavlink_msg_pixel_to_lla_result_get_altitude(msg);
    mavlink_msg_pixel_to_lla_result_get_ned_homography_matrix(msg, pixel_to_lla_result->ned_homography_matrix);
    pixel_to_lla_result->status = mavlink_msg_pixel_to_lla_result_get_status(msg);
    mavlink_msg_pixel_to_lla_result_get_error_message(msg, pixel_to_lla_result->error_message);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_LEN? msg->len : MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_LEN;
        memset(pixel_to_lla_result, 0, MAVLINK_MSG_ID_PIXEL_TO_LLA_RESULT_LEN);
    memcpy(pixel_to_lla_result, _MAV_PAYLOAD(msg), len);
#endif
}
