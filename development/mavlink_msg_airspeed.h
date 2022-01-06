#pragma once
// MESSAGE AIRSPEED PACKING

#define MAVLINK_MSG_ID_AIRSPEED 295


typedef struct __mavlink_airspeed_t {
 float airspeed; /*< [m/s] Calibrated airspeed (CAS) if available, otherwise indicated airspeed (IAS).*/
 float press_diff; /*< [hPa] Differential pressure. NaN for value unknown/not supplied.*/
 float press_static; /*< [hPa] Static pressure. NaN for value unknown/not supplied.*/
 float error; /*< [m/s] Error/accuracy. NaN for value unknown/not supplied.*/
 int16_t temperature; /*< [cdegC] Temperature. INT16_MAX for value unknown/not supplied.*/
 uint8_t id; /*<  Sensor ID.*/
 uint8_t type; /*<  Airspeed sensor type. NaN for value unknown/not supplied. Used to estimate accuracy (i.e. as an alternative to using the error field).*/
} mavlink_airspeed_t;

#define MAVLINK_MSG_ID_AIRSPEED_LEN 20
#define MAVLINK_MSG_ID_AIRSPEED_MIN_LEN 20
#define MAVLINK_MSG_ID_295_LEN 20
#define MAVLINK_MSG_ID_295_MIN_LEN 20

#define MAVLINK_MSG_ID_AIRSPEED_CRC 41
#define MAVLINK_MSG_ID_295_CRC 41



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_AIRSPEED { \
    295, \
    "AIRSPEED", \
    7, \
    {  { "id", NULL, MAVLINK_TYPE_UINT8_T, 0, 18, offsetof(mavlink_airspeed_t, id) }, \
         { "airspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_airspeed_t, airspeed) }, \
         { "temperature", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_airspeed_t, temperature) }, \
         { "press_diff", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_airspeed_t, press_diff) }, \
         { "press_static", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_airspeed_t, press_static) }, \
         { "error", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_airspeed_t, error) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 19, offsetof(mavlink_airspeed_t, type) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_AIRSPEED { \
    "AIRSPEED", \
    7, \
    {  { "id", NULL, MAVLINK_TYPE_UINT8_T, 0, 18, offsetof(mavlink_airspeed_t, id) }, \
         { "airspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_airspeed_t, airspeed) }, \
         { "temperature", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_airspeed_t, temperature) }, \
         { "press_diff", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_airspeed_t, press_diff) }, \
         { "press_static", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_airspeed_t, press_static) }, \
         { "error", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_airspeed_t, error) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 19, offsetof(mavlink_airspeed_t, type) }, \
         } \
}
#endif

/**
 * @brief Pack a airspeed message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param id  Sensor ID.
 * @param airspeed [m/s] Calibrated airspeed (CAS) if available, otherwise indicated airspeed (IAS).
 * @param temperature [cdegC] Temperature. INT16_MAX for value unknown/not supplied.
 * @param press_diff [hPa] Differential pressure. NaN for value unknown/not supplied.
 * @param press_static [hPa] Static pressure. NaN for value unknown/not supplied.
 * @param error [m/s] Error/accuracy. NaN for value unknown/not supplied.
 * @param type  Airspeed sensor type. NaN for value unknown/not supplied. Used to estimate accuracy (i.e. as an alternative to using the error field).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_airspeed_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t id, float airspeed, int16_t temperature, float press_diff, float press_static, float error, uint8_t type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AIRSPEED_LEN];
    _mav_put_float(buf, 0, airspeed);
    _mav_put_float(buf, 4, press_diff);
    _mav_put_float(buf, 8, press_static);
    _mav_put_float(buf, 12, error);
    _mav_put_int16_t(buf, 16, temperature);
    _mav_put_uint8_t(buf, 18, id);
    _mav_put_uint8_t(buf, 19, type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AIRSPEED_LEN);
#else
    mavlink_airspeed_t packet;
    packet.airspeed = airspeed;
    packet.press_diff = press_diff;
    packet.press_static = press_static;
    packet.error = error;
    packet.temperature = temperature;
    packet.id = id;
    packet.type = type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AIRSPEED_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AIRSPEED;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AIRSPEED_MIN_LEN, MAVLINK_MSG_ID_AIRSPEED_LEN, MAVLINK_MSG_ID_AIRSPEED_CRC);
}

/**
 * @brief Pack a airspeed message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param id  Sensor ID.
 * @param airspeed [m/s] Calibrated airspeed (CAS) if available, otherwise indicated airspeed (IAS).
 * @param temperature [cdegC] Temperature. INT16_MAX for value unknown/not supplied.
 * @param press_diff [hPa] Differential pressure. NaN for value unknown/not supplied.
 * @param press_static [hPa] Static pressure. NaN for value unknown/not supplied.
 * @param error [m/s] Error/accuracy. NaN for value unknown/not supplied.
 * @param type  Airspeed sensor type. NaN for value unknown/not supplied. Used to estimate accuracy (i.e. as an alternative to using the error field).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_airspeed_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t id,float airspeed,int16_t temperature,float press_diff,float press_static,float error,uint8_t type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AIRSPEED_LEN];
    _mav_put_float(buf, 0, airspeed);
    _mav_put_float(buf, 4, press_diff);
    _mav_put_float(buf, 8, press_static);
    _mav_put_float(buf, 12, error);
    _mav_put_int16_t(buf, 16, temperature);
    _mav_put_uint8_t(buf, 18, id);
    _mav_put_uint8_t(buf, 19, type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AIRSPEED_LEN);
#else
    mavlink_airspeed_t packet;
    packet.airspeed = airspeed;
    packet.press_diff = press_diff;
    packet.press_static = press_static;
    packet.error = error;
    packet.temperature = temperature;
    packet.id = id;
    packet.type = type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AIRSPEED_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AIRSPEED;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AIRSPEED_MIN_LEN, MAVLINK_MSG_ID_AIRSPEED_LEN, MAVLINK_MSG_ID_AIRSPEED_CRC);
}

/**
 * @brief Encode a airspeed struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param airspeed C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_airspeed_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_airspeed_t* airspeed)
{
    return mavlink_msg_airspeed_pack(system_id, component_id, msg, airspeed->id, airspeed->airspeed, airspeed->temperature, airspeed->press_diff, airspeed->press_static, airspeed->error, airspeed->type);
}

/**
 * @brief Encode a airspeed struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param airspeed C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_airspeed_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_airspeed_t* airspeed)
{
    return mavlink_msg_airspeed_pack_chan(system_id, component_id, chan, msg, airspeed->id, airspeed->airspeed, airspeed->temperature, airspeed->press_diff, airspeed->press_static, airspeed->error, airspeed->type);
}

/**
 * @brief Send a airspeed message
 * @param chan MAVLink channel to send the message
 *
 * @param id  Sensor ID.
 * @param airspeed [m/s] Calibrated airspeed (CAS) if available, otherwise indicated airspeed (IAS).
 * @param temperature [cdegC] Temperature. INT16_MAX for value unknown/not supplied.
 * @param press_diff [hPa] Differential pressure. NaN for value unknown/not supplied.
 * @param press_static [hPa] Static pressure. NaN for value unknown/not supplied.
 * @param error [m/s] Error/accuracy. NaN for value unknown/not supplied.
 * @param type  Airspeed sensor type. NaN for value unknown/not supplied. Used to estimate accuracy (i.e. as an alternative to using the error field).
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_airspeed_send(mavlink_channel_t chan, uint8_t id, float airspeed, int16_t temperature, float press_diff, float press_static, float error, uint8_t type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AIRSPEED_LEN];
    _mav_put_float(buf, 0, airspeed);
    _mav_put_float(buf, 4, press_diff);
    _mav_put_float(buf, 8, press_static);
    _mav_put_float(buf, 12, error);
    _mav_put_int16_t(buf, 16, temperature);
    _mav_put_uint8_t(buf, 18, id);
    _mav_put_uint8_t(buf, 19, type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AIRSPEED, buf, MAVLINK_MSG_ID_AIRSPEED_MIN_LEN, MAVLINK_MSG_ID_AIRSPEED_LEN, MAVLINK_MSG_ID_AIRSPEED_CRC);
#else
    mavlink_airspeed_t packet;
    packet.airspeed = airspeed;
    packet.press_diff = press_diff;
    packet.press_static = press_static;
    packet.error = error;
    packet.temperature = temperature;
    packet.id = id;
    packet.type = type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AIRSPEED, (const char *)&packet, MAVLINK_MSG_ID_AIRSPEED_MIN_LEN, MAVLINK_MSG_ID_AIRSPEED_LEN, MAVLINK_MSG_ID_AIRSPEED_CRC);
#endif
}

/**
 * @brief Send a airspeed message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_airspeed_send_struct(mavlink_channel_t chan, const mavlink_airspeed_t* airspeed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_airspeed_send(chan, airspeed->id, airspeed->airspeed, airspeed->temperature, airspeed->press_diff, airspeed->press_static, airspeed->error, airspeed->type);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AIRSPEED, (const char *)airspeed, MAVLINK_MSG_ID_AIRSPEED_MIN_LEN, MAVLINK_MSG_ID_AIRSPEED_LEN, MAVLINK_MSG_ID_AIRSPEED_CRC);
#endif
}

#if MAVLINK_MSG_ID_AIRSPEED_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_airspeed_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t id, float airspeed, int16_t temperature, float press_diff, float press_static, float error, uint8_t type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, airspeed);
    _mav_put_float(buf, 4, press_diff);
    _mav_put_float(buf, 8, press_static);
    _mav_put_float(buf, 12, error);
    _mav_put_int16_t(buf, 16, temperature);
    _mav_put_uint8_t(buf, 18, id);
    _mav_put_uint8_t(buf, 19, type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AIRSPEED, buf, MAVLINK_MSG_ID_AIRSPEED_MIN_LEN, MAVLINK_MSG_ID_AIRSPEED_LEN, MAVLINK_MSG_ID_AIRSPEED_CRC);
#else
    mavlink_airspeed_t *packet = (mavlink_airspeed_t *)msgbuf;
    packet->airspeed = airspeed;
    packet->press_diff = press_diff;
    packet->press_static = press_static;
    packet->error = error;
    packet->temperature = temperature;
    packet->id = id;
    packet->type = type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AIRSPEED, (const char *)packet, MAVLINK_MSG_ID_AIRSPEED_MIN_LEN, MAVLINK_MSG_ID_AIRSPEED_LEN, MAVLINK_MSG_ID_AIRSPEED_CRC);
#endif
}
#endif

#endif

// MESSAGE AIRSPEED UNPACKING


/**
 * @brief Get field id from airspeed message
 *
 * @return  Sensor ID.
 */
static inline uint8_t mavlink_msg_airspeed_get_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  18);
}

/**
 * @brief Get field airspeed from airspeed message
 *
 * @return [m/s] Calibrated airspeed (CAS) if available, otherwise indicated airspeed (IAS).
 */
static inline float mavlink_msg_airspeed_get_airspeed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field temperature from airspeed message
 *
 * @return [cdegC] Temperature. INT16_MAX for value unknown/not supplied.
 */
static inline int16_t mavlink_msg_airspeed_get_temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  16);
}

/**
 * @brief Get field press_diff from airspeed message
 *
 * @return [hPa] Differential pressure. NaN for value unknown/not supplied.
 */
static inline float mavlink_msg_airspeed_get_press_diff(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field press_static from airspeed message
 *
 * @return [hPa] Static pressure. NaN for value unknown/not supplied.
 */
static inline float mavlink_msg_airspeed_get_press_static(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field error from airspeed message
 *
 * @return [m/s] Error/accuracy. NaN for value unknown/not supplied.
 */
static inline float mavlink_msg_airspeed_get_error(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field type from airspeed message
 *
 * @return  Airspeed sensor type. NaN for value unknown/not supplied. Used to estimate accuracy (i.e. as an alternative to using the error field).
 */
static inline uint8_t mavlink_msg_airspeed_get_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  19);
}

/**
 * @brief Decode a airspeed message into a struct
 *
 * @param msg The message to decode
 * @param airspeed C-struct to decode the message contents into
 */
static inline void mavlink_msg_airspeed_decode(const mavlink_message_t* msg, mavlink_airspeed_t* airspeed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    airspeed->airspeed = mavlink_msg_airspeed_get_airspeed(msg);
    airspeed->press_diff = mavlink_msg_airspeed_get_press_diff(msg);
    airspeed->press_static = mavlink_msg_airspeed_get_press_static(msg);
    airspeed->error = mavlink_msg_airspeed_get_error(msg);
    airspeed->temperature = mavlink_msg_airspeed_get_temperature(msg);
    airspeed->id = mavlink_msg_airspeed_get_id(msg);
    airspeed->type = mavlink_msg_airspeed_get_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_AIRSPEED_LEN? msg->len : MAVLINK_MSG_ID_AIRSPEED_LEN;
        memset(airspeed, 0, MAVLINK_MSG_ID_AIRSPEED_LEN);
    memcpy(airspeed, _MAV_PAYLOAD(msg), len);
#endif
}
