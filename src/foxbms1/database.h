#pragma once

#include "database_cfg.h"
#include "std_types.h"

extern void DB_WriteBlock(const void *dataptrfromSender, const DATA_BLOCK_ID_TYPE_e  blockID);

extern STD_RETURN_TYPE_e DB_ReadBlock(void *dataptrtoReceiver, const DATA_BLOCK_ID_TYPE_e  blockID);
