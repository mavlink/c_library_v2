#pragma once
// MESSAGE CELLULAR_STATUS PACKING

#define MAVLINK_MSG_ID_CELLULAR_STATUS 334

MAVPACKED(
typedef struct __mavlink_cellular_status_t {
 uint16_t mcc; /*<  Mobile country code. If unknown, set to UINT16_MAX*/
 uint16_t mnc; /*<  Mobile network code. If unknown, set to UINT16_MAX*/
 uint16_t lac; /*<  Location area code. If unknown, set to 0*/
 uint8_t status; /*<  Cellular modem status*/
 uint8_t failure_reason; /*<  Failure reason when status in in CELLULAR_STATUS_FLAG_FAILED*/
 uint8_t type; /*<  Cellular network radio type: gsm, cdma, lte...*/
 uint8_t quality; /*<  Signal quality in percent. May be used for Received Signal Strength Indicator (RSSI). If unknown, set to UINT8_MAX*/
 uint8_t band_number; /*<  (WIP) LTE frequency band number.*/
 float band_frequency; /*< [MHz] (WIP) LTE radio frequency.*/
 uint16_t channel_number; /*<  (WIP) The channel number (CN). Absolute radio-frequency (ARFCN) / E-UTRA (EARFCN) / UTRA (UARFCN) / New radio (NR_CH).*/
 float rx_level; /*< [dBm] (WIP) On 3G is Received Signal Code Power (RSCP). On LTE Reference Signal Received Power (RSRP). On 5G  is New Radio Reference Signal Received Power (NR_RSRQ).*/
 float tx_level; /*< [dBm] (WIP) Transmitter (modem) signal absolute power level.*/
 float rx_quality; /*< [dBm] (WIP) On 3G is Receiver Quality (RxQual). On LTE is Reference Signal Received Quality (RSRQ). On 5G is New radio Reference Signal Received Quality (NR_RSRQ).*/
 uint32_t link_tx_rate; /*< [KiB/s] (WIP) Download rate.*/
 uint32_t link_rx_rate; /*< [KiB/s] (WIP) Upload rate.*/
 uint16_t ber; /*<  (WIP) The bit error rate (BER) is determined by comparing the erroneous bits received with the total number of bits received. It is a ratio.*/
 uint8_t id; /*<  (WIP) Cellular instance number. Indexed from 1. Matches index in corresponding CELLULAR_MODEM_INFORMATION message.*/
 char cell_tower_id[9]; /*<  (WIP) ID of the currently connected cell tower. This must be NULL terminated if the length is less than 9 human-readable chars, and without the null termination (NULL) byte if the length is exactly 9 chars.*/
}) mavlink_cellular_status_t;

#define MAVLINK_MSG_ID_CELLULAR_STATUS_LEN 49
#define MAVLINK_MSG_ID_CELLULAR_STATUS_MIN_LEN 10
#define MAVLINK_MSG_ID_334_LEN 49
#define MAVLINK_MSG_ID_334_MIN_LEN 10

#define MAVLINK_MSG_ID_CELLULAR_STATUS_CRC 72
#define MAVLINK_MSG_ID_334_CRC 72

#define MAVLINK_MSG_CELLULAR_STATUS_FIELD_CELL_TOWER_ID_LEN 9

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CELLULAR_STATUS { \
    334, \
    "CELLULAR_STATUS", \
    18, \
    {  { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_cellular_status_t, status) }, \
         { "failure_reason", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_cellular_status_t, failure_reason) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_cellular_status_t, type) }, \
         { "quality", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_cellular_status_t, quality) }, \
         { "mcc", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_cellular_status_t, mcc) }, \
         { "mnc", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_cellular_status_t, mnc) }, \
         { "lac", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_cellular_status_t, lac) }, \
         { "band_number", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_cellular_status_t, band_number) }, \
         { "band_frequency", NULL, MAVLINK_TYPE_FLOAT, 0, 11, offsetof(mavlink_cellular_status_t, band_frequency) }, \
         { "channel_number", NULL, MAVLINK_TYPE_UINT16_T, 0, 15, offsetof(mavlink_cellular_status_t, channel_number) }, \
         { "rx_level", NULL, MAVLINK_TYPE_FLOAT, 0, 17, offsetof(mavlink_cellular_status_t, rx_level) }, \
         { "tx_level", NULL, MAVLINK_TYPE_FLOAT, 0, 21, offsetof(mavlink_cellular_status_t, tx_level) }, \
         { "rx_quality", NULL, MAVLINK_TYPE_FLOAT, 0, 25, offsetof(mavlink_cellular_status_t, rx_quality) }, \
         { "link_tx_rate", NULL, MAVLINK_TYPE_UINT32_T, 0, 29, offsetof(mavlink_cellular_status_t, link_tx_rate) }, \
         { "link_rx_rate", NULL, MAVLINK_TYPE_UINT32_T, 0, 33, offsetof(mavlink_cellular_status_t, link_rx_rate) }, \
         { "ber", NULL, MAVLINK_TYPE_UINT16_T, 0, 37, offsetof(mavlink_cellular_status_t, ber) }, \
         { "id", NULL, MAVLINK_TYPE_UINT8_T, 0, 39, offsetof(mavlink_cellular_status_t, id) }, \
         { "cell_tower_id", NULL, MAVLINK_TYPE_CHAR, 9, 40, offsetof(mavlink_cellular_status_t, cell_tower_id) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CELLULAR_STATUS { \
    "CELLULAR_STATUS", \
    18, \
    {  { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_cellular_status_t, status) }, \
         { "failure_reason", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_cellular_status_t, failure_reason) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_cellular_status_t, type) }, \
         { "quality", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_cellular_status_t, quality) }, \
         { "mcc", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_cellular_status_t, mcc) }, \
         { "mnc", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_cellular_status_t, mnc) }, \
         { "lac", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_cellular_status_t, lac) }, \
         { "band_number", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_cellular_status_t, band_number) }, \
         { "band_frequency", NULL, MAVLINK_TYPE_FLOAT, 0, 11, offsetof(mavlink_cellular_status_t, band_frequency) }, \
         { "channel_number", NULL, MAVLINK_TYPE_UINT16_T, 0, 15, offsetof(mavlink_cellular_status_t, channel_number) }, \
         { "rx_level", NULL, MAVLINK_TYPE_FLOAT, 0, 17, offsetof(mavlink_cellular_status_t, rx_level) }, \
         { "tx_level", NULL, MAVLINK_TYPE_FLOAT, 0, 21, offsetof(mavlink_cellular_status_t, tx_level) }, \
         { "rx_quality", NULL, MAVLINK_TYPE_FLOAT, 0, 25, offsetof(mavlink_cellular_status_t, rx_quality) }, \
         { "link_tx_rate", NULL, MAVLINK_TYPE_UINT32_T, 0, 29, offsetof(mavlink_cellular_status_t, link_tx_rate) }, \
         { "link_rx_rate", NULL, MAVLINK_TYPE_UINT32_T, 0, 33, offsetof(mavlink_cellular_status_t, link_rx_rate) }, \
         { "ber", NULL, MAVLINK_TYPE_UINT16_T, 0, 37, offsetof(mavlink_cellular_status_t, ber) }, \
         { "id", NULL, MAVLINK_TYPE_UINT8_T, 0, 39, offsetof(mavlink_cellular_status_t, id) }, \
         { "cell_tower_id", NULL, MAVLINK_TYPE_CHAR, 9, 40, offsetof(mavlink_cellular_status_t, cell_tower_id) }, \
         } \
}
#endif

/**
 * @brief Pack a cellular_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param status  Cellular modem status
 * @param failure_reason  Failure reason when status in in CELLULAR_STATUS_FLAG_FAILED
 * @param type  Cellular network radio type: gsm, cdma, lte...
 * @param quality  Signal quality in percent. May be used for Received Signal Strength Indicator (RSSI). If unknown, set to UINT8_MAX
 * @param mcc  Mobile country code. If unknown, set to UINT16_MAX
 * @param mnc  Mobile network code. If unknown, set to UINT16_MAX
 * @param lac  Location area code. If unknown, set to 0
 * @param band_number  (WIP) LTE frequency band number.
 * @param band_frequency [MHz] (WIP) LTE radio frequency.
 * @param channel_number  (WIP) The channel number (CN). Absolute radio-frequency (ARFCN) / E-UTRA (EARFCN) / UTRA (UARFCN) / New radio (NR_CH).
 * @param rx_level [dBm] (WIP) On 3G is Received Signal Code Power (RSCP). On LTE Reference Signal Received Power (RSRP). On 5G  is New Radio Reference Signal Received Power (NR_RSRQ).
 * @param tx_level [dBm] (WIP) Transmitter (modem) signal absolute power level.
 * @param rx_quality [dBm] (WIP) On 3G is Receiver Quality (RxQual). On LTE is Reference Signal Received Quality (RSRQ). On 5G is New radio Reference Signal Received Quality (NR_RSRQ).
 * @param link_tx_rate [KiB/s] (WIP) Download rate.
 * @param link_rx_rate [KiB/s] (WIP) Upload rate.
 * @param ber  (WIP) The bit error rate (BER) is determined by comparing the erroneous bits received with the total number of bits received. It is a ratio.
 * @param id  (WIP) Cellular instance number. Indexed from 1. Matches index in corresponding CELLULAR_MODEM_INFORMATION message.
 * @param cell_tower_id  (WIP) ID of the currently connected cell tower. This must be NULL terminated if the length is less than 9 human-readable chars, and without the null termination (NULL) byte if the length is exactly 9 chars.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cellular_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t status, uint8_t failure_reason, uint8_t type, uint8_t quality, uint16_t mcc, uint16_t mnc, uint16_t lac, uint8_t band_number, float band_frequency, uint16_t channel_number, float rx_level, float tx_level, float rx_quality, uint32_t link_tx_rate, uint32_t link_rx_rate, uint16_t ber, uint8_t id, const char *cell_tower_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CELLULAR_STATUS_LEN];
    _mav_put_uint16_t(buf, 0, mcc);
    _mav_put_uint16_t(buf, 2, mnc);
    _mav_put_uint16_t(buf, 4, lac);
    _mav_put_uint8_t(buf, 6, status);
    _mav_put_uint8_t(buf, 7, failure_reason);
    _mav_put_uint8_t(buf, 8, type);
    _mav_put_uint8_t(buf, 9, quality);
    _mav_put_uint8_t(buf, 10, band_number);
    _mav_put_float(buf, 11, band_frequency);
    _mav_put_uint16_t(buf, 15, channel_number);
    _mav_put_float(buf, 17, rx_level);
    _mav_put_float(buf, 21, tx_level);
    _mav_put_float(buf, 25, rx_quality);
    _mav_put_uint32_t(buf, 29, link_tx_rate);
    _mav_put_uint32_t(buf, 33, link_rx_rate);
    _mav_put_uint16_t(buf, 37, ber);
    _mav_put_uint8_t(buf, 39, id);
    _mav_put_char_array(buf, 40, cell_tower_id, 9);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CELLULAR_STATUS_LEN);
#else
    mavlink_cellular_status_t packet;
    packet.mcc = mcc;
    packet.mnc = mnc;
    packet.lac = lac;
    packet.status = status;
    packet.failure_reason = failure_reason;
    packet.type = type;
    packet.quality = quality;
    packet.band_number = band_number;
    packet.band_frequency = band_frequency;
    packet.channel_number = channel_number;
    packet.rx_level = rx_level;
    packet.tx_level = tx_level;
    packet.rx_quality = rx_quality;
    packet.link_tx_rate = link_tx_rate;
    packet.link_rx_rate = link_rx_rate;
    packet.ber = ber;
    packet.id = id;
    mav_array_memcpy(packet.cell_tower_id, cell_tower_id, sizeof(char)*9);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CELLULAR_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CELLULAR_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CELLULAR_STATUS_MIN_LEN, MAVLINK_MSG_ID_CELLULAR_STATUS_LEN, MAVLINK_MSG_ID_CELLULAR_STATUS_CRC);
}

/**
 * @brief Pack a cellular_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param status  Cellular modem status
 * @param failure_reason  Failure reason when status in in CELLULAR_STATUS_FLAG_FAILED
 * @param type  Cellular network radio type: gsm, cdma, lte...
 * @param quality  Signal quality in percent. May be used for Received Signal Strength Indicator (RSSI). If unknown, set to UINT8_MAX
 * @param mcc  Mobile country code. If unknown, set to UINT16_MAX
 * @param mnc  Mobile network code. If unknown, set to UINT16_MAX
 * @param lac  Location area code. If unknown, set to 0
 * @param band_number  (WIP) LTE frequency band number.
 * @param band_frequency [MHz] (WIP) LTE radio frequency.
 * @param channel_number  (WIP) The channel number (CN). Absolute radio-frequency (ARFCN) / E-UTRA (EARFCN) / UTRA (UARFCN) / New radio (NR_CH).
 * @param rx_level [dBm] (WIP) On 3G is Received Signal Code Power (RSCP). On LTE Reference Signal Received Power (RSRP). On 5G  is New Radio Reference Signal Received Power (NR_RSRQ).
 * @param tx_level [dBm] (WIP) Transmitter (modem) signal absolute power level.
 * @param rx_quality [dBm] (WIP) On 3G is Receiver Quality (RxQual). On LTE is Reference Signal Received Quality (RSRQ). On 5G is New radio Reference Signal Received Quality (NR_RSRQ).
 * @param link_tx_rate [KiB/s] (WIP) Download rate.
 * @param link_rx_rate [KiB/s] (WIP) Upload rate.
 * @param ber  (WIP) The bit error rate (BER) is determined by comparing the erroneous bits received with the total number of bits received. It is a ratio.
 * @param id  (WIP) Cellular instance number. Indexed from 1. Matches index in corresponding CELLULAR_MODEM_INFORMATION message.
 * @param cell_tower_id  (WIP) ID of the currently connected cell tower. This must be NULL terminated if the length is less than 9 human-readable chars, and without the null termination (NULL) byte if the length is exactly 9 chars.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cellular_status_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t status, uint8_t failure_reason, uint8_t type, uint8_t quality, uint16_t mcc, uint16_t mnc, uint16_t lac, uint8_t band_number, float band_frequency, uint16_t channel_number, float rx_level, float tx_level, float rx_quality, uint32_t link_tx_rate, uint32_t link_rx_rate, uint16_t ber, uint8_t id, const char *cell_tower_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CELLULAR_STATUS_LEN];
    _mav_put_uint16_t(buf, 0, mcc);
    _mav_put_uint16_t(buf, 2, mnc);
    _mav_put_uint16_t(buf, 4, lac);
    _mav_put_uint8_t(buf, 6, status);
    _mav_put_uint8_t(buf, 7, failure_reason);
    _mav_put_uint8_t(buf, 8, type);
    _mav_put_uint8_t(buf, 9, quality);
    _mav_put_uint8_t(buf, 10, band_number);
    _mav_put_float(buf, 11, band_frequency);
    _mav_put_uint16_t(buf, 15, channel_number);
    _mav_put_float(buf, 17, rx_level);
    _mav_put_float(buf, 21, tx_level);
    _mav_put_float(buf, 25, rx_quality);
    _mav_put_uint32_t(buf, 29, link_tx_rate);
    _mav_put_uint32_t(buf, 33, link_rx_rate);
    _mav_put_uint16_t(buf, 37, ber);
    _mav_put_uint8_t(buf, 39, id);
    _mav_put_char_array(buf, 40, cell_tower_id, 9);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CELLULAR_STATUS_LEN);
#else
    mavlink_cellular_status_t packet;
    packet.mcc = mcc;
    packet.mnc = mnc;
    packet.lac = lac;
    packet.status = status;
    packet.failure_reason = failure_reason;
    packet.type = type;
    packet.quality = quality;
    packet.band_number = band_number;
    packet.band_frequency = band_frequency;
    packet.channel_number = channel_number;
    packet.rx_level = rx_level;
    packet.tx_level = tx_level;
    packet.rx_quality = rx_quality;
    packet.link_tx_rate = link_tx_rate;
    packet.link_rx_rate = link_rx_rate;
    packet.ber = ber;
    packet.id = id;
    mav_array_memcpy(packet.cell_tower_id, cell_tower_id, sizeof(char)*9);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CELLULAR_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CELLULAR_STATUS;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_CELLULAR_STATUS_MIN_LEN, MAVLINK_MSG_ID_CELLULAR_STATUS_LEN, MAVLINK_MSG_ID_CELLULAR_STATUS_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_CELLULAR_STATUS_MIN_LEN, MAVLINK_MSG_ID_CELLULAR_STATUS_LEN);
#endif
}

/**
 * @brief Pack a cellular_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param status  Cellular modem status
 * @param failure_reason  Failure reason when status in in CELLULAR_STATUS_FLAG_FAILED
 * @param type  Cellular network radio type: gsm, cdma, lte...
 * @param quality  Signal quality in percent. May be used for Received Signal Strength Indicator (RSSI). If unknown, set to UINT8_MAX
 * @param mcc  Mobile country code. If unknown, set to UINT16_MAX
 * @param mnc  Mobile network code. If unknown, set to UINT16_MAX
 * @param lac  Location area code. If unknown, set to 0
 * @param band_number  (WIP) LTE frequency band number.
 * @param band_frequency [MHz] (WIP) LTE radio frequency.
 * @param channel_number  (WIP) The channel number (CN). Absolute radio-frequency (ARFCN) / E-UTRA (EARFCN) / UTRA (UARFCN) / New radio (NR_CH).
 * @param rx_level [dBm] (WIP) On 3G is Received Signal Code Power (RSCP). On LTE Reference Signal Received Power (RSRP). On 5G  is New Radio Reference Signal Received Power (NR_RSRQ).
 * @param tx_level [dBm] (WIP) Transmitter (modem) signal absolute power level.
 * @param rx_quality [dBm] (WIP) On 3G is Receiver Quality (RxQual). On LTE is Reference Signal Received Quality (RSRQ). On 5G is New radio Reference Signal Received Quality (NR_RSRQ).
 * @param link_tx_rate [KiB/s] (WIP) Download rate.
 * @param link_rx_rate [KiB/s] (WIP) Upload rate.
 * @param ber  (WIP) The bit error rate (BER) is determined by comparing the erroneous bits received with the total number of bits received. It is a ratio.
 * @param id  (WIP) Cellular instance number. Indexed from 1. Matches index in corresponding CELLULAR_MODEM_INFORMATION message.
 * @param cell_tower_id  (WIP) ID of the currently connected cell tower. This must be NULL terminated if the length is less than 9 human-readable chars, and without the null termination (NULL) byte if the length is exactly 9 chars.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cellular_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t status,uint8_t failure_reason,uint8_t type,uint8_t quality,uint16_t mcc,uint16_t mnc,uint16_t lac,uint8_t band_number,float band_frequency,uint16_t channel_number,float rx_level,float tx_level,float rx_quality,uint32_t link_tx_rate,uint32_t link_rx_rate,uint16_t ber,uint8_t id,const char *cell_tower_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CELLULAR_STATUS_LEN];
    _mav_put_uint16_t(buf, 0, mcc);
    _mav_put_uint16_t(buf, 2, mnc);
    _mav_put_uint16_t(buf, 4, lac);
    _mav_put_uint8_t(buf, 6, status);
    _mav_put_uint8_t(buf, 7, failure_reason);
    _mav_put_uint8_t(buf, 8, type);
    _mav_put_uint8_t(buf, 9, quality);
    _mav_put_uint8_t(buf, 10, band_number);
    _mav_put_float(buf, 11, band_frequency);
    _mav_put_uint16_t(buf, 15, channel_number);
    _mav_put_float(buf, 17, rx_level);
    _mav_put_float(buf, 21, tx_level);
    _mav_put_float(buf, 25, rx_quality);
    _mav_put_uint32_t(buf, 29, link_tx_rate);
    _mav_put_uint32_t(buf, 33, link_rx_rate);
    _mav_put_uint16_t(buf, 37, ber);
    _mav_put_uint8_t(buf, 39, id);
    _mav_put_char_array(buf, 40, cell_tower_id, 9);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CELLULAR_STATUS_LEN);
#else
    mavlink_cellular_status_t packet;
    packet.mcc = mcc;
    packet.mnc = mnc;
    packet.lac = lac;
    packet.status = status;
    packet.failure_reason = failure_reason;
    packet.type = type;
    packet.quality = quality;
    packet.band_number = band_number;
    packet.band_frequency = band_frequency;
    packet.channel_number = channel_number;
    packet.rx_level = rx_level;
    packet.tx_level = tx_level;
    packet.rx_quality = rx_quality;
    packet.link_tx_rate = link_tx_rate;
    packet.link_rx_rate = link_rx_rate;
    packet.ber = ber;
    packet.id = id;
    mav_array_memcpy(packet.cell_tower_id, cell_tower_id, sizeof(char)*9);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CELLULAR_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CELLULAR_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CELLULAR_STATUS_MIN_LEN, MAVLINK_MSG_ID_CELLULAR_STATUS_LEN, MAVLINK_MSG_ID_CELLULAR_STATUS_CRC);
}

/**
 * @brief Encode a cellular_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param cellular_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cellular_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_cellular_status_t* cellular_status)
{
    return mavlink_msg_cellular_status_pack(system_id, component_id, msg, cellular_status->status, cellular_status->failure_reason, cellular_status->type, cellular_status->quality, cellular_status->mcc, cellular_status->mnc, cellular_status->lac, cellular_status->band_number, cellular_status->band_frequency, cellular_status->channel_number, cellular_status->rx_level, cellular_status->tx_level, cellular_status->rx_quality, cellular_status->link_tx_rate, cellular_status->link_rx_rate, cellular_status->ber, cellular_status->id, cellular_status->cell_tower_id);
}

/**
 * @brief Encode a cellular_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param cellular_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cellular_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_cellular_status_t* cellular_status)
{
    return mavlink_msg_cellular_status_pack_chan(system_id, component_id, chan, msg, cellular_status->status, cellular_status->failure_reason, cellular_status->type, cellular_status->quality, cellular_status->mcc, cellular_status->mnc, cellular_status->lac, cellular_status->band_number, cellular_status->band_frequency, cellular_status->channel_number, cellular_status->rx_level, cellular_status->tx_level, cellular_status->rx_quality, cellular_status->link_tx_rate, cellular_status->link_rx_rate, cellular_status->ber, cellular_status->id, cellular_status->cell_tower_id);
}

/**
 * @brief Encode a cellular_status struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param cellular_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cellular_status_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_cellular_status_t* cellular_status)
{
    return mavlink_msg_cellular_status_pack_status(system_id, component_id, _status, msg,  cellular_status->status, cellular_status->failure_reason, cellular_status->type, cellular_status->quality, cellular_status->mcc, cellular_status->mnc, cellular_status->lac, cellular_status->band_number, cellular_status->band_frequency, cellular_status->channel_number, cellular_status->rx_level, cellular_status->tx_level, cellular_status->rx_quality, cellular_status->link_tx_rate, cellular_status->link_rx_rate, cellular_status->ber, cellular_status->id, cellular_status->cell_tower_id);
}

/**
 * @brief Send a cellular_status message
 * @param chan MAVLink channel to send the message
 *
 * @param status  Cellular modem status
 * @param failure_reason  Failure reason when status in in CELLULAR_STATUS_FLAG_FAILED
 * @param type  Cellular network radio type: gsm, cdma, lte...
 * @param quality  Signal quality in percent. May be used for Received Signal Strength Indicator (RSSI). If unknown, set to UINT8_MAX
 * @param mcc  Mobile country code. If unknown, set to UINT16_MAX
 * @param mnc  Mobile network code. If unknown, set to UINT16_MAX
 * @param lac  Location area code. If unknown, set to 0
 * @param band_number  (WIP) LTE frequency band number.
 * @param band_frequency [MHz] (WIP) LTE radio frequency.
 * @param channel_number  (WIP) The channel number (CN). Absolute radio-frequency (ARFCN) / E-UTRA (EARFCN) / UTRA (UARFCN) / New radio (NR_CH).
 * @param rx_level [dBm] (WIP) On 3G is Received Signal Code Power (RSCP). On LTE Reference Signal Received Power (RSRP). On 5G  is New Radio Reference Signal Received Power (NR_RSRQ).
 * @param tx_level [dBm] (WIP) Transmitter (modem) signal absolute power level.
 * @param rx_quality [dBm] (WIP) On 3G is Receiver Quality (RxQual). On LTE is Reference Signal Received Quality (RSRQ). On 5G is New radio Reference Signal Received Quality (NR_RSRQ).
 * @param link_tx_rate [KiB/s] (WIP) Download rate.
 * @param link_rx_rate [KiB/s] (WIP) Upload rate.
 * @param ber  (WIP) The bit error rate (BER) is determined by comparing the erroneous bits received with the total number of bits received. It is a ratio.
 * @param id  (WIP) Cellular instance number. Indexed from 1. Matches index in corresponding CELLULAR_MODEM_INFORMATION message.
 * @param cell_tower_id  (WIP) ID of the currently connected cell tower. This must be NULL terminated if the length is less than 9 human-readable chars, and without the null termination (NULL) byte if the length is exactly 9 chars.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_cellular_status_send(mavlink_channel_t chan, uint8_t status, uint8_t failure_reason, uint8_t type, uint8_t quality, uint16_t mcc, uint16_t mnc, uint16_t lac, uint8_t band_number, float band_frequency, uint16_t channel_number, float rx_level, float tx_level, float rx_quality, uint32_t link_tx_rate, uint32_t link_rx_rate, uint16_t ber, uint8_t id, const char *cell_tower_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CELLULAR_STATUS_LEN];
    _mav_put_uint16_t(buf, 0, mcc);
    _mav_put_uint16_t(buf, 2, mnc);
    _mav_put_uint16_t(buf, 4, lac);
    _mav_put_uint8_t(buf, 6, status);
    _mav_put_uint8_t(buf, 7, failure_reason);
    _mav_put_uint8_t(buf, 8, type);
    _mav_put_uint8_t(buf, 9, quality);
    _mav_put_uint8_t(buf, 10, band_number);
    _mav_put_float(buf, 11, band_frequency);
    _mav_put_uint16_t(buf, 15, channel_number);
    _mav_put_float(buf, 17, rx_level);
    _mav_put_float(buf, 21, tx_level);
    _mav_put_float(buf, 25, rx_quality);
    _mav_put_uint32_t(buf, 29, link_tx_rate);
    _mav_put_uint32_t(buf, 33, link_rx_rate);
    _mav_put_uint16_t(buf, 37, ber);
    _mav_put_uint8_t(buf, 39, id);
    _mav_put_char_array(buf, 40, cell_tower_id, 9);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CELLULAR_STATUS, buf, MAVLINK_MSG_ID_CELLULAR_STATUS_MIN_LEN, MAVLINK_MSG_ID_CELLULAR_STATUS_LEN, MAVLINK_MSG_ID_CELLULAR_STATUS_CRC);
#else
    mavlink_cellular_status_t packet;
    packet.mcc = mcc;
    packet.mnc = mnc;
    packet.lac = lac;
    packet.status = status;
    packet.failure_reason = failure_reason;
    packet.type = type;
    packet.quality = quality;
    packet.band_number = band_number;
    packet.band_frequency = band_frequency;
    packet.channel_number = channel_number;
    packet.rx_level = rx_level;
    packet.tx_level = tx_level;
    packet.rx_quality = rx_quality;
    packet.link_tx_rate = link_tx_rate;
    packet.link_rx_rate = link_rx_rate;
    packet.ber = ber;
    packet.id = id;
    mav_array_memcpy(packet.cell_tower_id, cell_tower_id, sizeof(char)*9);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CELLULAR_STATUS, (const char *)&packet, MAVLINK_MSG_ID_CELLULAR_STATUS_MIN_LEN, MAVLINK_MSG_ID_CELLULAR_STATUS_LEN, MAVLINK_MSG_ID_CELLULAR_STATUS_CRC);
#endif
}

/**
 * @brief Send a cellular_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_cellular_status_send_struct(mavlink_channel_t chan, const mavlink_cellular_status_t* cellular_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_cellular_status_send(chan, cellular_status->status, cellular_status->failure_reason, cellular_status->type, cellular_status->quality, cellular_status->mcc, cellular_status->mnc, cellular_status->lac, cellular_status->band_number, cellular_status->band_frequency, cellular_status->channel_number, cellular_status->rx_level, cellular_status->tx_level, cellular_status->rx_quality, cellular_status->link_tx_rate, cellular_status->link_rx_rate, cellular_status->ber, cellular_status->id, cellular_status->cell_tower_id);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CELLULAR_STATUS, (const char *)cellular_status, MAVLINK_MSG_ID_CELLULAR_STATUS_MIN_LEN, MAVLINK_MSG_ID_CELLULAR_STATUS_LEN, MAVLINK_MSG_ID_CELLULAR_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_CELLULAR_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_cellular_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t status, uint8_t failure_reason, uint8_t type, uint8_t quality, uint16_t mcc, uint16_t mnc, uint16_t lac, uint8_t band_number, float band_frequency, uint16_t channel_number, float rx_level, float tx_level, float rx_quality, uint32_t link_tx_rate, uint32_t link_rx_rate, uint16_t ber, uint8_t id, const char *cell_tower_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, mcc);
    _mav_put_uint16_t(buf, 2, mnc);
    _mav_put_uint16_t(buf, 4, lac);
    _mav_put_uint8_t(buf, 6, status);
    _mav_put_uint8_t(buf, 7, failure_reason);
    _mav_put_uint8_t(buf, 8, type);
    _mav_put_uint8_t(buf, 9, quality);
    _mav_put_uint8_t(buf, 10, band_number);
    _mav_put_float(buf, 11, band_frequency);
    _mav_put_uint16_t(buf, 15, channel_number);
    _mav_put_float(buf, 17, rx_level);
    _mav_put_float(buf, 21, tx_level);
    _mav_put_float(buf, 25, rx_quality);
    _mav_put_uint32_t(buf, 29, link_tx_rate);
    _mav_put_uint32_t(buf, 33, link_rx_rate);
    _mav_put_uint16_t(buf, 37, ber);
    _mav_put_uint8_t(buf, 39, id);
    _mav_put_char_array(buf, 40, cell_tower_id, 9);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CELLULAR_STATUS, buf, MAVLINK_MSG_ID_CELLULAR_STATUS_MIN_LEN, MAVLINK_MSG_ID_CELLULAR_STATUS_LEN, MAVLINK_MSG_ID_CELLULAR_STATUS_CRC);
#else
    mavlink_cellular_status_t *packet = (mavlink_cellular_status_t *)msgbuf;
    packet->mcc = mcc;
    packet->mnc = mnc;
    packet->lac = lac;
    packet->status = status;
    packet->failure_reason = failure_reason;
    packet->type = type;
    packet->quality = quality;
    packet->band_number = band_number;
    packet->band_frequency = band_frequency;
    packet->channel_number = channel_number;
    packet->rx_level = rx_level;
    packet->tx_level = tx_level;
    packet->rx_quality = rx_quality;
    packet->link_tx_rate = link_tx_rate;
    packet->link_rx_rate = link_rx_rate;
    packet->ber = ber;
    packet->id = id;
    mav_array_memcpy(packet->cell_tower_id, cell_tower_id, sizeof(char)*9);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CELLULAR_STATUS, (const char *)packet, MAVLINK_MSG_ID_CELLULAR_STATUS_MIN_LEN, MAVLINK_MSG_ID_CELLULAR_STATUS_LEN, MAVLINK_MSG_ID_CELLULAR_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE CELLULAR_STATUS UNPACKING


/**
 * @brief Get field status from cellular_status message
 *
 * @return  Cellular modem status
 */
static inline uint8_t mavlink_msg_cellular_status_get_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field failure_reason from cellular_status message
 *
 * @return  Failure reason when status in in CELLULAR_STATUS_FLAG_FAILED
 */
static inline uint8_t mavlink_msg_cellular_status_get_failure_reason(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  7);
}

/**
 * @brief Get field type from cellular_status message
 *
 * @return  Cellular network radio type: gsm, cdma, lte...
 */
static inline uint8_t mavlink_msg_cellular_status_get_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field quality from cellular_status message
 *
 * @return  Signal quality in percent. May be used for Received Signal Strength Indicator (RSSI). If unknown, set to UINT8_MAX
 */
static inline uint8_t mavlink_msg_cellular_status_get_quality(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field mcc from cellular_status message
 *
 * @return  Mobile country code. If unknown, set to UINT16_MAX
 */
static inline uint16_t mavlink_msg_cellular_status_get_mcc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field mnc from cellular_status message
 *
 * @return  Mobile network code. If unknown, set to UINT16_MAX
 */
static inline uint16_t mavlink_msg_cellular_status_get_mnc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  2);
}

/**
 * @brief Get field lac from cellular_status message
 *
 * @return  Location area code. If unknown, set to 0
 */
static inline uint16_t mavlink_msg_cellular_status_get_lac(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field band_number from cellular_status message
 *
 * @return  (WIP) LTE frequency band number.
 */
static inline uint8_t mavlink_msg_cellular_status_get_band_number(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  10);
}

/**
 * @brief Get field band_frequency from cellular_status message
 *
 * @return [MHz] (WIP) LTE radio frequency.
 */
static inline float mavlink_msg_cellular_status_get_band_frequency(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  11);
}

/**
 * @brief Get field channel_number from cellular_status message
 *
 * @return  (WIP) The channel number (CN). Absolute radio-frequency (ARFCN) / E-UTRA (EARFCN) / UTRA (UARFCN) / New radio (NR_CH).
 */
static inline uint16_t mavlink_msg_cellular_status_get_channel_number(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  15);
}

/**
 * @brief Get field rx_level from cellular_status message
 *
 * @return [dBm] (WIP) On 3G is Received Signal Code Power (RSCP). On LTE Reference Signal Received Power (RSRP). On 5G  is New Radio Reference Signal Received Power (NR_RSRQ).
 */
static inline float mavlink_msg_cellular_status_get_rx_level(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  17);
}

/**
 * @brief Get field tx_level from cellular_status message
 *
 * @return [dBm] (WIP) Transmitter (modem) signal absolute power level.
 */
static inline float mavlink_msg_cellular_status_get_tx_level(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  21);
}

/**
 * @brief Get field rx_quality from cellular_status message
 *
 * @return [dBm] (WIP) On 3G is Receiver Quality (RxQual). On LTE is Reference Signal Received Quality (RSRQ). On 5G is New radio Reference Signal Received Quality (NR_RSRQ).
 */
static inline float mavlink_msg_cellular_status_get_rx_quality(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  25);
}

/**
 * @brief Get field link_tx_rate from cellular_status message
 *
 * @return [KiB/s] (WIP) Download rate.
 */
static inline uint32_t mavlink_msg_cellular_status_get_link_tx_rate(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  29);
}

/**
 * @brief Get field link_rx_rate from cellular_status message
 *
 * @return [KiB/s] (WIP) Upload rate.
 */
static inline uint32_t mavlink_msg_cellular_status_get_link_rx_rate(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  33);
}

/**
 * @brief Get field ber from cellular_status message
 *
 * @return  (WIP) The bit error rate (BER) is determined by comparing the erroneous bits received with the total number of bits received. It is a ratio.
 */
static inline uint16_t mavlink_msg_cellular_status_get_ber(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  37);
}

/**
 * @brief Get field id from cellular_status message
 *
 * @return  (WIP) Cellular instance number. Indexed from 1. Matches index in corresponding CELLULAR_MODEM_INFORMATION message.
 */
static inline uint8_t mavlink_msg_cellular_status_get_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  39);
}

/**
 * @brief Get field cell_tower_id from cellular_status message
 *
 * @return  (WIP) ID of the currently connected cell tower. This must be NULL terminated if the length is less than 9 human-readable chars, and without the null termination (NULL) byte if the length is exactly 9 chars.
 */
static inline uint16_t mavlink_msg_cellular_status_get_cell_tower_id(const mavlink_message_t* msg, char *cell_tower_id)
{
    return _MAV_RETURN_char_array(msg, cell_tower_id, 9,  40);
}

/**
 * @brief Decode a cellular_status message into a struct
 *
 * @param msg The message to decode
 * @param cellular_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_cellular_status_decode(const mavlink_message_t* msg, mavlink_cellular_status_t* cellular_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    cellular_status->mcc = mavlink_msg_cellular_status_get_mcc(msg);
    cellular_status->mnc = mavlink_msg_cellular_status_get_mnc(msg);
    cellular_status->lac = mavlink_msg_cellular_status_get_lac(msg);
    cellular_status->status = mavlink_msg_cellular_status_get_status(msg);
    cellular_status->failure_reason = mavlink_msg_cellular_status_get_failure_reason(msg);
    cellular_status->type = mavlink_msg_cellular_status_get_type(msg);
    cellular_status->quality = mavlink_msg_cellular_status_get_quality(msg);
    cellular_status->band_number = mavlink_msg_cellular_status_get_band_number(msg);
    cellular_status->band_frequency = mavlink_msg_cellular_status_get_band_frequency(msg);
    cellular_status->channel_number = mavlink_msg_cellular_status_get_channel_number(msg);
    cellular_status->rx_level = mavlink_msg_cellular_status_get_rx_level(msg);
    cellular_status->tx_level = mavlink_msg_cellular_status_get_tx_level(msg);
    cellular_status->rx_quality = mavlink_msg_cellular_status_get_rx_quality(msg);
    cellular_status->link_tx_rate = mavlink_msg_cellular_status_get_link_tx_rate(msg);
    cellular_status->link_rx_rate = mavlink_msg_cellular_status_get_link_rx_rate(msg);
    cellular_status->ber = mavlink_msg_cellular_status_get_ber(msg);
    cellular_status->id = mavlink_msg_cellular_status_get_id(msg);
    mavlink_msg_cellular_status_get_cell_tower_id(msg, cellular_status->cell_tower_id);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CELLULAR_STATUS_LEN? msg->len : MAVLINK_MSG_ID_CELLULAR_STATUS_LEN;
        memset(cellular_status, 0, MAVLINK_MSG_ID_CELLULAR_STATUS_LEN);
    memcpy(cellular_status, _MAV_PAYLOAD(msg), len);
#endif
}
