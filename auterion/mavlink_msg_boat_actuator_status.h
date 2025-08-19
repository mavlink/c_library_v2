#pragma once
// MESSAGE BOAT_ACTUATOR_STATUS PACKING

#define MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS 13666


typedef struct __mavlink_boat_actuator_status_t {
 uint64_t time_usec; /*< [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.*/
 float engine_leg_trim_position[6]; /*< [deg] Engine leg trim position.*/
 float rudder_position[6]; /*< [deg] Rudder position.*/
 uint8_t engine_leg_trim_state[6]; /*<  Engine leg trim state.*/
 uint8_t rudder_state[6]; /*<  Rudder state.*/
} mavlink_boat_actuator_status_t;

#define MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_LEN 68
#define MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_MIN_LEN 68
#define MAVLINK_MSG_ID_13666_LEN 68
#define MAVLINK_MSG_ID_13666_MIN_LEN 68

#define MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_CRC 246
#define MAVLINK_MSG_ID_13666_CRC 246

#define MAVLINK_MSG_BOAT_ACTUATOR_STATUS_FIELD_ENGINE_LEG_TRIM_POSITION_LEN 6
#define MAVLINK_MSG_BOAT_ACTUATOR_STATUS_FIELD_RUDDER_POSITION_LEN 6
#define MAVLINK_MSG_BOAT_ACTUATOR_STATUS_FIELD_ENGINE_LEG_TRIM_STATE_LEN 6
#define MAVLINK_MSG_BOAT_ACTUATOR_STATUS_FIELD_RUDDER_STATE_LEN 6

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_BOAT_ACTUATOR_STATUS { \
    13666, \
    "BOAT_ACTUATOR_STATUS", \
    5, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_boat_actuator_status_t, time_usec) }, \
         { "engine_leg_trim_state", NULL, MAVLINK_TYPE_UINT8_T, 6, 56, offsetof(mavlink_boat_actuator_status_t, engine_leg_trim_state) }, \
         { "engine_leg_trim_position", NULL, MAVLINK_TYPE_FLOAT, 6, 8, offsetof(mavlink_boat_actuator_status_t, engine_leg_trim_position) }, \
         { "rudder_state", NULL, MAVLINK_TYPE_UINT8_T, 6, 62, offsetof(mavlink_boat_actuator_status_t, rudder_state) }, \
         { "rudder_position", NULL, MAVLINK_TYPE_FLOAT, 6, 32, offsetof(mavlink_boat_actuator_status_t, rudder_position) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_BOAT_ACTUATOR_STATUS { \
    "BOAT_ACTUATOR_STATUS", \
    5, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_boat_actuator_status_t, time_usec) }, \
         { "engine_leg_trim_state", NULL, MAVLINK_TYPE_UINT8_T, 6, 56, offsetof(mavlink_boat_actuator_status_t, engine_leg_trim_state) }, \
         { "engine_leg_trim_position", NULL, MAVLINK_TYPE_FLOAT, 6, 8, offsetof(mavlink_boat_actuator_status_t, engine_leg_trim_position) }, \
         { "rudder_state", NULL, MAVLINK_TYPE_UINT8_T, 6, 62, offsetof(mavlink_boat_actuator_status_t, rudder_state) }, \
         { "rudder_position", NULL, MAVLINK_TYPE_FLOAT, 6, 32, offsetof(mavlink_boat_actuator_status_t, rudder_position) }, \
         } \
}
#endif

/**
 * @brief Pack a boat_actuator_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param engine_leg_trim_state  Engine leg trim state.
 * @param engine_leg_trim_position [deg] Engine leg trim position.
 * @param rudder_state  Rudder state.
 * @param rudder_position [deg] Rudder position.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_boat_actuator_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, const uint8_t *engine_leg_trim_state, const float *engine_leg_trim_position, const uint8_t *rudder_state, const float *rudder_position)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float_array(buf, 8, engine_leg_trim_position, 6);
    _mav_put_float_array(buf, 32, rudder_position, 6);
    _mav_put_uint8_t_array(buf, 56, engine_leg_trim_state, 6);
    _mav_put_uint8_t_array(buf, 62, rudder_state, 6);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_LEN);
#else
    mavlink_boat_actuator_status_t packet;
    packet.time_usec = time_usec;
    mav_array_memcpy(packet.engine_leg_trim_position, engine_leg_trim_position, sizeof(float)*6);
    mav_array_memcpy(packet.rudder_position, rudder_position, sizeof(float)*6);
    mav_array_memcpy(packet.engine_leg_trim_state, engine_leg_trim_state, sizeof(uint8_t)*6);
    mav_array_memcpy(packet.rudder_state, rudder_state, sizeof(uint8_t)*6);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_MIN_LEN, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_LEN, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_CRC);
}

/**
 * @brief Pack a boat_actuator_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param engine_leg_trim_state  Engine leg trim state.
 * @param engine_leg_trim_position [deg] Engine leg trim position.
 * @param rudder_state  Rudder state.
 * @param rudder_position [deg] Rudder position.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_boat_actuator_status_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint64_t time_usec, const uint8_t *engine_leg_trim_state, const float *engine_leg_trim_position, const uint8_t *rudder_state, const float *rudder_position)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float_array(buf, 8, engine_leg_trim_position, 6);
    _mav_put_float_array(buf, 32, rudder_position, 6);
    _mav_put_uint8_t_array(buf, 56, engine_leg_trim_state, 6);
    _mav_put_uint8_t_array(buf, 62, rudder_state, 6);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_LEN);
#else
    mavlink_boat_actuator_status_t packet;
    packet.time_usec = time_usec;
    mav_array_memcpy(packet.engine_leg_trim_position, engine_leg_trim_position, sizeof(float)*6);
    mav_array_memcpy(packet.rudder_position, rudder_position, sizeof(float)*6);
    mav_array_memcpy(packet.engine_leg_trim_state, engine_leg_trim_state, sizeof(uint8_t)*6);
    mav_array_memcpy(packet.rudder_state, rudder_state, sizeof(uint8_t)*6);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_MIN_LEN, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_LEN, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_MIN_LEN, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_LEN);
#endif
}

/**
 * @brief Pack a boat_actuator_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param engine_leg_trim_state  Engine leg trim state.
 * @param engine_leg_trim_position [deg] Engine leg trim position.
 * @param rudder_state  Rudder state.
 * @param rudder_position [deg] Rudder position.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_boat_actuator_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,const uint8_t *engine_leg_trim_state,const float *engine_leg_trim_position,const uint8_t *rudder_state,const float *rudder_position)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float_array(buf, 8, engine_leg_trim_position, 6);
    _mav_put_float_array(buf, 32, rudder_position, 6);
    _mav_put_uint8_t_array(buf, 56, engine_leg_trim_state, 6);
    _mav_put_uint8_t_array(buf, 62, rudder_state, 6);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_LEN);
#else
    mavlink_boat_actuator_status_t packet;
    packet.time_usec = time_usec;
    mav_array_memcpy(packet.engine_leg_trim_position, engine_leg_trim_position, sizeof(float)*6);
    mav_array_memcpy(packet.rudder_position, rudder_position, sizeof(float)*6);
    mav_array_memcpy(packet.engine_leg_trim_state, engine_leg_trim_state, sizeof(uint8_t)*6);
    mav_array_memcpy(packet.rudder_state, rudder_state, sizeof(uint8_t)*6);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_MIN_LEN, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_LEN, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_CRC);
}

/**
 * @brief Encode a boat_actuator_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param boat_actuator_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_boat_actuator_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_boat_actuator_status_t* boat_actuator_status)
{
    return mavlink_msg_boat_actuator_status_pack(system_id, component_id, msg, boat_actuator_status->time_usec, boat_actuator_status->engine_leg_trim_state, boat_actuator_status->engine_leg_trim_position, boat_actuator_status->rudder_state, boat_actuator_status->rudder_position);
}

/**
 * @brief Encode a boat_actuator_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param boat_actuator_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_boat_actuator_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_boat_actuator_status_t* boat_actuator_status)
{
    return mavlink_msg_boat_actuator_status_pack_chan(system_id, component_id, chan, msg, boat_actuator_status->time_usec, boat_actuator_status->engine_leg_trim_state, boat_actuator_status->engine_leg_trim_position, boat_actuator_status->rudder_state, boat_actuator_status->rudder_position);
}

/**
 * @brief Encode a boat_actuator_status struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param boat_actuator_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_boat_actuator_status_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_boat_actuator_status_t* boat_actuator_status)
{
    return mavlink_msg_boat_actuator_status_pack_status(system_id, component_id, _status, msg,  boat_actuator_status->time_usec, boat_actuator_status->engine_leg_trim_state, boat_actuator_status->engine_leg_trim_position, boat_actuator_status->rudder_state, boat_actuator_status->rudder_position);
}

/**
 * @brief Send a boat_actuator_status message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param engine_leg_trim_state  Engine leg trim state.
 * @param engine_leg_trim_position [deg] Engine leg trim position.
 * @param rudder_state  Rudder state.
 * @param rudder_position [deg] Rudder position.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_boat_actuator_status_send(mavlink_channel_t chan, uint64_t time_usec, const uint8_t *engine_leg_trim_state, const float *engine_leg_trim_position, const uint8_t *rudder_state, const float *rudder_position)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float_array(buf, 8, engine_leg_trim_position, 6);
    _mav_put_float_array(buf, 32, rudder_position, 6);
    _mav_put_uint8_t_array(buf, 56, engine_leg_trim_state, 6);
    _mav_put_uint8_t_array(buf, 62, rudder_state, 6);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS, buf, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_MIN_LEN, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_LEN, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_CRC);
#else
    mavlink_boat_actuator_status_t packet;
    packet.time_usec = time_usec;
    mav_array_memcpy(packet.engine_leg_trim_position, engine_leg_trim_position, sizeof(float)*6);
    mav_array_memcpy(packet.rudder_position, rudder_position, sizeof(float)*6);
    mav_array_memcpy(packet.engine_leg_trim_state, engine_leg_trim_state, sizeof(uint8_t)*6);
    mav_array_memcpy(packet.rudder_state, rudder_state, sizeof(uint8_t)*6);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS, (const char *)&packet, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_MIN_LEN, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_LEN, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_CRC);
#endif
}

/**
 * @brief Send a boat_actuator_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_boat_actuator_status_send_struct(mavlink_channel_t chan, const mavlink_boat_actuator_status_t* boat_actuator_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_boat_actuator_status_send(chan, boat_actuator_status->time_usec, boat_actuator_status->engine_leg_trim_state, boat_actuator_status->engine_leg_trim_position, boat_actuator_status->rudder_state, boat_actuator_status->rudder_position);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS, (const char *)boat_actuator_status, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_MIN_LEN, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_LEN, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_boat_actuator_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, const uint8_t *engine_leg_trim_state, const float *engine_leg_trim_position, const uint8_t *rudder_state, const float *rudder_position)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float_array(buf, 8, engine_leg_trim_position, 6);
    _mav_put_float_array(buf, 32, rudder_position, 6);
    _mav_put_uint8_t_array(buf, 56, engine_leg_trim_state, 6);
    _mav_put_uint8_t_array(buf, 62, rudder_state, 6);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS, buf, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_MIN_LEN, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_LEN, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_CRC);
#else
    mavlink_boat_actuator_status_t *packet = (mavlink_boat_actuator_status_t *)msgbuf;
    packet->time_usec = time_usec;
    mav_array_memcpy(packet->engine_leg_trim_position, engine_leg_trim_position, sizeof(float)*6);
    mav_array_memcpy(packet->rudder_position, rudder_position, sizeof(float)*6);
    mav_array_memcpy(packet->engine_leg_trim_state, engine_leg_trim_state, sizeof(uint8_t)*6);
    mav_array_memcpy(packet->rudder_state, rudder_state, sizeof(uint8_t)*6);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS, (const char *)packet, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_MIN_LEN, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_LEN, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE BOAT_ACTUATOR_STATUS UNPACKING


/**
 * @brief Get field time_usec from boat_actuator_status message
 *
 * @return [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 */
static inline uint64_t mavlink_msg_boat_actuator_status_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field engine_leg_trim_state from boat_actuator_status message
 *
 * @return  Engine leg trim state.
 */
static inline uint16_t mavlink_msg_boat_actuator_status_get_engine_leg_trim_state(const mavlink_message_t* msg, uint8_t *engine_leg_trim_state)
{
    return _MAV_RETURN_uint8_t_array(msg, engine_leg_trim_state, 6,  56);
}

/**
 * @brief Get field engine_leg_trim_position from boat_actuator_status message
 *
 * @return [deg] Engine leg trim position.
 */
static inline uint16_t mavlink_msg_boat_actuator_status_get_engine_leg_trim_position(const mavlink_message_t* msg, float *engine_leg_trim_position)
{
    return _MAV_RETURN_float_array(msg, engine_leg_trim_position, 6,  8);
}

/**
 * @brief Get field rudder_state from boat_actuator_status message
 *
 * @return  Rudder state.
 */
static inline uint16_t mavlink_msg_boat_actuator_status_get_rudder_state(const mavlink_message_t* msg, uint8_t *rudder_state)
{
    return _MAV_RETURN_uint8_t_array(msg, rudder_state, 6,  62);
}

/**
 * @brief Get field rudder_position from boat_actuator_status message
 *
 * @return [deg] Rudder position.
 */
static inline uint16_t mavlink_msg_boat_actuator_status_get_rudder_position(const mavlink_message_t* msg, float *rudder_position)
{
    return _MAV_RETURN_float_array(msg, rudder_position, 6,  32);
}

/**
 * @brief Decode a boat_actuator_status message into a struct
 *
 * @param msg The message to decode
 * @param boat_actuator_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_boat_actuator_status_decode(const mavlink_message_t* msg, mavlink_boat_actuator_status_t* boat_actuator_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    boat_actuator_status->time_usec = mavlink_msg_boat_actuator_status_get_time_usec(msg);
    mavlink_msg_boat_actuator_status_get_engine_leg_trim_position(msg, boat_actuator_status->engine_leg_trim_position);
    mavlink_msg_boat_actuator_status_get_rudder_position(msg, boat_actuator_status->rudder_position);
    mavlink_msg_boat_actuator_status_get_engine_leg_trim_state(msg, boat_actuator_status->engine_leg_trim_state);
    mavlink_msg_boat_actuator_status_get_rudder_state(msg, boat_actuator_status->rudder_state);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_LEN? msg->len : MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_LEN;
        memset(boat_actuator_status, 0, MAVLINK_MSG_ID_BOAT_ACTUATOR_STATUS_LEN);
    memcpy(boat_actuator_status, _MAV_PAYLOAD(msg), len);
#endif
}
