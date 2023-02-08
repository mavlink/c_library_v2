#include "mavlink_commands.hpp"

MAVLink::MAVLink(const int& baud_rate, const uint8_t& rx, const uint8_t& tx){
  Serial2.begin(baud_rate, SERIAL_8N1, rx, tx);
}

MAVLink::~MAVLink() {}

uint8_t MAVLink::get_px_mode(){
  return this->px_mode;
}

uint8_t MAVLink::get_px_status(){
  return this->px_status;
}

uint16_t MAVLink::get_mis_seq(){
  return this->mis_seq;
}

bool MAVLink::get_mis_req_status(){
  return this->req_mis;
}

std::array<float,3> MAVLink::get_global_pos_curr(){
  return this->global_pos_curr;
}

std::array<float, 3> MAVLink::get_velocity_curr(){
  return this->velocity_curr;
}

float MAVLink::get_time_boot(){
  return this->time_boot_sec;
}

uint16_t MAVLink::get_yaw_curr(){
  return this->yaw_curr;
}

void MAVLink::req_data_stream(){
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
  uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);
  
  Serial2.write(buf, len);
}

void MAVLink::read_data(){
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
        case MAVLINK_MSG_ID_MISSION_CURRENT:
          this->current_mission_status(&msg);
          break;
        case MAVLINK_MSG_ID_MISSION_COUNT:
          this->recv_mission_count(&msg);
          break;
        case MAVLINK_MSG_ID_MISSION_ITEM_INT:
          this->recv_mission(&msg);
          break;
        case MAVLINK_MSG_ID_GLOBAL_POSITION_INT:
          this->recv_global_pos(&msg);
          break;
      }
    }
  }
}

void MAVLink::check_mode(mavlink_message_t* msg){
  mavlink_heartbeat_t hb;
  mavlink_msg_heartbeat_decode(msg, &hb);
  this->px_mode = hb.base_mode;
  this->px_status = hb.system_status;
  Serial.println("Heartbeat detected");
}

void MAVLink::command_ack(mavlink_message_t* msg){
  mavlink_command_ack_t cmd_ack;
  mavlink_msg_command_ack_decode(msg, &cmd_ack);
  Serial.printf("Command %u result code %u\n", cmd_ack.command, cmd_ack.result);
}

void MAVLink::mission_request(mavlink_message_t* msg){
  mavlink_mission_request_int_t mis_req;
  mavlink_msg_mission_request_int_decode(msg, &mis_req);
  this->mis_seq = mis_req.seq;
  this->tgt_sys = mis_req.target_system;
  this->tgt_comp = mis_req.target_component;
  Serial.printf("Requesting for mission type %u sequence %u\n", mis_req.mission_type, this->mis_seq);
  this->send_mission_item();
}

void MAVLink::check_mission_progress(mavlink_message_t* msg){
  mavlink_mission_item_reached_t it;
  mavlink_msg_mission_item_reached_decode(msg, &it);
  Serial.printf("Mission sequence %u reached\n", it.seq);
}

void MAVLink::uploaded_mission_status(mavlink_message_t* msg){
  mavlink_mission_ack_t mis_ack;
  mavlink_msg_mission_ack_decode(msg, &mis_ack);
  if(mis_ack.type == MAV_MISSION_ACCEPTED){
    Serial.println("Mission accepted");
    this->start_mission();
  }else{
    Serial.printf("Mission unaccepted with enum %u\n", mis_ack.type);
  }
}

void MAVLink::sys_status(mavlink_message_t* msg){
  mavlink_sys_status_t sys_status;
  mavlink_msg_sys_status_decode(msg, &sys_status);
  Serial.printf(
    "Sensors Present : %u\n\
    Sensors Enabled : %u\n\
    Sensors Healthy : %u\n\
    Load (<1000%): %u %\n\
    Battery Voltage : %u V\n\
    Battery Current : %u cA\n\
    Battery Remaining : %u %\n\
    Comm Drop Rate : %u c%\n\
    Comm Errors : %u\n"
  );
}

void MAVLink::recv_global_pos(mavlink_message_t* msg){
  mavlink_global_position_int_t global_pos;
  mavlink_msg_global_position_int_decode(msg, &global_pos);
  this->global_pos_curr[0] = static_cast<float>(global_pos.lat / 1e7);
  this->global_pos_curr[1] = static_cast<float>(global_pos.lon / 1e7);
  this->global_pos_curr[2] = static_cast<float>(global_pos.relative_alt / 1000);
  this->velocity_curr[0] = static_cast<float>(global_pos.vx / 100);
  this->velocity_curr[1] = static_cast<float>(global_pos.vy / 100);
  this->velocity_curr[2] = static_cast<float>(global_pos.vz / 100);
  this->time_boot_sec = static_cast<float>(global_pos.time_boot_ms / 1000);
  this->yaw_curr = global_pos.hdg;
}

void MAVLink::current_mission_status(mavlink_message_t* msg){
  mavlink_mission_current_t mis_stat;
  mavlink_msg_mission_current_decode(msg, &mis_stat);
  if(mis_stat.mission_state == MISSION_STATE_COMPLETE){
    Serial.println("Mission completed. Returning to launch.");
    this->return_to_launch();
  }else if(mis_stat.mission_state == MISSION_STATE_NO_MISSION) 
    Serial.println("No mission uploaded");
  else if(mis_stat.mission_state == MISSION_STATE_NOT_STARTED) 
    Serial.println("Mission uploaded but not started");
  else if(mis_stat.mission_state == MISSION_STATE_PAUSED) 
    Serial.printf("Mission paused at waypoint %u out of %u\n", mis_stat.seq, mis_stat.total);
  else if(mis_stat.mission_state == MISSION_STATE_ACTIVE)
    Serial.printf("Mission active on the way to waypoint %u out of %u\n", mis_stat.seq, mis_stat.total);
  else
    Serial.println("Unknown mission status");
}

void MAVLink::recv_mission_count(mavlink_message_t* msg){
  mavlink_mission_count_t recv_mis_count;
  mavlink_msg_mission_count_decode(msg, &recv_mis_count);
  if(recv_mis_count.count != this->mis_count){
    Serial.println("Downloaded mission count is not the same as sent");
  }else{
    Serial.printf("Downloading %u missions\n", recv_mis_count.count);
    this->req_mission_item();
  }
}

void MAVLink::recv_mission(mavlink_message_t* msg){
  mavlink_mission_item_int_t recv_mis;
  mavlink_msg_mission_item_int_decode(msg, &recv_mis);
  Serial.printf("Downloaded waypoint %u with lat %f, long %f, and height %f\n", recv_mis.seq, recv_mis.x / 1e7, recv_mis.y / 1e7, recv_mis.z);
  if(recv_mis.seq != this->mis_count - 1) this->req_mission_item();
  else{
    this->mis_seq = 0;
  } 
}

void MAVLink::run_prearm_checks(){
  Serial.println("Running prearm checks");

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

void MAVLink::arm_disarm(bool arm){
  this->run_prearm_checks();

  if(arm) Serial.println("Arming"); else Serial.println("Disarming");
  
  mavlink_message_t msg;
  uint8_t buf[MAVLINK_MSG_ID_COMMAND_LONG_LEN];

  uint16_t command = 400; //arm disarm
  uint8_t conf = 0;
  float param1 = static_cast<float>(arm);

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

void MAVLink::takeoff(const float& height){
  while(this->px_mode != MAV_MODE_FLAG_SAFETY_ARMED){
    this->arm_disarm(true);
  }

  while(this->px_mode != MAV_MODE_FLAG_AUTO_ENABLED){
    this->set_mode(MAV_MODE_AUTO_ARMED);
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

  Serial2.write(buf, len);
}

void MAVLink::land(){
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

  Serial2.write(buf, len);

  this->arm_disarm(false);
}

void MAVLink::set_mode(const uint16_t& mode){
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

void MAVLink::return_to_launch(){
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

void MAVLink::send_mission_count(const uint16_t& num_of_mission){
  Serial.printf("Sending mission count: %u\n", num_of_mission);
  mavlink_message_t msg;
  uint8_t buf[MAVLINK_MSG_ID_MISSION_COUNT_LEN];

  this->mis_count = num_of_mission;
  this->mis_seq = 0;

  mavlink_msg_mission_count_pack(
    this->sys_id, 
    this->comp_id, 
    &msg, 
    this->tgt_sys, 
    this->tgt_comp, 
    num_of_mission, 
    MAV_MISSION_TYPE_MISSION
  );
  uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);

  Serial2.write(buf, len);
}

void MAVLink::send_mission_item(){
  float lat = std::get<0>(this->waypoints.at(this->mis_seq));
  float lng = std::get<1>(this->waypoints.at(this->mis_seq));
  float hgt = std::get<2>(this->waypoints.at(this->mis_seq));
  Serial.printf("Setting waypoint lat : %f, lng : %f, height : %f\n", lat, lng, hgt);
  mavlink_message_t msg;
  uint8_t buf[MAVLINK_MSG_ID_MISSION_ITEM_INT_LEN];

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
    hgt, 
    mission_type
  );
  uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);

  Serial2.write(buf, len);

  Serial.printf("Mission sequence %u sent", this->mis_seq);
}

void MAVLink::req_mission_list(){
  Serial.println("Downloading mission from pixhawk");
  mavlink_message_t msg;
  uint8_t buf[MAVLINK_MSG_ID_MISSION_REQUEST_LIST_LEN];

  this->mis_seq = 0;

  mavlink_msg_mission_request_list_pack(
    this->sys_id,
    this->comp_id,
    &msg,
    this->tgt_sys,
    this->tgt_comp,
    MAV_MISSION_TYPE_MISSION
  );

  uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);

  Serial2.write(buf, len);
}

void MAVLink::req_mission_item(){
  Serial.println("Requesting mission item");
  mavlink_message_t msg;
  uint8_t buf[MAVLINK_MSG_ID_MISSION_REQUEST_INT_LEN];

  mavlink_msg_mission_request_int_pack(
    this->sys_id,
    this->comp_id,
    &msg,
    this->tgt_sys,
    this->tgt_comp,
    this->mis_seq,
    MAV_MISSION_TYPE_MISSION
  );

  uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);

  Serial2.write(buf, len);

  this->mis_seq++;
}

void MAVLink::send_mission_ack(){
  Serial.println("Mission downloading finished");
  mavlink_message_t msg;
  uint8_t buf[MAVLINK_MSG_ID_MISSION_ACK_LEN];

  // TODO : Better error handling here
  mavlink_msg_mission_ack_pack(
    this->sys_id,
    this->comp_id,
    &msg,
    this->tgt_sys,
    this->tgt_comp,
    MAV_MISSION_ACCEPTED,
    MAV_MISSION_TYPE_MISSION
  );

  uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);

  Serial2.write(buf, len);

  /*
  if waypoints are correct -> takeoff
  else cancel
  */
}

// TODO : Implement a better way to start mission
void MAVLink::start_mission(){
  Serial.println("Starting mission");

  this->req_mission_list();
  
  /*
  If it takes off correctly but doesn't start mission, may need MAV_CMD_COMMAND_START here.
  Documentation says that drone will automatically start mission when switched to auto mode,
  with condition that mission is accepted.
  */
}