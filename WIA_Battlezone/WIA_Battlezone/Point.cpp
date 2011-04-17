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
 *	along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 *	@file Point.cpp
 *	@headerfile Point.h "Point.h"
 *	@author Ben Hubler
 *	@date 4/14/2011
 *	@version 1.0
 */
#include "Point.h"

/**	
 *	Default constructor sets default values for x,y, and z to 0.0 during initialization
 */
Point::Point()
{
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

/** 
 *	Overloaded constructor to set x,y, and z during initialization
 *	@param _x is a float representing the X coordinate
 *	@param _y is a float representing the Y coordinate
 *	@param _z is a float representing the Z coordinate
 */
Point::Point(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

/** 
 *	Function to return X coordinate
 *	@return a float representing the X coordinate
 */
float Point::getX()
{
	return x;
}

/** 
 *	Function to return Y coordinate
 *	@return a float representing the Y coordinate
 */
float Point::getY()
{
	return y;
}

/** 
 *	Function to return Z coordinate
 *	@return a float representing the Z coordinate
 */
float Point::getZ()
{
	return z;
}

/** 
 *	Function to set X,Y, and Z coordinates
 *	@param _x is a float representing the X coordinate
 *	@param _y is a float representing the Y coordinate
 *	@param _z is a float representing the Z coordinate
 */
void Point::setPoint(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

/** 
 *	Function to set X,Y, and Z coordinates
 *	@param _point is a Point representing the X, Y, and Z coordinates
 */
void Point::setPoint(Point _point)
{
	x = _point.getX();
	y = _point.getY();
	z = _point.getZ();
}