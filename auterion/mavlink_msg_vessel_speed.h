#pragma once
// MESSAGE VESSEL_SPEED PACKING

#define MAVLINK_MSG_ID_VESSEL_SPEED 13669


typedef struct __mavlink_vessel_speed_t {
 uint64_t time_usec; /*< [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.*/
 float speed_water_referenced; /*< [m/s] Speed water referenced.*/
 float speed_ground_referenced; /*< [m/s] Speed ground referenced.*/
 uint8_t speed_water_referenced_type; /*<  Speed water referenced type.*/
 uint8_t speed_direction; /*<  Speed direction.*/
} mavlink_vessel_speed_t;

#define MAVLINK_MSG_ID_VESSEL_SPEED_LEN 18
#define MAVLINK_MSG_ID_VESSEL_SPEED_MIN_LEN 18
#define MAVLINK_MSG_ID_13669_LEN 18
#define MAVLINK_MSG_ID_13669_MIN_LEN 18

#define MAVLINK_MSG_ID_VESSEL_SPEED_CRC 228
#define MAVLINK_MSG_ID_13669_CRC 228



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_VESSEL_SPEED { \
    13669, \
    "VESSEL_SPEED", \
    5, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_vessel_speed_t, time_usec) }, \
         { "speed_water_referenced", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_vessel_speed_t, speed_water_referenced) }, \
         { "speed_ground_referenced", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_vessel_speed_t, speed_ground_referenced) }, \
         { "speed_water_referenced_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_vessel_speed_t, speed_water_referenced_type) }, \
         { "speed_direction", NULL, MAVLINK_TYPE_UINT8_T, 0, 17, offsetof(mavlink_vessel_speed_t, speed_direction) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_VESSEL_SPEED { \
    "VESSEL_SPEED", \
    5, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_vessel_speed_t, time_usec) }, \
         { "speed_water_referenced", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_vessel_speed_t, speed_water_referenced) }, \
         { "speed_ground_referenced", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_vessel_speed_t, speed_ground_referenced) }, \
         { "speed_water_referenced_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_vessel_speed_t, speed_water_referenced_type) }, \
         { "speed_direction", NULL, MAVLINK_TYPE_UINT8_T, 0, 17, offsetof(mavlink_vessel_speed_t, speed_direction) }, \
         } \
}
#endif

/**
 * @brief Pack a vessel_speed message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param speed_water_referenced [m/s] Speed water referenced.
 * @param speed_ground_referenced [m/s] Speed ground referenced.
 * @param speed_water_referenced_type  Speed water referenced type.
 * @param speed_direction  Speed direction.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vessel_speed_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, float speed_water_referenced, float speed_ground_referenced, uint8_t speed_water_referenced_type, uint8_t speed_direction)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VESSEL_SPEED_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 8, speed_water_referenced);
    _mav_put_float(buf, 12, speed_ground_referenced);
    _mav_put_uint8_t(buf, 16, speed_water_referenced_type);
    _mav_put_uint8_t(buf, 17, speed_direction);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VESSEL_SPEED_LEN);
#else
    mavlink_vessel_speed_t packet;
    packet.time_usec = time_usec;
    packet.speed_water_referenced = speed_water_referenced;
    packet.speed_ground_referenced = speed_ground_referenced;
    packet.speed_water_referenced_type = speed_water_referenced_type;
    packet.speed_direction = speed_direction;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VESSEL_SPEED_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VESSEL_SPEED;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VESSEL_SPEED_MIN_LEN, MAVLINK_MSG_ID_VESSEL_SPEED_LEN, MAVLINK_MSG_ID_VESSEL_SPEED_CRC);
}

/**
 * @brief Pack a vessel_speed message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param speed_water_referenced [m/s] Speed water referenced.
 * @param speed_ground_referenced [m/s] Speed ground referenced.
 * @param speed_water_referenced_type  Speed water referenced type.
 * @param speed_direction  Speed direction.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vessel_speed_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint64_t time_usec, float speed_water_referenced, float speed_ground_referenced, uint8_t speed_water_referenced_type, uint8_t speed_direction)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VESSEL_SPEED_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 8, speed_water_referenced);
    _mav_put_float(buf, 12, speed_ground_referenced);
    _mav_put_uint8_t(buf, 16, speed_water_referenced_type);
    _mav_put_uint8_t(buf, 17, speed_direction);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VESSEL_SPEED_LEN);
#else
    mavlink_vessel_speed_t packet;
    packet.time_usec = time_usec;
    packet.speed_water_referenced = speed_water_referenced;
    packet.speed_ground_referenced = speed_ground_referenced;
    packet.speed_water_referenced_type = speed_water_referenced_type;
    packet.speed_direction = speed_direction;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VESSEL_SPEED_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VESSEL_SPEED;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_VESSEL_SPEED_MIN_LEN, MAVLINK_MSG_ID_VESSEL_SPEED_LEN, MAVLINK_MSG_ID_VESSEL_SPEED_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_VESSEL_SPEED_MIN_LEN, MAVLINK_MSG_ID_VESSEL_SPEED_LEN);
#endif
}

/**
 * @brief Pack a vessel_speed message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param speed_water_referenced [m/s] Speed water referenced.
 * @param speed_ground_referenced [m/s] Speed ground referenced.
 * @param speed_water_referenced_type  Speed water referenced type.
 * @param speed_direction  Speed direction.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vessel_speed_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,float speed_water_referenced,float speed_ground_referenced,uint8_t speed_water_referenced_type,uint8_t speed_direction)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VESSEL_SPEED_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 8, speed_water_referenced);
    _mav_put_float(buf, 12, speed_ground_referenced);
    _mav_put_uint8_t(buf, 16, speed_water_referenced_type);
    _mav_put_uint8_t(buf, 17, speed_direction);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VESSEL_SPEED_LEN);
#else
    mavlink_vessel_speed_t packet;
    packet.time_usec = time_usec;
    packet.speed_water_referenced = speed_water_referenced;
    packet.speed_ground_referenced = speed_ground_referenced;
    packet.speed_water_referenced_type = speed_water_referenced_type;
    packet.speed_direction = speed_direction;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VESSEL_SPEED_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VESSEL_SPEED;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_VESSEL_SPEED_MIN_LEN, MAVLINK_MSG_ID_VESSEL_SPEED_LEN, MAVLINK_MSG_ID_VESSEL_SPEED_CRC);
}

/**
 * @brief Encode a vessel_speed struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param vessel_speed C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vessel_speed_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_vessel_speed_t* vessel_speed)
{
    return mavlink_msg_vessel_speed_pack(system_id, component_id, msg, vessel_speed->time_usec, vessel_speed->speed_water_referenced, vessel_speed->speed_ground_referenced, vessel_speed->speed_water_referenced_type, vessel_speed->speed_direction);
}

/**
 * @brief Encode a vessel_speed struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param vessel_speed C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vessel_speed_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_vessel_speed_t* vessel_speed)
{
    return mavlink_msg_vessel_speed_pack_chan(system_id, component_id, chan, msg, vessel_speed->time_usec, vessel_speed->speed_water_referenced, vessel_speed->speed_ground_referenced, vessel_speed->speed_water_referenced_type, vessel_speed->speed_direction);
}

/**
 * @brief Encode a vessel_speed struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param vessel_speed C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vessel_speed_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_vessel_speed_t* vessel_speed)
{
    return mavlink_msg_vessel_speed_pack_status(system_id, component_id, _status, msg,  vessel_speed->time_usec, vessel_speed->speed_water_referenced, vessel_speed->speed_ground_referenced, vessel_speed->speed_water_referenced_type, vessel_speed->speed_direction);
}

/**
 * @brief Send a vessel_speed message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param speed_water_referenced [m/s] Speed water referenced.
 * @param speed_ground_referenced [m/s] Speed ground referenced.
 * @param speed_water_referenced_type  Speed water referenced type.
 * @param speed_direction  Speed direction.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_vessel_speed_send(mavlink_channel_t chan, uint64_t time_usec, float speed_water_referenced, float speed_ground_referenced, uint8_t speed_water_referenced_type, uint8_t speed_direction)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VESSEL_SPEED_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 8, speed_water_referenced);
    _mav_put_float(buf, 12, speed_ground_referenced);
    _mav_put_uint8_t(buf, 16, speed_water_referenced_type);
    _mav_put_uint8_t(buf, 17, speed_direction);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VESSEL_SPEED, buf, MAVLINK_MSG_ID_VESSEL_SPEED_MIN_LEN, MAVLINK_MSG_ID_VESSEL_SPEED_LEN, MAVLINK_MSG_ID_VESSEL_SPEED_CRC);
#else
    mavlink_vessel_speed_t packet;
    packet.time_usec = time_usec;
    packet.speed_water_referenced = speed_water_referenced;
    packet.speed_ground_referenced = speed_ground_referenced;
    packet.speed_water_referenced_type = speed_water_referenced_type;
    packet.speed_direction = speed_direction;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VESSEL_SPEED, (const char *)&packet, MAVLINK_MSG_ID_VESSEL_SPEED_MIN_LEN, MAVLINK_MSG_ID_VESSEL_SPEED_LEN, MAVLINK_MSG_ID_VESSEL_SPEED_CRC);
#endif
}

/**
 * @brief Send a vessel_speed message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_vessel_speed_send_struct(mavlink_channel_t chan, const mavlink_vessel_speed_t* vessel_speed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_vessel_speed_send(chan, vessel_speed->time_usec, vessel_speed->speed_water_referenced, vessel_speed->speed_ground_referenced, vessel_speed->speed_water_referenced_type, vessel_speed->speed_direction);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VESSEL_SPEED, (const char *)vessel_speed, MAVLINK_MSG_ID_VESSEL_SPEED_MIN_LEN, MAVLINK_MSG_ID_VESSEL_SPEED_LEN, MAVLINK_MSG_ID_VESSEL_SPEED_CRC);
#endif
}

#if MAVLINK_MSG_ID_VESSEL_SPEED_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_vessel_speed_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, float speed_water_referenced, float speed_ground_referenced, uint8_t speed_water_referenced_type, uint8_t speed_direction)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 8, speed_water_referenced);
    _mav_put_float(buf, 12, speed_ground_referenced);
    _mav_put_uint8_t(buf, 16, speed_water_referenced_type);
    _mav_put_uint8_t(buf, 17, speed_direction);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VESSEL_SPEED, buf, MAVLINK_MSG_ID_VESSEL_SPEED_MIN_LEN, MAVLINK_MSG_ID_VESSEL_SPEED_LEN, MAVLINK_MSG_ID_VESSEL_SPEED_CRC);
#else
    mavlink_vessel_speed_t *packet = (mavlink_vessel_speed_t *)msgbuf;
    packet->time_usec = time_usec;
    packet->speed_water_referenced = speed_water_referenced;
    packet->speed_ground_referenced = speed_ground_referenced;
    packet->speed_water_referenced_type = speed_water_referenced_type;
    packet->speed_direction = speed_direction;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VESSEL_SPEED, (const char *)packet, MAVLINK_MSG_ID_VESSEL_SPEED_MIN_LEN, MAVLINK_MSG_ID_VESSEL_SPEED_LEN, MAVLINK_MSG_ID_VESSEL_SPEED_CRC);
#endif
}
#endif

#endif

// MESSAGE VESSEL_SPEED UNPACKING


/**
 * @brief Get field time_usec from vessel_speed message
 *
 * @return [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 */
static inline uint64_t mavlink_msg_vessel_speed_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field speed_water_referenced from vessel_speed message
 *
 * @return [m/s] Speed water referenced.
 */
static inline float mavlink_msg_vessel_speed_get_speed_water_referenced(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field speed_ground_referenced from vessel_speed message
 *
 * @return [m/s] Speed ground referenced.
 */
static inline float mavlink_msg_vessel_speed_get_speed_ground_referenced(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field speed_water_referenced_type from vessel_speed message
 *
 * @return  Speed water referenced type.
 */
static inline uint8_t mavlink_msg_vessel_speed_get_speed_water_referenced_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  16);
}

/**
 * @brief Get field speed_direction from vessel_speed message
 *
 * @return  Speed direction.
 */
static inline uint8_t mavlink_msg_vessel_speed_get_speed_direction(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  17);
}

/**
 * @brief Decode a vessel_speed message into a struct
 *
 * @param msg The message to decode
 * @param vessel_speed C-struct to decode the message contents into
 */
static inline void mavlink_msg_vessel_speed_decode(const mavlink_message_t* msg, mavlink_vessel_speed_t* vessel_speed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    vessel_speed->time_usec = mavlink_msg_vessel_speed_get_time_usec(msg);
    vessel_speed->speed_water_referenced = mavlink_msg_vessel_speed_get_speed_water_referenced(msg);
    vessel_speed->speed_ground_referenced = mavlink_msg_vessel_speed_get_speed_ground_referenced(msg);
    vessel_speed->speed_water_referenced_type = mavlink_msg_vessel_speed_get_speed_water_referenced_type(msg);
    vessel_speed->speed_direction = mavlink_msg_vessel_speed_get_speed_direction(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_VESSEL_SPEED_LEN? msg->len : MAVLINK_MSG_ID_VESSEL_SPEED_LEN;
        memset(vessel_speed, 0, MAVLINK_MSG_ID_VESSEL_SPEED_LEN);
    memcpy(vessel_speed, _MAV_PAYLOAD(msg), len);
#endif
}
