#ifndef parameters_h
#define parameters_h

#include <cmath>

// Physical constants
const float pi = 3.1416;
const float g = 9.81;       // m/s^2

const float a2 = 1.16*pow(10,-7);
const float a1 = 4.488*pow(10,-12);

const float kl = 1.984*pow(10,-8); 
const float kd = 1.825*pow(10,-10); 

// Quadcopter dimensions
const float m = 30.0e-3;    // kg
const float I_xx = 16.0e-6; // kg.m^2
const float I_yy = 16.0e-6; // kg.m^2
const float I_zz = 29.0e-6; // kg.m^2
const float l = 33.0e-3;    // m


#endif