#pragma once
// MESSAGE WIFI_NETWORK_INFO PACKING

#define MAVLINK_MSG_ID_WIFI_NETWORK_INFO 298


typedef struct __mavlink_wifi_network_info_t {
 uint16_t data_rate; /*< [MiB/s] WiFi network data rate. Set to UINT16_MAX if data_rate information is not supplied.*/
 char ssid[32]; /*<  Name of Wi-Fi network (SSID).*/
 uint8_t channel_id; /*<  WiFi network operating channel ID. Set to 0 if unknown or unidentified.*/
 uint8_t signal_quality; /*< [%] WiFi network signal quality.*/
 uint8_t security; /*<  WiFi network security type.*/
} mavlink_wifi_network_info_t;

#define MAVLINK_MSG_ID_WIFI_NETWORK_INFO_LEN 37
#define MAVLINK_MSG_ID_WIFI_NETWORK_INFO_MIN_LEN 37
#define MAVLINK_MSG_ID_298_LEN 37
#define MAVLINK_MSG_ID_298_MIN_LEN 37

#define MAVLINK_MSG_ID_WIFI_NETWORK_INFO_CRC 237
#define MAVLINK_MSG_ID_298_CRC 237

#define MAVLINK_MSG_WIFI_NETWORK_INFO_FIELD_SSID_LEN 32

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WIFI_NETWORK_INFO { \
    298, \
    "WIFI_NETWORK_INFO", \
    5, \
    {  { "ssid", NULL, MAVLINK_TYPE_CHAR, 32, 2, offsetof(mavlink_wifi_network_info_t, ssid) }, \
         { "channel_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 34, offsetof(mavlink_wifi_network_info_t, channel_id) }, \
         { "signal_quality", NULL, MAVLINK_TYPE_UINT8_T, 0, 35, offsetof(mavlink_wifi_network_info_t, signal_quality) }, \
         { "data_rate", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_wifi_network_info_t, data_rate) }, \
         { "security", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_wifi_network_info_t, security) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WIFI_NETWORK_INFO { \
    "WIFI_NETWORK_INFO", \
    5, \
    {  { "ssid", NULL, MAVLINK_TYPE_CHAR, 32, 2, offsetof(mavlink_wifi_network_info_t, ssid) }, \
         { "channel_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 34, offsetof(mavlink_wifi_network_info_t, channel_id) }, \
         { "signal_quality", NULL, MAVLINK_TYPE_UINT8_T, 0, 35, offsetof(mavlink_wifi_network_info_t, signal_quality) }, \
         { "data_rate", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_wifi_network_info_t, data_rate) }, \
         { "security", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_wifi_network_info_t, security) }, \
         } \
}
#endif

/**
 * @brief Pack a wifi_network_info message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param ssid  Name of Wi-Fi network (SSID).
 * @param channel_id  WiFi network operating channel ID. Set to 0 if unknown or unidentified.
 * @param signal_quality [%] WiFi network signal quality.
 * @param data_rate [MiB/s] WiFi network data rate. Set to UINT16_MAX if data_rate information is not supplied.
 * @param security  WiFi network security type.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wifi_network_info_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const char *ssid, uint8_t channel_id, uint8_t signal_quality, uint16_t data_rate, uint8_t security)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WIFI_NETWORK_INFO_LEN];
    _mav_put_uint16_t(buf, 0, data_rate);
    _mav_put_uint8_t(buf, 34, channel_id);
    _mav_put_uint8_t(buf, 35, signal_quality);
    _mav_put_uint8_t(buf, 36, security);
    _mav_put_char_array(buf, 2, ssid, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WIFI_NETWORK_INFO_LEN);
#else
    mavlink_wifi_network_info_t packet;
    packet.data_rate = data_rate;
    packet.channel_id = channel_id;
    packet.signal_quality = signal_quality;
    packet.security = security;
    mav_array_memcpy(packet.ssid, ssid, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WIFI_NETWORK_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WIFI_NETWORK_INFO;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WIFI_NETWORK_INFO_MIN_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_INFO_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_INFO_CRC);
}

/**
 * @brief Pack a wifi_network_info message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ssid  Name of Wi-Fi network (SSID).
 * @param channel_id  WiFi network operating channel ID. Set to 0 if unknown or unidentified.
 * @param signal_quality [%] WiFi network signal quality.
 * @param data_rate [MiB/s] WiFi network data rate. Set to UINT16_MAX if data_rate information is not supplied.
 * @param security  WiFi network security type.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wifi_network_info_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const char *ssid,uint8_t channel_id,uint8_t signal_quality,uint16_t data_rate,uint8_t security)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WIFI_NETWORK_INFO_LEN];
    _mav_put_uint16_t(buf, 0, data_rate);
    _mav_put_uint8_t(buf, 34, channel_id);
    _mav_put_uint8_t(buf, 35, signal_quality);
    _mav_put_uint8_t(buf, 36, security);
    _mav_put_char_array(buf, 2, ssid, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WIFI_NETWORK_INFO_LEN);
#else
    mavlink_wifi_network_info_t packet;
    packet.data_rate = data_rate;
    packet.channel_id = channel_id;
    packet.signal_quality = signal_quality;
    packet.security = security;
    mav_array_memcpy(packet.ssid, ssid, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WIFI_NETWORK_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WIFI_NETWORK_INFO;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WIFI_NETWORK_INFO_MIN_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_INFO_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_INFO_CRC);
}

/**
 * @brief Encode a wifi_network_info struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wifi_network_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wifi_network_info_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wifi_network_info_t* wifi_network_info)
{
    return mavlink_msg_wifi_network_info_pack(system_id, component_id, msg, wifi_network_info->ssid, wifi_network_info->channel_id, wifi_network_info->signal_quality, wifi_network_info->data_rate, wifi_network_info->security);
}

/**
 * @brief Encode a wifi_network_info struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wifi_network_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wifi_network_info_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wifi_network_info_t* wifi_network_info)
{
    return mavlink_msg_wifi_network_info_pack_chan(system_id, component_id, chan, msg, wifi_network_info->ssid, wifi_network_info->channel_id, wifi_network_info->signal_quality, wifi_network_info->data_rate, wifi_network_info->security);
}

/**
 * @brief Send a wifi_network_info message
 * @param chan MAVLink channel to send the message
 *
 * @param ssid  Name of Wi-Fi network (SSID).
 * @param channel_id  WiFi network operating channel ID. Set to 0 if unknown or unidentified.
 * @param signal_quality [%] WiFi network signal quality.
 * @param data_rate [MiB/s] WiFi network data rate. Set to UINT16_MAX if data_rate information is not supplied.
 * @param security  WiFi network security type.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wifi_network_info_send(mavlink_channel_t chan, const char *ssid, uint8_t channel_id, uint8_t signal_quality, uint16_t data_rate, uint8_t security)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WIFI_NETWORK_INFO_LEN];
    _mav_put_uint16_t(buf, 0, data_rate);
    _mav_put_uint8_t(buf, 34, channel_id);
    _mav_put_uint8_t(buf, 35, signal_quality);
    _mav_put_uint8_t(buf, 36, security);
    _mav_put_char_array(buf, 2, ssid, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIFI_NETWORK_INFO, buf, MAVLINK_MSG_ID_WIFI_NETWORK_INFO_MIN_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_INFO_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_INFO_CRC);
#else
    mavlink_wifi_network_info_t packet;
    packet.data_rate = data_rate;
    packet.channel_id = channel_id;
    packet.signal_quality = signal_quality;
    packet.security = security;
    mav_array_memcpy(packet.ssid, ssid, sizeof(char)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIFI_NETWORK_INFO, (const char *)&packet, MAVLINK_MSG_ID_WIFI_NETWORK_INFO_MIN_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_INFO_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_INFO_CRC);
#endif
}

/**
 * @brief Send a wifi_network_info message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wifi_network_info_send_struct(mavlink_channel_t chan, const mavlink_wifi_network_info_t* wifi_network_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wifi_network_info_send(chan, wifi_network_info->ssid, wifi_network_info->channel_id, wifi_network_info->signal_quality, wifi_network_info->data_rate, wifi_network_info->security);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIFI_NETWORK_INFO, (const char *)wifi_network_info, MAVLINK_MSG_ID_WIFI_NETWORK_INFO_MIN_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_INFO_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_INFO_CRC);
#endif
}

#if MAVLINK_MSG_ID_WIFI_NETWORK_INFO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wifi_network_info_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const char *ssid, uint8_t channel_id, uint8_t signal_quality, uint16_t data_rate, uint8_t security)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, data_rate);
    _mav_put_uint8_t(buf, 34, channel_id);
    _mav_put_uint8_t(buf, 35, signal_quality);
    _mav_put_uint8_t(buf, 36, security);
    _mav_put_char_array(buf, 2, ssid, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIFI_NETWORK_INFO, buf, MAVLINK_MSG_ID_WIFI_NETWORK_INFO_MIN_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_INFO_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_INFO_CRC);
#else
    mavlink_wifi_network_info_t *packet = (mavlink_wifi_network_info_t *)msgbuf;
    packet->data_rate = data_rate;
    packet->channel_id = channel_id;
    packet->signal_quality = signal_quality;
    packet->security = security;
    mav_array_memcpy(packet->ssid, ssid, sizeof(char)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIFI_NETWORK_INFO, (const char *)packet, MAVLINK_MSG_ID_WIFI_NETWORK_INFO_MIN_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_INFO_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_INFO_CRC);
#endif
}
#endif

#endif

// MESSAGE WIFI_NETWORK_INFO UNPACKING


/**
 * @brief Get field ssid from wifi_network_info message
 *
 * @return  Name of Wi-Fi network (SSID).
 */
static inline uint16_t mavlink_msg_wifi_network_info_get_ssid(const mavlink_message_t* msg, char *ssid)
{
    return _MAV_RETURN_char_array(msg, ssid, 32,  2);
}

/**
 * @brief Get field channel_id from wifi_network_info message
 *
 * @return  WiFi network operating channel ID. Set to 0 if unknown or unidentified.
 */
static inline uint8_t mavlink_msg_wifi_network_info_get_channel_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  34);
}

/**
 * @brief Get field signal_quality from wifi_network_info message
 *
 * @return [%] WiFi network signal quality.
 */
static inline uint8_t mavlink_msg_wifi_network_info_get_signal_quality(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  35);
}

/**
 * @brief Get field data_rate from wifi_network_info message
 *
 * @return [MiB/s] WiFi network data rate. Set to UINT16_MAX if data_rate information is not supplied.
 */
static inline uint16_t mavlink_msg_wifi_network_info_get_data_rate(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field security from wifi_network_info message
 *
 * @return  WiFi network security type.
 */
static inline uint8_t mavlink_msg_wifi_network_info_get_security(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  36);
}

/**
 * @brief Decode a wifi_network_info message into a struct
 *
 * @param msg The message to decode
 * @param wifi_network_info C-struct to decode the message contents into
 */
static inline void mavlink_msg_wifi_network_info_decode(const mavlink_message_t* msg, mavlink_wifi_network_info_t* wifi_network_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wifi_network_info->data_rate = mavlink_msg_wifi_network_info_get_data_rate(msg);
    mavlink_msg_wifi_network_info_get_ssid(msg, wifi_network_info->ssid);
    wifi_network_info->channel_id = mavlink_msg_wifi_network_info_get_channel_id(msg);
    wifi_network_info->signal_quality = mavlink_msg_wifi_network_info_get_signal_quality(msg);
    wifi_network_info->security = mavlink_msg_wifi_network_info_get_security(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WIFI_NETWORK_INFO_LEN? msg->len : MAVLINK_MSG_ID_WIFI_NETWORK_INFO_LEN;
        memset(wifi_network_info, 0, MAVLINK_MSG_ID_WIFI_NETWORK_INFO_LEN);
    memcpy(wifi_network_info, _MAV_PAYLOAD(msg), len);
#endif
}
