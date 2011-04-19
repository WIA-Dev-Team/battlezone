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
 *	@file Pose.cpp
 *	@headerfile Pose.h "Pose.h"
 *	@author Ben Hubler
 *	@date 4/14/2011
 *	@version 1.0
 */

#include "Pose.h"

/**
 *	Default constructor sets x, y, z, and theta to 0.0 during initialization
 */
Pose::Pose():Point()
{
	theta = 0.0;
}

/**
 *	Overloaded constructor sets x, y, z, and theta during initialization
 *	@param _x is a float representing the X coordinate
 *	@param _y is a float representing the Y coordinate
 *	@param _z is a float representing the Z coordinate
 *	@param _theta is a float representing the theta orientation
 */
Pose::Pose(float _x, float _y, float _z,float _theta):Point(_x, _y, _z)
{
	theta = _theta;
}

/**
 *	Function to set theta
 *	@param _theta is a float representing the theta orientation
 */
void Pose::setTheta(float _theta)
{
	theta = _theta;
}

/**
 *	Function to return the float value of theta
 *	@return float value for theta
 */
float Pose::getTheta()
{
	return theta;
}
