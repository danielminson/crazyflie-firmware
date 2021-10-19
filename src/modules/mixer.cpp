#include "mixer.h"

Mixer::Mixer() : motor_1(MOTOR1), motor_2(MOTOR2), motor_3(MOTOR3), motor_4(MOTOR4), led_verm_esq(LED_RED_L), led_verm_dir(LED_RED_R){
    motor_1.period(1.0/500.0);
    motor_2.period(1.0/500.0);
    motor_3.period(1.0/500.0);
    motor_4.period(1.0/500.0);
    motor_1=0.0;
    motor_2=0.0;
    motor_3=0.0;
    motor_4=0.0;
}

void Mixer:: arm(){
    motor_1.write(0.2);
    wait(0.2);
    motor_1=0.0;

    motor_2.write(0.2);
    wait(0.2);
    motor_2=0.0;

    motor_3.write(0.2);
    wait(0.2);
    motor_3=0.0;
    
    motor_4.write(0.2);
    wait(0.2);
    motor_4=0.0;

    wait(0.5);

    for(int i=0;i<=2;i++){
        led_verm_dir=0;
        led_verm_esq=0;
        wait(0.5);
        led_verm_dir=1;
        led_verm_esq=1;
        wait(0.5);
    }    
    armed=true;
}

void Mixer:: disarm(){
    armed=false;
    actuate(0,0,0,0);
}
void Mixer:: actuate(float f_t, float tau_phi, float tau_theta, float tau_psi){
    if (!armed) {
      motor_1 = 0;
      motor_2 = 0;
      motor_3 = 0;
      motor_4 = 0;
      led_verm_dir = 1;
      led_verm_esq = 1;
    }
     if (armed){
      mixer(f_t, tau_phi, tau_theta, tau_psi);
      motor_1 = control_motor(omega_r_1);
      motor_2 = control_motor(omega_r_2);
      motor_3 = control_motor(omega_r_3);
      motor_4 = control_motor(omega_r_4);
      led_verm_dir = 0;
      led_verm_esq = 0;
    }
}

void Mixer:: mixer(float f_t, float tau_phi, float tau_theta, float tau_psi){
    float omega_1_sq = 0.25/kl*f_t - 0.25/(kl*l)*tau_phi - 0.25/(kl*l)*tau_theta - 0.25/kd*tau_psi; 
    float omega_2_sq = 0.25/kl*f_t - 0.25/(kl*l)*tau_phi + 0.25/(kl*l)*tau_theta + 0.25/kd*tau_psi;
    float omega_3_sq = 0.25/kl*f_t + 0.25/(kl*l)*tau_phi + 0.25/(kl*l)*tau_theta - 0.25/kd*tau_psi;
    float omega_4_sq = 0.25/kl*f_t + 0.25/(kl*l)*tau_phi - 0.25/(kl*l)*tau_theta + 0.25/kd*tau_psi;
    if(omega_1_sq>0){
        omega_r_1 = sqrt(omega_1_sq);
    }
    else{
        omega_r_1=0;
    }

    if (omega_2_sq>0){
        omega_r_2 = sqrt(omega_2_sq);
    }
    else{
        omega_r_2=0;
    }

    if(omega_3_sq>0){
        omega_r_3 = sqrt(omega_3_sq);
    }
    else{
        omega_r_3=0;
    }

    if(omega_4_sq>0){
        omega_r_4 = sqrt(omega_4_sq);
    }
    else{
        omega_r_4=0;
    }

}

float Mixer::control_motor(float omega_r){
    return a1*omega_r+a2*omega_r*omega_r;
}
