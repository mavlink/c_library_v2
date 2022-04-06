#pragma once
// MESSAGE TRACKER_STATUS PACKING

#define MAVLINK_MSG_ID_TRACKER_STATUS 500


typedef struct __mavlink_tracker_status_t {
 uint32_t tracked_object_id; /*<   The UID of the object currently being tracked.*/
 uint16_t number_objects_detected; /*<   Number of objects currently detected.*/
 uint8_t tracker_status; /*<   */
} mavlink_tracker_status_t;

#define MAVLINK_MSG_ID_TRACKER_STATUS_LEN 7
#define MAVLINK_MSG_ID_TRACKER_STATUS_MIN_LEN 7
#define MAVLINK_MSG_ID_500_LEN 7
#define MAVLINK_MSG_ID_500_MIN_LEN 7

#define MAVLINK_MSG_ID_TRACKER_STATUS_CRC 245
#define MAVLINK_MSG_ID_500_CRC 245



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TRACKER_STATUS { \
    500, \
    "TRACKER_STATUS", \
    3, \
    {  { "tracker_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_tracker_status_t, tracker_status) }, \
         { "number_objects_detected", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_tracker_status_t, number_objects_detected) }, \
         { "tracked_object_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_tracker_status_t, tracked_object_id) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TRACKER_STATUS { \
    "TRACKER_STATUS", \
    3, \
    {  { "tracker_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_tracker_status_t, tracker_status) }, \
         { "number_objects_detected", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_tracker_status_t, number_objects_detected) }, \
         { "tracked_object_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_tracker_status_t, tracked_object_id) }, \
         } \
}
#endif

/**
 * @brief Pack a tracker_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param tracker_status   
 * @param number_objects_detected   Number of objects currently detected.
 * @param tracked_object_id   The UID of the object currently being tracked.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tracker_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t tracker_status, uint16_t number_objects_detected, uint32_t tracked_object_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TRACKER_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, tracked_object_id);
    _mav_put_uint16_t(buf, 4, number_objects_detected);
    _mav_put_uint8_t(buf, 6, tracker_status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TRACKER_STATUS_LEN);
#else
    mavlink_tracker_status_t packet;
    packet.tracked_object_id = tracked_object_id;
    packet.number_objects_detected = number_objects_detected;
    packet.tracker_status = tracker_status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TRACKER_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TRACKER_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TRACKER_STATUS_MIN_LEN, MAVLINK_MSG_ID_TRACKER_STATUS_LEN, MAVLINK_MSG_ID_TRACKER_STATUS_CRC);
}

/**
 * @brief Pack a tracker_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param tracker_status   
 * @param number_objects_detected   Number of objects currently detected.
 * @param tracked_object_id   The UID of the object currently being tracked.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tracker_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t tracker_status,uint16_t number_objects_detected,uint32_t tracked_object_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TRACKER_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, tracked_object_id);
    _mav_put_uint16_t(buf, 4, number_objects_detected);
    _mav_put_uint8_t(buf, 6, tracker_status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TRACKER_STATUS_LEN);
#else
    mavlink_tracker_status_t packet;
    packet.tracked_object_id = tracked_object_id;
    packet.number_objects_detected = number_objects_detected;
    packet.tracker_status = tracker_status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TRACKER_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TRACKER_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TRACKER_STATUS_MIN_LEN, MAVLINK_MSG_ID_TRACKER_STATUS_LEN, MAVLINK_MSG_ID_TRACKER_STATUS_CRC);
}

/**
 * @brief Encode a tracker_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param tracker_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tracker_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_tracker_status_t* tracker_status)
{
    return mavlink_msg_tracker_status_pack(system_id, component_id, msg, tracker_status->tracker_status, tracker_status->number_objects_detected, tracker_status->tracked_object_id);
}

/**
 * @brief Encode a tracker_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param tracker_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tracker_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_tracker_status_t* tracker_status)
{
    return mavlink_msg_tracker_status_pack_chan(system_id, component_id, chan, msg, tracker_status->tracker_status, tracker_status->number_objects_detected, tracker_status->tracked_object_id);
}

/**
 * @brief Send a tracker_status message
 * @param chan MAVLink channel to send the message
 *
 * @param tracker_status   
 * @param number_objects_detected   Number of objects currently detected.
 * @param tracked_object_id   The UID of the object currently being tracked.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_tracker_status_send(mavlink_channel_t chan, uint8_t tracker_status, uint16_t number_objects_detected, uint32_t tracked_object_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TRACKER_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, tracked_object_id);
    _mav_put_uint16_t(buf, 4, number_objects_detected);
    _mav_put_uint8_t(buf, 6, tracker_status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRACKER_STATUS, buf, MAVLINK_MSG_ID_TRACKER_STATUS_MIN_LEN, MAVLINK_MSG_ID_TRACKER_STATUS_LEN, MAVLINK_MSG_ID_TRACKER_STATUS_CRC);
#else
    mavlink_tracker_status_t packet;
    packet.tracked_object_id = tracked_object_id;
    packet.number_objects_detected = number_objects_detected;
    packet.tracker_status = tracker_status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRACKER_STATUS, (const char *)&packet, MAVLINK_MSG_ID_TRACKER_STATUS_MIN_LEN, MAVLINK_MSG_ID_TRACKER_STATUS_LEN, MAVLINK_MSG_ID_TRACKER_STATUS_CRC);
#endif
}

/**
 * @brief Send a tracker_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_tracker_status_send_struct(mavlink_channel_t chan, const mavlink_tracker_status_t* tracker_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_tracker_status_send(chan, tracker_status->tracker_status, tracker_status->number_objects_detected, tracker_status->tracked_object_id);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRACKER_STATUS, (const char *)tracker_status, MAVLINK_MSG_ID_TRACKER_STATUS_MIN_LEN, MAVLINK_MSG_ID_TRACKER_STATUS_LEN, MAVLINK_MSG_ID_TRACKER_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_TRACKER_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_tracker_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t tracker_status, uint16_t number_objects_detected, uint32_t tracked_object_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, tracked_object_id);
    _mav_put_uint16_t(buf, 4, number_objects_detected);
    _mav_put_uint8_t(buf, 6, tracker_status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRACKER_STATUS, buf, MAVLINK_MSG_ID_TRACKER_STATUS_MIN_LEN, MAVLINK_MSG_ID_TRACKER_STATUS_LEN, MAVLINK_MSG_ID_TRACKER_STATUS_CRC);
#else
    mavlink_tracker_status_t *packet = (mavlink_tracker_status_t *)msgbuf;
    packet->tracked_object_id = tracked_object_id;
    packet->number_objects_detected = number_objects_detected;
    packet->tracker_status = tracker_status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRACKER_STATUS, (const char *)packet, MAVLINK_MSG_ID_TRACKER_STATUS_MIN_LEN, MAVLINK_MSG_ID_TRACKER_STATUS_LEN, MAVLINK_MSG_ID_TRACKER_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE TRACKER_STATUS UNPACKING


/**
 * @brief Get field tracker_status from tracker_status message
 *
 * @return   
 */
static inline uint8_t mavlink_msg_tracker_status_get_tracker_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field number_objects_detected from tracker_status message
 *
 * @return   Number of objects currently detected.
 */
static inline uint16_t mavlink_msg_tracker_status_get_number_objects_detected(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field tracked_object_id from tracker_status message
 *
 * @return   The UID of the object currently being tracked.
 */
static inline uint32_t mavlink_msg_tracker_status_get_tracked_object_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Decode a tracker_status message into a struct
 *
 * @param msg The message to decode
 * @param tracker_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_tracker_status_decode(const mavlink_message_t* msg, mavlink_tracker_status_t* tracker_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    tracker_status->tracked_object_id = mavlink_msg_tracker_status_get_tracked_object_id(msg);
    tracker_status->number_objects_detected = mavlink_msg_tracker_status_get_number_objects_detected(msg);
    tracker_status->tracker_status = mavlink_msg_tracker_status_get_tracker_status(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TRACKER_STATUS_LEN? msg->len : MAVLINK_MSG_ID_TRACKER_STATUS_LEN;
        memset(tracker_status, 0, MAVLINK_MSG_ID_TRACKER_STATUS_LEN);
    memcpy(tracker_status, _MAV_PAYLOAD(msg), len);
#endif
}
