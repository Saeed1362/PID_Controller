/**
 * @file    pid.cpp
 * @brief   PID controller simulation implementation.
 *
 * @author  Saeed Ansari
 * @version 1.0
 * @date    2026-07-05
 *
 * @note
 * This code was designed and implemented by Saeed Ansari.
 */

#include "PID.hpp"
#include <vector>
#include <fstream>
#include <iostream>


float PID_Controller::PID(float setpoint, float output, float integral, float previous_output, float * control_signal)
    {
        float error = setpoint - output;

        integral += error * dt;
        float derivitive = -(output - previous_output) / dt;
        *control_signal = Kp * error + Ki * integral + Kd * derivitive;

        return integral;
    }


float PID_Controller::Plant_Update(float output, float control_signal)
    {
        float O = output + (dt * (-output + control_signal));
        return O;
    }


void PID_Controller::Plot_Result(const std::vector<float>& time_data,
                     const std::vector<float>& setpoint_data,
                     const std::vector<float>& output_data,
                     const std::vector<float>& control_data)
    {
        std::ofstream file("pid_result.csv");

        file << "time,setpoint,output,control_signal\n";

        for (size_t i = 0; i < time_data.size(); i++)
        {
            file << time_data[i] << ","
                 << setpoint_data[i] << ","
                 << output_data[i] << ","
                 /*<< control_data[i] <<*/ "\n";    //You can plot the control signal by uncommenting this line.
        }

        file.close();

#ifdef _WIN32
        FILE* gnuplot = _popen("gnuplot -persistent", "w");
#else
        FILE* gnuplot = popen("gnuplot -persistent", "w");
#endif

        if (gnuplot == nullptr)
        {
            std::cout << "Could not open gnuplot.\n";
            return;
        }

        fprintf(gnuplot, "set datafile separator ','\n");
        fprintf(gnuplot, "set title 'PID Controller Simulation'\n");
        fprintf(gnuplot, "set xlabel 'Time (s)'\n");
        fprintf(gnuplot, "set ylabel 'Amplitude'\n");
        fprintf(gnuplot, "set grid\n");

        fprintf(gnuplot,
                "plot 'pid_result.csv' using 1:2 with lines title 'Setpoint', "
                "'pid_result.csv' using 1:3 with lines title 'Output', "
                "'pid_result.csv' using 1:4 with lines title 'Control Signal'\n");

#ifdef _WIN32
        _pclose(gnuplot);
#else
        pclose(gnuplot);
#endif
}

