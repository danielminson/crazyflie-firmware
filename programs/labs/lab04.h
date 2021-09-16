#include "mbed.h"
#include "crazyflie.h"
// #include "parameters.h"

// Define all motors as PWM objects
PwmOut motor1(MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3(MOTOR3);
PwmOut motor4(MOTOR4);

int rad=1000;
int rad2=2000;


float control_motor ( float omega_r )
    {
        return a1*omega_r+a2*omega_r*omega_r;
    }

// Main program
int main()
{
    
    // Turn on red LEDs indicating motors are armed
    // Test all motors with different frequencies (to make different noises)
    motor1.period(1.0/500.0);
    motor1 = control_motor(rad);

    motor2.period(1.0/500.0);
    motor2 = control_motor(rad2);

    motor3.period(1.0/500.0);
    motor3 = control_motor(rad);

    motor4.period(1.0/500.0);
    motor4 = control_motor(rad2);

    wait(5);

    motor1 = 0.0;
    motor2 = 0.0;
    motor3 = 0.0;
    motor4 = 0.0;


    while(true)
    {
       
    }
}
