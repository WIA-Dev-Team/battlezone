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
 *	@file VirtualEnvironment.h
 */

#ifndef VIRTUAL_ENVIRONMENT_H
#define VIRTUAL_ENVIRONMENT_H

#include "Tank.h"
#include <Vector>

using namespace std;

#define ObjectPtr Object*
#define TankPtr Tank*

/** 
 *	Header file for virtual environment
 *	@author Aaron Parker
 *	@date 4/18/2011
 *	@version 1.0.0
 */
class VirtualEnvironment
{
public:
	VirtualEnvironment();
	VirtualEnvironment(const VirtualEnvironment &env);
	~VirtualEnvironment();

	bool move(TankPtr &_tank, Pose &_pose);
	bool fire(TankPtr &_tank);
	void add(ObjectPtr &_obj);
	void add(Object &_obj);
	void remove(ObjectPtr &_obj);
	void prune();
	void generateEnv();

	int numObjects() const;

private:
	vector<ObjectPtr> environment;
	int findObject(ObjectPtr &_obj);
	void remove(const int &_object_index);
	//boundry somehow...
};

#endif