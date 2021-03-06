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
 *	@file RenderType.h
 */

#ifndef RENDEROBJECT_H
#define RENDEROBJECT_H

#include <list>
#include "Point.h"

/** 
 *	A class that is used to store information used to create images during the render process
 *	@author Ben Hubler
 *	@date 4/26/2011
 *	@version 1.0.2
 */
class RenderObject
{
public:
	RenderObject();
	RenderObject(int _objectid);
	RenderObject(int _objectid, double _maxdist);
	void addPoint(Point _point);
	void setObjectID(int _objectid);
	void setMaxDistance(double _maxdist);
	double getMaxDistance();
	int getObjectID();
	std::list<Point>::iterator getPointsBegin();
	std::list<Point>::iterator getPointsEnd();
private:
	int objectid;
	double maxdist;
	std::list<Point> points;
};

#endif
