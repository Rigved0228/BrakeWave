#include "PIDController.h"

PIDController::PIDController(double kp, double ki, double kd)
    : kp(kp), ki(ki), kd(kd), integral(0), previous_error(0) {}

double PIDController::compute(double setpoint, double measured_value, double dt)
{
    double error = setpoint - measured_value;
    integral += error * dt;
    double derivative = (error - previous_error) / dt;
    double output = kp * error + ki * integral + kd * derivative;
    previous_error = error;
    return output;
}
