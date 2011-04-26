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

#ifndef OBJECT_H
#define OBJECT_H

/**	
 *	@file Object.h
 */

#include "Object.h"
#include "Pose.h"

/** 
 *	A class that is used to represent all objects in battlezone
 *	@author Ben Hubler
 *	@date 4/16/2011
 *	@version 1.0
 */
class Object
{
public:
	Object();
	Object(Pose _pose, int _health, int _objectid, bool _movable);
	void setCoordinate(Point _point);
	void setCoordinate(float _x, float _y, float _z);
	void setOrientation(float _theta);
	void setHealth(int _health);
	void setObjectID(int _objectid);
	void setMovable(bool _movable);
	Pose& getPose();
	bool isDestroyed();
	int getHealth();
private:
	Pose pose;
	int health;
	int objectid;
	bool movable;
};

#endif