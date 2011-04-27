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
 *	@file VirtualEnvironment.cpp
 */

#include "VirtualEnvironment.h"
#include <iostream>
#include <cassert>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEFAULT_MAX_NUM_OBJECTS 100
#define DEFAULT_MAX_DIST		400

#ifndef PI
#define PI 3.14159
#endif

#ifndef D2R
#define D2R(d) d*PI/180
#endif
/** 
 *	Source code for the virtual envirnoment, handles colisions, 
 *	move requests, fire requests, adding and removing objects, 
 *	creating randomly generated environments, and pruning 
 *	objects with no health.
 *	@author Aaron Parker
 *	@date 4/18/2011
 *	@version 1.0.0
 */

/**
 *	Default constructor, calls generateEnv()
 */
VirtualEnvironment::VirtualEnvironment()
{
}

/**
 *	Copy constructor
 */
VirtualEnvironment::VirtualEnvironment(const VirtualEnvironment &env)
{
	render_list = env.render_list;
	environment = env.environment;
}

/**
 *	Init's the render engine with the render_list and the tank given
 */
VirtualEnvironment::VirtualEnvironment(RenderListPtr &_render_list, TankPtr &_tank)
{
	init(_tank,_render_list);
}

/**
 *	Destroy all objects in the environment.
 */
VirtualEnvironment::~VirtualEnvironment()
{
	while(environment.size())
		remove(0);
}

/**
 *	Initizlizes the virtual environment, seeds random, assigns 
 *	the tank and render list pointers and generates a random environment
 */
void VirtualEnvironment::init(TankPtr &_tank,RenderListPtr _render_list)
{
	render_list = _render_list;
	srand ( time(NULL) );
	add(_tank); 
	generateEnv(DEFAULT_MAX_NUM_OBJECTS,DEFAULT_MAX_DIST);
}

/**
 *	Broken Code! Doesn't work!
 *	Moves the passed tank at angular velocity _degrees and forward _speed.  
 *	Returns false if a collision is detected and does not move the tank.
 */
bool VirtualEnvironment::move(TankPtr &_tank, const float& _degrees, const float &_speed)
{
	ObjectPtr obj = _tank;
	Pose previous_pose = _tank->getPose();

	cout << "(" << previous_pose.getX() << "," << previous_pose.getY() << "," << previous_pose.getZ() << ") " << previous_pose.getTheta() << endl; 

	float delta_x = cos(D2R(_degrees+90))*_speed;
	float delta_z = sin(D2R(_degrees+90))*_speed;

	_tank->getPose().setPoint(previous_pose.getX()+delta_x,previous_pose.getY(),previous_pose.getZ()-delta_z);
	_tank->getPose().setTheta(previous_pose.getTheta()+_degrees);

	vector<ObjectPtr> near_objects = findObjectsNear(obj,_speed+7.5);
	if(!near_objects.size())
		return true;
	else 
		_tank->getPose()=previous_pose;
	return false;
}

/**
 *	Fires the passed tank's gun, detects if it hits an object
 */
/*bool VirtualEnvironment::fire(TankPtr &_tank)
{
	ObjectPtr tank_obj = _tank;
	vector<ObjectPtr> front_objects = findObjectsInFrontOf(tank_obj);
	for(int i=0;i<front_objects.size();i++)
	{
		//if(front_objects[i])
	}
	return false;
}*/

/**
 *	Check's to see if the object is valid and not already in 
 *	the environment, then add's it to the environment.
 *	Add's object to the list (does not create a deep copy).
 */
void VirtualEnvironment::add(ObjectPtr &_obj)
{
	if(findObject(_obj)!=-1) return;
	environment.push_back(_obj);
}

/**
 *	Create's a deep copy of the passed object and adds it to the environment.
 *
 *	This will ALWAYS create a new object in the environment
 */
void VirtualEnvironment::add(Object &_obj)
{
	ObjectPtr obj = new Object(_obj);
	environment.push_back(obj);
}

/**
 *	Add's the passed tank pointer to the virtual environment
 */
void VirtualEnvironment::add(TankPtr &_tank)
{
	ObjectPtr obj = _tank;
	add(obj);
}

/**
 *	Find's the object in the environment, remvoes from vector,
 *	and deletes the object itself. Passed a pointer to an object.
 */
void VirtualEnvironment::remove(ObjectPtr &_obj)
{
	int index = findObject(_obj);
	if(index == -1) return;
	environment.erase(environment.begin()+index);
	delete _obj;
	_obj = NULL;
}

/**
 *	Find's the object in the environment, removes from vector,
 *	and deletes the object itself. Passed the index of the object
 *	in the vector. This is cheaper than passing the pointer 
 *	to the object because no search is needed.
 */
void VirtualEnvironment::remove(const unsigned int &_object_index)
{
	if(_object_index >= environment.size() || _object_index < (unsigned) 0) return;
	delete environment[_object_index];
	environment.erase(environment.begin()+_object_index);
}

/**
 *	Parses through the environment vector and removes all 
 *	destroyed objects.
 */
void VirtualEnvironment::prune()
{
	for(unsigned int i = 0;i < environment.size();i++)
	{
		if(environment[i]->isDestroyed()) 
		{
			remove(i);
			i--;
		}
	}
}

/**
 *	Will eventually generate a random environment everytime it 
 *	is called.  currently just creates and add's one default 
 *	object.
 */
void VirtualEnvironment::generateEnv(const unsigned int &_max_objects,const unsigned int &_max_dist)
{
	int num_objects = rand()%_max_objects;
	int object_id,x,y,z,theta;
	ObjectPtr obj;

	for(int i=0;i<num_objects;i++)
	{
		x=(rand()%(_max_dist*2))-_max_dist;
		y=0;
		z=(rand()%(_max_dist*2))-_max_dist;
		theta=rand()%360;
		object_id=rand()%render_list->size();
		obj = new Object(Pose::Pose(x,y,z,theta),10,object_id,false);
		add(obj);
	}
	//std::cout << "health: " << obj->getHealth() << std::endl;
}

/**
 *	returns the index of the object pointer in the environments
 *	vector of objects, -1 if object is not found.
 */
int VirtualEnvironment::findObject(ObjectPtr &_obj)
{
	if(_obj == NULL) return -1;
	for(unsigned int i = 0;i < environment.size();i++)
	{
		if(environment[i] == _obj) return i;
	}
	return -1;
}

/**
 *	returns the number of objects currently in the environment.
 */
int VirtualEnvironment::numObjects() const
{
	return environment.size();
}

/**
 *	BROKEN!! DOESNT WORK!
 *	attempts to fire the tank's gun and damage the first thing it hits.
 */
bool VirtualEnvironment::fire(TankPtr &_tank)
{
	assert(render_list != NULL);

	ObjectPtr tank = _tank;
	Pose temp_pose;
	ObjectPtr closest = NULL;
	double max_dist;
	for(unsigned int i=0;i<environment.size();i++)
	{
		if(environment[i]!=_tank)
		{
			temp_pose.setPoint(environment[i]->getPose().getX()-_tank->getPose().getX(),
				environment[i]->getPose().getY()-_tank->getPose().getY(),
				environment[i]->getPose().getZ()-_tank->getPose().getZ());
			//cout << "translated (" << temp_pose.getX() << "," << temp_pose.getY() << "," << temp_pose.getZ() << ")\n";

			temp_pose = translatePose(temp_pose,_tank->getPose().getTheta());
			max_dist = (*render_list)[environment[i]->getObjectID()].getMaxDistance();
			if(temp_pose.getZ()>=0 && temp_pose.getX()>=-max_dist && temp_pose.getX()<=max_dist)
			{
				if(closest != NULL && distanceBetween(tank,environment[i])<distanceBetween(closest,tank))
					closest = environment[i];
				if(closest == NULL) closest = environment[i];
			}
		}
	}
	//cout << "found " << front_objects.size() << " objects in front." << endl;
	return false;
}

/**
 *	Returns a vector of all objects within _radius units of passed object
 */
vector<ObjectPtr> VirtualEnvironment::findObjectsNear(ObjectPtr &_obj, const float &_radius)
{
	vector<ObjectPtr> near_objects;
	for(unsigned int i=0;i<environment.size();i++)
	{
		if(environment[i]!=_obj && distanceBetween(_obj,environment[i])<=_radius) near_objects.push_back(environment[i]);
	}
	//cout << "found " << near_objects.size() << " near objects." << endl;
	return near_objects;
}

/**
 *	Returns a Pose rotated about _degrees
 *
 *	rotates _pose to a new coordinate system _degree's offset from origin
 */
Pose VirtualEnvironment::translatePose(Pose _pose, const float &_degree)
{
	float x,y,z,theta;
	//cout << _degree << endl;
	x = ((float)cos(D2R(_degree))*_pose.getX()-(float)sin(D2R(_degree))*_pose.getZ());
	z = ((float)sin(D2R(_degree))*_pose.getX()+(float)cos(D2R(_degree))*_pose.getZ());
	theta = _pose.getTheta()+_degree;
	y = 0;
	if(x < .0001 && x > -.0001) x=0;
	if(z < .0001 && z > -.0001) z=0;
	return Pose::Pose(x,y,z,theta);
}

/**
 *	Returns the distance between the two passed object pointers.
 */
float VirtualEnvironment::distanceBetween(ObjectPtr &_obj1, ObjectPtr &_obj2)
{
	float delta_x = _obj1->getPose().getX()-_obj2->getPose().getX();
	float delta_z = _obj1->getPose().getZ()-_obj2->getPose().getZ();

	return sqrt((delta_x*delta_x)+(delta_z*delta_z));
}

/**
 *	Returns a pointer to the maintained Environment
 */
EnvironmentPtr VirtualEnvironment::getEnvironment()
{
	return &environment;
}