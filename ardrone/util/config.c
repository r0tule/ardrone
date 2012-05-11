/*
    config.c - Config file for ardrone

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

#define CONFIG_FILE "D:/Documents and Settings/A775189/Bureau/drone/ardrone/config/config.ini"
#define BUFFER_SIZE 1024

#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */

#include "config.h"
#include "iniparser.h"

configAdvanced getAdvancedConfig () {
	dictionary	*	ini ;
	configAdvanced config;
	
	ini = iniparser_load(CONFIG_FILE);
	
	config.pGain = (float)iniparser_getdouble(ini, "ADVANCED:pGain",  2);
	config.iGain = (float)iniparser_getdouble(ini, "ADVANCED:iGain",  100);
	config.dGain = (float)iniparser_getdouble(ini, "ADVANCED:dGain",  0.01);
	config.toMuchAngleActive = iniparser_getboolean(ini, "ADVANCED:toMuchAngle", true);
	config.angleMax = iniparser_getint(ini, "ADVANCED:angleMax", 90);
	
	iniparser_freedict(ini);
	return config;
}