#ifndef vertical_controller_h
#define vertical_controller_h

#include "mbed.h"
#include "crazyflie.h"


// Attitude controller class
class VerticalController {
public:
  // Class constructor
  VerticalController();
  // Control torques (N.m) given reference angles (rad) and current angles ( rad
  // ) and angular velocities ( rad /s)
  void control(float z_r, float z, float w);
  // Torques (N.m)
  float f_t;

private:
  // Control torque (N.m) given reference angle ( rad ) and current angle ( rad)
  // and angular velocity ( rad /s) with given controller gains
  float control_siso(float angle_r, float angle, float rate, float kp, float kd);
};
#endif
