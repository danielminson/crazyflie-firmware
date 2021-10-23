# include "attitude_estimator.h"

// Class constructor
AttitudeEstimator :: AttitudeEstimator () : imu ( IMU_SDA , IMU_SCL )
{
phi =0;
theta =0;
psi =0;
p=0;
q =0;
r =0;
}
// Initialize class
void AttitudeEstimator :: init ()
 {
 imu.init();
 float p_bias;
 for(int i=0;i<500;i++){
     imu.read();

     p_bias+=imu.gx/500.0;
     q_bias+=imu.ay/500.0;
     r_bias+=imu.az/500.0;
     wait(dt);

 }

 }

 // Estimate Euler angles (rad ) and angular velocities ( rad /s)
void AttitudeEstimator :: estimate ()
{
    imu.read();
    // float phi_a= atan2(-imu.ay,-imu.az);
    // phi = phi_a*alpha + (1-alpha)*phi;
    // p = imu.gx - p_bias;
    // float phi_g = phi+dt*p;
    // phi = phi_g*(1-0.1);

    // float phi_a= atan2(-imu.ay,-imu.az);
    // p = imu.gx - p_bias;
    // float phi_g = phi+dt*p;
    // phi = phi_g*(1-alpha)+phi_a*alpha;

    
    float phi_a= atan2(-imu.ay,-imu.az);
    float theta_a = atan2 (imu.ax,-(((imu.az>0)-(imu.az<0))*(sqrt(imu.ay*imu.ay+imu.az*imu.az))));
    p = imu.gx - p_bias;
    q = imu.gy - q_bias;
    r = imu.gz - r_bias;

    float phi_g = psi+dt*(sin(phi)*tan(theta)*q+cos(phi)*tan(theta)*r);  
    float theta_g = theta +dt*(sin(phi)*(1/cos(theta))*q+cos(phi)*(1/cos(theta))*r);
    float psi_g = psi+dt*(sin(phi)*(1/cos(theta))*q+cos(phi)*(1/cos(theta)*r));


    phi = phi_g*(1-alpha)+phi_a*alpha;
    theta = (1-alpha)*theta_g+alpha*theta_a;
    psi=psi_g;
}