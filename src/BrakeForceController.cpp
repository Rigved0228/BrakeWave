#include "BrakeForceController.h"
#include <algorithm>

double adjustBrakeForce(double current_brake_force, double adjustment)
{
    // Adjust the brake force based on the PID controller output
    double new_brake_force = current_brake_force + adjustment;
    // Ensure the brake force is within realistic bounds (e.g., 0 to 1)
    return std::max(0.0, std::min(new_brake_force, 1.0));
}
