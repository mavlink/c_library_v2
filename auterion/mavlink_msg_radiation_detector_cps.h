#pragma once
// MESSAGE RADIATION_DETECTOR_CPS PACKING

#define MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS 462


typedef struct __mavlink_radiation_detector_cps_t {
 double timestamp; /*< [s] Time of data measurement*/
 uint32_t serial_no; /*<  Detector serial number*/
 uint32_t cps; /*<  Detector value scaled by factor*/
 float dt; /*< [s] delta-t integration period*/
} mavlink_radiation_detector_cps_t;

#define MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS_LEN 20
#define MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS_MIN_LEN 20
#define MAVLINK_MSG_ID_462_LEN 20
#define MAVLINK_MSG_ID_462_MIN_LEN 20

#define MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS_CRC 193
#define MAVLINK_MSG_ID_462_CRC 193



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RADIATION_DETECTOR_CPS { \
    462, \
    "RADIATION_DETECTOR_CPS", \
    4, \
    {  { "serial_no", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_radiation_detector_cps_t, serial_no) }, \
         { "timestamp", NULL, MAVLINK_TYPE_DOUBLE, 0, 0, offsetof(mavlink_radiation_detector_cps_t, timestamp) }, \
         { "cps", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_radiation_detector_cps_t, cps) }, \
         { "dt", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_radiation_detector_cps_t, dt) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_RADIATION_DETECTOR_CPS { \
    "RADIATION_DETECTOR_CPS", \
    4, \
    {  { "serial_no", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_radiation_detector_cps_t, serial_no) }, \
         { "timestamp", NULL, MAVLINK_TYPE_DOUBLE, 0, 0, offsetof(mavlink_radiation_detector_cps_t, timestamp) }, \
         { "cps", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_radiation_detector_cps_t, cps) }, \
         { "dt", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_radiation_detector_cps_t, dt) }, \
         } \
}
#endif

/**
 * @brief Pack a radiation_detector_cps message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param serial_no  Detector serial number
 * @param timestamp [s] Time of data measurement
 * @param cps  Detector value scaled by factor
 * @param dt [s] delta-t integration period
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_radiation_detector_cps_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t serial_no, double timestamp, uint32_t cps, float dt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS_LEN];
    _mav_put_double(buf, 0, timestamp);
    _mav_put_uint32_t(buf, 8, serial_no);
    _mav_put_uint32_t(buf, 12, cps);
    _mav_put_float(buf, 16, dt);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS_LEN);
#else
    mavlink_radiation_detector_cps_t packet;
    packet.timestamp = timestamp;
    packet.serial_no = serial_no;
    packet.cps = cps;
    packet.dt = dt;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS_MIN_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS_CRC);
}

/**
 * @brief Pack a radiation_detector_cps message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param serial_no  Detector serial number
 * @param timestamp [s] Time of data measurement
 * @param cps  Detector value scaled by factor
 * @param dt [s] delta-t integration period
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_radiation_detector_cps_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t serial_no,double timestamp,uint32_t cps,float dt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS_LEN];
    _mav_put_double(buf, 0, timestamp);
    _mav_put_uint32_t(buf, 8, serial_no);
    _mav_put_uint32_t(buf, 12, cps);
    _mav_put_float(buf, 16, dt);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS_LEN);
#else
    mavlink_radiation_detector_cps_t packet;
    packet.timestamp = timestamp;
    packet.serial_no = serial_no;
    packet.cps = cps;
    packet.dt = dt;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS_MIN_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS_CRC);
}

/**
 * @brief Encode a radiation_detector_cps struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param radiation_detector_cps C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_radiation_detector_cps_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_radiation_detector_cps_t* radiation_detector_cps)
{
    return mavlink_msg_radiation_detector_cps_pack(system_id, component_id, msg, radiation_detector_cps->serial_no, radiation_detector_cps->timestamp, radiation_detector_cps->cps, radiation_detector_cps->dt);
}

/**
 * @brief Encode a radiation_detector_cps struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param radiation_detector_cps C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_radiation_detector_cps_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_radiation_detector_cps_t* radiation_detector_cps)
{
    return mavlink_msg_radiation_detector_cps_pack_chan(system_id, component_id, chan, msg, radiation_detector_cps->serial_no, radiation_detector_cps->timestamp, radiation_detector_cps->cps, radiation_detector_cps->dt);
}

/**
 * @brief Send a radiation_detector_cps message
 * @param chan MAVLink channel to send the message
 *
 * @param serial_no  Detector serial number
 * @param timestamp [s] Time of data measurement
 * @param cps  Detector value scaled by factor
 * @param dt [s] delta-t integration period
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_radiation_detector_cps_send(mavlink_channel_t chan, uint32_t serial_no, double timestamp, uint32_t cps, float dt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS_LEN];
    _mav_put_double(buf, 0, timestamp);
    _mav_put_uint32_t(buf, 8, serial_no);
    _mav_put_uint32_t(buf, 12, cps);
    _mav_put_float(buf, 16, dt);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS, buf, MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS_MIN_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS_CRC);
#else
    mavlink_radiation_detector_cps_t packet;
    packet.timestamp = timestamp;
    packet.serial_no = serial_no;
    packet.cps = cps;
    packet.dt = dt;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS, (const char *)&packet, MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS_MIN_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS_CRC);
#endif
}

/**
 * @brief Send a radiation_detector_cps message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_radiation_detector_cps_send_struct(mavlink_channel_t chan, const mavlink_radiation_detector_cps_t* radiation_detector_cps)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_radiation_detector_cps_send(chan, radiation_detector_cps->serial_no, radiation_detector_cps->timestamp, radiation_detector_cps->cps, radiation_detector_cps->dt);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS, (const char *)radiation_detector_cps, MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS_MIN_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS_CRC);
#endif
}

#if MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_radiation_detector_cps_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t serial_no, double timestamp, uint32_t cps, float dt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_double(buf, 0, timestamp);
    _mav_put_uint32_t(buf, 8, serial_no);
    _mav_put_uint32_t(buf, 12, cps);
    _mav_put_float(buf, 16, dt);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS, buf, MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS_MIN_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS_CRC);
#else
    mavlink_radiation_detector_cps_t *packet = (mavlink_radiation_detector_cps_t *)msgbuf;
    packet->timestamp = timestamp;
    packet->serial_no = serial_no;
    packet->cps = cps;
    packet->dt = dt;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS, (const char *)packet, MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS_MIN_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS_CRC);
#endif
}
#endif

#endif

// MESSAGE RADIATION_DETECTOR_CPS UNPACKING


/**
 * @brief Get field serial_no from radiation_detector_cps message
 *
 * @return  Detector serial number
 */
static inline uint32_t mavlink_msg_radiation_detector_cps_get_serial_no(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field timestamp from radiation_detector_cps message
 *
 * @return [s] Time of data measurement
 */
static inline double mavlink_msg_radiation_detector_cps_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_double(msg,  0);
}

/**
 * @brief Get field cps from radiation_detector_cps message
 *
 * @return  Detector value scaled by factor
 */
static inline uint32_t mavlink_msg_radiation_detector_cps_get_cps(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  12);
}

/**
 * @brief Get field dt from radiation_detector_cps message
 *
 * @return [s] delta-t integration period
 */
static inline float mavlink_msg_radiation_detector_cps_get_dt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Decode a radiation_detector_cps message into a struct
 *
 * @param msg The message to decode
 * @param radiation_detector_cps C-struct to decode the message contents into
 */
static inline void mavlink_msg_radiation_detector_cps_decode(const mavlink_message_t* msg, mavlink_radiation_detector_cps_t* radiation_detector_cps)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    radiation_detector_cps->timestamp = mavlink_msg_radiation_detector_cps_get_timestamp(msg);
    radiation_detector_cps->serial_no = mavlink_msg_radiation_detector_cps_get_serial_no(msg);
    radiation_detector_cps->cps = mavlink_msg_radiation_detector_cps_get_cps(msg);
    radiation_detector_cps->dt = mavlink_msg_radiation_detector_cps_get_dt(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS_LEN? msg->len : MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS_LEN;
        memset(radiation_detector_cps, 0, MAVLINK_MSG_ID_RADIATION_DETECTOR_CPS_LEN);
    memcpy(radiation_detector_cps, _MAV_PAYLOAD(msg), len);
#endif
}
