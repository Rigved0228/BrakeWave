#include "WheelSpeedSensor.h"
#include <algorithm>
#include <cstdlib>

double simulateWheelSpeed(double vehicle_speed, double brake_force, double noise_level)
{
    // Generate random noise
    double noise = ((double)rand() / (RAND_MAX)) * noise_level;
    // Simulate wheel speed with noise and brake force effect
    double wheel_speed = vehicle_speed * (1 - noise) - brake_force;
    // Ensure wheel speed doesn't exceed vehicle speed and is not negative
    return std::max(0.0, std::min(wheel_speed, vehicle_speed));
}
