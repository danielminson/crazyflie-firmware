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

const float dt = 0.002;
const float dt_range = 0.05;

// Ganho estimador atitude
const float omega_c = 1;
const float alpha=omega_c*dt/(1.0+omega_c*dt);

// Ganho controleador atitude
const float UP = 0.005;
const float Ts = 0.3;
const float zetta = abs(log(UP))/sqrt(pi*pi+log(UP)*log(UP));
const float wn = 4.0/(zetta*Ts);
const float kp_att = wn*wn;
const float kd_att = 2.0*zetta*wn;

const float Ts_psi = 0.6;//
const float wn_psi = 4.0/(zetta*Ts_psi);
const float kp_att_psi = wn_psi*wn_psi;
const float kd_att_psi = 2.0*zetta*wn_psi;

// Ganho estimador vertical
const float w_c = 10.0;
const float zetta_vert = sqrt(2.0)/2.0;
const float l1 = w_c*w_c;
const float l2 = w_c*2*zetta_vert;

// Ganho controlador vertical
const float Ts_ver = 2.0;
const float wn_ver = 4.0/(zetta*Ts_ver);
const float kp_ver = wn_ver*wn_ver;
const float kd_ver = 2.0*zetta*wn_ver;

const float W=420;
const float gamma = 42*pi/180;
const float sigma=2*tan(gamma/2)/(W*dt);
const float l_hor=50;

#endif