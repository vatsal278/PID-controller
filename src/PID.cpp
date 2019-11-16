#include "PID.h"


PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {

  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
  
  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;
  
  previous_cte = 0.0;
}

void PID::UpdateError(double cte) {

  p_error = cte;
  d_error = cte - previous_cte;
  i_error += cte;
  previous_cte = cte;


}

double PID::CalcSteer() {
  //calculate steer value
  static double steer;
  steer = -Kp*p_error - Kd*d_error - Ki*i_error;
    
  return steer;
}