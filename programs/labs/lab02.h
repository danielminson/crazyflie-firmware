#include "mbed.h"
#include "crazyflie.h"
// #include "parameters.h"

// Define all motors as PWM objects
PwmOut motor(MOTOR1);

float control_motor ( float omega_r )
    {
        return a1*omega_r+a2*omega_r*omega_r;
    }

// Main program
int main()
{
    
    // Turn on red LEDs indicating motors are armed
    // Test all motors with different frequencies (to make different noises)
    motor.period(1.0/500.0);
    motor = control_motor(1000.0);//1000 rad -> medido 11510

    wait(5);

    motor = 0.0;

    while(true)
    {
       
    }
}
