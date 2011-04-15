// This file is part of WIA Battlezone.
//
// WIA Battlezone is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// WIA Battlezone is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
//

/*!	\author Ben Hubler
 *	\date 4/14/2011
 *	\version 1.0
 *	\class Point Point.h "Point.h"
 *	\brief This class is used to store x,y, and z coordinates
 */

#include "Pose.h"

Pose::Pose():Point()
{
	theta = 0;
}

Pose::Pose(float _x, float _y, float _z,float _theta):Point(_x, _y, _z)
{
	theta = _theta;
}
