#pragma once
// MESSAGE EXPLORATION_INFO PACKING

#define MAVLINK_MSG_ID_EXPLORATION_INFO 451


typedef struct __mavlink_exploration_info_t {
 uint32_t time_limit; /*< [s] Time limit to execute the exploration. Reaching this time triggers the behavior defined in the behaviour_after_stopping field. Set to 0 when the exploration time is not limited.*/
 int32_t boundaries_p1_lat; /*< [degE7] Exploration cuboid boundaries point 1 Latitude (WGS84). INT32_MAX if unknown. p1_lat == p3_lat.*/
 int32_t boundaries_p1_lon; /*< [degE7] Exploration cuboid boundaries point 1 Longitude (WGS84). INT32_MAX if unknown. p1_lat == p3_lat.*/
 float boundaries_p1_alt; /*< [m] Exploration cuboid boundaries point 1 Altitude (MSL). NaN if unknown. p1_alt == p2_alt.*/
 float boundaries_p1_x; /*< [m] Exploration cuboid boundaries point 1 local NED X coordinate. NaN if unknown. p1_x == p3_x.*/
 float boundaries_p1_y; /*< [m] Exploration cuboid boundaries point 1 local NED Y coordinate. NaN if unknown. p1_y == p3_y.*/
 float boundaries_p1_z; /*< [m] Exploration cuboid boundaries point 1 local NED Z coordinate. NaN if unknown. p1_z == p2_z.*/
 int32_t boundaries_p2_lat; /*< [degE7] Exploration cuboid boundaries point 2 Latitude (WGS84). INT32_MAX if unknown.*/
 int32_t boundaries_p2_lon; /*< [degE7] Exploration cuboid boundaries point 2 Longitude (WGS84). INT32_MAX if unknown.*/
 float boundaries_p2_x; /*< [m] Exploration cuboid boundaries point 2 local NED X coordinate. NaN if unknown.*/
 float boundaries_p2_y; /*< [m] Exploration cuboid boundaries point 2 local NED Y coordinate. NaN if unknown.*/
 float boundaries_p3_alt; /*< [m] Exploration cuboid boundaries point 3 Altitude (MSL). NaN if unknown.*/
 float boundaries_p3_z; /*< [m] Exploration cuboid boundaries point 3 local NED Z coordinate. NaN if unknown.*/
 uint32_t ingress_portal_id; /*<  Currently defined ingress portal ID. This portal ID can either be set by the system autonomy engine or by an offboard controller or operator using MAV_CMD_SET_INGRESS_PORTAL. When unknown, not applicable or not deterministic, set to UINT32_MAX.*/
 int32_t ingress_portal_lat; /*< [degE7] Currently defined ingress portal Latitude (WGS84). INT32_MAX if unknown, not applicable or when ingress_portal_id is set and different from UINT32_MAX.*/
 int32_t ingress_portal_lon; /*< [degE7] Currently defined ingress portal Longitude (WGS84). INT32_MAX if unknown, not applicable or when ingress_portal_id is set and different from UINT32_MAX.*/
 float ingress_portal_alt; /*< [m] Currently defined ingress portal Altitude (MSL). NaN if unknown, not applicable or when ingress_portal_id is set and different from UINT32_MAX.*/
 uint32_t egress_portal_id; /*<  Currently defined egress portal ID. This portal ID can either be set by the system autonomy engine or by an offboard controller or operator using MAV_CMD_SET_EGRESS_PORTAL. When unknown, not applicable or not deterministic, set to UINT32_MAX.*/
 int32_t egress_portal_lat; /*< [degE7] Currently defined egress portal Latitude (WGS84). INT32_MAX if unknown, not applicable or when egress_portal_id is set and different from UINT32_MAX.*/
 int32_t egress_portal_lon; /*< [degE7] Currently defined egress portal Longitude (WGS84). INT32_MAX if unknown, not applicable or when egress_portal_id is set and different from UINT32_MAX.*/
 float egress_portal_alt; /*< [m] Currently defined egress portal Altitude (MSL). NaN if unknown, not applicable or when egress_portal_id is set and different from UINT32_MAX.*/
 uint8_t exploration_id; /*<  ID of the exploration task. 255 to get the information of the current running exploration task.*/
 uint8_t behaviour_after_stopping; /*<  The behavior after stopping the exploration task. 0: Hold, 1: Land, 2: Return (to exploration return position).*/
} mavlink_exploration_info_t;

#define MAVLINK_MSG_ID_EXPLORATION_INFO_LEN 86
#define MAVLINK_MSG_ID_EXPLORATION_INFO_MIN_LEN 86
#define MAVLINK_MSG_ID_451_LEN 86
#define MAVLINK_MSG_ID_451_MIN_LEN 86

#define MAVLINK_MSG_ID_EXPLORATION_INFO_CRC 147
#define MAVLINK_MSG_ID_451_CRC 147



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_EXPLORATION_INFO { \
    451, \
    "EXPLORATION_INFO", \
    23, \
    {  { "exploration_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 84, offsetof(mavlink_exploration_info_t, exploration_id) }, \
         { "time_limit", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_exploration_info_t, time_limit) }, \
         { "behaviour_after_stopping", NULL, MAVLINK_TYPE_UINT8_T, 0, 85, offsetof(mavlink_exploration_info_t, behaviour_after_stopping) }, \
         { "boundaries_p1_lat", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_exploration_info_t, boundaries_p1_lat) }, \
         { "boundaries_p1_lon", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_exploration_info_t, boundaries_p1_lon) }, \
         { "boundaries_p1_alt", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_exploration_info_t, boundaries_p1_alt) }, \
         { "boundaries_p1_x", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_exploration_info_t, boundaries_p1_x) }, \
         { "boundaries_p1_y", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_exploration_info_t, boundaries_p1_y) }, \
         { "boundaries_p1_z", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_exploration_info_t, boundaries_p1_z) }, \
         { "boundaries_p2_lat", NULL, MAVLINK_TYPE_INT32_T, 0, 28, offsetof(mavlink_exploration_info_t, boundaries_p2_lat) }, \
         { "boundaries_p2_lon", NULL, MAVLINK_TYPE_INT32_T, 0, 32, offsetof(mavlink_exploration_info_t, boundaries_p2_lon) }, \
         { "boundaries_p2_x", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_exploration_info_t, boundaries_p2_x) }, \
         { "boundaries_p2_y", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_exploration_info_t, boundaries_p2_y) }, \
         { "boundaries_p3_alt", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_exploration_info_t, boundaries_p3_alt) }, \
         { "boundaries_p3_z", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_exploration_info_t, boundaries_p3_z) }, \
         { "ingress_portal_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 52, offsetof(mavlink_exploration_info_t, ingress_portal_id) }, \
         { "ingress_portal_lat", NULL, MAVLINK_TYPE_INT32_T, 0, 56, offsetof(mavlink_exploration_info_t, ingress_portal_lat) }, \
         { "ingress_portal_lon", NULL, MAVLINK_TYPE_INT32_T, 0, 60, offsetof(mavlink_exploration_info_t, ingress_portal_lon) }, \
         { "ingress_portal_alt", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_exploration_info_t, ingress_portal_alt) }, \
         { "egress_portal_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 68, offsetof(mavlink_exploration_info_t, egress_portal_id) }, \
         { "egress_portal_lat", NULL, MAVLINK_TYPE_INT32_T, 0, 72, offsetof(mavlink_exploration_info_t, egress_portal_lat) }, \
         { "egress_portal_lon", NULL, MAVLINK_TYPE_INT32_T, 0, 76, offsetof(mavlink_exploration_info_t, egress_portal_lon) }, \
         { "egress_portal_alt", NULL, MAVLINK_TYPE_FLOAT, 0, 80, offsetof(mavlink_exploration_info_t, egress_portal_alt) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_EXPLORATION_INFO { \
    "EXPLORATION_INFO", \
    23, \
    {  { "exploration_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 84, offsetof(mavlink_exploration_info_t, exploration_id) }, \
         { "time_limit", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_exploration_info_t, time_limit) }, \
         { "behaviour_after_stopping", NULL, MAVLINK_TYPE_UINT8_T, 0, 85, offsetof(mavlink_exploration_info_t, behaviour_after_stopping) }, \
         { "boundaries_p1_lat", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_exploration_info_t, boundaries_p1_lat) }, \
         { "boundaries_p1_lon", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_exploration_info_t, boundaries_p1_lon) }, \
         { "boundaries_p1_alt", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_exploration_info_t, boundaries_p1_alt) }, \
         { "boundaries_p1_x", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_exploration_info_t, boundaries_p1_x) }, \
         { "boundaries_p1_y", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_exploration_info_t, boundaries_p1_y) }, \
         { "boundaries_p1_z", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_exploration_info_t, boundaries_p1_z) }, \
         { "boundaries_p2_lat", NULL, MAVLINK_TYPE_INT32_T, 0, 28, offsetof(mavlink_exploration_info_t, boundaries_p2_lat) }, \
         { "boundaries_p2_lon", NULL, MAVLINK_TYPE_INT32_T, 0, 32, offsetof(mavlink_exploration_info_t, boundaries_p2_lon) }, \
         { "boundaries_p2_x", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_exploration_info_t, boundaries_p2_x) }, \
         { "boundaries_p2_y", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_exploration_info_t, boundaries_p2_y) }, \
         { "boundaries_p3_alt", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_exploration_info_t, boundaries_p3_alt) }, \
         { "boundaries_p3_z", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_exploration_info_t, boundaries_p3_z) }, \
         { "ingress_portal_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 52, offsetof(mavlink_exploration_info_t, ingress_portal_id) }, \
         { "ingress_portal_lat", NULL, MAVLINK_TYPE_INT32_T, 0, 56, offsetof(mavlink_exploration_info_t, ingress_portal_lat) }, \
         { "ingress_portal_lon", NULL, MAVLINK_TYPE_INT32_T, 0, 60, offsetof(mavlink_exploration_info_t, ingress_portal_lon) }, \
         { "ingress_portal_alt", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_exploration_info_t, ingress_portal_alt) }, \
         { "egress_portal_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 68, offsetof(mavlink_exploration_info_t, egress_portal_id) }, \
         { "egress_portal_lat", NULL, MAVLINK_TYPE_INT32_T, 0, 72, offsetof(mavlink_exploration_info_t, egress_portal_lat) }, \
         { "egress_portal_lon", NULL, MAVLINK_TYPE_INT32_T, 0, 76, offsetof(mavlink_exploration_info_t, egress_portal_lon) }, \
         { "egress_portal_alt", NULL, MAVLINK_TYPE_FLOAT, 0, 80, offsetof(mavlink_exploration_info_t, egress_portal_alt) }, \
         } \
}
#endif

/**
 * @brief Pack a exploration_info message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param exploration_id  ID of the exploration task. 255 to get the information of the current running exploration task.
 * @param time_limit [s] Time limit to execute the exploration. Reaching this time triggers the behavior defined in the behaviour_after_stopping field. Set to 0 when the exploration time is not limited.
 * @param behaviour_after_stopping  The behavior after stopping the exploration task. 0: Hold, 1: Land, 2: Return (to exploration return position).
 * @param boundaries_p1_lat [degE7] Exploration cuboid boundaries point 1 Latitude (WGS84). INT32_MAX if unknown. p1_lat == p3_lat.
 * @param boundaries_p1_lon [degE7] Exploration cuboid boundaries point 1 Longitude (WGS84). INT32_MAX if unknown. p1_lat == p3_lat.
 * @param boundaries_p1_alt [m] Exploration cuboid boundaries point 1 Altitude (MSL). NaN if unknown. p1_alt == p2_alt.
 * @param boundaries_p1_x [m] Exploration cuboid boundaries point 1 local NED X coordinate. NaN if unknown. p1_x == p3_x.
 * @param boundaries_p1_y [m] Exploration cuboid boundaries point 1 local NED Y coordinate. NaN if unknown. p1_y == p3_y.
 * @param boundaries_p1_z [m] Exploration cuboid boundaries point 1 local NED Z coordinate. NaN if unknown. p1_z == p2_z.
 * @param boundaries_p2_lat [degE7] Exploration cuboid boundaries point 2 Latitude (WGS84). INT32_MAX if unknown.
 * @param boundaries_p2_lon [degE7] Exploration cuboid boundaries point 2 Longitude (WGS84). INT32_MAX if unknown.
 * @param boundaries_p2_x [m] Exploration cuboid boundaries point 2 local NED X coordinate. NaN if unknown.
 * @param boundaries_p2_y [m] Exploration cuboid boundaries point 2 local NED Y coordinate. NaN if unknown.
 * @param boundaries_p3_alt [m] Exploration cuboid boundaries point 3 Altitude (MSL). NaN if unknown.
 * @param boundaries_p3_z [m] Exploration cuboid boundaries point 3 local NED Z coordinate. NaN if unknown.
 * @param ingress_portal_id  Currently defined ingress portal ID. This portal ID can either be set by the system autonomy engine or by an offboard controller or operator using MAV_CMD_SET_INGRESS_PORTAL. When unknown, not applicable or not deterministic, set to UINT32_MAX.
 * @param ingress_portal_lat [degE7] Currently defined ingress portal Latitude (WGS84). INT32_MAX if unknown, not applicable or when ingress_portal_id is set and different from UINT32_MAX.
 * @param ingress_portal_lon [degE7] Currently defined ingress portal Longitude (WGS84). INT32_MAX if unknown, not applicable or when ingress_portal_id is set and different from UINT32_MAX.
 * @param ingress_portal_alt [m] Currently defined ingress portal Altitude (MSL). NaN if unknown, not applicable or when ingress_portal_id is set and different from UINT32_MAX.
 * @param egress_portal_id  Currently defined egress portal ID. This portal ID can either be set by the system autonomy engine or by an offboard controller or operator using MAV_CMD_SET_EGRESS_PORTAL. When unknown, not applicable or not deterministic, set to UINT32_MAX.
 * @param egress_portal_lat [degE7] Currently defined egress portal Latitude (WGS84). INT32_MAX if unknown, not applicable or when egress_portal_id is set and different from UINT32_MAX.
 * @param egress_portal_lon [degE7] Currently defined egress portal Longitude (WGS84). INT32_MAX if unknown, not applicable or when egress_portal_id is set and different from UINT32_MAX.
 * @param egress_portal_alt [m] Currently defined egress portal Altitude (MSL). NaN if unknown, not applicable or when egress_portal_id is set and different from UINT32_MAX.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_exploration_info_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t exploration_id, uint32_t time_limit, uint8_t behaviour_after_stopping, int32_t boundaries_p1_lat, int32_t boundaries_p1_lon, float boundaries_p1_alt, float boundaries_p1_x, float boundaries_p1_y, float boundaries_p1_z, int32_t boundaries_p2_lat, int32_t boundaries_p2_lon, float boundaries_p2_x, float boundaries_p2_y, float boundaries_p3_alt, float boundaries_p3_z, uint32_t ingress_portal_id, int32_t ingress_portal_lat, int32_t ingress_portal_lon, float ingress_portal_alt, uint32_t egress_portal_id, int32_t egress_portal_lat, int32_t egress_portal_lon, float egress_portal_alt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EXPLORATION_INFO_LEN];
    _mav_put_uint32_t(buf, 0, time_limit);
    _mav_put_int32_t(buf, 4, boundaries_p1_lat);
    _mav_put_int32_t(buf, 8, boundaries_p1_lon);
    _mav_put_float(buf, 12, boundaries_p1_alt);
    _mav_put_float(buf, 16, boundaries_p1_x);
    _mav_put_float(buf, 20, boundaries_p1_y);
    _mav_put_float(buf, 24, boundaries_p1_z);
    _mav_put_int32_t(buf, 28, boundaries_p2_lat);
    _mav_put_int32_t(buf, 32, boundaries_p2_lon);
    _mav_put_float(buf, 36, boundaries_p2_x);
    _mav_put_float(buf, 40, boundaries_p2_y);
    _mav_put_float(buf, 44, boundaries_p3_alt);
    _mav_put_float(buf, 48, boundaries_p3_z);
    _mav_put_uint32_t(buf, 52, ingress_portal_id);
    _mav_put_int32_t(buf, 56, ingress_portal_lat);
    _mav_put_int32_t(buf, 60, ingress_portal_lon);
    _mav_put_float(buf, 64, ingress_portal_alt);
    _mav_put_uint32_t(buf, 68, egress_portal_id);
    _mav_put_int32_t(buf, 72, egress_portal_lat);
    _mav_put_int32_t(buf, 76, egress_portal_lon);
    _mav_put_float(buf, 80, egress_portal_alt);
    _mav_put_uint8_t(buf, 84, exploration_id);
    _mav_put_uint8_t(buf, 85, behaviour_after_stopping);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EXPLORATION_INFO_LEN);
#else
    mavlink_exploration_info_t packet;
    packet.time_limit = time_limit;
    packet.boundaries_p1_lat = boundaries_p1_lat;
    packet.boundaries_p1_lon = boundaries_p1_lon;
    packet.boundaries_p1_alt = boundaries_p1_alt;
    packet.boundaries_p1_x = boundaries_p1_x;
    packet.boundaries_p1_y = boundaries_p1_y;
    packet.boundaries_p1_z = boundaries_p1_z;
    packet.boundaries_p2_lat = boundaries_p2_lat;
    packet.boundaries_p2_lon = boundaries_p2_lon;
    packet.boundaries_p2_x = boundaries_p2_x;
    packet.boundaries_p2_y = boundaries_p2_y;
    packet.boundaries_p3_alt = boundaries_p3_alt;
    packet.boundaries_p3_z = boundaries_p3_z;
    packet.ingress_portal_id = ingress_portal_id;
    packet.ingress_portal_lat = ingress_portal_lat;
    packet.ingress_portal_lon = ingress_portal_lon;
    packet.ingress_portal_alt = ingress_portal_alt;
    packet.egress_portal_id = egress_portal_id;
    packet.egress_portal_lat = egress_portal_lat;
    packet.egress_portal_lon = egress_portal_lon;
    packet.egress_portal_alt = egress_portal_alt;
    packet.exploration_id = exploration_id;
    packet.behaviour_after_stopping = behaviour_after_stopping;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EXPLORATION_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EXPLORATION_INFO;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_EXPLORATION_INFO_MIN_LEN, MAVLINK_MSG_ID_EXPLORATION_INFO_LEN, MAVLINK_MSG_ID_EXPLORATION_INFO_CRC);
}

/**
 * @brief Pack a exploration_info message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param exploration_id  ID of the exploration task. 255 to get the information of the current running exploration task.
 * @param time_limit [s] Time limit to execute the exploration. Reaching this time triggers the behavior defined in the behaviour_after_stopping field. Set to 0 when the exploration time is not limited.
 * @param behaviour_after_stopping  The behavior after stopping the exploration task. 0: Hold, 1: Land, 2: Return (to exploration return position).
 * @param boundaries_p1_lat [degE7] Exploration cuboid boundaries point 1 Latitude (WGS84). INT32_MAX if unknown. p1_lat == p3_lat.
 * @param boundaries_p1_lon [degE7] Exploration cuboid boundaries point 1 Longitude (WGS84). INT32_MAX if unknown. p1_lat == p3_lat.
 * @param boundaries_p1_alt [m] Exploration cuboid boundaries point 1 Altitude (MSL). NaN if unknown. p1_alt == p2_alt.
 * @param boundaries_p1_x [m] Exploration cuboid boundaries point 1 local NED X coordinate. NaN if unknown. p1_x == p3_x.
 * @param boundaries_p1_y [m] Exploration cuboid boundaries point 1 local NED Y coordinate. NaN if unknown. p1_y == p3_y.
 * @param boundaries_p1_z [m] Exploration cuboid boundaries point 1 local NED Z coordinate. NaN if unknown. p1_z == p2_z.
 * @param boundaries_p2_lat [degE7] Exploration cuboid boundaries point 2 Latitude (WGS84). INT32_MAX if unknown.
 * @param boundaries_p2_lon [degE7] Exploration cuboid boundaries point 2 Longitude (WGS84). INT32_MAX if unknown.
 * @param boundaries_p2_x [m] Exploration cuboid boundaries point 2 local NED X coordinate. NaN if unknown.
 * @param boundaries_p2_y [m] Exploration cuboid boundaries point 2 local NED Y coordinate. NaN if unknown.
 * @param boundaries_p3_alt [m] Exploration cuboid boundaries point 3 Altitude (MSL). NaN if unknown.
 * @param boundaries_p3_z [m] Exploration cuboid boundaries point 3 local NED Z coordinate. NaN if unknown.
 * @param ingress_portal_id  Currently defined ingress portal ID. This portal ID can either be set by the system autonomy engine or by an offboard controller or operator using MAV_CMD_SET_INGRESS_PORTAL. When unknown, not applicable or not deterministic, set to UINT32_MAX.
 * @param ingress_portal_lat [degE7] Currently defined ingress portal Latitude (WGS84). INT32_MAX if unknown, not applicable or when ingress_portal_id is set and different from UINT32_MAX.
 * @param ingress_portal_lon [degE7] Currently defined ingress portal Longitude (WGS84). INT32_MAX if unknown, not applicable or when ingress_portal_id is set and different from UINT32_MAX.
 * @param ingress_portal_alt [m] Currently defined ingress portal Altitude (MSL). NaN if unknown, not applicable or when ingress_portal_id is set and different from UINT32_MAX.
 * @param egress_portal_id  Currently defined egress portal ID. This portal ID can either be set by the system autonomy engine or by an offboard controller or operator using MAV_CMD_SET_EGRESS_PORTAL. When unknown, not applicable or not deterministic, set to UINT32_MAX.
 * @param egress_portal_lat [degE7] Currently defined egress portal Latitude (WGS84). INT32_MAX if unknown, not applicable or when egress_portal_id is set and different from UINT32_MAX.
 * @param egress_portal_lon [degE7] Currently defined egress portal Longitude (WGS84). INT32_MAX if unknown, not applicable or when egress_portal_id is set and different from UINT32_MAX.
 * @param egress_portal_alt [m] Currently defined egress portal Altitude (MSL). NaN if unknown, not applicable or when egress_portal_id is set and different from UINT32_MAX.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_exploration_info_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t exploration_id,uint32_t time_limit,uint8_t behaviour_after_stopping,int32_t boundaries_p1_lat,int32_t boundaries_p1_lon,float boundaries_p1_alt,float boundaries_p1_x,float boundaries_p1_y,float boundaries_p1_z,int32_t boundaries_p2_lat,int32_t boundaries_p2_lon,float boundaries_p2_x,float boundaries_p2_y,float boundaries_p3_alt,float boundaries_p3_z,uint32_t ingress_portal_id,int32_t ingress_portal_lat,int32_t ingress_portal_lon,float ingress_portal_alt,uint32_t egress_portal_id,int32_t egress_portal_lat,int32_t egress_portal_lon,float egress_portal_alt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EXPLORATION_INFO_LEN];
    _mav_put_uint32_t(buf, 0, time_limit);
    _mav_put_int32_t(buf, 4, boundaries_p1_lat);
    _mav_put_int32_t(buf, 8, boundaries_p1_lon);
    _mav_put_float(buf, 12, boundaries_p1_alt);
    _mav_put_float(buf, 16, boundaries_p1_x);
    _mav_put_float(buf, 20, boundaries_p1_y);
    _mav_put_float(buf, 24, boundaries_p1_z);
    _mav_put_int32_t(buf, 28, boundaries_p2_lat);
    _mav_put_int32_t(buf, 32, boundaries_p2_lon);
    _mav_put_float(buf, 36, boundaries_p2_x);
    _mav_put_float(buf, 40, boundaries_p2_y);
    _mav_put_float(buf, 44, boundaries_p3_alt);
    _mav_put_float(buf, 48, boundaries_p3_z);
    _mav_put_uint32_t(buf, 52, ingress_portal_id);
    _mav_put_int32_t(buf, 56, ingress_portal_lat);
    _mav_put_int32_t(buf, 60, ingress_portal_lon);
    _mav_put_float(buf, 64, ingress_portal_alt);
    _mav_put_uint32_t(buf, 68, egress_portal_id);
    _mav_put_int32_t(buf, 72, egress_portal_lat);
    _mav_put_int32_t(buf, 76, egress_portal_lon);
    _mav_put_float(buf, 80, egress_portal_alt);
    _mav_put_uint8_t(buf, 84, exploration_id);
    _mav_put_uint8_t(buf, 85, behaviour_after_stopping);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EXPLORATION_INFO_LEN);
#else
    mavlink_exploration_info_t packet;
    packet.time_limit = time_limit;
    packet.boundaries_p1_lat = boundaries_p1_lat;
    packet.boundaries_p1_lon = boundaries_p1_lon;
    packet.boundaries_p1_alt = boundaries_p1_alt;
    packet.boundaries_p1_x = boundaries_p1_x;
    packet.boundaries_p1_y = boundaries_p1_y;
    packet.boundaries_p1_z = boundaries_p1_z;
    packet.boundaries_p2_lat = boundaries_p2_lat;
    packet.boundaries_p2_lon = boundaries_p2_lon;
    packet.boundaries_p2_x = boundaries_p2_x;
    packet.boundaries_p2_y = boundaries_p2_y;
    packet.boundaries_p3_alt = boundaries_p3_alt;
    packet.boundaries_p3_z = boundaries_p3_z;
    packet.ingress_portal_id = ingress_portal_id;
    packet.ingress_portal_lat = ingress_portal_lat;
    packet.ingress_portal_lon = ingress_portal_lon;
    packet.ingress_portal_alt = ingress_portal_alt;
    packet.egress_portal_id = egress_portal_id;
    packet.egress_portal_lat = egress_portal_lat;
    packet.egress_portal_lon = egress_portal_lon;
    packet.egress_portal_alt = egress_portal_alt;
    packet.exploration_id = exploration_id;
    packet.behaviour_after_stopping = behaviour_after_stopping;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EXPLORATION_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EXPLORATION_INFO;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_EXPLORATION_INFO_MIN_LEN, MAVLINK_MSG_ID_EXPLORATION_INFO_LEN, MAVLINK_MSG_ID_EXPLORATION_INFO_CRC);
}

/**
 * @brief Encode a exploration_info struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param exploration_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_exploration_info_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_exploration_info_t* exploration_info)
{
    return mavlink_msg_exploration_info_pack(system_id, component_id, msg, exploration_info->exploration_id, exploration_info->time_limit, exploration_info->behaviour_after_stopping, exploration_info->boundaries_p1_lat, exploration_info->boundaries_p1_lon, exploration_info->boundaries_p1_alt, exploration_info->boundaries_p1_x, exploration_info->boundaries_p1_y, exploration_info->boundaries_p1_z, exploration_info->boundaries_p2_lat, exploration_info->boundaries_p2_lon, exploration_info->boundaries_p2_x, exploration_info->boundaries_p2_y, exploration_info->boundaries_p3_alt, exploration_info->boundaries_p3_z, exploration_info->ingress_portal_id, exploration_info->ingress_portal_lat, exploration_info->ingress_portal_lon, exploration_info->ingress_portal_alt, exploration_info->egress_portal_id, exploration_info->egress_portal_lat, exploration_info->egress_portal_lon, exploration_info->egress_portal_alt);
}

/**
 * @brief Encode a exploration_info struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param exploration_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_exploration_info_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_exploration_info_t* exploration_info)
{
    return mavlink_msg_exploration_info_pack_chan(system_id, component_id, chan, msg, exploration_info->exploration_id, exploration_info->time_limit, exploration_info->behaviour_after_stopping, exploration_info->boundaries_p1_lat, exploration_info->boundaries_p1_lon, exploration_info->boundaries_p1_alt, exploration_info->boundaries_p1_x, exploration_info->boundaries_p1_y, exploration_info->boundaries_p1_z, exploration_info->boundaries_p2_lat, exploration_info->boundaries_p2_lon, exploration_info->boundaries_p2_x, exploration_info->boundaries_p2_y, exploration_info->boundaries_p3_alt, exploration_info->boundaries_p3_z, exploration_info->ingress_portal_id, exploration_info->ingress_portal_lat, exploration_info->ingress_portal_lon, exploration_info->ingress_portal_alt, exploration_info->egress_portal_id, exploration_info->egress_portal_lat, exploration_info->egress_portal_lon, exploration_info->egress_portal_alt);
}

/**
 * @brief Send a exploration_info message
 * @param chan MAVLink channel to send the message
 *
 * @param exploration_id  ID of the exploration task. 255 to get the information of the current running exploration task.
 * @param time_limit [s] Time limit to execute the exploration. Reaching this time triggers the behavior defined in the behaviour_after_stopping field. Set to 0 when the exploration time is not limited.
 * @param behaviour_after_stopping  The behavior after stopping the exploration task. 0: Hold, 1: Land, 2: Return (to exploration return position).
 * @param boundaries_p1_lat [degE7] Exploration cuboid boundaries point 1 Latitude (WGS84). INT32_MAX if unknown. p1_lat == p3_lat.
 * @param boundaries_p1_lon [degE7] Exploration cuboid boundaries point 1 Longitude (WGS84). INT32_MAX if unknown. p1_lat == p3_lat.
 * @param boundaries_p1_alt [m] Exploration cuboid boundaries point 1 Altitude (MSL). NaN if unknown. p1_alt == p2_alt.
 * @param boundaries_p1_x [m] Exploration cuboid boundaries point 1 local NED X coordinate. NaN if unknown. p1_x == p3_x.
 * @param boundaries_p1_y [m] Exploration cuboid boundaries point 1 local NED Y coordinate. NaN if unknown. p1_y == p3_y.
 * @param boundaries_p1_z [m] Exploration cuboid boundaries point 1 local NED Z coordinate. NaN if unknown. p1_z == p2_z.
 * @param boundaries_p2_lat [degE7] Exploration cuboid boundaries point 2 Latitude (WGS84). INT32_MAX if unknown.
 * @param boundaries_p2_lon [degE7] Exploration cuboid boundaries point 2 Longitude (WGS84). INT32_MAX if unknown.
 * @param boundaries_p2_x [m] Exploration cuboid boundaries point 2 local NED X coordinate. NaN if unknown.
 * @param boundaries_p2_y [m] Exploration cuboid boundaries point 2 local NED Y coordinate. NaN if unknown.
 * @param boundaries_p3_alt [m] Exploration cuboid boundaries point 3 Altitude (MSL). NaN if unknown.
 * @param boundaries_p3_z [m] Exploration cuboid boundaries point 3 local NED Z coordinate. NaN if unknown.
 * @param ingress_portal_id  Currently defined ingress portal ID. This portal ID can either be set by the system autonomy engine or by an offboard controller or operator using MAV_CMD_SET_INGRESS_PORTAL. When unknown, not applicable or not deterministic, set to UINT32_MAX.
 * @param ingress_portal_lat [degE7] Currently defined ingress portal Latitude (WGS84). INT32_MAX if unknown, not applicable or when ingress_portal_id is set and different from UINT32_MAX.
 * @param ingress_portal_lon [degE7] Currently defined ingress portal Longitude (WGS84). INT32_MAX if unknown, not applicable or when ingress_portal_id is set and different from UINT32_MAX.
 * @param ingress_portal_alt [m] Currently defined ingress portal Altitude (MSL). NaN if unknown, not applicable or when ingress_portal_id is set and different from UINT32_MAX.
 * @param egress_portal_id  Currently defined egress portal ID. This portal ID can either be set by the system autonomy engine or by an offboard controller or operator using MAV_CMD_SET_EGRESS_PORTAL. When unknown, not applicable or not deterministic, set to UINT32_MAX.
 * @param egress_portal_lat [degE7] Currently defined egress portal Latitude (WGS84). INT32_MAX if unknown, not applicable or when egress_portal_id is set and different from UINT32_MAX.
 * @param egress_portal_lon [degE7] Currently defined egress portal Longitude (WGS84). INT32_MAX if unknown, not applicable or when egress_portal_id is set and different from UINT32_MAX.
 * @param egress_portal_alt [m] Currently defined egress portal Altitude (MSL). NaN if unknown, not applicable or when egress_portal_id is set and different from UINT32_MAX.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_exploration_info_send(mavlink_channel_t chan, uint8_t exploration_id, uint32_t time_limit, uint8_t behaviour_after_stopping, int32_t boundaries_p1_lat, int32_t boundaries_p1_lon, float boundaries_p1_alt, float boundaries_p1_x, float boundaries_p1_y, float boundaries_p1_z, int32_t boundaries_p2_lat, int32_t boundaries_p2_lon, float boundaries_p2_x, float boundaries_p2_y, float boundaries_p3_alt, float boundaries_p3_z, uint32_t ingress_portal_id, int32_t ingress_portal_lat, int32_t ingress_portal_lon, float ingress_portal_alt, uint32_t egress_portal_id, int32_t egress_portal_lat, int32_t egress_portal_lon, float egress_portal_alt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EXPLORATION_INFO_LEN];
    _mav_put_uint32_t(buf, 0, time_limit);
    _mav_put_int32_t(buf, 4, boundaries_p1_lat);
    _mav_put_int32_t(buf, 8, boundaries_p1_lon);
    _mav_put_float(buf, 12, boundaries_p1_alt);
    _mav_put_float(buf, 16, boundaries_p1_x);
    _mav_put_float(buf, 20, boundaries_p1_y);
    _mav_put_float(buf, 24, boundaries_p1_z);
    _mav_put_int32_t(buf, 28, boundaries_p2_lat);
    _mav_put_int32_t(buf, 32, boundaries_p2_lon);
    _mav_put_float(buf, 36, boundaries_p2_x);
    _mav_put_float(buf, 40, boundaries_p2_y);
    _mav_put_float(buf, 44, boundaries_p3_alt);
    _mav_put_float(buf, 48, boundaries_p3_z);
    _mav_put_uint32_t(buf, 52, ingress_portal_id);
    _mav_put_int32_t(buf, 56, ingress_portal_lat);
    _mav_put_int32_t(buf, 60, ingress_portal_lon);
    _mav_put_float(buf, 64, ingress_portal_alt);
    _mav_put_uint32_t(buf, 68, egress_portal_id);
    _mav_put_int32_t(buf, 72, egress_portal_lat);
    _mav_put_int32_t(buf, 76, egress_portal_lon);
    _mav_put_float(buf, 80, egress_portal_alt);
    _mav_put_uint8_t(buf, 84, exploration_id);
    _mav_put_uint8_t(buf, 85, behaviour_after_stopping);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXPLORATION_INFO, buf, MAVLINK_MSG_ID_EXPLORATION_INFO_MIN_LEN, MAVLINK_MSG_ID_EXPLORATION_INFO_LEN, MAVLINK_MSG_ID_EXPLORATION_INFO_CRC);
#else
    mavlink_exploration_info_t packet;
    packet.time_limit = time_limit;
    packet.boundaries_p1_lat = boundaries_p1_lat;
    packet.boundaries_p1_lon = boundaries_p1_lon;
    packet.boundaries_p1_alt = boundaries_p1_alt;
    packet.boundaries_p1_x = boundaries_p1_x;
    packet.boundaries_p1_y = boundaries_p1_y;
    packet.boundaries_p1_z = boundaries_p1_z;
    packet.boundaries_p2_lat = boundaries_p2_lat;
    packet.boundaries_p2_lon = boundaries_p2_lon;
    packet.boundaries_p2_x = boundaries_p2_x;
    packet.boundaries_p2_y = boundaries_p2_y;
    packet.boundaries_p3_alt = boundaries_p3_alt;
    packet.boundaries_p3_z = boundaries_p3_z;
    packet.ingress_portal_id = ingress_portal_id;
    packet.ingress_portal_lat = ingress_portal_lat;
    packet.ingress_portal_lon = ingress_portal_lon;
    packet.ingress_portal_alt = ingress_portal_alt;
    packet.egress_portal_id = egress_portal_id;
    packet.egress_portal_lat = egress_portal_lat;
    packet.egress_portal_lon = egress_portal_lon;
    packet.egress_portal_alt = egress_portal_alt;
    packet.exploration_id = exploration_id;
    packet.behaviour_after_stopping = behaviour_after_stopping;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXPLORATION_INFO, (const char *)&packet, MAVLINK_MSG_ID_EXPLORATION_INFO_MIN_LEN, MAVLINK_MSG_ID_EXPLORATION_INFO_LEN, MAVLINK_MSG_ID_EXPLORATION_INFO_CRC);
#endif
}

/**
 * @brief Send a exploration_info message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_exploration_info_send_struct(mavlink_channel_t chan, const mavlink_exploration_info_t* exploration_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_exploration_info_send(chan, exploration_info->exploration_id, exploration_info->time_limit, exploration_info->behaviour_after_stopping, exploration_info->boundaries_p1_lat, exploration_info->boundaries_p1_lon, exploration_info->boundaries_p1_alt, exploration_info->boundaries_p1_x, exploration_info->boundaries_p1_y, exploration_info->boundaries_p1_z, exploration_info->boundaries_p2_lat, exploration_info->boundaries_p2_lon, exploration_info->boundaries_p2_x, exploration_info->boundaries_p2_y, exploration_info->boundaries_p3_alt, exploration_info->boundaries_p3_z, exploration_info->ingress_portal_id, exploration_info->ingress_portal_lat, exploration_info->ingress_portal_lon, exploration_info->ingress_portal_alt, exploration_info->egress_portal_id, exploration_info->egress_portal_lat, exploration_info->egress_portal_lon, exploration_info->egress_portal_alt);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXPLORATION_INFO, (const char *)exploration_info, MAVLINK_MSG_ID_EXPLORATION_INFO_MIN_LEN, MAVLINK_MSG_ID_EXPLORATION_INFO_LEN, MAVLINK_MSG_ID_EXPLORATION_INFO_CRC);
#endif
}

#if MAVLINK_MSG_ID_EXPLORATION_INFO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_exploration_info_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t exploration_id, uint32_t time_limit, uint8_t behaviour_after_stopping, int32_t boundaries_p1_lat, int32_t boundaries_p1_lon, float boundaries_p1_alt, float boundaries_p1_x, float boundaries_p1_y, float boundaries_p1_z, int32_t boundaries_p2_lat, int32_t boundaries_p2_lon, float boundaries_p2_x, float boundaries_p2_y, float boundaries_p3_alt, float boundaries_p3_z, uint32_t ingress_portal_id, int32_t ingress_portal_lat, int32_t ingress_portal_lon, float ingress_portal_alt, uint32_t egress_portal_id, int32_t egress_portal_lat, int32_t egress_portal_lon, float egress_portal_alt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, time_limit);
    _mav_put_int32_t(buf, 4, boundaries_p1_lat);
    _mav_put_int32_t(buf, 8, boundaries_p1_lon);
    _mav_put_float(buf, 12, boundaries_p1_alt);
    _mav_put_float(buf, 16, boundaries_p1_x);
    _mav_put_float(buf, 20, boundaries_p1_y);
    _mav_put_float(buf, 24, boundaries_p1_z);
    _mav_put_int32_t(buf, 28, boundaries_p2_lat);
    _mav_put_int32_t(buf, 32, boundaries_p2_lon);
    _mav_put_float(buf, 36, boundaries_p2_x);
    _mav_put_float(buf, 40, boundaries_p2_y);
    _mav_put_float(buf, 44, boundaries_p3_alt);
    _mav_put_float(buf, 48, boundaries_p3_z);
    _mav_put_uint32_t(buf, 52, ingress_portal_id);
    _mav_put_int32_t(buf, 56, ingress_portal_lat);
    _mav_put_int32_t(buf, 60, ingress_portal_lon);
    _mav_put_float(buf, 64, ingress_portal_alt);
    _mav_put_uint32_t(buf, 68, egress_portal_id);
    _mav_put_int32_t(buf, 72, egress_portal_lat);
    _mav_put_int32_t(buf, 76, egress_portal_lon);
    _mav_put_float(buf, 80, egress_portal_alt);
    _mav_put_uint8_t(buf, 84, exploration_id);
    _mav_put_uint8_t(buf, 85, behaviour_after_stopping);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXPLORATION_INFO, buf, MAVLINK_MSG_ID_EXPLORATION_INFO_MIN_LEN, MAVLINK_MSG_ID_EXPLORATION_INFO_LEN, MAVLINK_MSG_ID_EXPLORATION_INFO_CRC);
#else
    mavlink_exploration_info_t *packet = (mavlink_exploration_info_t *)msgbuf;
    packet->time_limit = time_limit;
    packet->boundaries_p1_lat = boundaries_p1_lat;
    packet->boundaries_p1_lon = boundaries_p1_lon;
    packet->boundaries_p1_alt = boundaries_p1_alt;
    packet->boundaries_p1_x = boundaries_p1_x;
    packet->boundaries_p1_y = boundaries_p1_y;
    packet->boundaries_p1_z = boundaries_p1_z;
    packet->boundaries_p2_lat = boundaries_p2_lat;
    packet->boundaries_p2_lon = boundaries_p2_lon;
    packet->boundaries_p2_x = boundaries_p2_x;
    packet->boundaries_p2_y = boundaries_p2_y;
    packet->boundaries_p3_alt = boundaries_p3_alt;
    packet->boundaries_p3_z = boundaries_p3_z;
    packet->ingress_portal_id = ingress_portal_id;
    packet->ingress_portal_lat = ingress_portal_lat;
    packet->ingress_portal_lon = ingress_portal_lon;
    packet->ingress_portal_alt = ingress_portal_alt;
    packet->egress_portal_id = egress_portal_id;
    packet->egress_portal_lat = egress_portal_lat;
    packet->egress_portal_lon = egress_portal_lon;
    packet->egress_portal_alt = egress_portal_alt;
    packet->exploration_id = exploration_id;
    packet->behaviour_after_stopping = behaviour_after_stopping;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXPLORATION_INFO, (const char *)packet, MAVLINK_MSG_ID_EXPLORATION_INFO_MIN_LEN, MAVLINK_MSG_ID_EXPLORATION_INFO_LEN, MAVLINK_MSG_ID_EXPLORATION_INFO_CRC);
#endif
}
#endif

#endif

// MESSAGE EXPLORATION_INFO UNPACKING


/**
 * @brief Get field exploration_id from exploration_info message
 *
 * @return  ID of the exploration task. 255 to get the information of the current running exploration task.
 */
static inline uint8_t mavlink_msg_exploration_info_get_exploration_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  84);
}

/**
 * @brief Get field time_limit from exploration_info message
 *
 * @return [s] Time limit to execute the exploration. Reaching this time triggers the behavior defined in the behaviour_after_stopping field. Set to 0 when the exploration time is not limited.
 */
static inline uint32_t mavlink_msg_exploration_info_get_time_limit(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field behaviour_after_stopping from exploration_info message
 *
 * @return  The behavior after stopping the exploration task. 0: Hold, 1: Land, 2: Return (to exploration return position).
 */
static inline uint8_t mavlink_msg_exploration_info_get_behaviour_after_stopping(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  85);
}

/**
 * @brief Get field boundaries_p1_lat from exploration_info message
 *
 * @return [degE7] Exploration cuboid boundaries point 1 Latitude (WGS84). INT32_MAX if unknown. p1_lat == p3_lat.
 */
static inline int32_t mavlink_msg_exploration_info_get_boundaries_p1_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field boundaries_p1_lon from exploration_info message
 *
 * @return [degE7] Exploration cuboid boundaries point 1 Longitude (WGS84). INT32_MAX if unknown. p1_lat == p3_lat.
 */
static inline int32_t mavlink_msg_exploration_info_get_boundaries_p1_lon(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field boundaries_p1_alt from exploration_info message
 *
 * @return [m] Exploration cuboid boundaries point 1 Altitude (MSL). NaN if unknown. p1_alt == p2_alt.
 */
static inline float mavlink_msg_exploration_info_get_boundaries_p1_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field boundaries_p1_x from exploration_info message
 *
 * @return [m] Exploration cuboid boundaries point 1 local NED X coordinate. NaN if unknown. p1_x == p3_x.
 */
static inline float mavlink_msg_exploration_info_get_boundaries_p1_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field boundaries_p1_y from exploration_info message
 *
 * @return [m] Exploration cuboid boundaries point 1 local NED Y coordinate. NaN if unknown. p1_y == p3_y.
 */
static inline float mavlink_msg_exploration_info_get_boundaries_p1_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field boundaries_p1_z from exploration_info message
 *
 * @return [m] Exploration cuboid boundaries point 1 local NED Z coordinate. NaN if unknown. p1_z == p2_z.
 */
static inline float mavlink_msg_exploration_info_get_boundaries_p1_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field boundaries_p2_lat from exploration_info message
 *
 * @return [degE7] Exploration cuboid boundaries point 2 Latitude (WGS84). INT32_MAX if unknown.
 */
static inline int32_t mavlink_msg_exploration_info_get_boundaries_p2_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  28);
}

/**
 * @brief Get field boundaries_p2_lon from exploration_info message
 *
 * @return [degE7] Exploration cuboid boundaries point 2 Longitude (WGS84). INT32_MAX if unknown.
 */
static inline int32_t mavlink_msg_exploration_info_get_boundaries_p2_lon(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  32);
}

/**
 * @brief Get field boundaries_p2_x from exploration_info message
 *
 * @return [m] Exploration cuboid boundaries point 2 local NED X coordinate. NaN if unknown.
 */
static inline float mavlink_msg_exploration_info_get_boundaries_p2_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field boundaries_p2_y from exploration_info message
 *
 * @return [m] Exploration cuboid boundaries point 2 local NED Y coordinate. NaN if unknown.
 */
static inline float mavlink_msg_exploration_info_get_boundaries_p2_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field boundaries_p3_alt from exploration_info message
 *
 * @return [m] Exploration cuboid boundaries point 3 Altitude (MSL). NaN if unknown.
 */
static inline float mavlink_msg_exploration_info_get_boundaries_p3_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field boundaries_p3_z from exploration_info message
 *
 * @return [m] Exploration cuboid boundaries point 3 local NED Z coordinate. NaN if unknown.
 */
static inline float mavlink_msg_exploration_info_get_boundaries_p3_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field ingress_portal_id from exploration_info message
 *
 * @return  Currently defined ingress portal ID. This portal ID can either be set by the system autonomy engine or by an offboard controller or operator using MAV_CMD_SET_INGRESS_PORTAL. When unknown, not applicable or not deterministic, set to UINT32_MAX.
 */
static inline uint32_t mavlink_msg_exploration_info_get_ingress_portal_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  52);
}

/**
 * @brief Get field ingress_portal_lat from exploration_info message
 *
 * @return [degE7] Currently defined ingress portal Latitude (WGS84). INT32_MAX if unknown, not applicable or when ingress_portal_id is set and different from UINT32_MAX.
 */
static inline int32_t mavlink_msg_exploration_info_get_ingress_portal_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  56);
}

/**
 * @brief Get field ingress_portal_lon from exploration_info message
 *
 * @return [degE7] Currently defined ingress portal Longitude (WGS84). INT32_MAX if unknown, not applicable or when ingress_portal_id is set and different from UINT32_MAX.
 */
static inline int32_t mavlink_msg_exploration_info_get_ingress_portal_lon(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  60);
}

/**
 * @brief Get field ingress_portal_alt from exploration_info message
 *
 * @return [m] Currently defined ingress portal Altitude (MSL). NaN if unknown, not applicable or when ingress_portal_id is set and different from UINT32_MAX.
 */
static inline float mavlink_msg_exploration_info_get_ingress_portal_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  64);
}

/**
 * @brief Get field egress_portal_id from exploration_info message
 *
 * @return  Currently defined egress portal ID. This portal ID can either be set by the system autonomy engine or by an offboard controller or operator using MAV_CMD_SET_EGRESS_PORTAL. When unknown, not applicable or not deterministic, set to UINT32_MAX.
 */
static inline uint32_t mavlink_msg_exploration_info_get_egress_portal_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  68);
}

/**
 * @brief Get field egress_portal_lat from exploration_info message
 *
 * @return [degE7] Currently defined egress portal Latitude (WGS84). INT32_MAX if unknown, not applicable or when egress_portal_id is set and different from UINT32_MAX.
 */
static inline int32_t mavlink_msg_exploration_info_get_egress_portal_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  72);
}

/**
 * @brief Get field egress_portal_lon from exploration_info message
 *
 * @return [degE7] Currently defined egress portal Longitude (WGS84). INT32_MAX if unknown, not applicable or when egress_portal_id is set and different from UINT32_MAX.
 */
static inline int32_t mavlink_msg_exploration_info_get_egress_portal_lon(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  76);
}

/**
 * @brief Get field egress_portal_alt from exploration_info message
 *
 * @return [m] Currently defined egress portal Altitude (MSL). NaN if unknown, not applicable or when egress_portal_id is set and different from UINT32_MAX.
 */
static inline float mavlink_msg_exploration_info_get_egress_portal_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  80);
}

/**
 * @brief Decode a exploration_info message into a struct
 *
 * @param msg The message to decode
 * @param exploration_info C-struct to decode the message contents into
 */
static inline void mavlink_msg_exploration_info_decode(const mavlink_message_t* msg, mavlink_exploration_info_t* exploration_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    exploration_info->time_limit = mavlink_msg_exploration_info_get_time_limit(msg);
    exploration_info->boundaries_p1_lat = mavlink_msg_exploration_info_get_boundaries_p1_lat(msg);
    exploration_info->boundaries_p1_lon = mavlink_msg_exploration_info_get_boundaries_p1_lon(msg);
    exploration_info->boundaries_p1_alt = mavlink_msg_exploration_info_get_boundaries_p1_alt(msg);
    exploration_info->boundaries_p1_x = mavlink_msg_exploration_info_get_boundaries_p1_x(msg);
    exploration_info->boundaries_p1_y = mavlink_msg_exploration_info_get_boundaries_p1_y(msg);
    exploration_info->boundaries_p1_z = mavlink_msg_exploration_info_get_boundaries_p1_z(msg);
    exploration_info->boundaries_p2_lat = mavlink_msg_exploration_info_get_boundaries_p2_lat(msg);
    exploration_info->boundaries_p2_lon = mavlink_msg_exploration_info_get_boundaries_p2_lon(msg);
    exploration_info->boundaries_p2_x = mavlink_msg_exploration_info_get_boundaries_p2_x(msg);
    exploration_info->boundaries_p2_y = mavlink_msg_exploration_info_get_boundaries_p2_y(msg);
    exploration_info->boundaries_p3_alt = mavlink_msg_exploration_info_get_boundaries_p3_alt(msg);
    exploration_info->boundaries_p3_z = mavlink_msg_exploration_info_get_boundaries_p3_z(msg);
    exploration_info->ingress_portal_id = mavlink_msg_exploration_info_get_ingress_portal_id(msg);
    exploration_info->ingress_portal_lat = mavlink_msg_exploration_info_get_ingress_portal_lat(msg);
    exploration_info->ingress_portal_lon = mavlink_msg_exploration_info_get_ingress_portal_lon(msg);
    exploration_info->ingress_portal_alt = mavlink_msg_exploration_info_get_ingress_portal_alt(msg);
    exploration_info->egress_portal_id = mavlink_msg_exploration_info_get_egress_portal_id(msg);
    exploration_info->egress_portal_lat = mavlink_msg_exploration_info_get_egress_portal_lat(msg);
    exploration_info->egress_portal_lon = mavlink_msg_exploration_info_get_egress_portal_lon(msg);
    exploration_info->egress_portal_alt = mavlink_msg_exploration_info_get_egress_portal_alt(msg);
    exploration_info->exploration_id = mavlink_msg_exploration_info_get_exploration_id(msg);
    exploration_info->behaviour_after_stopping = mavlink_msg_exploration_info_get_behaviour_after_stopping(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_EXPLORATION_INFO_LEN? msg->len : MAVLINK_MSG_ID_EXPLORATION_INFO_LEN;
        memset(exploration_info, 0, MAVLINK_MSG_ID_EXPLORATION_INFO_LEN);
    memcpy(exploration_info, _MAV_PAYLOAD(msg), len);
#endif
}
