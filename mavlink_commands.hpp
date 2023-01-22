#include "common/mavlink.h"
#include <HardwareSerial.h>

class Mavlink{
  public : 
    // Setup serial communication
    Mavlink(const int& baud_rate, const uint8_t& tx, const uint8_t& rx);

    ~Mavlink();

    uint8_t get_px_mode();

    uint8_t get_px_status();

    uint16_t get_mis_prog();

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

    void start_mission();

    // Sends 1 mission item
    void send_mission_item(const float& lat, const float& lng, const float& height);

  private :
    uint8_t px_mode;
    uint8_t px_status;
    uint8_t sys_id; // GCS id
    uint8_t comp_id; // any?
    uint8_t tgt_sys; // id of pxhawk = 1
    uint8_t tgt_comp; // 0 broadcast, 1 work juga
    uint16_t mis_seq;
    uint16_t mis_progress;
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

    // Arms or disarms the drone (true == arm, false == disarm)
    void arm_disarm(bool arm);
};