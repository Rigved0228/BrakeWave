# BrakeWave

BrakeWave is a dynamic simulation project that models the behavior of an Anti-lock Braking System (ABS) using real-time data visualization. This project provides insights into vehicle dynamics, slip ratios, and brake force management, making it an excellent tool for understanding and optimizing braking performance.

## Features

- **Real-Time Data Simulation**: Simulates vehicle speed, wheel speed, slip ratio, and brake force in real-time.
- **Interactive Visualization**: Utilizes Plotly for interactive plots, allowing users to explore data dynamically.
- **PID Controller**: Implements a PID controller to manage brake force and maintain optimal slip ratios.
- **CSV Data Export**: Outputs simulation data to a CSV file for further analysis.

## Installation

1. **Clone the Repository**:

   ```bash
   git clone https://github.com/Rigved0228/BrakeWave.git
   cd BrakeWave

   ```

2. **_Set Up Python Environment_**: Create a virtual environment and install dependencies:
   Ensure you have Python installed. It's recommended to use a virtual environment.

   ```bash
    python -m venv env
    source env/bin/activate  # On Windows, use `env\Scripts\activate`

   ```

3. **_Install Dependnecies_**:

   ```bash
   pip install -r requirements.txt

   ```

4. **_Build the C++ Simulation Library_**:
   Navigate to the `cpp` directory and build the shared library:
   ```bash
   cd src
   g++ -o simulation main.cpp -I.
   ./simulation
   ```

## Usage

1. **_Run the Python Visualization_**:
   After generating the simulation data, run the Python script to visualize the results.

   ```bash
   python scripts/abs_simulation.py
   ```

2. **_Explore the Interactive Plots_**:
   Use the interactive Plotly plots to analyze vehicle speed, wheel speed, slip ratio, and brake force over time.

## Project Structure

- **src/:**:
  Contains the C++ source code for the ABS simulation.
- **scripts/:**:
  Contains the Python scripts for data visualization.
- **build/:**:
  Directory where simulation data is stored.
- **CMakeLists.txt:**:
  Configuration file for building the C++ simulation library.
- **requirements.txt:**
  Lists required Python packages.
- **README.MD:**:
  Provides information about the project and its usage.
