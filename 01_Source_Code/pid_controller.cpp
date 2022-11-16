/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#include "pid_controller.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kpi, double Kii, double Kdi, double output_lim_maxi, double output_lim_mini) {
    /**
    * TODO: Initialize PID coefficients (and errors, if needed)
    **/
   // Errors initialization.
    error_p = 0.0; // Proportional error.
    error_i = 0.0; // Integral error.
    error_d = 0.0; // Derivative error.

    // Constants initialization.
    Kp = Kpi; // Proportional constant.
    Ki = Kii; // Integral constant.
    Kd = Kdi; // Derivative constant.

    // Limits initialization.
    lim_min = output_lim_mini; // Minimal Output limit.
    lim_max = output_lim_maxi; // Maximum Output limit.
    
    // Delta time initialization.
    dt = 0.0; // Delta time.
}

void PID::UpdateError(double cte) {
    /**
    * TODO: Update PID errors based on cte.
    **/
    // Integral error calculus.
    error_i += (cte * dt);
   // Differential error calculus.
    if( dt > 0.0){ // Avoid division by zero.
        error_d = ((cte - error_p) / dt); // Differential error calculation.
    }
    else{
        error_d = 0.0; // If zero o other force to zero.
    }
	// Proportional error calculus.
    error_p = cte;

}

double PID::TotalError() {
    /**
    * TODO: Calculate and return the total error
    * The code should return a value in the interval [output_lim_mini, output_lim_maxi]
    */
   double control = ((Kp * error_p) + (Ki * error_i) + (Kd * error_d));
   
   // Limiting the control signal to minimum and maximum parameterized values. 
   // If the value is out of limits, will be 0.
   if (control < lim_min){
    control = lim_min;
   }
   else if (control > lim_max){
    control = lim_max;
   }

   // Return the control value.
   return control;
}

double PID::UpdateDeltaTime(double new_delta_time) {
    /**
    * TODO: Update the delta time with new value
    */
    dt = new_delta_time;
    
    return dt;
}