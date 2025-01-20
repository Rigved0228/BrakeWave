cmake_minimum_required(VERSION 3.10)

# Set the project name
project(ABSSimulation)

# Add the executable
add_executable(abs_simulation
    src/main.cpp
    src/PIDController.cpp
    src/WheelSpeedSensor.cpp
    src/SlipRatioCalculator.cpp
    src/BrakeForceController.cpp
)

# Include directories
target_include_directories(abs_simulation PRIVATE incl)
