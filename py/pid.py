"""
@file    pid.py
@brief   PID controller simulation implementation.

@author  Saeed Ansari
@version 1.0
@date    2026-07-05

@note
This code was designed and implemented by Saeed Ansari.
"""

import matplotlib.pyplot as plt
import random

DT = 0.01
SIM_TIME = 10.0
NOISE_ENABLE = 1

def PID(Kp, Ki, Kd, setpoint, output, integral, previous_output, dt):

    error = setpoint - output

    integral += error * dt
    derivitive = -(output  - previous_output) / dt
    control_signal = Kp * error + Ki * integral + Kd * derivitive

    return control_signal, integral


def Plant_Update(output, control_signal, dt):

    O = output + (dt * (-output + control_signal))
    return O

def plot_pid(time_data, setpoint_data, output_data, control_data):

    plt.plot(time_data, setpoint_data, label="Setpoint")
    plt.plot(time_data, output_data, label="Output")
    # plt.plot(time_data, control_data, label="Control Signal")  #You can uncomment this line to see the control signal as well
    plt.xlabel("Time (s)")
    plt.ylabel("Amplitude")
    plt.title("PID Controller Simulation")
    plt.grid(True)
    plt.legend()
    plt.show()



def main():
   
    output = 0.0
    integral = 0.0
    setpoint_amplitude = 1.0
    noise_amplitude = 0.08
    noise = random.uniform(-noise_amplitude, noise_amplitude)
    setpoint = setpoint_amplitude
    previous_output = output

    Kp = 1.0
    Ki = 20.5
    Kd = 0.1

    time_data = []
    setpoint_data = []
    output_data = []
    control_data = []

    steps = int(SIM_TIME / DT)

    for i in range(steps):
        time = i * DT

        noise = random.uniform(-noise_amplitude, noise_amplitude)
        measured_output = output + noise * NOISE_ENABLE

        control_signal, integral = PID(Kp, Ki, Kd, setpoint, measured_output, integral, previous_output, DT)
        previous_output = measured_output
        output = Plant_Update(output, control_signal, DT)

        time_data.append(time)
        output_data.append(output)
        setpoint_data.append(setpoint)
        control_data.append(control_signal)

    plot_pid(time_data, setpoint_data, output_data, control_data)




if __name__ == "__main__":
    main()