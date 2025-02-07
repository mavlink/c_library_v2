#pragma once
// MESSAGE CONTROL_STATUS_REPORT PACKING

#define MAVLINK_MSG_ID_CONTROL_STATUS_REPORT 13441


typedef struct __mavlink_control_status_report_t {
 uint8_t current_flight_controller; /*<  Current flight control entity.*/
 uint8_t current_payload_controller; /*<  Current payload control entity.*/
} mavlink_control_status_report_t;

#define MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_LEN 2
#define MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_MIN_LEN 2
#define MAVLINK_MSG_ID_13441_LEN 2
#define MAVLINK_MSG_ID_13441_MIN_LEN 2

#define MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_CRC 21
#define MAVLINK_MSG_ID_13441_CRC 21



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CONTROL_STATUS_REPORT { \
    13441, \
    "CONTROL_STATUS_REPORT", \
    2, \
    {  { "current_flight_controller", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_control_status_report_t, current_flight_controller) }, \
         { "current_payload_controller", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_control_status_report_t, current_payload_controller) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CONTROL_STATUS_REPORT { \
    "CONTROL_STATUS_REPORT", \
    2, \
    {  { "current_flight_controller", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_control_status_report_t, current_flight_controller) }, \
         { "current_payload_controller", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_control_status_report_t, current_payload_controller) }, \
         } \
}
#endif

/**
 * @brief Pack a control_status_report message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param current_flight_controller  Current flight control entity.
 * @param current_payload_controller  Current payload control entity.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_control_status_report_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t current_flight_controller, uint8_t current_payload_controller)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_LEN];
    _mav_put_uint8_t(buf, 0, current_flight_controller);
    _mav_put_uint8_t(buf, 1, current_payload_controller);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_LEN);
#else
    mavlink_control_status_report_t packet;
    packet.current_flight_controller = current_flight_controller;
    packet.current_payload_controller = current_payload_controller;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CONTROL_STATUS_REPORT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_MIN_LEN, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_LEN, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_CRC);
}

/**
 * @brief Pack a control_status_report message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param current_flight_controller  Current flight control entity.
 * @param current_payload_controller  Current payload control entity.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_control_status_report_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t current_flight_controller, uint8_t current_payload_controller)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_LEN];
    _mav_put_uint8_t(buf, 0, current_flight_controller);
    _mav_put_uint8_t(buf, 1, current_payload_controller);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_LEN);
#else
    mavlink_control_status_report_t packet;
    packet.current_flight_controller = current_flight_controller;
    packet.current_payload_controller = current_payload_controller;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CONTROL_STATUS_REPORT;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_MIN_LEN, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_LEN, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_MIN_LEN, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_LEN);
#endif
}

/**
 * @brief Pack a control_status_report message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param current_flight_controller  Current flight control entity.
 * @param current_payload_controller  Current payload control entity.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_control_status_report_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t current_flight_controller,uint8_t current_payload_controller)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_LEN];
    _mav_put_uint8_t(buf, 0, current_flight_controller);
    _mav_put_uint8_t(buf, 1, current_payload_controller);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_LEN);
#else
    mavlink_control_status_report_t packet;
    packet.current_flight_controller = current_flight_controller;
    packet.current_payload_controller = current_payload_controller;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CONTROL_STATUS_REPORT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_MIN_LEN, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_LEN, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_CRC);
}

/**
 * @brief Encode a control_status_report struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param control_status_report C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_control_status_report_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_control_status_report_t* control_status_report)
{
    return mavlink_msg_control_status_report_pack(system_id, component_id, msg, control_status_report->current_flight_controller, control_status_report->current_payload_controller);
}

/**
 * @brief Encode a control_status_report struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param control_status_report C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_control_status_report_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_control_status_report_t* control_status_report)
{
    return mavlink_msg_control_status_report_pack_chan(system_id, component_id, chan, msg, control_status_report->current_flight_controller, control_status_report->current_payload_controller);
}

/**
 * @brief Encode a control_status_report struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param control_status_report C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_control_status_report_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_control_status_report_t* control_status_report)
{
    return mavlink_msg_control_status_report_pack_status(system_id, component_id, _status, msg,  control_status_report->current_flight_controller, control_status_report->current_payload_controller);
}

/**
 * @brief Send a control_status_report message
 * @param chan MAVLink channel to send the message
 *
 * @param current_flight_controller  Current flight control entity.
 * @param current_payload_controller  Current payload control entity.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_control_status_report_send(mavlink_channel_t chan, uint8_t current_flight_controller, uint8_t current_payload_controller)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_LEN];
    _mav_put_uint8_t(buf, 0, current_flight_controller);
    _mav_put_uint8_t(buf, 1, current_payload_controller);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT, buf, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_MIN_LEN, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_LEN, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_CRC);
#else
    mavlink_control_status_report_t packet;
    packet.current_flight_controller = current_flight_controller;
    packet.current_payload_controller = current_payload_controller;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT, (const char *)&packet, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_MIN_LEN, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_LEN, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_CRC);
#endif
}

/**
 * @brief Send a control_status_report message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_control_status_report_send_struct(mavlink_channel_t chan, const mavlink_control_status_report_t* control_status_report)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_control_status_report_send(chan, control_status_report->current_flight_controller, control_status_report->current_payload_controller);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT, (const char *)control_status_report, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_MIN_LEN, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_LEN, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_CRC);
#endif
}

#if MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_control_status_report_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t current_flight_controller, uint8_t current_payload_controller)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, current_flight_controller);
    _mav_put_uint8_t(buf, 1, current_payload_controller);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT, buf, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_MIN_LEN, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_LEN, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_CRC);
#else
    mavlink_control_status_report_t *packet = (mavlink_control_status_report_t *)msgbuf;
    packet->current_flight_controller = current_flight_controller;
    packet->current_payload_controller = current_payload_controller;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT, (const char *)packet, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_MIN_LEN, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_LEN, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_CRC);
#endif
}
#endif

#endif

// MESSAGE CONTROL_STATUS_REPORT UNPACKING


/**
 * @brief Get field current_flight_controller from control_status_report message
 *
 * @return  Current flight control entity.
 */
static inline uint8_t mavlink_msg_control_status_report_get_current_flight_controller(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field current_payload_controller from control_status_report message
 *
 * @return  Current payload control entity.
 */
static inline uint8_t mavlink_msg_control_status_report_get_current_payload_controller(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Decode a control_status_report message into a struct
 *
 * @param msg The message to decode
 * @param control_status_report C-struct to decode the message contents into
 */
static inline void mavlink_msg_control_status_report_decode(const mavlink_message_t* msg, mavlink_control_status_report_t* control_status_report)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    control_status_report->current_flight_controller = mavlink_msg_control_status_report_get_current_flight_controller(msg);
    control_status_report->current_payload_controller = mavlink_msg_control_status_report_get_current_payload_controller(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_LEN? msg->len : MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_LEN;
        memset(control_status_report, 0, MAVLINK_MSG_ID_CONTROL_STATUS_REPORT_LEN);
    memcpy(control_status_report, _MAV_PAYLOAD(msg), len);
#endif
}
