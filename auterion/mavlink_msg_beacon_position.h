#pragma once
// MESSAGE BEACON_POSITION PACKING

#define MAVLINK_MSG_ID_BEACON_POSITION 447


typedef struct __mavlink_beacon_position_t {
 uint32_t beacon_id; /*<  Unique Beacon ID*/
 int32_t latitude; /*< [degE7] Latitude (WGS84), in degrees * 1E7*/
 int32_t longitude; /*< [degE7] Longitude (WGS84), in degrees * 1E7*/
 float altitude; /*< [m] Altitude (MSL), in meters*/
 float distance; /*< [m] Distance to the Beacon, in meters*/
 int32_t delay; /*< [ms] Time between generating the value and request, in milliseconds*/
 int32_t link_quality; /*<  Value indicating the Signal to noise ratio (in units of dB)*/
 uint8_t gps_status; /*<  Status indicating the quality of the GPS Data. 0=invalid 1=lat long valid, alt invalid 2=valid*/
} mavlink_beacon_position_t;

#define MAVLINK_MSG_ID_BEACON_POSITION_LEN 29
#define MAVLINK_MSG_ID_BEACON_POSITION_MIN_LEN 29
#define MAVLINK_MSG_ID_447_LEN 29
#define MAVLINK_MSG_ID_447_MIN_LEN 29

#define MAVLINK_MSG_ID_BEACON_POSITION_CRC 101
#define MAVLINK_MSG_ID_447_CRC 101



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_BEACON_POSITION { \
    447, \
    "BEACON_POSITION", \
    8, \
    {  { "beacon_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_beacon_position_t, beacon_id) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_beacon_position_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_beacon_position_t, longitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_beacon_position_t, altitude) }, \
         { "distance", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_beacon_position_t, distance) }, \
         { "delay", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_beacon_position_t, delay) }, \
         { "gps_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 28, offsetof(mavlink_beacon_position_t, gps_status) }, \
         { "link_quality", NULL, MAVLINK_TYPE_INT32_T, 0, 24, offsetof(mavlink_beacon_position_t, link_quality) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_BEACON_POSITION { \
    "BEACON_POSITION", \
    8, \
    {  { "beacon_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_beacon_position_t, beacon_id) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_beacon_position_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_beacon_position_t, longitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_beacon_position_t, altitude) }, \
         { "distance", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_beacon_position_t, distance) }, \
         { "delay", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_beacon_position_t, delay) }, \
         { "gps_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 28, offsetof(mavlink_beacon_position_t, gps_status) }, \
         { "link_quality", NULL, MAVLINK_TYPE_INT32_T, 0, 24, offsetof(mavlink_beacon_position_t, link_quality) }, \
         } \
}
#endif

/**
 * @brief Pack a beacon_position message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param beacon_id  Unique Beacon ID
 * @param latitude [degE7] Latitude (WGS84), in degrees * 1E7
 * @param longitude [degE7] Longitude (WGS84), in degrees * 1E7
 * @param altitude [m] Altitude (MSL), in meters
 * @param distance [m] Distance to the Beacon, in meters
 * @param delay [ms] Time between generating the value and request, in milliseconds
 * @param gps_status  Status indicating the quality of the GPS Data. 0=invalid 1=lat long valid, alt invalid 2=valid
 * @param link_quality  Value indicating the Signal to noise ratio (in units of dB)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_beacon_position_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t beacon_id, int32_t latitude, int32_t longitude, float altitude, float distance, int32_t delay, uint8_t gps_status, int32_t link_quality)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BEACON_POSITION_LEN];
    _mav_put_uint32_t(buf, 0, beacon_id);
    _mav_put_int32_t(buf, 4, latitude);
    _mav_put_int32_t(buf, 8, longitude);
    _mav_put_float(buf, 12, altitude);
    _mav_put_float(buf, 16, distance);
    _mav_put_int32_t(buf, 20, delay);
    _mav_put_int32_t(buf, 24, link_quality);
    _mav_put_uint8_t(buf, 28, gps_status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BEACON_POSITION_LEN);
#else
    mavlink_beacon_position_t packet;
    packet.beacon_id = beacon_id;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.altitude = altitude;
    packet.distance = distance;
    packet.delay = delay;
    packet.link_quality = link_quality;
    packet.gps_status = gps_status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BEACON_POSITION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_BEACON_POSITION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_BEACON_POSITION_MIN_LEN, MAVLINK_MSG_ID_BEACON_POSITION_LEN, MAVLINK_MSG_ID_BEACON_POSITION_CRC);
}

/**
 * @brief Pack a beacon_position message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param beacon_id  Unique Beacon ID
 * @param latitude [degE7] Latitude (WGS84), in degrees * 1E7
 * @param longitude [degE7] Longitude (WGS84), in degrees * 1E7
 * @param altitude [m] Altitude (MSL), in meters
 * @param distance [m] Distance to the Beacon, in meters
 * @param delay [ms] Time between generating the value and request, in milliseconds
 * @param gps_status  Status indicating the quality of the GPS Data. 0=invalid 1=lat long valid, alt invalid 2=valid
 * @param link_quality  Value indicating the Signal to noise ratio (in units of dB)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_beacon_position_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint32_t beacon_id, int32_t latitude, int32_t longitude, float altitude, float distance, int32_t delay, uint8_t gps_status, int32_t link_quality)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BEACON_POSITION_LEN];
    _mav_put_uint32_t(buf, 0, beacon_id);
    _mav_put_int32_t(buf, 4, latitude);
    _mav_put_int32_t(buf, 8, longitude);
    _mav_put_float(buf, 12, altitude);
    _mav_put_float(buf, 16, distance);
    _mav_put_int32_t(buf, 20, delay);
    _mav_put_int32_t(buf, 24, link_quality);
    _mav_put_uint8_t(buf, 28, gps_status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BEACON_POSITION_LEN);
#else
    mavlink_beacon_position_t packet;
    packet.beacon_id = beacon_id;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.altitude = altitude;
    packet.distance = distance;
    packet.delay = delay;
    packet.link_quality = link_quality;
    packet.gps_status = gps_status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BEACON_POSITION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_BEACON_POSITION;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_BEACON_POSITION_MIN_LEN, MAVLINK_MSG_ID_BEACON_POSITION_LEN, MAVLINK_MSG_ID_BEACON_POSITION_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_BEACON_POSITION_MIN_LEN, MAVLINK_MSG_ID_BEACON_POSITION_LEN);
#endif
}

/**
 * @brief Pack a beacon_position message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param beacon_id  Unique Beacon ID
 * @param latitude [degE7] Latitude (WGS84), in degrees * 1E7
 * @param longitude [degE7] Longitude (WGS84), in degrees * 1E7
 * @param altitude [m] Altitude (MSL), in meters
 * @param distance [m] Distance to the Beacon, in meters
 * @param delay [ms] Time between generating the value and request, in milliseconds
 * @param gps_status  Status indicating the quality of the GPS Data. 0=invalid 1=lat long valid, alt invalid 2=valid
 * @param link_quality  Value indicating the Signal to noise ratio (in units of dB)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_beacon_position_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t beacon_id,int32_t latitude,int32_t longitude,float altitude,float distance,int32_t delay,uint8_t gps_status,int32_t link_quality)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BEACON_POSITION_LEN];
    _mav_put_uint32_t(buf, 0, beacon_id);
    _mav_put_int32_t(buf, 4, latitude);
    _mav_put_int32_t(buf, 8, longitude);
    _mav_put_float(buf, 12, altitude);
    _mav_put_float(buf, 16, distance);
    _mav_put_int32_t(buf, 20, delay);
    _mav_put_int32_t(buf, 24, link_quality);
    _mav_put_uint8_t(buf, 28, gps_status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BEACON_POSITION_LEN);
#else
    mavlink_beacon_position_t packet;
    packet.beacon_id = beacon_id;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.altitude = altitude;
    packet.distance = distance;
    packet.delay = delay;
    packet.link_quality = link_quality;
    packet.gps_status = gps_status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BEACON_POSITION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_BEACON_POSITION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_BEACON_POSITION_MIN_LEN, MAVLINK_MSG_ID_BEACON_POSITION_LEN, MAVLINK_MSG_ID_BEACON_POSITION_CRC);
}

/**
 * @brief Encode a beacon_position struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param beacon_position C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_beacon_position_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_beacon_position_t* beacon_position)
{
    return mavlink_msg_beacon_position_pack(system_id, component_id, msg, beacon_position->beacon_id, beacon_position->latitude, beacon_position->longitude, beacon_position->altitude, beacon_position->distance, beacon_position->delay, beacon_position->gps_status, beacon_position->link_quality);
}

/**
 * @brief Encode a beacon_position struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param beacon_position C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_beacon_position_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_beacon_position_t* beacon_position)
{
    return mavlink_msg_beacon_position_pack_chan(system_id, component_id, chan, msg, beacon_position->beacon_id, beacon_position->latitude, beacon_position->longitude, beacon_position->altitude, beacon_position->distance, beacon_position->delay, beacon_position->gps_status, beacon_position->link_quality);
}

/**
 * @brief Encode a beacon_position struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param beacon_position C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_beacon_position_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_beacon_position_t* beacon_position)
{
    return mavlink_msg_beacon_position_pack_status(system_id, component_id, _status, msg,  beacon_position->beacon_id, beacon_position->latitude, beacon_position->longitude, beacon_position->altitude, beacon_position->distance, beacon_position->delay, beacon_position->gps_status, beacon_position->link_quality);
}

/**
 * @brief Send a beacon_position message
 * @param chan MAVLink channel to send the message
 *
 * @param beacon_id  Unique Beacon ID
 * @param latitude [degE7] Latitude (WGS84), in degrees * 1E7
 * @param longitude [degE7] Longitude (WGS84), in degrees * 1E7
 * @param altitude [m] Altitude (MSL), in meters
 * @param distance [m] Distance to the Beacon, in meters
 * @param delay [ms] Time between generating the value and request, in milliseconds
 * @param gps_status  Status indicating the quality of the GPS Data. 0=invalid 1=lat long valid, alt invalid 2=valid
 * @param link_quality  Value indicating the Signal to noise ratio (in units of dB)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_beacon_position_send(mavlink_channel_t chan, uint32_t beacon_id, int32_t latitude, int32_t longitude, float altitude, float distance, int32_t delay, uint8_t gps_status, int32_t link_quality)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BEACON_POSITION_LEN];
    _mav_put_uint32_t(buf, 0, beacon_id);
    _mav_put_int32_t(buf, 4, latitude);
    _mav_put_int32_t(buf, 8, longitude);
    _mav_put_float(buf, 12, altitude);
    _mav_put_float(buf, 16, distance);
    _mav_put_int32_t(buf, 20, delay);
    _mav_put_int32_t(buf, 24, link_quality);
    _mav_put_uint8_t(buf, 28, gps_status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BEACON_POSITION, buf, MAVLINK_MSG_ID_BEACON_POSITION_MIN_LEN, MAVLINK_MSG_ID_BEACON_POSITION_LEN, MAVLINK_MSG_ID_BEACON_POSITION_CRC);
#else
    mavlink_beacon_position_t packet;
    packet.beacon_id = beacon_id;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.altitude = altitude;
    packet.distance = distance;
    packet.delay = delay;
    packet.link_quality = link_quality;
    packet.gps_status = gps_status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BEACON_POSITION, (const char *)&packet, MAVLINK_MSG_ID_BEACON_POSITION_MIN_LEN, MAVLINK_MSG_ID_BEACON_POSITION_LEN, MAVLINK_MSG_ID_BEACON_POSITION_CRC);
#endif
}

/**
 * @brief Send a beacon_position message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_beacon_position_send_struct(mavlink_channel_t chan, const mavlink_beacon_position_t* beacon_position)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_beacon_position_send(chan, beacon_position->beacon_id, beacon_position->latitude, beacon_position->longitude, beacon_position->altitude, beacon_position->distance, beacon_position->delay, beacon_position->gps_status, beacon_position->link_quality);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BEACON_POSITION, (const char *)beacon_position, MAVLINK_MSG_ID_BEACON_POSITION_MIN_LEN, MAVLINK_MSG_ID_BEACON_POSITION_LEN, MAVLINK_MSG_ID_BEACON_POSITION_CRC);
#endif
}

#if MAVLINK_MSG_ID_BEACON_POSITION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_beacon_position_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t beacon_id, int32_t latitude, int32_t longitude, float altitude, float distance, int32_t delay, uint8_t gps_status, int32_t link_quality)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, beacon_id);
    _mav_put_int32_t(buf, 4, latitude);
    _mav_put_int32_t(buf, 8, longitude);
    _mav_put_float(buf, 12, altitude);
    _mav_put_float(buf, 16, distance);
    _mav_put_int32_t(buf, 20, delay);
    _mav_put_int32_t(buf, 24, link_quality);
    _mav_put_uint8_t(buf, 28, gps_status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BEACON_POSITION, buf, MAVLINK_MSG_ID_BEACON_POSITION_MIN_LEN, MAVLINK_MSG_ID_BEACON_POSITION_LEN, MAVLINK_MSG_ID_BEACON_POSITION_CRC);
#else
    mavlink_beacon_position_t *packet = (mavlink_beacon_position_t *)msgbuf;
    packet->beacon_id = beacon_id;
    packet->latitude = latitude;
    packet->longitude = longitude;
    packet->altitude = altitude;
    packet->distance = distance;
    packet->delay = delay;
    packet->link_quality = link_quality;
    packet->gps_status = gps_status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BEACON_POSITION, (const char *)packet, MAVLINK_MSG_ID_BEACON_POSITION_MIN_LEN, MAVLINK_MSG_ID_BEACON_POSITION_LEN, MAVLINK_MSG_ID_BEACON_POSITION_CRC);
#endif
}
#endif

#endif

// MESSAGE BEACON_POSITION UNPACKING


/**
 * @brief Get field beacon_id from beacon_position message
 *
 * @return  Unique Beacon ID
 */
static inline uint32_t mavlink_msg_beacon_position_get_beacon_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field latitude from beacon_position message
 *
 * @return [degE7] Latitude (WGS84), in degrees * 1E7
 */
static inline int32_t mavlink_msg_beacon_position_get_latitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field longitude from beacon_position message
 *
 * @return [degE7] Longitude (WGS84), in degrees * 1E7
 */
static inline int32_t mavlink_msg_beacon_position_get_longitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field altitude from beacon_position message
 *
 * @return [m] Altitude (MSL), in meters
 */
static inline float mavlink_msg_beacon_position_get_altitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field distance from beacon_position message
 *
 * @return [m] Distance to the Beacon, in meters
 */
static inline float mavlink_msg_beacon_position_get_distance(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field delay from beacon_position message
 *
 * @return [ms] Time between generating the value and request, in milliseconds
 */
static inline int32_t mavlink_msg_beacon_position_get_delay(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  20);
}

/**
 * @brief Get field gps_status from beacon_position message
 *
 * @return  Status indicating the quality of the GPS Data. 0=invalid 1=lat long valid, alt invalid 2=valid
 */
static inline uint8_t mavlink_msg_beacon_position_get_gps_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  28);
}

/**
 * @brief Get field link_quality from beacon_position message
 *
 * @return  Value indicating the Signal to noise ratio (in units of dB)
 */
static inline int32_t mavlink_msg_beacon_position_get_link_quality(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  24);
}

/**
 * @brief Decode a beacon_position message into a struct
 *
 * @param msg The message to decode
 * @param beacon_position C-struct to decode the message contents into
 */
static inline void mavlink_msg_beacon_position_decode(const mavlink_message_t* msg, mavlink_beacon_position_t* beacon_position)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    beacon_position->beacon_id = mavlink_msg_beacon_position_get_beacon_id(msg);
    beacon_position->latitude = mavlink_msg_beacon_position_get_latitude(msg);
    beacon_position->longitude = mavlink_msg_beacon_position_get_longitude(msg);
    beacon_position->altitude = mavlink_msg_beacon_position_get_altitude(msg);
    beacon_position->distance = mavlink_msg_beacon_position_get_distance(msg);
    beacon_position->delay = mavlink_msg_beacon_position_get_delay(msg);
    beacon_position->link_quality = mavlink_msg_beacon_position_get_link_quality(msg);
    beacon_position->gps_status = mavlink_msg_beacon_position_get_gps_status(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_BEACON_POSITION_LEN? msg->len : MAVLINK_MSG_ID_BEACON_POSITION_LEN;
        memset(beacon_position, 0, MAVLINK_MSG_ID_BEACON_POSITION_LEN);
    memcpy(beacon_position, _MAV_PAYLOAD(msg), len);
#endif
}
