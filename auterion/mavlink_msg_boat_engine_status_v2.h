#pragma once
// MESSAGE BOAT_ENGINE_STATUS_V2 PACKING

#define MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2 13667


typedef struct __mavlink_boat_engine_status_v2_t {
 uint64_t time_usec; /*< [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.*/
 float fuel_consumption_rate; /*< [L/h] Fuel consumption rate.*/
 float oil_pressure[6]; /*< [kPa] Engine oil pressure.*/
 float engine_coolant_temperature[6]; /*< [degC] Engine coolant temperature.*/
 uint16_t engine_rpm[6]; /*< [rpm] Engine RPM.*/
 uint8_t engine_state[6]; /*<  Engine state.*/
 uint8_t engine_load[6]; /*< [%] Engine load.*/
 uint8_t throttle_position[6]; /*< [%] Throttle position.*/
 uint8_t transmission_state[6]; /*<  Transmission state.*/
} mavlink_boat_engine_status_v2_t;

#define MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_LEN 96
#define MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_MIN_LEN 96
#define MAVLINK_MSG_ID_13667_LEN 96
#define MAVLINK_MSG_ID_13667_MIN_LEN 96

#define MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_CRC 111
#define MAVLINK_MSG_ID_13667_CRC 111

#define MAVLINK_MSG_BOAT_ENGINE_STATUS_V2_FIELD_OIL_PRESSURE_LEN 6
#define MAVLINK_MSG_BOAT_ENGINE_STATUS_V2_FIELD_ENGINE_COOLANT_TEMPERATURE_LEN 6
#define MAVLINK_MSG_BOAT_ENGINE_STATUS_V2_FIELD_ENGINE_RPM_LEN 6
#define MAVLINK_MSG_BOAT_ENGINE_STATUS_V2_FIELD_ENGINE_STATE_LEN 6
#define MAVLINK_MSG_BOAT_ENGINE_STATUS_V2_FIELD_ENGINE_LOAD_LEN 6
#define MAVLINK_MSG_BOAT_ENGINE_STATUS_V2_FIELD_THROTTLE_POSITION_LEN 6
#define MAVLINK_MSG_BOAT_ENGINE_STATUS_V2_FIELD_TRANSMISSION_STATE_LEN 6

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_BOAT_ENGINE_STATUS_V2 { \
    13667, \
    "BOAT_ENGINE_STATUS_V2", \
    9, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_boat_engine_status_v2_t, time_usec) }, \
         { "engine_state", NULL, MAVLINK_TYPE_UINT8_T, 6, 72, offsetof(mavlink_boat_engine_status_v2_t, engine_state) }, \
         { "engine_load", NULL, MAVLINK_TYPE_UINT8_T, 6, 78, offsetof(mavlink_boat_engine_status_v2_t, engine_load) }, \
         { "engine_rpm", NULL, MAVLINK_TYPE_UINT16_T, 6, 60, offsetof(mavlink_boat_engine_status_v2_t, engine_rpm) }, \
         { "fuel_consumption_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_boat_engine_status_v2_t, fuel_consumption_rate) }, \
         { "oil_pressure", NULL, MAVLINK_TYPE_FLOAT, 6, 12, offsetof(mavlink_boat_engine_status_v2_t, oil_pressure) }, \
         { "throttle_position", NULL, MAVLINK_TYPE_UINT8_T, 6, 84, offsetof(mavlink_boat_engine_status_v2_t, throttle_position) }, \
         { "engine_coolant_temperature", NULL, MAVLINK_TYPE_FLOAT, 6, 36, offsetof(mavlink_boat_engine_status_v2_t, engine_coolant_temperature) }, \
         { "transmission_state", NULL, MAVLINK_TYPE_UINT8_T, 6, 90, offsetof(mavlink_boat_engine_status_v2_t, transmission_state) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_BOAT_ENGINE_STATUS_V2 { \
    "BOAT_ENGINE_STATUS_V2", \
    9, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_boat_engine_status_v2_t, time_usec) }, \
         { "engine_state", NULL, MAVLINK_TYPE_UINT8_T, 6, 72, offsetof(mavlink_boat_engine_status_v2_t, engine_state) }, \
         { "engine_load", NULL, MAVLINK_TYPE_UINT8_T, 6, 78, offsetof(mavlink_boat_engine_status_v2_t, engine_load) }, \
         { "engine_rpm", NULL, MAVLINK_TYPE_UINT16_T, 6, 60, offsetof(mavlink_boat_engine_status_v2_t, engine_rpm) }, \
         { "fuel_consumption_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_boat_engine_status_v2_t, fuel_consumption_rate) }, \
         { "oil_pressure", NULL, MAVLINK_TYPE_FLOAT, 6, 12, offsetof(mavlink_boat_engine_status_v2_t, oil_pressure) }, \
         { "throttle_position", NULL, MAVLINK_TYPE_UINT8_T, 6, 84, offsetof(mavlink_boat_engine_status_v2_t, throttle_position) }, \
         { "engine_coolant_temperature", NULL, MAVLINK_TYPE_FLOAT, 6, 36, offsetof(mavlink_boat_engine_status_v2_t, engine_coolant_temperature) }, \
         { "transmission_state", NULL, MAVLINK_TYPE_UINT8_T, 6, 90, offsetof(mavlink_boat_engine_status_v2_t, transmission_state) }, \
         } \
}
#endif

/**
 * @brief Pack a boat_engine_status_v2 message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param engine_state  Engine state.
 * @param engine_load [%] Engine load.
 * @param engine_rpm [rpm] Engine RPM.
 * @param fuel_consumption_rate [L/h] Fuel consumption rate.
 * @param oil_pressure [kPa] Engine oil pressure.
 * @param throttle_position [%] Throttle position.
 * @param engine_coolant_temperature [degC] Engine coolant temperature.
 * @param transmission_state  Transmission state.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_boat_engine_status_v2_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, const uint8_t *engine_state, const uint8_t *engine_load, const uint16_t *engine_rpm, float fuel_consumption_rate, const float *oil_pressure, const uint8_t *throttle_position, const float *engine_coolant_temperature, const uint8_t *transmission_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 8, fuel_consumption_rate);
    _mav_put_float_array(buf, 12, oil_pressure, 6);
    _mav_put_float_array(buf, 36, engine_coolant_temperature, 6);
    _mav_put_uint16_t_array(buf, 60, engine_rpm, 6);
    _mav_put_uint8_t_array(buf, 72, engine_state, 6);
    _mav_put_uint8_t_array(buf, 78, engine_load, 6);
    _mav_put_uint8_t_array(buf, 84, throttle_position, 6);
    _mav_put_uint8_t_array(buf, 90, transmission_state, 6);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_LEN);
#else
    mavlink_boat_engine_status_v2_t packet;
    packet.time_usec = time_usec;
    packet.fuel_consumption_rate = fuel_consumption_rate;
    mav_array_memcpy(packet.oil_pressure, oil_pressure, sizeof(float)*6);
    mav_array_memcpy(packet.engine_coolant_temperature, engine_coolant_temperature, sizeof(float)*6);
    mav_array_memcpy(packet.engine_rpm, engine_rpm, sizeof(uint16_t)*6);
    mav_array_memcpy(packet.engine_state, engine_state, sizeof(uint8_t)*6);
    mav_array_memcpy(packet.engine_load, engine_load, sizeof(uint8_t)*6);
    mav_array_memcpy(packet.throttle_position, throttle_position, sizeof(uint8_t)*6);
    mav_array_memcpy(packet.transmission_state, transmission_state, sizeof(uint8_t)*6);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_MIN_LEN, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_LEN, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_CRC);
}

/**
 * @brief Pack a boat_engine_status_v2 message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param engine_state  Engine state.
 * @param engine_load [%] Engine load.
 * @param engine_rpm [rpm] Engine RPM.
 * @param fuel_consumption_rate [L/h] Fuel consumption rate.
 * @param oil_pressure [kPa] Engine oil pressure.
 * @param throttle_position [%] Throttle position.
 * @param engine_coolant_temperature [degC] Engine coolant temperature.
 * @param transmission_state  Transmission state.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_boat_engine_status_v2_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint64_t time_usec, const uint8_t *engine_state, const uint8_t *engine_load, const uint16_t *engine_rpm, float fuel_consumption_rate, const float *oil_pressure, const uint8_t *throttle_position, const float *engine_coolant_temperature, const uint8_t *transmission_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 8, fuel_consumption_rate);
    _mav_put_float_array(buf, 12, oil_pressure, 6);
    _mav_put_float_array(buf, 36, engine_coolant_temperature, 6);
    _mav_put_uint16_t_array(buf, 60, engine_rpm, 6);
    _mav_put_uint8_t_array(buf, 72, engine_state, 6);
    _mav_put_uint8_t_array(buf, 78, engine_load, 6);
    _mav_put_uint8_t_array(buf, 84, throttle_position, 6);
    _mav_put_uint8_t_array(buf, 90, transmission_state, 6);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_LEN);
#else
    mavlink_boat_engine_status_v2_t packet;
    packet.time_usec = time_usec;
    packet.fuel_consumption_rate = fuel_consumption_rate;
    mav_array_memcpy(packet.oil_pressure, oil_pressure, sizeof(float)*6);
    mav_array_memcpy(packet.engine_coolant_temperature, engine_coolant_temperature, sizeof(float)*6);
    mav_array_memcpy(packet.engine_rpm, engine_rpm, sizeof(uint16_t)*6);
    mav_array_memcpy(packet.engine_state, engine_state, sizeof(uint8_t)*6);
    mav_array_memcpy(packet.engine_load, engine_load, sizeof(uint8_t)*6);
    mav_array_memcpy(packet.throttle_position, throttle_position, sizeof(uint8_t)*6);
    mav_array_memcpy(packet.transmission_state, transmission_state, sizeof(uint8_t)*6);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_MIN_LEN, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_LEN, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_MIN_LEN, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_LEN);
#endif
}

/**
 * @brief Pack a boat_engine_status_v2 message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param engine_state  Engine state.
 * @param engine_load [%] Engine load.
 * @param engine_rpm [rpm] Engine RPM.
 * @param fuel_consumption_rate [L/h] Fuel consumption rate.
 * @param oil_pressure [kPa] Engine oil pressure.
 * @param throttle_position [%] Throttle position.
 * @param engine_coolant_temperature [degC] Engine coolant temperature.
 * @param transmission_state  Transmission state.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_boat_engine_status_v2_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,const uint8_t *engine_state,const uint8_t *engine_load,const uint16_t *engine_rpm,float fuel_consumption_rate,const float *oil_pressure,const uint8_t *throttle_position,const float *engine_coolant_temperature,const uint8_t *transmission_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 8, fuel_consumption_rate);
    _mav_put_float_array(buf, 12, oil_pressure, 6);
    _mav_put_float_array(buf, 36, engine_coolant_temperature, 6);
    _mav_put_uint16_t_array(buf, 60, engine_rpm, 6);
    _mav_put_uint8_t_array(buf, 72, engine_state, 6);
    _mav_put_uint8_t_array(buf, 78, engine_load, 6);
    _mav_put_uint8_t_array(buf, 84, throttle_position, 6);
    _mav_put_uint8_t_array(buf, 90, transmission_state, 6);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_LEN);
#else
    mavlink_boat_engine_status_v2_t packet;
    packet.time_usec = time_usec;
    packet.fuel_consumption_rate = fuel_consumption_rate;
    mav_array_memcpy(packet.oil_pressure, oil_pressure, sizeof(float)*6);
    mav_array_memcpy(packet.engine_coolant_temperature, engine_coolant_temperature, sizeof(float)*6);
    mav_array_memcpy(packet.engine_rpm, engine_rpm, sizeof(uint16_t)*6);
    mav_array_memcpy(packet.engine_state, engine_state, sizeof(uint8_t)*6);
    mav_array_memcpy(packet.engine_load, engine_load, sizeof(uint8_t)*6);
    mav_array_memcpy(packet.throttle_position, throttle_position, sizeof(uint8_t)*6);
    mav_array_memcpy(packet.transmission_state, transmission_state, sizeof(uint8_t)*6);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_MIN_LEN, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_LEN, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_CRC);
}

/**
 * @brief Encode a boat_engine_status_v2 struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param boat_engine_status_v2 C-struct to read the message contents from
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_boat_engine_status_v2_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_boat_engine_status_v2_t* boat_engine_status_v2)
{
    return mavlink_msg_boat_engine_status_v2_pack(system_id, component_id, msg, boat_engine_status_v2->time_usec, boat_engine_status_v2->engine_state, boat_engine_status_v2->engine_load, boat_engine_status_v2->engine_rpm, boat_engine_status_v2->fuel_consumption_rate, boat_engine_status_v2->oil_pressure, boat_engine_status_v2->throttle_position, boat_engine_status_v2->engine_coolant_temperature, boat_engine_status_v2->transmission_state);
}

/**
 * @brief Encode a boat_engine_status_v2 struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param boat_engine_status_v2 C-struct to read the message contents from
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_boat_engine_status_v2_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_boat_engine_status_v2_t* boat_engine_status_v2)
{
    return mavlink_msg_boat_engine_status_v2_pack_chan(system_id, component_id, chan, msg, boat_engine_status_v2->time_usec, boat_engine_status_v2->engine_state, boat_engine_status_v2->engine_load, boat_engine_status_v2->engine_rpm, boat_engine_status_v2->fuel_consumption_rate, boat_engine_status_v2->oil_pressure, boat_engine_status_v2->throttle_position, boat_engine_status_v2->engine_coolant_temperature, boat_engine_status_v2->transmission_state);
}

/**
 * @brief Encode a boat_engine_status_v2 struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param boat_engine_status_v2 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_boat_engine_status_v2_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_boat_engine_status_v2_t* boat_engine_status_v2)
{
    return mavlink_msg_boat_engine_status_v2_pack_status(system_id, component_id, _status, msg,  boat_engine_status_v2->time_usec, boat_engine_status_v2->engine_state, boat_engine_status_v2->engine_load, boat_engine_status_v2->engine_rpm, boat_engine_status_v2->fuel_consumption_rate, boat_engine_status_v2->oil_pressure, boat_engine_status_v2->throttle_position, boat_engine_status_v2->engine_coolant_temperature, boat_engine_status_v2->transmission_state);
}

/**
 * @brief Send a boat_engine_status_v2 message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param engine_state  Engine state.
 * @param engine_load [%] Engine load.
 * @param engine_rpm [rpm] Engine RPM.
 * @param fuel_consumption_rate [L/h] Fuel consumption rate.
 * @param oil_pressure [kPa] Engine oil pressure.
 * @param throttle_position [%] Throttle position.
 * @param engine_coolant_temperature [degC] Engine coolant temperature.
 * @param transmission_state  Transmission state.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

MAVLINK_WIP
static inline void mavlink_msg_boat_engine_status_v2_send(mavlink_channel_t chan, uint64_t time_usec, const uint8_t *engine_state, const uint8_t *engine_load, const uint16_t *engine_rpm, float fuel_consumption_rate, const float *oil_pressure, const uint8_t *throttle_position, const float *engine_coolant_temperature, const uint8_t *transmission_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 8, fuel_consumption_rate);
    _mav_put_float_array(buf, 12, oil_pressure, 6);
    _mav_put_float_array(buf, 36, engine_coolant_temperature, 6);
    _mav_put_uint16_t_array(buf, 60, engine_rpm, 6);
    _mav_put_uint8_t_array(buf, 72, engine_state, 6);
    _mav_put_uint8_t_array(buf, 78, engine_load, 6);
    _mav_put_uint8_t_array(buf, 84, throttle_position, 6);
    _mav_put_uint8_t_array(buf, 90, transmission_state, 6);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2, buf, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_MIN_LEN, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_LEN, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_CRC);
#else
    mavlink_boat_engine_status_v2_t packet;
    packet.time_usec = time_usec;
    packet.fuel_consumption_rate = fuel_consumption_rate;
    mav_array_memcpy(packet.oil_pressure, oil_pressure, sizeof(float)*6);
    mav_array_memcpy(packet.engine_coolant_temperature, engine_coolant_temperature, sizeof(float)*6);
    mav_array_memcpy(packet.engine_rpm, engine_rpm, sizeof(uint16_t)*6);
    mav_array_memcpy(packet.engine_state, engine_state, sizeof(uint8_t)*6);
    mav_array_memcpy(packet.engine_load, engine_load, sizeof(uint8_t)*6);
    mav_array_memcpy(packet.throttle_position, throttle_position, sizeof(uint8_t)*6);
    mav_array_memcpy(packet.transmission_state, transmission_state, sizeof(uint8_t)*6);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2, (const char *)&packet, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_MIN_LEN, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_LEN, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_CRC);
#endif
}

/**
 * @brief Send a boat_engine_status_v2 message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
MAVLINK_WIP
static inline void mavlink_msg_boat_engine_status_v2_send_struct(mavlink_channel_t chan, const mavlink_boat_engine_status_v2_t* boat_engine_status_v2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_boat_engine_status_v2_send(chan, boat_engine_status_v2->time_usec, boat_engine_status_v2->engine_state, boat_engine_status_v2->engine_load, boat_engine_status_v2->engine_rpm, boat_engine_status_v2->fuel_consumption_rate, boat_engine_status_v2->oil_pressure, boat_engine_status_v2->throttle_position, boat_engine_status_v2->engine_coolant_temperature, boat_engine_status_v2->transmission_state);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2, (const char *)boat_engine_status_v2, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_MIN_LEN, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_LEN, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_CRC);
#endif
}

#if MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
MAVLINK_WIP
static inline void mavlink_msg_boat_engine_status_v2_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, const uint8_t *engine_state, const uint8_t *engine_load, const uint16_t *engine_rpm, float fuel_consumption_rate, const float *oil_pressure, const uint8_t *throttle_position, const float *engine_coolant_temperature, const uint8_t *transmission_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 8, fuel_consumption_rate);
    _mav_put_float_array(buf, 12, oil_pressure, 6);
    _mav_put_float_array(buf, 36, engine_coolant_temperature, 6);
    _mav_put_uint16_t_array(buf, 60, engine_rpm, 6);
    _mav_put_uint8_t_array(buf, 72, engine_state, 6);
    _mav_put_uint8_t_array(buf, 78, engine_load, 6);
    _mav_put_uint8_t_array(buf, 84, throttle_position, 6);
    _mav_put_uint8_t_array(buf, 90, transmission_state, 6);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2, buf, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_MIN_LEN, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_LEN, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_CRC);
#else
    mavlink_boat_engine_status_v2_t *packet = (mavlink_boat_engine_status_v2_t *)msgbuf;
    packet->time_usec = time_usec;
    packet->fuel_consumption_rate = fuel_consumption_rate;
    mav_array_memcpy(packet->oil_pressure, oil_pressure, sizeof(float)*6);
    mav_array_memcpy(packet->engine_coolant_temperature, engine_coolant_temperature, sizeof(float)*6);
    mav_array_memcpy(packet->engine_rpm, engine_rpm, sizeof(uint16_t)*6);
    mav_array_memcpy(packet->engine_state, engine_state, sizeof(uint8_t)*6);
    mav_array_memcpy(packet->engine_load, engine_load, sizeof(uint8_t)*6);
    mav_array_memcpy(packet->throttle_position, throttle_position, sizeof(uint8_t)*6);
    mav_array_memcpy(packet->transmission_state, transmission_state, sizeof(uint8_t)*6);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2, (const char *)packet, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_MIN_LEN, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_LEN, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_CRC);
#endif
}
#endif

#endif

// MESSAGE BOAT_ENGINE_STATUS_V2 UNPACKING


/**
 * @brief Get field time_usec from boat_engine_status_v2 message
 *
 * @return [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 */
MAVLINK_WIP
static inline uint64_t mavlink_msg_boat_engine_status_v2_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field engine_state from boat_engine_status_v2 message
 *
 * @return  Engine state.
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_boat_engine_status_v2_get_engine_state(const mavlink_message_t* msg, uint8_t *engine_state)
{
    return _MAV_RETURN_uint8_t_array(msg, engine_state, 6,  72);
}

/**
 * @brief Get field engine_load from boat_engine_status_v2 message
 *
 * @return [%] Engine load.
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_boat_engine_status_v2_get_engine_load(const mavlink_message_t* msg, uint8_t *engine_load)
{
    return _MAV_RETURN_uint8_t_array(msg, engine_load, 6,  78);
}

/**
 * @brief Get field engine_rpm from boat_engine_status_v2 message
 *
 * @return [rpm] Engine RPM.
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_boat_engine_status_v2_get_engine_rpm(const mavlink_message_t* msg, uint16_t *engine_rpm)
{
    return _MAV_RETURN_uint16_t_array(msg, engine_rpm, 6,  60);
}

/**
 * @brief Get field fuel_consumption_rate from boat_engine_status_v2 message
 *
 * @return [L/h] Fuel consumption rate.
 */
MAVLINK_WIP
static inline float mavlink_msg_boat_engine_status_v2_get_fuel_consumption_rate(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field oil_pressure from boat_engine_status_v2 message
 *
 * @return [kPa] Engine oil pressure.
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_boat_engine_status_v2_get_oil_pressure(const mavlink_message_t* msg, float *oil_pressure)
{
    return _MAV_RETURN_float_array(msg, oil_pressure, 6,  12);
}

/**
 * @brief Get field throttle_position from boat_engine_status_v2 message
 *
 * @return [%] Throttle position.
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_boat_engine_status_v2_get_throttle_position(const mavlink_message_t* msg, uint8_t *throttle_position)
{
    return _MAV_RETURN_uint8_t_array(msg, throttle_position, 6,  84);
}

/**
 * @brief Get field engine_coolant_temperature from boat_engine_status_v2 message
 *
 * @return [degC] Engine coolant temperature.
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_boat_engine_status_v2_get_engine_coolant_temperature(const mavlink_message_t* msg, float *engine_coolant_temperature)
{
    return _MAV_RETURN_float_array(msg, engine_coolant_temperature, 6,  36);
}

/**
 * @brief Get field transmission_state from boat_engine_status_v2 message
 *
 * @return  Transmission state.
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_boat_engine_status_v2_get_transmission_state(const mavlink_message_t* msg, uint8_t *transmission_state)
{
    return _MAV_RETURN_uint8_t_array(msg, transmission_state, 6,  90);
}

/**
 * @brief Decode a boat_engine_status_v2 message into a struct
 *
 * @param msg The message to decode
 * @param boat_engine_status_v2 C-struct to decode the message contents into
 */
MAVLINK_WIP
static inline void mavlink_msg_boat_engine_status_v2_decode(const mavlink_message_t* msg, mavlink_boat_engine_status_v2_t* boat_engine_status_v2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    boat_engine_status_v2->time_usec = mavlink_msg_boat_engine_status_v2_get_time_usec(msg);
    boat_engine_status_v2->fuel_consumption_rate = mavlink_msg_boat_engine_status_v2_get_fuel_consumption_rate(msg);
    mavlink_msg_boat_engine_status_v2_get_oil_pressure(msg, boat_engine_status_v2->oil_pressure);
    mavlink_msg_boat_engine_status_v2_get_engine_coolant_temperature(msg, boat_engine_status_v2->engine_coolant_temperature);
    mavlink_msg_boat_engine_status_v2_get_engine_rpm(msg, boat_engine_status_v2->engine_rpm);
    mavlink_msg_boat_engine_status_v2_get_engine_state(msg, boat_engine_status_v2->engine_state);
    mavlink_msg_boat_engine_status_v2_get_engine_load(msg, boat_engine_status_v2->engine_load);
    mavlink_msg_boat_engine_status_v2_get_throttle_position(msg, boat_engine_status_v2->throttle_position);
    mavlink_msg_boat_engine_status_v2_get_transmission_state(msg, boat_engine_status_v2->transmission_state);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_LEN? msg->len : MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_LEN;
        memset(boat_engine_status_v2, 0, MAVLINK_MSG_ID_BOAT_ENGINE_STATUS_V2_LEN);
    memcpy(boat_engine_status_v2, _MAV_PAYLOAD(msg), len);
#endif
}
