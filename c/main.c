/**
 * @file    main.c
 * @brief   PID controller simulation implementation.
 *
 * @author  Saeed Ansari
 * @version 1.0
 * @date    2026-07-11
 *
 * @note
 * This code was designed and implemented by Saeed Ansari.
 */

#include <stdio.h>
#include "pid.h"


int main(void)
{

    PID_Controller controller;

    /////////////// [ PID gains can be set here ] ///////////////
    init_pid(&controller);
    ///////////////////////////////////////////////////////////

    int steps = (int)(SIM_TIME / DT);

    for(int i = 0; i < steps; i++)
    {
        const float time = (float)i * DT;
        controller.integral = pid(&controller, DT);
        controller.previous_output = controller.output;
        controller.output = plant_update(&controller, DT);

        printf("%f - ", controller.output);
    }
    
    return 0;
}
