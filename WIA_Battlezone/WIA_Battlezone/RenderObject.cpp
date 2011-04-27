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
 *	@file RenderType.cpp
 *	@headerfile RenderObject.h "RenderObject.h"
 *	@author Ben Hubler
 *	@date 4/26/2011
 *	@version 1.0.2
 */
#include "RenderObject.h"

/**
 *	Default constructor
 *	Sets all members to NULL and clears the points list
 */
RenderObject::RenderObject()
{
	objectid = NULL;
	maxdist = NULL;
	points.clear();
}

/**
 *	Overloaded constructor to set the objectid
 *	@param _objectid int value representing a unique number for each RenderObject
 */
RenderObject::RenderObject(int _objectid)
{
	objectid = _objectid;
	points.clear();
}

/**
 *	Overloaded constructor to set objectid and maxdist
 *	@param _objectid int value representing a unique number for each RenderObject
 *	@param _maxdist double value representing max distance from center of RenderObject
 */
RenderObject::RenderObject(int _objectid, double _maxdist)
{
	objectid = _objectid;
	maxdist = _maxdist;
	points.clear();
}

/**
 *	Function to return an iterator pointing to the beginning of points
 *	@return iterator pointing to the beginning of points list
 */
std::list<Point>::iterator RenderObject::getPointsBegin()
{
	return points.begin();
}

/**
 *	Function to return an iterator pointing to the end of points
 *	@return iterator pointing to the end of points list
 */
std::list<Point>::iterator RenderObject::getPointsEnd()
{
	return points.end();
}

/**
 *	Function to add a Point to a list of points
 *	@param _point is a Point with an X, Y, and Z coordinate
 */
void RenderObject::addPoint(Point _point)
{
	points.push_back(_point);
}

/**
 *	Function to return the objectID
 *	@return int value representing the objectID
 */
int RenderObject::getObjectID()
{
	return objectid;
}

/**
 *	Function to set objectid
 *	@param _objectid int value representing a unique number for each RenderObject
 */
void RenderObject::setObjectID(int _objectid)
{
	objectid = _objectid;
}

/**
 *	Function to set maxdist
 *	@param _maxdist double value representing max distance from center of RenderObject
 */
void RenderObject::setMaxDistance(double _maxdist)
{
	maxdist = _maxdist;
}

double RenderObject::getMaxDistance()
{
	return maxdist;
}
