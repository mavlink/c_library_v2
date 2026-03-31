#pragma once
// MESSAGE RANGING_BEACON PACKING

#define MAVLINK_MSG_ID_RANGING_BEACON 513


typedef struct __mavlink_ranging_beacon_t {
 uint64_t time_usec; /*< [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.*/
 uint32_t range; /*< [mm] Range measurement between a beacon and a vehicle.*/
 int32_t lat; /*< [degE7] Beacon latitude (WGS84).*/
 int32_t lon; /*< [degE7] Beacon longitude (WGS84).*/
 float alt; /*< [m] Beacon altitude (frame defined in alt_type).*/
 uint32_t hacc_est; /*< [mm] Beacon 1-sigma horizontal accuracy estimate.*/
 uint32_t vacc_est; /*< [mm] Beacon 1-sigma vertical accuracy estimate.*/
 uint32_t range_accuracy; /*< [mm] Estimated 1-sigma range measurement accuracy.*/
 uint16_t beacon_id; /*<  ID of the ranging beacon/station.*/
 uint16_t carrier_freq; /*< [MHz] Ranging carrier frequency*/
 uint8_t target_system; /*<  System ID.*/
 uint8_t target_component; /*<  Component ID.*/
 uint8_t alt_type; /*<  Altitude frame for alt field. RANGING_BEACON_ALT_TYPE_WGS84 (0) preferred.*/
 uint8_t sequence; /*<  Measurement sequence number.*/
 uint8_t status; /*<  Ranging beacon status.*/
} mavlink_ranging_beacon_t;

#define MAVLINK_MSG_ID_RANGING_BEACON_LEN 45
#define MAVLINK_MSG_ID_RANGING_BEACON_MIN_LEN 45
#define MAVLINK_MSG_ID_513_LEN 45
#define MAVLINK_MSG_ID_513_MIN_LEN 45

#define MAVLINK_MSG_ID_RANGING_BEACON_CRC 99
#define MAVLINK_MSG_ID_513_CRC 99



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RANGING_BEACON { \
    513, \
    "RANGING_BEACON", \
    15, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_ranging_beacon_t, time_usec) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 40, offsetof(mavlink_ranging_beacon_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 41, offsetof(mavlink_ranging_beacon_t, target_component) }, \
         { "beacon_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 36, offsetof(mavlink_ranging_beacon_t, beacon_id) }, \
         { "range", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_ranging_beacon_t, range) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_ranging_beacon_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_ranging_beacon_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_ranging_beacon_t, alt) }, \
         { "alt_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 42, offsetof(mavlink_ranging_beacon_t, alt_type) }, \
         { "hacc_est", NULL, MAVLINK_TYPE_UINT32_T, 0, 24, offsetof(mavlink_ranging_beacon_t, hacc_est) }, \
         { "vacc_est", NULL, MAVLINK_TYPE_UINT32_T, 0, 28, offsetof(mavlink_ranging_beacon_t, vacc_est) }, \
         { "carrier_freq", NULL, MAVLINK_TYPE_UINT16_T, 0, 38, offsetof(mavlink_ranging_beacon_t, carrier_freq) }, \
         { "range_accuracy", NULL, MAVLINK_TYPE_UINT32_T, 0, 32, offsetof(mavlink_ranging_beacon_t, range_accuracy) }, \
         { "sequence", NULL, MAVLINK_TYPE_UINT8_T, 0, 43, offsetof(mavlink_ranging_beacon_t, sequence) }, \
         { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 44, offsetof(mavlink_ranging_beacon_t, status) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_RANGING_BEACON { \
    "RANGING_BEACON", \
    15, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_ranging_beacon_t, time_usec) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 40, offsetof(mavlink_ranging_beacon_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 41, offsetof(mavlink_ranging_beacon_t, target_component) }, \
         { "beacon_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 36, offsetof(mavlink_ranging_beacon_t, beacon_id) }, \
         { "range", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_ranging_beacon_t, range) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_ranging_beacon_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_ranging_beacon_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_ranging_beacon_t, alt) }, \
         { "alt_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 42, offsetof(mavlink_ranging_beacon_t, alt_type) }, \
         { "hacc_est", NULL, MAVLINK_TYPE_UINT32_T, 0, 24, offsetof(mavlink_ranging_beacon_t, hacc_est) }, \
         { "vacc_est", NULL, MAVLINK_TYPE_UINT32_T, 0, 28, offsetof(mavlink_ranging_beacon_t, vacc_est) }, \
         { "carrier_freq", NULL, MAVLINK_TYPE_UINT16_T, 0, 38, offsetof(mavlink_ranging_beacon_t, carrier_freq) }, \
         { "range_accuracy", NULL, MAVLINK_TYPE_UINT32_T, 0, 32, offsetof(mavlink_ranging_beacon_t, range_accuracy) }, \
         { "sequence", NULL, MAVLINK_TYPE_UINT8_T, 0, 43, offsetof(mavlink_ranging_beacon_t, sequence) }, \
         { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 44, offsetof(mavlink_ranging_beacon_t, status) }, \
         } \
}
#endif

/**
 * @brief Pack a ranging_beacon message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param target_system  System ID.
 * @param target_component  Component ID.
 * @param beacon_id  ID of the ranging beacon/station.
 * @param range [mm] Range measurement between a beacon and a vehicle.
 * @param lat [degE7] Beacon latitude (WGS84).
 * @param lon [degE7] Beacon longitude (WGS84).
 * @param alt [m] Beacon altitude (frame defined in alt_type).
 * @param alt_type  Altitude frame for alt field. RANGING_BEACON_ALT_TYPE_WGS84 (0) preferred.
 * @param hacc_est [mm] Beacon 1-sigma horizontal accuracy estimate.
 * @param vacc_est [mm] Beacon 1-sigma vertical accuracy estimate.
 * @param carrier_freq [MHz] Ranging carrier frequency
 * @param range_accuracy [mm] Estimated 1-sigma range measurement accuracy.
 * @param sequence  Measurement sequence number.
 * @param status  Ranging beacon status.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_ranging_beacon_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, uint8_t target_system, uint8_t target_component, uint16_t beacon_id, uint32_t range, int32_t lat, int32_t lon, float alt, uint8_t alt_type, uint32_t hacc_est, uint32_t vacc_est, uint16_t carrier_freq, uint32_t range_accuracy, uint8_t sequence, uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RANGING_BEACON_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint32_t(buf, 8, range);
    _mav_put_int32_t(buf, 12, lat);
    _mav_put_int32_t(buf, 16, lon);
    _mav_put_float(buf, 20, alt);
    _mav_put_uint32_t(buf, 24, hacc_est);
    _mav_put_uint32_t(buf, 28, vacc_est);
    _mav_put_uint32_t(buf, 32, range_accuracy);
    _mav_put_uint16_t(buf, 36, beacon_id);
    _mav_put_uint16_t(buf, 38, carrier_freq);
    _mav_put_uint8_t(buf, 40, target_system);
    _mav_put_uint8_t(buf, 41, target_component);
    _mav_put_uint8_t(buf, 42, alt_type);
    _mav_put_uint8_t(buf, 43, sequence);
    _mav_put_uint8_t(buf, 44, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RANGING_BEACON_LEN);
#else
    mavlink_ranging_beacon_t packet;
    packet.time_usec = time_usec;
    packet.range = range;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.hacc_est = hacc_est;
    packet.vacc_est = vacc_est;
    packet.range_accuracy = range_accuracy;
    packet.beacon_id = beacon_id;
    packet.carrier_freq = carrier_freq;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.alt_type = alt_type;
    packet.sequence = sequence;
    packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RANGING_BEACON_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RANGING_BEACON;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RANGING_BEACON_MIN_LEN, MAVLINK_MSG_ID_RANGING_BEACON_LEN, MAVLINK_MSG_ID_RANGING_BEACON_CRC);
}

/**
 * @brief Pack a ranging_beacon message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param target_system  System ID.
 * @param target_component  Component ID.
 * @param beacon_id  ID of the ranging beacon/station.
 * @param range [mm] Range measurement between a beacon and a vehicle.
 * @param lat [degE7] Beacon latitude (WGS84).
 * @param lon [degE7] Beacon longitude (WGS84).
 * @param alt [m] Beacon altitude (frame defined in alt_type).
 * @param alt_type  Altitude frame for alt field. RANGING_BEACON_ALT_TYPE_WGS84 (0) preferred.
 * @param hacc_est [mm] Beacon 1-sigma horizontal accuracy estimate.
 * @param vacc_est [mm] Beacon 1-sigma vertical accuracy estimate.
 * @param carrier_freq [MHz] Ranging carrier frequency
 * @param range_accuracy [mm] Estimated 1-sigma range measurement accuracy.
 * @param sequence  Measurement sequence number.
 * @param status  Ranging beacon status.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ranging_beacon_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint64_t time_usec, uint8_t target_system, uint8_t target_component, uint16_t beacon_id, uint32_t range, int32_t lat, int32_t lon, float alt, uint8_t alt_type, uint32_t hacc_est, uint32_t vacc_est, uint16_t carrier_freq, uint32_t range_accuracy, uint8_t sequence, uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RANGING_BEACON_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint32_t(buf, 8, range);
    _mav_put_int32_t(buf, 12, lat);
    _mav_put_int32_t(buf, 16, lon);
    _mav_put_float(buf, 20, alt);
    _mav_put_uint32_t(buf, 24, hacc_est);
    _mav_put_uint32_t(buf, 28, vacc_est);
    _mav_put_uint32_t(buf, 32, range_accuracy);
    _mav_put_uint16_t(buf, 36, beacon_id);
    _mav_put_uint16_t(buf, 38, carrier_freq);
    _mav_put_uint8_t(buf, 40, target_system);
    _mav_put_uint8_t(buf, 41, target_component);
    _mav_put_uint8_t(buf, 42, alt_type);
    _mav_put_uint8_t(buf, 43, sequence);
    _mav_put_uint8_t(buf, 44, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RANGING_BEACON_LEN);
#else
    mavlink_ranging_beacon_t packet;
    packet.time_usec = time_usec;
    packet.range = range;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.hacc_est = hacc_est;
    packet.vacc_est = vacc_est;
    packet.range_accuracy = range_accuracy;
    packet.beacon_id = beacon_id;
    packet.carrier_freq = carrier_freq;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.alt_type = alt_type;
    packet.sequence = sequence;
    packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RANGING_BEACON_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RANGING_BEACON;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_RANGING_BEACON_MIN_LEN, MAVLINK_MSG_ID_RANGING_BEACON_LEN, MAVLINK_MSG_ID_RANGING_BEACON_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_RANGING_BEACON_MIN_LEN, MAVLINK_MSG_ID_RANGING_BEACON_LEN);
#endif
}

/**
 * @brief Pack a ranging_beacon message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param target_system  System ID.
 * @param target_component  Component ID.
 * @param beacon_id  ID of the ranging beacon/station.
 * @param range [mm] Range measurement between a beacon and a vehicle.
 * @param lat [degE7] Beacon latitude (WGS84).
 * @param lon [degE7] Beacon longitude (WGS84).
 * @param alt [m] Beacon altitude (frame defined in alt_type).
 * @param alt_type  Altitude frame for alt field. RANGING_BEACON_ALT_TYPE_WGS84 (0) preferred.
 * @param hacc_est [mm] Beacon 1-sigma horizontal accuracy estimate.
 * @param vacc_est [mm] Beacon 1-sigma vertical accuracy estimate.
 * @param carrier_freq [MHz] Ranging carrier frequency
 * @param range_accuracy [mm] Estimated 1-sigma range measurement accuracy.
 * @param sequence  Measurement sequence number.
 * @param status  Ranging beacon status.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_ranging_beacon_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,uint8_t target_system,uint8_t target_component,uint16_t beacon_id,uint32_t range,int32_t lat,int32_t lon,float alt,uint8_t alt_type,uint32_t hacc_est,uint32_t vacc_est,uint16_t carrier_freq,uint32_t range_accuracy,uint8_t sequence,uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RANGING_BEACON_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint32_t(buf, 8, range);
    _mav_put_int32_t(buf, 12, lat);
    _mav_put_int32_t(buf, 16, lon);
    _mav_put_float(buf, 20, alt);
    _mav_put_uint32_t(buf, 24, hacc_est);
    _mav_put_uint32_t(buf, 28, vacc_est);
    _mav_put_uint32_t(buf, 32, range_accuracy);
    _mav_put_uint16_t(buf, 36, beacon_id);
    _mav_put_uint16_t(buf, 38, carrier_freq);
    _mav_put_uint8_t(buf, 40, target_system);
    _mav_put_uint8_t(buf, 41, target_component);
    _mav_put_uint8_t(buf, 42, alt_type);
    _mav_put_uint8_t(buf, 43, sequence);
    _mav_put_uint8_t(buf, 44, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RANGING_BEACON_LEN);
#else
    mavlink_ranging_beacon_t packet;
    packet.time_usec = time_usec;
    packet.range = range;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.hacc_est = hacc_est;
    packet.vacc_est = vacc_est;
    packet.range_accuracy = range_accuracy;
    packet.beacon_id = beacon_id;
    packet.carrier_freq = carrier_freq;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.alt_type = alt_type;
    packet.sequence = sequence;
    packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RANGING_BEACON_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RANGING_BEACON;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RANGING_BEACON_MIN_LEN, MAVLINK_MSG_ID_RANGING_BEACON_LEN, MAVLINK_MSG_ID_RANGING_BEACON_CRC);
}

/**
 * @brief Encode a ranging_beacon struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ranging_beacon C-struct to read the message contents from
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_ranging_beacon_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ranging_beacon_t* ranging_beacon)
{
    return mavlink_msg_ranging_beacon_pack(system_id, component_id, msg, ranging_beacon->time_usec, ranging_beacon->target_system, ranging_beacon->target_component, ranging_beacon->beacon_id, ranging_beacon->range, ranging_beacon->lat, ranging_beacon->lon, ranging_beacon->alt, ranging_beacon->alt_type, ranging_beacon->hacc_est, ranging_beacon->vacc_est, ranging_beacon->carrier_freq, ranging_beacon->range_accuracy, ranging_beacon->sequence, ranging_beacon->status);
}

/**
 * @brief Encode a ranging_beacon struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ranging_beacon C-struct to read the message contents from
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_ranging_beacon_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ranging_beacon_t* ranging_beacon)
{
    return mavlink_msg_ranging_beacon_pack_chan(system_id, component_id, chan, msg, ranging_beacon->time_usec, ranging_beacon->target_system, ranging_beacon->target_component, ranging_beacon->beacon_id, ranging_beacon->range, ranging_beacon->lat, ranging_beacon->lon, ranging_beacon->alt, ranging_beacon->alt_type, ranging_beacon->hacc_est, ranging_beacon->vacc_est, ranging_beacon->carrier_freq, ranging_beacon->range_accuracy, ranging_beacon->sequence, ranging_beacon->status);
}

/**
 * @brief Encode a ranging_beacon struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param ranging_beacon C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ranging_beacon_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_ranging_beacon_t* ranging_beacon)
{
    return mavlink_msg_ranging_beacon_pack_status(system_id, component_id, _status, msg,  ranging_beacon->time_usec, ranging_beacon->target_system, ranging_beacon->target_component, ranging_beacon->beacon_id, ranging_beacon->range, ranging_beacon->lat, ranging_beacon->lon, ranging_beacon->alt, ranging_beacon->alt_type, ranging_beacon->hacc_est, ranging_beacon->vacc_est, ranging_beacon->carrier_freq, ranging_beacon->range_accuracy, ranging_beacon->sequence, ranging_beacon->status);
}

/**
 * @brief Send a ranging_beacon message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param target_system  System ID.
 * @param target_component  Component ID.
 * @param beacon_id  ID of the ranging beacon/station.
 * @param range [mm] Range measurement between a beacon and a vehicle.
 * @param lat [degE7] Beacon latitude (WGS84).
 * @param lon [degE7] Beacon longitude (WGS84).
 * @param alt [m] Beacon altitude (frame defined in alt_type).
 * @param alt_type  Altitude frame for alt field. RANGING_BEACON_ALT_TYPE_WGS84 (0) preferred.
 * @param hacc_est [mm] Beacon 1-sigma horizontal accuracy estimate.
 * @param vacc_est [mm] Beacon 1-sigma vertical accuracy estimate.
 * @param carrier_freq [MHz] Ranging carrier frequency
 * @param range_accuracy [mm] Estimated 1-sigma range measurement accuracy.
 * @param sequence  Measurement sequence number.
 * @param status  Ranging beacon status.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

MAVLINK_WIP
static inline void mavlink_msg_ranging_beacon_send(mavlink_channel_t chan, uint64_t time_usec, uint8_t target_system, uint8_t target_component, uint16_t beacon_id, uint32_t range, int32_t lat, int32_t lon, float alt, uint8_t alt_type, uint32_t hacc_est, uint32_t vacc_est, uint16_t carrier_freq, uint32_t range_accuracy, uint8_t sequence, uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RANGING_BEACON_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint32_t(buf, 8, range);
    _mav_put_int32_t(buf, 12, lat);
    _mav_put_int32_t(buf, 16, lon);
    _mav_put_float(buf, 20, alt);
    _mav_put_uint32_t(buf, 24, hacc_est);
    _mav_put_uint32_t(buf, 28, vacc_est);
    _mav_put_uint32_t(buf, 32, range_accuracy);
    _mav_put_uint16_t(buf, 36, beacon_id);
    _mav_put_uint16_t(buf, 38, carrier_freq);
    _mav_put_uint8_t(buf, 40, target_system);
    _mav_put_uint8_t(buf, 41, target_component);
    _mav_put_uint8_t(buf, 42, alt_type);
    _mav_put_uint8_t(buf, 43, sequence);
    _mav_put_uint8_t(buf, 44, status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RANGING_BEACON, buf, MAVLINK_MSG_ID_RANGING_BEACON_MIN_LEN, MAVLINK_MSG_ID_RANGING_BEACON_LEN, MAVLINK_MSG_ID_RANGING_BEACON_CRC);
#else
    mavlink_ranging_beacon_t packet;
    packet.time_usec = time_usec;
    packet.range = range;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.hacc_est = hacc_est;
    packet.vacc_est = vacc_est;
    packet.range_accuracy = range_accuracy;
    packet.beacon_id = beacon_id;
    packet.carrier_freq = carrier_freq;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.alt_type = alt_type;
    packet.sequence = sequence;
    packet.status = status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RANGING_BEACON, (const char *)&packet, MAVLINK_MSG_ID_RANGING_BEACON_MIN_LEN, MAVLINK_MSG_ID_RANGING_BEACON_LEN, MAVLINK_MSG_ID_RANGING_BEACON_CRC);
#endif
}

/**
 * @brief Send a ranging_beacon message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
MAVLINK_WIP
static inline void mavlink_msg_ranging_beacon_send_struct(mavlink_channel_t chan, const mavlink_ranging_beacon_t* ranging_beacon)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_ranging_beacon_send(chan, ranging_beacon->time_usec, ranging_beacon->target_system, ranging_beacon->target_component, ranging_beacon->beacon_id, ranging_beacon->range, ranging_beacon->lat, ranging_beacon->lon, ranging_beacon->alt, ranging_beacon->alt_type, ranging_beacon->hacc_est, ranging_beacon->vacc_est, ranging_beacon->carrier_freq, ranging_beacon->range_accuracy, ranging_beacon->sequence, ranging_beacon->status);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RANGING_BEACON, (const char *)ranging_beacon, MAVLINK_MSG_ID_RANGING_BEACON_MIN_LEN, MAVLINK_MSG_ID_RANGING_BEACON_LEN, MAVLINK_MSG_ID_RANGING_BEACON_CRC);
#endif
}

#if MAVLINK_MSG_ID_RANGING_BEACON_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
MAVLINK_WIP
static inline void mavlink_msg_ranging_beacon_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, uint8_t target_system, uint8_t target_component, uint16_t beacon_id, uint32_t range, int32_t lat, int32_t lon, float alt, uint8_t alt_type, uint32_t hacc_est, uint32_t vacc_est, uint16_t carrier_freq, uint32_t range_accuracy, uint8_t sequence, uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint32_t(buf, 8, range);
    _mav_put_int32_t(buf, 12, lat);
    _mav_put_int32_t(buf, 16, lon);
    _mav_put_float(buf, 20, alt);
    _mav_put_uint32_t(buf, 24, hacc_est);
    _mav_put_uint32_t(buf, 28, vacc_est);
    _mav_put_uint32_t(buf, 32, range_accuracy);
    _mav_put_uint16_t(buf, 36, beacon_id);
    _mav_put_uint16_t(buf, 38, carrier_freq);
    _mav_put_uint8_t(buf, 40, target_system);
    _mav_put_uint8_t(buf, 41, target_component);
    _mav_put_uint8_t(buf, 42, alt_type);
    _mav_put_uint8_t(buf, 43, sequence);
    _mav_put_uint8_t(buf, 44, status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RANGING_BEACON, buf, MAVLINK_MSG_ID_RANGING_BEACON_MIN_LEN, MAVLINK_MSG_ID_RANGING_BEACON_LEN, MAVLINK_MSG_ID_RANGING_BEACON_CRC);
#else
    mavlink_ranging_beacon_t *packet = (mavlink_ranging_beacon_t *)msgbuf;
    packet->time_usec = time_usec;
    packet->range = range;
    packet->lat = lat;
    packet->lon = lon;
    packet->alt = alt;
    packet->hacc_est = hacc_est;
    packet->vacc_est = vacc_est;
    packet->range_accuracy = range_accuracy;
    packet->beacon_id = beacon_id;
    packet->carrier_freq = carrier_freq;
    packet->target_system = target_system;
    packet->target_component = target_component;
    packet->alt_type = alt_type;
    packet->sequence = sequence;
    packet->status = status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RANGING_BEACON, (const char *)packet, MAVLINK_MSG_ID_RANGING_BEACON_MIN_LEN, MAVLINK_MSG_ID_RANGING_BEACON_LEN, MAVLINK_MSG_ID_RANGING_BEACON_CRC);
#endif
}
#endif

#endif

// MESSAGE RANGING_BEACON UNPACKING


/**
 * @brief Get field time_usec from ranging_beacon message
 *
 * @return [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 */
MAVLINK_WIP
static inline uint64_t mavlink_msg_ranging_beacon_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field target_system from ranging_beacon message
 *
 * @return  System ID.
 */
MAVLINK_WIP
static inline uint8_t mavlink_msg_ranging_beacon_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  40);
}

/**
 * @brief Get field target_component from ranging_beacon message
 *
 * @return  Component ID.
 */
MAVLINK_WIP
static inline uint8_t mavlink_msg_ranging_beacon_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  41);
}

/**
 * @brief Get field beacon_id from ranging_beacon message
 *
 * @return  ID of the ranging beacon/station.
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_ranging_beacon_get_beacon_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  36);
}

/**
 * @brief Get field range from ranging_beacon message
 *
 * @return [mm] Range measurement between a beacon and a vehicle.
 */
MAVLINK_WIP
static inline uint32_t mavlink_msg_ranging_beacon_get_range(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field lat from ranging_beacon message
 *
 * @return [degE7] Beacon latitude (WGS84).
 */
MAVLINK_WIP
static inline int32_t mavlink_msg_ranging_beacon_get_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field lon from ranging_beacon message
 *
 * @return [degE7] Beacon longitude (WGS84).
 */
MAVLINK_WIP
static inline int32_t mavlink_msg_ranging_beacon_get_lon(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field alt from ranging_beacon message
 *
 * @return [m] Beacon altitude (frame defined in alt_type).
 */
MAVLINK_WIP
static inline float mavlink_msg_ranging_beacon_get_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field alt_type from ranging_beacon message
 *
 * @return  Altitude frame for alt field. RANGING_BEACON_ALT_TYPE_WGS84 (0) preferred.
 */
MAVLINK_WIP
static inline uint8_t mavlink_msg_ranging_beacon_get_alt_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  42);
}

/**
 * @brief Get field hacc_est from ranging_beacon message
 *
 * @return [mm] Beacon 1-sigma horizontal accuracy estimate.
 */
MAVLINK_WIP
static inline uint32_t mavlink_msg_ranging_beacon_get_hacc_est(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  24);
}

/**
 * @brief Get field vacc_est from ranging_beacon message
 *
 * @return [mm] Beacon 1-sigma vertical accuracy estimate.
 */
MAVLINK_WIP
static inline uint32_t mavlink_msg_ranging_beacon_get_vacc_est(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  28);
}

/**
 * @brief Get field carrier_freq from ranging_beacon message
 *
 * @return [MHz] Ranging carrier frequency
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_ranging_beacon_get_carrier_freq(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  38);
}

/**
 * @brief Get field range_accuracy from ranging_beacon message
 *
 * @return [mm] Estimated 1-sigma range measurement accuracy.
 */
MAVLINK_WIP
static inline uint32_t mavlink_msg_ranging_beacon_get_range_accuracy(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  32);
}

/**
 * @brief Get field sequence from ranging_beacon message
 *
 * @return  Measurement sequence number.
 */
MAVLINK_WIP
static inline uint8_t mavlink_msg_ranging_beacon_get_sequence(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  43);
}

/**
 * @brief Get field status from ranging_beacon message
 *
 * @return  Ranging beacon status.
 */
MAVLINK_WIP
static inline uint8_t mavlink_msg_ranging_beacon_get_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  44);
}

/**
 * @brief Decode a ranging_beacon message into a struct
 *
 * @param msg The message to decode
 * @param ranging_beacon C-struct to decode the message contents into
 */
MAVLINK_WIP
static inline void mavlink_msg_ranging_beacon_decode(const mavlink_message_t* msg, mavlink_ranging_beacon_t* ranging_beacon)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    ranging_beacon->time_usec = mavlink_msg_ranging_beacon_get_time_usec(msg);
    ranging_beacon->range = mavlink_msg_ranging_beacon_get_range(msg);
    ranging_beacon->lat = mavlink_msg_ranging_beacon_get_lat(msg);
    ranging_beacon->lon = mavlink_msg_ranging_beacon_get_lon(msg);
    ranging_beacon->alt = mavlink_msg_ranging_beacon_get_alt(msg);
    ranging_beacon->hacc_est = mavlink_msg_ranging_beacon_get_hacc_est(msg);
    ranging_beacon->vacc_est = mavlink_msg_ranging_beacon_get_vacc_est(msg);
    ranging_beacon->range_accuracy = mavlink_msg_ranging_beacon_get_range_accuracy(msg);
    ranging_beacon->beacon_id = mavlink_msg_ranging_beacon_get_beacon_id(msg);
    ranging_beacon->carrier_freq = mavlink_msg_ranging_beacon_get_carrier_freq(msg);
    ranging_beacon->target_system = mavlink_msg_ranging_beacon_get_target_system(msg);
    ranging_beacon->target_component = mavlink_msg_ranging_beacon_get_target_component(msg);
    ranging_beacon->alt_type = mavlink_msg_ranging_beacon_get_alt_type(msg);
    ranging_beacon->sequence = mavlink_msg_ranging_beacon_get_sequence(msg);
    ranging_beacon->status = mavlink_msg_ranging_beacon_get_status(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_RANGING_BEACON_LEN? msg->len : MAVLINK_MSG_ID_RANGING_BEACON_LEN;
        memset(ranging_beacon, 0, MAVLINK_MSG_ID_RANGING_BEACON_LEN);
    memcpy(ranging_beacon, _MAV_PAYLOAD(msg), len);
#endif
}
