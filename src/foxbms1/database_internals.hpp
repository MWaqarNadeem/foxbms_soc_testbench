#pragma once

extern "C" {
#include "database_cfg.h"
}

struct db_storage {
    DATA_BLOCK_CURRENT_SENSOR_s cs;
    DATA_BLOCK_MINMAX_s minmax;
    DATA_BLOCK_SOX_s sox;
    DATA_BLOCK_SOF_s sof;
    DATA_BLOCK_CONTFEEDBACK_s cfb;
};

extern db_storage db;

