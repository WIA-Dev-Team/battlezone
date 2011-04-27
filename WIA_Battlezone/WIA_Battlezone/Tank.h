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
 *	@file Tank.h
 */

#ifndef TANK_H
#define TANK_H

#include "Object.h"
#include <time.h>

/** 
 *	A subclass that is used to store information about a tank object
 *	@author Ben Hubler
 *	@date 4/17/2011
 *	@version 1.0.1
 */
class Tank:public Object
{
public:
	Tank();
	bool canFire();
	void shotFired();

private:
	float turretoffset; /**< Degrees from positive x-axis for turrent view */
	float fieldofview;
	time_t lastfire;
	int cooldowntime;

};

#endif
