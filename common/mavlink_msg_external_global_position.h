#pragma once
// MESSAGE EXTERNAL_GLOBAL_POSITION PACKING

#define MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION 296


typedef struct __mavlink_external_global_position_t {
 uint64_t time_usec; /*< [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.*/
 int32_t lat; /*< [degE7] Latitude (WGS84)*/
 int32_t lon; /*< [degE7] Longitude (WGS84)*/
 float alt; /*< [m] Altitude (MSL)*/
 float vn; /*< [m/s] GPS velocity in north direction in earth-fixed NED frame. NaN is unused*/
 float ve; /*< [m/s] GPS velocity in east direction in earth-fixed NED frame*/
 float vd; /*< [m/s] GPS velocity in down direction in earth-fixed NED frame*/
 float eph; /*< [m] Standard deviation of horizontal position error*/
 float epv; /*< [m] Standard deviation of vertical position error*/
 float evh; /*< [m] Standard deviation of horizontal velocity error*/
 float evv; /*< [m] Standard deviation of vertical velocity error*/
 uint8_t id; /*<  Sensor ID*/
} mavlink_external_global_position_t;

#define MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_LEN 49
#define MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_MIN_LEN 49
#define MAVLINK_MSG_ID_296_LEN 49
#define MAVLINK_MSG_ID_296_MIN_LEN 49

#define MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_CRC 110
#define MAVLINK_MSG_ID_296_CRC 110



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_EXTERNAL_GLOBAL_POSITION { \
    296, \
    "EXTERNAL_GLOBAL_POSITION", \
    12, \
    {  { "id", NULL, MAVLINK_TYPE_UINT8_T, 0, 48, offsetof(mavlink_external_global_position_t, id) }, \
         { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_external_global_position_t, time_usec) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_external_global_position_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_external_global_position_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_external_global_position_t, alt) }, \
         { "vn", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_external_global_position_t, vn) }, \
         { "ve", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_external_global_position_t, ve) }, \
         { "vd", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_external_global_position_t, vd) }, \
         { "eph", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_external_global_position_t, eph) }, \
         { "epv", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_external_global_position_t, epv) }, \
         { "evh", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_external_global_position_t, evh) }, \
         { "evv", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_external_global_position_t, evv) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_EXTERNAL_GLOBAL_POSITION { \
    "EXTERNAL_GLOBAL_POSITION", \
    12, \
    {  { "id", NULL, MAVLINK_TYPE_UINT8_T, 0, 48, offsetof(mavlink_external_global_position_t, id) }, \
         { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_external_global_position_t, time_usec) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_external_global_position_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_external_global_position_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_external_global_position_t, alt) }, \
         { "vn", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_external_global_position_t, vn) }, \
         { "ve", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_external_global_position_t, ve) }, \
         { "vd", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_external_global_position_t, vd) }, \
         { "eph", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_external_global_position_t, eph) }, \
         { "epv", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_external_global_position_t, epv) }, \
         { "evh", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_external_global_position_t, evh) }, \
         { "evv", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_external_global_position_t, evv) }, \
         } \
}
#endif

/**
 * @brief Pack a external_global_position message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param id  Sensor ID
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param lat [degE7] Latitude (WGS84)
 * @param lon [degE7] Longitude (WGS84)
 * @param alt [m] Altitude (MSL)
 * @param vn [m/s] GPS velocity in north direction in earth-fixed NED frame. NaN is unused
 * @param ve [m/s] GPS velocity in east direction in earth-fixed NED frame
 * @param vd [m/s] GPS velocity in down direction in earth-fixed NED frame
 * @param eph [m] Standard deviation of horizontal position error
 * @param epv [m] Standard deviation of vertical position error
 * @param evh [m] Standard deviation of horizontal velocity error
 * @param evv [m] Standard deviation of vertical velocity error
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_external_global_position_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t id, uint64_t time_usec, int32_t lat, int32_t lon, float alt, float vn, float ve, float vd, float eph, float epv, float evh, float evv)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int32_t(buf, 8, lat);
    _mav_put_int32_t(buf, 12, lon);
    _mav_put_float(buf, 16, alt);
    _mav_put_float(buf, 20, vn);
    _mav_put_float(buf, 24, ve);
    _mav_put_float(buf, 28, vd);
    _mav_put_float(buf, 32, eph);
    _mav_put_float(buf, 36, epv);
    _mav_put_float(buf, 40, evh);
    _mav_put_float(buf, 44, evv);
    _mav_put_uint8_t(buf, 48, id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_LEN);
#else
    mavlink_external_global_position_t packet;
    packet.time_usec = time_usec;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.vn = vn;
    packet.ve = ve;
    packet.vd = vd;
    packet.eph = eph;
    packet.epv = epv;
    packet.evh = evh;
    packet.evv = evv;
    packet.id = id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_MIN_LEN, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_LEN, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_CRC);
}

/**
 * @brief Pack a external_global_position message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param id  Sensor ID
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param lat [degE7] Latitude (WGS84)
 * @param lon [degE7] Longitude (WGS84)
 * @param alt [m] Altitude (MSL)
 * @param vn [m/s] GPS velocity in north direction in earth-fixed NED frame. NaN is unused
 * @param ve [m/s] GPS velocity in east direction in earth-fixed NED frame
 * @param vd [m/s] GPS velocity in down direction in earth-fixed NED frame
 * @param eph [m] Standard deviation of horizontal position error
 * @param epv [m] Standard deviation of vertical position error
 * @param evh [m] Standard deviation of horizontal velocity error
 * @param evv [m] Standard deviation of vertical velocity error
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_external_global_position_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t id, uint64_t time_usec, int32_t lat, int32_t lon, float alt, float vn, float ve, float vd, float eph, float epv, float evh, float evv)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int32_t(buf, 8, lat);
    _mav_put_int32_t(buf, 12, lon);
    _mav_put_float(buf, 16, alt);
    _mav_put_float(buf, 20, vn);
    _mav_put_float(buf, 24, ve);
    _mav_put_float(buf, 28, vd);
    _mav_put_float(buf, 32, eph);
    _mav_put_float(buf, 36, epv);
    _mav_put_float(buf, 40, evh);
    _mav_put_float(buf, 44, evv);
    _mav_put_uint8_t(buf, 48, id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_LEN);
#else
    mavlink_external_global_position_t packet;
    packet.time_usec = time_usec;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.vn = vn;
    packet.ve = ve;
    packet.vd = vd;
    packet.eph = eph;
    packet.epv = epv;
    packet.evh = evh;
    packet.evv = evv;
    packet.id = id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_MIN_LEN, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_LEN, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_MIN_LEN, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_LEN);
#endif
}

/**
 * @brief Pack a external_global_position message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param id  Sensor ID
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param lat [degE7] Latitude (WGS84)
 * @param lon [degE7] Longitude (WGS84)
 * @param alt [m] Altitude (MSL)
 * @param vn [m/s] GPS velocity in north direction in earth-fixed NED frame. NaN is unused
 * @param ve [m/s] GPS velocity in east direction in earth-fixed NED frame
 * @param vd [m/s] GPS velocity in down direction in earth-fixed NED frame
 * @param eph [m] Standard deviation of horizontal position error
 * @param epv [m] Standard deviation of vertical position error
 * @param evh [m] Standard deviation of horizontal velocity error
 * @param evv [m] Standard deviation of vertical velocity error
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_external_global_position_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t id,uint64_t time_usec,int32_t lat,int32_t lon,float alt,float vn,float ve,float vd,float eph,float epv,float evh,float evv)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int32_t(buf, 8, lat);
    _mav_put_int32_t(buf, 12, lon);
    _mav_put_float(buf, 16, alt);
    _mav_put_float(buf, 20, vn);
    _mav_put_float(buf, 24, ve);
    _mav_put_float(buf, 28, vd);
    _mav_put_float(buf, 32, eph);
    _mav_put_float(buf, 36, epv);
    _mav_put_float(buf, 40, evh);
    _mav_put_float(buf, 44, evv);
    _mav_put_uint8_t(buf, 48, id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_LEN);
#else
    mavlink_external_global_position_t packet;
    packet.time_usec = time_usec;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.vn = vn;
    packet.ve = ve;
    packet.vd = vd;
    packet.eph = eph;
    packet.epv = epv;
    packet.evh = evh;
    packet.evv = evv;
    packet.id = id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_MIN_LEN, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_LEN, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_CRC);
}

/**
 * @brief Encode a external_global_position struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param external_global_position C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_external_global_position_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_external_global_position_t* external_global_position)
{
    return mavlink_msg_external_global_position_pack(system_id, component_id, msg, external_global_position->id, external_global_position->time_usec, external_global_position->lat, external_global_position->lon, external_global_position->alt, external_global_position->vn, external_global_position->ve, external_global_position->vd, external_global_position->eph, external_global_position->epv, external_global_position->evh, external_global_position->evv);
}

/**
 * @brief Encode a external_global_position struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param external_global_position C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_external_global_position_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_external_global_position_t* external_global_position)
{
    return mavlink_msg_external_global_position_pack_chan(system_id, component_id, chan, msg, external_global_position->id, external_global_position->time_usec, external_global_position->lat, external_global_position->lon, external_global_position->alt, external_global_position->vn, external_global_position->ve, external_global_position->vd, external_global_position->eph, external_global_position->epv, external_global_position->evh, external_global_position->evv);
}

/**
 * @brief Encode a external_global_position struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param external_global_position C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_external_global_position_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_external_global_position_t* external_global_position)
{
    return mavlink_msg_external_global_position_pack_status(system_id, component_id, _status, msg,  external_global_position->id, external_global_position->time_usec, external_global_position->lat, external_global_position->lon, external_global_position->alt, external_global_position->vn, external_global_position->ve, external_global_position->vd, external_global_position->eph, external_global_position->epv, external_global_position->evh, external_global_position->evv);
}

/**
 * @brief Send a external_global_position message
 * @param chan MAVLink channel to send the message
 *
 * @param id  Sensor ID
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param lat [degE7] Latitude (WGS84)
 * @param lon [degE7] Longitude (WGS84)
 * @param alt [m] Altitude (MSL)
 * @param vn [m/s] GPS velocity in north direction in earth-fixed NED frame. NaN is unused
 * @param ve [m/s] GPS velocity in east direction in earth-fixed NED frame
 * @param vd [m/s] GPS velocity in down direction in earth-fixed NED frame
 * @param eph [m] Standard deviation of horizontal position error
 * @param epv [m] Standard deviation of vertical position error
 * @param evh [m] Standard deviation of horizontal velocity error
 * @param evv [m] Standard deviation of vertical velocity error
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_external_global_position_send(mavlink_channel_t chan, uint8_t id, uint64_t time_usec, int32_t lat, int32_t lon, float alt, float vn, float ve, float vd, float eph, float epv, float evh, float evv)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int32_t(buf, 8, lat);
    _mav_put_int32_t(buf, 12, lon);
    _mav_put_float(buf, 16, alt);
    _mav_put_float(buf, 20, vn);
    _mav_put_float(buf, 24, ve);
    _mav_put_float(buf, 28, vd);
    _mav_put_float(buf, 32, eph);
    _mav_put_float(buf, 36, epv);
    _mav_put_float(buf, 40, evh);
    _mav_put_float(buf, 44, evv);
    _mav_put_uint8_t(buf, 48, id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION, buf, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_MIN_LEN, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_LEN, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_CRC);
#else
    mavlink_external_global_position_t packet;
    packet.time_usec = time_usec;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.vn = vn;
    packet.ve = ve;
    packet.vd = vd;
    packet.eph = eph;
    packet.epv = epv;
    packet.evh = evh;
    packet.evv = evv;
    packet.id = id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION, (const char *)&packet, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_MIN_LEN, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_LEN, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_CRC);
#endif
}

/**
 * @brief Send a external_global_position message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_external_global_position_send_struct(mavlink_channel_t chan, const mavlink_external_global_position_t* external_global_position)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_external_global_position_send(chan, external_global_position->id, external_global_position->time_usec, external_global_position->lat, external_global_position->lon, external_global_position->alt, external_global_position->vn, external_global_position->ve, external_global_position->vd, external_global_position->eph, external_global_position->epv, external_global_position->evh, external_global_position->evv);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION, (const char *)external_global_position, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_MIN_LEN, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_LEN, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_CRC);
#endif
}

#if MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_external_global_position_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t id, uint64_t time_usec, int32_t lat, int32_t lon, float alt, float vn, float ve, float vd, float eph, float epv, float evh, float evv)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int32_t(buf, 8, lat);
    _mav_put_int32_t(buf, 12, lon);
    _mav_put_float(buf, 16, alt);
    _mav_put_float(buf, 20, vn);
    _mav_put_float(buf, 24, ve);
    _mav_put_float(buf, 28, vd);
    _mav_put_float(buf, 32, eph);
    _mav_put_float(buf, 36, epv);
    _mav_put_float(buf, 40, evh);
    _mav_put_float(buf, 44, evv);
    _mav_put_uint8_t(buf, 48, id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION, buf, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_MIN_LEN, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_LEN, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_CRC);
#else
    mavlink_external_global_position_t *packet = (mavlink_external_global_position_t *)msgbuf;
    packet->time_usec = time_usec;
    packet->lat = lat;
    packet->lon = lon;
    packet->alt = alt;
    packet->vn = vn;
    packet->ve = ve;
    packet->vd = vd;
    packet->eph = eph;
    packet->epv = epv;
    packet->evh = evh;
    packet->evv = evv;
    packet->id = id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION, (const char *)packet, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_MIN_LEN, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_LEN, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_CRC);
#endif
}
#endif

#endif

// MESSAGE EXTERNAL_GLOBAL_POSITION UNPACKING


/**
 * @brief Get field id from external_global_position message
 *
 * @return  Sensor ID
 */
static inline uint8_t mavlink_msg_external_global_position_get_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  48);
}

/**
 * @brief Get field time_usec from external_global_position message
 *
 * @return [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 */
static inline uint64_t mavlink_msg_external_global_position_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field lat from external_global_position message
 *
 * @return [degE7] Latitude (WGS84)
 */
static inline int32_t mavlink_msg_external_global_position_get_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field lon from external_global_position message
 *
 * @return [degE7] Longitude (WGS84)
 */
static inline int32_t mavlink_msg_external_global_position_get_lon(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field alt from external_global_position message
 *
 * @return [m] Altitude (MSL)
 */
static inline float mavlink_msg_external_global_position_get_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field vn from external_global_position message
 *
 * @return [m/s] GPS velocity in north direction in earth-fixed NED frame. NaN is unused
 */
static inline float mavlink_msg_external_global_position_get_vn(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field ve from external_global_position message
 *
 * @return [m/s] GPS velocity in east direction in earth-fixed NED frame
 */
static inline float mavlink_msg_external_global_position_get_ve(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field vd from external_global_position message
 *
 * @return [m/s] GPS velocity in down direction in earth-fixed NED frame
 */
static inline float mavlink_msg_external_global_position_get_vd(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field eph from external_global_position message
 *
 * @return [m] Standard deviation of horizontal position error
 */
static inline float mavlink_msg_external_global_position_get_eph(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field epv from external_global_position message
 *
 * @return [m] Standard deviation of vertical position error
 */
static inline float mavlink_msg_external_global_position_get_epv(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field evh from external_global_position message
 *
 * @return [m] Standard deviation of horizontal velocity error
 */
static inline float mavlink_msg_external_global_position_get_evh(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field evv from external_global_position message
 *
 * @return [m] Standard deviation of vertical velocity error
 */
static inline float mavlink_msg_external_global_position_get_evv(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Decode a external_global_position message into a struct
 *
 * @param msg The message to decode
 * @param external_global_position C-struct to decode the message contents into
 */
static inline void mavlink_msg_external_global_position_decode(const mavlink_message_t* msg, mavlink_external_global_position_t* external_global_position)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    external_global_position->time_usec = mavlink_msg_external_global_position_get_time_usec(msg);
    external_global_position->lat = mavlink_msg_external_global_position_get_lat(msg);
    external_global_position->lon = mavlink_msg_external_global_position_get_lon(msg);
    external_global_position->alt = mavlink_msg_external_global_position_get_alt(msg);
    external_global_position->vn = mavlink_msg_external_global_position_get_vn(msg);
    external_global_position->ve = mavlink_msg_external_global_position_get_ve(msg);
    external_global_position->vd = mavlink_msg_external_global_position_get_vd(msg);
    external_global_position->eph = mavlink_msg_external_global_position_get_eph(msg);
    external_global_position->epv = mavlink_msg_external_global_position_get_epv(msg);
    external_global_position->evh = mavlink_msg_external_global_position_get_evh(msg);
    external_global_position->evv = mavlink_msg_external_global_position_get_evv(msg);
    external_global_position->id = mavlink_msg_external_global_position_get_id(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_LEN? msg->len : MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_LEN;
        memset(external_global_position, 0, MAVLINK_MSG_ID_EXTERNAL_GLOBAL_POSITION_LEN);
    memcpy(external_global_position, _MAV_PAYLOAD(msg), len);
#endif
}
