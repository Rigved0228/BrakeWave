#include "SlipRatioCalculator.h"

double calculateSlipRatio(double vehicle_speed, double wheel_speed)
{
    if (vehicle_speed == 0)
    {
        return 0.0; // Avoid division by zero
    }
    return (vehicle_speed - wheel_speed) / vehicle_speed;
}
