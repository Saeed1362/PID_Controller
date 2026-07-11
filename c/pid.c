/**
 * @file    pid.c
 * @brief   PID controller simulation implementation.
 *
 * @author  Saeed Ansari
 * @version 1.0
 * @date    2026-07-11
 *
 * @note
 * This code was designed and implemented by Saeed Ansari.
 */

#include "pid.h"

void init_pid(PID_Controller * pid)
{
        pid->kp = 1.0f;
        pid->ki = 1.0f;
        pid->kd = 0.1f;
        pid->control_signal = 0.0f;
        pid->integral = 0.0f;
        pid->updated_integral = 0.0f;
        pid->output = 0.0f;
        pid->setpoint = 1.0f;
        pid->previous_output = 0.0f;
}

float pid(PID_Controller * pid, float dt)
{
    float error = pid->setpoint - pid->output;

    pid->updated_integral = pid->integral + error * dt;
    float derivative = -(pid->output  - pid->previous_output) / dt;
    pid->control_signal = pid->kp * error + pid->ki * pid->updated_integral + pid->kd * derivative;

    return pid->updated_integral;
}

float plant_update(PID_Controller * pid, float dt)
{
    float Out = pid->output + (dt * (-pid->output + pid->control_signal));

    return Out;
}

