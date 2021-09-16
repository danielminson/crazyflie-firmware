#include "mbed.h"
#include "crazyflie.h"
#include <cmath>
// #include "parameters.h"

// Define all motors as PWM objects
PwmOut motor_1(MOTOR1);
PwmOut motor_2(MOTOR2);
PwmOut motor_3(MOTOR3);
PwmOut motor_4(MOTOR4);

float omega_1;
float omega_2;
float omega_3;
float omega_4;

float control_motor ( float omega_r )
    {
        return a1*omega_r+a2*omega_r*omega_r;
    }

void mixer(float f_t, float tau_phi, float tau_theta, float tau_psi){
    float omega_1_sq = 0.25/kl*f_t - 0.25/(kl*l)*tau_phi - 0.25/(kl*l)*tau_theta - 0.25/kd*tau_psi; 
    float omega_2_sq = 0.25/kl*f_t - 0.25/(kl*l)*tau_phi + 0.25/(kl*l)*tau_theta + 0.25/kd*tau_psi;
    float omega_3_sq = 0.25/kl*f_t + 0.25/(kl*l)*tau_phi + 0.25/(kl*l)*tau_theta - 0.25/kd*tau_psi;
    float omega_4_sq = 0.25/kl*f_t + 0.25/(kl*l)*tau_phi - 0.25/(kl*l)*tau_theta + 0.25/kd*tau_psi;
    if(omega_1_sq>0){
        omega_1 = sqrt(omega_1_sq);
    }
    else{
        omega_1=0;
    }

    if (omega_2_sq>0){
        omega_2 = sqrt(omega_2_sq);
    }
    else{
        omega_2=0;
    }

    if(omega_3_sq>0){
        omega_3 = sqrt(omega_3_sq);
    }
    else{
        omega_3=0;
    }

    if(omega_4_sq>0){
        omega_4 = sqrt(omega_4_sq);
    }
    else{
        omega_4=0;
    }
}

void actuate(float f_t, float tau_phi, float tau_theta, float tau_psi){
    mixer (f_t , tau_phi , tau_theta , tau_psi );
    motor_1 = control_motor ( omega_1 ) ;
    motor_2 = control_motor ( omega_2 ) ;
    motor_3 = control_motor ( omega_3 ) ;
    motor_4 = control_motor ( omega_4 ) ;    
}

// Main program
int main()
{
    
    // Turn on red LEDs indicating motors are armed
    // Test all motors with different frequencies (to make different noises)
    motor_1.period(1.0/500.0);

    motor_2.period(1.0/500.0);

    motor_3.period(1.0/500.0);

    motor_4.period(1.0/500.0);

    actuate(0,0,0,-0.001);

    wait(5);

    actuate(0,0,0,0);


    while(true)
    {
    }
}
