#pragma once
// MESSAGE ESTIMATOR_INNOV_COV PACKING

#define MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV 340

MAVPACKED(
typedef struct __mavlink_estimator_innov_cov_t {
 uint64_t time_usec; /*< Timestamp (microseconds since system boot or since UNIX epoch)*/
 float cov[210]; /*< The estimator covariance matrix (upper triangle), horizontally stacked with lengths [n, n-1, n-2, ..., 1]*/
 uint8_t n; /*< Number of innovations, max 21, limited by mavlink protocol*/
 uint8_t id[21]; /*< An array describing field type (see MAV_FIELD)*/
 uint8_t sensor[21]; /*< An array describing the sensor associated with the field (see MAV_SENSOR_TYPE)*/
}) mavlink_estimator_innov_cov_t;

#define MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV_LEN 891
#define MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV_MIN_LEN 891
#define MAVLINK_MSG_ID_340_LEN 891
#define MAVLINK_MSG_ID_340_MIN_LEN 891

#define MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV_CRC 152
#define MAVLINK_MSG_ID_340_CRC 152

#define MAVLINK_MSG_ESTIMATOR_INNOV_COV_FIELD_COV_LEN 210
#define MAVLINK_MSG_ESTIMATOR_INNOV_COV_FIELD_ID_LEN 21
#define MAVLINK_MSG_ESTIMATOR_INNOV_COV_FIELD_SENSOR_LEN 21

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ESTIMATOR_INNOV_COV { \
    340, \
    "ESTIMATOR_INNOV_COV", \
    5, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_estimator_innov_cov_t, time_usec) }, \
         { "n", NULL, MAVLINK_TYPE_UINT8_T, 0, 848, offsetof(mavlink_estimator_innov_cov_t, n) }, \
         { "id", NULL, MAVLINK_TYPE_UINT8_T, 21, 849, offsetof(mavlink_estimator_innov_cov_t, id) }, \
         { "sensor", NULL, MAVLINK_TYPE_UINT8_T, 21, 870, offsetof(mavlink_estimator_innov_cov_t, sensor) }, \
         { "cov", NULL, MAVLINK_TYPE_FLOAT, 210, 8, offsetof(mavlink_estimator_innov_cov_t, cov) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ESTIMATOR_INNOV_COV { \
    "ESTIMATOR_INNOV_COV", \
    5, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_estimator_innov_cov_t, time_usec) }, \
         { "n", NULL, MAVLINK_TYPE_UINT8_T, 0, 848, offsetof(mavlink_estimator_innov_cov_t, n) }, \
         { "id", NULL, MAVLINK_TYPE_UINT8_T, 21, 849, offsetof(mavlink_estimator_innov_cov_t, id) }, \
         { "sensor", NULL, MAVLINK_TYPE_UINT8_T, 21, 870, offsetof(mavlink_estimator_innov_cov_t, sensor) }, \
         { "cov", NULL, MAVLINK_TYPE_FLOAT, 210, 8, offsetof(mavlink_estimator_innov_cov_t, cov) }, \
         } \
}
#endif

/**
 * @brief Pack a estimator_innov_cov message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Timestamp (microseconds since system boot or since UNIX epoch)
 * @param n Number of innovations, max 21, limited by mavlink protocol
 * @param id An array describing field type (see MAV_FIELD)
 * @param sensor An array describing the sensor associated with the field (see MAV_SENSOR_TYPE)
 * @param cov The estimator covariance matrix (upper triangle), horizontally stacked with lengths [n, n-1, n-2, ..., 1]
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_estimator_innov_cov_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, uint8_t n, const uint8_t *id, const uint8_t *sensor, const float *cov)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint8_t(buf, 848, n);
    _mav_put_float_array(buf, 8, cov, 210);
    _mav_put_uint8_t_array(buf, 849, id, 21);
    _mav_put_uint8_t_array(buf, 870, sensor, 21);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV_LEN);
#else
    mavlink_estimator_innov_cov_t packet;
    packet.time_usec = time_usec;
    packet.n = n;
    mav_array_memcpy(packet.cov, cov, sizeof(float)*210);
    mav_array_memcpy(packet.id, id, sizeof(uint8_t)*21);
    mav_array_memcpy(packet.sensor, sensor, sizeof(uint8_t)*21);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV_MIN_LEN, MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV_LEN, MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV_CRC);
}

/**
 * @brief Pack a estimator_innov_cov message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Timestamp (microseconds since system boot or since UNIX epoch)
 * @param n Number of innovations, max 21, limited by mavlink protocol
 * @param id An array describing field type (see MAV_FIELD)
 * @param sensor An array describing the sensor associated with the field (see MAV_SENSOR_TYPE)
 * @param cov The estimator covariance matrix (upper triangle), horizontally stacked with lengths [n, n-1, n-2, ..., 1]
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_estimator_innov_cov_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,uint8_t n,const uint8_t *id,const uint8_t *sensor,const float *cov)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint8_t(buf, 848, n);
    _mav_put_float_array(buf, 8, cov, 210);
    _mav_put_uint8_t_array(buf, 849, id, 21);
    _mav_put_uint8_t_array(buf, 870, sensor, 21);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV_LEN);
#else
    mavlink_estimator_innov_cov_t packet;
    packet.time_usec = time_usec;
    packet.n = n;
    mav_array_memcpy(packet.cov, cov, sizeof(float)*210);
    mav_array_memcpy(packet.id, id, sizeof(uint8_t)*21);
    mav_array_memcpy(packet.sensor, sensor, sizeof(uint8_t)*21);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV_MIN_LEN, MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV_LEN, MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV_CRC);
}

/**
 * @brief Encode a estimator_innov_cov struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param estimator_innov_cov C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_estimator_innov_cov_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_estimator_innov_cov_t* estimator_innov_cov)
{
    return mavlink_msg_estimator_innov_cov_pack(system_id, component_id, msg, estimator_innov_cov->time_usec, estimator_innov_cov->n, estimator_innov_cov->id, estimator_innov_cov->sensor, estimator_innov_cov->cov);
}

/**
 * @brief Encode a estimator_innov_cov struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param estimator_innov_cov C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_estimator_innov_cov_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_estimator_innov_cov_t* estimator_innov_cov)
{
    return mavlink_msg_estimator_innov_cov_pack_chan(system_id, component_id, chan, msg, estimator_innov_cov->time_usec, estimator_innov_cov->n, estimator_innov_cov->id, estimator_innov_cov->sensor, estimator_innov_cov->cov);
}

/**
 * @brief Send a estimator_innov_cov message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec Timestamp (microseconds since system boot or since UNIX epoch)
 * @param n Number of innovations, max 21, limited by mavlink protocol
 * @param id An array describing field type (see MAV_FIELD)
 * @param sensor An array describing the sensor associated with the field (see MAV_SENSOR_TYPE)
 * @param cov The estimator covariance matrix (upper triangle), horizontally stacked with lengths [n, n-1, n-2, ..., 1]
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_estimator_innov_cov_send(mavlink_channel_t chan, uint64_t time_usec, uint8_t n, const uint8_t *id, const uint8_t *sensor, const float *cov)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint8_t(buf, 848, n);
    _mav_put_float_array(buf, 8, cov, 210);
    _mav_put_uint8_t_array(buf, 849, id, 21);
    _mav_put_uint8_t_array(buf, 870, sensor, 21);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV, buf, MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV_MIN_LEN, MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV_LEN, MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV_CRC);
#else
    mavlink_estimator_innov_cov_t packet;
    packet.time_usec = time_usec;
    packet.n = n;
    mav_array_memcpy(packet.cov, cov, sizeof(float)*210);
    mav_array_memcpy(packet.id, id, sizeof(uint8_t)*21);
    mav_array_memcpy(packet.sensor, sensor, sizeof(uint8_t)*21);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV, (const char *)&packet, MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV_MIN_LEN, MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV_LEN, MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV_CRC);
#endif
}

/**
 * @brief Send a estimator_innov_cov message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_estimator_innov_cov_send_struct(mavlink_channel_t chan, const mavlink_estimator_innov_cov_t* estimator_innov_cov)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_estimator_innov_cov_send(chan, estimator_innov_cov->time_usec, estimator_innov_cov->n, estimator_innov_cov->id, estimator_innov_cov->sensor, estimator_innov_cov->cov);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV, (const char *)estimator_innov_cov, MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV_MIN_LEN, MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV_LEN, MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV_CRC);
#endif
}

#if MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_estimator_innov_cov_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, uint8_t n, const uint8_t *id, const uint8_t *sensor, const float *cov)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint8_t(buf, 848, n);
    _mav_put_float_array(buf, 8, cov, 210);
    _mav_put_uint8_t_array(buf, 849, id, 21);
    _mav_put_uint8_t_array(buf, 870, sensor, 21);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV, buf, MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV_MIN_LEN, MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV_LEN, MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV_CRC);
#else
    mavlink_estimator_innov_cov_t *packet = (mavlink_estimator_innov_cov_t *)msgbuf;
    packet->time_usec = time_usec;
    packet->n = n;
    mav_array_memcpy(packet->cov, cov, sizeof(float)*210);
    mav_array_memcpy(packet->id, id, sizeof(uint8_t)*21);
    mav_array_memcpy(packet->sensor, sensor, sizeof(uint8_t)*21);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV, (const char *)packet, MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV_MIN_LEN, MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV_LEN, MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV_CRC);
#endif
}
#endif

#endif

// MESSAGE ESTIMATOR_INNOV_COV UNPACKING


/**
 * @brief Get field time_usec from estimator_innov_cov message
 *
 * @return Timestamp (microseconds since system boot or since UNIX epoch)
 */
static inline uint64_t mavlink_msg_estimator_innov_cov_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field n from estimator_innov_cov message
 *
 * @return Number of innovations, max 21, limited by mavlink protocol
 */
static inline uint8_t mavlink_msg_estimator_innov_cov_get_n(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  848);
}

/**
 * @brief Get field id from estimator_innov_cov message
 *
 * @return An array describing field type (see MAV_FIELD)
 */
static inline uint16_t mavlink_msg_estimator_innov_cov_get_id(const mavlink_message_t* msg, uint8_t *id)
{
    return _MAV_RETURN_uint8_t_array(msg, id, 21,  849);
}

/**
 * @brief Get field sensor from estimator_innov_cov message
 *
 * @return An array describing the sensor associated with the field (see MAV_SENSOR_TYPE)
 */
static inline uint16_t mavlink_msg_estimator_innov_cov_get_sensor(const mavlink_message_t* msg, uint8_t *sensor)
{
    return _MAV_RETURN_uint8_t_array(msg, sensor, 21,  870);
}

/**
 * @brief Get field cov from estimator_innov_cov message
 *
 * @return The estimator covariance matrix (upper triangle), horizontally stacked with lengths [n, n-1, n-2, ..., 1]
 */
static inline uint16_t mavlink_msg_estimator_innov_cov_get_cov(const mavlink_message_t* msg, float *cov)
{
    return _MAV_RETURN_float_array(msg, cov, 210,  8);
}

/**
 * @brief Decode a estimator_innov_cov message into a struct
 *
 * @param msg The message to decode
 * @param estimator_innov_cov C-struct to decode the message contents into
 */
static inline void mavlink_msg_estimator_innov_cov_decode(const mavlink_message_t* msg, mavlink_estimator_innov_cov_t* estimator_innov_cov)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    estimator_innov_cov->time_usec = mavlink_msg_estimator_innov_cov_get_time_usec(msg);
    mavlink_msg_estimator_innov_cov_get_cov(msg, estimator_innov_cov->cov);
    estimator_innov_cov->n = mavlink_msg_estimator_innov_cov_get_n(msg);
    mavlink_msg_estimator_innov_cov_get_id(msg, estimator_innov_cov->id);
    mavlink_msg_estimator_innov_cov_get_sensor(msg, estimator_innov_cov->sensor);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV_LEN? msg->len : MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV_LEN;
        memset(estimator_innov_cov, 0, MAVLINK_MSG_ID_ESTIMATOR_INNOV_COV_LEN);
    memcpy(estimator_innov_cov, _MAV_PAYLOAD(msg), len);
#endif
}
