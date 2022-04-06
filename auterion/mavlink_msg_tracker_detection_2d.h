#pragma once
// MESSAGE TRACKER_DETECTION_2D PACKING

#define MAVLINK_MSG_ID_TRACKER_DETECTION_2D 501


typedef struct __mavlink_tracker_detection_2d_t {
 uint64_t img_ts; /*< [us]  Time stamp of the image.*/
 uint64_t img_id; /*<   Unique ID specifiying the video frame (image) in the message sender video stream.*/
 uint32_t object_id; /*<   Unique ID representing the object. */
 uint32_t class_id; /*<   Unique ID specifiying the class of the object.*/
 int32_t lat; /*< [degE7]  Latitude in WGS84 coordinate frame of the detected object. NAN if unknown.*/
 int32_t lon; /*< [degE7]  Longitude in WGS84 coordinate frame of the detected object. NAN if unknown.*/
 float alt; /*< [m]  Altitude in EGM96 coordiante frame of the detected object. NAN if unknown.*/
 float vel_n; /*< [m/s]  North velocity of the object in global frame. NAN if unknown.*/
 float vel_e; /*< [m/s]  East velocity of the object in global frame. NAN if unknown.*/
 float vel_up; /*< [m/s]  Up velocity of the object in global frame. NAN if unknown.*/
 uint16_t bbox_top_left_x; /*< [c%]  Relative image x coordinate (left to right axis) in the range of [0.00, 100.00] describing the top left corner of the bounding box .*/
 uint16_t bbox_top_left_y; /*< [c%]  Relative image y coordinate (top to bottom axis) in the range of [0.00, 100.00] describing the top left corner of the bounding box.*/
 uint16_t bbox_bot_right_x; /*< [c%]  Relative image x coordinate (left to right axis) in the range of [0.00, 100.00] describing the bottom right corner of the bounding box.*/
 uint16_t bbox_bot_right_y; /*< [c%]  Relative image y coordinate (top to bottom axis) in the range of [0.00, 100.00] describing the bottom left corner of the bounding box.*/
 uint8_t tracking_status; /*<   0: not tracked, 1: tracked.*/
 uint8_t confidence; /*< [%]  Confidence score in the range of [0, 100] for the classifcation.*/
} mavlink_tracker_detection_2d_t;

#define MAVLINK_MSG_ID_TRACKER_DETECTION_2D_LEN 58
#define MAVLINK_MSG_ID_TRACKER_DETECTION_2D_MIN_LEN 58
#define MAVLINK_MSG_ID_501_LEN 58
#define MAVLINK_MSG_ID_501_MIN_LEN 58

#define MAVLINK_MSG_ID_TRACKER_DETECTION_2D_CRC 178
#define MAVLINK_MSG_ID_501_CRC 178



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TRACKER_DETECTION_2D { \
    501, \
    "TRACKER_DETECTION_2D", \
    16, \
    {  { "img_ts", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_tracker_detection_2d_t, img_ts) }, \
         { "img_id", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_tracker_detection_2d_t, img_id) }, \
         { "object_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_tracker_detection_2d_t, object_id) }, \
         { "class_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 20, offsetof(mavlink_tracker_detection_2d_t, class_id) }, \
         { "tracking_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 56, offsetof(mavlink_tracker_detection_2d_t, tracking_status) }, \
         { "confidence", NULL, MAVLINK_TYPE_UINT8_T, 0, 57, offsetof(mavlink_tracker_detection_2d_t, confidence) }, \
         { "bbox_top_left_x", NULL, MAVLINK_TYPE_UINT16_T, 0, 48, offsetof(mavlink_tracker_detection_2d_t, bbox_top_left_x) }, \
         { "bbox_top_left_y", NULL, MAVLINK_TYPE_UINT16_T, 0, 50, offsetof(mavlink_tracker_detection_2d_t, bbox_top_left_y) }, \
         { "bbox_bot_right_x", NULL, MAVLINK_TYPE_UINT16_T, 0, 52, offsetof(mavlink_tracker_detection_2d_t, bbox_bot_right_x) }, \
         { "bbox_bot_right_y", NULL, MAVLINK_TYPE_UINT16_T, 0, 54, offsetof(mavlink_tracker_detection_2d_t, bbox_bot_right_y) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 24, offsetof(mavlink_tracker_detection_2d_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 28, offsetof(mavlink_tracker_detection_2d_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_tracker_detection_2d_t, alt) }, \
         { "vel_n", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_tracker_detection_2d_t, vel_n) }, \
         { "vel_e", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_tracker_detection_2d_t, vel_e) }, \
         { "vel_up", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_tracker_detection_2d_t, vel_up) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TRACKER_DETECTION_2D { \
    "TRACKER_DETECTION_2D", \
    16, \
    {  { "img_ts", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_tracker_detection_2d_t, img_ts) }, \
         { "img_id", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_tracker_detection_2d_t, img_id) }, \
         { "object_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_tracker_detection_2d_t, object_id) }, \
         { "class_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 20, offsetof(mavlink_tracker_detection_2d_t, class_id) }, \
         { "tracking_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 56, offsetof(mavlink_tracker_detection_2d_t, tracking_status) }, \
         { "confidence", NULL, MAVLINK_TYPE_UINT8_T, 0, 57, offsetof(mavlink_tracker_detection_2d_t, confidence) }, \
         { "bbox_top_left_x", NULL, MAVLINK_TYPE_UINT16_T, 0, 48, offsetof(mavlink_tracker_detection_2d_t, bbox_top_left_x) }, \
         { "bbox_top_left_y", NULL, MAVLINK_TYPE_UINT16_T, 0, 50, offsetof(mavlink_tracker_detection_2d_t, bbox_top_left_y) }, \
         { "bbox_bot_right_x", NULL, MAVLINK_TYPE_UINT16_T, 0, 52, offsetof(mavlink_tracker_detection_2d_t, bbox_bot_right_x) }, \
         { "bbox_bot_right_y", NULL, MAVLINK_TYPE_UINT16_T, 0, 54, offsetof(mavlink_tracker_detection_2d_t, bbox_bot_right_y) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 24, offsetof(mavlink_tracker_detection_2d_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 28, offsetof(mavlink_tracker_detection_2d_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_tracker_detection_2d_t, alt) }, \
         { "vel_n", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_tracker_detection_2d_t, vel_n) }, \
         { "vel_e", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_tracker_detection_2d_t, vel_e) }, \
         { "vel_up", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_tracker_detection_2d_t, vel_up) }, \
         } \
}
#endif

/**
 * @brief Pack a tracker_detection_2d message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param img_ts [us]  Time stamp of the image.
 * @param img_id   Unique ID specifiying the video frame (image) in the message sender video stream.
 * @param object_id   Unique ID representing the object. 
 * @param class_id   Unique ID specifiying the class of the object.
 * @param tracking_status   0: not tracked, 1: tracked.
 * @param confidence [%]  Confidence score in the range of [0, 100] for the classifcation.
 * @param bbox_top_left_x [c%]  Relative image x coordinate (left to right axis) in the range of [0.00, 100.00] describing the top left corner of the bounding box .
 * @param bbox_top_left_y [c%]  Relative image y coordinate (top to bottom axis) in the range of [0.00, 100.00] describing the top left corner of the bounding box.
 * @param bbox_bot_right_x [c%]  Relative image x coordinate (left to right axis) in the range of [0.00, 100.00] describing the bottom right corner of the bounding box.
 * @param bbox_bot_right_y [c%]  Relative image y coordinate (top to bottom axis) in the range of [0.00, 100.00] describing the bottom left corner of the bounding box.
 * @param lat [degE7]  Latitude in WGS84 coordinate frame of the detected object. NAN if unknown.
 * @param lon [degE7]  Longitude in WGS84 coordinate frame of the detected object. NAN if unknown.
 * @param alt [m]  Altitude in EGM96 coordiante frame of the detected object. NAN if unknown.
 * @param vel_n [m/s]  North velocity of the object in global frame. NAN if unknown.
 * @param vel_e [m/s]  East velocity of the object in global frame. NAN if unknown.
 * @param vel_up [m/s]  Up velocity of the object in global frame. NAN if unknown.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tracker_detection_2d_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t img_ts, uint64_t img_id, uint32_t object_id, uint32_t class_id, uint8_t tracking_status, uint8_t confidence, uint16_t bbox_top_left_x, uint16_t bbox_top_left_y, uint16_t bbox_bot_right_x, uint16_t bbox_bot_right_y, int32_t lat, int32_t lon, float alt, float vel_n, float vel_e, float vel_up)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TRACKER_DETECTION_2D_LEN];
    _mav_put_uint64_t(buf, 0, img_ts);
    _mav_put_uint64_t(buf, 8, img_id);
    _mav_put_uint32_t(buf, 16, object_id);
    _mav_put_uint32_t(buf, 20, class_id);
    _mav_put_int32_t(buf, 24, lat);
    _mav_put_int32_t(buf, 28, lon);
    _mav_put_float(buf, 32, alt);
    _mav_put_float(buf, 36, vel_n);
    _mav_put_float(buf, 40, vel_e);
    _mav_put_float(buf, 44, vel_up);
    _mav_put_uint16_t(buf, 48, bbox_top_left_x);
    _mav_put_uint16_t(buf, 50, bbox_top_left_y);
    _mav_put_uint16_t(buf, 52, bbox_bot_right_x);
    _mav_put_uint16_t(buf, 54, bbox_bot_right_y);
    _mav_put_uint8_t(buf, 56, tracking_status);
    _mav_put_uint8_t(buf, 57, confidence);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TRACKER_DETECTION_2D_LEN);
#else
    mavlink_tracker_detection_2d_t packet;
    packet.img_ts = img_ts;
    packet.img_id = img_id;
    packet.object_id = object_id;
    packet.class_id = class_id;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.vel_n = vel_n;
    packet.vel_e = vel_e;
    packet.vel_up = vel_up;
    packet.bbox_top_left_x = bbox_top_left_x;
    packet.bbox_top_left_y = bbox_top_left_y;
    packet.bbox_bot_right_x = bbox_bot_right_x;
    packet.bbox_bot_right_y = bbox_bot_right_y;
    packet.tracking_status = tracking_status;
    packet.confidence = confidence;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TRACKER_DETECTION_2D_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TRACKER_DETECTION_2D;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TRACKER_DETECTION_2D_MIN_LEN, MAVLINK_MSG_ID_TRACKER_DETECTION_2D_LEN, MAVLINK_MSG_ID_TRACKER_DETECTION_2D_CRC);
}

/**
 * @brief Pack a tracker_detection_2d message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param img_ts [us]  Time stamp of the image.
 * @param img_id   Unique ID specifiying the video frame (image) in the message sender video stream.
 * @param object_id   Unique ID representing the object. 
 * @param class_id   Unique ID specifiying the class of the object.
 * @param tracking_status   0: not tracked, 1: tracked.
 * @param confidence [%]  Confidence score in the range of [0, 100] for the classifcation.
 * @param bbox_top_left_x [c%]  Relative image x coordinate (left to right axis) in the range of [0.00, 100.00] describing the top left corner of the bounding box .
 * @param bbox_top_left_y [c%]  Relative image y coordinate (top to bottom axis) in the range of [0.00, 100.00] describing the top left corner of the bounding box.
 * @param bbox_bot_right_x [c%]  Relative image x coordinate (left to right axis) in the range of [0.00, 100.00] describing the bottom right corner of the bounding box.
 * @param bbox_bot_right_y [c%]  Relative image y coordinate (top to bottom axis) in the range of [0.00, 100.00] describing the bottom left corner of the bounding box.
 * @param lat [degE7]  Latitude in WGS84 coordinate frame of the detected object. NAN if unknown.
 * @param lon [degE7]  Longitude in WGS84 coordinate frame of the detected object. NAN if unknown.
 * @param alt [m]  Altitude in EGM96 coordiante frame of the detected object. NAN if unknown.
 * @param vel_n [m/s]  North velocity of the object in global frame. NAN if unknown.
 * @param vel_e [m/s]  East velocity of the object in global frame. NAN if unknown.
 * @param vel_up [m/s]  Up velocity of the object in global frame. NAN if unknown.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tracker_detection_2d_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t img_ts,uint64_t img_id,uint32_t object_id,uint32_t class_id,uint8_t tracking_status,uint8_t confidence,uint16_t bbox_top_left_x,uint16_t bbox_top_left_y,uint16_t bbox_bot_right_x,uint16_t bbox_bot_right_y,int32_t lat,int32_t lon,float alt,float vel_n,float vel_e,float vel_up)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TRACKER_DETECTION_2D_LEN];
    _mav_put_uint64_t(buf, 0, img_ts);
    _mav_put_uint64_t(buf, 8, img_id);
    _mav_put_uint32_t(buf, 16, object_id);
    _mav_put_uint32_t(buf, 20, class_id);
    _mav_put_int32_t(buf, 24, lat);
    _mav_put_int32_t(buf, 28, lon);
    _mav_put_float(buf, 32, alt);
    _mav_put_float(buf, 36, vel_n);
    _mav_put_float(buf, 40, vel_e);
    _mav_put_float(buf, 44, vel_up);
    _mav_put_uint16_t(buf, 48, bbox_top_left_x);
    _mav_put_uint16_t(buf, 50, bbox_top_left_y);
    _mav_put_uint16_t(buf, 52, bbox_bot_right_x);
    _mav_put_uint16_t(buf, 54, bbox_bot_right_y);
    _mav_put_uint8_t(buf, 56, tracking_status);
    _mav_put_uint8_t(buf, 57, confidence);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TRACKER_DETECTION_2D_LEN);
#else
    mavlink_tracker_detection_2d_t packet;
    packet.img_ts = img_ts;
    packet.img_id = img_id;
    packet.object_id = object_id;
    packet.class_id = class_id;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.vel_n = vel_n;
    packet.vel_e = vel_e;
    packet.vel_up = vel_up;
    packet.bbox_top_left_x = bbox_top_left_x;
    packet.bbox_top_left_y = bbox_top_left_y;
    packet.bbox_bot_right_x = bbox_bot_right_x;
    packet.bbox_bot_right_y = bbox_bot_right_y;
    packet.tracking_status = tracking_status;
    packet.confidence = confidence;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TRACKER_DETECTION_2D_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TRACKER_DETECTION_2D;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TRACKER_DETECTION_2D_MIN_LEN, MAVLINK_MSG_ID_TRACKER_DETECTION_2D_LEN, MAVLINK_MSG_ID_TRACKER_DETECTION_2D_CRC);
}

/**
 * @brief Encode a tracker_detection_2d struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param tracker_detection_2d C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tracker_detection_2d_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_tracker_detection_2d_t* tracker_detection_2d)
{
    return mavlink_msg_tracker_detection_2d_pack(system_id, component_id, msg, tracker_detection_2d->img_ts, tracker_detection_2d->img_id, tracker_detection_2d->object_id, tracker_detection_2d->class_id, tracker_detection_2d->tracking_status, tracker_detection_2d->confidence, tracker_detection_2d->bbox_top_left_x, tracker_detection_2d->bbox_top_left_y, tracker_detection_2d->bbox_bot_right_x, tracker_detection_2d->bbox_bot_right_y, tracker_detection_2d->lat, tracker_detection_2d->lon, tracker_detection_2d->alt, tracker_detection_2d->vel_n, tracker_detection_2d->vel_e, tracker_detection_2d->vel_up);
}

/**
 * @brief Encode a tracker_detection_2d struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param tracker_detection_2d C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tracker_detection_2d_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_tracker_detection_2d_t* tracker_detection_2d)
{
    return mavlink_msg_tracker_detection_2d_pack_chan(system_id, component_id, chan, msg, tracker_detection_2d->img_ts, tracker_detection_2d->img_id, tracker_detection_2d->object_id, tracker_detection_2d->class_id, tracker_detection_2d->tracking_status, tracker_detection_2d->confidence, tracker_detection_2d->bbox_top_left_x, tracker_detection_2d->bbox_top_left_y, tracker_detection_2d->bbox_bot_right_x, tracker_detection_2d->bbox_bot_right_y, tracker_detection_2d->lat, tracker_detection_2d->lon, tracker_detection_2d->alt, tracker_detection_2d->vel_n, tracker_detection_2d->vel_e, tracker_detection_2d->vel_up);
}

/**
 * @brief Send a tracker_detection_2d message
 * @param chan MAVLink channel to send the message
 *
 * @param img_ts [us]  Time stamp of the image.
 * @param img_id   Unique ID specifiying the video frame (image) in the message sender video stream.
 * @param object_id   Unique ID representing the object. 
 * @param class_id   Unique ID specifiying the class of the object.
 * @param tracking_status   0: not tracked, 1: tracked.
 * @param confidence [%]  Confidence score in the range of [0, 100] for the classifcation.
 * @param bbox_top_left_x [c%]  Relative image x coordinate (left to right axis) in the range of [0.00, 100.00] describing the top left corner of the bounding box .
 * @param bbox_top_left_y [c%]  Relative image y coordinate (top to bottom axis) in the range of [0.00, 100.00] describing the top left corner of the bounding box.
 * @param bbox_bot_right_x [c%]  Relative image x coordinate (left to right axis) in the range of [0.00, 100.00] describing the bottom right corner of the bounding box.
 * @param bbox_bot_right_y [c%]  Relative image y coordinate (top to bottom axis) in the range of [0.00, 100.00] describing the bottom left corner of the bounding box.
 * @param lat [degE7]  Latitude in WGS84 coordinate frame of the detected object. NAN if unknown.
 * @param lon [degE7]  Longitude in WGS84 coordinate frame of the detected object. NAN if unknown.
 * @param alt [m]  Altitude in EGM96 coordiante frame of the detected object. NAN if unknown.
 * @param vel_n [m/s]  North velocity of the object in global frame. NAN if unknown.
 * @param vel_e [m/s]  East velocity of the object in global frame. NAN if unknown.
 * @param vel_up [m/s]  Up velocity of the object in global frame. NAN if unknown.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_tracker_detection_2d_send(mavlink_channel_t chan, uint64_t img_ts, uint64_t img_id, uint32_t object_id, uint32_t class_id, uint8_t tracking_status, uint8_t confidence, uint16_t bbox_top_left_x, uint16_t bbox_top_left_y, uint16_t bbox_bot_right_x, uint16_t bbox_bot_right_y, int32_t lat, int32_t lon, float alt, float vel_n, float vel_e, float vel_up)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TRACKER_DETECTION_2D_LEN];
    _mav_put_uint64_t(buf, 0, img_ts);
    _mav_put_uint64_t(buf, 8, img_id);
    _mav_put_uint32_t(buf, 16, object_id);
    _mav_put_uint32_t(buf, 20, class_id);
    _mav_put_int32_t(buf, 24, lat);
    _mav_put_int32_t(buf, 28, lon);
    _mav_put_float(buf, 32, alt);
    _mav_put_float(buf, 36, vel_n);
    _mav_put_float(buf, 40, vel_e);
    _mav_put_float(buf, 44, vel_up);
    _mav_put_uint16_t(buf, 48, bbox_top_left_x);
    _mav_put_uint16_t(buf, 50, bbox_top_left_y);
    _mav_put_uint16_t(buf, 52, bbox_bot_right_x);
    _mav_put_uint16_t(buf, 54, bbox_bot_right_y);
    _mav_put_uint8_t(buf, 56, tracking_status);
    _mav_put_uint8_t(buf, 57, confidence);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRACKER_DETECTION_2D, buf, MAVLINK_MSG_ID_TRACKER_DETECTION_2D_MIN_LEN, MAVLINK_MSG_ID_TRACKER_DETECTION_2D_LEN, MAVLINK_MSG_ID_TRACKER_DETECTION_2D_CRC);
#else
    mavlink_tracker_detection_2d_t packet;
    packet.img_ts = img_ts;
    packet.img_id = img_id;
    packet.object_id = object_id;
    packet.class_id = class_id;
    packet.lat = lat;
    packet.lon = lon;
    packet.alt = alt;
    packet.vel_n = vel_n;
    packet.vel_e = vel_e;
    packet.vel_up = vel_up;
    packet.bbox_top_left_x = bbox_top_left_x;
    packet.bbox_top_left_y = bbox_top_left_y;
    packet.bbox_bot_right_x = bbox_bot_right_x;
    packet.bbox_bot_right_y = bbox_bot_right_y;
    packet.tracking_status = tracking_status;
    packet.confidence = confidence;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRACKER_DETECTION_2D, (const char *)&packet, MAVLINK_MSG_ID_TRACKER_DETECTION_2D_MIN_LEN, MAVLINK_MSG_ID_TRACKER_DETECTION_2D_LEN, MAVLINK_MSG_ID_TRACKER_DETECTION_2D_CRC);
#endif
}

/**
 * @brief Send a tracker_detection_2d message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_tracker_detection_2d_send_struct(mavlink_channel_t chan, const mavlink_tracker_detection_2d_t* tracker_detection_2d)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_tracker_detection_2d_send(chan, tracker_detection_2d->img_ts, tracker_detection_2d->img_id, tracker_detection_2d->object_id, tracker_detection_2d->class_id, tracker_detection_2d->tracking_status, tracker_detection_2d->confidence, tracker_detection_2d->bbox_top_left_x, tracker_detection_2d->bbox_top_left_y, tracker_detection_2d->bbox_bot_right_x, tracker_detection_2d->bbox_bot_right_y, tracker_detection_2d->lat, tracker_detection_2d->lon, tracker_detection_2d->alt, tracker_detection_2d->vel_n, tracker_detection_2d->vel_e, tracker_detection_2d->vel_up);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRACKER_DETECTION_2D, (const char *)tracker_detection_2d, MAVLINK_MSG_ID_TRACKER_DETECTION_2D_MIN_LEN, MAVLINK_MSG_ID_TRACKER_DETECTION_2D_LEN, MAVLINK_MSG_ID_TRACKER_DETECTION_2D_CRC);
#endif
}

#if MAVLINK_MSG_ID_TRACKER_DETECTION_2D_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_tracker_detection_2d_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t img_ts, uint64_t img_id, uint32_t object_id, uint32_t class_id, uint8_t tracking_status, uint8_t confidence, uint16_t bbox_top_left_x, uint16_t bbox_top_left_y, uint16_t bbox_bot_right_x, uint16_t bbox_bot_right_y, int32_t lat, int32_t lon, float alt, float vel_n, float vel_e, float vel_up)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, img_ts);
    _mav_put_uint64_t(buf, 8, img_id);
    _mav_put_uint32_t(buf, 16, object_id);
    _mav_put_uint32_t(buf, 20, class_id);
    _mav_put_int32_t(buf, 24, lat);
    _mav_put_int32_t(buf, 28, lon);
    _mav_put_float(buf, 32, alt);
    _mav_put_float(buf, 36, vel_n);
    _mav_put_float(buf, 40, vel_e);
    _mav_put_float(buf, 44, vel_up);
    _mav_put_uint16_t(buf, 48, bbox_top_left_x);
    _mav_put_uint16_t(buf, 50, bbox_top_left_y);
    _mav_put_uint16_t(buf, 52, bbox_bot_right_x);
    _mav_put_uint16_t(buf, 54, bbox_bot_right_y);
    _mav_put_uint8_t(buf, 56, tracking_status);
    _mav_put_uint8_t(buf, 57, confidence);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRACKER_DETECTION_2D, buf, MAVLINK_MSG_ID_TRACKER_DETECTION_2D_MIN_LEN, MAVLINK_MSG_ID_TRACKER_DETECTION_2D_LEN, MAVLINK_MSG_ID_TRACKER_DETECTION_2D_CRC);
#else
    mavlink_tracker_detection_2d_t *packet = (mavlink_tracker_detection_2d_t *)msgbuf;
    packet->img_ts = img_ts;
    packet->img_id = img_id;
    packet->object_id = object_id;
    packet->class_id = class_id;
    packet->lat = lat;
    packet->lon = lon;
    packet->alt = alt;
    packet->vel_n = vel_n;
    packet->vel_e = vel_e;
    packet->vel_up = vel_up;
    packet->bbox_top_left_x = bbox_top_left_x;
    packet->bbox_top_left_y = bbox_top_left_y;
    packet->bbox_bot_right_x = bbox_bot_right_x;
    packet->bbox_bot_right_y = bbox_bot_right_y;
    packet->tracking_status = tracking_status;
    packet->confidence = confidence;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRACKER_DETECTION_2D, (const char *)packet, MAVLINK_MSG_ID_TRACKER_DETECTION_2D_MIN_LEN, MAVLINK_MSG_ID_TRACKER_DETECTION_2D_LEN, MAVLINK_MSG_ID_TRACKER_DETECTION_2D_CRC);
#endif
}
#endif

#endif

// MESSAGE TRACKER_DETECTION_2D UNPACKING


/**
 * @brief Get field img_ts from tracker_detection_2d message
 *
 * @return [us]  Time stamp of the image.
 */
static inline uint64_t mavlink_msg_tracker_detection_2d_get_img_ts(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field img_id from tracker_detection_2d message
 *
 * @return   Unique ID specifiying the video frame (image) in the message sender video stream.
 */
static inline uint64_t mavlink_msg_tracker_detection_2d_get_img_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  8);
}

/**
 * @brief Get field object_id from tracker_detection_2d message
 *
 * @return   Unique ID representing the object. 
 */
static inline uint32_t mavlink_msg_tracker_detection_2d_get_object_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  16);
}

/**
 * @brief Get field class_id from tracker_detection_2d message
 *
 * @return   Unique ID specifiying the class of the object.
 */
static inline uint32_t mavlink_msg_tracker_detection_2d_get_class_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  20);
}

/**
 * @brief Get field tracking_status from tracker_detection_2d message
 *
 * @return   0: not tracked, 1: tracked.
 */
static inline uint8_t mavlink_msg_tracker_detection_2d_get_tracking_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  56);
}

/**
 * @brief Get field confidence from tracker_detection_2d message
 *
 * @return [%]  Confidence score in the range of [0, 100] for the classifcation.
 */
static inline uint8_t mavlink_msg_tracker_detection_2d_get_confidence(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  57);
}

/**
 * @brief Get field bbox_top_left_x from tracker_detection_2d message
 *
 * @return [c%]  Relative image x coordinate (left to right axis) in the range of [0.00, 100.00] describing the top left corner of the bounding box .
 */
static inline uint16_t mavlink_msg_tracker_detection_2d_get_bbox_top_left_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  48);
}

/**
 * @brief Get field bbox_top_left_y from tracker_detection_2d message
 *
 * @return [c%]  Relative image y coordinate (top to bottom axis) in the range of [0.00, 100.00] describing the top left corner of the bounding box.
 */
static inline uint16_t mavlink_msg_tracker_detection_2d_get_bbox_top_left_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  50);
}

/**
 * @brief Get field bbox_bot_right_x from tracker_detection_2d message
 *
 * @return [c%]  Relative image x coordinate (left to right axis) in the range of [0.00, 100.00] describing the bottom right corner of the bounding box.
 */
static inline uint16_t mavlink_msg_tracker_detection_2d_get_bbox_bot_right_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  52);
}

/**
 * @brief Get field bbox_bot_right_y from tracker_detection_2d message
 *
 * @return [c%]  Relative image y coordinate (top to bottom axis) in the range of [0.00, 100.00] describing the bottom left corner of the bounding box.
 */
static inline uint16_t mavlink_msg_tracker_detection_2d_get_bbox_bot_right_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  54);
}

/**
 * @brief Get field lat from tracker_detection_2d message
 *
 * @return [degE7]  Latitude in WGS84 coordinate frame of the detected object. NAN if unknown.
 */
static inline int32_t mavlink_msg_tracker_detection_2d_get_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  24);
}

/**
 * @brief Get field lon from tracker_detection_2d message
 *
 * @return [degE7]  Longitude in WGS84 coordinate frame of the detected object. NAN if unknown.
 */
static inline int32_t mavlink_msg_tracker_detection_2d_get_lon(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  28);
}

/**
 * @brief Get field alt from tracker_detection_2d message
 *
 * @return [m]  Altitude in EGM96 coordiante frame of the detected object. NAN if unknown.
 */
static inline float mavlink_msg_tracker_detection_2d_get_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field vel_n from tracker_detection_2d message
 *
 * @return [m/s]  North velocity of the object in global frame. NAN if unknown.
 */
static inline float mavlink_msg_tracker_detection_2d_get_vel_n(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field vel_e from tracker_detection_2d message
 *
 * @return [m/s]  East velocity of the object in global frame. NAN if unknown.
 */
static inline float mavlink_msg_tracker_detection_2d_get_vel_e(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field vel_up from tracker_detection_2d message
 *
 * @return [m/s]  Up velocity of the object in global frame. NAN if unknown.
 */
static inline float mavlink_msg_tracker_detection_2d_get_vel_up(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Decode a tracker_detection_2d message into a struct
 *
 * @param msg The message to decode
 * @param tracker_detection_2d C-struct to decode the message contents into
 */
static inline void mavlink_msg_tracker_detection_2d_decode(const mavlink_message_t* msg, mavlink_tracker_detection_2d_t* tracker_detection_2d)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    tracker_detection_2d->img_ts = mavlink_msg_tracker_detection_2d_get_img_ts(msg);
    tracker_detection_2d->img_id = mavlink_msg_tracker_detection_2d_get_img_id(msg);
    tracker_detection_2d->object_id = mavlink_msg_tracker_detection_2d_get_object_id(msg);
    tracker_detection_2d->class_id = mavlink_msg_tracker_detection_2d_get_class_id(msg);
    tracker_detection_2d->lat = mavlink_msg_tracker_detection_2d_get_lat(msg);
    tracker_detection_2d->lon = mavlink_msg_tracker_detection_2d_get_lon(msg);
    tracker_detection_2d->alt = mavlink_msg_tracker_detection_2d_get_alt(msg);
    tracker_detection_2d->vel_n = mavlink_msg_tracker_detection_2d_get_vel_n(msg);
    tracker_detection_2d->vel_e = mavlink_msg_tracker_detection_2d_get_vel_e(msg);
    tracker_detection_2d->vel_up = mavlink_msg_tracker_detection_2d_get_vel_up(msg);
    tracker_detection_2d->bbox_top_left_x = mavlink_msg_tracker_detection_2d_get_bbox_top_left_x(msg);
    tracker_detection_2d->bbox_top_left_y = mavlink_msg_tracker_detection_2d_get_bbox_top_left_y(msg);
    tracker_detection_2d->bbox_bot_right_x = mavlink_msg_tracker_detection_2d_get_bbox_bot_right_x(msg);
    tracker_detection_2d->bbox_bot_right_y = mavlink_msg_tracker_detection_2d_get_bbox_bot_right_y(msg);
    tracker_detection_2d->tracking_status = mavlink_msg_tracker_detection_2d_get_tracking_status(msg);
    tracker_detection_2d->confidence = mavlink_msg_tracker_detection_2d_get_confidence(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TRACKER_DETECTION_2D_LEN? msg->len : MAVLINK_MSG_ID_TRACKER_DETECTION_2D_LEN;
        memset(tracker_detection_2d, 0, MAVLINK_MSG_ID_TRACKER_DETECTION_2D_LEN);
    memcpy(tracker_detection_2d, _MAV_PAYLOAD(msg), len);
#endif
}
