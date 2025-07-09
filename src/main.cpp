#include "bms_api.hpp"
#include "dut/dut_wrapper.hpp"
#include "database_api.hpp"

// Standard libs
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    // input.csv 
    FILE *ip_file = fopen("input.csv", "r");
    if(!ip_file){
        printf("Error opening input file\n");
        return false;
    }

    // output.csv
    FILE *op_file = fopen("output.csv", "w");
    if(!op_file){
        printf("Error opening output file\n");
        fclose(ip_file);
        return false;
    }

    // write header to output file
    fprintf(op_file, "Voltage,Current,Temperature\n");

    // Initialize BMS
    init_db(3.7, 25);   // Initialize database with nominal voltage and temperature, cellminmax
    bms_idle();         // Need to confirm if we need different states, here it is `bms_state = state::Idle;`
    init_dut();         // Initialize dut (Device Under Test), here it is `SOC_Init(FALSE);`, meaning LUT is not used
    update_dut();       // Update DUT to set initial state, it is calling `SOC_Calculation();`, which is defined in `sox.c`


    // Read input file and update database
    char line[256];     // considering maximum 256 characters per line (3 comma seperated values)
    
    // changing from 10 to 15000, // as we are reading from input file, 
    // 500 to 600 lines will be utilized to update the state, and then proper SoC estimation will be done
    for(unsigned i = 0; i < 15000; i++){
        float voltage, current, temperature;

        fscanf(ip_file, "%f,%f,%f\n", &voltage, &current, &temperature);

        // Update database with values from input file
        //update_db(0.1, 0, 3.7, 25);
        update_db(voltage, current, temperature);   // remember to follow the seq, V, I, T

        // SoC calculation
        update_dut();
    }

    bms_discharge();

    for(unsigned i = 0; i < 10; i++){
        update_db(0.1, 0, 3.7, 25);

        update_dut();
    }

    return 0;
}
