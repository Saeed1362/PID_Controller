/**
 * @file    pid.hpp
 * @brief   PID controller simulation implementation.
 *
 * @author  Saeed Ansari
 * @version 1.0
 * @date    2026-07-05
 *
 * @note
 * This code was designed and implemented by Saeed Ansari.
 */
#pragma once

#include <vector>

class PID_Controller
{
private:
    float Kp;
    float Ki;
    float Kd;

public:
    static constexpr float dt = 0.01f;
    static constexpr float  SIM_TIME = 50.0f;

    PID_Controller(float Kp_t, float Ki_t, float Kd_t) :
             Kp{Kp_t}, Ki{Ki_t}, Kd{Kd_t}
                {};
    float PID(float setpoint, float output, float integral, float previous_output, float * control_signal);

    float Plant_Update(float output, float control_signal);

void Plot_Result(const std::vector<float>& time_data,
                    const std::vector<float>& setpoint_data,
                    const std::vector<float>& output_data,
                    const std::vector<float>& control_data);

    ~PID_Controller(){};

};