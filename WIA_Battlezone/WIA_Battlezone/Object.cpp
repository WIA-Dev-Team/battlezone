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
 *	@file Object.cpp
 *	@author Ben Hubler
 *	@date 4/16/2011
 *	@version 1.0
 */

#include "Object.h"
#include "Pose.h"

/**
 *	Default constructor sets pose to default, 
 *	health and objectid to 0, and movable to false
 */
Object::Object()
{
	pose = Pose();
	health = 0;
	objectid = 0;
	movable = false;
}

/**
 *	Overloaded constructor sets pose, health, objectid, and movable
 *	@param _pose is a Pose representing the position
 *	@param _health is an int representing the health
 *	@param _objectid is an int representing the unique objectid
 *	@param _movable is a bool representing if the object is movable
 */
Object::Object(Pose _pose, int _health, int _objectid, bool _movable)
{
	pose = _pose;
	health = _health;
	objectid = _objectid;
	movable = _movable;
}

void Object::setCoordinate(Point _point)
{
	pose.setPoint(_point);
}

void Object::setCoordinate(float _x, float _y, float _z)
{
	pose.setPoint(_x,_y,_z);
}

void Object::setOrientation(float _theta)
{
	pose.setTheta(_theta);
}

Pose& Object::getPose()
{
	return pose;
}

bool Object::isDestroyed()
{
	if(health <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Object::setHealth(int _health)
{
	health = _health;
}

void Object::setObjectID(int _objectid)
{
	objectid = _objectid;
}

void Object::setMovable(bool _movable)
{
	movable = _movable;
}

int Object::getHealth()
{
	return health;
}