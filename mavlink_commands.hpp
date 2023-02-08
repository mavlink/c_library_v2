#include "common/mavlink.h"
#include <HardwareSerial.h>
#include <vector>
#include <array>

class MAVLink{
  public : 
    uint16_t mis_count;
    std::vector<std::tuple<float, float, float>> waypoints;

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

    // Set data requests from pixhawk
    void req_data_stream();

    // Read data from pixhawk via UART2
    void read_data();

    // Takeoff
    void takeoff(const float& height);

    // Land
    void land();

    // Set mode (use MAV_MODE enum for parameter)
    void set_mode(const uint16_t& mode);

    // Return to launch position (without land)
    void return_to_launch();

    // Send mission count (needed for pixhawk to start requesting mission)
    void send_mission_count(const uint16_t& num_of_mission);

    // Starts mission
    void start_mission();

    // Sends 1 mission item
    void send_mission_item();

    // Arms or disarms the drone (true == arm, false == disarm)
    void arm_disarm(bool arm);

  private :
    uint8_t px_mode;
    uint8_t px_status;
    uint8_t sys_id; // GCS id
    uint8_t comp_id; // any?
    uint8_t tgt_sys; // id of pxhawk = 1
    uint8_t tgt_comp; // 0 broadcast, 1 work juga
    uint16_t mis_seq;
    std::array<float, 3> global_pos_curr; //lat, long, relative alt
    std::array<float, 3> velocity_curr; // velocity north, velocity east, velocity down
    uint16_t yaw_curr;
    float time_boot_sec;
    bool req_mis;

    // Check pixhawks current mode
    void check_mode(mavlink_message_t* msg);

    // Accept a mission request and send a mission item
    void mission_request(mavlink_message_t* msg);

    // Check mission items reached
    void check_mission_progress(mavlink_message_t* msg);

    // Check whether uploaded mission is accepted
    void uploaded_mission_status(mavlink_message_t* msg);

    // Check whether command was successfuly accepted
    void command_ack(mavlink_message_t* msg);

    // Results of prearm checks
    void sys_status(mavlink_message_t* msg);

    // Receive current global pos and velocity
    void recv_global_pos(mavlink_message_t * msg);

    // Status of currently run mission
    void current_mission_status(mavlink_message_t* msg);

    // Get downloaded mission count
    void recv_mission_count(mavlink_message_t* msg);

    // Get downloaded missions
    void recv_mission(mavlink_message_t* msg);

    // Run pre-arm checks
    void run_prearm_checks();

    // Downloads mission from pixhawk
    void req_mission_list();

    // Requests a mission item
    void req_mission_item();

    // Sends mission download acknowledgement
    void send_mission_ack();

};