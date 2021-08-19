#include "mbed.h"
#include "crazyflie.h"
int f = 400;
// Define all LEDs as digital output objects
DigitalOut led_vermelho_dir(LED_RED_R);
DigitalOut led_vermelho_esq(LED_RED_L);
DigitalOut led_verde_dir(LED_GREEN_R);
DigitalOut led_verde_esq(LED_GREEN_L);
DigitalOut led_azul_esq(LED_BLUE_L);

// Define all motors as PWM objects
PwmOut motor1(MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3(MOTOR3);
PwmOut motor4(MOTOR4);
Timer ligando;

// Main program
int main()
{
    //desligando led vermelhos e verdes 
    led_vermelho_dir = 1;
    led_vermelho_esq = 1;

    led_verde_dir =1;
    led_verde_esq =1;
    // Blink blue LED indicating inicialization (5 seconds)
    ligando.start();
    for (int i=0; i<9;i++){
        led_azul_esq = 1;
        wait(0.5);
        led_azul_esq = 0;
        wait(0.5);
    }
    
    // Turn on red LEDs indicating motors are armed
    led_vermelho_dir = 0;
    led_vermelho_esq = 0;
    // Test all motors with different frequencies (to make different noises)
    motor1.period(1.0/f);
    motor1 = 0.01;
    wait(1);
    motor1.period(1.0/600);
    wait(1);
    motor1.period(1.0/800);
    wait(1);
    motor1 = 0.0;

    motor2.period(1.0/f);
    motor2 = 0.01;
    wait(1);
    motor2.period(1.0/600);
    wait(1);
    motor2.period(1.0/800);
    wait(1);
    motor2 = 0.0;

    motor3.period(1.0/f);
    motor3 = 0.01;
    wait(1);
    motor3.period(1.0/600);
    wait(1);
    motor3.period(1.0/800);
    wait(1);
    motor3 = 0.0;

    motor4.period(1.0/f);
    motor4 = 0.01;
    wait(1);
    motor4.period(1.0/600);
    wait(1);
    motor4.period(1.0/800);
    wait(1);
    motor4 = 0.0;

    // motor1 = 0.0;
    // motor2 = 0.0;
    // motor3 = 0.0;
    // motor4 = 0.0;
    // Turn off red LEDs indicating motors are disarmed
    led_vermelho_dir = 1;
    led_vermelho_esq = 1;
    wait(1);
    // Blink green LEDs indicating end of program
    led_verde_dir =0;
    led_verde_esq =0;

    wait(1);
    led_verde_dir =1;
    led_verde_esq =1;

    while(true)
    {
       
    }
}
