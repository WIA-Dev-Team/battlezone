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
 *	@headerfile Object.h "Object.cpp"
 *	@author Ben Hubler
 *	@date 4/16/2011
 *	@version 1.0.1
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

/**
 *	A function used to set the coordinate of the object
 *	@param _point is a Point used to set the X, Y, and Z coordinates of the objects pose
 */
void Object::setCoordinate(Point _point)
{
	pose.setPoint(_point);
}

/**
 *	An overloaded function to set coordinate using X, Y, and Z floats
 *	@param _x is a float representing the X coordinate
 *	@param _y is a float representing the Y coordinate
 *	@param _z is a float representing the Z coordinate
 */
void Object::setCoordinate(float _x, float _y, float _z)
{
	pose.setPoint(_x,_y,_z);
}

/**
 *	A function to set the orientation of the objects pose
 *	@param _theta is a float representing positive degrees from the x-axis
 */
void Object::setOrientation(float _theta)
{
	pose.setTheta(_theta);
}

/**
 *	A function to return a reference to the objects pose
 *	@return a reference to the objects pose
 */
Pose &Object::getPose()
{
	return pose;
}

/**
 *	A function to indicate if an object has been destroyed by reaching a health of 0
 *	@return a bool indicating if an object has been destroyed
 */
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

/**
 *	A function used to set the health of an object
 *	@param _health is an int representing the value of the objects health
 */
void Object::setHealth(int _health)
{
	health = _health;
}

/**
 *	A function used to set the objectID
 *	@param _objectid is an int representing the objects ID
 */
void Object::setObjectID(int _objectid)
{
	objectid = _objectid;
}

/**
 *	A function used to set the mobility of an object
 *	@param _movable is a bool representing if the object can move
 */
void Object::setMovable(bool _movable)
{
	movable = _movable;
}

/**
 *	A function used to get the health of an object
 *	@return an int representing the value of the objects health
 */
int Object::getHealth()
{
	return health;
}

/**
 *	A function used to get the object ID
 *	@return an int representing the value of the objects ID
 */
int Object::getObjectID()
{
	return objectid;
}