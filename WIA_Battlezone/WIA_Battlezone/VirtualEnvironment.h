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
#include "RenderObject.h"

using namespace std;

#define ObjectPtr Object*
#define TankPtr Tank*
#define RenderListPtr vector<RenderObject>*

/** 
 *	Header file for virtual environment
 *	@author Aaron Parker
 *	@date 4/18/2011
 *	@version 1.0.0
 */
class VirtualEnvironment
{
public:
	//Constructors
	VirtualEnvironment();
	VirtualEnvironment(const VirtualEnvironment &env);
	VirtualEnvironment(RenderListPtr &_render_list, TankPtr &_tank);
	~VirtualEnvironment();

	//Functional Methods
	bool move(TankPtr &_tank, const float& _theta);
	bool fire(TankPtr &_tank);
	void add(ObjectPtr &_obj);
	void add(Object &_obj);
	void add(TankPtr &_tank);
	void remove(ObjectPtr &_obj);
	void prune();
	void generateEnv();
	int numObjects() const;

	vector<ObjectPtr>* VirtualEnvironment::getEnvironment();

private:
	vector<ObjectPtr> environment;
	int findObject(ObjectPtr &_obj);
	RenderListPtr render_list;
	
public:
	vector<ObjectPtr> findObjectsInFrontOf(ObjectPtr &_obj);
	vector<ObjectPtr> findObjectsNear(ObjectPtr &_obj,const float &_radius);
	Pose translatePose(Pose _pose, const float &_degree);
	float distanceBetween(ObjectPtr &_obj1, ObjectPtr &_obj2);

	void remove(const unsigned int &_object_index);
	//boundry somehow...
};

#endif