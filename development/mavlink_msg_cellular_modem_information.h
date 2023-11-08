#pragma once
// MESSAGE CELLULAR_MODEM_INFORMATION PACKING

#define MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION 337


typedef struct __mavlink_cellular_modem_information_t {
 uint64_t imei; /*<  Unique Modem International Mobile Equipment Identity Number.*/
 uint64_t imsi; /*<  Current SIM International mobile subscriber identity.*/
 uint8_t id; /*<  Modem instance number. Indexed from 1. Matches index in corresponding CELLULAR_STATUS message.*/
 char modem_id[10]; /*<  Unique id for modem. This must be NULL terminated if the length is less than 10 human-readable chars, and without the null termination (NULL) byte if the length is exactly 10 chars.*/
 char iccid[20]; /*<  Integrated Circuit Card Identification Number of SIM Card.  This must be NULL terminated if the length is less than 20 human-readable chars, and without the null termination (NULL) byte if the length is exactly 20 chars.*/
 char firmware[24]; /*<  The firmware version installed on the modem. This must be NULL terminated if the length is less than 24 human-readable chars, and without the null termination (NULL) byte if the length is exactly 24 chars. The format is not intended for display.*/
 char modem_model[50]; /*<  Modem model name.  This must be NULL terminated if the length is less than 50 human-readable chars, and without the null termination (NULL) byte if the length is exactly 50 chars.*/
} mavlink_cellular_modem_information_t;

#define MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION_LEN 121
#define MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION_MIN_LEN 121
#define MAVLINK_MSG_ID_337_LEN 121
#define MAVLINK_MSG_ID_337_MIN_LEN 121

#define MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION_CRC 198
#define MAVLINK_MSG_ID_337_CRC 198

#define MAVLINK_MSG_CELLULAR_MODEM_INFORMATION_FIELD_MODEM_ID_LEN 10
#define MAVLINK_MSG_CELLULAR_MODEM_INFORMATION_FIELD_ICCID_LEN 20
#define MAVLINK_MSG_CELLULAR_MODEM_INFORMATION_FIELD_FIRMWARE_LEN 24
#define MAVLINK_MSG_CELLULAR_MODEM_INFORMATION_FIELD_MODEM_MODEL_LEN 50

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CELLULAR_MODEM_INFORMATION { \
    337, \
    "CELLULAR_MODEM_INFORMATION", \
    7, \
    {  { "id", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_cellular_modem_information_t, id) }, \
         { "imei", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_cellular_modem_information_t, imei) }, \
         { "imsi", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_cellular_modem_information_t, imsi) }, \
         { "modem_id", NULL, MAVLINK_TYPE_CHAR, 10, 17, offsetof(mavlink_cellular_modem_information_t, modem_id) }, \
         { "iccid", NULL, MAVLINK_TYPE_CHAR, 20, 27, offsetof(mavlink_cellular_modem_information_t, iccid) }, \
         { "firmware", NULL, MAVLINK_TYPE_CHAR, 24, 47, offsetof(mavlink_cellular_modem_information_t, firmware) }, \
         { "modem_model", NULL, MAVLINK_TYPE_CHAR, 50, 71, offsetof(mavlink_cellular_modem_information_t, modem_model) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CELLULAR_MODEM_INFORMATION { \
    "CELLULAR_MODEM_INFORMATION", \
    7, \
    {  { "id", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_cellular_modem_information_t, id) }, \
         { "imei", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_cellular_modem_information_t, imei) }, \
         { "imsi", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_cellular_modem_information_t, imsi) }, \
         { "modem_id", NULL, MAVLINK_TYPE_CHAR, 10, 17, offsetof(mavlink_cellular_modem_information_t, modem_id) }, \
         { "iccid", NULL, MAVLINK_TYPE_CHAR, 20, 27, offsetof(mavlink_cellular_modem_information_t, iccid) }, \
         { "firmware", NULL, MAVLINK_TYPE_CHAR, 24, 47, offsetof(mavlink_cellular_modem_information_t, firmware) }, \
         { "modem_model", NULL, MAVLINK_TYPE_CHAR, 50, 71, offsetof(mavlink_cellular_modem_information_t, modem_model) }, \
         } \
}
#endif

/**
 * @brief Pack a cellular_modem_information message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param id  Modem instance number. Indexed from 1. Matches index in corresponding CELLULAR_STATUS message.
 * @param imei  Unique Modem International Mobile Equipment Identity Number.
 * @param imsi  Current SIM International mobile subscriber identity.
 * @param modem_id  Unique id for modem. This must be NULL terminated if the length is less than 10 human-readable chars, and without the null termination (NULL) byte if the length is exactly 10 chars.
 * @param iccid  Integrated Circuit Card Identification Number of SIM Card.  This must be NULL terminated if the length is less than 20 human-readable chars, and without the null termination (NULL) byte if the length is exactly 20 chars.
 * @param firmware  The firmware version installed on the modem. This must be NULL terminated if the length is less than 24 human-readable chars, and without the null termination (NULL) byte if the length is exactly 24 chars. The format is not intended for display.
 * @param modem_model  Modem model name.  This must be NULL terminated if the length is less than 50 human-readable chars, and without the null termination (NULL) byte if the length is exactly 50 chars.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cellular_modem_information_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t id, uint64_t imei, uint64_t imsi, const char *modem_id, const char *iccid, const char *firmware, const char *modem_model)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION_LEN];
    _mav_put_uint64_t(buf, 0, imei);
    _mav_put_uint64_t(buf, 8, imsi);
    _mav_put_uint8_t(buf, 16, id);
    _mav_put_char_array(buf, 17, modem_id, 10);
    _mav_put_char_array(buf, 27, iccid, 20);
    _mav_put_char_array(buf, 47, firmware, 24);
    _mav_put_char_array(buf, 71, modem_model, 50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION_LEN);
#else
    mavlink_cellular_modem_information_t packet;
    packet.imei = imei;
    packet.imsi = imsi;
    packet.id = id;
    mav_array_memcpy(packet.modem_id, modem_id, sizeof(char)*10);
    mav_array_memcpy(packet.iccid, iccid, sizeof(char)*20);
    mav_array_memcpy(packet.firmware, firmware, sizeof(char)*24);
    mav_array_memcpy(packet.modem_model, modem_model, sizeof(char)*50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION_LEN, MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION_CRC);
}

/**
 * @brief Pack a cellular_modem_information message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param id  Modem instance number. Indexed from 1. Matches index in corresponding CELLULAR_STATUS message.
 * @param imei  Unique Modem International Mobile Equipment Identity Number.
 * @param imsi  Current SIM International mobile subscriber identity.
 * @param modem_id  Unique id for modem. This must be NULL terminated if the length is less than 10 human-readable chars, and without the null termination (NULL) byte if the length is exactly 10 chars.
 * @param iccid  Integrated Circuit Card Identification Number of SIM Card.  This must be NULL terminated if the length is less than 20 human-readable chars, and without the null termination (NULL) byte if the length is exactly 20 chars.
 * @param firmware  The firmware version installed on the modem. This must be NULL terminated if the length is less than 24 human-readable chars, and without the null termination (NULL) byte if the length is exactly 24 chars. The format is not intended for display.
 * @param modem_model  Modem model name.  This must be NULL terminated if the length is less than 50 human-readable chars, and without the null termination (NULL) byte if the length is exactly 50 chars.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cellular_modem_information_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t id,uint64_t imei,uint64_t imsi,const char *modem_id,const char *iccid,const char *firmware,const char *modem_model)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION_LEN];
    _mav_put_uint64_t(buf, 0, imei);
    _mav_put_uint64_t(buf, 8, imsi);
    _mav_put_uint8_t(buf, 16, id);
    _mav_put_char_array(buf, 17, modem_id, 10);
    _mav_put_char_array(buf, 27, iccid, 20);
    _mav_put_char_array(buf, 47, firmware, 24);
    _mav_put_char_array(buf, 71, modem_model, 50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION_LEN);
#else
    mavlink_cellular_modem_information_t packet;
    packet.imei = imei;
    packet.imsi = imsi;
    packet.id = id;
    mav_array_memcpy(packet.modem_id, modem_id, sizeof(char)*10);
    mav_array_memcpy(packet.iccid, iccid, sizeof(char)*20);
    mav_array_memcpy(packet.firmware, firmware, sizeof(char)*24);
    mav_array_memcpy(packet.modem_model, modem_model, sizeof(char)*50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION_LEN, MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION_CRC);
}

/**
 * @brief Encode a cellular_modem_information struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param cellular_modem_information C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cellular_modem_information_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_cellular_modem_information_t* cellular_modem_information)
{
    return mavlink_msg_cellular_modem_information_pack(system_id, component_id, msg, cellular_modem_information->id, cellular_modem_information->imei, cellular_modem_information->imsi, cellular_modem_information->modem_id, cellular_modem_information->iccid, cellular_modem_information->firmware, cellular_modem_information->modem_model);
}

/**
 * @brief Encode a cellular_modem_information struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param cellular_modem_information C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cellular_modem_information_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_cellular_modem_information_t* cellular_modem_information)
{
    return mavlink_msg_cellular_modem_information_pack_chan(system_id, component_id, chan, msg, cellular_modem_information->id, cellular_modem_information->imei, cellular_modem_information->imsi, cellular_modem_information->modem_id, cellular_modem_information->iccid, cellular_modem_information->firmware, cellular_modem_information->modem_model);
}

/**
 * @brief Send a cellular_modem_information message
 * @param chan MAVLink channel to send the message
 *
 * @param id  Modem instance number. Indexed from 1. Matches index in corresponding CELLULAR_STATUS message.
 * @param imei  Unique Modem International Mobile Equipment Identity Number.
 * @param imsi  Current SIM International mobile subscriber identity.
 * @param modem_id  Unique id for modem. This must be NULL terminated if the length is less than 10 human-readable chars, and without the null termination (NULL) byte if the length is exactly 10 chars.
 * @param iccid  Integrated Circuit Card Identification Number of SIM Card.  This must be NULL terminated if the length is less than 20 human-readable chars, and without the null termination (NULL) byte if the length is exactly 20 chars.
 * @param firmware  The firmware version installed on the modem. This must be NULL terminated if the length is less than 24 human-readable chars, and without the null termination (NULL) byte if the length is exactly 24 chars. The format is not intended for display.
 * @param modem_model  Modem model name.  This must be NULL terminated if the length is less than 50 human-readable chars, and without the null termination (NULL) byte if the length is exactly 50 chars.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_cellular_modem_information_send(mavlink_channel_t chan, uint8_t id, uint64_t imei, uint64_t imsi, const char *modem_id, const char *iccid, const char *firmware, const char *modem_model)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION_LEN];
    _mav_put_uint64_t(buf, 0, imei);
    _mav_put_uint64_t(buf, 8, imsi);
    _mav_put_uint8_t(buf, 16, id);
    _mav_put_char_array(buf, 17, modem_id, 10);
    _mav_put_char_array(buf, 27, iccid, 20);
    _mav_put_char_array(buf, 47, firmware, 24);
    _mav_put_char_array(buf, 71, modem_model, 50);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION, buf, MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION_LEN, MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION_CRC);
#else
    mavlink_cellular_modem_information_t packet;
    packet.imei = imei;
    packet.imsi = imsi;
    packet.id = id;
    mav_array_memcpy(packet.modem_id, modem_id, sizeof(char)*10);
    mav_array_memcpy(packet.iccid, iccid, sizeof(char)*20);
    mav_array_memcpy(packet.firmware, firmware, sizeof(char)*24);
    mav_array_memcpy(packet.modem_model, modem_model, sizeof(char)*50);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION, (const char *)&packet, MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION_LEN, MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION_CRC);
#endif
}

/**
 * @brief Send a cellular_modem_information message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_cellular_modem_information_send_struct(mavlink_channel_t chan, const mavlink_cellular_modem_information_t* cellular_modem_information)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_cellular_modem_information_send(chan, cellular_modem_information->id, cellular_modem_information->imei, cellular_modem_information->imsi, cellular_modem_information->modem_id, cellular_modem_information->iccid, cellular_modem_information->firmware, cellular_modem_information->modem_model);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION, (const char *)cellular_modem_information, MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION_LEN, MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION_CRC);
#endif
}

#if MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_cellular_modem_information_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t id, uint64_t imei, uint64_t imsi, const char *modem_id, const char *iccid, const char *firmware, const char *modem_model)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, imei);
    _mav_put_uint64_t(buf, 8, imsi);
    _mav_put_uint8_t(buf, 16, id);
    _mav_put_char_array(buf, 17, modem_id, 10);
    _mav_put_char_array(buf, 27, iccid, 20);
    _mav_put_char_array(buf, 47, firmware, 24);
    _mav_put_char_array(buf, 71, modem_model, 50);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION, buf, MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION_LEN, MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION_CRC);
#else
    mavlink_cellular_modem_information_t *packet = (mavlink_cellular_modem_information_t *)msgbuf;
    packet->imei = imei;
    packet->imsi = imsi;
    packet->id = id;
    mav_array_memcpy(packet->modem_id, modem_id, sizeof(char)*10);
    mav_array_memcpy(packet->iccid, iccid, sizeof(char)*20);
    mav_array_memcpy(packet->firmware, firmware, sizeof(char)*24);
    mav_array_memcpy(packet->modem_model, modem_model, sizeof(char)*50);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION, (const char *)packet, MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION_LEN, MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION_CRC);
#endif
}
#endif

#endif

// MESSAGE CELLULAR_MODEM_INFORMATION UNPACKING


/**
 * @brief Get field id from cellular_modem_information message
 *
 * @return  Modem instance number. Indexed from 1. Matches index in corresponding CELLULAR_STATUS message.
 */
static inline uint8_t mavlink_msg_cellular_modem_information_get_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  16);
}

/**
 * @brief Get field imei from cellular_modem_information message
 *
 * @return  Unique Modem International Mobile Equipment Identity Number.
 */
static inline uint64_t mavlink_msg_cellular_modem_information_get_imei(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field imsi from cellular_modem_information message
 *
 * @return  Current SIM International mobile subscriber identity.
 */
static inline uint64_t mavlink_msg_cellular_modem_information_get_imsi(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  8);
}

/**
 * @brief Get field modem_id from cellular_modem_information message
 *
 * @return  Unique id for modem. This must be NULL terminated if the length is less than 10 human-readable chars, and without the null termination (NULL) byte if the length is exactly 10 chars.
 */
static inline uint16_t mavlink_msg_cellular_modem_information_get_modem_id(const mavlink_message_t* msg, char *modem_id)
{
    return _MAV_RETURN_char_array(msg, modem_id, 10,  17);
}

/**
 * @brief Get field iccid from cellular_modem_information message
 *
 * @return  Integrated Circuit Card Identification Number of SIM Card.  This must be NULL terminated if the length is less than 20 human-readable chars, and without the null termination (NULL) byte if the length is exactly 20 chars.
 */
static inline uint16_t mavlink_msg_cellular_modem_information_get_iccid(const mavlink_message_t* msg, char *iccid)
{
    return _MAV_RETURN_char_array(msg, iccid, 20,  27);
}

/**
 * @brief Get field firmware from cellular_modem_information message
 *
 * @return  The firmware version installed on the modem. This must be NULL terminated if the length is less than 24 human-readable chars, and without the null termination (NULL) byte if the length is exactly 24 chars. The format is not intended for display.
 */
static inline uint16_t mavlink_msg_cellular_modem_information_get_firmware(const mavlink_message_t* msg, char *firmware)
{
    return _MAV_RETURN_char_array(msg, firmware, 24,  47);
}

/**
 * @brief Get field modem_model from cellular_modem_information message
 *
 * @return  Modem model name.  This must be NULL terminated if the length is less than 50 human-readable chars, and without the null termination (NULL) byte if the length is exactly 50 chars.
 */
static inline uint16_t mavlink_msg_cellular_modem_information_get_modem_model(const mavlink_message_t* msg, char *modem_model)
{
    return _MAV_RETURN_char_array(msg, modem_model, 50,  71);
}

/**
 * @brief Decode a cellular_modem_information message into a struct
 *
 * @param msg The message to decode
 * @param cellular_modem_information C-struct to decode the message contents into
 */
static inline void mavlink_msg_cellular_modem_information_decode(const mavlink_message_t* msg, mavlink_cellular_modem_information_t* cellular_modem_information)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    cellular_modem_information->imei = mavlink_msg_cellular_modem_information_get_imei(msg);
    cellular_modem_information->imsi = mavlink_msg_cellular_modem_information_get_imsi(msg);
    cellular_modem_information->id = mavlink_msg_cellular_modem_information_get_id(msg);
    mavlink_msg_cellular_modem_information_get_modem_id(msg, cellular_modem_information->modem_id);
    mavlink_msg_cellular_modem_information_get_iccid(msg, cellular_modem_information->iccid);
    mavlink_msg_cellular_modem_information_get_firmware(msg, cellular_modem_information->firmware);
    mavlink_msg_cellular_modem_information_get_modem_model(msg, cellular_modem_information->modem_model);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION_LEN? msg->len : MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION_LEN;
        memset(cellular_modem_information, 0, MAVLINK_MSG_ID_CELLULAR_MODEM_INFORMATION_LEN);
    memcpy(cellular_modem_information, _MAV_PAYLOAD(msg), len);
#endif
}
