#pragma once
// MESSAGE ESTIMATOR_STATE PACKING

#define MAVLINK_MSG_ID_ESTIMATOR_STATE 335

MAVPACKED(
typedef struct __mavlink_estimator_state_t {
 uint64_t time_usec; /*< Timestamp (microseconds since system boot or since UNIX epoch)*/
 float state[30]; /*< The estimator state*/
 uint8_t n; /*< Number of states, max 30*/
 uint8_t id[30]; /*< An array describing field type (see MAV_FIELD)*/
 uint8_t sensor[30]; /*< An array describing the sensor associated with the field (see MAV_SENSOR_TYPE)*/
}) mavlink_estimator_state_t;

#define MAVLINK_MSG_ID_ESTIMATOR_STATE_LEN 189
#define MAVLINK_MSG_ID_ESTIMATOR_STATE_MIN_LEN 189
#define MAVLINK_MSG_ID_335_LEN 189
#define MAVLINK_MSG_ID_335_MIN_LEN 189

#define MAVLINK_MSG_ID_ESTIMATOR_STATE_CRC 186
#define MAVLINK_MSG_ID_335_CRC 186

#define MAVLINK_MSG_ESTIMATOR_STATE_FIELD_STATE_LEN 30
#define MAVLINK_MSG_ESTIMATOR_STATE_FIELD_ID_LEN 30
#define MAVLINK_MSG_ESTIMATOR_STATE_FIELD_SENSOR_LEN 30

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ESTIMATOR_STATE { \
    335, \
    "ESTIMATOR_STATE", \
    5, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_estimator_state_t, time_usec) }, \
         { "n", NULL, MAVLINK_TYPE_UINT8_T, 0, 128, offsetof(mavlink_estimator_state_t, n) }, \
         { "id", NULL, MAVLINK_TYPE_UINT8_T, 30, 129, offsetof(mavlink_estimator_state_t, id) }, \
         { "sensor", NULL, MAVLINK_TYPE_UINT8_T, 30, 159, offsetof(mavlink_estimator_state_t, sensor) }, \
         { "state", NULL, MAVLINK_TYPE_FLOAT, 30, 8, offsetof(mavlink_estimator_state_t, state) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ESTIMATOR_STATE { \
    "ESTIMATOR_STATE", \
    5, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_estimator_state_t, time_usec) }, \
         { "n", NULL, MAVLINK_TYPE_UINT8_T, 0, 128, offsetof(mavlink_estimator_state_t, n) }, \
         { "id", NULL, MAVLINK_TYPE_UINT8_T, 30, 129, offsetof(mavlink_estimator_state_t, id) }, \
         { "sensor", NULL, MAVLINK_TYPE_UINT8_T, 30, 159, offsetof(mavlink_estimator_state_t, sensor) }, \
         { "state", NULL, MAVLINK_TYPE_FLOAT, 30, 8, offsetof(mavlink_estimator_state_t, state) }, \
         } \
}
#endif

/**
 * @brief Pack a estimator_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Timestamp (microseconds since system boot or since UNIX epoch)
 * @param n Number of states, max 30
 * @param id An array describing field type (see MAV_FIELD)
 * @param sensor An array describing the sensor associated with the field (see MAV_SENSOR_TYPE)
 * @param state The estimator state
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_estimator_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, uint8_t n, const uint8_t *id, const uint8_t *sensor, const float *state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESTIMATOR_STATE_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint8_t(buf, 128, n);
    _mav_put_float_array(buf, 8, state, 30);
    _mav_put_uint8_t_array(buf, 129, id, 30);
    _mav_put_uint8_t_array(buf, 159, sensor, 30);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ESTIMATOR_STATE_LEN);
#else
    mavlink_estimator_state_t packet;
    packet.time_usec = time_usec;
    packet.n = n;
    mav_array_memcpy(packet.state, state, sizeof(float)*30);
    mav_array_memcpy(packet.id, id, sizeof(uint8_t)*30);
    mav_array_memcpy(packet.sensor, sensor, sizeof(uint8_t)*30);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ESTIMATOR_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ESTIMATOR_STATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ESTIMATOR_STATE_MIN_LEN, MAVLINK_MSG_ID_ESTIMATOR_STATE_LEN, MAVLINK_MSG_ID_ESTIMATOR_STATE_CRC);
}

/**
 * @brief Pack a estimator_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Timestamp (microseconds since system boot or since UNIX epoch)
 * @param n Number of states, max 30
 * @param id An array describing field type (see MAV_FIELD)
 * @param sensor An array describing the sensor associated with the field (see MAV_SENSOR_TYPE)
 * @param state The estimator state
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_estimator_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,uint8_t n,const uint8_t *id,const uint8_t *sensor,const float *state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESTIMATOR_STATE_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint8_t(buf, 128, n);
    _mav_put_float_array(buf, 8, state, 30);
    _mav_put_uint8_t_array(buf, 129, id, 30);
    _mav_put_uint8_t_array(buf, 159, sensor, 30);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ESTIMATOR_STATE_LEN);
#else
    mavlink_estimator_state_t packet;
    packet.time_usec = time_usec;
    packet.n = n;
    mav_array_memcpy(packet.state, state, sizeof(float)*30);
    mav_array_memcpy(packet.id, id, sizeof(uint8_t)*30);
    mav_array_memcpy(packet.sensor, sensor, sizeof(uint8_t)*30);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ESTIMATOR_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ESTIMATOR_STATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ESTIMATOR_STATE_MIN_LEN, MAVLINK_MSG_ID_ESTIMATOR_STATE_LEN, MAVLINK_MSG_ID_ESTIMATOR_STATE_CRC);
}

/**
 * @brief Encode a estimator_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param estimator_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_estimator_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_estimator_state_t* estimator_state)
{
    return mavlink_msg_estimator_state_pack(system_id, component_id, msg, estimator_state->time_usec, estimator_state->n, estimator_state->id, estimator_state->sensor, estimator_state->state);
}

/**
 * @brief Encode a estimator_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param estimator_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_estimator_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_estimator_state_t* estimator_state)
{
    return mavlink_msg_estimator_state_pack_chan(system_id, component_id, chan, msg, estimator_state->time_usec, estimator_state->n, estimator_state->id, estimator_state->sensor, estimator_state->state);
}

/**
 * @brief Send a estimator_state message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec Timestamp (microseconds since system boot or since UNIX epoch)
 * @param n Number of states, max 30
 * @param id An array describing field type (see MAV_FIELD)
 * @param sensor An array describing the sensor associated with the field (see MAV_SENSOR_TYPE)
 * @param state The estimator state
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_estimator_state_send(mavlink_channel_t chan, uint64_t time_usec, uint8_t n, const uint8_t *id, const uint8_t *sensor, const float *state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESTIMATOR_STATE_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint8_t(buf, 128, n);
    _mav_put_float_array(buf, 8, state, 30);
    _mav_put_uint8_t_array(buf, 129, id, 30);
    _mav_put_uint8_t_array(buf, 159, sensor, 30);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESTIMATOR_STATE, buf, MAVLINK_MSG_ID_ESTIMATOR_STATE_MIN_LEN, MAVLINK_MSG_ID_ESTIMATOR_STATE_LEN, MAVLINK_MSG_ID_ESTIMATOR_STATE_CRC);
#else
    mavlink_estimator_state_t packet;
    packet.time_usec = time_usec;
    packet.n = n;
    mav_array_memcpy(packet.state, state, sizeof(float)*30);
    mav_array_memcpy(packet.id, id, sizeof(uint8_t)*30);
    mav_array_memcpy(packet.sensor, sensor, sizeof(uint8_t)*30);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESTIMATOR_STATE, (const char *)&packet, MAVLINK_MSG_ID_ESTIMATOR_STATE_MIN_LEN, MAVLINK_MSG_ID_ESTIMATOR_STATE_LEN, MAVLINK_MSG_ID_ESTIMATOR_STATE_CRC);
#endif
}

/**
 * @brief Send a estimator_state message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_estimator_state_send_struct(mavlink_channel_t chan, const mavlink_estimator_state_t* estimator_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_estimator_state_send(chan, estimator_state->time_usec, estimator_state->n, estimator_state->id, estimator_state->sensor, estimator_state->state);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESTIMATOR_STATE, (const char *)estimator_state, MAVLINK_MSG_ID_ESTIMATOR_STATE_MIN_LEN, MAVLINK_MSG_ID_ESTIMATOR_STATE_LEN, MAVLINK_MSG_ID_ESTIMATOR_STATE_CRC);
#endif
}

#if MAVLINK_MSG_ID_ESTIMATOR_STATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_estimator_state_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, uint8_t n, const uint8_t *id, const uint8_t *sensor, const float *state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint8_t(buf, 128, n);
    _mav_put_float_array(buf, 8, state, 30);
    _mav_put_uint8_t_array(buf, 129, id, 30);
    _mav_put_uint8_t_array(buf, 159, sensor, 30);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESTIMATOR_STATE, buf, MAVLINK_MSG_ID_ESTIMATOR_STATE_MIN_LEN, MAVLINK_MSG_ID_ESTIMATOR_STATE_LEN, MAVLINK_MSG_ID_ESTIMATOR_STATE_CRC);
#else
    mavlink_estimator_state_t *packet = (mavlink_estimator_state_t *)msgbuf;
    packet->time_usec = time_usec;
    packet->n = n;
    mav_array_memcpy(packet->state, state, sizeof(float)*30);
    mav_array_memcpy(packet->id, id, sizeof(uint8_t)*30);
    mav_array_memcpy(packet->sensor, sensor, sizeof(uint8_t)*30);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESTIMATOR_STATE, (const char *)packet, MAVLINK_MSG_ID_ESTIMATOR_STATE_MIN_LEN, MAVLINK_MSG_ID_ESTIMATOR_STATE_LEN, MAVLINK_MSG_ID_ESTIMATOR_STATE_CRC);
#endif
}
#endif

#endif

// MESSAGE ESTIMATOR_STATE UNPACKING


/**
 * @brief Get field time_usec from estimator_state message
 *
 * @return Timestamp (microseconds since system boot or since UNIX epoch)
 */
static inline uint64_t mavlink_msg_estimator_state_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field n from estimator_state message
 *
 * @return Number of states, max 30
 */
static inline uint8_t mavlink_msg_estimator_state_get_n(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  128);
}

/**
 * @brief Get field id from estimator_state message
 *
 * @return An array describing field type (see MAV_FIELD)
 */
static inline uint16_t mavlink_msg_estimator_state_get_id(const mavlink_message_t* msg, uint8_t *id)
{
    return _MAV_RETURN_uint8_t_array(msg, id, 30,  129);
}

/**
 * @brief Get field sensor from estimator_state message
 *
 * @return An array describing the sensor associated with the field (see MAV_SENSOR_TYPE)
 */
static inline uint16_t mavlink_msg_estimator_state_get_sensor(const mavlink_message_t* msg, uint8_t *sensor)
{
    return _MAV_RETURN_uint8_t_array(msg, sensor, 30,  159);
}

/**
 * @brief Get field state from estimator_state message
 *
 * @return The estimator state
 */
static inline uint16_t mavlink_msg_estimator_state_get_state(const mavlink_message_t* msg, float *state)
{
    return _MAV_RETURN_float_array(msg, state, 30,  8);
}

/**
 * @brief Decode a estimator_state message into a struct
 *
 * @param msg The message to decode
 * @param estimator_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_estimator_state_decode(const mavlink_message_t* msg, mavlink_estimator_state_t* estimator_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    estimator_state->time_usec = mavlink_msg_estimator_state_get_time_usec(msg);
    mavlink_msg_estimator_state_get_state(msg, estimator_state->state);
    estimator_state->n = mavlink_msg_estimator_state_get_n(msg);
    mavlink_msg_estimator_state_get_id(msg, estimator_state->id);
    mavlink_msg_estimator_state_get_sensor(msg, estimator_state->sensor);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ESTIMATOR_STATE_LEN? msg->len : MAVLINK_MSG_ID_ESTIMATOR_STATE_LEN;
        memset(estimator_state, 0, MAVLINK_MSG_ID_ESTIMATOR_STATE_LEN);
    memcpy(estimator_state, _MAV_PAYLOAD(msg), len);
#endif
}
