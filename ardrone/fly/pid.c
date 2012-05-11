/*
    pid.c - pid controller

    Copyright (C) 2011 Hugo Perquin - http://blog.perquin.com

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
    MA 02110-1301 USA.
*/
#include "pid.h"

void pid_Init(SPid *pid, float pGain, float iGain, float dGain, float iMin, float iMax) 
{
	pid->pGain=pGain;
	pid->dGain=dGain;
	pid->iGain=iGain;
	pid->iMax=iMax;
	pid->iMin=iMin;
	pid->dState=0;
	pid->iState=0;
}

float UpdatePID(SPid * pid, float error, float dt, float position) {
	float pTerm, dTerm, iTerm; 
	pTerm = pid->pGain * error; // calculate the proportional term 

	// calculate the integral state with appropriate limiting 
	pid->iState += error * dt; 
	if (pid->iState > pid->iMax) 
		pid->iState = pid->iMax; 
	else if (pid->iState < pid->iMin)
		pid->iState = pid->iMin; 

	iTerm = pid->iGain * pid->iState; // calculate the integral term 
	dTerm = pid->dGain * ((position - pid->dState)/dt); 
	pid->dState = position; 
	return pTerm + iTerm - dTerm; 
}

/*
previous_error = setpoint - actual_position
integral = 0
start:
  error = setpoint - actual_position
  integral = integral + (error*dt)
  derivative = (error - previous_error)/dt
  output = (Kp*error) + (Ki*integral) + (Kd*derivative)
  previous_error = error
  wait(dt)
  goto start
*/