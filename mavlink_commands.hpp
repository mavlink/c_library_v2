#include "common/mavlink.h"
#include <HardwareSerial.h>
#include <Arduino.h>

#include <vector>
#include <array>
#include <memory>
#include <chrono>

class MAVLink{
  public :

    uint16_t mis_count;

    // Setup serial communication
    MAVLink(const int& baud_rate, const uint8_t& rx, const uint8_t& tx);

    ~MAVLink();

    uint8_t get_px_mode();

    uint8_t get_px_status();

    std::array<float, 3> get_global_pos_curr();

    std::array<float, 3> get_velocity_curr();

    float get_time_boot();

    uint16_t get_yaw_curr();

    uint16_t get_mis_seq();

    bool get_mis_req_status();

    void add_waypoint(float lat, float lng, float hgt);

    // Set data requests from pixhawk
    void req_data_stream();

    void req_data(uint16_t msg_id);

    // Read data from pixhawk via UART2
    void read_data();

    // Takeoff
    void takeoff(const float& height);

    // Land
    void land();

    // Hold position for a certain amount of time
    void loiter_time(const uint16_t& time, const float& lat, const float& longitude, const float& alt);
    
    // Set mode (use MAV_MODE enum for parameter)
    void set_mode(const uint16_t& mode);

    // Return to launch position (without land)
    void return_to_launch();

    // Send mission count (needed for pixhawk to start requesting mission)
    void send_mission_count(const uint16_t& num_of_mission = 0);

    // Clear All Mission
    void clear_all_mission();

    // Starts mission
    void start_mission();

    // Sends 1 mission item
    void send_mission_item();

    // Arms or disarms the drone (true == arm, false == disarm)
    void arm_disarm(bool arm);

    void timeout(uint32_t duration);

    void set_servo(uint8_t port, uint16_t pwm);

  private :
    uint8_t px_mode;
    uint8_t px_status;
    uint8_t sys_id; // GCS id
    uint8_t comp_id; // any?
    uint8_t tgt_sys; // id of pxhawk = 1
    uint8_t tgt_comp; // 0 broadcast, 1 work juga
    uint8_t mis_status;
    uint16_t reached;
    uint16_t mis_seq;
    std::array<int32_t, 2> home_pos;
    std::array<float, 3> global_pos_curr; //lat, long, relative alt
    std::array<float, 3> velocity_curr; // velocity north, velocity east, velocity down
    uint16_t yaw_curr;
    float time_boot_sec;
    bool req_mis;
    bool armed;
    bool home_set = false;
    std::vector<std::tuple<float, float, float>> waypoints;

    // Check pixhawks current mode
    void parse_heartbeat(mavlink_message_t* msg);

    // Accept a mission request (int32) and send a mission item
    void parse_mission_request_int(mavlink_message_t* msg);

    // Accept a mission reqeuest (float) and send a mission item
    void parse_mission_request(mavlink_message_t* msg);

    // Check mission items reached
    void parse_mission_progress(mavlink_message_t* msg);

    // Check whether uploaded mission is accepted
    void parse_mission_ack(mavlink_message_t* msg);

    // Check whether command was successfuly accepted
    void parse_command_ack(mavlink_message_t* msg);

    // Results of prearm checks
    void parse_sys_status(mavlink_message_t* msg);

    // Receive current global pos and velocity
    void parse_global_pos(mavlink_message_t * msg);

    // Status of currently run mission
    void parse_mission_status(mavlink_message_t* msg);

    // Get downloaded mission count
    void parse_mission_count(mavlink_message_t* msg);

    // Get downloaded missions
    void parse_mission_item(mavlink_message_t* msg);

    void parse_home_position(mavlink_message_t* msg);

    // Run pre-arm checks
    void run_prearm_checks();

    // Downloads mission from pixhawk
    void req_mission_list();

    // Requests a mission item
    void req_mission_item();

    // Sends mission download acknowledgement
    void send_mission_ack();

};
