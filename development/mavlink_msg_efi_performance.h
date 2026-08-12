#pragma once
// MESSAGE EFI_PERFORMANCE PACKING

#include <stdint.h>

#define MAVLINK_MSG_ID_EFI_PERFORMANCE 442


typedef struct __mavlink_efi_performance_t {
 uint64_t status_flags; /*<  EFI status flags.*/
 float fuel_mass_rate; /*< [g/min] Instantaneous fuel consumption by mass. NaN if not provided.*/
 float commanded_rpm; /*< [rpm] Governor/target RPM setpoint.*/
 uint32_t engine_runtime; /*< [s] Cumulative engine run time (hobbs).*/
 float boost_pressure; /*< [kPa] Forced-induction boost pressure. NaN if not provided.*/
 float coolant_pressure; /*< [kPa] Coolant-circuit pressure. NaN if not provided.*/
 uint16_t fuel_pump_voltage; /*< [mV] Fuel pump supply voltage.*/
 uint16_t fuel_pump_current; /*< [cA] Fuel pump current draw.*/
 uint16_t ecu_supply_voltage; /*< [mV] ECU supply voltage.*/
 uint16_t ecu_current; /*< [cA] ECU current draw.*/
 int16_t ecu_temperature; /*< [cdegC] ECU/electronics board temperature.*/
 uint16_t servo_supply_voltage; /*< [mV] Throttle-servo / actuator supply voltage.*/
 int16_t engine_torque; /*< [%] Percent engine torque (signed; negative = motoring/braking).*/
 uint8_t ecu_index; /*<  Electronic Control Unit (ECU) index for systems with multiple EFI units. Set to 0 for the first (or only) ECU.*/
 uint8_t fuel_pump_duty_cycle; /*< [%] Fuel pump power output, as a percentage of maximum. 0 = off, 100 = full power.*/
 uint8_t ecu_cpu_load; /*< [%] ECU processor load.*/
 uint8_t servo_output_level; /*< [%] Electronic-throttle / servo commanded output level.*/
 uint8_t water_pump_duty_cycle; /*< [%] Coolant-pump power output, as a percentage of maximum.*/
 uint8_t injector_duty_cycle; /*< [%] Primary injector duty cycle.*/
 uint8_t error_memory_count; /*<  Number of faults currently stored in the ECU error memory.*/
} mavlink_efi_performance_t;

#define MAVLINK_MSG_ID_EFI_PERFORMANCE_LEN 49
#define MAVLINK_MSG_ID_EFI_PERFORMANCE_MIN_LEN 49
#define MAVLINK_MSG_ID_442_LEN 49
#define MAVLINK_MSG_ID_442_MIN_LEN 49

#define MAVLINK_MSG_ID_EFI_PERFORMANCE_CRC 189
#define MAVLINK_MSG_ID_442_CRC 189



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_EFI_PERFORMANCE { \
    442, \
    "EFI_PERFORMANCE", \
    20, \
    {  { "ecu_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 42, offsetof(mavlink_efi_performance_t, ecu_index) }, \
         { "fuel_pump_duty_cycle", NULL, MAVLINK_TYPE_UINT8_T, 0, 43, offsetof(mavlink_efi_performance_t, fuel_pump_duty_cycle) }, \
         { "fuel_pump_voltage", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_efi_performance_t, fuel_pump_voltage) }, \
         { "fuel_pump_current", NULL, MAVLINK_TYPE_UINT16_T, 0, 30, offsetof(mavlink_efi_performance_t, fuel_pump_current) }, \
         { "ecu_supply_voltage", NULL, MAVLINK_TYPE_UINT16_T, 0, 32, offsetof(mavlink_efi_performance_t, ecu_supply_voltage) }, \
         { "ecu_current", NULL, MAVLINK_TYPE_UINT16_T, 0, 34, offsetof(mavlink_efi_performance_t, ecu_current) }, \
         { "ecu_temperature", NULL, MAVLINK_TYPE_INT16_T, 0, 36, offsetof(mavlink_efi_performance_t, ecu_temperature) }, \
         { "ecu_cpu_load", NULL, MAVLINK_TYPE_UINT8_T, 0, 44, offsetof(mavlink_efi_performance_t, ecu_cpu_load) }, \
         { "servo_supply_voltage", NULL, MAVLINK_TYPE_UINT16_T, 0, 38, offsetof(mavlink_efi_performance_t, servo_supply_voltage) }, \
         { "servo_output_level", NULL, MAVLINK_TYPE_UINT8_T, 0, 45, offsetof(mavlink_efi_performance_t, servo_output_level) }, \
         { "water_pump_duty_cycle", NULL, MAVLINK_TYPE_UINT8_T, 0, 46, offsetof(mavlink_efi_performance_t, water_pump_duty_cycle) }, \
         { "injector_duty_cycle", NULL, MAVLINK_TYPE_UINT8_T, 0, 47, offsetof(mavlink_efi_performance_t, injector_duty_cycle) }, \
         { "fuel_mass_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_efi_performance_t, fuel_mass_rate) }, \
         { "commanded_rpm", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_efi_performance_t, commanded_rpm) }, \
         { "engine_runtime", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_efi_performance_t, engine_runtime) }, \
         { "error_memory_count", NULL, MAVLINK_TYPE_UINT8_T, 0, 48, offsetof(mavlink_efi_performance_t, error_memory_count) }, \
         { "boost_pressure", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_efi_performance_t, boost_pressure) }, \
         { "coolant_pressure", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_efi_performance_t, coolant_pressure) }, \
         { "engine_torque", NULL, MAVLINK_TYPE_INT16_T, 0, 40, offsetof(mavlink_efi_performance_t, engine_torque) }, \
         { "status_flags", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_efi_performance_t, status_flags) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_EFI_PERFORMANCE { \
    "EFI_PERFORMANCE", \
    20, \
    {  { "ecu_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 42, offsetof(mavlink_efi_performance_t, ecu_index) }, \
         { "fuel_pump_duty_cycle", NULL, MAVLINK_TYPE_UINT8_T, 0, 43, offsetof(mavlink_efi_performance_t, fuel_pump_duty_cycle) }, \
         { "fuel_pump_voltage", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_efi_performance_t, fuel_pump_voltage) }, \
         { "fuel_pump_current", NULL, MAVLINK_TYPE_UINT16_T, 0, 30, offsetof(mavlink_efi_performance_t, fuel_pump_current) }, \
         { "ecu_supply_voltage", NULL, MAVLINK_TYPE_UINT16_T, 0, 32, offsetof(mavlink_efi_performance_t, ecu_supply_voltage) }, \
         { "ecu_current", NULL, MAVLINK_TYPE_UINT16_T, 0, 34, offsetof(mavlink_efi_performance_t, ecu_current) }, \
         { "ecu_temperature", NULL, MAVLINK_TYPE_INT16_T, 0, 36, offsetof(mavlink_efi_performance_t, ecu_temperature) }, \
         { "ecu_cpu_load", NULL, MAVLINK_TYPE_UINT8_T, 0, 44, offsetof(mavlink_efi_performance_t, ecu_cpu_load) }, \
         { "servo_supply_voltage", NULL, MAVLINK_TYPE_UINT16_T, 0, 38, offsetof(mavlink_efi_performance_t, servo_supply_voltage) }, \
         { "servo_output_level", NULL, MAVLINK_TYPE_UINT8_T, 0, 45, offsetof(mavlink_efi_performance_t, servo_output_level) }, \
         { "water_pump_duty_cycle", NULL, MAVLINK_TYPE_UINT8_T, 0, 46, offsetof(mavlink_efi_performance_t, water_pump_duty_cycle) }, \
         { "injector_duty_cycle", NULL, MAVLINK_TYPE_UINT8_T, 0, 47, offsetof(mavlink_efi_performance_t, injector_duty_cycle) }, \
         { "fuel_mass_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_efi_performance_t, fuel_mass_rate) }, \
         { "commanded_rpm", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_efi_performance_t, commanded_rpm) }, \
         { "engine_runtime", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_efi_performance_t, engine_runtime) }, \
         { "error_memory_count", NULL, MAVLINK_TYPE_UINT8_T, 0, 48, offsetof(mavlink_efi_performance_t, error_memory_count) }, \
         { "boost_pressure", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_efi_performance_t, boost_pressure) }, \
         { "coolant_pressure", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_efi_performance_t, coolant_pressure) }, \
         { "engine_torque", NULL, MAVLINK_TYPE_INT16_T, 0, 40, offsetof(mavlink_efi_performance_t, engine_torque) }, \
         { "status_flags", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_efi_performance_t, status_flags) }, \
         } \
}
#endif

/**
 * @brief Pack a efi_performance message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param ecu_index  Electronic Control Unit (ECU) index for systems with multiple EFI units. Set to 0 for the first (or only) ECU.
 * @param fuel_pump_duty_cycle [%] Fuel pump power output, as a percentage of maximum. 0 = off, 100 = full power.
 * @param fuel_pump_voltage [mV] Fuel pump supply voltage.
 * @param fuel_pump_current [cA] Fuel pump current draw.
 * @param ecu_supply_voltage [mV] ECU supply voltage.
 * @param ecu_current [cA] ECU current draw.
 * @param ecu_temperature [cdegC] ECU/electronics board temperature.
 * @param ecu_cpu_load [%] ECU processor load.
 * @param servo_supply_voltage [mV] Throttle-servo / actuator supply voltage.
 * @param servo_output_level [%] Electronic-throttle / servo commanded output level.
 * @param water_pump_duty_cycle [%] Coolant-pump power output, as a percentage of maximum.
 * @param injector_duty_cycle [%] Primary injector duty cycle.
 * @param fuel_mass_rate [g/min] Instantaneous fuel consumption by mass. NaN if not provided.
 * @param commanded_rpm [rpm] Governor/target RPM setpoint.
 * @param engine_runtime [s] Cumulative engine run time (hobbs).
 * @param error_memory_count  Number of faults currently stored in the ECU error memory.
 * @param boost_pressure [kPa] Forced-induction boost pressure. NaN if not provided.
 * @param coolant_pressure [kPa] Coolant-circuit pressure. NaN if not provided.
 * @param engine_torque [%] Percent engine torque (signed; negative = motoring/braking).
 * @param status_flags  EFI status flags.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_efi_performance_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t ecu_index, uint8_t fuel_pump_duty_cycle, uint16_t fuel_pump_voltage, uint16_t fuel_pump_current, uint16_t ecu_supply_voltage, uint16_t ecu_current, int16_t ecu_temperature, uint8_t ecu_cpu_load, uint16_t servo_supply_voltage, uint8_t servo_output_level, uint8_t water_pump_duty_cycle, uint8_t injector_duty_cycle, float fuel_mass_rate, float commanded_rpm, uint32_t engine_runtime, uint8_t error_memory_count, float boost_pressure, float coolant_pressure, int16_t engine_torque, uint64_t status_flags)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EFI_PERFORMANCE_LEN];
    _mav_put_uint64_t(buf, 0, status_flags);
    _mav_put_float(buf, 8, fuel_mass_rate);
    _mav_put_float(buf, 12, commanded_rpm);
    _mav_put_uint32_t(buf, 16, engine_runtime);
    _mav_put_float(buf, 20, boost_pressure);
    _mav_put_float(buf, 24, coolant_pressure);
    _mav_put_uint16_t(buf, 28, fuel_pump_voltage);
    _mav_put_uint16_t(buf, 30, fuel_pump_current);
    _mav_put_uint16_t(buf, 32, ecu_supply_voltage);
    _mav_put_uint16_t(buf, 34, ecu_current);
    _mav_put_int16_t(buf, 36, ecu_temperature);
    _mav_put_uint16_t(buf, 38, servo_supply_voltage);
    _mav_put_int16_t(buf, 40, engine_torque);
    _mav_put_uint8_t(buf, 42, ecu_index);
    _mav_put_uint8_t(buf, 43, fuel_pump_duty_cycle);
    _mav_put_uint8_t(buf, 44, ecu_cpu_load);
    _mav_put_uint8_t(buf, 45, servo_output_level);
    _mav_put_uint8_t(buf, 46, water_pump_duty_cycle);
    _mav_put_uint8_t(buf, 47, injector_duty_cycle);
    _mav_put_uint8_t(buf, 48, error_memory_count);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EFI_PERFORMANCE_LEN);
#else
    mavlink_efi_performance_t packet;
    packet.status_flags = status_flags;
    packet.fuel_mass_rate = fuel_mass_rate;
    packet.commanded_rpm = commanded_rpm;
    packet.engine_runtime = engine_runtime;
    packet.boost_pressure = boost_pressure;
    packet.coolant_pressure = coolant_pressure;
    packet.fuel_pump_voltage = fuel_pump_voltage;
    packet.fuel_pump_current = fuel_pump_current;
    packet.ecu_supply_voltage = ecu_supply_voltage;
    packet.ecu_current = ecu_current;
    packet.ecu_temperature = ecu_temperature;
    packet.servo_supply_voltage = servo_supply_voltage;
    packet.engine_torque = engine_torque;
    packet.ecu_index = ecu_index;
    packet.fuel_pump_duty_cycle = fuel_pump_duty_cycle;
    packet.ecu_cpu_load = ecu_cpu_load;
    packet.servo_output_level = servo_output_level;
    packet.water_pump_duty_cycle = water_pump_duty_cycle;
    packet.injector_duty_cycle = injector_duty_cycle;
    packet.error_memory_count = error_memory_count;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EFI_PERFORMANCE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EFI_PERFORMANCE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_EFI_PERFORMANCE_MIN_LEN, MAVLINK_MSG_ID_EFI_PERFORMANCE_LEN, MAVLINK_MSG_ID_EFI_PERFORMANCE_CRC);
}

/**
 * @brief Pack a efi_performance message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param ecu_index  Electronic Control Unit (ECU) index for systems with multiple EFI units. Set to 0 for the first (or only) ECU.
 * @param fuel_pump_duty_cycle [%] Fuel pump power output, as a percentage of maximum. 0 = off, 100 = full power.
 * @param fuel_pump_voltage [mV] Fuel pump supply voltage.
 * @param fuel_pump_current [cA] Fuel pump current draw.
 * @param ecu_supply_voltage [mV] ECU supply voltage.
 * @param ecu_current [cA] ECU current draw.
 * @param ecu_temperature [cdegC] ECU/electronics board temperature.
 * @param ecu_cpu_load [%] ECU processor load.
 * @param servo_supply_voltage [mV] Throttle-servo / actuator supply voltage.
 * @param servo_output_level [%] Electronic-throttle / servo commanded output level.
 * @param water_pump_duty_cycle [%] Coolant-pump power output, as a percentage of maximum.
 * @param injector_duty_cycle [%] Primary injector duty cycle.
 * @param fuel_mass_rate [g/min] Instantaneous fuel consumption by mass. NaN if not provided.
 * @param commanded_rpm [rpm] Governor/target RPM setpoint.
 * @param engine_runtime [s] Cumulative engine run time (hobbs).
 * @param error_memory_count  Number of faults currently stored in the ECU error memory.
 * @param boost_pressure [kPa] Forced-induction boost pressure. NaN if not provided.
 * @param coolant_pressure [kPa] Coolant-circuit pressure. NaN if not provided.
 * @param engine_torque [%] Percent engine torque (signed; negative = motoring/braking).
 * @param status_flags  EFI status flags.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_efi_performance_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t ecu_index, uint8_t fuel_pump_duty_cycle, uint16_t fuel_pump_voltage, uint16_t fuel_pump_current, uint16_t ecu_supply_voltage, uint16_t ecu_current, int16_t ecu_temperature, uint8_t ecu_cpu_load, uint16_t servo_supply_voltage, uint8_t servo_output_level, uint8_t water_pump_duty_cycle, uint8_t injector_duty_cycle, float fuel_mass_rate, float commanded_rpm, uint32_t engine_runtime, uint8_t error_memory_count, float boost_pressure, float coolant_pressure, int16_t engine_torque, uint64_t status_flags)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EFI_PERFORMANCE_LEN];
    _mav_put_uint64_t(buf, 0, status_flags);
    _mav_put_float(buf, 8, fuel_mass_rate);
    _mav_put_float(buf, 12, commanded_rpm);
    _mav_put_uint32_t(buf, 16, engine_runtime);
    _mav_put_float(buf, 20, boost_pressure);
    _mav_put_float(buf, 24, coolant_pressure);
    _mav_put_uint16_t(buf, 28, fuel_pump_voltage);
    _mav_put_uint16_t(buf, 30, fuel_pump_current);
    _mav_put_uint16_t(buf, 32, ecu_supply_voltage);
    _mav_put_uint16_t(buf, 34, ecu_current);
    _mav_put_int16_t(buf, 36, ecu_temperature);
    _mav_put_uint16_t(buf, 38, servo_supply_voltage);
    _mav_put_int16_t(buf, 40, engine_torque);
    _mav_put_uint8_t(buf, 42, ecu_index);
    _mav_put_uint8_t(buf, 43, fuel_pump_duty_cycle);
    _mav_put_uint8_t(buf, 44, ecu_cpu_load);
    _mav_put_uint8_t(buf, 45, servo_output_level);
    _mav_put_uint8_t(buf, 46, water_pump_duty_cycle);
    _mav_put_uint8_t(buf, 47, injector_duty_cycle);
    _mav_put_uint8_t(buf, 48, error_memory_count);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EFI_PERFORMANCE_LEN);
#else
    mavlink_efi_performance_t packet;
    packet.status_flags = status_flags;
    packet.fuel_mass_rate = fuel_mass_rate;
    packet.commanded_rpm = commanded_rpm;
    packet.engine_runtime = engine_runtime;
    packet.boost_pressure = boost_pressure;
    packet.coolant_pressure = coolant_pressure;
    packet.fuel_pump_voltage = fuel_pump_voltage;
    packet.fuel_pump_current = fuel_pump_current;
    packet.ecu_supply_voltage = ecu_supply_voltage;
    packet.ecu_current = ecu_current;
    packet.ecu_temperature = ecu_temperature;
    packet.servo_supply_voltage = servo_supply_voltage;
    packet.engine_torque = engine_torque;
    packet.ecu_index = ecu_index;
    packet.fuel_pump_duty_cycle = fuel_pump_duty_cycle;
    packet.ecu_cpu_load = ecu_cpu_load;
    packet.servo_output_level = servo_output_level;
    packet.water_pump_duty_cycle = water_pump_duty_cycle;
    packet.injector_duty_cycle = injector_duty_cycle;
    packet.error_memory_count = error_memory_count;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EFI_PERFORMANCE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EFI_PERFORMANCE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_EFI_PERFORMANCE_MIN_LEN, MAVLINK_MSG_ID_EFI_PERFORMANCE_LEN, MAVLINK_MSG_ID_EFI_PERFORMANCE_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_EFI_PERFORMANCE_MIN_LEN, MAVLINK_MSG_ID_EFI_PERFORMANCE_LEN);
#endif
}

/**
 * @brief Pack a efi_performance message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ecu_index  Electronic Control Unit (ECU) index for systems with multiple EFI units. Set to 0 for the first (or only) ECU.
 * @param fuel_pump_duty_cycle [%] Fuel pump power output, as a percentage of maximum. 0 = off, 100 = full power.
 * @param fuel_pump_voltage [mV] Fuel pump supply voltage.
 * @param fuel_pump_current [cA] Fuel pump current draw.
 * @param ecu_supply_voltage [mV] ECU supply voltage.
 * @param ecu_current [cA] ECU current draw.
 * @param ecu_temperature [cdegC] ECU/electronics board temperature.
 * @param ecu_cpu_load [%] ECU processor load.
 * @param servo_supply_voltage [mV] Throttle-servo / actuator supply voltage.
 * @param servo_output_level [%] Electronic-throttle / servo commanded output level.
 * @param water_pump_duty_cycle [%] Coolant-pump power output, as a percentage of maximum.
 * @param injector_duty_cycle [%] Primary injector duty cycle.
 * @param fuel_mass_rate [g/min] Instantaneous fuel consumption by mass. NaN if not provided.
 * @param commanded_rpm [rpm] Governor/target RPM setpoint.
 * @param engine_runtime [s] Cumulative engine run time (hobbs).
 * @param error_memory_count  Number of faults currently stored in the ECU error memory.
 * @param boost_pressure [kPa] Forced-induction boost pressure. NaN if not provided.
 * @param coolant_pressure [kPa] Coolant-circuit pressure. NaN if not provided.
 * @param engine_torque [%] Percent engine torque (signed; negative = motoring/braking).
 * @param status_flags  EFI status flags.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_efi_performance_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t ecu_index,uint8_t fuel_pump_duty_cycle,uint16_t fuel_pump_voltage,uint16_t fuel_pump_current,uint16_t ecu_supply_voltage,uint16_t ecu_current,int16_t ecu_temperature,uint8_t ecu_cpu_load,uint16_t servo_supply_voltage,uint8_t servo_output_level,uint8_t water_pump_duty_cycle,uint8_t injector_duty_cycle,float fuel_mass_rate,float commanded_rpm,uint32_t engine_runtime,uint8_t error_memory_count,float boost_pressure,float coolant_pressure,int16_t engine_torque,uint64_t status_flags)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EFI_PERFORMANCE_LEN];
    _mav_put_uint64_t(buf, 0, status_flags);
    _mav_put_float(buf, 8, fuel_mass_rate);
    _mav_put_float(buf, 12, commanded_rpm);
    _mav_put_uint32_t(buf, 16, engine_runtime);
    _mav_put_float(buf, 20, boost_pressure);
    _mav_put_float(buf, 24, coolant_pressure);
    _mav_put_uint16_t(buf, 28, fuel_pump_voltage);
    _mav_put_uint16_t(buf, 30, fuel_pump_current);
    _mav_put_uint16_t(buf, 32, ecu_supply_voltage);
    _mav_put_uint16_t(buf, 34, ecu_current);
    _mav_put_int16_t(buf, 36, ecu_temperature);
    _mav_put_uint16_t(buf, 38, servo_supply_voltage);
    _mav_put_int16_t(buf, 40, engine_torque);
    _mav_put_uint8_t(buf, 42, ecu_index);
    _mav_put_uint8_t(buf, 43, fuel_pump_duty_cycle);
    _mav_put_uint8_t(buf, 44, ecu_cpu_load);
    _mav_put_uint8_t(buf, 45, servo_output_level);
    _mav_put_uint8_t(buf, 46, water_pump_duty_cycle);
    _mav_put_uint8_t(buf, 47, injector_duty_cycle);
    _mav_put_uint8_t(buf, 48, error_memory_count);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EFI_PERFORMANCE_LEN);
#else
    mavlink_efi_performance_t packet;
    packet.status_flags = status_flags;
    packet.fuel_mass_rate = fuel_mass_rate;
    packet.commanded_rpm = commanded_rpm;
    packet.engine_runtime = engine_runtime;
    packet.boost_pressure = boost_pressure;
    packet.coolant_pressure = coolant_pressure;
    packet.fuel_pump_voltage = fuel_pump_voltage;
    packet.fuel_pump_current = fuel_pump_current;
    packet.ecu_supply_voltage = ecu_supply_voltage;
    packet.ecu_current = ecu_current;
    packet.ecu_temperature = ecu_temperature;
    packet.servo_supply_voltage = servo_supply_voltage;
    packet.engine_torque = engine_torque;
    packet.ecu_index = ecu_index;
    packet.fuel_pump_duty_cycle = fuel_pump_duty_cycle;
    packet.ecu_cpu_load = ecu_cpu_load;
    packet.servo_output_level = servo_output_level;
    packet.water_pump_duty_cycle = water_pump_duty_cycle;
    packet.injector_duty_cycle = injector_duty_cycle;
    packet.error_memory_count = error_memory_count;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EFI_PERFORMANCE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EFI_PERFORMANCE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_EFI_PERFORMANCE_MIN_LEN, MAVLINK_MSG_ID_EFI_PERFORMANCE_LEN, MAVLINK_MSG_ID_EFI_PERFORMANCE_CRC);
}

/**
 * @brief Encode a efi_performance struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param efi_performance C-struct to read the message contents from
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_efi_performance_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_efi_performance_t* efi_performance)
{
    return mavlink_msg_efi_performance_pack(system_id, component_id, msg, efi_performance->ecu_index, efi_performance->fuel_pump_duty_cycle, efi_performance->fuel_pump_voltage, efi_performance->fuel_pump_current, efi_performance->ecu_supply_voltage, efi_performance->ecu_current, efi_performance->ecu_temperature, efi_performance->ecu_cpu_load, efi_performance->servo_supply_voltage, efi_performance->servo_output_level, efi_performance->water_pump_duty_cycle, efi_performance->injector_duty_cycle, efi_performance->fuel_mass_rate, efi_performance->commanded_rpm, efi_performance->engine_runtime, efi_performance->error_memory_count, efi_performance->boost_pressure, efi_performance->coolant_pressure, efi_performance->engine_torque, efi_performance->status_flags);
}

/**
 * @brief Encode a efi_performance struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param efi_performance C-struct to read the message contents from
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_efi_performance_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_efi_performance_t* efi_performance)
{
    return mavlink_msg_efi_performance_pack_chan(system_id, component_id, chan, msg, efi_performance->ecu_index, efi_performance->fuel_pump_duty_cycle, efi_performance->fuel_pump_voltage, efi_performance->fuel_pump_current, efi_performance->ecu_supply_voltage, efi_performance->ecu_current, efi_performance->ecu_temperature, efi_performance->ecu_cpu_load, efi_performance->servo_supply_voltage, efi_performance->servo_output_level, efi_performance->water_pump_duty_cycle, efi_performance->injector_duty_cycle, efi_performance->fuel_mass_rate, efi_performance->commanded_rpm, efi_performance->engine_runtime, efi_performance->error_memory_count, efi_performance->boost_pressure, efi_performance->coolant_pressure, efi_performance->engine_torque, efi_performance->status_flags);
}

/**
 * @brief Encode a efi_performance struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param efi_performance C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_efi_performance_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_efi_performance_t* efi_performance)
{
    return mavlink_msg_efi_performance_pack_status(system_id, component_id, _status, msg,  efi_performance->ecu_index, efi_performance->fuel_pump_duty_cycle, efi_performance->fuel_pump_voltage, efi_performance->fuel_pump_current, efi_performance->ecu_supply_voltage, efi_performance->ecu_current, efi_performance->ecu_temperature, efi_performance->ecu_cpu_load, efi_performance->servo_supply_voltage, efi_performance->servo_output_level, efi_performance->water_pump_duty_cycle, efi_performance->injector_duty_cycle, efi_performance->fuel_mass_rate, efi_performance->commanded_rpm, efi_performance->engine_runtime, efi_performance->error_memory_count, efi_performance->boost_pressure, efi_performance->coolant_pressure, efi_performance->engine_torque, efi_performance->status_flags);
}

/**
 * @brief Send a efi_performance message
 * @param chan MAVLink channel to send the message
 *
 * @param ecu_index  Electronic Control Unit (ECU) index for systems with multiple EFI units. Set to 0 for the first (or only) ECU.
 * @param fuel_pump_duty_cycle [%] Fuel pump power output, as a percentage of maximum. 0 = off, 100 = full power.
 * @param fuel_pump_voltage [mV] Fuel pump supply voltage.
 * @param fuel_pump_current [cA] Fuel pump current draw.
 * @param ecu_supply_voltage [mV] ECU supply voltage.
 * @param ecu_current [cA] ECU current draw.
 * @param ecu_temperature [cdegC] ECU/electronics board temperature.
 * @param ecu_cpu_load [%] ECU processor load.
 * @param servo_supply_voltage [mV] Throttle-servo / actuator supply voltage.
 * @param servo_output_level [%] Electronic-throttle / servo commanded output level.
 * @param water_pump_duty_cycle [%] Coolant-pump power output, as a percentage of maximum.
 * @param injector_duty_cycle [%] Primary injector duty cycle.
 * @param fuel_mass_rate [g/min] Instantaneous fuel consumption by mass. NaN if not provided.
 * @param commanded_rpm [rpm] Governor/target RPM setpoint.
 * @param engine_runtime [s] Cumulative engine run time (hobbs).
 * @param error_memory_count  Number of faults currently stored in the ECU error memory.
 * @param boost_pressure [kPa] Forced-induction boost pressure. NaN if not provided.
 * @param coolant_pressure [kPa] Coolant-circuit pressure. NaN if not provided.
 * @param engine_torque [%] Percent engine torque (signed; negative = motoring/braking).
 * @param status_flags  EFI status flags.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

MAVLINK_WIP
static inline void mavlink_msg_efi_performance_send(mavlink_channel_t chan, uint8_t ecu_index, uint8_t fuel_pump_duty_cycle, uint16_t fuel_pump_voltage, uint16_t fuel_pump_current, uint16_t ecu_supply_voltage, uint16_t ecu_current, int16_t ecu_temperature, uint8_t ecu_cpu_load, uint16_t servo_supply_voltage, uint8_t servo_output_level, uint8_t water_pump_duty_cycle, uint8_t injector_duty_cycle, float fuel_mass_rate, float commanded_rpm, uint32_t engine_runtime, uint8_t error_memory_count, float boost_pressure, float coolant_pressure, int16_t engine_torque, uint64_t status_flags)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EFI_PERFORMANCE_LEN];
    _mav_put_uint64_t(buf, 0, status_flags);
    _mav_put_float(buf, 8, fuel_mass_rate);
    _mav_put_float(buf, 12, commanded_rpm);
    _mav_put_uint32_t(buf, 16, engine_runtime);
    _mav_put_float(buf, 20, boost_pressure);
    _mav_put_float(buf, 24, coolant_pressure);
    _mav_put_uint16_t(buf, 28, fuel_pump_voltage);
    _mav_put_uint16_t(buf, 30, fuel_pump_current);
    _mav_put_uint16_t(buf, 32, ecu_supply_voltage);
    _mav_put_uint16_t(buf, 34, ecu_current);
    _mav_put_int16_t(buf, 36, ecu_temperature);
    _mav_put_uint16_t(buf, 38, servo_supply_voltage);
    _mav_put_int16_t(buf, 40, engine_torque);
    _mav_put_uint8_t(buf, 42, ecu_index);
    _mav_put_uint8_t(buf, 43, fuel_pump_duty_cycle);
    _mav_put_uint8_t(buf, 44, ecu_cpu_load);
    _mav_put_uint8_t(buf, 45, servo_output_level);
    _mav_put_uint8_t(buf, 46, water_pump_duty_cycle);
    _mav_put_uint8_t(buf, 47, injector_duty_cycle);
    _mav_put_uint8_t(buf, 48, error_memory_count);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EFI_PERFORMANCE, buf, MAVLINK_MSG_ID_EFI_PERFORMANCE_MIN_LEN, MAVLINK_MSG_ID_EFI_PERFORMANCE_LEN, MAVLINK_MSG_ID_EFI_PERFORMANCE_CRC);
#else
    mavlink_efi_performance_t packet;
    packet.status_flags = status_flags;
    packet.fuel_mass_rate = fuel_mass_rate;
    packet.commanded_rpm = commanded_rpm;
    packet.engine_runtime = engine_runtime;
    packet.boost_pressure = boost_pressure;
    packet.coolant_pressure = coolant_pressure;
    packet.fuel_pump_voltage = fuel_pump_voltage;
    packet.fuel_pump_current = fuel_pump_current;
    packet.ecu_supply_voltage = ecu_supply_voltage;
    packet.ecu_current = ecu_current;
    packet.ecu_temperature = ecu_temperature;
    packet.servo_supply_voltage = servo_supply_voltage;
    packet.engine_torque = engine_torque;
    packet.ecu_index = ecu_index;
    packet.fuel_pump_duty_cycle = fuel_pump_duty_cycle;
    packet.ecu_cpu_load = ecu_cpu_load;
    packet.servo_output_level = servo_output_level;
    packet.water_pump_duty_cycle = water_pump_duty_cycle;
    packet.injector_duty_cycle = injector_duty_cycle;
    packet.error_memory_count = error_memory_count;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EFI_PERFORMANCE, (const char *)&packet, MAVLINK_MSG_ID_EFI_PERFORMANCE_MIN_LEN, MAVLINK_MSG_ID_EFI_PERFORMANCE_LEN, MAVLINK_MSG_ID_EFI_PERFORMANCE_CRC);
#endif
}

/**
 * @brief Send a efi_performance message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
MAVLINK_WIP
static inline void mavlink_msg_efi_performance_send_struct(mavlink_channel_t chan, const mavlink_efi_performance_t* efi_performance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_efi_performance_send(chan, efi_performance->ecu_index, efi_performance->fuel_pump_duty_cycle, efi_performance->fuel_pump_voltage, efi_performance->fuel_pump_current, efi_performance->ecu_supply_voltage, efi_performance->ecu_current, efi_performance->ecu_temperature, efi_performance->ecu_cpu_load, efi_performance->servo_supply_voltage, efi_performance->servo_output_level, efi_performance->water_pump_duty_cycle, efi_performance->injector_duty_cycle, efi_performance->fuel_mass_rate, efi_performance->commanded_rpm, efi_performance->engine_runtime, efi_performance->error_memory_count, efi_performance->boost_pressure, efi_performance->coolant_pressure, efi_performance->engine_torque, efi_performance->status_flags);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EFI_PERFORMANCE, (const char *)efi_performance, MAVLINK_MSG_ID_EFI_PERFORMANCE_MIN_LEN, MAVLINK_MSG_ID_EFI_PERFORMANCE_LEN, MAVLINK_MSG_ID_EFI_PERFORMANCE_CRC);
#endif
}

#if MAVLINK_MSG_ID_EFI_PERFORMANCE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
MAVLINK_WIP
static inline void mavlink_msg_efi_performance_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t ecu_index, uint8_t fuel_pump_duty_cycle, uint16_t fuel_pump_voltage, uint16_t fuel_pump_current, uint16_t ecu_supply_voltage, uint16_t ecu_current, int16_t ecu_temperature, uint8_t ecu_cpu_load, uint16_t servo_supply_voltage, uint8_t servo_output_level, uint8_t water_pump_duty_cycle, uint8_t injector_duty_cycle, float fuel_mass_rate, float commanded_rpm, uint32_t engine_runtime, uint8_t error_memory_count, float boost_pressure, float coolant_pressure, int16_t engine_torque, uint64_t status_flags)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, status_flags);
    _mav_put_float(buf, 8, fuel_mass_rate);
    _mav_put_float(buf, 12, commanded_rpm);
    _mav_put_uint32_t(buf, 16, engine_runtime);
    _mav_put_float(buf, 20, boost_pressure);
    _mav_put_float(buf, 24, coolant_pressure);
    _mav_put_uint16_t(buf, 28, fuel_pump_voltage);
    _mav_put_uint16_t(buf, 30, fuel_pump_current);
    _mav_put_uint16_t(buf, 32, ecu_supply_voltage);
    _mav_put_uint16_t(buf, 34, ecu_current);
    _mav_put_int16_t(buf, 36, ecu_temperature);
    _mav_put_uint16_t(buf, 38, servo_supply_voltage);
    _mav_put_int16_t(buf, 40, engine_torque);
    _mav_put_uint8_t(buf, 42, ecu_index);
    _mav_put_uint8_t(buf, 43, fuel_pump_duty_cycle);
    _mav_put_uint8_t(buf, 44, ecu_cpu_load);
    _mav_put_uint8_t(buf, 45, servo_output_level);
    _mav_put_uint8_t(buf, 46, water_pump_duty_cycle);
    _mav_put_uint8_t(buf, 47, injector_duty_cycle);
    _mav_put_uint8_t(buf, 48, error_memory_count);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EFI_PERFORMANCE, buf, MAVLINK_MSG_ID_EFI_PERFORMANCE_MIN_LEN, MAVLINK_MSG_ID_EFI_PERFORMANCE_LEN, MAVLINK_MSG_ID_EFI_PERFORMANCE_CRC);
#else
    mavlink_efi_performance_t *packet = (mavlink_efi_performance_t *)msgbuf;
    packet->status_flags = status_flags;
    packet->fuel_mass_rate = fuel_mass_rate;
    packet->commanded_rpm = commanded_rpm;
    packet->engine_runtime = engine_runtime;
    packet->boost_pressure = boost_pressure;
    packet->coolant_pressure = coolant_pressure;
    packet->fuel_pump_voltage = fuel_pump_voltage;
    packet->fuel_pump_current = fuel_pump_current;
    packet->ecu_supply_voltage = ecu_supply_voltage;
    packet->ecu_current = ecu_current;
    packet->ecu_temperature = ecu_temperature;
    packet->servo_supply_voltage = servo_supply_voltage;
    packet->engine_torque = engine_torque;
    packet->ecu_index = ecu_index;
    packet->fuel_pump_duty_cycle = fuel_pump_duty_cycle;
    packet->ecu_cpu_load = ecu_cpu_load;
    packet->servo_output_level = servo_output_level;
    packet->water_pump_duty_cycle = water_pump_duty_cycle;
    packet->injector_duty_cycle = injector_duty_cycle;
    packet->error_memory_count = error_memory_count;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EFI_PERFORMANCE, (const char *)packet, MAVLINK_MSG_ID_EFI_PERFORMANCE_MIN_LEN, MAVLINK_MSG_ID_EFI_PERFORMANCE_LEN, MAVLINK_MSG_ID_EFI_PERFORMANCE_CRC);
#endif
}
#endif

#endif

// MESSAGE EFI_PERFORMANCE UNPACKING


/**
 * @brief Get field ecu_index from efi_performance message
 *
 * @return  Electronic Control Unit (ECU) index for systems with multiple EFI units. Set to 0 for the first (or only) ECU.
 */
MAVLINK_WIP
static inline uint8_t mavlink_msg_efi_performance_get_ecu_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  42);
}

/**
 * @brief Get field fuel_pump_duty_cycle from efi_performance message
 *
 * @return [%] Fuel pump power output, as a percentage of maximum. 0 = off, 100 = full power.
 */
MAVLINK_WIP
static inline uint8_t mavlink_msg_efi_performance_get_fuel_pump_duty_cycle(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  43);
}

/**
 * @brief Get field fuel_pump_voltage from efi_performance message
 *
 * @return [mV] Fuel pump supply voltage.
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_efi_performance_get_fuel_pump_voltage(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  28);
}

/**
 * @brief Get field fuel_pump_current from efi_performance message
 *
 * @return [cA] Fuel pump current draw.
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_efi_performance_get_fuel_pump_current(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  30);
}

/**
 * @brief Get field ecu_supply_voltage from efi_performance message
 *
 * @return [mV] ECU supply voltage.
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_efi_performance_get_ecu_supply_voltage(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  32);
}

/**
 * @brief Get field ecu_current from efi_performance message
 *
 * @return [cA] ECU current draw.
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_efi_performance_get_ecu_current(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  34);
}

/**
 * @brief Get field ecu_temperature from efi_performance message
 *
 * @return [cdegC] ECU/electronics board temperature.
 */
MAVLINK_WIP
static inline int16_t mavlink_msg_efi_performance_get_ecu_temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  36);
}

/**
 * @brief Get field ecu_cpu_load from efi_performance message
 *
 * @return [%] ECU processor load.
 */
MAVLINK_WIP
static inline uint8_t mavlink_msg_efi_performance_get_ecu_cpu_load(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  44);
}

/**
 * @brief Get field servo_supply_voltage from efi_performance message
 *
 * @return [mV] Throttle-servo / actuator supply voltage.
 */
MAVLINK_WIP
static inline uint16_t mavlink_msg_efi_performance_get_servo_supply_voltage(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  38);
}

/**
 * @brief Get field servo_output_level from efi_performance message
 *
 * @return [%] Electronic-throttle / servo commanded output level.
 */
MAVLINK_WIP
static inline uint8_t mavlink_msg_efi_performance_get_servo_output_level(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  45);
}

/**
 * @brief Get field water_pump_duty_cycle from efi_performance message
 *
 * @return [%] Coolant-pump power output, as a percentage of maximum.
 */
MAVLINK_WIP
static inline uint8_t mavlink_msg_efi_performance_get_water_pump_duty_cycle(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  46);
}

/**
 * @brief Get field injector_duty_cycle from efi_performance message
 *
 * @return [%] Primary injector duty cycle.
 */
MAVLINK_WIP
static inline uint8_t mavlink_msg_efi_performance_get_injector_duty_cycle(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  47);
}

/**
 * @brief Get field fuel_mass_rate from efi_performance message
 *
 * @return [g/min] Instantaneous fuel consumption by mass. NaN if not provided.
 */
MAVLINK_WIP
static inline float mavlink_msg_efi_performance_get_fuel_mass_rate(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field commanded_rpm from efi_performance message
 *
 * @return [rpm] Governor/target RPM setpoint.
 */
MAVLINK_WIP
static inline float mavlink_msg_efi_performance_get_commanded_rpm(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field engine_runtime from efi_performance message
 *
 * @return [s] Cumulative engine run time (hobbs).
 */
MAVLINK_WIP
static inline uint32_t mavlink_msg_efi_performance_get_engine_runtime(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  16);
}

/**
 * @brief Get field error_memory_count from efi_performance message
 *
 * @return  Number of faults currently stored in the ECU error memory.
 */
MAVLINK_WIP
static inline uint8_t mavlink_msg_efi_performance_get_error_memory_count(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  48);
}

/**
 * @brief Get field boost_pressure from efi_performance message
 *
 * @return [kPa] Forced-induction boost pressure. NaN if not provided.
 */
MAVLINK_WIP
static inline float mavlink_msg_efi_performance_get_boost_pressure(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field coolant_pressure from efi_performance message
 *
 * @return [kPa] Coolant-circuit pressure. NaN if not provided.
 */
MAVLINK_WIP
static inline float mavlink_msg_efi_performance_get_coolant_pressure(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field engine_torque from efi_performance message
 *
 * @return [%] Percent engine torque (signed; negative = motoring/braking).
 */
MAVLINK_WIP
static inline int16_t mavlink_msg_efi_performance_get_engine_torque(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  40);
}

/**
 * @brief Get field status_flags from efi_performance message
 *
 * @return  EFI status flags.
 */
MAVLINK_WIP
static inline uint64_t mavlink_msg_efi_performance_get_status_flags(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Decode a efi_performance message into a struct
 *
 * @param msg The message to decode
 * @param efi_performance C-struct to decode the message contents into
 */
MAVLINK_WIP
static inline void mavlink_msg_efi_performance_decode(const mavlink_message_t* msg, mavlink_efi_performance_t* efi_performance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    efi_performance->status_flags = mavlink_msg_efi_performance_get_status_flags(msg);
    efi_performance->fuel_mass_rate = mavlink_msg_efi_performance_get_fuel_mass_rate(msg);
    efi_performance->commanded_rpm = mavlink_msg_efi_performance_get_commanded_rpm(msg);
    efi_performance->engine_runtime = mavlink_msg_efi_performance_get_engine_runtime(msg);
    efi_performance->boost_pressure = mavlink_msg_efi_performance_get_boost_pressure(msg);
    efi_performance->coolant_pressure = mavlink_msg_efi_performance_get_coolant_pressure(msg);
    efi_performance->fuel_pump_voltage = mavlink_msg_efi_performance_get_fuel_pump_voltage(msg);
    efi_performance->fuel_pump_current = mavlink_msg_efi_performance_get_fuel_pump_current(msg);
    efi_performance->ecu_supply_voltage = mavlink_msg_efi_performance_get_ecu_supply_voltage(msg);
    efi_performance->ecu_current = mavlink_msg_efi_performance_get_ecu_current(msg);
    efi_performance->ecu_temperature = mavlink_msg_efi_performance_get_ecu_temperature(msg);
    efi_performance->servo_supply_voltage = mavlink_msg_efi_performance_get_servo_supply_voltage(msg);
    efi_performance->engine_torque = mavlink_msg_efi_performance_get_engine_torque(msg);
    efi_performance->ecu_index = mavlink_msg_efi_performance_get_ecu_index(msg);
    efi_performance->fuel_pump_duty_cycle = mavlink_msg_efi_performance_get_fuel_pump_duty_cycle(msg);
    efi_performance->ecu_cpu_load = mavlink_msg_efi_performance_get_ecu_cpu_load(msg);
    efi_performance->servo_output_level = mavlink_msg_efi_performance_get_servo_output_level(msg);
    efi_performance->water_pump_duty_cycle = mavlink_msg_efi_performance_get_water_pump_duty_cycle(msg);
    efi_performance->injector_duty_cycle = mavlink_msg_efi_performance_get_injector_duty_cycle(msg);
    efi_performance->error_memory_count = mavlink_msg_efi_performance_get_error_memory_count(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_EFI_PERFORMANCE_LEN? msg->len : MAVLINK_MSG_ID_EFI_PERFORMANCE_LEN;
        memset(efi_performance, 0, MAVLINK_MSG_ID_EFI_PERFORMANCE_LEN);
    memcpy(efi_performance, _MAV_PAYLOAD(msg), len);
#endif
}
