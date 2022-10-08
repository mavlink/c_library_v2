#pragma once
// MESSAGE RADIATION_DETECTOR_COUNTS PACKING

#define MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS 460


typedef struct __mavlink_radiation_detector_counts_t {
 double timestamp; /*< [s] Timestamp of measurement(UNIX Epoch time or time since detector boot)*/
 uint64_t counts; /*<  Accumulated detector counts*/
 uint64_t integration_time_usec; /*< [us] Integration period*/
 uint32_t serial_no; /*<  Detector serial number*/
 uint32_t rate; /*<   Detector count in the current dt integration period.*/
} mavlink_radiation_detector_counts_t;

#define MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS_LEN 32
#define MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS_MIN_LEN 32
#define MAVLINK_MSG_ID_460_LEN 32
#define MAVLINK_MSG_ID_460_MIN_LEN 32

#define MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS_CRC 228
#define MAVLINK_MSG_ID_460_CRC 228



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RADIATION_DETECTOR_COUNTS { \
    460, \
    "RADIATION_DETECTOR_COUNTS", \
    5, \
    {  { "serial_no", NULL, MAVLINK_TYPE_UINT32_T, 0, 24, offsetof(mavlink_radiation_detector_counts_t, serial_no) }, \
         { "timestamp", NULL, MAVLINK_TYPE_DOUBLE, 0, 0, offsetof(mavlink_radiation_detector_counts_t, timestamp) }, \
         { "counts", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_radiation_detector_counts_t, counts) }, \
         { "rate", NULL, MAVLINK_TYPE_UINT32_T, 0, 28, offsetof(mavlink_radiation_detector_counts_t, rate) }, \
         { "integration_time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 16, offsetof(mavlink_radiation_detector_counts_t, integration_time_usec) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_RADIATION_DETECTOR_COUNTS { \
    "RADIATION_DETECTOR_COUNTS", \
    5, \
    {  { "serial_no", NULL, MAVLINK_TYPE_UINT32_T, 0, 24, offsetof(mavlink_radiation_detector_counts_t, serial_no) }, \
         { "timestamp", NULL, MAVLINK_TYPE_DOUBLE, 0, 0, offsetof(mavlink_radiation_detector_counts_t, timestamp) }, \
         { "counts", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_radiation_detector_counts_t, counts) }, \
         { "rate", NULL, MAVLINK_TYPE_UINT32_T, 0, 28, offsetof(mavlink_radiation_detector_counts_t, rate) }, \
         { "integration_time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 16, offsetof(mavlink_radiation_detector_counts_t, integration_time_usec) }, \
         } \
}
#endif

/**
 * @brief Pack a radiation_detector_counts message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param serial_no  Detector serial number
 * @param timestamp [s] Timestamp of measurement(UNIX Epoch time or time since detector boot)
 * @param counts  Accumulated detector counts
 * @param rate   Detector count in the current dt integration period.
 * @param integration_time_usec [us] Integration period
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_radiation_detector_counts_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t serial_no, double timestamp, uint64_t counts, uint32_t rate, uint64_t integration_time_usec)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS_LEN];
    _mav_put_double(buf, 0, timestamp);
    _mav_put_uint64_t(buf, 8, counts);
    _mav_put_uint64_t(buf, 16, integration_time_usec);
    _mav_put_uint32_t(buf, 24, serial_no);
    _mav_put_uint32_t(buf, 28, rate);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS_LEN);
#else
    mavlink_radiation_detector_counts_t packet;
    packet.timestamp = timestamp;
    packet.counts = counts;
    packet.integration_time_usec = integration_time_usec;
    packet.serial_no = serial_no;
    packet.rate = rate;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS_MIN_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS_CRC);
}

/**
 * @brief Pack a radiation_detector_counts message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param serial_no  Detector serial number
 * @param timestamp [s] Timestamp of measurement(UNIX Epoch time or time since detector boot)
 * @param counts  Accumulated detector counts
 * @param rate   Detector count in the current dt integration period.
 * @param integration_time_usec [us] Integration period
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_radiation_detector_counts_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t serial_no,double timestamp,uint64_t counts,uint32_t rate,uint64_t integration_time_usec)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS_LEN];
    _mav_put_double(buf, 0, timestamp);
    _mav_put_uint64_t(buf, 8, counts);
    _mav_put_uint64_t(buf, 16, integration_time_usec);
    _mav_put_uint32_t(buf, 24, serial_no);
    _mav_put_uint32_t(buf, 28, rate);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS_LEN);
#else
    mavlink_radiation_detector_counts_t packet;
    packet.timestamp = timestamp;
    packet.counts = counts;
    packet.integration_time_usec = integration_time_usec;
    packet.serial_no = serial_no;
    packet.rate = rate;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS_MIN_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS_CRC);
}

/**
 * @brief Encode a radiation_detector_counts struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param radiation_detector_counts C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_radiation_detector_counts_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_radiation_detector_counts_t* radiation_detector_counts)
{
    return mavlink_msg_radiation_detector_counts_pack(system_id, component_id, msg, radiation_detector_counts->serial_no, radiation_detector_counts->timestamp, radiation_detector_counts->counts, radiation_detector_counts->rate, radiation_detector_counts->integration_time_usec);
}

/**
 * @brief Encode a radiation_detector_counts struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param radiation_detector_counts C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_radiation_detector_counts_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_radiation_detector_counts_t* radiation_detector_counts)
{
    return mavlink_msg_radiation_detector_counts_pack_chan(system_id, component_id, chan, msg, radiation_detector_counts->serial_no, radiation_detector_counts->timestamp, radiation_detector_counts->counts, radiation_detector_counts->rate, radiation_detector_counts->integration_time_usec);
}

/**
 * @brief Send a radiation_detector_counts message
 * @param chan MAVLink channel to send the message
 *
 * @param serial_no  Detector serial number
 * @param timestamp [s] Timestamp of measurement(UNIX Epoch time or time since detector boot)
 * @param counts  Accumulated detector counts
 * @param rate   Detector count in the current dt integration period.
 * @param integration_time_usec [us] Integration period
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_radiation_detector_counts_send(mavlink_channel_t chan, uint32_t serial_no, double timestamp, uint64_t counts, uint32_t rate, uint64_t integration_time_usec)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS_LEN];
    _mav_put_double(buf, 0, timestamp);
    _mav_put_uint64_t(buf, 8, counts);
    _mav_put_uint64_t(buf, 16, integration_time_usec);
    _mav_put_uint32_t(buf, 24, serial_no);
    _mav_put_uint32_t(buf, 28, rate);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS, buf, MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS_MIN_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS_CRC);
#else
    mavlink_radiation_detector_counts_t packet;
    packet.timestamp = timestamp;
    packet.counts = counts;
    packet.integration_time_usec = integration_time_usec;
    packet.serial_no = serial_no;
    packet.rate = rate;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS, (const char *)&packet, MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS_MIN_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS_CRC);
#endif
}

/**
 * @brief Send a radiation_detector_counts message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_radiation_detector_counts_send_struct(mavlink_channel_t chan, const mavlink_radiation_detector_counts_t* radiation_detector_counts)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_radiation_detector_counts_send(chan, radiation_detector_counts->serial_no, radiation_detector_counts->timestamp, radiation_detector_counts->counts, radiation_detector_counts->rate, radiation_detector_counts->integration_time_usec);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS, (const char *)radiation_detector_counts, MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS_MIN_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS_CRC);
#endif
}

#if MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_radiation_detector_counts_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t serial_no, double timestamp, uint64_t counts, uint32_t rate, uint64_t integration_time_usec)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_double(buf, 0, timestamp);
    _mav_put_uint64_t(buf, 8, counts);
    _mav_put_uint64_t(buf, 16, integration_time_usec);
    _mav_put_uint32_t(buf, 24, serial_no);
    _mav_put_uint32_t(buf, 28, rate);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS, buf, MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS_MIN_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS_CRC);
#else
    mavlink_radiation_detector_counts_t *packet = (mavlink_radiation_detector_counts_t *)msgbuf;
    packet->timestamp = timestamp;
    packet->counts = counts;
    packet->integration_time_usec = integration_time_usec;
    packet->serial_no = serial_no;
    packet->rate = rate;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS, (const char *)packet, MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS_MIN_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS_CRC);
#endif
}
#endif

#endif

// MESSAGE RADIATION_DETECTOR_COUNTS UNPACKING


/**
 * @brief Get field serial_no from radiation_detector_counts message
 *
 * @return  Detector serial number
 */
static inline uint32_t mavlink_msg_radiation_detector_counts_get_serial_no(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  24);
}

/**
 * @brief Get field timestamp from radiation_detector_counts message
 *
 * @return [s] Timestamp of measurement(UNIX Epoch time or time since detector boot)
 */
static inline double mavlink_msg_radiation_detector_counts_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_double(msg,  0);
}

/**
 * @brief Get field counts from radiation_detector_counts message
 *
 * @return  Accumulated detector counts
 */
static inline uint64_t mavlink_msg_radiation_detector_counts_get_counts(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  8);
}

/**
 * @brief Get field rate from radiation_detector_counts message
 *
 * @return   Detector count in the current dt integration period.
 */
static inline uint32_t mavlink_msg_radiation_detector_counts_get_rate(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  28);
}

/**
 * @brief Get field integration_time_usec from radiation_detector_counts message
 *
 * @return [us] Integration period
 */
static inline uint64_t mavlink_msg_radiation_detector_counts_get_integration_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  16);
}

/**
 * @brief Decode a radiation_detector_counts message into a struct
 *
 * @param msg The message to decode
 * @param radiation_detector_counts C-struct to decode the message contents into
 */
static inline void mavlink_msg_radiation_detector_counts_decode(const mavlink_message_t* msg, mavlink_radiation_detector_counts_t* radiation_detector_counts)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    radiation_detector_counts->timestamp = mavlink_msg_radiation_detector_counts_get_timestamp(msg);
    radiation_detector_counts->counts = mavlink_msg_radiation_detector_counts_get_counts(msg);
    radiation_detector_counts->integration_time_usec = mavlink_msg_radiation_detector_counts_get_integration_time_usec(msg);
    radiation_detector_counts->serial_no = mavlink_msg_radiation_detector_counts_get_serial_no(msg);
    radiation_detector_counts->rate = mavlink_msg_radiation_detector_counts_get_rate(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS_LEN? msg->len : MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS_LEN;
        memset(radiation_detector_counts, 0, MAVLINK_MSG_ID_RADIATION_DETECTOR_COUNTS_LEN);
    memcpy(radiation_detector_counts, _MAV_PAYLOAD(msg), len);
#endif
}
