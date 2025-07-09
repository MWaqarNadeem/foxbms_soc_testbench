#include "bms_api.hpp"
#include "database_internals.hpp"

enum class state{
    Charging,
    Discharging,
    Idle,
};

state bms_state = state::Idle;

extern "C"{
#include "bms.h"

BMS_CURRENT_FLOW_STATE_e BMS_GetBatterySystemState(){
    if(bms_state == state::Idle){
        return BMS_AT_REST;
    }
    else if (bms_state == state::Discharging) {
        return BMS_DISCHARGING;
    }

    return BMS_RELAXATION;
};
}

void bms_idle(){
    bms_state = state::Idle;

    // set contactors to idle
    db.cfb.contactor_feedback = 0;
}

void bms_discharge(){
    bms_state = state::Discharging;

    // enable main bus contactors
    db.cfb.contactor_feedback = 0x05;
}
