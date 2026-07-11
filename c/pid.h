/**
 * @file    pid.h
 * @brief   PID controller simulation implementation.
 *
 * @author  Saeed Ansari
 * @version 1.0
 * @date    2026-07-11
 *
 * @note
 * This code was designed and implemented by Saeed Ansari.
 */

#ifndef PID__H
#define  PID__H

#define SIM_TIME 10.0f
#define DT 0.1f

typedef struct pid
{
    float kp;
    float ki;
    float kd;

    float output;
    float previous_output;
    float integral;
    float updated_integral;
    float setpoint;
    float control_signal;

} PID_Controller;

void init_pid(PID_Controller * pid);
float pid(PID_Controller * pid,float dt);
float plant_update(PID_Controller * pid,float dt);

#endif
