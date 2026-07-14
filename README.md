## How to Run

This project includes three versions of the PID controller simulation:

* Python version
* C++ version
* C version

All versions simulate a PID controller but C++ and Python plot the system response.

---

## Running the Python Version

### Requirements

Make sure Python is installed. Then install the required package:

```bash
pip install matplotlib
```

### Run

From the project directory, run:

```bash
python pid_controller.py
```

or:

```bash
python3 pid_controller.py
```

---

## Running the C++ Version

### Requirements

Make sure you have a C++ compiler installed, such as `g++`.

This version also uses `gnuplot` to plot the result, so make sure `gnuplot` is installed and available from the terminal.

### Compile

From the project directory, compile the code using:

```bash
g++ main.cpp PID.cpp -o pid_sim
```

### Run

On Windows:

```bash
pid_sim.exe
```

On Linux/macOS:

```bash
./pid_sim
```

The C++ program also generates a CSV file named:

```bash
pid_result.csv
```

This file contains the simulation data and can be plotted manually if needed.


## Running the C Version

### Requirements

Make sure you have a C compiler installed, such as `gcc`.

The C version runs the PID simulation but does not plot the system response.

### Compile

From the project directory, compile the code using:

```bash
gcc main.c pid.c -o pid_sim
```

### Run

On Windows:

```bash
pid_sim.exe
```

On Linux/macOS:

```bash
./pid_sim
```


<img width="640" height="480" alt="Py" src="https://github.com/user-attachments/assets/8f812806-6b35-47e4-bb39-1322afa09875" />
<img width="644" height="568" alt="cpp" src="https://github.com/user-attachments/assets/18a27fdb-6a4f-448e-8db4-8d870d292975" />

