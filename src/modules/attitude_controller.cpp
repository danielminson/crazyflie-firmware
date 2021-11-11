# include "attitude_controller.h"

// Class constructor
AttitudeController :: AttitudeController ()
{
tau_theta = 0;
tau_phi = 0;
tau_psi = 0;
}


// Control torque (N.m) given reference angle ( rad ) and current angle ( rad ) and angular velocity ( rad /s) with given controller gains
float AttitudeController :: control_siso (float angle_r, float angle, float rate, float kp_c, float kd_c)
{
    return kp_c*(angle_r-angle)+kd_c*(-rate);
}

// Control torques (N.m) given reference angles ( rad) and current angles ( rad ) and angular velocities ( rad /s)
void AttitudeController :: control (float phi_r , float theta_r, float psi_r, float phi, float theta, float psi, float p, float q, float r)
{
    tau_phi = I_xx*control_siso(phi_r, phi, p, kp_att, kd_att);
    tau_theta = I_yy*control_siso(theta_r, theta, q, kp_att, kd_att);
    tau_psi = I_zz*control_siso(psi_r, psi, r, kp_att_psi, kd_att_psi);
}
