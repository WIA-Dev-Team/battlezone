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
 *	@file Point.h
 */

#ifndef POINT_H
#define POINT_H

/** 
 *	A class that is used to store X, Y, and Z float values used as coordinates
 *	@author Ben Hubler
 *	@date 4/14/2011
 *	@version 1.0
 */
class Point
{
public:
	Point();
	Point(float _x, float _y, float _z);
	float getX();
	float getY();
	float getZ();
	void setPoint(float _x, float _y, float _z);
	void setPoint(Point _point);

private:
	float x;
	float y;
	float z;
};

#endif
