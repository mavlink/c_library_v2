#pragma once
// MESSAGE TILT_STATUS PACKING

#define MAVLINK_MSG_ID_TILT_STATUS 514


typedef struct __mavlink_tilt_status_t {
 uint32_t time_boot_ms; /*< [ms] Timestamp (time since system boot).*/
 float angle[4]; /*< [deg] Actual angle of each motor.*/
 float angular_vel[4]; /*< [deg/s] Actual angular velocity of each motor.*/
 float voltage[4]; /*< [V] Actual voltage of each motor.*/
 int32_t current[4]; /*< [mA] Actual current of each motor.*/
 float temperature[4]; /*< [degC] Actual temperature of each motor.*/
 uint16_t realtime_tick[4]; /*<  Realtime tick value for each motor.*/
 uint8_t error_status[4]; /*<  Error status for each motor.*/
} mavlink_tilt_status_t;

#define MAVLINK_MSG_ID_TILT_STATUS_LEN 96
#define MAVLINK_MSG_ID_TILT_STATUS_MIN_LEN 96
#define MAVLINK_MSG_ID_514_LEN 96
#define MAVLINK_MSG_ID_514_MIN_LEN 96

#define MAVLINK_MSG_ID_TILT_STATUS_CRC 175
#define MAVLINK_MSG_ID_514_CRC 175

#define MAVLINK_MSG_TILT_STATUS_FIELD_ANGLE_LEN 4
#define MAVLINK_MSG_TILT_STATUS_FIELD_ANGULAR_VEL_LEN 4
#define MAVLINK_MSG_TILT_STATUS_FIELD_VOLTAGE_LEN 4
#define MAVLINK_MSG_TILT_STATUS_FIELD_CURRENT_LEN 4
#define MAVLINK_MSG_TILT_STATUS_FIELD_TEMPERATURE_LEN 4
#define MAVLINK_MSG_TILT_STATUS_FIELD_REALTIME_TICK_LEN 4
#define MAVLINK_MSG_TILT_STATUS_FIELD_ERROR_STATUS_LEN 4

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TILT_STATUS { \
    514, \
    "TILT_STATUS", \
    8, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_tilt_status_t, time_boot_ms) }, \
         { "realtime_tick", NULL, MAVLINK_TYPE_UINT16_T, 4, 84, offsetof(mavlink_tilt_status_t, realtime_tick) }, \
         { "error_status", NULL, MAVLINK_TYPE_UINT8_T, 4, 92, offsetof(mavlink_tilt_status_t, error_status) }, \
         { "angle", NULL, MAVLINK_TYPE_FLOAT, 4, 4, offsetof(mavlink_tilt_status_t, angle) }, \
         { "angular_vel", NULL, MAVLINK_TYPE_FLOAT, 4, 20, offsetof(mavlink_tilt_status_t, angular_vel) }, \
         { "voltage", NULL, MAVLINK_TYPE_FLOAT, 4, 36, offsetof(mavlink_tilt_status_t, voltage) }, \
         { "current", NULL, MAVLINK_TYPE_INT32_T, 4, 52, offsetof(mavlink_tilt_status_t, current) }, \
         { "temperature", NULL, MAVLINK_TYPE_FLOAT, 4, 68, offsetof(mavlink_tilt_status_t, temperature) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TILT_STATUS { \
    "TILT_STATUS", \
    8, \
    {  { "time_boot_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_tilt_status_t, time_boot_ms) }, \
         { "realtime_tick", NULL, MAVLINK_TYPE_UINT16_T, 4, 84, offsetof(mavlink_tilt_status_t, realtime_tick) }, \
         { "error_status", NULL, MAVLINK_TYPE_UINT8_T, 4, 92, offsetof(mavlink_tilt_status_t, error_status) }, \
         { "angle", NULL, MAVLINK_TYPE_FLOAT, 4, 4, offsetof(mavlink_tilt_status_t, angle) }, \
         { "angular_vel", NULL, MAVLINK_TYPE_FLOAT, 4, 20, offsetof(mavlink_tilt_status_t, angular_vel) }, \
         { "voltage", NULL, MAVLINK_TYPE_FLOAT, 4, 36, offsetof(mavlink_tilt_status_t, voltage) }, \
         { "current", NULL, MAVLINK_TYPE_INT32_T, 4, 52, offsetof(mavlink_tilt_status_t, current) }, \
         { "temperature", NULL, MAVLINK_TYPE_FLOAT, 4, 68, offsetof(mavlink_tilt_status_t, temperature) }, \
         } \
}
#endif

/**
 * @brief Pack a tilt_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param realtime_tick  Realtime tick value for each motor.
 * @param error_status  Error status for each motor.
 * @param angle [deg] Actual angle of each motor.
 * @param angular_vel [deg/s] Actual angular velocity of each motor.
 * @param voltage [V] Actual voltage of each motor.
 * @param current [mA] Actual current of each motor.
 * @param temperature [degC] Actual temperature of each motor.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tilt_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_boot_ms, const uint16_t *realtime_tick, const uint8_t *error_status, const float *angle, const float *angular_vel, const float *voltage, const int32_t *current, const float *temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TILT_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float_array(buf, 4, angle, 4);
    _mav_put_float_array(buf, 20, angular_vel, 4);
    _mav_put_float_array(buf, 36, voltage, 4);
    _mav_put_int32_t_array(buf, 52, current, 4);
    _mav_put_float_array(buf, 68, temperature, 4);
    _mav_put_uint16_t_array(buf, 84, realtime_tick, 4);
    _mav_put_uint8_t_array(buf, 92, error_status, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TILT_STATUS_LEN);
#else
    mavlink_tilt_status_t packet;
    packet.time_boot_ms = time_boot_ms;
    mav_array_memcpy(packet.angle, angle, sizeof(float)*4);
    mav_array_memcpy(packet.angular_vel, angular_vel, sizeof(float)*4);
    mav_array_memcpy(packet.voltage, voltage, sizeof(float)*4);
    mav_array_memcpy(packet.current, current, sizeof(int32_t)*4);
    mav_array_memcpy(packet.temperature, temperature, sizeof(float)*4);
    mav_array_memcpy(packet.realtime_tick, realtime_tick, sizeof(uint16_t)*4);
    mav_array_memcpy(packet.error_status, error_status, sizeof(uint8_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TILT_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TILT_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TILT_STATUS_MIN_LEN, MAVLINK_MSG_ID_TILT_STATUS_LEN, MAVLINK_MSG_ID_TILT_STATUS_CRC);
}

/**
 * @brief Pack a tilt_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param realtime_tick  Realtime tick value for each motor.
 * @param error_status  Error status for each motor.
 * @param angle [deg] Actual angle of each motor.
 * @param angular_vel [deg/s] Actual angular velocity of each motor.
 * @param voltage [V] Actual voltage of each motor.
 * @param current [mA] Actual current of each motor.
 * @param temperature [degC] Actual temperature of each motor.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tilt_status_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint32_t time_boot_ms, const uint16_t *realtime_tick, const uint8_t *error_status, const float *angle, const float *angular_vel, const float *voltage, const int32_t *current, const float *temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TILT_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float_array(buf, 4, angle, 4);
    _mav_put_float_array(buf, 20, angular_vel, 4);
    _mav_put_float_array(buf, 36, voltage, 4);
    _mav_put_int32_t_array(buf, 52, current, 4);
    _mav_put_float_array(buf, 68, temperature, 4);
    _mav_put_uint16_t_array(buf, 84, realtime_tick, 4);
    _mav_put_uint8_t_array(buf, 92, error_status, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TILT_STATUS_LEN);
#else
    mavlink_tilt_status_t packet;
    packet.time_boot_ms = time_boot_ms;
    mav_array_memcpy(packet.angle, angle, sizeof(float)*4);
    mav_array_memcpy(packet.angular_vel, angular_vel, sizeof(float)*4);
    mav_array_memcpy(packet.voltage, voltage, sizeof(float)*4);
    mav_array_memcpy(packet.current, current, sizeof(int32_t)*4);
    mav_array_memcpy(packet.temperature, temperature, sizeof(float)*4);
    mav_array_memcpy(packet.realtime_tick, realtime_tick, sizeof(uint16_t)*4);
    mav_array_memcpy(packet.error_status, error_status, sizeof(uint8_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TILT_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TILT_STATUS;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_TILT_STATUS_MIN_LEN, MAVLINK_MSG_ID_TILT_STATUS_LEN, MAVLINK_MSG_ID_TILT_STATUS_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_TILT_STATUS_MIN_LEN, MAVLINK_MSG_ID_TILT_STATUS_LEN);
#endif
}

/**
 * @brief Pack a tilt_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param realtime_tick  Realtime tick value for each motor.
 * @param error_status  Error status for each motor.
 * @param angle [deg] Actual angle of each motor.
 * @param angular_vel [deg/s] Actual angular velocity of each motor.
 * @param voltage [V] Actual voltage of each motor.
 * @param current [mA] Actual current of each motor.
 * @param temperature [degC] Actual temperature of each motor.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tilt_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_boot_ms,const uint16_t *realtime_tick,const uint8_t *error_status,const float *angle,const float *angular_vel,const float *voltage,const int32_t *current,const float *temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TILT_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float_array(buf, 4, angle, 4);
    _mav_put_float_array(buf, 20, angular_vel, 4);
    _mav_put_float_array(buf, 36, voltage, 4);
    _mav_put_int32_t_array(buf, 52, current, 4);
    _mav_put_float_array(buf, 68, temperature, 4);
    _mav_put_uint16_t_array(buf, 84, realtime_tick, 4);
    _mav_put_uint8_t_array(buf, 92, error_status, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TILT_STATUS_LEN);
#else
    mavlink_tilt_status_t packet;
    packet.time_boot_ms = time_boot_ms;
    mav_array_memcpy(packet.angle, angle, sizeof(float)*4);
    mav_array_memcpy(packet.angular_vel, angular_vel, sizeof(float)*4);
    mav_array_memcpy(packet.voltage, voltage, sizeof(float)*4);
    mav_array_memcpy(packet.current, current, sizeof(int32_t)*4);
    mav_array_memcpy(packet.temperature, temperature, sizeof(float)*4);
    mav_array_memcpy(packet.realtime_tick, realtime_tick, sizeof(uint16_t)*4);
    mav_array_memcpy(packet.error_status, error_status, sizeof(uint8_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TILT_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TILT_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TILT_STATUS_MIN_LEN, MAVLINK_MSG_ID_TILT_STATUS_LEN, MAVLINK_MSG_ID_TILT_STATUS_CRC);
}

/**
 * @brief Encode a tilt_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param tilt_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tilt_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_tilt_status_t* tilt_status)
{
    return mavlink_msg_tilt_status_pack(system_id, component_id, msg, tilt_status->time_boot_ms, tilt_status->realtime_tick, tilt_status->error_status, tilt_status->angle, tilt_status->angular_vel, tilt_status->voltage, tilt_status->current, tilt_status->temperature);
}

/**
 * @brief Encode a tilt_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param tilt_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tilt_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_tilt_status_t* tilt_status)
{
    return mavlink_msg_tilt_status_pack_chan(system_id, component_id, chan, msg, tilt_status->time_boot_ms, tilt_status->realtime_tick, tilt_status->error_status, tilt_status->angle, tilt_status->angular_vel, tilt_status->voltage, tilt_status->current, tilt_status->temperature);
}

/**
 * @brief Encode a tilt_status struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param tilt_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tilt_status_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_tilt_status_t* tilt_status)
{
    return mavlink_msg_tilt_status_pack_status(system_id, component_id, _status, msg,  tilt_status->time_boot_ms, tilt_status->realtime_tick, tilt_status->error_status, tilt_status->angle, tilt_status->angular_vel, tilt_status->voltage, tilt_status->current, tilt_status->temperature);
}

/**
 * @brief Send a tilt_status message
 * @param chan MAVLink channel to send the message
 *
 * @param time_boot_ms [ms] Timestamp (time since system boot).
 * @param realtime_tick  Realtime tick value for each motor.
 * @param error_status  Error status for each motor.
 * @param angle [deg] Actual angle of each motor.
 * @param angular_vel [deg/s] Actual angular velocity of each motor.
 * @param voltage [V] Actual voltage of each motor.
 * @param current [mA] Actual current of each motor.
 * @param temperature [degC] Actual temperature of each motor.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_tilt_status_send(mavlink_channel_t chan, uint32_t time_boot_ms, const uint16_t *realtime_tick, const uint8_t *error_status, const float *angle, const float *angular_vel, const float *voltage, const int32_t *current, const float *temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TILT_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float_array(buf, 4, angle, 4);
    _mav_put_float_array(buf, 20, angular_vel, 4);
    _mav_put_float_array(buf, 36, voltage, 4);
    _mav_put_int32_t_array(buf, 52, current, 4);
    _mav_put_float_array(buf, 68, temperature, 4);
    _mav_put_uint16_t_array(buf, 84, realtime_tick, 4);
    _mav_put_uint8_t_array(buf, 92, error_status, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TILT_STATUS, buf, MAVLINK_MSG_ID_TILT_STATUS_MIN_LEN, MAVLINK_MSG_ID_TILT_STATUS_LEN, MAVLINK_MSG_ID_TILT_STATUS_CRC);
#else
    mavlink_tilt_status_t packet;
    packet.time_boot_ms = time_boot_ms;
    mav_array_memcpy(packet.angle, angle, sizeof(float)*4);
    mav_array_memcpy(packet.angular_vel, angular_vel, sizeof(float)*4);
    mav_array_memcpy(packet.voltage, voltage, sizeof(float)*4);
    mav_array_memcpy(packet.current, current, sizeof(int32_t)*4);
    mav_array_memcpy(packet.temperature, temperature, sizeof(float)*4);
    mav_array_memcpy(packet.realtime_tick, realtime_tick, sizeof(uint16_t)*4);
    mav_array_memcpy(packet.error_status, error_status, sizeof(uint8_t)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TILT_STATUS, (const char *)&packet, MAVLINK_MSG_ID_TILT_STATUS_MIN_LEN, MAVLINK_MSG_ID_TILT_STATUS_LEN, MAVLINK_MSG_ID_TILT_STATUS_CRC);
#endif
}

/**
 * @brief Send a tilt_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_tilt_status_send_struct(mavlink_channel_t chan, const mavlink_tilt_status_t* tilt_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_tilt_status_send(chan, tilt_status->time_boot_ms, tilt_status->realtime_tick, tilt_status->error_status, tilt_status->angle, tilt_status->angular_vel, tilt_status->voltage, tilt_status->current, tilt_status->temperature);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TILT_STATUS, (const char *)tilt_status, MAVLINK_MSG_ID_TILT_STATUS_MIN_LEN, MAVLINK_MSG_ID_TILT_STATUS_LEN, MAVLINK_MSG_ID_TILT_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_TILT_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_tilt_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time_boot_ms, const uint16_t *realtime_tick, const uint8_t *error_status, const float *angle, const float *angular_vel, const float *voltage, const int32_t *current, const float *temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, time_boot_ms);
    _mav_put_float_array(buf, 4, angle, 4);
    _mav_put_float_array(buf, 20, angular_vel, 4);
    _mav_put_float_array(buf, 36, voltage, 4);
    _mav_put_int32_t_array(buf, 52, current, 4);
    _mav_put_float_array(buf, 68, temperature, 4);
    _mav_put_uint16_t_array(buf, 84, realtime_tick, 4);
    _mav_put_uint8_t_array(buf, 92, error_status, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TILT_STATUS, buf, MAVLINK_MSG_ID_TILT_STATUS_MIN_LEN, MAVLINK_MSG_ID_TILT_STATUS_LEN, MAVLINK_MSG_ID_TILT_STATUS_CRC);
#else
    mavlink_tilt_status_t *packet = (mavlink_tilt_status_t *)msgbuf;
    packet->time_boot_ms = time_boot_ms;
    mav_array_memcpy(packet->angle, angle, sizeof(float)*4);
    mav_array_memcpy(packet->angular_vel, angular_vel, sizeof(float)*4);
    mav_array_memcpy(packet->voltage, voltage, sizeof(float)*4);
    mav_array_memcpy(packet->current, current, sizeof(int32_t)*4);
    mav_array_memcpy(packet->temperature, temperature, sizeof(float)*4);
    mav_array_memcpy(packet->realtime_tick, realtime_tick, sizeof(uint16_t)*4);
    mav_array_memcpy(packet->error_status, error_status, sizeof(uint8_t)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TILT_STATUS, (const char *)packet, MAVLINK_MSG_ID_TILT_STATUS_MIN_LEN, MAVLINK_MSG_ID_TILT_STATUS_LEN, MAVLINK_MSG_ID_TILT_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE TILT_STATUS UNPACKING


/**
 * @brief Get field time_boot_ms from tilt_status message
 *
 * @return [ms] Timestamp (time since system boot).
 */
static inline uint32_t mavlink_msg_tilt_status_get_time_boot_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field realtime_tick from tilt_status message
 *
 * @return  Realtime tick value for each motor.
 */
static inline uint16_t mavlink_msg_tilt_status_get_realtime_tick(const mavlink_message_t* msg, uint16_t *realtime_tick)
{
    return _MAV_RETURN_uint16_t_array(msg, realtime_tick, 4,  84);
}

/**
 * @brief Get field error_status from tilt_status message
 *
 * @return  Error status for each motor.
 */
static inline uint16_t mavlink_msg_tilt_status_get_error_status(const mavlink_message_t* msg, uint8_t *error_status)
{
    return _MAV_RETURN_uint8_t_array(msg, error_status, 4,  92);
}

/**
 * @brief Get field angle from tilt_status message
 *
 * @return [deg] Actual angle of each motor.
 */
static inline uint16_t mavlink_msg_tilt_status_get_angle(const mavlink_message_t* msg, float *angle)
{
    return _MAV_RETURN_float_array(msg, angle, 4,  4);
}

/**
 * @brief Get field angular_vel from tilt_status message
 *
 * @return [deg/s] Actual angular velocity of each motor.
 */
static inline uint16_t mavlink_msg_tilt_status_get_angular_vel(const mavlink_message_t* msg, float *angular_vel)
{
    return _MAV_RETURN_float_array(msg, angular_vel, 4,  20);
}

/**
 * @brief Get field voltage from tilt_status message
 *
 * @return [V] Actual voltage of each motor.
 */
static inline uint16_t mavlink_msg_tilt_status_get_voltage(const mavlink_message_t* msg, float *voltage)
{
    return _MAV_RETURN_float_array(msg, voltage, 4,  36);
}

/**
 * @brief Get field current from tilt_status message
 *
 * @return [mA] Actual current of each motor.
 */
static inline uint16_t mavlink_msg_tilt_status_get_current(const mavlink_message_t* msg, int32_t *current)
{
    return _MAV_RETURN_int32_t_array(msg, current, 4,  52);
}

/**
 * @brief Get field temperature from tilt_status message
 *
 * @return [degC] Actual temperature of each motor.
 */
static inline uint16_t mavlink_msg_tilt_status_get_temperature(const mavlink_message_t* msg, float *temperature)
{
    return _MAV_RETURN_float_array(msg, temperature, 4,  68);
}

/**
 * @brief Decode a tilt_status message into a struct
 *
 * @param msg The message to decode
 * @param tilt_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_tilt_status_decode(const mavlink_message_t* msg, mavlink_tilt_status_t* tilt_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    tilt_status->time_boot_ms = mavlink_msg_tilt_status_get_time_boot_ms(msg);
    mavlink_msg_tilt_status_get_angle(msg, tilt_status->angle);
    mavlink_msg_tilt_status_get_angular_vel(msg, tilt_status->angular_vel);
    mavlink_msg_tilt_status_get_voltage(msg, tilt_status->voltage);
    mavlink_msg_tilt_status_get_current(msg, tilt_status->current);
    mavlink_msg_tilt_status_get_temperature(msg, tilt_status->temperature);
    mavlink_msg_tilt_status_get_realtime_tick(msg, tilt_status->realtime_tick);
    mavlink_msg_tilt_status_get_error_status(msg, tilt_status->error_status);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TILT_STATUS_LEN? msg->len : MAVLINK_MSG_ID_TILT_STATUS_LEN;
        memset(tilt_status, 0, MAVLINK_MSG_ID_TILT_STATUS_LEN);
    memcpy(tilt_status, _MAV_PAYLOAD(msg), len);
#endif
}
