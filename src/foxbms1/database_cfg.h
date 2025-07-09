#pragma once

#include <stdint.h>

typedef enum {
    DATA_BLOCK_ID_MINMAX,
    DATA_BLOCK_ID_SOX,
    DATA_BLOCK_ID_SOF,
    DATA_BLOCK_ID_CONTFEEDBACK,
    DATA_BLOCK_ID_CURRENT_SENSOR,
} DATA_BLOCK_ID_TYPE_e;

typedef struct {
    // uint32_t timestamp;
    // uint32_t previous_timestamp;

    int32_t current;

    float voltage[3];
    float power;
    float current_counter;
    // float energy_counter;

    uint32_t timestamp_cc;
    uint32_t previous_timestamp_cc;

    uint32_t timestamp_cur;
    uint32_t previous_timestamp_cur;
} DATA_BLOCK_CURRENT_SENSOR_s;

typedef struct {
    uint32_t voltage_mean;
    uint16_t voltage_min;
    uint16_t voltage_max;

    float temperature_mean;
    int16_t temperature_min;
    int16_t temperature_max;
} DATA_BLOCK_MINMAX_s;

typedef struct {
    /* Timestamp info needs to be at the beginning. Automatically written on DB_WriteBlock */
    uint32_t timestamp;                 /*!< timestamp of database entry                */
    uint32_t previous_timestamp;        /*!< timestamp of last database entry           */
    float soc_mean;                     /*!< 0.0 <= soc_mean <= 100.0           */
    float soc_min;                      /*!< 0.0 <= soc_min <= 100.0            */
    float soc_max;                      /*!< 0.0 <= soc_max <= 100.0            */
    uint8_t state;                      /*!<                                    */
} DATA_BLOCK_SOX_s;

typedef struct {
    uint32_t timestamp;                     /*!< timestamp of database entry                        */
    uint32_t previous_timestamp;            /*!< timestamp of last database entry                   */
    float recommended_continuous_charge;    /*!< recommended continuous operating charge current    */
    float recommended_continuous_discharge; /*!< recommended continuous operating discharge current */
    float recommended_peak_charge;          /*!< recommended peak operating charge current          */
    float recommended_peak_discharge;       /*!< recommended peak operating discharge current       */
    float continuous_charge_MOL;            /*!< charge current maximum operating level             */
    float continuous_discharge_MOL;         /*!< discharge current maximum operating level          */
    float continuous_charge_RSL;            /*!< charge current recommended safety level            */
    float continuous_discharge_RSL;         /*!< discharge current recommended safety level         */
    float continuous_charge_MSL;            /*!< charge current maximum safety level                */
    float continuous_discharge_MSL;         /*!< discharge current maximum safety level             */
} DATA_BLOCK_SOF_s;

typedef struct {
    /* Timestamp info needs to be at the beginning. Automatically written on DB_WriteBlock */
    uint32_t timestamp;                         /*!< timestamp of database entry                */
    uint32_t previous_timestamp;                /*!< timestamp of last database entry           */
    uint16_t contactor_feedback;                /*!< feedback of contactors, without interlock */
} DATA_BLOCK_CONTFEEDBACK_s;

