#include "dut_wrapper.hpp"


extern "C" {
#include "sox.h"
#include "std_types.h"
}

void init_dut(){
    SOC_Init(FALSE);
}

void update_dut(){
    SOC_Calculation();
}