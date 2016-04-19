// MESSAGE WIND PACKING

#define MAVLINK_MSG_ID_WIND 231

typedef struct __mavlink_wind_t
{
 uint64_t time_usec; /*< Timestamp (micros since boot or Unix epoch)*/
 float wind_x; /*< Wind in X (NED) direction in m/s*/
 float wind_y; /*< Wind in Y (NED) direction in m/s*/
 float wind_z; /*< Wind in Z (NED) direction in m/s*/
 float var_horiz; /*< Variability of the wind in XY. RMS of a 1 Hz lowpassed wind estimate.*/
 float var_vert; /*< Variability of the wind in Z. RMS of a 1 Hz lowpassed wind estimate.*/
 float wind_alt; /*< AMSL altitude (m) this measurement was taken at*/
 float pos_horiz_accuracy; /*< Horizontal position 1-STD accuracy relative to the EKF local origin (m)*/
 float pos_vert_accuracy; /*< Vertical position 1-STD accuracy relative to the EKF local origin (m)*/
} mavlink_wind_t;

#define MAVLINK_MSG_ID_WIND_LEN 40
#define MAVLINK_MSG_ID_231_LEN 40

#define MAVLINK_MSG_ID_WIND_CRC 24
#define MAVLINK_MSG_ID_231_CRC 24



#define MAVLINK_MESSAGE_INFO_WIND { \
	"WIND", \
	9, \
	{  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_wind_t, time_usec) }, \
         { "wind_x", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_wind_t, wind_x) }, \
         { "wind_y", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_wind_t, wind_y) }, \
         { "wind_z", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_wind_t, wind_z) }, \
         { "var_horiz", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_wind_t, var_horiz) }, \
         { "var_vert", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_wind_t, var_vert) }, \
         { "wind_alt", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_wind_t, wind_alt) }, \
         { "pos_horiz_accuracy", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_wind_t, pos_horiz_accuracy) }, \
         { "pos_vert_accuracy", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_wind_t, pos_vert_accuracy) }, \
         } \
}


/**
 * @brief Pack a wind message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Timestamp (micros since boot or Unix epoch)
 * @param wind_x Wind in X (NED) direction in m/s
 * @param wind_y Wind in Y (NED) direction in m/s
 * @param wind_z Wind in Z (NED) direction in m/s
 * @param var_horiz Variability of the wind in XY. RMS of a 1 Hz lowpassed wind estimate.
 * @param var_vert Variability of the wind in Z. RMS of a 1 Hz lowpassed wind estimate.
 * @param wind_alt AMSL altitude (m) this measurement was taken at
 * @param pos_horiz_accuracy Horizontal position 1-STD accuracy relative to the EKF local origin (m)
 * @param pos_vert_accuracy Vertical position 1-STD accuracy relative to the EKF local origin (m)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wind_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t time_usec, float wind_x, float wind_y, float wind_z, float var_horiz, float var_vert, float wind_alt, float pos_horiz_accuracy, float pos_vert_accuracy)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_WIND_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_float(buf, 8, wind_x);
	_mav_put_float(buf, 12, wind_y);
	_mav_put_float(buf, 16, wind_z);
	_mav_put_float(buf, 20, var_horiz);
	_mav_put_float(buf, 24, var_vert);
	_mav_put_float(buf, 28, wind_alt);
	_mav_put_float(buf, 32, pos_horiz_accuracy);
	_mav_put_float(buf, 36, pos_vert_accuracy);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WIND_LEN);
#else
	mavlink_wind_t packet;
	packet.time_usec = time_usec;
	packet.wind_x = wind_x;
	packet.wind_y = wind_y;
	packet.wind_z = wind_z;
	packet.var_horiz = var_horiz;
	packet.var_vert = var_vert;
	packet.wind_alt = wind_alt;
	packet.pos_horiz_accuracy = pos_horiz_accuracy;
	packet.pos_vert_accuracy = pos_vert_accuracy;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WIND_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_WIND;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WIND_LEN, MAVLINK_MSG_ID_WIND_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WIND_LEN);
#endif
}

/**
 * @brief Pack a wind message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Timestamp (micros since boot or Unix epoch)
 * @param wind_x Wind in X (NED) direction in m/s
 * @param wind_y Wind in Y (NED) direction in m/s
 * @param wind_z Wind in Z (NED) direction in m/s
 * @param var_horiz Variability of the wind in XY. RMS of a 1 Hz lowpassed wind estimate.
 * @param var_vert Variability of the wind in Z. RMS of a 1 Hz lowpassed wind estimate.
 * @param wind_alt AMSL altitude (m) this measurement was taken at
 * @param pos_horiz_accuracy Horizontal position 1-STD accuracy relative to the EKF local origin (m)
 * @param pos_vert_accuracy Vertical position 1-STD accuracy relative to the EKF local origin (m)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wind_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint64_t time_usec,float wind_x,float wind_y,float wind_z,float var_horiz,float var_vert,float wind_alt,float pos_horiz_accuracy,float pos_vert_accuracy)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_WIND_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_float(buf, 8, wind_x);
	_mav_put_float(buf, 12, wind_y);
	_mav_put_float(buf, 16, wind_z);
	_mav_put_float(buf, 20, var_horiz);
	_mav_put_float(buf, 24, var_vert);
	_mav_put_float(buf, 28, wind_alt);
	_mav_put_float(buf, 32, pos_horiz_accuracy);
	_mav_put_float(buf, 36, pos_vert_accuracy);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WIND_LEN);
#else
	mavlink_wind_t packet;
	packet.time_usec = time_usec;
	packet.wind_x = wind_x;
	packet.wind_y = wind_y;
	packet.wind_z = wind_z;
	packet.var_horiz = var_horiz;
	packet.var_vert = var_vert;
	packet.wind_alt = wind_alt;
	packet.pos_horiz_accuracy = pos_horiz_accuracy;
	packet.pos_vert_accuracy = pos_vert_accuracy;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WIND_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_WIND;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WIND_LEN, MAVLINK_MSG_ID_WIND_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WIND_LEN);
#endif
}

/**
 * @brief Encode a wind struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wind C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wind_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wind_t* wind)
{
	return mavlink_msg_wind_pack(system_id, component_id, msg, wind->time_usec, wind->wind_x, wind->wind_y, wind->wind_z, wind->var_horiz, wind->var_vert, wind->wind_alt, wind->pos_horiz_accuracy, wind->pos_vert_accuracy);
}

/**
 * @brief Encode a wind struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wind C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wind_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wind_t* wind)
{
	return mavlink_msg_wind_pack_chan(system_id, component_id, chan, msg, wind->time_usec, wind->wind_x, wind->wind_y, wind->wind_z, wind->var_horiz, wind->var_vert, wind->wind_alt, wind->pos_horiz_accuracy, wind->pos_vert_accuracy);
}

/**
 * @brief Send a wind message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec Timestamp (micros since boot or Unix epoch)
 * @param wind_x Wind in X (NED) direction in m/s
 * @param wind_y Wind in Y (NED) direction in m/s
 * @param wind_z Wind in Z (NED) direction in m/s
 * @param var_horiz Variability of the wind in XY. RMS of a 1 Hz lowpassed wind estimate.
 * @param var_vert Variability of the wind in Z. RMS of a 1 Hz lowpassed wind estimate.
 * @param wind_alt AMSL altitude (m) this measurement was taken at
 * @param pos_horiz_accuracy Horizontal position 1-STD accuracy relative to the EKF local origin (m)
 * @param pos_vert_accuracy Vertical position 1-STD accuracy relative to the EKF local origin (m)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wind_send(mavlink_channel_t chan, uint64_t time_usec, float wind_x, float wind_y, float wind_z, float var_horiz, float var_vert, float wind_alt, float pos_horiz_accuracy, float pos_vert_accuracy)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_WIND_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_float(buf, 8, wind_x);
	_mav_put_float(buf, 12, wind_y);
	_mav_put_float(buf, 16, wind_z);
	_mav_put_float(buf, 20, var_horiz);
	_mav_put_float(buf, 24, var_vert);
	_mav_put_float(buf, 28, wind_alt);
	_mav_put_float(buf, 32, pos_horiz_accuracy);
	_mav_put_float(buf, 36, pos_vert_accuracy);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIND, buf, MAVLINK_MSG_ID_WIND_LEN, MAVLINK_MSG_ID_WIND_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIND, buf, MAVLINK_MSG_ID_WIND_LEN);
#endif
#else
	mavlink_wind_t packet;
	packet.time_usec = time_usec;
	packet.wind_x = wind_x;
	packet.wind_y = wind_y;
	packet.wind_z = wind_z;
	packet.var_horiz = var_horiz;
	packet.var_vert = var_vert;
	packet.wind_alt = wind_alt;
	packet.pos_horiz_accuracy = pos_horiz_accuracy;
	packet.pos_vert_accuracy = pos_vert_accuracy;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIND, (const char *)&packet, MAVLINK_MSG_ID_WIND_LEN, MAVLINK_MSG_ID_WIND_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIND, (const char *)&packet, MAVLINK_MSG_ID_WIND_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_WIND_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wind_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, float wind_x, float wind_y, float wind_z, float var_horiz, float var_vert, float wind_alt, float pos_horiz_accuracy, float pos_vert_accuracy)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_float(buf, 8, wind_x);
	_mav_put_float(buf, 12, wind_y);
	_mav_put_float(buf, 16, wind_z);
	_mav_put_float(buf, 20, var_horiz);
	_mav_put_float(buf, 24, var_vert);
	_mav_put_float(buf, 28, wind_alt);
	_mav_put_float(buf, 32, pos_horiz_accuracy);
	_mav_put_float(buf, 36, pos_vert_accuracy);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIND, buf, MAVLINK_MSG_ID_WIND_LEN, MAVLINK_MSG_ID_WIND_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIND, buf, MAVLINK_MSG_ID_WIND_LEN);
#endif
#else
	mavlink_wind_t *packet = (mavlink_wind_t *)msgbuf;
	packet->time_usec = time_usec;
	packet->wind_x = wind_x;
	packet->wind_y = wind_y;
	packet->wind_z = wind_z;
	packet->var_horiz = var_horiz;
	packet->var_vert = var_vert;
	packet->wind_alt = wind_alt;
	packet->pos_horiz_accuracy = pos_horiz_accuracy;
	packet->pos_vert_accuracy = pos_vert_accuracy;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIND, (const char *)packet, MAVLINK_MSG_ID_WIND_LEN, MAVLINK_MSG_ID_WIND_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIND, (const char *)packet, MAVLINK_MSG_ID_WIND_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE WIND UNPACKING


/**
 * @brief Get field time_usec from wind message
 *
 * @return Timestamp (micros since boot or Unix epoch)
 */
static inline uint64_t mavlink_msg_wind_get_time_usec(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field wind_x from wind message
 *
 * @return Wind in X (NED) direction in m/s
 */
static inline float mavlink_msg_wind_get_wind_x(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field wind_y from wind message
 *
 * @return Wind in Y (NED) direction in m/s
 */
static inline float mavlink_msg_wind_get_wind_y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field wind_z from wind message
 *
 * @return Wind in Z (NED) direction in m/s
 */
static inline float mavlink_msg_wind_get_wind_z(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field var_horiz from wind message
 *
 * @return Variability of the wind in XY. RMS of a 1 Hz lowpassed wind estimate.
 */
static inline float mavlink_msg_wind_get_var_horiz(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field var_vert from wind message
 *
 * @return Variability of the wind in Z. RMS of a 1 Hz lowpassed wind estimate.
 */
static inline float mavlink_msg_wind_get_var_vert(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field wind_alt from wind message
 *
 * @return AMSL altitude (m) this measurement was taken at
 */
static inline float mavlink_msg_wind_get_wind_alt(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field pos_horiz_accuracy from wind message
 *
 * @return Horizontal position 1-STD accuracy relative to the EKF local origin (m)
 */
static inline float mavlink_msg_wind_get_pos_horiz_accuracy(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field pos_vert_accuracy from wind message
 *
 * @return Vertical position 1-STD accuracy relative to the EKF local origin (m)
 */
static inline float mavlink_msg_wind_get_pos_vert_accuracy(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Decode a wind message into a struct
 *
 * @param msg The message to decode
 * @param wind C-struct to decode the message contents into
 */
static inline void mavlink_msg_wind_decode(const mavlink_message_t* msg, mavlink_wind_t* wind)
{
#if MAVLINK_NEED_BYTE_SWAP
	wind->time_usec = mavlink_msg_wind_get_time_usec(msg);
	wind->wind_x = mavlink_msg_wind_get_wind_x(msg);
	wind->wind_y = mavlink_msg_wind_get_wind_y(msg);
	wind->wind_z = mavlink_msg_wind_get_wind_z(msg);
	wind->var_horiz = mavlink_msg_wind_get_var_horiz(msg);
	wind->var_vert = mavlink_msg_wind_get_var_vert(msg);
	wind->wind_alt = mavlink_msg_wind_get_wind_alt(msg);
	wind->pos_horiz_accuracy = mavlink_msg_wind_get_pos_horiz_accuracy(msg);
	wind->pos_vert_accuracy = mavlink_msg_wind_get_pos_vert_accuracy(msg);
#else
	memcpy(wind, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_WIND_LEN);
#endif
}
