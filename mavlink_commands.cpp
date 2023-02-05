#include "mavlink_commands.hpp"

Mavlink::Mavlink(const int& baud_rate, const uint8_t& tx, const uint8_t& rx){
  Serial2.begin(baud_rate, SERIAL_8N1, tx, rx);
}

Mavlink::~Mavlink() {}

uint8_t Mavlink::get_px_mode(){
  return this->px_mode;
}

uint8_t Mavlink::get_px_status(){
  return this->px_status;
}

uint16_t Mavlink::get_mis_prog(){
  return this->mis_progress;
}

uint16_t Mavlink::get_mis_seq(){
  return this->mis_seq;
}

bool Mavlink::get_mis_req_status(){
  return this->req_mis;
}

void Mavlink::req_data_stream(){
  this->sys_id = 255;
  this->comp_id = 2;
  this->tgt_sys = 1;
  this->tgt_comp = 1;
  uint8_t req_stream_id = MAV_DATA_STREAM_ALL;
  uint16_t req_msg_rate = 0x01; // 1 times per second
  uint8_t start_stop = 1; // 1 start, 0 = stop

  mavlink_message_t msg;
  uint8_t buf[MAVLINK_MAX_PACKET_LEN];

  mavlink_msg_request_data_stream_pack(
    this->sys_id, 
    this->comp_id, 
    &msg, 
    this->tgt_sys, 
    this->tgt_comp, 
    req_stream_id, 
    req_msg_rate, 
    start_stop
  );
  uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);  // Send the message (.write sends as bytes)
  
  Serial2.write(buf, len);
}

void Mavlink::read_data(){
  mavlink_message_t msg;
  mavlink_status_t status;

  while(Serial2.available())
  {
    uint8_t c = Serial2.read();

    //Get new message
    if(mavlink_parse_char(MAVLINK_COMM_0, c, &msg, &status))
    {

    //Handle new message from autopilot
      switch(msg.msgid)
      {
        case MAVLINK_MSG_ID_HEARTBEAT:
          this->check_mode(&msg);
          break;
        case MAVLINK_MSG_ID_MISSION_REQUEST_INT:
          this->mission_request(&msg);
          break;
        case MAVLINK_MSG_ID_MISSION_ACK:
          this->uploaded_mission_status(&msg);
          break;
        case MAVLINK_MSG_ID_MISSION_ITEM_REACHED:
          this->check_mission_progress(&msg);
          break;
        case MAVLINK_MSG_ID_COMMAND_ACK:
          this->command_ack(&msg);
          break;
        case MAVLINK_MSG_ID_SYS_STATUS:
          this->sys_status(&msg);
          break;
      }
    }
  }
}

void Mavlink::check_mode(mavlink_message_t* msg){
  mavlink_heartbeat_t hb;
  mavlink_msg_heartbeat_decode(msg, &hb);
  this->px_mode = hb.base_mode;
  this->px_status = hb.system_status;
  Serial.println("Heartbeat detected");
}

void Mavlink::command_ack(mavlink_message_t* msg){
  mavlink_command_ack_t cmd_ack;
  mavlink_msg_command_ack_decode(msg, &cmd_ack);
  Serial.printf("Command %u result code %u\n", cmd_ack.command, cmd_ack.result);
}

void Mavlink::mission_request(mavlink_message_t* msg){
  mavlink_mission_request_int_t mis_req;
  mavlink_msg_mission_request_int_decode(msg, &mis_req);
  this->mis_seq = mis_req.seq;
  this->tgt_sys = mis_req.target_system;
  this->tgt_comp = mis_req.target_component;
  Serial.printf("Requesting for mission type %u sequence %u\n", mis_req.mission_type, this->mis_seq);
  this->req_mis = true;
}

void Mavlink::check_mission_progress(mavlink_message_t* msg){
  mavlink_mission_item_reached_t it;
  mavlink_msg_mission_item_reached_decode(msg, &it);
  this->mis_progress = it.seq;
  Serial.printf("Mission sequence %u reached\n", this->mis_progress);
}

void Mavlink::uploaded_mission_status(mavlink_message_t* msg){
  mavlink_mission_ack_t mis_ack;
  mavlink_msg_mission_ack_decode(msg, &mis_ack);
  if(mis_ack.type == MAV_MISSION_ACCEPTED){
    Serial.println("Mission accepted");
  }else{
    Serial.printf("Mission unaccepted with enum %u\n", mis_ack.type);
  }
}

void sys_status(mavlink_message_t * msg){
  mavlink_sys_status_t sys_status;
  mavlink_msg_sys_status_decode(msg, &sys_status);
  Serial.printf(
    "Sensors Present : %u\n
    Sensors Enabled : %u\n
    Sensors Healthy : %u\n
    Load (<1000%): %u %\n
    Battery Voltage : %u V\n
    Battery Current : %u cA\n
    Battery Remaining : %u %\n
    Comm Drop Rate : %u c%\n
    Comm Errors : %u\n"
  );
}

void Mavlink::run_prearm_checks(){
  mavlink_message_t msg;
  uint8_t buf[MAVLINK_MSG_ID_COMMAND_LONG_LEN];

  uint16_t command = 401;
  uint8_t conf = 0;

  mavlink_msg_command_long_pack(
    this->sys_id, 
    this->comp_id, 
    &msg, 
    this->tgt_sys, 
    this->tgt_comp, 
    command, 
    conf, 
    0, 0, 0, 0, 0, 0, 0
  );
  uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);

  Serial2.write(buf, len);
}

void Mavlink::arm_disarm(bool arm){
  if(arm) Serial.println("Arming"); else Serial.println("Disarming");
  
  mavlink_message_t msg;
  uint8_t buf[MAVLINK_MSG_ID_COMMAND_LONG_LEN];

  uint16_t command = 400; //arm disarm
  uint8_t conf = 0;
  float param1 = float(arm);

  mavlink_msg_command_long_pack(
    this->sys_id, 
    this->comp_id, 
    &msg, 
    this->tgt_sys, 
    this->tgt_comp, 
    command, 
    conf, 
    param1, 
    0, 0, 0, 0, 0, 0
  );
  uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);

  Serial2.write(buf, len);
}

void Mavlink::takeoff(const float& height){
  while(this->px_mode != MAV_MODE_FLAG_SAFETY_ARMED){
    this->arm_disarm(true);
  }

  while(this->px_mode != MAV_MODE_FLAG_AUTO_ENABLED){
    set_mode(MAV_MODE_AUTO_ARMED);
  }

  Serial.println("Taking off");
  mavlink_message_t msg;
  uint8_t buf[MAVLINK_MSG_ID_COMMAND_LONG_LEN];

  uint16_t command = 22; //takeoff
  uint8_t conf = 0;
  float param7 = height;

  mavlink_msg_command_long_pack(
    this->sys_id, 
    this->comp_id, 
    &msg, 
    this->tgt_sys, 
    this->tgt_comp, 
    command, 
    conf, 
    0, 0, 0, 0, 0, 0, 
    param7
  );
  uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);

  Serial.write(buf, len);
}

void Mavlink::land(){
  Serial.println("Landing");
  mavlink_message_t msg;
  uint8_t buf[MAVLINK_MSG_ID_COMMAND_LONG_LEN];

  uint16_t command = 21; //land
  uint8_t conf = 0;

  mavlink_msg_command_long_pack(
    this->sys_id, 
    this->comp_id, 
    &msg, 
    this->tgt_sys, 
    this->tgt_comp, 
    command, 
    conf, 
    0, 0, 0, 0, 0, 0, 0
  );
  uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);

  Serial.write(buf, len);

  this->arm_disarm(false);
}

void Mavlink::set_mode(const uint16_t& mode){
  Serial.printf("Setting mode to %u", mode);
  mavlink_message_t msg;
  uint8_t buf[MAVLINK_MSG_ID_COMMAND_LONG_LEN];

  uint16_t command = 176; //do set mode
  uint8_t conf = 0;
  float param1 = float(mode); //auto disarmed

  mavlink_msg_command_long_pack(
    this->sys_id, 
    this->comp_id, 
    &msg, 
    this->tgt_sys, 
    this->tgt_comp, 
    command, 
    conf, 
    param1, 
    0, 0, 0, 0, 0, 0
  );
  uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);
  
  Serial2.write(buf, len);
}

void Mavlink::return_to_launch(){
  Serial.println("Returning to launch position");

  mavlink_message_t msg;
  uint8_t buf[MAVLINK_MSG_ID_COMMAND_LONG_LEN];

  uint16_t command = 20; //return to launch
  uint8_t conf = 0;

  mavlink_msg_command_long_pack(
    this->sys_id, 
    this->comp_id, 
    &msg, 
    this->tgt_sys, 
    this->tgt_comp, 
    command, 
    conf, 
    0, 0, 0, 0, 0, 0, 0
  );
  uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);

  Serial2.write(buf, len);
}

void Mavlink::send_mission_count(const uint16_t& num_of_mission){
  // this->mis_progress = 1000;
  // this->mis_seq = 1000; // hardcoded for now, maybe there is a better solution

  Serial.printf("Sending mission count: %d\n", (num_of_mission));
  mavlink_message_t msg;
  uint8_t buf[MAVLINK_MSG_ID_MISSION_COUNT_LEN];
  uint8_t mission_type = MAV_MISSION_TYPE_MISSION;

  mavlink_msg_mission_count_pack(
    this->sys_id, 
    this->comp_id, 
    &msg, 
    this->tgt_sys, 
    this->tgt_comp, 
    num_of_mission, 
    mission_type
  );
  uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);

  Serial2.write(buf, len);  
  this->req_mis = false;
}

void Mavlink::send_mission_item(const float& lat, const float& lng, const float& height){
  Serial.printf("Setting waypoint lat : %f, lng : %f, height : %f\n", lat, lng, height);
  mavlink_message_t msg;
  uint8_t buf[MAVLINK_MSG_ID_MISSION_ITEM_LEN];

  uint8_t frame = MAV_FRAME_GLOBAL_RELATIVE_ALT; //lat, long, altitude is relative to home altitude in meters
  uint8_t command = 16; //waypoint
  uint8_t current = 0;
  uint8_t cont = 1;
  float param1 = 1;
  float param2 = 1;
  float param3 = 0;
  float param4 = NAN;
  int32_t lat_send = lat * 1e7;
  int32_t lng_send = lng * 1e7;
  uint8_t mission_type = MAV_MISSION_TYPE_MISSION;

  mavlink_msg_mission_item_int_pack(
    this->sys_id, 
    this->comp_id, 
    &msg, 
    this->tgt_sys, 
    this->tgt_comp, 
    this->mis_seq, 
    frame, 
    command, 
    current, 
    cont, 
    param1, 
    param2, 
    param3, 
    param4, 
    lat_send, 
    lng_send, 
    height, 
    mission_type
  );
  uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);

  Serial2.write(buf, len);

  Serial.printf("Mission sequence %u sent", this->mis_seq);
  this->req_mis = false;
}

void Mavlink::start_mission(){
  Serial.println("Starting mission");
  
  /*
  If it takes off correctly but doesn't start mission, may need MAV_CMD_COMMAND_START here.
  Documentation says that drone will automatically start mission when switched to auto mode,
  with condition that mission is accepted.
  */

  /*
  Loops while not all mission item is completed. 
  Supposedly, there is MISSON_STATE enum with MISSION_STATE_COMPLETE, but how do you request
  for it???? Or is it automatic?????????
  */
  while(this->mis_progress != this->mis_seq);

  this->return_to_launch();
}