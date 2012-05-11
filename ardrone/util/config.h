/*
    config.h - Config file for ardrone

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

#include "../util/type.h"
#ifndef _CONFIG_H
#define _CONFIG_H
// Advanced configuration of drone comportment
typedef struct {
	// Configuration of PID values
	float	iGain;
	float	pGain;
	float	dGain;
	
	bool	toMuchAngleActive;	// Should we cut the motors on too much angle
	u16		angleMax;			// Maximum angle of drone before cut-off
} configAdvanced;

typedef struct  {
	float	yawSpeed;			// Maximum yaw speed of the drone ( rad/s )
	u16		verticalSpeed;		// Maximum vertical speed of the drone
	u16		translationAngle;	// Maximum angle on translations
} configFlight;


configAdvanced getAdvancedConfig ();
int getSectionStart(FILE* f);
#endif