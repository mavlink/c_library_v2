#pragma once
// MESSAGE RADIATION_DETECTOR_SPECTRUM PACKING

#define MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM 461


typedef struct __mavlink_radiation_detector_spectrum_t {
 uint32_t serial_no; /*<  Detector serial number*/
 uint8_t msg_no; /*<  Message number [0;255]*/
 uint8_t seq_no; /*<  Sequence number [0;127]*/
 uint8_t segment[249]; /*<  One segment of a spectrum PDU*/
} mavlink_radiation_detector_spectrum_t;

#define MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM_LEN 255
#define MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM_MIN_LEN 255
#define MAVLINK_MSG_ID_461_LEN 255
#define MAVLINK_MSG_ID_461_MIN_LEN 255

#define MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM_CRC 235
#define MAVLINK_MSG_ID_461_CRC 235

#define MAVLINK_MSG_RADIATION_DETECTOR_SPECTRUM_FIELD_SEGMENT_LEN 249

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RADIATION_DETECTOR_SPECTRUM { \
    461, \
    "RADIATION_DETECTOR_SPECTRUM", \
    4, \
    {  { "serial_no", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_radiation_detector_spectrum_t, serial_no) }, \
         { "msg_no", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_radiation_detector_spectrum_t, msg_no) }, \
         { "seq_no", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_radiation_detector_spectrum_t, seq_no) }, \
         { "segment", NULL, MAVLINK_TYPE_UINT8_T, 249, 6, offsetof(mavlink_radiation_detector_spectrum_t, segment) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_RADIATION_DETECTOR_SPECTRUM { \
    "RADIATION_DETECTOR_SPECTRUM", \
    4, \
    {  { "serial_no", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_radiation_detector_spectrum_t, serial_no) }, \
         { "msg_no", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_radiation_detector_spectrum_t, msg_no) }, \
         { "seq_no", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_radiation_detector_spectrum_t, seq_no) }, \
         { "segment", NULL, MAVLINK_TYPE_UINT8_T, 249, 6, offsetof(mavlink_radiation_detector_spectrum_t, segment) }, \
         } \
}
#endif

/**
 * @brief Pack a radiation_detector_spectrum message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param serial_no  Detector serial number
 * @param msg_no  Message number [0;255]
 * @param seq_no  Sequence number [0;127]
 * @param segment  One segment of a spectrum PDU
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_radiation_detector_spectrum_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t serial_no, uint8_t msg_no, uint8_t seq_no, const uint8_t *segment)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM_LEN];
    _mav_put_uint32_t(buf, 0, serial_no);
    _mav_put_uint8_t(buf, 4, msg_no);
    _mav_put_uint8_t(buf, 5, seq_no);
    _mav_put_uint8_t_array(buf, 6, segment, 249);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM_LEN);
#else
    mavlink_radiation_detector_spectrum_t packet;
    packet.serial_no = serial_no;
    packet.msg_no = msg_no;
    packet.seq_no = seq_no;
    mav_array_memcpy(packet.segment, segment, sizeof(uint8_t)*249);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM_MIN_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM_CRC);
}

/**
 * @brief Pack a radiation_detector_spectrum message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param serial_no  Detector serial number
 * @param msg_no  Message number [0;255]
 * @param seq_no  Sequence number [0;127]
 * @param segment  One segment of a spectrum PDU
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_radiation_detector_spectrum_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t serial_no,uint8_t msg_no,uint8_t seq_no,const uint8_t *segment)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM_LEN];
    _mav_put_uint32_t(buf, 0, serial_no);
    _mav_put_uint8_t(buf, 4, msg_no);
    _mav_put_uint8_t(buf, 5, seq_no);
    _mav_put_uint8_t_array(buf, 6, segment, 249);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM_LEN);
#else
    mavlink_radiation_detector_spectrum_t packet;
    packet.serial_no = serial_no;
    packet.msg_no = msg_no;
    packet.seq_no = seq_no;
    mav_array_memcpy(packet.segment, segment, sizeof(uint8_t)*249);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM_MIN_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM_CRC);
}

/**
 * @brief Encode a radiation_detector_spectrum struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param radiation_detector_spectrum C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_radiation_detector_spectrum_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_radiation_detector_spectrum_t* radiation_detector_spectrum)
{
    return mavlink_msg_radiation_detector_spectrum_pack(system_id, component_id, msg, radiation_detector_spectrum->serial_no, radiation_detector_spectrum->msg_no, radiation_detector_spectrum->seq_no, radiation_detector_spectrum->segment);
}

/**
 * @brief Encode a radiation_detector_spectrum struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param radiation_detector_spectrum C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_radiation_detector_spectrum_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_radiation_detector_spectrum_t* radiation_detector_spectrum)
{
    return mavlink_msg_radiation_detector_spectrum_pack_chan(system_id, component_id, chan, msg, radiation_detector_spectrum->serial_no, radiation_detector_spectrum->msg_no, radiation_detector_spectrum->seq_no, radiation_detector_spectrum->segment);
}

/**
 * @brief Send a radiation_detector_spectrum message
 * @param chan MAVLink channel to send the message
 *
 * @param serial_no  Detector serial number
 * @param msg_no  Message number [0;255]
 * @param seq_no  Sequence number [0;127]
 * @param segment  One segment of a spectrum PDU
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_radiation_detector_spectrum_send(mavlink_channel_t chan, uint32_t serial_no, uint8_t msg_no, uint8_t seq_no, const uint8_t *segment)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM_LEN];
    _mav_put_uint32_t(buf, 0, serial_no);
    _mav_put_uint8_t(buf, 4, msg_no);
    _mav_put_uint8_t(buf, 5, seq_no);
    _mav_put_uint8_t_array(buf, 6, segment, 249);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM, buf, MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM_MIN_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM_CRC);
#else
    mavlink_radiation_detector_spectrum_t packet;
    packet.serial_no = serial_no;
    packet.msg_no = msg_no;
    packet.seq_no = seq_no;
    mav_array_memcpy(packet.segment, segment, sizeof(uint8_t)*249);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM, (const char *)&packet, MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM_MIN_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM_CRC);
#endif
}

/**
 * @brief Send a radiation_detector_spectrum message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_radiation_detector_spectrum_send_struct(mavlink_channel_t chan, const mavlink_radiation_detector_spectrum_t* radiation_detector_spectrum)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_radiation_detector_spectrum_send(chan, radiation_detector_spectrum->serial_no, radiation_detector_spectrum->msg_no, radiation_detector_spectrum->seq_no, radiation_detector_spectrum->segment);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM, (const char *)radiation_detector_spectrum, MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM_MIN_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM_CRC);
#endif
}

#if MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_radiation_detector_spectrum_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t serial_no, uint8_t msg_no, uint8_t seq_no, const uint8_t *segment)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, serial_no);
    _mav_put_uint8_t(buf, 4, msg_no);
    _mav_put_uint8_t(buf, 5, seq_no);
    _mav_put_uint8_t_array(buf, 6, segment, 249);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM, buf, MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM_MIN_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM_CRC);
#else
    mavlink_radiation_detector_spectrum_t *packet = (mavlink_radiation_detector_spectrum_t *)msgbuf;
    packet->serial_no = serial_no;
    packet->msg_no = msg_no;
    packet->seq_no = seq_no;
    mav_array_memcpy(packet->segment, segment, sizeof(uint8_t)*249);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM, (const char *)packet, MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM_MIN_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM_LEN, MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM_CRC);
#endif
}
#endif

#endif

// MESSAGE RADIATION_DETECTOR_SPECTRUM UNPACKING


/**
 * @brief Get field serial_no from radiation_detector_spectrum message
 *
 * @return  Detector serial number
 */
static inline uint32_t mavlink_msg_radiation_detector_spectrum_get_serial_no(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field msg_no from radiation_detector_spectrum message
 *
 * @return  Message number [0;255]
 */
static inline uint8_t mavlink_msg_radiation_detector_spectrum_get_msg_no(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field seq_no from radiation_detector_spectrum message
 *
 * @return  Sequence number [0;127]
 */
static inline uint8_t mavlink_msg_radiation_detector_spectrum_get_seq_no(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field segment from radiation_detector_spectrum message
 *
 * @return  One segment of a spectrum PDU
 */
static inline uint16_t mavlink_msg_radiation_detector_spectrum_get_segment(const mavlink_message_t* msg, uint8_t *segment)
{
    return _MAV_RETURN_uint8_t_array(msg, segment, 249,  6);
}

/**
 * @brief Decode a radiation_detector_spectrum message into a struct
 *
 * @param msg The message to decode
 * @param radiation_detector_spectrum C-struct to decode the message contents into
 */
static inline void mavlink_msg_radiation_detector_spectrum_decode(const mavlink_message_t* msg, mavlink_radiation_detector_spectrum_t* radiation_detector_spectrum)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    radiation_detector_spectrum->serial_no = mavlink_msg_radiation_detector_spectrum_get_serial_no(msg);
    radiation_detector_spectrum->msg_no = mavlink_msg_radiation_detector_spectrum_get_msg_no(msg);
    radiation_detector_spectrum->seq_no = mavlink_msg_radiation_detector_spectrum_get_seq_no(msg);
    mavlink_msg_radiation_detector_spectrum_get_segment(msg, radiation_detector_spectrum->segment);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM_LEN? msg->len : MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM_LEN;
        memset(radiation_detector_spectrum, 0, MAVLINK_MSG_ID_RADIATION_DETECTOR_SPECTRUM_LEN);
    memcpy(radiation_detector_spectrum, _MAV_PAYLOAD(msg), len);
#endif
}
