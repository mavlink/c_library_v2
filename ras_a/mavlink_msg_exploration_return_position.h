#pragma once
// MESSAGE EXPLORATION_RETURN_POSITION PACKING

#define MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION 452


typedef struct __mavlink_exploration_return_position_t {
 uint64_t time_usec; /*< [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.*/
 int32_t latitude; /*< [degE7] Latitude (WGS84). INT32_MAX when unknown.*/
 int32_t longitude; /*< [degE7] Longitude (WGS84). INT32_MAX when unknown.*/
 int32_t altitude; /*< [mm] Altitude (MSL). Positive for up. Note that virtually all GPS modules provide both WGS84 and MSL. INT32_MAX when unknown.*/
 int32_t relative_alt; /*< [mm] Altitude above ground. INT32_MAX when unknown.*/
 int32_t geoid_alt; /*< [mm] Altitude relative to WGS84 geoid. INT32_MAX when unknown.*/
 float x; /*< [m] Local X position of this position in the local coordinate NED frame. NaN when unknown.*/
 float y; /*< [m] Local Y position of this position in the local coordinate NED frame. NaN when unknown.*/
 float z; /*< [m] Local Z position of this position in the local coordinate NED frame. NaN when unknown.*/
 float yaw; /*< [rad] World to surface heading transformation of the return-from-exploration position. Used to indicate the heading with respect to the ground. NaN when unknown.*/
} mavlink_exploration_return_position_t;

#define MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION_LEN 44
#define MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION_MIN_LEN 44
#define MAVLINK_MSG_ID_452_LEN 44
#define MAVLINK_MSG_ID_452_MIN_LEN 44

#define MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION_CRC 142
#define MAVLINK_MSG_ID_452_CRC 142



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_EXPLORATION_RETURN_POSITION { \
    452, \
    "EXPLORATION_RETURN_POSITION", \
    10, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_exploration_return_position_t, time_usec) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_exploration_return_position_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_exploration_return_position_t, longitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_exploration_return_position_t, altitude) }, \
         { "relative_alt", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_exploration_return_position_t, relative_alt) }, \
         { "geoid_alt", NULL, MAVLINK_TYPE_INT32_T, 0, 24, offsetof(mavlink_exploration_return_position_t, geoid_alt) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_exploration_return_position_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_exploration_return_position_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_exploration_return_position_t, z) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_exploration_return_position_t, yaw) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_EXPLORATION_RETURN_POSITION { \
    "EXPLORATION_RETURN_POSITION", \
    10, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_exploration_return_position_t, time_usec) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_exploration_return_position_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_exploration_return_position_t, longitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_exploration_return_position_t, altitude) }, \
         { "relative_alt", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_exploration_return_position_t, relative_alt) }, \
         { "geoid_alt", NULL, MAVLINK_TYPE_INT32_T, 0, 24, offsetof(mavlink_exploration_return_position_t, geoid_alt) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_exploration_return_position_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_exploration_return_position_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_exploration_return_position_t, z) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_exploration_return_position_t, yaw) }, \
         } \
}
#endif

/**
 * @brief Pack a exploration_return_position message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param latitude [degE7] Latitude (WGS84). INT32_MAX when unknown.
 * @param longitude [degE7] Longitude (WGS84). INT32_MAX when unknown.
 * @param altitude [mm] Altitude (MSL). Positive for up. Note that virtually all GPS modules provide both WGS84 and MSL. INT32_MAX when unknown.
 * @param relative_alt [mm] Altitude above ground. INT32_MAX when unknown.
 * @param geoid_alt [mm] Altitude relative to WGS84 geoid. INT32_MAX when unknown.
 * @param x [m] Local X position of this position in the local coordinate NED frame. NaN when unknown.
 * @param y [m] Local Y position of this position in the local coordinate NED frame. NaN when unknown.
 * @param z [m] Local Z position of this position in the local coordinate NED frame. NaN when unknown.
 * @param yaw [rad] World to surface heading transformation of the return-from-exploration position. Used to indicate the heading with respect to the ground. NaN when unknown.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_exploration_return_position_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, int32_t latitude, int32_t longitude, int32_t altitude, int32_t relative_alt, int32_t geoid_alt, float x, float y, float z, float yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int32_t(buf, 8, latitude);
    _mav_put_int32_t(buf, 12, longitude);
    _mav_put_int32_t(buf, 16, altitude);
    _mav_put_int32_t(buf, 20, relative_alt);
    _mav_put_int32_t(buf, 24, geoid_alt);
    _mav_put_float(buf, 28, x);
    _mav_put_float(buf, 32, y);
    _mav_put_float(buf, 36, z);
    _mav_put_float(buf, 40, yaw);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION_LEN);
#else
    mavlink_exploration_return_position_t packet;
    packet.time_usec = time_usec;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.altitude = altitude;
    packet.relative_alt = relative_alt;
    packet.geoid_alt = geoid_alt;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.yaw = yaw;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION_MIN_LEN, MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION_LEN, MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION_CRC);
}

/**
 * @brief Pack a exploration_return_position message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param latitude [degE7] Latitude (WGS84). INT32_MAX when unknown.
 * @param longitude [degE7] Longitude (WGS84). INT32_MAX when unknown.
 * @param altitude [mm] Altitude (MSL). Positive for up. Note that virtually all GPS modules provide both WGS84 and MSL. INT32_MAX when unknown.
 * @param relative_alt [mm] Altitude above ground. INT32_MAX when unknown.
 * @param geoid_alt [mm] Altitude relative to WGS84 geoid. INT32_MAX when unknown.
 * @param x [m] Local X position of this position in the local coordinate NED frame. NaN when unknown.
 * @param y [m] Local Y position of this position in the local coordinate NED frame. NaN when unknown.
 * @param z [m] Local Z position of this position in the local coordinate NED frame. NaN when unknown.
 * @param yaw [rad] World to surface heading transformation of the return-from-exploration position. Used to indicate the heading with respect to the ground. NaN when unknown.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_exploration_return_position_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,int32_t latitude,int32_t longitude,int32_t altitude,int32_t relative_alt,int32_t geoid_alt,float x,float y,float z,float yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int32_t(buf, 8, latitude);
    _mav_put_int32_t(buf, 12, longitude);
    _mav_put_int32_t(buf, 16, altitude);
    _mav_put_int32_t(buf, 20, relative_alt);
    _mav_put_int32_t(buf, 24, geoid_alt);
    _mav_put_float(buf, 28, x);
    _mav_put_float(buf, 32, y);
    _mav_put_float(buf, 36, z);
    _mav_put_float(buf, 40, yaw);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION_LEN);
#else
    mavlink_exploration_return_position_t packet;
    packet.time_usec = time_usec;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.altitude = altitude;
    packet.relative_alt = relative_alt;
    packet.geoid_alt = geoid_alt;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.yaw = yaw;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION_MIN_LEN, MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION_LEN, MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION_CRC);
}

/**
 * @brief Encode a exploration_return_position struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param exploration_return_position C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_exploration_return_position_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_exploration_return_position_t* exploration_return_position)
{
    return mavlink_msg_exploration_return_position_pack(system_id, component_id, msg, exploration_return_position->time_usec, exploration_return_position->latitude, exploration_return_position->longitude, exploration_return_position->altitude, exploration_return_position->relative_alt, exploration_return_position->geoid_alt, exploration_return_position->x, exploration_return_position->y, exploration_return_position->z, exploration_return_position->yaw);
}

/**
 * @brief Encode a exploration_return_position struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param exploration_return_position C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_exploration_return_position_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_exploration_return_position_t* exploration_return_position)
{
    return mavlink_msg_exploration_return_position_pack_chan(system_id, component_id, chan, msg, exploration_return_position->time_usec, exploration_return_position->latitude, exploration_return_position->longitude, exploration_return_position->altitude, exploration_return_position->relative_alt, exploration_return_position->geoid_alt, exploration_return_position->x, exploration_return_position->y, exploration_return_position->z, exploration_return_position->yaw);
}

/**
 * @brief Send a exploration_return_position message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param latitude [degE7] Latitude (WGS84). INT32_MAX when unknown.
 * @param longitude [degE7] Longitude (WGS84). INT32_MAX when unknown.
 * @param altitude [mm] Altitude (MSL). Positive for up. Note that virtually all GPS modules provide both WGS84 and MSL. INT32_MAX when unknown.
 * @param relative_alt [mm] Altitude above ground. INT32_MAX when unknown.
 * @param geoid_alt [mm] Altitude relative to WGS84 geoid. INT32_MAX when unknown.
 * @param x [m] Local X position of this position in the local coordinate NED frame. NaN when unknown.
 * @param y [m] Local Y position of this position in the local coordinate NED frame. NaN when unknown.
 * @param z [m] Local Z position of this position in the local coordinate NED frame. NaN when unknown.
 * @param yaw [rad] World to surface heading transformation of the return-from-exploration position. Used to indicate the heading with respect to the ground. NaN when unknown.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_exploration_return_position_send(mavlink_channel_t chan, uint64_t time_usec, int32_t latitude, int32_t longitude, int32_t altitude, int32_t relative_alt, int32_t geoid_alt, float x, float y, float z, float yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int32_t(buf, 8, latitude);
    _mav_put_int32_t(buf, 12, longitude);
    _mav_put_int32_t(buf, 16, altitude);
    _mav_put_int32_t(buf, 20, relative_alt);
    _mav_put_int32_t(buf, 24, geoid_alt);
    _mav_put_float(buf, 28, x);
    _mav_put_float(buf, 32, y);
    _mav_put_float(buf, 36, z);
    _mav_put_float(buf, 40, yaw);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION, buf, MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION_MIN_LEN, MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION_LEN, MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION_CRC);
#else
    mavlink_exploration_return_position_t packet;
    packet.time_usec = time_usec;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.altitude = altitude;
    packet.relative_alt = relative_alt;
    packet.geoid_alt = geoid_alt;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.yaw = yaw;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION, (const char *)&packet, MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION_MIN_LEN, MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION_LEN, MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION_CRC);
#endif
}

/**
 * @brief Send a exploration_return_position message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_exploration_return_position_send_struct(mavlink_channel_t chan, const mavlink_exploration_return_position_t* exploration_return_position)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_exploration_return_position_send(chan, exploration_return_position->time_usec, exploration_return_position->latitude, exploration_return_position->longitude, exploration_return_position->altitude, exploration_return_position->relative_alt, exploration_return_position->geoid_alt, exploration_return_position->x, exploration_return_position->y, exploration_return_position->z, exploration_return_position->yaw);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION, (const char *)exploration_return_position, MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION_MIN_LEN, MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION_LEN, MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION_CRC);
#endif
}

#if MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_exploration_return_position_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, int32_t latitude, int32_t longitude, int32_t altitude, int32_t relative_alt, int32_t geoid_alt, float x, float y, float z, float yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int32_t(buf, 8, latitude);
    _mav_put_int32_t(buf, 12, longitude);
    _mav_put_int32_t(buf, 16, altitude);
    _mav_put_int32_t(buf, 20, relative_alt);
    _mav_put_int32_t(buf, 24, geoid_alt);
    _mav_put_float(buf, 28, x);
    _mav_put_float(buf, 32, y);
    _mav_put_float(buf, 36, z);
    _mav_put_float(buf, 40, yaw);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION, buf, MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION_MIN_LEN, MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION_LEN, MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION_CRC);
#else
    mavlink_exploration_return_position_t *packet = (mavlink_exploration_return_position_t *)msgbuf;
    packet->time_usec = time_usec;
    packet->latitude = latitude;
    packet->longitude = longitude;
    packet->altitude = altitude;
    packet->relative_alt = relative_alt;
    packet->geoid_alt = geoid_alt;
    packet->x = x;
    packet->y = y;
    packet->z = z;
    packet->yaw = yaw;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION, (const char *)packet, MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION_MIN_LEN, MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION_LEN, MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION_CRC);
#endif
}
#endif

#endif

// MESSAGE EXPLORATION_RETURN_POSITION UNPACKING


/**
 * @brief Get field time_usec from exploration_return_position message
 *
 * @return [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 */
static inline uint64_t mavlink_msg_exploration_return_position_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field latitude from exploration_return_position message
 *
 * @return [degE7] Latitude (WGS84). INT32_MAX when unknown.
 */
static inline int32_t mavlink_msg_exploration_return_position_get_latitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field longitude from exploration_return_position message
 *
 * @return [degE7] Longitude (WGS84). INT32_MAX when unknown.
 */
static inline int32_t mavlink_msg_exploration_return_position_get_longitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field altitude from exploration_return_position message
 *
 * @return [mm] Altitude (MSL). Positive for up. Note that virtually all GPS modules provide both WGS84 and MSL. INT32_MAX when unknown.
 */
static inline int32_t mavlink_msg_exploration_return_position_get_altitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field relative_alt from exploration_return_position message
 *
 * @return [mm] Altitude above ground. INT32_MAX when unknown.
 */
static inline int32_t mavlink_msg_exploration_return_position_get_relative_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  20);
}

/**
 * @brief Get field geoid_alt from exploration_return_position message
 *
 * @return [mm] Altitude relative to WGS84 geoid. INT32_MAX when unknown.
 */
static inline int32_t mavlink_msg_exploration_return_position_get_geoid_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  24);
}

/**
 * @brief Get field x from exploration_return_position message
 *
 * @return [m] Local X position of this position in the local coordinate NED frame. NaN when unknown.
 */
static inline float mavlink_msg_exploration_return_position_get_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field y from exploration_return_position message
 *
 * @return [m] Local Y position of this position in the local coordinate NED frame. NaN when unknown.
 */
static inline float mavlink_msg_exploration_return_position_get_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field z from exploration_return_position message
 *
 * @return [m] Local Z position of this position in the local coordinate NED frame. NaN when unknown.
 */
static inline float mavlink_msg_exploration_return_position_get_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field yaw from exploration_return_position message
 *
 * @return [rad] World to surface heading transformation of the return-from-exploration position. Used to indicate the heading with respect to the ground. NaN when unknown.
 */
static inline float mavlink_msg_exploration_return_position_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Decode a exploration_return_position message into a struct
 *
 * @param msg The message to decode
 * @param exploration_return_position C-struct to decode the message contents into
 */
static inline void mavlink_msg_exploration_return_position_decode(const mavlink_message_t* msg, mavlink_exploration_return_position_t* exploration_return_position)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    exploration_return_position->time_usec = mavlink_msg_exploration_return_position_get_time_usec(msg);
    exploration_return_position->latitude = mavlink_msg_exploration_return_position_get_latitude(msg);
    exploration_return_position->longitude = mavlink_msg_exploration_return_position_get_longitude(msg);
    exploration_return_position->altitude = mavlink_msg_exploration_return_position_get_altitude(msg);
    exploration_return_position->relative_alt = mavlink_msg_exploration_return_position_get_relative_alt(msg);
    exploration_return_position->geoid_alt = mavlink_msg_exploration_return_position_get_geoid_alt(msg);
    exploration_return_position->x = mavlink_msg_exploration_return_position_get_x(msg);
    exploration_return_position->y = mavlink_msg_exploration_return_position_get_y(msg);
    exploration_return_position->z = mavlink_msg_exploration_return_position_get_z(msg);
    exploration_return_position->yaw = mavlink_msg_exploration_return_position_get_yaw(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION_LEN? msg->len : MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION_LEN;
        memset(exploration_return_position, 0, MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION_LEN);
    memcpy(exploration_return_position, _MAV_PAYLOAD(msg), len);
#endif
}
