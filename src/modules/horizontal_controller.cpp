#include "horizontal_controller.h"

// Class constructor
HorizontalController :: HorizontalController()
{
    theta_r=0;
    phi_r=0;
}

// Predict vertical position and velocity from model
void HorizontalController :: control( float x_r,float x,float u, float y_r,float y,float v)
{
    theta_r = 1/g*(control_siso(x_r, x, u, kp_ver, kd_ver));
    phi_r =-1/g*(control_siso(y_r, y, v, kp_ver, kd_ver));

}
// Control torque (N.m) given reference angle (rad) and current angle (rad) and angular velocity (rad/s) with given controller gains
float HorizontalController::control_siso(float p_r, float p, float p_p, float kp, float kd){
    return kp*(p_r - p) + kd*(-p_p);
}