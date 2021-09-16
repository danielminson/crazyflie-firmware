#include "mbed.h"
#include "crazyflie.h"

Mixer mixer;

// Main program
int main()
{
    // Turn on red LEDs indicating motors are armed
    // Test all motors with different frequencies (to make different noises)
    mixer.arm();
    mixer.actuate(0, 0,0.005,0);

    wait(5);

    mixer.disarm();
    while(true)
    {
    }
}
