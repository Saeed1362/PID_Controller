/**
 * @file    main.cpp
 * @brief   PID controller simulation implementation.
 *
 * @author  Saeed Ansari
 * @version 1.0
 * @date    2026-07-05
 *
 * @note
 * This code was designed and implemented by Saeed Ansari.
 */

#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <random>
#include "PID.hpp"


int main()
{
    float output = 0.0f;
    float integral = 0.0f;
    float setpoint_amplitude = 1.0f;
    float noise_amplitude = 0.02f;
    float setpoint = setpoint_amplitude;
    float previous_output = output;
    float control_signal = 0.0f;

    bool noise_enable = true;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(-noise_amplitude, noise_amplitude);

    std::vector<float> time_data;
    std::vector<float> setpoint_data;
    std::vector<float> output_data;
    std::vector<float> control_data;

    int steps = static_cast<int>(PID_Controller::SIM_TIME / PID_Controller::dt);

    time_data.reserve(steps);
    setpoint_data.reserve(steps);
    output_data.reserve(steps);
    control_data.reserve(steps);

    //// [ PID gains can be set here via the constructor as: pid(kp, ki, kd)] ////    
    PID_Controller pid(1.0f, 5.5f, 0.1f);


    for(int i=0; i < steps; i++)
    {
        float t = i * PID_Controller::dt;

        float noise = noise_enable ? dist(gen) : 0.0f;
        float measured_output = output + noise;

        time_data.push_back(t);
        setpoint_data.push_back(setpoint);
        output_data.push_back(output);
        control_data.push_back(control_signal);

        integral = pid.PID(setpoint, output, integral, previous_output, &control_signal);
        previous_output = measured_output;
        output = pid.Plant_Update(output, control_signal);
    }
    pid.Plot_Result(time_data, setpoint_data, output_data, control_data);

    return 0;
}

