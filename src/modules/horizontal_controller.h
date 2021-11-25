# ifndef horizontal_controller_h
# define horizontal_controller_h

# include "mbed.h"
# include "crazyflie.h"

// Horizontal estimator class
class HorizontalController
{
public :
// Class constructor
HorizontalController () ;
// Initialize class
void control(float x_r,float x,float u, float y_r,float y,float v);
// Horizontal positions (m) and velocities (m/s) estimations
float phi_r, theta_r;
//float x, y, u, v;
private :
// Flow sensor object
    float control_siso(float p_r, float p, float p_p, float kp, float kd);
};

# endif
