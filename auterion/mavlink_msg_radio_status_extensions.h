#pragma once
// MESSAGE RADIO_STATUS_EXTENSIONS PACKING

#define MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS 420


typedef struct __mavlink_radio_status_extensions_t {
 uint8_t rssi; /*< [dB] Local (message sender) recieved signal strength indication in decibels.*/
 uint8_t snr; /*< [dB]   Local (message sender) signal to noise ratio in decibels.*/
 uint8_t mcs_index; /*<   Local (message sender) Modulation Coding Scheme index. This index uniquely describes the combination of number of spatial streams, modulation type and coding scheme.*/
 uint8_t number_spatial_streams; /*<   Local (message sender) number of spatial streams.*/
 uint8_t queue_size; /*<   Local (message sender) number of packets in buffer.*/
 uint8_t air_time; /*< [%] Local (message sender) percentage of time the radio is transmitting.*/
} mavlink_radio_status_extensions_t;

#define MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS_LEN 6
#define MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS_MIN_LEN 6
#define MAVLINK_MSG_ID_420_LEN 6
#define MAVLINK_MSG_ID_420_MIN_LEN 6

#define MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS_CRC 135
#define MAVLINK_MSG_ID_420_CRC 135



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RADIO_STATUS_EXTENSIONS { \
    420, \
    "RADIO_STATUS_EXTENSIONS", \
    6, \
    {  { "rssi", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_radio_status_extensions_t, rssi) }, \
         { "snr", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_radio_status_extensions_t, snr) }, \
         { "mcs_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_radio_status_extensions_t, mcs_index) }, \
         { "number_spatial_streams", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_radio_status_extensions_t, number_spatial_streams) }, \
         { "queue_size", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_radio_status_extensions_t, queue_size) }, \
         { "air_time", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_radio_status_extensions_t, air_time) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_RADIO_STATUS_EXTENSIONS { \
    "RADIO_STATUS_EXTENSIONS", \
    6, \
    {  { "rssi", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_radio_status_extensions_t, rssi) }, \
         { "snr", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_radio_status_extensions_t, snr) }, \
         { "mcs_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_radio_status_extensions_t, mcs_index) }, \
         { "number_spatial_streams", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_radio_status_extensions_t, number_spatial_streams) }, \
         { "queue_size", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_radio_status_extensions_t, queue_size) }, \
         { "air_time", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_radio_status_extensions_t, air_time) }, \
         } \
}
#endif

/**
 * @brief Pack a radio_status_extensions message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param rssi [dB] Local (message sender) recieved signal strength indication in decibels.
 * @param snr [dB]   Local (message sender) signal to noise ratio in decibels.
 * @param mcs_index   Local (message sender) Modulation Coding Scheme index. This index uniquely describes the combination of number of spatial streams, modulation type and coding scheme.
 * @param number_spatial_streams   Local (message sender) number of spatial streams.
 * @param queue_size   Local (message sender) number of packets in buffer.
 * @param air_time [%] Local (message sender) percentage of time the radio is transmitting.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_radio_status_extensions_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t rssi, uint8_t snr, uint8_t mcs_index, uint8_t number_spatial_streams, uint8_t queue_size, uint8_t air_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS_LEN];
    _mav_put_uint8_t(buf, 0, rssi);
    _mav_put_uint8_t(buf, 1, snr);
    _mav_put_uint8_t(buf, 2, mcs_index);
    _mav_put_uint8_t(buf, 3, number_spatial_streams);
    _mav_put_uint8_t(buf, 4, queue_size);
    _mav_put_uint8_t(buf, 5, air_time);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS_LEN);
#else
    mavlink_radio_status_extensions_t packet;
    packet.rssi = rssi;
    packet.snr = snr;
    packet.mcs_index = mcs_index;
    packet.number_spatial_streams = number_spatial_streams;
    packet.queue_size = queue_size;
    packet.air_time = air_time;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS_MIN_LEN, MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS_LEN, MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS_CRC);
}

/**
 * @brief Pack a radio_status_extensions message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param rssi [dB] Local (message sender) recieved signal strength indication in decibels.
 * @param snr [dB]   Local (message sender) signal to noise ratio in decibels.
 * @param mcs_index   Local (message sender) Modulation Coding Scheme index. This index uniquely describes the combination of number of spatial streams, modulation type and coding scheme.
 * @param number_spatial_streams   Local (message sender) number of spatial streams.
 * @param queue_size   Local (message sender) number of packets in buffer.
 * @param air_time [%] Local (message sender) percentage of time the radio is transmitting.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_radio_status_extensions_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t rssi,uint8_t snr,uint8_t mcs_index,uint8_t number_spatial_streams,uint8_t queue_size,uint8_t air_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS_LEN];
    _mav_put_uint8_t(buf, 0, rssi);
    _mav_put_uint8_t(buf, 1, snr);
    _mav_put_uint8_t(buf, 2, mcs_index);
    _mav_put_uint8_t(buf, 3, number_spatial_streams);
    _mav_put_uint8_t(buf, 4, queue_size);
    _mav_put_uint8_t(buf, 5, air_time);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS_LEN);
#else
    mavlink_radio_status_extensions_t packet;
    packet.rssi = rssi;
    packet.snr = snr;
    packet.mcs_index = mcs_index;
    packet.number_spatial_streams = number_spatial_streams;
    packet.queue_size = queue_size;
    packet.air_time = air_time;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS_MIN_LEN, MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS_LEN, MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS_CRC);
}

/**
 * @brief Encode a radio_status_extensions struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param radio_status_extensions C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_radio_status_extensions_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_radio_status_extensions_t* radio_status_extensions)
{
    return mavlink_msg_radio_status_extensions_pack(system_id, component_id, msg, radio_status_extensions->rssi, radio_status_extensions->snr, radio_status_extensions->mcs_index, radio_status_extensions->number_spatial_streams, radio_status_extensions->queue_size, radio_status_extensions->air_time);
}

/**
 * @brief Encode a radio_status_extensions struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param radio_status_extensions C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_radio_status_extensions_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_radio_status_extensions_t* radio_status_extensions)
{
    return mavlink_msg_radio_status_extensions_pack_chan(system_id, component_id, chan, msg, radio_status_extensions->rssi, radio_status_extensions->snr, radio_status_extensions->mcs_index, radio_status_extensions->number_spatial_streams, radio_status_extensions->queue_size, radio_status_extensions->air_time);
}

/**
 * @brief Send a radio_status_extensions message
 * @param chan MAVLink channel to send the message
 *
 * @param rssi [dB] Local (message sender) recieved signal strength indication in decibels.
 * @param snr [dB]   Local (message sender) signal to noise ratio in decibels.
 * @param mcs_index   Local (message sender) Modulation Coding Scheme index. This index uniquely describes the combination of number of spatial streams, modulation type and coding scheme.
 * @param number_spatial_streams   Local (message sender) number of spatial streams.
 * @param queue_size   Local (message sender) number of packets in buffer.
 * @param air_time [%] Local (message sender) percentage of time the radio is transmitting.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_radio_status_extensions_send(mavlink_channel_t chan, uint8_t rssi, uint8_t snr, uint8_t mcs_index, uint8_t number_spatial_streams, uint8_t queue_size, uint8_t air_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS_LEN];
    _mav_put_uint8_t(buf, 0, rssi);
    _mav_put_uint8_t(buf, 1, snr);
    _mav_put_uint8_t(buf, 2, mcs_index);
    _mav_put_uint8_t(buf, 3, number_spatial_streams);
    _mav_put_uint8_t(buf, 4, queue_size);
    _mav_put_uint8_t(buf, 5, air_time);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS, buf, MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS_MIN_LEN, MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS_LEN, MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS_CRC);
#else
    mavlink_radio_status_extensions_t packet;
    packet.rssi = rssi;
    packet.snr = snr;
    packet.mcs_index = mcs_index;
    packet.number_spatial_streams = number_spatial_streams;
    packet.queue_size = queue_size;
    packet.air_time = air_time;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS, (const char *)&packet, MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS_MIN_LEN, MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS_LEN, MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS_CRC);
#endif
}

/**
 * @brief Send a radio_status_extensions message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_radio_status_extensions_send_struct(mavlink_channel_t chan, const mavlink_radio_status_extensions_t* radio_status_extensions)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_radio_status_extensions_send(chan, radio_status_extensions->rssi, radio_status_extensions->snr, radio_status_extensions->mcs_index, radio_status_extensions->number_spatial_streams, radio_status_extensions->queue_size, radio_status_extensions->air_time);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS, (const char *)radio_status_extensions, MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS_MIN_LEN, MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS_LEN, MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS_CRC);
#endif
}

#if MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_radio_status_extensions_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t rssi, uint8_t snr, uint8_t mcs_index, uint8_t number_spatial_streams, uint8_t queue_size, uint8_t air_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, rssi);
    _mav_put_uint8_t(buf, 1, snr);
    _mav_put_uint8_t(buf, 2, mcs_index);
    _mav_put_uint8_t(buf, 3, number_spatial_streams);
    _mav_put_uint8_t(buf, 4, queue_size);
    _mav_put_uint8_t(buf, 5, air_time);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS, buf, MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS_MIN_LEN, MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS_LEN, MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS_CRC);
#else
    mavlink_radio_status_extensions_t *packet = (mavlink_radio_status_extensions_t *)msgbuf;
    packet->rssi = rssi;
    packet->snr = snr;
    packet->mcs_index = mcs_index;
    packet->number_spatial_streams = number_spatial_streams;
    packet->queue_size = queue_size;
    packet->air_time = air_time;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS, (const char *)packet, MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS_MIN_LEN, MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS_LEN, MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS_CRC);
#endif
}
#endif

#endif

// MESSAGE RADIO_STATUS_EXTENSIONS UNPACKING


/**
 * @brief Get field rssi from radio_status_extensions message
 *
 * @return [dB] Local (message sender) recieved signal strength indication in decibels.
 */
static inline uint8_t mavlink_msg_radio_status_extensions_get_rssi(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field snr from radio_status_extensions message
 *
 * @return [dB]   Local (message sender) signal to noise ratio in decibels.
 */
static inline uint8_t mavlink_msg_radio_status_extensions_get_snr(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field mcs_index from radio_status_extensions message
 *
 * @return   Local (message sender) Modulation Coding Scheme index. This index uniquely describes the combination of number of spatial streams, modulation type and coding scheme.
 */
static inline uint8_t mavlink_msg_radio_status_extensions_get_mcs_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field number_spatial_streams from radio_status_extensions message
 *
 * @return   Local (message sender) number of spatial streams.
 */
static inline uint8_t mavlink_msg_radio_status_extensions_get_number_spatial_streams(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field queue_size from radio_status_extensions message
 *
 * @return   Local (message sender) number of packets in buffer.
 */
static inline uint8_t mavlink_msg_radio_status_extensions_get_queue_size(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field air_time from radio_status_extensions message
 *
 * @return [%] Local (message sender) percentage of time the radio is transmitting.
 */
static inline uint8_t mavlink_msg_radio_status_extensions_get_air_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Decode a radio_status_extensions message into a struct
 *
 * @param msg The message to decode
 * @param radio_status_extensions C-struct to decode the message contents into
 */
static inline void mavlink_msg_radio_status_extensions_decode(const mavlink_message_t* msg, mavlink_radio_status_extensions_t* radio_status_extensions)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    radio_status_extensions->rssi = mavlink_msg_radio_status_extensions_get_rssi(msg);
    radio_status_extensions->snr = mavlink_msg_radio_status_extensions_get_snr(msg);
    radio_status_extensions->mcs_index = mavlink_msg_radio_status_extensions_get_mcs_index(msg);
    radio_status_extensions->number_spatial_streams = mavlink_msg_radio_status_extensions_get_number_spatial_streams(msg);
    radio_status_extensions->queue_size = mavlink_msg_radio_status_extensions_get_queue_size(msg);
    radio_status_extensions->air_time = mavlink_msg_radio_status_extensions_get_air_time(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS_LEN? msg->len : MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS_LEN;
        memset(radio_status_extensions, 0, MAVLINK_MSG_ID_RADIO_STATUS_EXTENSIONS_LEN);
    memcpy(radio_status_extensions, _MAV_PAYLOAD(msg), len);
#endif
}
