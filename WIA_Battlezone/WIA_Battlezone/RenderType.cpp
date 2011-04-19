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
 *	@headerfile RenderType.h "RenderType.h"
 *	@author Ben Hubler
 *	@date 4/17/2011
 *	@version 1.0
 */
#include "RenderType.h"

/**
 *	Default constructor
 */
RenderType::RenderType()
{
	objectid = NULL;
	points.clear();
}

/**
 *	Overloaded constructor to set the objectid
 *	@param _objectid int value representing a unique number for each RenderType
 */
RenderType::RenderType(int _objectid)
{
	objectid = _objectid;
	points.clear();
}

/**
 *	Function to return an iterator pointing to the beginning of points
 *	@return iterator pointing to the beginning of points list
 */
std::list<Point>::iterator RenderType::getPointsBegin()
{
	return points.begin();
}

/**
 *	Function to return an iterator pointing to the end of points
 *	@return iterator pointing to the end of points list
 */
std::list<Point>::iterator RenderType::getPointsEnd()
{
	return points.end();
}

/**
 *	Function to add a Point to a list of points
 *	@param _point is a Point with an X, Y, and Z coordinate
 */
void RenderType::addPoint(Point _point)
{
	points.push_back(_point);
}

/**
 *	Function to return the objectID
 *	@return int value representing the objectID
 */
int RenderType::getObjectID()
{
	return objectid;
}