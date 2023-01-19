#include "mavlink_commands_c.hpp"

void req_data_stream(){
  sys_id = 255;
  comp_id = 2;
  tgt_sys = 1;
  tgt_comp = 1;
  uint8_t req_stream_id = MAV_DATA_STREAM_ALL;
  uint16_t req_msg_rate = 0x01; // 1 times per second
  uint8_t start_stop = 1; // 1 start, 0 = stop

  mavlink_message_t msg;
  uint8_t buf[MAVLINK_MAX_PACKET_LEN];

  mavlink_msg_request_data_stream_pack(
    sys_id, 
    comp_id, 
    &msg, 
    tgt_sys, 
    tgt_comp, 
    req_stream_id, 
    req_msg_rate, 
    start_stop
  );
  uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);  // Send the message (.write sends as bytes)

  Serial2.write(buf, len);
}

void read_data(){
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
          check_mode(&msg);
          break;
        case MAVLINK_MSG_ID_MISSION_REQUEST_INT:
          mission_request(&msg);
          break;
        case MAVLINK_MSG_ID_MISSION_ACK:
          uploaded_mission_status(&msg);
          break;
        case MAVLINK_MSG_ID_MISSION_ITEM_REACHED:
          check_mission_progress(&msg);
          break;
      }
    }
  }
}

void check_mode(mavlink_message_t* msg){
  mavlink_heartbeat_t hb;
  mavlink_msg_heartbeat_decode(msg, &hb);
  px_mode = hb.base_mode;
  px_status = hb.system_status;
}

void mission_request(mavlink_message_t* msg){
  mavlink_mission_request_int_t mis_req;
  mavlink_msg_mission_request_int_decode(msg, &mis_req);
  // seq_prev = seq; //retain previous sequence number
  mis_seq = mis_req.seq;
  tgt_sys = mis_req.target_system;
  tgt_comp = mis_req.target_component;
  Serial.printf("Requesting for mission type %u sequence %u\n", mis_req.mission_type, mis_seq);
}

void check_mission_progress(mavlink_message_t* msg){
  mavlink_mission_item_reached_t it;
  mavlink_msg_mission_item_reached_decode(msg, &it);
  mis_progress = it.seq;
  // seq_prev = it.seq; //using same variable to save memory
  Serial.printf("Mission sequence %u reached\n", mis_progress);
}

void uploaded_mission_status(mavlink_message_t* msg){
  mavlink_mission_ack_t mis_ack;
  mavlink_msg_mission_ack_decode(msg, &mis_ack);
  // mis_up_status = mis_ack.type;
  if(mis_ack.type == MAV_MISSION_ACCEPTED){
    Serial.println("Mission accepted");
  }else{
    Serial.printf("Mission unaccepted with enum %u\n", mis_ack.type);
  }
}

void takeoff(const float height){
  while(px_mode != MAV_MODE_FLAG_SAFETY_ARMED){
    arm_disarm(true);
  }

  while(px_mode != MAV_MODE_FLAG_AUTO_ENABLED){
    set_mode(MAV_MODE_AUTO_ARMED);
  }

  Serial.println("Taking off");
  mavlink_message_t msg;
  uint8_t buf[MAVLINK_MSG_ID_COMMAND_LONG_LEN];

  uint16_t command = 22; //takeoff
  uint8_t conf = 0;
  float param7 = height;

  mavlink_msg_command_long_pack(
    sys_id, 
    comp_id, 
    &msg, 
    tgt_sys, 
    tgt_comp, 
    command, 
    conf, 
    0, 0, 0, 0, 0, 0, 
    param7
  );
  uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);

  Serial2.write(buf, len);
}

void land(){
  Serial.println("Landing");
  mavlink_message_t msg;
  uint8_t buf[MAVLINK_MSG_ID_COMMAND_LONG_LEN];

  uint16_t command = 21; //land
  uint8_t conf = 0;

  mavlink_msg_command_long_pack(
    sys_id, 
    comp_id, 
    &msg, 
    tgt_sys, 
    tgt_comp, 
    command, 
    conf, 
    0, 0, 0, 0, 0, 0, 0
  );
  uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);

  Serial.write(buf, len);

  arm_disarm(false);
}

void arm_disarm(bool arm){
  if(arm) Serial.println("Arming"); else Serial.println("Disarming");
  
  mavlink_message_t msg;
  uint8_t buf[MAVLINK_MSG_ID_COMMAND_LONG_LEN];

  uint16_t command = 400; //arm disarm
  uint8_t conf = 0;
  float param1 = float(arm);

  mavlink_msg_command_long_pack(
    sys_id, 
    comp_id, 
    &msg, 
    tgt_sys, 
    tgt_comp, 
    command, 
    conf, 
    param1, 
    0, 0, 0, 0, 0, 0);
  uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);

  Serial2.write(buf, len);
}

void set_mode(const uint16_t mode){
  Serial.printf("Setting mode to %u", mode);
  mavlink_message_t msg;
  uint8_t buf[MAVLINK_MSG_ID_COMMAND_LONG_LEN];

  uint16_t command = 176; //do set mode
  uint8_t conf = 0;
  float param1 = float(mode); //auto disarmed

  mavlink_msg_command_long_pack(
    sys_id, 
    comp_id, 
    &msg, 
    tgt_sys, 
    tgt_comp, 
    command, 
    conf, 
    param1, 
    0, 0, 0, 0, 0, 0
  );
  uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);
  
  Serial2.write(buf, len);
}

void return_to_launch(){
  Serial.println("Returning to launch position");

  mavlink_message_t msg;
  uint8_t buf[MAVLINK_MSG_ID_COMMAND_LONG_LEN];

  uint16_t command = 20; //return to launch
  uint8_t conf = 0;

  mavlink_msg_command_long_pack(
    sys_id, 
    comp_id, 
    &msg, 
    tgt_sys, 
    tgt_comp, 
    command, 
    conf, 
    0, 0, 0, 0, 0, 0, 0
  );
  uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);

  Serial2.write(buf, len);
}

void send_mission_count(const uint16_t num_of_mission){
  Serial.printf("Sending mission count: %d\n", (num_of_mission));
  mavlink_message_t msg;
  uint8_t buf[MAVLINK_MSG_ID_MISSION_COUNT_LEN];
  uint8_t mission_type = MAV_MISSION_TYPE_MISSION;

  mavlink_msg_mission_count_pack(
    sys_id, 
    comp_id, 
    &msg, 
    tgt_sys, 
    tgt_comp, 
    num_of_mission, 
    mission_type
  );
  uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);

  Serial2.write(buf, len);  
}

void send_mission_item(const float lat, const float lng, const float height){
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
    sys_id, 
    comp_id, 
    &msg, 
    tgt_sys, 
    tgt_comp, 
    mis_seq, 
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

  Serial.printf("Mission sequence %u sent", mis_seq);
}

void start_mission(){
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
  while(mis_progress != mis_seq){ 
    read_data();
  }

  return_to_launch();
}