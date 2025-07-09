#include "database_internals.hpp"
#include <cstring>
#include <iostream>
using std::cout;

extern "C" {
#include "database.h"
#include "std_types.h"
#include "database_cfg.h"

STD_RETURN_TYPE_e DB_ReadBlock(void *dataptrtoReceiver, const DATA_BLOCK_ID_TYPE_e blockID){
    if(dataptrtoReceiver == nullptr){
        return E_NOT_OK;
    }

    switch (blockID){
        case DATA_BLOCK_ID_CURRENT_SENSOR:
            cout << "Reading Current Sensor\n";
            memcpy(dataptrtoReceiver, &(db.cs), sizeof(DATA_BLOCK_CURRENT_SENSOR_s));
            break;
        case DATA_BLOCK_ID_MINMAX:
            cout << "Reading minmax voltages\n";
            memcpy(dataptrtoReceiver, &(db.minmax), sizeof(DATA_BLOCK_MINMAX_s));
            break;

        case DATA_BLOCK_ID_CONTFEEDBACK:
            cout << "Reading contactor feedback\n";
            memcpy(dataptrtoReceiver, &(db.cfb), sizeof(DATA_BLOCK_CONTFEEDBACK_s));
            break;

        case DATA_BLOCK_ID_SOX:
            cout << "Reading SOX block\n";
            memcpy(dataptrtoReceiver, &(db.sox), sizeof(DATA_BLOCK_SOX_s));
            break;

        case DATA_BLOCK_ID_SOF:
            cout << "Reading SOF block\n";
            memcpy(dataptrtoReceiver, &(db.sof), sizeof(DATA_BLOCK_SOF_s));
            break;

    }

    return E_OK;
}

void DB_WriteBlock(const void *dataptrfromSender, const DATA_BLOCK_ID_TYPE_e blockID){
    if(dataptrfromSender == nullptr){
        return;
    }

    switch (blockID){
        case DATA_BLOCK_ID_CURRENT_SENSOR:
            cout << "Error: write to current sensor block!\n";
            // memcpy(&(db.cs), dataptrfromSender, sizeof(DATA_BLOCK_CURRENT_SENSOR_s));
            break;
        case DATA_BLOCK_ID_MINMAX:
            cout << "Error: write to minmax block!\n";
            // memcpy(&(db.minmax), dataptrfromSender, sizeof(DATA_BLOCK_MINMAX_s));
            break;
        case DATA_BLOCK_ID_CONTFEEDBACK:
            cout << "Error: write to contactor feedback block!\n";
            break;

        case DATA_BLOCK_ID_SOX:
            cout << "Updating SOX block\n";
            memcpy(&(db.sox), dataptrfromSender, sizeof(DATA_BLOCK_SOX_s));
            break;

        case DATA_BLOCK_ID_SOF:
            cout << "Updating SOF block\n";
            memcpy(&(db.sof), dataptrfromSender, sizeof(DATA_BLOCK_SOF_s));
            break;

    }
}
}
