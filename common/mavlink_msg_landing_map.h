// MESSAGE LANDING_MAP PACKING

#define MAVLINK_MSG_ID_LANDING_MAP 240

MAVPACKED(
typedef struct __mavlink_landing_map_t {
 uint64_t time_usec; /*< Timestamp (micros since boot or Unix epoch)*/
 float best_x; /*< Best landing position on X-axis*/
 float best_y; /*< Best landing position on Y-axis*/
 float best_z; /*< Best landing position on Z-axis*/
 float local_x; /*< Position on X-axis*/
 float local_y; /*< Position on Y-axis*/
 float local_z; /*< Position on Z-axis*/
 uint8_t factors[169]; /*< LSB 0-2: Score between 0 and 7, LSB 3-7: Distance to the vehicle in meters.*/
}) mavlink_landing_map_t;

#define MAVLINK_MSG_ID_LANDING_MAP_LEN 201
#define MAVLINK_MSG_ID_LANDING_MAP_MIN_LEN 201
#define MAVLINK_MSG_ID_240_LEN 201
#define MAVLINK_MSG_ID_240_MIN_LEN 201

#define MAVLINK_MSG_ID_LANDING_MAP_CRC 138
#define MAVLINK_MSG_ID_240_CRC 138

#define MAVLINK_MSG_LANDING_MAP_FIELD_FACTORS_LEN 169

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_LANDING_MAP { \
	240, \
	"LANDING_MAP", \
	8, \
	{  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_landing_map_t, time_usec) }, \
         { "best_x", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_landing_map_t, best_x) }, \
         { "best_y", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_landing_map_t, best_y) }, \
         { "best_z", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_landing_map_t, best_z) }, \
         { "local_x", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_landing_map_t, local_x) }, \
         { "local_y", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_landing_map_t, local_y) }, \
         { "local_z", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_landing_map_t, local_z) }, \
         { "factors", NULL, MAVLINK_TYPE_UINT8_T, 169, 32, offsetof(mavlink_landing_map_t, factors) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_LANDING_MAP { \
	"LANDING_MAP", \
	8, \
	{  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_landing_map_t, time_usec) }, \
         { "best_x", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_landing_map_t, best_x) }, \
         { "best_y", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_landing_map_t, best_y) }, \
         { "best_z", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_landing_map_t, best_z) }, \
         { "local_x", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_landing_map_t, local_x) }, \
         { "local_y", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_landing_map_t, local_y) }, \
         { "local_z", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_landing_map_t, local_z) }, \
         { "factors", NULL, MAVLINK_TYPE_UINT8_T, 169, 32, offsetof(mavlink_landing_map_t, factors) }, \
         } \
}
#endif

/**
 * @brief Pack a landing_map message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Timestamp (micros since boot or Unix epoch)
 * @param best_x Best landing position on X-axis
 * @param best_y Best landing position on Y-axis
 * @param best_z Best landing position on Z-axis
 * @param local_x Position on X-axis
 * @param local_y Position on Y-axis
 * @param local_z Position on Z-axis
 * @param factors LSB 0-2: Score between 0 and 7, LSB 3-7: Distance to the vehicle in meters.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_landing_map_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t time_usec, float best_x, float best_y, float best_z, float local_x, float local_y, float local_z, const uint8_t *factors)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_LANDING_MAP_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_float(buf, 8, best_x);
	_mav_put_float(buf, 12, best_y);
	_mav_put_float(buf, 16, best_z);
	_mav_put_float(buf, 20, local_x);
	_mav_put_float(buf, 24, local_y);
	_mav_put_float(buf, 28, local_z);
	_mav_put_uint8_t_array(buf, 32, factors, 169);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LANDING_MAP_LEN);
#else
	mavlink_landing_map_t packet;
	packet.time_usec = time_usec;
	packet.best_x = best_x;
	packet.best_y = best_y;
	packet.best_z = best_z;
	packet.local_x = local_x;
	packet.local_y = local_y;
	packet.local_z = local_z;
	mav_array_memcpy(packet.factors, factors, sizeof(uint8_t)*169);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LANDING_MAP_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_LANDING_MAP;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_LANDING_MAP_MIN_LEN, MAVLINK_MSG_ID_LANDING_MAP_LEN, MAVLINK_MSG_ID_LANDING_MAP_CRC);
}

/**
 * @brief Pack a landing_map message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Timestamp (micros since boot or Unix epoch)
 * @param best_x Best landing position on X-axis
 * @param best_y Best landing position on Y-axis
 * @param best_z Best landing position on Z-axis
 * @param local_x Position on X-axis
 * @param local_y Position on Y-axis
 * @param local_z Position on Z-axis
 * @param factors LSB 0-2: Score between 0 and 7, LSB 3-7: Distance to the vehicle in meters.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_landing_map_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint64_t time_usec,float best_x,float best_y,float best_z,float local_x,float local_y,float local_z,const uint8_t *factors)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_LANDING_MAP_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_float(buf, 8, best_x);
	_mav_put_float(buf, 12, best_y);
	_mav_put_float(buf, 16, best_z);
	_mav_put_float(buf, 20, local_x);
	_mav_put_float(buf, 24, local_y);
	_mav_put_float(buf, 28, local_z);
	_mav_put_uint8_t_array(buf, 32, factors, 169);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LANDING_MAP_LEN);
#else
	mavlink_landing_map_t packet;
	packet.time_usec = time_usec;
	packet.best_x = best_x;
	packet.best_y = best_y;
	packet.best_z = best_z;
	packet.local_x = local_x;
	packet.local_y = local_y;
	packet.local_z = local_z;
	mav_array_memcpy(packet.factors, factors, sizeof(uint8_t)*169);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LANDING_MAP_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_LANDING_MAP;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_LANDING_MAP_MIN_LEN, MAVLINK_MSG_ID_LANDING_MAP_LEN, MAVLINK_MSG_ID_LANDING_MAP_CRC);
}

/**
 * @brief Encode a landing_map struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param landing_map C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_landing_map_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_landing_map_t* landing_map)
{
	return mavlink_msg_landing_map_pack(system_id, component_id, msg, landing_map->time_usec, landing_map->best_x, landing_map->best_y, landing_map->best_z, landing_map->local_x, landing_map->local_y, landing_map->local_z, landing_map->factors);
}

/**
 * @brief Encode a landing_map struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param landing_map C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_landing_map_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_landing_map_t* landing_map)
{
	return mavlink_msg_landing_map_pack_chan(system_id, component_id, chan, msg, landing_map->time_usec, landing_map->best_x, landing_map->best_y, landing_map->best_z, landing_map->local_x, landing_map->local_y, landing_map->local_z, landing_map->factors);
}

/**
 * @brief Send a landing_map message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec Timestamp (micros since boot or Unix epoch)
 * @param best_x Best landing position on X-axis
 * @param best_y Best landing position on Y-axis
 * @param best_z Best landing position on Z-axis
 * @param local_x Position on X-axis
 * @param local_y Position on Y-axis
 * @param local_z Position on Z-axis
 * @param factors LSB 0-2: Score between 0 and 7, LSB 3-7: Distance to the vehicle in meters.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_landing_map_send(mavlink_channel_t chan, uint64_t time_usec, float best_x, float best_y, float best_z, float local_x, float local_y, float local_z, const uint8_t *factors)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_LANDING_MAP_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_float(buf, 8, best_x);
	_mav_put_float(buf, 12, best_y);
	_mav_put_float(buf, 16, best_z);
	_mav_put_float(buf, 20, local_x);
	_mav_put_float(buf, 24, local_y);
	_mav_put_float(buf, 28, local_z);
	_mav_put_uint8_t_array(buf, 32, factors, 169);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LANDING_MAP, buf, MAVLINK_MSG_ID_LANDING_MAP_MIN_LEN, MAVLINK_MSG_ID_LANDING_MAP_LEN, MAVLINK_MSG_ID_LANDING_MAP_CRC);
#else
	mavlink_landing_map_t packet;
	packet.time_usec = time_usec;
	packet.best_x = best_x;
	packet.best_y = best_y;
	packet.best_z = best_z;
	packet.local_x = local_x;
	packet.local_y = local_y;
	packet.local_z = local_z;
	mav_array_memcpy(packet.factors, factors, sizeof(uint8_t)*169);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LANDING_MAP, (const char *)&packet, MAVLINK_MSG_ID_LANDING_MAP_MIN_LEN, MAVLINK_MSG_ID_LANDING_MAP_LEN, MAVLINK_MSG_ID_LANDING_MAP_CRC);
#endif
}

/**
 * @brief Send a landing_map message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_landing_map_send_struct(mavlink_channel_t chan, const mavlink_landing_map_t* landing_map)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_landing_map_send(chan, landing_map->time_usec, landing_map->best_x, landing_map->best_y, landing_map->best_z, landing_map->local_x, landing_map->local_y, landing_map->local_z, landing_map->factors);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LANDING_MAP, (const char *)landing_map, MAVLINK_MSG_ID_LANDING_MAP_MIN_LEN, MAVLINK_MSG_ID_LANDING_MAP_LEN, MAVLINK_MSG_ID_LANDING_MAP_CRC);
#endif
}

#if MAVLINK_MSG_ID_LANDING_MAP_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_landing_map_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, float best_x, float best_y, float best_z, float local_x, float local_y, float local_z, const uint8_t *factors)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_float(buf, 8, best_x);
	_mav_put_float(buf, 12, best_y);
	_mav_put_float(buf, 16, best_z);
	_mav_put_float(buf, 20, local_x);
	_mav_put_float(buf, 24, local_y);
	_mav_put_float(buf, 28, local_z);
	_mav_put_uint8_t_array(buf, 32, factors, 169);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LANDING_MAP, buf, MAVLINK_MSG_ID_LANDING_MAP_MIN_LEN, MAVLINK_MSG_ID_LANDING_MAP_LEN, MAVLINK_MSG_ID_LANDING_MAP_CRC);
#else
	mavlink_landing_map_t *packet = (mavlink_landing_map_t *)msgbuf;
	packet->time_usec = time_usec;
	packet->best_x = best_x;
	packet->best_y = best_y;
	packet->best_z = best_z;
	packet->local_x = local_x;
	packet->local_y = local_y;
	packet->local_z = local_z;
	mav_array_memcpy(packet->factors, factors, sizeof(uint8_t)*169);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LANDING_MAP, (const char *)packet, MAVLINK_MSG_ID_LANDING_MAP_MIN_LEN, MAVLINK_MSG_ID_LANDING_MAP_LEN, MAVLINK_MSG_ID_LANDING_MAP_CRC);
#endif
}
#endif

#endif

// MESSAGE LANDING_MAP UNPACKING


/**
 * @brief Get field time_usec from landing_map message
 *
 * @return Timestamp (micros since boot or Unix epoch)
 */
static inline uint64_t mavlink_msg_landing_map_get_time_usec(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field best_x from landing_map message
 *
 * @return Best landing position on X-axis
 */
static inline float mavlink_msg_landing_map_get_best_x(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field best_y from landing_map message
 *
 * @return Best landing position on Y-axis
 */
static inline float mavlink_msg_landing_map_get_best_y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field best_z from landing_map message
 *
 * @return Best landing position on Z-axis
 */
static inline float mavlink_msg_landing_map_get_best_z(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field local_x from landing_map message
 *
 * @return Position on X-axis
 */
static inline float mavlink_msg_landing_map_get_local_x(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field local_y from landing_map message
 *
 * @return Position on Y-axis
 */
static inline float mavlink_msg_landing_map_get_local_y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field local_z from landing_map message
 *
 * @return Position on Z-axis
 */
static inline float mavlink_msg_landing_map_get_local_z(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field factors from landing_map message
 *
 * @return LSB 0-2: Score between 0 and 7, LSB 3-7: Distance to the vehicle in meters.
 */
static inline uint16_t mavlink_msg_landing_map_get_factors(const mavlink_message_t* msg, uint8_t *factors)
{
	return _MAV_RETURN_uint8_t_array(msg, factors, 169,  32);
}

/**
 * @brief Decode a landing_map message into a struct
 *
 * @param msg The message to decode
 * @param landing_map C-struct to decode the message contents into
 */
static inline void mavlink_msg_landing_map_decode(const mavlink_message_t* msg, mavlink_landing_map_t* landing_map)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	landing_map->time_usec = mavlink_msg_landing_map_get_time_usec(msg);
	landing_map->best_x = mavlink_msg_landing_map_get_best_x(msg);
	landing_map->best_y = mavlink_msg_landing_map_get_best_y(msg);
	landing_map->best_z = mavlink_msg_landing_map_get_best_z(msg);
	landing_map->local_x = mavlink_msg_landing_map_get_local_x(msg);
	landing_map->local_y = mavlink_msg_landing_map_get_local_y(msg);
	landing_map->local_z = mavlink_msg_landing_map_get_local_z(msg);
	mavlink_msg_landing_map_get_factors(msg, landing_map->factors);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_LANDING_MAP_LEN? msg->len : MAVLINK_MSG_ID_LANDING_MAP_LEN;
        memset(landing_map, 0, MAVLINK_MSG_ID_LANDING_MAP_LEN);
	memcpy(landing_map, _MAV_PAYLOAD(msg), len);
#endif
}
