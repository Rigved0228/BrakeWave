#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include "PIDController.h"
#include "WheelSpeedSensor.h"
#include "SlipRatioCalculator.h"
#include "BrakeForceController.h"

// Function to write data to a CSV file
void writeDataToCSV(const std::vector<double> &time, const std::vector<double> &vehicle_speed,
                    const std::vector<double> &wheel_speed, const std::vector<double> &slip_ratio,
                    const std::vector<double> &brake_force, const std::string &filename)
{
    std::ofstream file(filename);
    file << "Time,VehicleSpeed,WheelSpeed,SlipRatio,BrakeForce\n";
    for (size_t i = 0; i < time.size(); ++i)
    {
        file << time[i] << "," << vehicle_speed[i] << "," << wheel_speed[i] << ","
             << slip_ratio[i] << "," << brake_force[i] << "\n";
    }
    file.close();
}

int main()
{
    // Simulation parameters
    const int num_samples = 100;
    const double total_time = 10.0; // 10 seconds
    const double dt = total_time / num_samples;
    std::vector<double> time(num_samples);
    std::vector<double> vehicle_speed(num_samples);
    std::vector<double> wheel_speed(num_samples);
    std::vector<double> slip_ratio(num_samples);
    std::vector<double> brake_force(num_samples, 0.0);

    // Initialize vehicle speed (decelerating from 30 m/s to 0 m/s)
    for (int i = 0; i < num_samples; ++i)
    {
        time[i] = i * dt;
        vehicle_speed[i] = 30.0 * (1.0 - static_cast<double>(i) / num_samples);
    }

    // PID controller setup
    PIDController pid(0.5, 0.1, 0.05);
    double target_slip_ratio = 0.2;

    // Simulation loop
    for (int i = 1; i < num_samples; ++i)
    {
        // Calculate current wheel speed
        wheel_speed[i] = simulateWheelSpeed(vehicle_speed[i], brake_force[i - 1]);

        // Calculate slip ratio
        slip_ratio[i] = calculateSlipRatio(vehicle_speed[i], wheel_speed[i]);

        // Compute brake force using PID controller
        brake_force[i] = pid.compute(target_slip_ratio, slip_ratio[i], dt);

        // Output results for each step
        std::cout << "Time: " << time[i]
                  << " Vehicle Speed: " << vehicle_speed[i]
                  << " Wheel Speed: " << wheel_speed[i]
                  << " Slip Ratio: " << slip_ratio[i]
                  << " Brake Force: " << brake_force[i] << std::endl;
    }

    // Write data to CSV
    writeDataToCSV(time, vehicle_speed, wheel_speed, slip_ratio, brake_force, "simulation_data.csv");

    return 0;
}
