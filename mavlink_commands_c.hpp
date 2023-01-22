#ifndef MAVLINK_COMMANDS_C_HPP
#define MAVLINK_COMMNADS_C_HPP

#include "common/mavlink.h"
#include <HardwareSerial.h>

extern uint8_t px_mode;
extern uint8_t px_status;
extern uint8_t sys_id; // GCS id
extern uint8_t comp_id; // any?
extern uint8_t tgt_sys; // id of pxhawk = 1
extern uint8_t tgt_comp; // 0 broadcast, 1 work juga
extern uint16_t mis_seq;
extern uint16_t mis_progress;

// Set data requests from pixhawk
void req_data_stream();

// Read data from pixhawk via UART2
void read_data();

// Check pixhawks current mode
void check_mode(mavlink_message_t* msg);

// Accept a mission request and send a mission item
void mission_request(mavlink_message_t* msg);

// Check mission items reached
void check_mission_progress(mavlink_message_t* msg);

// Check whether uploaded mission is accepted
void uploaded_mission_status(mavlink_message_t* msg);

// Takeoff
void takeoff(const float height);

// Land
void land();

// Arms or disarms the drone (true == arm, false == disarm)
void arm_disarm(bool arm);

// Sends 1 mission item
void send_mission_item(const float lat, const float lng, const float height);

// Set mode (use MAV_MODE enum for parameter)
void set_mode(const uint16_t mode);

// Return to launch position (without land)
void return_to_launch();

// Send mission count (needed for pixhawk to start requesting mission)
void send_mission_count(const uint16_t num_of_mission);

void start_mission();

#endif
