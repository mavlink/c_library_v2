#pragma once
// MESSAGE WATER_DEPTH_RAW PACKING

#define MAVLINK_MSG_ID_WATER_DEPTH_RAW 13670


typedef struct __mavlink_water_depth_raw_t {
 uint64_t time_usec; /*< [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.*/
 float depth; /*< [m] Depth below transducer.*/
 float offset; /*< [m] Distance between transducer and surface (positive) or keel (negative).*/
 float range; /*< [m] Max measurement range.*/
} mavlink_water_depth_raw_t;

#define MAVLINK_MSG_ID_WATER_DEPTH_RAW_LEN 20
#define MAVLINK_MSG_ID_WATER_DEPTH_RAW_MIN_LEN 20
#define MAVLINK_MSG_ID_13670_LEN 20
#define MAVLINK_MSG_ID_13670_MIN_LEN 20

#define MAVLINK_MSG_ID_WATER_DEPTH_RAW_CRC 131
#define MAVLINK_MSG_ID_13670_CRC 131



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WATER_DEPTH_RAW { \
    13670, \
    "WATER_DEPTH_RAW", \
    4, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_water_depth_raw_t, time_usec) }, \
         { "depth", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_water_depth_raw_t, depth) }, \
         { "offset", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_water_depth_raw_t, offset) }, \
         { "range", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_water_depth_raw_t, range) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WATER_DEPTH_RAW { \
    "WATER_DEPTH_RAW", \
    4, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_water_depth_raw_t, time_usec) }, \
         { "depth", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_water_depth_raw_t, depth) }, \
         { "offset", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_water_depth_raw_t, offset) }, \
         { "range", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_water_depth_raw_t, range) }, \
         } \
}
#endif

/**
 * @brief Pack a water_depth_raw message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param depth [m] Depth below transducer.
 * @param offset [m] Distance between transducer and surface (positive) or keel (negative).
 * @param range [m] Max measurement range.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_water_depth_raw_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, float depth, float offset, float range)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WATER_DEPTH_RAW_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 8, depth);
    _mav_put_float(buf, 12, offset);
    _mav_put_float(buf, 16, range);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WATER_DEPTH_RAW_LEN);
#else
    mavlink_water_depth_raw_t packet;
    packet.time_usec = time_usec;
    packet.depth = depth;
    packet.offset = offset;
    packet.range = range;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WATER_DEPTH_RAW_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WATER_DEPTH_RAW;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WATER_DEPTH_RAW_MIN_LEN, MAVLINK_MSG_ID_WATER_DEPTH_RAW_LEN, MAVLINK_MSG_ID_WATER_DEPTH_RAW_CRC);
}

/**
 * @brief Pack a water_depth_raw message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param depth [m] Depth below transducer.
 * @param offset [m] Distance between transducer and surface (positive) or keel (negative).
 * @param range [m] Max measurement range.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_water_depth_raw_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint64_t time_usec, float depth, float offset, float range)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WATER_DEPTH_RAW_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 8, depth);
    _mav_put_float(buf, 12, offset);
    _mav_put_float(buf, 16, range);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WATER_DEPTH_RAW_LEN);
#else
    mavlink_water_depth_raw_t packet;
    packet.time_usec = time_usec;
    packet.depth = depth;
    packet.offset = offset;
    packet.range = range;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WATER_DEPTH_RAW_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WATER_DEPTH_RAW;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_WATER_DEPTH_RAW_MIN_LEN, MAVLINK_MSG_ID_WATER_DEPTH_RAW_LEN, MAVLINK_MSG_ID_WATER_DEPTH_RAW_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_WATER_DEPTH_RAW_MIN_LEN, MAVLINK_MSG_ID_WATER_DEPTH_RAW_LEN);
#endif
}

/**
 * @brief Pack a water_depth_raw message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param depth [m] Depth below transducer.
 * @param offset [m] Distance between transducer and surface (positive) or keel (negative).
 * @param range [m] Max measurement range.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_water_depth_raw_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,float depth,float offset,float range)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WATER_DEPTH_RAW_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 8, depth);
    _mav_put_float(buf, 12, offset);
    _mav_put_float(buf, 16, range);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WATER_DEPTH_RAW_LEN);
#else
    mavlink_water_depth_raw_t packet;
    packet.time_usec = time_usec;
    packet.depth = depth;
    packet.offset = offset;
    packet.range = range;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WATER_DEPTH_RAW_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WATER_DEPTH_RAW;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WATER_DEPTH_RAW_MIN_LEN, MAVLINK_MSG_ID_WATER_DEPTH_RAW_LEN, MAVLINK_MSG_ID_WATER_DEPTH_RAW_CRC);
}

/**
 * @brief Encode a water_depth_raw struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param water_depth_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_water_depth_raw_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_water_depth_raw_t* water_depth_raw)
{
    return mavlink_msg_water_depth_raw_pack(system_id, component_id, msg, water_depth_raw->time_usec, water_depth_raw->depth, water_depth_raw->offset, water_depth_raw->range);
}

/**
 * @brief Encode a water_depth_raw struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param water_depth_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_water_depth_raw_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_water_depth_raw_t* water_depth_raw)
{
    return mavlink_msg_water_depth_raw_pack_chan(system_id, component_id, chan, msg, water_depth_raw->time_usec, water_depth_raw->depth, water_depth_raw->offset, water_depth_raw->range);
}

/**
 * @brief Encode a water_depth_raw struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param water_depth_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_water_depth_raw_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_water_depth_raw_t* water_depth_raw)
{
    return mavlink_msg_water_depth_raw_pack_status(system_id, component_id, _status, msg,  water_depth_raw->time_usec, water_depth_raw->depth, water_depth_raw->offset, water_depth_raw->range);
}

/**
 * @brief Send a water_depth_raw message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param depth [m] Depth below transducer.
 * @param offset [m] Distance between transducer and surface (positive) or keel (negative).
 * @param range [m] Max measurement range.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_water_depth_raw_send(mavlink_channel_t chan, uint64_t time_usec, float depth, float offset, float range)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WATER_DEPTH_RAW_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 8, depth);
    _mav_put_float(buf, 12, offset);
    _mav_put_float(buf, 16, range);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WATER_DEPTH_RAW, buf, MAVLINK_MSG_ID_WATER_DEPTH_RAW_MIN_LEN, MAVLINK_MSG_ID_WATER_DEPTH_RAW_LEN, MAVLINK_MSG_ID_WATER_DEPTH_RAW_CRC);
#else
    mavlink_water_depth_raw_t packet;
    packet.time_usec = time_usec;
    packet.depth = depth;
    packet.offset = offset;
    packet.range = range;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WATER_DEPTH_RAW, (const char *)&packet, MAVLINK_MSG_ID_WATER_DEPTH_RAW_MIN_LEN, MAVLINK_MSG_ID_WATER_DEPTH_RAW_LEN, MAVLINK_MSG_ID_WATER_DEPTH_RAW_CRC);
#endif
}

/**
 * @brief Send a water_depth_raw message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_water_depth_raw_send_struct(mavlink_channel_t chan, const mavlink_water_depth_raw_t* water_depth_raw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_water_depth_raw_send(chan, water_depth_raw->time_usec, water_depth_raw->depth, water_depth_raw->offset, water_depth_raw->range);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WATER_DEPTH_RAW, (const char *)water_depth_raw, MAVLINK_MSG_ID_WATER_DEPTH_RAW_MIN_LEN, MAVLINK_MSG_ID_WATER_DEPTH_RAW_LEN, MAVLINK_MSG_ID_WATER_DEPTH_RAW_CRC);
#endif
}

#if MAVLINK_MSG_ID_WATER_DEPTH_RAW_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_water_depth_raw_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, float depth, float offset, float range)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 8, depth);
    _mav_put_float(buf, 12, offset);
    _mav_put_float(buf, 16, range);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WATER_DEPTH_RAW, buf, MAVLINK_MSG_ID_WATER_DEPTH_RAW_MIN_LEN, MAVLINK_MSG_ID_WATER_DEPTH_RAW_LEN, MAVLINK_MSG_ID_WATER_DEPTH_RAW_CRC);
#else
    mavlink_water_depth_raw_t *packet = (mavlink_water_depth_raw_t *)msgbuf;
    packet->time_usec = time_usec;
    packet->depth = depth;
    packet->offset = offset;
    packet->range = range;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WATER_DEPTH_RAW, (const char *)packet, MAVLINK_MSG_ID_WATER_DEPTH_RAW_MIN_LEN, MAVLINK_MSG_ID_WATER_DEPTH_RAW_LEN, MAVLINK_MSG_ID_WATER_DEPTH_RAW_CRC);
#endif
}
#endif

#endif

// MESSAGE WATER_DEPTH_RAW UNPACKING


/**
 * @brief Get field time_usec from water_depth_raw message
 *
 * @return [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 */
static inline uint64_t mavlink_msg_water_depth_raw_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field depth from water_depth_raw message
 *
 * @return [m] Depth below transducer.
 */
static inline float mavlink_msg_water_depth_raw_get_depth(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field offset from water_depth_raw message
 *
 * @return [m] Distance between transducer and surface (positive) or keel (negative).
 */
static inline float mavlink_msg_water_depth_raw_get_offset(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field range from water_depth_raw message
 *
 * @return [m] Max measurement range.
 */
static inline float mavlink_msg_water_depth_raw_get_range(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Decode a water_depth_raw message into a struct
 *
 * @param msg The message to decode
 * @param water_depth_raw C-struct to decode the message contents into
 */
static inline void mavlink_msg_water_depth_raw_decode(const mavlink_message_t* msg, mavlink_water_depth_raw_t* water_depth_raw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    water_depth_raw->time_usec = mavlink_msg_water_depth_raw_get_time_usec(msg);
    water_depth_raw->depth = mavlink_msg_water_depth_raw_get_depth(msg);
    water_depth_raw->offset = mavlink_msg_water_depth_raw_get_offset(msg);
    water_depth_raw->range = mavlink_msg_water_depth_raw_get_range(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WATER_DEPTH_RAW_LEN? msg->len : MAVLINK_MSG_ID_WATER_DEPTH_RAW_LEN;
        memset(water_depth_raw, 0, MAVLINK_MSG_ID_WATER_DEPTH_RAW_LEN);
    memcpy(water_depth_raw, _MAV_PAYLOAD(msg), len);
#endif
}
