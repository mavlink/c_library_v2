#pragma once
// MESSAGE JOYSTICK_INFORMATION PACKING

#define MAVLINK_MSG_ID_JOYSTICK_INFORMATION 514


typedef struct __mavlink_joystick_information_t {
 uint64_t time_usec; /*< [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.*/
 uint16_t axis_shift; /*<  Axis shift to positive direction, before multiplying and sending as integer in joystick status.*/
 uint16_t axis_multiplier; /*<  Axis value is first shifted, then multipled by this number before sending in the joystick state as an integer*/
 uint16_t joy_definition_version; /*<  Joystick definition version (iteration)*/
 uint8_t vendor_name[32]; /*<  Name of the joystick vendor*/
 uint8_t model_name[32]; /*<  Name of the joystick model*/
 uint8_t number_of_axes; /*<  Number of joystick axes*/
 uint8_t number_of_buttons; /*<  Number of joystick buttons*/
 uint8_t button_trigger_value; /*<  Value of button when triggered*/
 uint8_t button_release_value; /*<  Value of button when release*/
 char joy_definition_uri[140]; /*<  Joystick definition URI (if any, otherwise only basic functions will be available). HTTP- (http://) and MAVLink FTP- (mavlinkftp://) formatted URIs are allowed (and both must be supported by any GCS that implements the Camera Protocol). The definition file may be xz compressed, which will be indicated by the file extension .xml.xz (a GCS that implements the protocol must support decompressing the file). The string needs to be zero terminated.*/
} mavlink_joystick_information_t;

#define MAVLINK_MSG_ID_JOYSTICK_INFORMATION_LEN 222
#define MAVLINK_MSG_ID_JOYSTICK_INFORMATION_MIN_LEN 222
#define MAVLINK_MSG_ID_514_LEN 222
#define MAVLINK_MSG_ID_514_MIN_LEN 222

#define MAVLINK_MSG_ID_JOYSTICK_INFORMATION_CRC 14
#define MAVLINK_MSG_ID_514_CRC 14

#define MAVLINK_MSG_JOYSTICK_INFORMATION_FIELD_VENDOR_NAME_LEN 32
#define MAVLINK_MSG_JOYSTICK_INFORMATION_FIELD_MODEL_NAME_LEN 32
#define MAVLINK_MSG_JOYSTICK_INFORMATION_FIELD_JOY_DEFINITION_URI_LEN 140

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_JOYSTICK_INFORMATION { \
    514, \
    "JOYSTICK_INFORMATION", \
    11, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_joystick_information_t, time_usec) }, \
         { "vendor_name", NULL, MAVLINK_TYPE_UINT8_T, 32, 14, offsetof(mavlink_joystick_information_t, vendor_name) }, \
         { "model_name", NULL, MAVLINK_TYPE_UINT8_T, 32, 46, offsetof(mavlink_joystick_information_t, model_name) }, \
         { "number_of_axes", NULL, MAVLINK_TYPE_UINT8_T, 0, 78, offsetof(mavlink_joystick_information_t, number_of_axes) }, \
         { "number_of_buttons", NULL, MAVLINK_TYPE_UINT8_T, 0, 79, offsetof(mavlink_joystick_information_t, number_of_buttons) }, \
         { "button_trigger_value", NULL, MAVLINK_TYPE_UINT8_T, 0, 80, offsetof(mavlink_joystick_information_t, button_trigger_value) }, \
         { "button_release_value", NULL, MAVLINK_TYPE_UINT8_T, 0, 81, offsetof(mavlink_joystick_information_t, button_release_value) }, \
         { "axis_shift", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_joystick_information_t, axis_shift) }, \
         { "axis_multiplier", NULL, MAVLINK_TYPE_UINT16_T, 0, 10, offsetof(mavlink_joystick_information_t, axis_multiplier) }, \
         { "joy_definition_version", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_joystick_information_t, joy_definition_version) }, \
         { "joy_definition_uri", NULL, MAVLINK_TYPE_CHAR, 140, 82, offsetof(mavlink_joystick_information_t, joy_definition_uri) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_JOYSTICK_INFORMATION { \
    "JOYSTICK_INFORMATION", \
    11, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_joystick_information_t, time_usec) }, \
         { "vendor_name", NULL, MAVLINK_TYPE_UINT8_T, 32, 14, offsetof(mavlink_joystick_information_t, vendor_name) }, \
         { "model_name", NULL, MAVLINK_TYPE_UINT8_T, 32, 46, offsetof(mavlink_joystick_information_t, model_name) }, \
         { "number_of_axes", NULL, MAVLINK_TYPE_UINT8_T, 0, 78, offsetof(mavlink_joystick_information_t, number_of_axes) }, \
         { "number_of_buttons", NULL, MAVLINK_TYPE_UINT8_T, 0, 79, offsetof(mavlink_joystick_information_t, number_of_buttons) }, \
         { "button_trigger_value", NULL, MAVLINK_TYPE_UINT8_T, 0, 80, offsetof(mavlink_joystick_information_t, button_trigger_value) }, \
         { "button_release_value", NULL, MAVLINK_TYPE_UINT8_T, 0, 81, offsetof(mavlink_joystick_information_t, button_release_value) }, \
         { "axis_shift", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_joystick_information_t, axis_shift) }, \
         { "axis_multiplier", NULL, MAVLINK_TYPE_UINT16_T, 0, 10, offsetof(mavlink_joystick_information_t, axis_multiplier) }, \
         { "joy_definition_version", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_joystick_information_t, joy_definition_version) }, \
         { "joy_definition_uri", NULL, MAVLINK_TYPE_CHAR, 140, 82, offsetof(mavlink_joystick_information_t, joy_definition_uri) }, \
         } \
}
#endif

/**
 * @brief Pack a joystick_information message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param vendor_name  Name of the joystick vendor
 * @param model_name  Name of the joystick model
 * @param number_of_axes  Number of joystick axes
 * @param number_of_buttons  Number of joystick buttons
 * @param button_trigger_value  Value of button when triggered
 * @param button_release_value  Value of button when release
 * @param axis_shift  Axis shift to positive direction, before multiplying and sending as integer in joystick status.
 * @param axis_multiplier  Axis value is first shifted, then multipled by this number before sending in the joystick state as an integer
 * @param joy_definition_version  Joystick definition version (iteration)
 * @param joy_definition_uri  Joystick definition URI (if any, otherwise only basic functions will be available). HTTP- (http://) and MAVLink FTP- (mavlinkftp://) formatted URIs are allowed (and both must be supported by any GCS that implements the Camera Protocol). The definition file may be xz compressed, which will be indicated by the file extension .xml.xz (a GCS that implements the protocol must support decompressing the file). The string needs to be zero terminated.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_joystick_information_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, const uint8_t *vendor_name, const uint8_t *model_name, uint8_t number_of_axes, uint8_t number_of_buttons, uint8_t button_trigger_value, uint8_t button_release_value, uint16_t axis_shift, uint16_t axis_multiplier, uint16_t joy_definition_version, const char *joy_definition_uri)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_JOYSTICK_INFORMATION_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint16_t(buf, 8, axis_shift);
    _mav_put_uint16_t(buf, 10, axis_multiplier);
    _mav_put_uint16_t(buf, 12, joy_definition_version);
    _mav_put_uint8_t(buf, 78, number_of_axes);
    _mav_put_uint8_t(buf, 79, number_of_buttons);
    _mav_put_uint8_t(buf, 80, button_trigger_value);
    _mav_put_uint8_t(buf, 81, button_release_value);
    _mav_put_uint8_t_array(buf, 14, vendor_name, 32);
    _mav_put_uint8_t_array(buf, 46, model_name, 32);
    _mav_put_char_array(buf, 82, joy_definition_uri, 140);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_JOYSTICK_INFORMATION_LEN);
#else
    mavlink_joystick_information_t packet;
    packet.time_usec = time_usec;
    packet.axis_shift = axis_shift;
    packet.axis_multiplier = axis_multiplier;
    packet.joy_definition_version = joy_definition_version;
    packet.number_of_axes = number_of_axes;
    packet.number_of_buttons = number_of_buttons;
    packet.button_trigger_value = button_trigger_value;
    packet.button_release_value = button_release_value;
    mav_array_memcpy(packet.vendor_name, vendor_name, sizeof(uint8_t)*32);
    mav_array_memcpy(packet.model_name, model_name, sizeof(uint8_t)*32);
    mav_array_memcpy(packet.joy_definition_uri, joy_definition_uri, sizeof(char)*140);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_JOYSTICK_INFORMATION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_JOYSTICK_INFORMATION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_JOYSTICK_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_JOYSTICK_INFORMATION_LEN, MAVLINK_MSG_ID_JOYSTICK_INFORMATION_CRC);
}

/**
 * @brief Pack a joystick_information message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param vendor_name  Name of the joystick vendor
 * @param model_name  Name of the joystick model
 * @param number_of_axes  Number of joystick axes
 * @param number_of_buttons  Number of joystick buttons
 * @param button_trigger_value  Value of button when triggered
 * @param button_release_value  Value of button when release
 * @param axis_shift  Axis shift to positive direction, before multiplying and sending as integer in joystick status.
 * @param axis_multiplier  Axis value is first shifted, then multipled by this number before sending in the joystick state as an integer
 * @param joy_definition_version  Joystick definition version (iteration)
 * @param joy_definition_uri  Joystick definition URI (if any, otherwise only basic functions will be available). HTTP- (http://) and MAVLink FTP- (mavlinkftp://) formatted URIs are allowed (and both must be supported by any GCS that implements the Camera Protocol). The definition file may be xz compressed, which will be indicated by the file extension .xml.xz (a GCS that implements the protocol must support decompressing the file). The string needs to be zero terminated.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_joystick_information_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,const uint8_t *vendor_name,const uint8_t *model_name,uint8_t number_of_axes,uint8_t number_of_buttons,uint8_t button_trigger_value,uint8_t button_release_value,uint16_t axis_shift,uint16_t axis_multiplier,uint16_t joy_definition_version,const char *joy_definition_uri)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_JOYSTICK_INFORMATION_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint16_t(buf, 8, axis_shift);
    _mav_put_uint16_t(buf, 10, axis_multiplier);
    _mav_put_uint16_t(buf, 12, joy_definition_version);
    _mav_put_uint8_t(buf, 78, number_of_axes);
    _mav_put_uint8_t(buf, 79, number_of_buttons);
    _mav_put_uint8_t(buf, 80, button_trigger_value);
    _mav_put_uint8_t(buf, 81, button_release_value);
    _mav_put_uint8_t_array(buf, 14, vendor_name, 32);
    _mav_put_uint8_t_array(buf, 46, model_name, 32);
    _mav_put_char_array(buf, 82, joy_definition_uri, 140);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_JOYSTICK_INFORMATION_LEN);
#else
    mavlink_joystick_information_t packet;
    packet.time_usec = time_usec;
    packet.axis_shift = axis_shift;
    packet.axis_multiplier = axis_multiplier;
    packet.joy_definition_version = joy_definition_version;
    packet.number_of_axes = number_of_axes;
    packet.number_of_buttons = number_of_buttons;
    packet.button_trigger_value = button_trigger_value;
    packet.button_release_value = button_release_value;
    mav_array_memcpy(packet.vendor_name, vendor_name, sizeof(uint8_t)*32);
    mav_array_memcpy(packet.model_name, model_name, sizeof(uint8_t)*32);
    mav_array_memcpy(packet.joy_definition_uri, joy_definition_uri, sizeof(char)*140);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_JOYSTICK_INFORMATION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_JOYSTICK_INFORMATION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_JOYSTICK_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_JOYSTICK_INFORMATION_LEN, MAVLINK_MSG_ID_JOYSTICK_INFORMATION_CRC);
}

/**
 * @brief Encode a joystick_information struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param joystick_information C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_joystick_information_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_joystick_information_t* joystick_information)
{
    return mavlink_msg_joystick_information_pack(system_id, component_id, msg, joystick_information->time_usec, joystick_information->vendor_name, joystick_information->model_name, joystick_information->number_of_axes, joystick_information->number_of_buttons, joystick_information->button_trigger_value, joystick_information->button_release_value, joystick_information->axis_shift, joystick_information->axis_multiplier, joystick_information->joy_definition_version, joystick_information->joy_definition_uri);
}

/**
 * @brief Encode a joystick_information struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param joystick_information C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_joystick_information_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_joystick_information_t* joystick_information)
{
    return mavlink_msg_joystick_information_pack_chan(system_id, component_id, chan, msg, joystick_information->time_usec, joystick_information->vendor_name, joystick_information->model_name, joystick_information->number_of_axes, joystick_information->number_of_buttons, joystick_information->button_trigger_value, joystick_information->button_release_value, joystick_information->axis_shift, joystick_information->axis_multiplier, joystick_information->joy_definition_version, joystick_information->joy_definition_uri);
}

/**
 * @brief Send a joystick_information message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 * @param vendor_name  Name of the joystick vendor
 * @param model_name  Name of the joystick model
 * @param number_of_axes  Number of joystick axes
 * @param number_of_buttons  Number of joystick buttons
 * @param button_trigger_value  Value of button when triggered
 * @param button_release_value  Value of button when release
 * @param axis_shift  Axis shift to positive direction, before multiplying and sending as integer in joystick status.
 * @param axis_multiplier  Axis value is first shifted, then multipled by this number before sending in the joystick state as an integer
 * @param joy_definition_version  Joystick definition version (iteration)
 * @param joy_definition_uri  Joystick definition URI (if any, otherwise only basic functions will be available). HTTP- (http://) and MAVLink FTP- (mavlinkftp://) formatted URIs are allowed (and both must be supported by any GCS that implements the Camera Protocol). The definition file may be xz compressed, which will be indicated by the file extension .xml.xz (a GCS that implements the protocol must support decompressing the file). The string needs to be zero terminated.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_joystick_information_send(mavlink_channel_t chan, uint64_t time_usec, const uint8_t *vendor_name, const uint8_t *model_name, uint8_t number_of_axes, uint8_t number_of_buttons, uint8_t button_trigger_value, uint8_t button_release_value, uint16_t axis_shift, uint16_t axis_multiplier, uint16_t joy_definition_version, const char *joy_definition_uri)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_JOYSTICK_INFORMATION_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint16_t(buf, 8, axis_shift);
    _mav_put_uint16_t(buf, 10, axis_multiplier);
    _mav_put_uint16_t(buf, 12, joy_definition_version);
    _mav_put_uint8_t(buf, 78, number_of_axes);
    _mav_put_uint8_t(buf, 79, number_of_buttons);
    _mav_put_uint8_t(buf, 80, button_trigger_value);
    _mav_put_uint8_t(buf, 81, button_release_value);
    _mav_put_uint8_t_array(buf, 14, vendor_name, 32);
    _mav_put_uint8_t_array(buf, 46, model_name, 32);
    _mav_put_char_array(buf, 82, joy_definition_uri, 140);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_JOYSTICK_INFORMATION, buf, MAVLINK_MSG_ID_JOYSTICK_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_JOYSTICK_INFORMATION_LEN, MAVLINK_MSG_ID_JOYSTICK_INFORMATION_CRC);
#else
    mavlink_joystick_information_t packet;
    packet.time_usec = time_usec;
    packet.axis_shift = axis_shift;
    packet.axis_multiplier = axis_multiplier;
    packet.joy_definition_version = joy_definition_version;
    packet.number_of_axes = number_of_axes;
    packet.number_of_buttons = number_of_buttons;
    packet.button_trigger_value = button_trigger_value;
    packet.button_release_value = button_release_value;
    mav_array_memcpy(packet.vendor_name, vendor_name, sizeof(uint8_t)*32);
    mav_array_memcpy(packet.model_name, model_name, sizeof(uint8_t)*32);
    mav_array_memcpy(packet.joy_definition_uri, joy_definition_uri, sizeof(char)*140);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_JOYSTICK_INFORMATION, (const char *)&packet, MAVLINK_MSG_ID_JOYSTICK_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_JOYSTICK_INFORMATION_LEN, MAVLINK_MSG_ID_JOYSTICK_INFORMATION_CRC);
#endif
}

/**
 * @brief Send a joystick_information message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_joystick_information_send_struct(mavlink_channel_t chan, const mavlink_joystick_information_t* joystick_information)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_joystick_information_send(chan, joystick_information->time_usec, joystick_information->vendor_name, joystick_information->model_name, joystick_information->number_of_axes, joystick_information->number_of_buttons, joystick_information->button_trigger_value, joystick_information->button_release_value, joystick_information->axis_shift, joystick_information->axis_multiplier, joystick_information->joy_definition_version, joystick_information->joy_definition_uri);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_JOYSTICK_INFORMATION, (const char *)joystick_information, MAVLINK_MSG_ID_JOYSTICK_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_JOYSTICK_INFORMATION_LEN, MAVLINK_MSG_ID_JOYSTICK_INFORMATION_CRC);
#endif
}

#if MAVLINK_MSG_ID_JOYSTICK_INFORMATION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_joystick_information_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, const uint8_t *vendor_name, const uint8_t *model_name, uint8_t number_of_axes, uint8_t number_of_buttons, uint8_t button_trigger_value, uint8_t button_release_value, uint16_t axis_shift, uint16_t axis_multiplier, uint16_t joy_definition_version, const char *joy_definition_uri)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint16_t(buf, 8, axis_shift);
    _mav_put_uint16_t(buf, 10, axis_multiplier);
    _mav_put_uint16_t(buf, 12, joy_definition_version);
    _mav_put_uint8_t(buf, 78, number_of_axes);
    _mav_put_uint8_t(buf, 79, number_of_buttons);
    _mav_put_uint8_t(buf, 80, button_trigger_value);
    _mav_put_uint8_t(buf, 81, button_release_value);
    _mav_put_uint8_t_array(buf, 14, vendor_name, 32);
    _mav_put_uint8_t_array(buf, 46, model_name, 32);
    _mav_put_char_array(buf, 82, joy_definition_uri, 140);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_JOYSTICK_INFORMATION, buf, MAVLINK_MSG_ID_JOYSTICK_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_JOYSTICK_INFORMATION_LEN, MAVLINK_MSG_ID_JOYSTICK_INFORMATION_CRC);
#else
    mavlink_joystick_information_t *packet = (mavlink_joystick_information_t *)msgbuf;
    packet->time_usec = time_usec;
    packet->axis_shift = axis_shift;
    packet->axis_multiplier = axis_multiplier;
    packet->joy_definition_version = joy_definition_version;
    packet->number_of_axes = number_of_axes;
    packet->number_of_buttons = number_of_buttons;
    packet->button_trigger_value = button_trigger_value;
    packet->button_release_value = button_release_value;
    mav_array_memcpy(packet->vendor_name, vendor_name, sizeof(uint8_t)*32);
    mav_array_memcpy(packet->model_name, model_name, sizeof(uint8_t)*32);
    mav_array_memcpy(packet->joy_definition_uri, joy_definition_uri, sizeof(char)*140);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_JOYSTICK_INFORMATION, (const char *)packet, MAVLINK_MSG_ID_JOYSTICK_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_JOYSTICK_INFORMATION_LEN, MAVLINK_MSG_ID_JOYSTICK_INFORMATION_CRC);
#endif
}
#endif

#endif

// MESSAGE JOYSTICK_INFORMATION UNPACKING


/**
 * @brief Get field time_usec from joystick_information message
 *
 * @return [us] Timestamp (UNIX Epoch time or time since system boot). The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the magnitude of the number.
 */
static inline uint64_t mavlink_msg_joystick_information_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field vendor_name from joystick_information message
 *
 * @return  Name of the joystick vendor
 */
static inline uint16_t mavlink_msg_joystick_information_get_vendor_name(const mavlink_message_t* msg, uint8_t *vendor_name)
{
    return _MAV_RETURN_uint8_t_array(msg, vendor_name, 32,  14);
}

/**
 * @brief Get field model_name from joystick_information message
 *
 * @return  Name of the joystick model
 */
static inline uint16_t mavlink_msg_joystick_information_get_model_name(const mavlink_message_t* msg, uint8_t *model_name)
{
    return _MAV_RETURN_uint8_t_array(msg, model_name, 32,  46);
}

/**
 * @brief Get field number_of_axes from joystick_information message
 *
 * @return  Number of joystick axes
 */
static inline uint8_t mavlink_msg_joystick_information_get_number_of_axes(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  78);
}

/**
 * @brief Get field number_of_buttons from joystick_information message
 *
 * @return  Number of joystick buttons
 */
static inline uint8_t mavlink_msg_joystick_information_get_number_of_buttons(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  79);
}

/**
 * @brief Get field button_trigger_value from joystick_information message
 *
 * @return  Value of button when triggered
 */
static inline uint8_t mavlink_msg_joystick_information_get_button_trigger_value(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  80);
}

/**
 * @brief Get field button_release_value from joystick_information message
 *
 * @return  Value of button when release
 */
static inline uint8_t mavlink_msg_joystick_information_get_button_release_value(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  81);
}

/**
 * @brief Get field axis_shift from joystick_information message
 *
 * @return  Axis shift to positive direction, before multiplying and sending as integer in joystick status.
 */
static inline uint16_t mavlink_msg_joystick_information_get_axis_shift(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Get field axis_multiplier from joystick_information message
 *
 * @return  Axis value is first shifted, then multipled by this number before sending in the joystick state as an integer
 */
static inline uint16_t mavlink_msg_joystick_information_get_axis_multiplier(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  10);
}

/**
 * @brief Get field joy_definition_version from joystick_information message
 *
 * @return  Joystick definition version (iteration)
 */
static inline uint16_t mavlink_msg_joystick_information_get_joy_definition_version(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  12);
}

/**
 * @brief Get field joy_definition_uri from joystick_information message
 *
 * @return  Joystick definition URI (if any, otherwise only basic functions will be available). HTTP- (http://) and MAVLink FTP- (mavlinkftp://) formatted URIs are allowed (and both must be supported by any GCS that implements the Camera Protocol). The definition file may be xz compressed, which will be indicated by the file extension .xml.xz (a GCS that implements the protocol must support decompressing the file). The string needs to be zero terminated.
 */
static inline uint16_t mavlink_msg_joystick_information_get_joy_definition_uri(const mavlink_message_t* msg, char *joy_definition_uri)
{
    return _MAV_RETURN_char_array(msg, joy_definition_uri, 140,  82);
}

/**
 * @brief Decode a joystick_information message into a struct
 *
 * @param msg The message to decode
 * @param joystick_information C-struct to decode the message contents into
 */
static inline void mavlink_msg_joystick_information_decode(const mavlink_message_t* msg, mavlink_joystick_information_t* joystick_information)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    joystick_information->time_usec = mavlink_msg_joystick_information_get_time_usec(msg);
    joystick_information->axis_shift = mavlink_msg_joystick_information_get_axis_shift(msg);
    joystick_information->axis_multiplier = mavlink_msg_joystick_information_get_axis_multiplier(msg);
    joystick_information->joy_definition_version = mavlink_msg_joystick_information_get_joy_definition_version(msg);
    mavlink_msg_joystick_information_get_vendor_name(msg, joystick_information->vendor_name);
    mavlink_msg_joystick_information_get_model_name(msg, joystick_information->model_name);
    joystick_information->number_of_axes = mavlink_msg_joystick_information_get_number_of_axes(msg);
    joystick_information->number_of_buttons = mavlink_msg_joystick_information_get_number_of_buttons(msg);
    joystick_information->button_trigger_value = mavlink_msg_joystick_information_get_button_trigger_value(msg);
    joystick_information->button_release_value = mavlink_msg_joystick_information_get_button_release_value(msg);
    mavlink_msg_joystick_information_get_joy_definition_uri(msg, joystick_information->joy_definition_uri);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_JOYSTICK_INFORMATION_LEN? msg->len : MAVLINK_MSG_ID_JOYSTICK_INFORMATION_LEN;
        memset(joystick_information, 0, MAVLINK_MSG_ID_JOYSTICK_INFORMATION_LEN);
    memcpy(joystick_information, _MAV_PAYLOAD(msg), len);
#endif
}
