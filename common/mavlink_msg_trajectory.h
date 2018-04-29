#pragma once
// MESSAGE TRAJECTORY PACKING

#define MAVLINK_MSG_ID_TRAJECTORY 332

MAVPACKED(
typedef struct __mavlink_trajectory_t {
 uint64_t time_usec; /*< Timestamp (microseconds since system boot or since UNIX epoch).*/
 float point_1[11]; /*< Depending on the type (see MAV_TRAJECTORY_REPRESENTATION)*/
 float point_2[11]; /*< Depending on the type (see MAV_TRAJECTORY_REPRESENTATION)*/
 float point_3[11]; /*< Depending on the type (see MAV_TRAJECTORY_REPRESENTATION)*/
 float point_4[11]; /*< Depending on the type (see MAV_TRAJECTORY_REPRESENTATION)*/
 float point_5[11]; /*< Depending on the type (see MAV_TRAJECTORY_REPRESENTATION)*/
 uint8_t type; /*< Waypoints, Bezier etc. see MAV_TRAJECTORY_REPRESENTATION*/
 uint8_t point_valid[5]; /*< States if respective point is valid (boolean)*/
}) mavlink_trajectory_t;

#define MAVLINK_MSG_ID_TRAJECTORY_LEN 234
#define MAVLINK_MSG_ID_TRAJECTORY_MIN_LEN 234
#define MAVLINK_MSG_ID_332_LEN 234
#define MAVLINK_MSG_ID_332_MIN_LEN 234

#define MAVLINK_MSG_ID_TRAJECTORY_CRC 131
#define MAVLINK_MSG_ID_332_CRC 131

#define MAVLINK_MSG_TRAJECTORY_FIELD_POINT_1_LEN 11
#define MAVLINK_MSG_TRAJECTORY_FIELD_POINT_2_LEN 11
#define MAVLINK_MSG_TRAJECTORY_FIELD_POINT_3_LEN 11
#define MAVLINK_MSG_TRAJECTORY_FIELD_POINT_4_LEN 11
#define MAVLINK_MSG_TRAJECTORY_FIELD_POINT_5_LEN 11
#define MAVLINK_MSG_TRAJECTORY_FIELD_POINT_VALID_LEN 5

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TRAJECTORY { \
    332, \
    "TRAJECTORY", \
    8, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_trajectory_t, time_usec) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 228, offsetof(mavlink_trajectory_t, type) }, \
         { "point_1", NULL, MAVLINK_TYPE_FLOAT, 11, 8, offsetof(mavlink_trajectory_t, point_1) }, \
         { "point_2", NULL, MAVLINK_TYPE_FLOAT, 11, 52, offsetof(mavlink_trajectory_t, point_2) }, \
         { "point_3", NULL, MAVLINK_TYPE_FLOAT, 11, 96, offsetof(mavlink_trajectory_t, point_3) }, \
         { "point_4", NULL, MAVLINK_TYPE_FLOAT, 11, 140, offsetof(mavlink_trajectory_t, point_4) }, \
         { "point_5", NULL, MAVLINK_TYPE_FLOAT, 11, 184, offsetof(mavlink_trajectory_t, point_5) }, \
         { "point_valid", NULL, MAVLINK_TYPE_UINT8_T, 5, 229, offsetof(mavlink_trajectory_t, point_valid) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TRAJECTORY { \
    "TRAJECTORY", \
    8, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_trajectory_t, time_usec) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 228, offsetof(mavlink_trajectory_t, type) }, \
         { "point_1", NULL, MAVLINK_TYPE_FLOAT, 11, 8, offsetof(mavlink_trajectory_t, point_1) }, \
         { "point_2", NULL, MAVLINK_TYPE_FLOAT, 11, 52, offsetof(mavlink_trajectory_t, point_2) }, \
         { "point_3", NULL, MAVLINK_TYPE_FLOAT, 11, 96, offsetof(mavlink_trajectory_t, point_3) }, \
         { "point_4", NULL, MAVLINK_TYPE_FLOAT, 11, 140, offsetof(mavlink_trajectory_t, point_4) }, \
         { "point_5", NULL, MAVLINK_TYPE_FLOAT, 11, 184, offsetof(mavlink_trajectory_t, point_5) }, \
         { "point_valid", NULL, MAVLINK_TYPE_UINT8_T, 5, 229, offsetof(mavlink_trajectory_t, point_valid) }, \
         } \
}
#endif

/**
 * @brief Pack a trajectory message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Timestamp (microseconds since system boot or since UNIX epoch).
 * @param type Waypoints, Bezier etc. see MAV_TRAJECTORY_REPRESENTATION
 * @param point_1 Depending on the type (see MAV_TRAJECTORY_REPRESENTATION)
 * @param point_2 Depending on the type (see MAV_TRAJECTORY_REPRESENTATION)
 * @param point_3 Depending on the type (see MAV_TRAJECTORY_REPRESENTATION)
 * @param point_4 Depending on the type (see MAV_TRAJECTORY_REPRESENTATION)
 * @param point_5 Depending on the type (see MAV_TRAJECTORY_REPRESENTATION)
 * @param point_valid States if respective point is valid (boolean)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_trajectory_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, uint8_t type, const float *point_1, const float *point_2, const float *point_3, const float *point_4, const float *point_5, const uint8_t *point_valid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TRAJECTORY_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint8_t(buf, 228, type);
    _mav_put_float_array(buf, 8, point_1, 11);
    _mav_put_float_array(buf, 52, point_2, 11);
    _mav_put_float_array(buf, 96, point_3, 11);
    _mav_put_float_array(buf, 140, point_4, 11);
    _mav_put_float_array(buf, 184, point_5, 11);
    _mav_put_uint8_t_array(buf, 229, point_valid, 5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TRAJECTORY_LEN);
#else
    mavlink_trajectory_t packet;
    packet.time_usec = time_usec;
    packet.type = type;
    mav_array_memcpy(packet.point_1, point_1, sizeof(float)*11);
    mav_array_memcpy(packet.point_2, point_2, sizeof(float)*11);
    mav_array_memcpy(packet.point_3, point_3, sizeof(float)*11);
    mav_array_memcpy(packet.point_4, point_4, sizeof(float)*11);
    mav_array_memcpy(packet.point_5, point_5, sizeof(float)*11);
    mav_array_memcpy(packet.point_valid, point_valid, sizeof(uint8_t)*5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TRAJECTORY_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TRAJECTORY;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TRAJECTORY_MIN_LEN, MAVLINK_MSG_ID_TRAJECTORY_LEN, MAVLINK_MSG_ID_TRAJECTORY_CRC);
}

/**
 * @brief Pack a trajectory message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Timestamp (microseconds since system boot or since UNIX epoch).
 * @param type Waypoints, Bezier etc. see MAV_TRAJECTORY_REPRESENTATION
 * @param point_1 Depending on the type (see MAV_TRAJECTORY_REPRESENTATION)
 * @param point_2 Depending on the type (see MAV_TRAJECTORY_REPRESENTATION)
 * @param point_3 Depending on the type (see MAV_TRAJECTORY_REPRESENTATION)
 * @param point_4 Depending on the type (see MAV_TRAJECTORY_REPRESENTATION)
 * @param point_5 Depending on the type (see MAV_TRAJECTORY_REPRESENTATION)
 * @param point_valid States if respective point is valid (boolean)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_trajectory_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,uint8_t type,const float *point_1,const float *point_2,const float *point_3,const float *point_4,const float *point_5,const uint8_t *point_valid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TRAJECTORY_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint8_t(buf, 228, type);
    _mav_put_float_array(buf, 8, point_1, 11);
    _mav_put_float_array(buf, 52, point_2, 11);
    _mav_put_float_array(buf, 96, point_3, 11);
    _mav_put_float_array(buf, 140, point_4, 11);
    _mav_put_float_array(buf, 184, point_5, 11);
    _mav_put_uint8_t_array(buf, 229, point_valid, 5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TRAJECTORY_LEN);
#else
    mavlink_trajectory_t packet;
    packet.time_usec = time_usec;
    packet.type = type;
    mav_array_memcpy(packet.point_1, point_1, sizeof(float)*11);
    mav_array_memcpy(packet.point_2, point_2, sizeof(float)*11);
    mav_array_memcpy(packet.point_3, point_3, sizeof(float)*11);
    mav_array_memcpy(packet.point_4, point_4, sizeof(float)*11);
    mav_array_memcpy(packet.point_5, point_5, sizeof(float)*11);
    mav_array_memcpy(packet.point_valid, point_valid, sizeof(uint8_t)*5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TRAJECTORY_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TRAJECTORY;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TRAJECTORY_MIN_LEN, MAVLINK_MSG_ID_TRAJECTORY_LEN, MAVLINK_MSG_ID_TRAJECTORY_CRC);
}

/**
 * @brief Encode a trajectory struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param trajectory C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_trajectory_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_trajectory_t* trajectory)
{
    return mavlink_msg_trajectory_pack(system_id, component_id, msg, trajectory->time_usec, trajectory->type, trajectory->point_1, trajectory->point_2, trajectory->point_3, trajectory->point_4, trajectory->point_5, trajectory->point_valid);
}

/**
 * @brief Encode a trajectory struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param trajectory C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_trajectory_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_trajectory_t* trajectory)
{
    return mavlink_msg_trajectory_pack_chan(system_id, component_id, chan, msg, trajectory->time_usec, trajectory->type, trajectory->point_1, trajectory->point_2, trajectory->point_3, trajectory->point_4, trajectory->point_5, trajectory->point_valid);
}

/**
 * @brief Send a trajectory message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec Timestamp (microseconds since system boot or since UNIX epoch).
 * @param type Waypoints, Bezier etc. see MAV_TRAJECTORY_REPRESENTATION
 * @param point_1 Depending on the type (see MAV_TRAJECTORY_REPRESENTATION)
 * @param point_2 Depending on the type (see MAV_TRAJECTORY_REPRESENTATION)
 * @param point_3 Depending on the type (see MAV_TRAJECTORY_REPRESENTATION)
 * @param point_4 Depending on the type (see MAV_TRAJECTORY_REPRESENTATION)
 * @param point_5 Depending on the type (see MAV_TRAJECTORY_REPRESENTATION)
 * @param point_valid States if respective point is valid (boolean)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_trajectory_send(mavlink_channel_t chan, uint64_t time_usec, uint8_t type, const float *point_1, const float *point_2, const float *point_3, const float *point_4, const float *point_5, const uint8_t *point_valid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TRAJECTORY_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint8_t(buf, 228, type);
    _mav_put_float_array(buf, 8, point_1, 11);
    _mav_put_float_array(buf, 52, point_2, 11);
    _mav_put_float_array(buf, 96, point_3, 11);
    _mav_put_float_array(buf, 140, point_4, 11);
    _mav_put_float_array(buf, 184, point_5, 11);
    _mav_put_uint8_t_array(buf, 229, point_valid, 5);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRAJECTORY, buf, MAVLINK_MSG_ID_TRAJECTORY_MIN_LEN, MAVLINK_MSG_ID_TRAJECTORY_LEN, MAVLINK_MSG_ID_TRAJECTORY_CRC);
#else
    mavlink_trajectory_t packet;
    packet.time_usec = time_usec;
    packet.type = type;
    mav_array_memcpy(packet.point_1, point_1, sizeof(float)*11);
    mav_array_memcpy(packet.point_2, point_2, sizeof(float)*11);
    mav_array_memcpy(packet.point_3, point_3, sizeof(float)*11);
    mav_array_memcpy(packet.point_4, point_4, sizeof(float)*11);
    mav_array_memcpy(packet.point_5, point_5, sizeof(float)*11);
    mav_array_memcpy(packet.point_valid, point_valid, sizeof(uint8_t)*5);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRAJECTORY, (const char *)&packet, MAVLINK_MSG_ID_TRAJECTORY_MIN_LEN, MAVLINK_MSG_ID_TRAJECTORY_LEN, MAVLINK_MSG_ID_TRAJECTORY_CRC);
#endif
}

/**
 * @brief Send a trajectory message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_trajectory_send_struct(mavlink_channel_t chan, const mavlink_trajectory_t* trajectory)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_trajectory_send(chan, trajectory->time_usec, trajectory->type, trajectory->point_1, trajectory->point_2, trajectory->point_3, trajectory->point_4, trajectory->point_5, trajectory->point_valid);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRAJECTORY, (const char *)trajectory, MAVLINK_MSG_ID_TRAJECTORY_MIN_LEN, MAVLINK_MSG_ID_TRAJECTORY_LEN, MAVLINK_MSG_ID_TRAJECTORY_CRC);
#endif
}

#if MAVLINK_MSG_ID_TRAJECTORY_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_trajectory_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, uint8_t type, const float *point_1, const float *point_2, const float *point_3, const float *point_4, const float *point_5, const uint8_t *point_valid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint8_t(buf, 228, type);
    _mav_put_float_array(buf, 8, point_1, 11);
    _mav_put_float_array(buf, 52, point_2, 11);
    _mav_put_float_array(buf, 96, point_3, 11);
    _mav_put_float_array(buf, 140, point_4, 11);
    _mav_put_float_array(buf, 184, point_5, 11);
    _mav_put_uint8_t_array(buf, 229, point_valid, 5);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRAJECTORY, buf, MAVLINK_MSG_ID_TRAJECTORY_MIN_LEN, MAVLINK_MSG_ID_TRAJECTORY_LEN, MAVLINK_MSG_ID_TRAJECTORY_CRC);
#else
    mavlink_trajectory_t *packet = (mavlink_trajectory_t *)msgbuf;
    packet->time_usec = time_usec;
    packet->type = type;
    mav_array_memcpy(packet->point_1, point_1, sizeof(float)*11);
    mav_array_memcpy(packet->point_2, point_2, sizeof(float)*11);
    mav_array_memcpy(packet->point_3, point_3, sizeof(float)*11);
    mav_array_memcpy(packet->point_4, point_4, sizeof(float)*11);
    mav_array_memcpy(packet->point_5, point_5, sizeof(float)*11);
    mav_array_memcpy(packet->point_valid, point_valid, sizeof(uint8_t)*5);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRAJECTORY, (const char *)packet, MAVLINK_MSG_ID_TRAJECTORY_MIN_LEN, MAVLINK_MSG_ID_TRAJECTORY_LEN, MAVLINK_MSG_ID_TRAJECTORY_CRC);
#endif
}
#endif

#endif

// MESSAGE TRAJECTORY UNPACKING


/**
 * @brief Get field time_usec from trajectory message
 *
 * @return Timestamp (microseconds since system boot or since UNIX epoch).
 */
static inline uint64_t mavlink_msg_trajectory_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field type from trajectory message
 *
 * @return Waypoints, Bezier etc. see MAV_TRAJECTORY_REPRESENTATION
 */
static inline uint8_t mavlink_msg_trajectory_get_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  228);
}

/**
 * @brief Get field point_1 from trajectory message
 *
 * @return Depending on the type (see MAV_TRAJECTORY_REPRESENTATION)
 */
static inline uint16_t mavlink_msg_trajectory_get_point_1(const mavlink_message_t* msg, float *point_1)
{
    return _MAV_RETURN_float_array(msg, point_1, 11,  8);
}

/**
 * @brief Get field point_2 from trajectory message
 *
 * @return Depending on the type (see MAV_TRAJECTORY_REPRESENTATION)
 */
static inline uint16_t mavlink_msg_trajectory_get_point_2(const mavlink_message_t* msg, float *point_2)
{
    return _MAV_RETURN_float_array(msg, point_2, 11,  52);
}

/**
 * @brief Get field point_3 from trajectory message
 *
 * @return Depending on the type (see MAV_TRAJECTORY_REPRESENTATION)
 */
static inline uint16_t mavlink_msg_trajectory_get_point_3(const mavlink_message_t* msg, float *point_3)
{
    return _MAV_RETURN_float_array(msg, point_3, 11,  96);
}

/**
 * @brief Get field point_4 from trajectory message
 *
 * @return Depending on the type (see MAV_TRAJECTORY_REPRESENTATION)
 */
static inline uint16_t mavlink_msg_trajectory_get_point_4(const mavlink_message_t* msg, float *point_4)
{
    return _MAV_RETURN_float_array(msg, point_4, 11,  140);
}

/**
 * @brief Get field point_5 from trajectory message
 *
 * @return Depending on the type (see MAV_TRAJECTORY_REPRESENTATION)
 */
static inline uint16_t mavlink_msg_trajectory_get_point_5(const mavlink_message_t* msg, float *point_5)
{
    return _MAV_RETURN_float_array(msg, point_5, 11,  184);
}

/**
 * @brief Get field point_valid from trajectory message
 *
 * @return States if respective point is valid (boolean)
 */
static inline uint16_t mavlink_msg_trajectory_get_point_valid(const mavlink_message_t* msg, uint8_t *point_valid)
{
    return _MAV_RETURN_uint8_t_array(msg, point_valid, 5,  229);
}

/**
 * @brief Decode a trajectory message into a struct
 *
 * @param msg The message to decode
 * @param trajectory C-struct to decode the message contents into
 */
static inline void mavlink_msg_trajectory_decode(const mavlink_message_t* msg, mavlink_trajectory_t* trajectory)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    trajectory->time_usec = mavlink_msg_trajectory_get_time_usec(msg);
    mavlink_msg_trajectory_get_point_1(msg, trajectory->point_1);
    mavlink_msg_trajectory_get_point_2(msg, trajectory->point_2);
    mavlink_msg_trajectory_get_point_3(msg, trajectory->point_3);
    mavlink_msg_trajectory_get_point_4(msg, trajectory->point_4);
    mavlink_msg_trajectory_get_point_5(msg, trajectory->point_5);
    trajectory->type = mavlink_msg_trajectory_get_type(msg);
    mavlink_msg_trajectory_get_point_valid(msg, trajectory->point_valid);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TRAJECTORY_LEN? msg->len : MAVLINK_MSG_ID_TRAJECTORY_LEN;
        memset(trajectory, 0, MAVLINK_MSG_ID_TRAJECTORY_LEN);
    memcpy(trajectory, _MAV_PAYLOAD(msg), len);
#endif
}
