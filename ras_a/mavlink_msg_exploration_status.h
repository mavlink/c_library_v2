#pragma once
// MESSAGE EXPLORATION_STATUS PACKING

#define MAVLINK_MSG_ID_EXPLORATION_STATUS 450


typedef struct __mavlink_exploration_status_t {
 uint64_t time_usec; /*< [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.*/
 uint64_t time_to_timeout; /*< [us] Remaining time for the vehicle to execute the exploration task, after which another predefined behavior is triggered. UINT64_MAX when unknown or not applicable.*/
 uint16_t progress; /*<  Progress measurement of the exploration task. Specific meaning may vary by implementation, but in general, increasing values mean more has been explored. UINT16_MAX when unknown or not applicable.*/
 uint16_t denominator; /*<  Measurement of the known size of the exploration task. Specific meaning may vary, but when progress == denominator, this should imply that exploration is complete. This value may increase as more need to explore is discovered, or may be fixed (100 recommended) if the end state is known (e.g., exploration in a known mapped environment). 0 when no meaningful size can be communicated.*/
 uint16_t flags; /*<  Bitmap of the exploration task status flags.*/
 uint8_t exploration_id; /*<  ID of the exploration task. 255 if not applicable or unknown.*/
 int8_t level; /*<  In an indoor exploration task, it indicates the floor/level of the structure that is currently being explored. The level where the vehicle started the exploration is considered the level 0. INT8_MAX when unknown, not capable to provide or not applicable.*/
} mavlink_exploration_status_t;

#define MAVLINK_MSG_ID_EXPLORATION_STATUS_LEN 24
#define MAVLINK_MSG_ID_EXPLORATION_STATUS_MIN_LEN 24
#define MAVLINK_MSG_ID_450_LEN 24
#define MAVLINK_MSG_ID_450_MIN_LEN 24

#define MAVLINK_MSG_ID_EXPLORATION_STATUS_CRC 86
#define MAVLINK_MSG_ID_450_CRC 86



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_EXPLORATION_STATUS { \
    450, \
    "EXPLORATION_STATUS", \
    7, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_exploration_status_t, time_usec) }, \
         { "time_to_timeout", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_exploration_status_t, time_to_timeout) }, \
         { "exploration_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 22, offsetof(mavlink_exploration_status_t, exploration_id) }, \
         { "progress", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_exploration_status_t, progress) }, \
         { "denominator", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_exploration_status_t, denominator) }, \
         { "flags", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_exploration_status_t, flags) }, \
         { "level", NULL, MAVLINK_TYPE_INT8_T, 0, 23, offsetof(mavlink_exploration_status_t, level) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_EXPLORATION_STATUS { \
    "EXPLORATION_STATUS", \
    7, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_exploration_status_t, time_usec) }, \
         { "time_to_timeout", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_exploration_status_t, time_to_timeout) }, \
         { "exploration_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 22, offsetof(mavlink_exploration_status_t, exploration_id) }, \
         { "progress", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_exploration_status_t, progress) }, \
         { "denominator", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_exploration_status_t, denominator) }, \
         { "flags", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_exploration_status_t, flags) }, \
         { "level", NULL, MAVLINK_TYPE_INT8_T, 0, 23, offsetof(mavlink_exploration_status_t, level) }, \
         } \
}
#endif

/**
 * @brief Pack a exploration_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param time_to_timeout [us] Remaining time for the vehicle to execute the exploration task, after which another predefined behavior is triggered. UINT64_MAX when unknown or not applicable.
 * @param exploration_id  ID of the exploration task. 255 if not applicable or unknown.
 * @param progress  Progress measurement of the exploration task. Specific meaning may vary by implementation, but in general, increasing values mean more has been explored. UINT16_MAX when unknown or not applicable.
 * @param denominator  Measurement of the known size of the exploration task. Specific meaning may vary, but when progress == denominator, this should imply that exploration is complete. This value may increase as more need to explore is discovered, or may be fixed (100 recommended) if the end state is known (e.g., exploration in a known mapped environment). 0 when no meaningful size can be communicated.
 * @param flags  Bitmap of the exploration task status flags.
 * @param level  In an indoor exploration task, it indicates the floor/level of the structure that is currently being explored. The level where the vehicle started the exploration is considered the level 0. INT8_MAX when unknown, not capable to provide or not applicable.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_exploration_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, uint64_t time_to_timeout, uint8_t exploration_id, uint16_t progress, uint16_t denominator, uint16_t flags, int8_t level)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EXPLORATION_STATUS_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint64_t(buf, 8, time_to_timeout);
    _mav_put_uint16_t(buf, 16, progress);
    _mav_put_uint16_t(buf, 18, denominator);
    _mav_put_uint16_t(buf, 20, flags);
    _mav_put_uint8_t(buf, 22, exploration_id);
    _mav_put_int8_t(buf, 23, level);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EXPLORATION_STATUS_LEN);
#else
    mavlink_exploration_status_t packet;
    packet.time_usec = time_usec;
    packet.time_to_timeout = time_to_timeout;
    packet.progress = progress;
    packet.denominator = denominator;
    packet.flags = flags;
    packet.exploration_id = exploration_id;
    packet.level = level;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EXPLORATION_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EXPLORATION_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_EXPLORATION_STATUS_MIN_LEN, MAVLINK_MSG_ID_EXPLORATION_STATUS_LEN, MAVLINK_MSG_ID_EXPLORATION_STATUS_CRC);
}

/**
 * @brief Pack a exploration_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param time_to_timeout [us] Remaining time for the vehicle to execute the exploration task, after which another predefined behavior is triggered. UINT64_MAX when unknown or not applicable.
 * @param exploration_id  ID of the exploration task. 255 if not applicable or unknown.
 * @param progress  Progress measurement of the exploration task. Specific meaning may vary by implementation, but in general, increasing values mean more has been explored. UINT16_MAX when unknown or not applicable.
 * @param denominator  Measurement of the known size of the exploration task. Specific meaning may vary, but when progress == denominator, this should imply that exploration is complete. This value may increase as more need to explore is discovered, or may be fixed (100 recommended) if the end state is known (e.g., exploration in a known mapped environment). 0 when no meaningful size can be communicated.
 * @param flags  Bitmap of the exploration task status flags.
 * @param level  In an indoor exploration task, it indicates the floor/level of the structure that is currently being explored. The level where the vehicle started the exploration is considered the level 0. INT8_MAX when unknown, not capable to provide or not applicable.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_exploration_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,uint64_t time_to_timeout,uint8_t exploration_id,uint16_t progress,uint16_t denominator,uint16_t flags,int8_t level)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EXPLORATION_STATUS_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint64_t(buf, 8, time_to_timeout);
    _mav_put_uint16_t(buf, 16, progress);
    _mav_put_uint16_t(buf, 18, denominator);
    _mav_put_uint16_t(buf, 20, flags);
    _mav_put_uint8_t(buf, 22, exploration_id);
    _mav_put_int8_t(buf, 23, level);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EXPLORATION_STATUS_LEN);
#else
    mavlink_exploration_status_t packet;
    packet.time_usec = time_usec;
    packet.time_to_timeout = time_to_timeout;
    packet.progress = progress;
    packet.denominator = denominator;
    packet.flags = flags;
    packet.exploration_id = exploration_id;
    packet.level = level;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EXPLORATION_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EXPLORATION_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_EXPLORATION_STATUS_MIN_LEN, MAVLINK_MSG_ID_EXPLORATION_STATUS_LEN, MAVLINK_MSG_ID_EXPLORATION_STATUS_CRC);
}

/**
 * @brief Encode a exploration_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param exploration_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_exploration_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_exploration_status_t* exploration_status)
{
    return mavlink_msg_exploration_status_pack(system_id, component_id, msg, exploration_status->time_usec, exploration_status->time_to_timeout, exploration_status->exploration_id, exploration_status->progress, exploration_status->denominator, exploration_status->flags, exploration_status->level);
}

/**
 * @brief Encode a exploration_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param exploration_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_exploration_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_exploration_status_t* exploration_status)
{
    return mavlink_msg_exploration_status_pack_chan(system_id, component_id, chan, msg, exploration_status->time_usec, exploration_status->time_to_timeout, exploration_status->exploration_id, exploration_status->progress, exploration_status->denominator, exploration_status->flags, exploration_status->level);
}

/**
 * @brief Send a exploration_status message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param time_to_timeout [us] Remaining time for the vehicle to execute the exploration task, after which another predefined behavior is triggered. UINT64_MAX when unknown or not applicable.
 * @param exploration_id  ID of the exploration task. 255 if not applicable or unknown.
 * @param progress  Progress measurement of the exploration task. Specific meaning may vary by implementation, but in general, increasing values mean more has been explored. UINT16_MAX when unknown or not applicable.
 * @param denominator  Measurement of the known size of the exploration task. Specific meaning may vary, but when progress == denominator, this should imply that exploration is complete. This value may increase as more need to explore is discovered, or may be fixed (100 recommended) if the end state is known (e.g., exploration in a known mapped environment). 0 when no meaningful size can be communicated.
 * @param flags  Bitmap of the exploration task status flags.
 * @param level  In an indoor exploration task, it indicates the floor/level of the structure that is currently being explored. The level where the vehicle started the exploration is considered the level 0. INT8_MAX when unknown, not capable to provide or not applicable.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_exploration_status_send(mavlink_channel_t chan, uint64_t time_usec, uint64_t time_to_timeout, uint8_t exploration_id, uint16_t progress, uint16_t denominator, uint16_t flags, int8_t level)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EXPLORATION_STATUS_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint64_t(buf, 8, time_to_timeout);
    _mav_put_uint16_t(buf, 16, progress);
    _mav_put_uint16_t(buf, 18, denominator);
    _mav_put_uint16_t(buf, 20, flags);
    _mav_put_uint8_t(buf, 22, exploration_id);
    _mav_put_int8_t(buf, 23, level);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXPLORATION_STATUS, buf, MAVLINK_MSG_ID_EXPLORATION_STATUS_MIN_LEN, MAVLINK_MSG_ID_EXPLORATION_STATUS_LEN, MAVLINK_MSG_ID_EXPLORATION_STATUS_CRC);
#else
    mavlink_exploration_status_t packet;
    packet.time_usec = time_usec;
    packet.time_to_timeout = time_to_timeout;
    packet.progress = progress;
    packet.denominator = denominator;
    packet.flags = flags;
    packet.exploration_id = exploration_id;
    packet.level = level;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXPLORATION_STATUS, (const char *)&packet, MAVLINK_MSG_ID_EXPLORATION_STATUS_MIN_LEN, MAVLINK_MSG_ID_EXPLORATION_STATUS_LEN, MAVLINK_MSG_ID_EXPLORATION_STATUS_CRC);
#endif
}

/**
 * @brief Send a exploration_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_exploration_status_send_struct(mavlink_channel_t chan, const mavlink_exploration_status_t* exploration_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_exploration_status_send(chan, exploration_status->time_usec, exploration_status->time_to_timeout, exploration_status->exploration_id, exploration_status->progress, exploration_status->denominator, exploration_status->flags, exploration_status->level);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXPLORATION_STATUS, (const char *)exploration_status, MAVLINK_MSG_ID_EXPLORATION_STATUS_MIN_LEN, MAVLINK_MSG_ID_EXPLORATION_STATUS_LEN, MAVLINK_MSG_ID_EXPLORATION_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_EXPLORATION_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_exploration_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, uint64_t time_to_timeout, uint8_t exploration_id, uint16_t progress, uint16_t denominator, uint16_t flags, int8_t level)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint64_t(buf, 8, time_to_timeout);
    _mav_put_uint16_t(buf, 16, progress);
    _mav_put_uint16_t(buf, 18, denominator);
    _mav_put_uint16_t(buf, 20, flags);
    _mav_put_uint8_t(buf, 22, exploration_id);
    _mav_put_int8_t(buf, 23, level);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXPLORATION_STATUS, buf, MAVLINK_MSG_ID_EXPLORATION_STATUS_MIN_LEN, MAVLINK_MSG_ID_EXPLORATION_STATUS_LEN, MAVLINK_MSG_ID_EXPLORATION_STATUS_CRC);
#else
    mavlink_exploration_status_t *packet = (mavlink_exploration_status_t *)msgbuf;
    packet->time_usec = time_usec;
    packet->time_to_timeout = time_to_timeout;
    packet->progress = progress;
    packet->denominator = denominator;
    packet->flags = flags;
    packet->exploration_id = exploration_id;
    packet->level = level;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXPLORATION_STATUS, (const char *)packet, MAVLINK_MSG_ID_EXPLORATION_STATUS_MIN_LEN, MAVLINK_MSG_ID_EXPLORATION_STATUS_LEN, MAVLINK_MSG_ID_EXPLORATION_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE EXPLORATION_STATUS UNPACKING


/**
 * @brief Get field time_usec from exploration_status message
 *
 * @return [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 */
static inline uint64_t mavlink_msg_exploration_status_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field time_to_timeout from exploration_status message
 *
 * @return [us] Remaining time for the vehicle to execute the exploration task, after which another predefined behavior is triggered. UINT64_MAX when unknown or not applicable.
 */
static inline uint64_t mavlink_msg_exploration_status_get_time_to_timeout(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  8);
}

/**
 * @brief Get field exploration_id from exploration_status message
 *
 * @return  ID of the exploration task. 255 if not applicable or unknown.
 */
static inline uint8_t mavlink_msg_exploration_status_get_exploration_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  22);
}

/**
 * @brief Get field progress from exploration_status message
 *
 * @return  Progress measurement of the exploration task. Specific meaning may vary by implementation, but in general, increasing values mean more has been explored. UINT16_MAX when unknown or not applicable.
 */
static inline uint16_t mavlink_msg_exploration_status_get_progress(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  16);
}

/**
 * @brief Get field denominator from exploration_status message
 *
 * @return  Measurement of the known size of the exploration task. Specific meaning may vary, but when progress == denominator, this should imply that exploration is complete. This value may increase as more need to explore is discovered, or may be fixed (100 recommended) if the end state is known (e.g., exploration in a known mapped environment). 0 when no meaningful size can be communicated.
 */
static inline uint16_t mavlink_msg_exploration_status_get_denominator(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  18);
}

/**
 * @brief Get field flags from exploration_status message
 *
 * @return  Bitmap of the exploration task status flags.
 */
static inline uint16_t mavlink_msg_exploration_status_get_flags(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  20);
}

/**
 * @brief Get field level from exploration_status message
 *
 * @return  In an indoor exploration task, it indicates the floor/level of the structure that is currently being explored. The level where the vehicle started the exploration is considered the level 0. INT8_MAX when unknown, not capable to provide or not applicable.
 */
static inline int8_t mavlink_msg_exploration_status_get_level(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  23);
}

/**
 * @brief Decode a exploration_status message into a struct
 *
 * @param msg The message to decode
 * @param exploration_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_exploration_status_decode(const mavlink_message_t* msg, mavlink_exploration_status_t* exploration_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    exploration_status->time_usec = mavlink_msg_exploration_status_get_time_usec(msg);
    exploration_status->time_to_timeout = mavlink_msg_exploration_status_get_time_to_timeout(msg);
    exploration_status->progress = mavlink_msg_exploration_status_get_progress(msg);
    exploration_status->denominator = mavlink_msg_exploration_status_get_denominator(msg);
    exploration_status->flags = mavlink_msg_exploration_status_get_flags(msg);
    exploration_status->exploration_id = mavlink_msg_exploration_status_get_exploration_id(msg);
    exploration_status->level = mavlink_msg_exploration_status_get_level(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_EXPLORATION_STATUS_LEN? msg->len : MAVLINK_MSG_ID_EXPLORATION_STATUS_LEN;
        memset(exploration_status, 0, MAVLINK_MSG_ID_EXPLORATION_STATUS_LEN);
    memcpy(exploration_status, _MAV_PAYLOAD(msg), len);
#endif
}
