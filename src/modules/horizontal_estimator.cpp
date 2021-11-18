# include "horizontal_estimator.h"

// Class constructor
HorizontalEstimator :: HorizontalEstimator () : flow (PA_7 ,PA_6 ,PA_5 , PB_4 )
{
x=0;
y=0;
u=0;
v=0;
}
// Initialize class
void HorizontalEstimator :: init ()
{
flow.init();
}

 // Predict horizontal positions and velocities from model
void HorizontalEstimator :: predict ( float phi , float theta )
{
    x=x+u*dt;
    y=y+v*dt;
    u=u+g*theta*dt;
    v=v-g*theta*dt;
}

// Correct horizontal velocities with measurements
void HorizontalEstimator :: correct ( float phi , float theta , float p, float q, float z)
{
 
float div = cos ( phi )* cos ( theta ) ;
if ( div > 0.5)
{
float d = z/ div;
flow.read () ;
float u_m = (sigma*flow.px+q)*d;
float v_m = (sigma*flow.py-p)*d;
u = u+l_hor*dt*(u_m-u);
v = v+l_hor*dt*(v_m-v);

}
}