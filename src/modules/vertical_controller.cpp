#include "vertical_controller.h"

// Class constructor
VerticalController :: VerticalController()
{
    f_t = 0;
}

// Predict vertical position and velocity from model
void VerticalController :: control( float z_r,float z,float w)
{
    f_t = m*(control_siso(z_r, z, w, kp_ver, kd_ver) + g);

}
// Control torque (N.m) given reference angle (rad) and current angle (rad) and angular velocity (rad/s) with given controller gains
float VerticalController::control_siso(float pos_r, float pos, float vel, float kp, float kd){
    return kp*(pos_r - pos) + kd*(-vel);
}