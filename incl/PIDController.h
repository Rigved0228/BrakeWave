#ifndef PIDCONTROLLER_H
#define PIDCONTROLLER_H

class PIDController
{
public:
    PIDController(double kp, double ki, double kd);
    double compute(double setpoint, double measured_value, double dt);

private:
    double kp, ki, kd;
    double integral, previous_error;
};

#endif // PIDCONTROLLER_H
