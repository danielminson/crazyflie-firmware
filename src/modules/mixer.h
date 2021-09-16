#ifndef mixer_h
#define mixer_h

#include "mbed.h"
#include "crazyflie.h"
class Mixer
{
    public:

        Mixer();

        void actuate(float f_t, float tau_phi, float tau_theta, float tau_psi);

        void arm();

        void disarm();

        bool armed;

        bool armando;

    private:

        PwmOut motor_1, motor_2, motor_3, motor_4;

        DigitalOut led_verm_esq, led_verm_dir;

        float omega_r_1, omega_r_2, omega_r_3, omega_r_4;

        void mixer(float f_t, float tau_phi, float tau_theta, float tau_psi);

        float control_motor(float omega_r);

        
};

#endif