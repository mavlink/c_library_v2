#pragma once
// MESSAGE RADIO_LINK_STATS PACKING

#define MAVLINK_MSG_ID_RADIO_LINK_STATS 60046


typedef struct __mavlink_radio_link_stats_t {
 uint8_t flags; /*<  Radio link statistics flags.*/
 uint8_t rx_LQ; /*< [c%] Values: 0..100. UINT8_MAX: invalid/unknown.*/
 uint8_t rx_rssi1; /*<  Rssi of antenna1. UINT8_MAX: invalid/unknown.*/
 int8_t rx_snr1; /*<  Noise on antenna1. Radio dependent. INT8_MAX: invalid/unknown.*/
 uint8_t rx_rssi2; /*<  Rssi of antenna2. UINT8_MAX: ignore/unknown, use rx_rssi1.*/
 int8_t rx_snr2; /*<  Noise on antenna2. Radio dependent. INT8_MAX: ignore/unknown, use rx_snr1.*/
 uint8_t rx_receive_antenna; /*<  0: antenna1, 1: antenna2, UINT8_MAX: ignore, no Rx receive diversity, use rx_rssi1, rx_snr1.*/
 uint8_t rx_transmit_antenna; /*<  0: antenna1, 1: antenna2, UINT8_MAX: ignore, no Rx transmit diversity.*/
 uint8_t tx_LQ; /*< [c%] Values: 0..100. UINT8_MAX: invalid/unknown.*/
 uint8_t tx_rssi1; /*<  Rssi of antenna1. UINT8_MAX: invalid/unknown.*/
 int8_t tx_snr1; /*<  Noise on antenna1. Radio dependent. INT8_MAX: invalid/unknown.*/
 uint8_t tx_rssi2; /*<  Rssi of antenna2. UINT8_MAX: ignore/unknown, use tx_rssi1.*/
 int8_t tx_snr2; /*<  Noise on antenna2. Radio dependent. INT8_MAX: ignore/unknown, use tx_snr1.*/
 uint8_t tx_receive_antenna; /*<  0: antenna1, 1: antenna2, UINT8_MAX: ignore, no Tx receive diversity, use tx_rssi1, tx_snr1.*/
 uint8_t tx_transmit_antenna; /*<  0: antenna1, 1: antenna2, UINT8_MAX: ignore, no Tx transmit diversity.*/
} mavlink_radio_link_stats_t;

#define MAVLINK_MSG_ID_RADIO_LINK_STATS_LEN 15
#define MAVLINK_MSG_ID_RADIO_LINK_STATS_MIN_LEN 15
#define MAVLINK_MSG_ID_60046_LEN 15
#define MAVLINK_MSG_ID_60046_MIN_LEN 15

#define MAVLINK_MSG_ID_RADIO_LINK_STATS_CRC 238
#define MAVLINK_MSG_ID_60046_CRC 238



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RADIO_LINK_STATS { \
    60046, \
    "RADIO_LINK_STATS", \
    15, \
    {  { "flags", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_radio_link_stats_t, flags) }, \
         { "rx_LQ", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_radio_link_stats_t, rx_LQ) }, \
         { "rx_rssi1", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_radio_link_stats_t, rx_rssi1) }, \
         { "rx_snr1", NULL, MAVLINK_TYPE_INT8_T, 0, 3, offsetof(mavlink_radio_link_stats_t, rx_snr1) }, \
         { "rx_rssi2", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_radio_link_stats_t, rx_rssi2) }, \
         { "rx_snr2", NULL, MAVLINK_TYPE_INT8_T, 0, 5, offsetof(mavlink_radio_link_stats_t, rx_snr2) }, \
         { "rx_receive_antenna", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_radio_link_stats_t, rx_receive_antenna) }, \
         { "rx_transmit_antenna", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_radio_link_stats_t, rx_transmit_antenna) }, \
         { "tx_LQ", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_radio_link_stats_t, tx_LQ) }, \
         { "tx_rssi1", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_radio_link_stats_t, tx_rssi1) }, \
         { "tx_snr1", NULL, MAVLINK_TYPE_INT8_T, 0, 10, offsetof(mavlink_radio_link_stats_t, tx_snr1) }, \
         { "tx_rssi2", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_radio_link_stats_t, tx_rssi2) }, \
         { "tx_snr2", NULL, MAVLINK_TYPE_INT8_T, 0, 12, offsetof(mavlink_radio_link_stats_t, tx_snr2) }, \
         { "tx_receive_antenna", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_radio_link_stats_t, tx_receive_antenna) }, \
         { "tx_transmit_antenna", NULL, MAVLINK_TYPE_UINT8_T, 0, 14, offsetof(mavlink_radio_link_stats_t, tx_transmit_antenna) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_RADIO_LINK_STATS { \
    "RADIO_LINK_STATS", \
    15, \
    {  { "flags", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_radio_link_stats_t, flags) }, \
         { "rx_LQ", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_radio_link_stats_t, rx_LQ) }, \
         { "rx_rssi1", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_radio_link_stats_t, rx_rssi1) }, \
         { "rx_snr1", NULL, MAVLINK_TYPE_INT8_T, 0, 3, offsetof(mavlink_radio_link_stats_t, rx_snr1) }, \
         { "rx_rssi2", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_radio_link_stats_t, rx_rssi2) }, \
         { "rx_snr2", NULL, MAVLINK_TYPE_INT8_T, 0, 5, offsetof(mavlink_radio_link_stats_t, rx_snr2) }, \
         { "rx_receive_antenna", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_radio_link_stats_t, rx_receive_antenna) }, \
         { "rx_transmit_antenna", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_radio_link_stats_t, rx_transmit_antenna) }, \
         { "tx_LQ", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_radio_link_stats_t, tx_LQ) }, \
         { "tx_rssi1", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_radio_link_stats_t, tx_rssi1) }, \
         { "tx_snr1", NULL, MAVLINK_TYPE_INT8_T, 0, 10, offsetof(mavlink_radio_link_stats_t, tx_snr1) }, \
         { "tx_rssi2", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_radio_link_stats_t, tx_rssi2) }, \
         { "tx_snr2", NULL, MAVLINK_TYPE_INT8_T, 0, 12, offsetof(mavlink_radio_link_stats_t, tx_snr2) }, \
         { "tx_receive_antenna", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_radio_link_stats_t, tx_receive_antenna) }, \
         { "tx_transmit_antenna", NULL, MAVLINK_TYPE_UINT8_T, 0, 14, offsetof(mavlink_radio_link_stats_t, tx_transmit_antenna) }, \
         } \
}
#endif

/**
 * @brief Pack a radio_link_stats message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param flags  Radio link statistics flags.
 * @param rx_LQ [c%] Values: 0..100. UINT8_MAX: invalid/unknown.
 * @param rx_rssi1  Rssi of antenna1. UINT8_MAX: invalid/unknown.
 * @param rx_snr1  Noise on antenna1. Radio dependent. INT8_MAX: invalid/unknown.
 * @param rx_rssi2  Rssi of antenna2. UINT8_MAX: ignore/unknown, use rx_rssi1.
 * @param rx_snr2  Noise on antenna2. Radio dependent. INT8_MAX: ignore/unknown, use rx_snr1.
 * @param rx_receive_antenna  0: antenna1, 1: antenna2, UINT8_MAX: ignore, no Rx receive diversity, use rx_rssi1, rx_snr1.
 * @param rx_transmit_antenna  0: antenna1, 1: antenna2, UINT8_MAX: ignore, no Rx transmit diversity.
 * @param tx_LQ [c%] Values: 0..100. UINT8_MAX: invalid/unknown.
 * @param tx_rssi1  Rssi of antenna1. UINT8_MAX: invalid/unknown.
 * @param tx_snr1  Noise on antenna1. Radio dependent. INT8_MAX: invalid/unknown.
 * @param tx_rssi2  Rssi of antenna2. UINT8_MAX: ignore/unknown, use tx_rssi1.
 * @param tx_snr2  Noise on antenna2. Radio dependent. INT8_MAX: ignore/unknown, use tx_snr1.
 * @param tx_receive_antenna  0: antenna1, 1: antenna2, UINT8_MAX: ignore, no Tx receive diversity, use tx_rssi1, tx_snr1.
 * @param tx_transmit_antenna  0: antenna1, 1: antenna2, UINT8_MAX: ignore, no Tx transmit diversity.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_radio_link_stats_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t flags, uint8_t rx_LQ, uint8_t rx_rssi1, int8_t rx_snr1, uint8_t rx_rssi2, int8_t rx_snr2, uint8_t rx_receive_antenna, uint8_t rx_transmit_antenna, uint8_t tx_LQ, uint8_t tx_rssi1, int8_t tx_snr1, uint8_t tx_rssi2, int8_t tx_snr2, uint8_t tx_receive_antenna, uint8_t tx_transmit_antenna)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RADIO_LINK_STATS_LEN];
    _mav_put_uint8_t(buf, 0, flags);
    _mav_put_uint8_t(buf, 1, rx_LQ);
    _mav_put_uint8_t(buf, 2, rx_rssi1);
    _mav_put_int8_t(buf, 3, rx_snr1);
    _mav_put_uint8_t(buf, 4, rx_rssi2);
    _mav_put_int8_t(buf, 5, rx_snr2);
    _mav_put_uint8_t(buf, 6, rx_receive_antenna);
    _mav_put_uint8_t(buf, 7, rx_transmit_antenna);
    _mav_put_uint8_t(buf, 8, tx_LQ);
    _mav_put_uint8_t(buf, 9, tx_rssi1);
    _mav_put_int8_t(buf, 10, tx_snr1);
    _mav_put_uint8_t(buf, 11, tx_rssi2);
    _mav_put_int8_t(buf, 12, tx_snr2);
    _mav_put_uint8_t(buf, 13, tx_receive_antenna);
    _mav_put_uint8_t(buf, 14, tx_transmit_antenna);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RADIO_LINK_STATS_LEN);
#else
    mavlink_radio_link_stats_t packet;
    packet.flags = flags;
    packet.rx_LQ = rx_LQ;
    packet.rx_rssi1 = rx_rssi1;
    packet.rx_snr1 = rx_snr1;
    packet.rx_rssi2 = rx_rssi2;
    packet.rx_snr2 = rx_snr2;
    packet.rx_receive_antenna = rx_receive_antenna;
    packet.rx_transmit_antenna = rx_transmit_antenna;
    packet.tx_LQ = tx_LQ;
    packet.tx_rssi1 = tx_rssi1;
    packet.tx_snr1 = tx_snr1;
    packet.tx_rssi2 = tx_rssi2;
    packet.tx_snr2 = tx_snr2;
    packet.tx_receive_antenna = tx_receive_antenna;
    packet.tx_transmit_antenna = tx_transmit_antenna;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RADIO_LINK_STATS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RADIO_LINK_STATS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RADIO_LINK_STATS_MIN_LEN, MAVLINK_MSG_ID_RADIO_LINK_STATS_LEN, MAVLINK_MSG_ID_RADIO_LINK_STATS_CRC);
}

/**
 * @brief Pack a radio_link_stats message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param flags  Radio link statistics flags.
 * @param rx_LQ [c%] Values: 0..100. UINT8_MAX: invalid/unknown.
 * @param rx_rssi1  Rssi of antenna1. UINT8_MAX: invalid/unknown.
 * @param rx_snr1  Noise on antenna1. Radio dependent. INT8_MAX: invalid/unknown.
 * @param rx_rssi2  Rssi of antenna2. UINT8_MAX: ignore/unknown, use rx_rssi1.
 * @param rx_snr2  Noise on antenna2. Radio dependent. INT8_MAX: ignore/unknown, use rx_snr1.
 * @param rx_receive_antenna  0: antenna1, 1: antenna2, UINT8_MAX: ignore, no Rx receive diversity, use rx_rssi1, rx_snr1.
 * @param rx_transmit_antenna  0: antenna1, 1: antenna2, UINT8_MAX: ignore, no Rx transmit diversity.
 * @param tx_LQ [c%] Values: 0..100. UINT8_MAX: invalid/unknown.
 * @param tx_rssi1  Rssi of antenna1. UINT8_MAX: invalid/unknown.
 * @param tx_snr1  Noise on antenna1. Radio dependent. INT8_MAX: invalid/unknown.
 * @param tx_rssi2  Rssi of antenna2. UINT8_MAX: ignore/unknown, use tx_rssi1.
 * @param tx_snr2  Noise on antenna2. Radio dependent. INT8_MAX: ignore/unknown, use tx_snr1.
 * @param tx_receive_antenna  0: antenna1, 1: antenna2, UINT8_MAX: ignore, no Tx receive diversity, use tx_rssi1, tx_snr1.
 * @param tx_transmit_antenna  0: antenna1, 1: antenna2, UINT8_MAX: ignore, no Tx transmit diversity.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_radio_link_stats_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t flags,uint8_t rx_LQ,uint8_t rx_rssi1,int8_t rx_snr1,uint8_t rx_rssi2,int8_t rx_snr2,uint8_t rx_receive_antenna,uint8_t rx_transmit_antenna,uint8_t tx_LQ,uint8_t tx_rssi1,int8_t tx_snr1,uint8_t tx_rssi2,int8_t tx_snr2,uint8_t tx_receive_antenna,uint8_t tx_transmit_antenna)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RADIO_LINK_STATS_LEN];
    _mav_put_uint8_t(buf, 0, flags);
    _mav_put_uint8_t(buf, 1, rx_LQ);
    _mav_put_uint8_t(buf, 2, rx_rssi1);
    _mav_put_int8_t(buf, 3, rx_snr1);
    _mav_put_uint8_t(buf, 4, rx_rssi2);
    _mav_put_int8_t(buf, 5, rx_snr2);
    _mav_put_uint8_t(buf, 6, rx_receive_antenna);
    _mav_put_uint8_t(buf, 7, rx_transmit_antenna);
    _mav_put_uint8_t(buf, 8, tx_LQ);
    _mav_put_uint8_t(buf, 9, tx_rssi1);
    _mav_put_int8_t(buf, 10, tx_snr1);
    _mav_put_uint8_t(buf, 11, tx_rssi2);
    _mav_put_int8_t(buf, 12, tx_snr2);
    _mav_put_uint8_t(buf, 13, tx_receive_antenna);
    _mav_put_uint8_t(buf, 14, tx_transmit_antenna);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RADIO_LINK_STATS_LEN);
#else
    mavlink_radio_link_stats_t packet;
    packet.flags = flags;
    packet.rx_LQ = rx_LQ;
    packet.rx_rssi1 = rx_rssi1;
    packet.rx_snr1 = rx_snr1;
    packet.rx_rssi2 = rx_rssi2;
    packet.rx_snr2 = rx_snr2;
    packet.rx_receive_antenna = rx_receive_antenna;
    packet.rx_transmit_antenna = rx_transmit_antenna;
    packet.tx_LQ = tx_LQ;
    packet.tx_rssi1 = tx_rssi1;
    packet.tx_snr1 = tx_snr1;
    packet.tx_rssi2 = tx_rssi2;
    packet.tx_snr2 = tx_snr2;
    packet.tx_receive_antenna = tx_receive_antenna;
    packet.tx_transmit_antenna = tx_transmit_antenna;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RADIO_LINK_STATS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RADIO_LINK_STATS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RADIO_LINK_STATS_MIN_LEN, MAVLINK_MSG_ID_RADIO_LINK_STATS_LEN, MAVLINK_MSG_ID_RADIO_LINK_STATS_CRC);
}

/**
 * @brief Encode a radio_link_stats struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param radio_link_stats C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_radio_link_stats_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_radio_link_stats_t* radio_link_stats)
{
    return mavlink_msg_radio_link_stats_pack(system_id, component_id, msg, radio_link_stats->flags, radio_link_stats->rx_LQ, radio_link_stats->rx_rssi1, radio_link_stats->rx_snr1, radio_link_stats->rx_rssi2, radio_link_stats->rx_snr2, radio_link_stats->rx_receive_antenna, radio_link_stats->rx_transmit_antenna, radio_link_stats->tx_LQ, radio_link_stats->tx_rssi1, radio_link_stats->tx_snr1, radio_link_stats->tx_rssi2, radio_link_stats->tx_snr2, radio_link_stats->tx_receive_antenna, radio_link_stats->tx_transmit_antenna);
}

/**
 * @brief Encode a radio_link_stats struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param radio_link_stats C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_radio_link_stats_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_radio_link_stats_t* radio_link_stats)
{
    return mavlink_msg_radio_link_stats_pack_chan(system_id, component_id, chan, msg, radio_link_stats->flags, radio_link_stats->rx_LQ, radio_link_stats->rx_rssi1, radio_link_stats->rx_snr1, radio_link_stats->rx_rssi2, radio_link_stats->rx_snr2, radio_link_stats->rx_receive_antenna, radio_link_stats->rx_transmit_antenna, radio_link_stats->tx_LQ, radio_link_stats->tx_rssi1, radio_link_stats->tx_snr1, radio_link_stats->tx_rssi2, radio_link_stats->tx_snr2, radio_link_stats->tx_receive_antenna, radio_link_stats->tx_transmit_antenna);
}

/**
 * @brief Send a radio_link_stats message
 * @param chan MAVLink channel to send the message
 *
 * @param flags  Radio link statistics flags.
 * @param rx_LQ [c%] Values: 0..100. UINT8_MAX: invalid/unknown.
 * @param rx_rssi1  Rssi of antenna1. UINT8_MAX: invalid/unknown.
 * @param rx_snr1  Noise on antenna1. Radio dependent. INT8_MAX: invalid/unknown.
 * @param rx_rssi2  Rssi of antenna2. UINT8_MAX: ignore/unknown, use rx_rssi1.
 * @param rx_snr2  Noise on antenna2. Radio dependent. INT8_MAX: ignore/unknown, use rx_snr1.
 * @param rx_receive_antenna  0: antenna1, 1: antenna2, UINT8_MAX: ignore, no Rx receive diversity, use rx_rssi1, rx_snr1.
 * @param rx_transmit_antenna  0: antenna1, 1: antenna2, UINT8_MAX: ignore, no Rx transmit diversity.
 * @param tx_LQ [c%] Values: 0..100. UINT8_MAX: invalid/unknown.
 * @param tx_rssi1  Rssi of antenna1. UINT8_MAX: invalid/unknown.
 * @param tx_snr1  Noise on antenna1. Radio dependent. INT8_MAX: invalid/unknown.
 * @param tx_rssi2  Rssi of antenna2. UINT8_MAX: ignore/unknown, use tx_rssi1.
 * @param tx_snr2  Noise on antenna2. Radio dependent. INT8_MAX: ignore/unknown, use tx_snr1.
 * @param tx_receive_antenna  0: antenna1, 1: antenna2, UINT8_MAX: ignore, no Tx receive diversity, use tx_rssi1, tx_snr1.
 * @param tx_transmit_antenna  0: antenna1, 1: antenna2, UINT8_MAX: ignore, no Tx transmit diversity.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_radio_link_stats_send(mavlink_channel_t chan, uint8_t flags, uint8_t rx_LQ, uint8_t rx_rssi1, int8_t rx_snr1, uint8_t rx_rssi2, int8_t rx_snr2, uint8_t rx_receive_antenna, uint8_t rx_transmit_antenna, uint8_t tx_LQ, uint8_t tx_rssi1, int8_t tx_snr1, uint8_t tx_rssi2, int8_t tx_snr2, uint8_t tx_receive_antenna, uint8_t tx_transmit_antenna)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RADIO_LINK_STATS_LEN];
    _mav_put_uint8_t(buf, 0, flags);
    _mav_put_uint8_t(buf, 1, rx_LQ);
    _mav_put_uint8_t(buf, 2, rx_rssi1);
    _mav_put_int8_t(buf, 3, rx_snr1);
    _mav_put_uint8_t(buf, 4, rx_rssi2);
    _mav_put_int8_t(buf, 5, rx_snr2);
    _mav_put_uint8_t(buf, 6, rx_receive_antenna);
    _mav_put_uint8_t(buf, 7, rx_transmit_antenna);
    _mav_put_uint8_t(buf, 8, tx_LQ);
    _mav_put_uint8_t(buf, 9, tx_rssi1);
    _mav_put_int8_t(buf, 10, tx_snr1);
    _mav_put_uint8_t(buf, 11, tx_rssi2);
    _mav_put_int8_t(buf, 12, tx_snr2);
    _mav_put_uint8_t(buf, 13, tx_receive_antenna);
    _mav_put_uint8_t(buf, 14, tx_transmit_antenna);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADIO_LINK_STATS, buf, MAVLINK_MSG_ID_RADIO_LINK_STATS_MIN_LEN, MAVLINK_MSG_ID_RADIO_LINK_STATS_LEN, MAVLINK_MSG_ID_RADIO_LINK_STATS_CRC);
#else
    mavlink_radio_link_stats_t packet;
    packet.flags = flags;
    packet.rx_LQ = rx_LQ;
    packet.rx_rssi1 = rx_rssi1;
    packet.rx_snr1 = rx_snr1;
    packet.rx_rssi2 = rx_rssi2;
    packet.rx_snr2 = rx_snr2;
    packet.rx_receive_antenna = rx_receive_antenna;
    packet.rx_transmit_antenna = rx_transmit_antenna;
    packet.tx_LQ = tx_LQ;
    packet.tx_rssi1 = tx_rssi1;
    packet.tx_snr1 = tx_snr1;
    packet.tx_rssi2 = tx_rssi2;
    packet.tx_snr2 = tx_snr2;
    packet.tx_receive_antenna = tx_receive_antenna;
    packet.tx_transmit_antenna = tx_transmit_antenna;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADIO_LINK_STATS, (const char *)&packet, MAVLINK_MSG_ID_RADIO_LINK_STATS_MIN_LEN, MAVLINK_MSG_ID_RADIO_LINK_STATS_LEN, MAVLINK_MSG_ID_RADIO_LINK_STATS_CRC);
#endif
}

/**
 * @brief Send a radio_link_stats message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_radio_link_stats_send_struct(mavlink_channel_t chan, const mavlink_radio_link_stats_t* radio_link_stats)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_radio_link_stats_send(chan, radio_link_stats->flags, radio_link_stats->rx_LQ, radio_link_stats->rx_rssi1, radio_link_stats->rx_snr1, radio_link_stats->rx_rssi2, radio_link_stats->rx_snr2, radio_link_stats->rx_receive_antenna, radio_link_stats->rx_transmit_antenna, radio_link_stats->tx_LQ, radio_link_stats->tx_rssi1, radio_link_stats->tx_snr1, radio_link_stats->tx_rssi2, radio_link_stats->tx_snr2, radio_link_stats->tx_receive_antenna, radio_link_stats->tx_transmit_antenna);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADIO_LINK_STATS, (const char *)radio_link_stats, MAVLINK_MSG_ID_RADIO_LINK_STATS_MIN_LEN, MAVLINK_MSG_ID_RADIO_LINK_STATS_LEN, MAVLINK_MSG_ID_RADIO_LINK_STATS_CRC);
#endif
}

#if MAVLINK_MSG_ID_RADIO_LINK_STATS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_radio_link_stats_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t flags, uint8_t rx_LQ, uint8_t rx_rssi1, int8_t rx_snr1, uint8_t rx_rssi2, int8_t rx_snr2, uint8_t rx_receive_antenna, uint8_t rx_transmit_antenna, uint8_t tx_LQ, uint8_t tx_rssi1, int8_t tx_snr1, uint8_t tx_rssi2, int8_t tx_snr2, uint8_t tx_receive_antenna, uint8_t tx_transmit_antenna)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, flags);
    _mav_put_uint8_t(buf, 1, rx_LQ);
    _mav_put_uint8_t(buf, 2, rx_rssi1);
    _mav_put_int8_t(buf, 3, rx_snr1);
    _mav_put_uint8_t(buf, 4, rx_rssi2);
    _mav_put_int8_t(buf, 5, rx_snr2);
    _mav_put_uint8_t(buf, 6, rx_receive_antenna);
    _mav_put_uint8_t(buf, 7, rx_transmit_antenna);
    _mav_put_uint8_t(buf, 8, tx_LQ);
    _mav_put_uint8_t(buf, 9, tx_rssi1);
    _mav_put_int8_t(buf, 10, tx_snr1);
    _mav_put_uint8_t(buf, 11, tx_rssi2);
    _mav_put_int8_t(buf, 12, tx_snr2);
    _mav_put_uint8_t(buf, 13, tx_receive_antenna);
    _mav_put_uint8_t(buf, 14, tx_transmit_antenna);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADIO_LINK_STATS, buf, MAVLINK_MSG_ID_RADIO_LINK_STATS_MIN_LEN, MAVLINK_MSG_ID_RADIO_LINK_STATS_LEN, MAVLINK_MSG_ID_RADIO_LINK_STATS_CRC);
#else
    mavlink_radio_link_stats_t *packet = (mavlink_radio_link_stats_t *)msgbuf;
    packet->flags = flags;
    packet->rx_LQ = rx_LQ;
    packet->rx_rssi1 = rx_rssi1;
    packet->rx_snr1 = rx_snr1;
    packet->rx_rssi2 = rx_rssi2;
    packet->rx_snr2 = rx_snr2;
    packet->rx_receive_antenna = rx_receive_antenna;
    packet->rx_transmit_antenna = rx_transmit_antenna;
    packet->tx_LQ = tx_LQ;
    packet->tx_rssi1 = tx_rssi1;
    packet->tx_snr1 = tx_snr1;
    packet->tx_rssi2 = tx_rssi2;
    packet->tx_snr2 = tx_snr2;
    packet->tx_receive_antenna = tx_receive_antenna;
    packet->tx_transmit_antenna = tx_transmit_antenna;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RADIO_LINK_STATS, (const char *)packet, MAVLINK_MSG_ID_RADIO_LINK_STATS_MIN_LEN, MAVLINK_MSG_ID_RADIO_LINK_STATS_LEN, MAVLINK_MSG_ID_RADIO_LINK_STATS_CRC);
#endif
}
#endif

#endif

// MESSAGE RADIO_LINK_STATS UNPACKING


/**
 * @brief Get field flags from radio_link_stats message
 *
 * @return  Radio link statistics flags.
 */
static inline uint8_t mavlink_msg_radio_link_stats_get_flags(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field rx_LQ from radio_link_stats message
 *
 * @return [c%] Values: 0..100. UINT8_MAX: invalid/unknown.
 */
static inline uint8_t mavlink_msg_radio_link_stats_get_rx_LQ(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field rx_rssi1 from radio_link_stats message
 *
 * @return  Rssi of antenna1. UINT8_MAX: invalid/unknown.
 */
static inline uint8_t mavlink_msg_radio_link_stats_get_rx_rssi1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field rx_snr1 from radio_link_stats message
 *
 * @return  Noise on antenna1. Radio dependent. INT8_MAX: invalid/unknown.
 */
static inline int8_t mavlink_msg_radio_link_stats_get_rx_snr1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  3);
}

/**
 * @brief Get field rx_rssi2 from radio_link_stats message
 *
 * @return  Rssi of antenna2. UINT8_MAX: ignore/unknown, use rx_rssi1.
 */
static inline uint8_t mavlink_msg_radio_link_stats_get_rx_rssi2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field rx_snr2 from radio_link_stats message
 *
 * @return  Noise on antenna2. Radio dependent. INT8_MAX: ignore/unknown, use rx_snr1.
 */
static inline int8_t mavlink_msg_radio_link_stats_get_rx_snr2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  5);
}

/**
 * @brief Get field rx_receive_antenna from radio_link_stats message
 *
 * @return  0: antenna1, 1: antenna2, UINT8_MAX: ignore, no Rx receive diversity, use rx_rssi1, rx_snr1.
 */
static inline uint8_t mavlink_msg_radio_link_stats_get_rx_receive_antenna(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field rx_transmit_antenna from radio_link_stats message
 *
 * @return  0: antenna1, 1: antenna2, UINT8_MAX: ignore, no Rx transmit diversity.
 */
static inline uint8_t mavlink_msg_radio_link_stats_get_rx_transmit_antenna(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  7);
}

/**
 * @brief Get field tx_LQ from radio_link_stats message
 *
 * @return [c%] Values: 0..100. UINT8_MAX: invalid/unknown.
 */
static inline uint8_t mavlink_msg_radio_link_stats_get_tx_LQ(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field tx_rssi1 from radio_link_stats message
 *
 * @return  Rssi of antenna1. UINT8_MAX: invalid/unknown.
 */
static inline uint8_t mavlink_msg_radio_link_stats_get_tx_rssi1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field tx_snr1 from radio_link_stats message
 *
 * @return  Noise on antenna1. Radio dependent. INT8_MAX: invalid/unknown.
 */
static inline int8_t mavlink_msg_radio_link_stats_get_tx_snr1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  10);
}

/**
 * @brief Get field tx_rssi2 from radio_link_stats message
 *
 * @return  Rssi of antenna2. UINT8_MAX: ignore/unknown, use tx_rssi1.
 */
static inline uint8_t mavlink_msg_radio_link_stats_get_tx_rssi2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  11);
}

/**
 * @brief Get field tx_snr2 from radio_link_stats message
 *
 * @return  Noise on antenna2. Radio dependent. INT8_MAX: ignore/unknown, use tx_snr1.
 */
static inline int8_t mavlink_msg_radio_link_stats_get_tx_snr2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  12);
}

/**
 * @brief Get field tx_receive_antenna from radio_link_stats message
 *
 * @return  0: antenna1, 1: antenna2, UINT8_MAX: ignore, no Tx receive diversity, use tx_rssi1, tx_snr1.
 */
static inline uint8_t mavlink_msg_radio_link_stats_get_tx_receive_antenna(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  13);
}

/**
 * @brief Get field tx_transmit_antenna from radio_link_stats message
 *
 * @return  0: antenna1, 1: antenna2, UINT8_MAX: ignore, no Tx transmit diversity.
 */
static inline uint8_t mavlink_msg_radio_link_stats_get_tx_transmit_antenna(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  14);
}

/**
 * @brief Decode a radio_link_stats message into a struct
 *
 * @param msg The message to decode
 * @param radio_link_stats C-struct to decode the message contents into
 */
static inline void mavlink_msg_radio_link_stats_decode(const mavlink_message_t* msg, mavlink_radio_link_stats_t* radio_link_stats)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    radio_link_stats->flags = mavlink_msg_radio_link_stats_get_flags(msg);
    radio_link_stats->rx_LQ = mavlink_msg_radio_link_stats_get_rx_LQ(msg);
    radio_link_stats->rx_rssi1 = mavlink_msg_radio_link_stats_get_rx_rssi1(msg);
    radio_link_stats->rx_snr1 = mavlink_msg_radio_link_stats_get_rx_snr1(msg);
    radio_link_stats->rx_rssi2 = mavlink_msg_radio_link_stats_get_rx_rssi2(msg);
    radio_link_stats->rx_snr2 = mavlink_msg_radio_link_stats_get_rx_snr2(msg);
    radio_link_stats->rx_receive_antenna = mavlink_msg_radio_link_stats_get_rx_receive_antenna(msg);
    radio_link_stats->rx_transmit_antenna = mavlink_msg_radio_link_stats_get_rx_transmit_antenna(msg);
    radio_link_stats->tx_LQ = mavlink_msg_radio_link_stats_get_tx_LQ(msg);
    radio_link_stats->tx_rssi1 = mavlink_msg_radio_link_stats_get_tx_rssi1(msg);
    radio_link_stats->tx_snr1 = mavlink_msg_radio_link_stats_get_tx_snr1(msg);
    radio_link_stats->tx_rssi2 = mavlink_msg_radio_link_stats_get_tx_rssi2(msg);
    radio_link_stats->tx_snr2 = mavlink_msg_radio_link_stats_get_tx_snr2(msg);
    radio_link_stats->tx_receive_antenna = mavlink_msg_radio_link_stats_get_tx_receive_antenna(msg);
    radio_link_stats->tx_transmit_antenna = mavlink_msg_radio_link_stats_get_tx_transmit_antenna(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_RADIO_LINK_STATS_LEN? msg->len : MAVLINK_MSG_ID_RADIO_LINK_STATS_LEN;
        memset(radio_link_stats, 0, MAVLINK_MSG_ID_RADIO_LINK_STATS_LEN);
    memcpy(radio_link_stats, _MAV_PAYLOAD(msg), len);
#endif
}
