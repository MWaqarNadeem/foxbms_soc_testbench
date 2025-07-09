#pragma once

typedef enum {
    BMS_CHARGING,     /*!< battery is charged */
    BMS_DISCHARGING,  /*!< battery is discharged */
    BMS_RELAXATION,   /*!< battery relaxation ongoing */
    BMS_AT_REST,      /*!< battery is resting */
} BMS_CURRENT_FLOW_STATE_e;

extern BMS_CURRENT_FLOW_STATE_e BMS_GetBatterySystemState(void);
