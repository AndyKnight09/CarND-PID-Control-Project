#include "PID.h"

#include <cmath>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;

  this->p_error = 0;
  this->i_error = 0;
  this->d_error = 0;
}

void PID::UpdateError(double cte) {
  // Update errors
  d_error = cte - p_error;
  i_error += cte;
  p_error = cte;

  // Limit integral error
  i_error = std::fmin(std::fmax(-100, i_error), 100);
}

double PID::TotalError() {
  return abs(d_error) + abs(i_error) + abs(p_error);
}

