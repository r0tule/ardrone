/*
    pid.h - pid controller

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
struct pid_struct 
{
	float kp;
	float ki;
	float kd;
	float i;
	float e_prev;
	float i_max;
};


typedef struct { 
  float dState; // Last position input 
  float iState; // Integrator state 
  float iMax, iMin; // Maximum and minimum allowable integrator state 
  float iGain, // integral gain 
        pGain, // proportional gain 
        dGain; // derivative gain 

} SPid; 

void pid_Init(SPid *pid, float pGain, float iGain, float dGain, float iMin, float iMax);
//float pid_Calc(pid_struct *pid, float error, float dt);
//float pid_CalcD(pid_struct *pid, float error, float dt, float d);
float UpdatePID(SPid * pid, float error, float dt, float position);
