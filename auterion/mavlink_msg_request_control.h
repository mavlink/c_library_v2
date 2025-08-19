#pragma once
// MESSAGE REQUEST_CONTROL PACKING

#define MAVLINK_MSG_ID_REQUEST_CONTROL 13442


typedef struct __mavlink_request_control_t {
 uint8_t control_target; /*<  Control target to change to own ownership.*/
 uint8_t request_priority; /*<  Priority of the control request. If the priority is higher than the priority
        of the current control entity, control is given without handoff request.
        The priority request should be authenticated on the target system before granting this privilegs. Default value of 0.*/
 char requester_id[40]; /*<  Identification of the control entity requesting ownership.*/
 char reason[100]; /*<  Reason for taking ownership.*/
} mavlink_request_control_t;

#define MAVLINK_MSG_ID_REQUEST_CONTROL_LEN 142
#define MAVLINK_MSG_ID_REQUEST_CONTROL_MIN_LEN 142
#define MAVLINK_MSG_ID_13442_LEN 142
#define MAVLINK_MSG_ID_13442_MIN_LEN 142

#define MAVLINK_MSG_ID_REQUEST_CONTROL_CRC 172
#define MAVLINK_MSG_ID_13442_CRC 172

#define MAVLINK_MSG_REQUEST_CONTROL_FIELD_REQUESTER_ID_LEN 40
#define MAVLINK_MSG_REQUEST_CONTROL_FIELD_REASON_LEN 100

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_REQUEST_CONTROL { \
    13442, \
    "REQUEST_CONTROL", \
    4, \
    {  { "control_target", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_request_control_t, control_target) }, \
         { "request_priority", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_request_control_t, request_priority) }, \
         { "requester_id", NULL, MAVLINK_TYPE_CHAR, 40, 2, offsetof(mavlink_request_control_t, requester_id) }, \
         { "reason", NULL, MAVLINK_TYPE_CHAR, 100, 42, offsetof(mavlink_request_control_t, reason) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_REQUEST_CONTROL { \
    "REQUEST_CONTROL", \
    4, \
    {  { "control_target", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_request_control_t, control_target) }, \
         { "request_priority", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_request_control_t, request_priority) }, \
         { "requester_id", NULL, MAVLINK_TYPE_CHAR, 40, 2, offsetof(mavlink_request_control_t, requester_id) }, \
         { "reason", NULL, MAVLINK_TYPE_CHAR, 100, 42, offsetof(mavlink_request_control_t, reason) }, \
         } \
}
#endif

/**
 * @brief Pack a request_control message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param control_target  Control target to change to own ownership.
 * @param request_priority  Priority of the control request. If the priority is higher than the priority
        of the current control entity, control is given without handoff request.
        The priority request should be authenticated on the target system before granting this privilegs. Default value of 0.
 * @param requester_id  Identification of the control entity requesting ownership.
 * @param reason  Reason for taking ownership.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_request_control_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t control_target, uint8_t request_priority, const char *requester_id, const char *reason)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_REQUEST_CONTROL_LEN];
    _mav_put_uint8_t(buf, 0, control_target);
    _mav_put_uint8_t(buf, 1, request_priority);
    _mav_put_char_array(buf, 2, requester_id, 40);
    _mav_put_char_array(buf, 42, reason, 100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_REQUEST_CONTROL_LEN);
#else
    mavlink_request_control_t packet;
    packet.control_target = control_target;
    packet.request_priority = request_priority;
    mav_array_memcpy(packet.requester_id, requester_id, sizeof(char)*40);
    mav_array_memcpy(packet.reason, reason, sizeof(char)*100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_REQUEST_CONTROL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_REQUEST_CONTROL;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_REQUEST_CONTROL_MIN_LEN, MAVLINK_MSG_ID_REQUEST_CONTROL_LEN, MAVLINK_MSG_ID_REQUEST_CONTROL_CRC);
}

/**
 * @brief Pack a request_control message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param control_target  Control target to change to own ownership.
 * @param request_priority  Priority of the control request. If the priority is higher than the priority
        of the current control entity, control is given without handoff request.
        The priority request should be authenticated on the target system before granting this privilegs. Default value of 0.
 * @param requester_id  Identification of the control entity requesting ownership.
 * @param reason  Reason for taking ownership.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_request_control_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t control_target, uint8_t request_priority, const char *requester_id, const char *reason)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_REQUEST_CONTROL_LEN];
    _mav_put_uint8_t(buf, 0, control_target);
    _mav_put_uint8_t(buf, 1, request_priority);
    _mav_put_char_array(buf, 2, requester_id, 40);
    _mav_put_char_array(buf, 42, reason, 100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_REQUEST_CONTROL_LEN);
#else
    mavlink_request_control_t packet;
    packet.control_target = control_target;
    packet.request_priority = request_priority;
    mav_array_memcpy(packet.requester_id, requester_id, sizeof(char)*40);
    mav_array_memcpy(packet.reason, reason, sizeof(char)*100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_REQUEST_CONTROL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_REQUEST_CONTROL;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_REQUEST_CONTROL_MIN_LEN, MAVLINK_MSG_ID_REQUEST_CONTROL_LEN, MAVLINK_MSG_ID_REQUEST_CONTROL_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_REQUEST_CONTROL_MIN_LEN, MAVLINK_MSG_ID_REQUEST_CONTROL_LEN);
#endif
}

/**
 * @brief Pack a request_control message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param control_target  Control target to change to own ownership.
 * @param request_priority  Priority of the control request. If the priority is higher than the priority
        of the current control entity, control is given without handoff request.
        The priority request should be authenticated on the target system before granting this privilegs. Default value of 0.
 * @param requester_id  Identification of the control entity requesting ownership.
 * @param reason  Reason for taking ownership.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_request_control_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t control_target,uint8_t request_priority,const char *requester_id,const char *reason)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_REQUEST_CONTROL_LEN];
    _mav_put_uint8_t(buf, 0, control_target);
    _mav_put_uint8_t(buf, 1, request_priority);
    _mav_put_char_array(buf, 2, requester_id, 40);
    _mav_put_char_array(buf, 42, reason, 100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_REQUEST_CONTROL_LEN);
#else
    mavlink_request_control_t packet;
    packet.control_target = control_target;
    packet.request_priority = request_priority;
    mav_array_memcpy(packet.requester_id, requester_id, sizeof(char)*40);
    mav_array_memcpy(packet.reason, reason, sizeof(char)*100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_REQUEST_CONTROL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_REQUEST_CONTROL;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_REQUEST_CONTROL_MIN_LEN, MAVLINK_MSG_ID_REQUEST_CONTROL_LEN, MAVLINK_MSG_ID_REQUEST_CONTROL_CRC);
}

/**
 * @brief Encode a request_control struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param request_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_request_control_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_request_control_t* request_control)
{
    return mavlink_msg_request_control_pack(system_id, component_id, msg, request_control->control_target, request_control->request_priority, request_control->requester_id, request_control->reason);
}

/**
 * @brief Encode a request_control struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param request_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_request_control_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_request_control_t* request_control)
{
    return mavlink_msg_request_control_pack_chan(system_id, component_id, chan, msg, request_control->control_target, request_control->request_priority, request_control->requester_id, request_control->reason);
}

/**
 * @brief Encode a request_control struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param request_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_request_control_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_request_control_t* request_control)
{
    return mavlink_msg_request_control_pack_status(system_id, component_id, _status, msg,  request_control->control_target, request_control->request_priority, request_control->requester_id, request_control->reason);
}

/**
 * @brief Send a request_control message
 * @param chan MAVLink channel to send the message
 *
 * @param control_target  Control target to change to own ownership.
 * @param request_priority  Priority of the control request. If the priority is higher than the priority
        of the current control entity, control is given without handoff request.
        The priority request should be authenticated on the target system before granting this privilegs. Default value of 0.
 * @param requester_id  Identification of the control entity requesting ownership.
 * @param reason  Reason for taking ownership.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_request_control_send(mavlink_channel_t chan, uint8_t control_target, uint8_t request_priority, const char *requester_id, const char *reason)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_REQUEST_CONTROL_LEN];
    _mav_put_uint8_t(buf, 0, control_target);
    _mav_put_uint8_t(buf, 1, request_priority);
    _mav_put_char_array(buf, 2, requester_id, 40);
    _mav_put_char_array(buf, 42, reason, 100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REQUEST_CONTROL, buf, MAVLINK_MSG_ID_REQUEST_CONTROL_MIN_LEN, MAVLINK_MSG_ID_REQUEST_CONTROL_LEN, MAVLINK_MSG_ID_REQUEST_CONTROL_CRC);
#else
    mavlink_request_control_t packet;
    packet.control_target = control_target;
    packet.request_priority = request_priority;
    mav_array_memcpy(packet.requester_id, requester_id, sizeof(char)*40);
    mav_array_memcpy(packet.reason, reason, sizeof(char)*100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REQUEST_CONTROL, (const char *)&packet, MAVLINK_MSG_ID_REQUEST_CONTROL_MIN_LEN, MAVLINK_MSG_ID_REQUEST_CONTROL_LEN, MAVLINK_MSG_ID_REQUEST_CONTROL_CRC);
#endif
}

/**
 * @brief Send a request_control message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_request_control_send_struct(mavlink_channel_t chan, const mavlink_request_control_t* request_control)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_request_control_send(chan, request_control->control_target, request_control->request_priority, request_control->requester_id, request_control->reason);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REQUEST_CONTROL, (const char *)request_control, MAVLINK_MSG_ID_REQUEST_CONTROL_MIN_LEN, MAVLINK_MSG_ID_REQUEST_CONTROL_LEN, MAVLINK_MSG_ID_REQUEST_CONTROL_CRC);
#endif
}

#if MAVLINK_MSG_ID_REQUEST_CONTROL_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_request_control_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t control_target, uint8_t request_priority, const char *requester_id, const char *reason)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, control_target);
    _mav_put_uint8_t(buf, 1, request_priority);
    _mav_put_char_array(buf, 2, requester_id, 40);
    _mav_put_char_array(buf, 42, reason, 100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REQUEST_CONTROL, buf, MAVLINK_MSG_ID_REQUEST_CONTROL_MIN_LEN, MAVLINK_MSG_ID_REQUEST_CONTROL_LEN, MAVLINK_MSG_ID_REQUEST_CONTROL_CRC);
#else
    mavlink_request_control_t *packet = (mavlink_request_control_t *)msgbuf;
    packet->control_target = control_target;
    packet->request_priority = request_priority;
    mav_array_memcpy(packet->requester_id, requester_id, sizeof(char)*40);
    mav_array_memcpy(packet->reason, reason, sizeof(char)*100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REQUEST_CONTROL, (const char *)packet, MAVLINK_MSG_ID_REQUEST_CONTROL_MIN_LEN, MAVLINK_MSG_ID_REQUEST_CONTROL_LEN, MAVLINK_MSG_ID_REQUEST_CONTROL_CRC);
#endif
}
#endif

#endif

// MESSAGE REQUEST_CONTROL UNPACKING


/**
 * @brief Get field control_target from request_control message
 *
 * @return  Control target to change to own ownership.
 */
static inline uint8_t mavlink_msg_request_control_get_control_target(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field request_priority from request_control message
 *
 * @return  Priority of the control request. If the priority is higher than the priority
        of the current control entity, control is given without handoff request.
        The priority request should be authenticated on the target system before granting this privilegs. Default value of 0.
 */
static inline uint8_t mavlink_msg_request_control_get_request_priority(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field requester_id from request_control message
 *
 * @return  Identification of the control entity requesting ownership.
 */
static inline uint16_t mavlink_msg_request_control_get_requester_id(const mavlink_message_t* msg, char *requester_id)
{
    return _MAV_RETURN_char_array(msg, requester_id, 40,  2);
}

/**
 * @brief Get field reason from request_control message
 *
 * @return  Reason for taking ownership.
 */
static inline uint16_t mavlink_msg_request_control_get_reason(const mavlink_message_t* msg, char *reason)
{
    return _MAV_RETURN_char_array(msg, reason, 100,  42);
}

/**
 * @brief Decode a request_control message into a struct
 *
 * @param msg The message to decode
 * @param request_control C-struct to decode the message contents into
 */
static inline void mavlink_msg_request_control_decode(const mavlink_message_t* msg, mavlink_request_control_t* request_control)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    request_control->control_target = mavlink_msg_request_control_get_control_target(msg);
    request_control->request_priority = mavlink_msg_request_control_get_request_priority(msg);
    mavlink_msg_request_control_get_requester_id(msg, request_control->requester_id);
    mavlink_msg_request_control_get_reason(msg, request_control->reason);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_REQUEST_CONTROL_LEN? msg->len : MAVLINK_MSG_ID_REQUEST_CONTROL_LEN;
        memset(request_control, 0, MAVLINK_MSG_ID_REQUEST_CONTROL_LEN);
    memcpy(request_control, _MAV_PAYLOAD(msg), len);
#endif
}
