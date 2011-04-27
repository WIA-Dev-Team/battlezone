/*	This file is part of WIA Battlezone.
 *
 *	WIA Battlezone is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	 WIA Battlezone is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with WIA Battlezone.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 *	@file Tank.cpp
 *	@headerfile Tank.h "Tank.h"
 *	@author Ben Hubler
 *	@date 4/17/2011
 *	@version 1.0.1
 */

#include "Tank.h"

/**
 *	Default constructor for the tank class
 */
Tank::Tank():Object()
{
	turretoffset = 0.0;
	fieldofview = 0.0;
	cooldowntime = 10;
	lastfire = time(NULL) - cooldowntime;
}

/**
 *	Function returns true if the cooldowntime has passed
 *	@return bool value indicating if weapon cooldown timer has expired
 */
bool Tank::canFire()
{
	if(time(NULL) - lastfire >= cooldowntime)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
 *	Function to set lastfire when a shot is fired
 */
void Tank::shotFired()
{
	lastfire = time(NULL);
}