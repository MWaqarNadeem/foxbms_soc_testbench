#include "database_internals.hpp"
#include "database_api.hpp"

db_storage db{};

void init_db(float init_voltage, float init_temp){
    db.cs.timestamp_cur = 0;
    db.cs.previous_timestamp_cur = 0;
    db.cs.timestamp_cc = 0;
    db.cs.previous_timestamp_cc = 0;
    
    db.cs.current = 0;
    db.cs.current_counter = 0;

    //unit: mV
    db.minmax.voltage_max = init_voltage * 1000;
    db.minmax.voltage_min = init_voltage * 1000;
    db.minmax.voltage_mean = init_voltage * 1000;

    db.minmax.temperature_max = init_temp;
    db.minmax.temperature_min = init_temp;
    db.minmax.temperature_mean = init_temp;

}

void update_db(float voltage, float current, float temp){
    int dt = 0;
    int dt_ms = dt * 1000;

    db.cs.previous_timestamp_cur = db.cs.timestamp_cur;
    db.cs.timestamp_cur += dt_ms;

    // db.cs.previous_timestamp_cc = db.cs.timestamp_cc;
    // db.cs.timestamp_cc += dt_ms;

    db.cs.current = current * 1000; //unit: mA

    //unit: mV
    db.minmax.voltage_max = voltage * 1000;
    db.minmax.voltage_min = voltage * 1000;
    db.minmax.voltage_mean = voltage * 1000;

    db.minmax.temperature_max = temp;
    db.minmax.temperature_min = temp;
    db.minmax.temperature_mean = temp;

}
