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
	generateEnv();
}

/**
 *	Copy constructor
 */
VirtualEnvironment::VirtualEnvironment(const VirtualEnvironment &env)
{
	environment = env.environment;
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
 *	Attempts to move the passed tank to the passed pose. 
 *	returns false if failed. 
 */
bool VirtualEnvironment::move(TankPtr &_tank, Pose &_pose)
{
	ObjectPtr obj = _tank;
	if(findObjectsNear(obj,1).size()) return false;
	return true;
}

/**
 *	Fires the passed tank's gun, detects if it hits an object
 */
bool VirtualEnvironment::fire(TankPtr &_tank)
{
	return false;
}

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
void VirtualEnvironment::generateEnv()
{
	//std::cout << "entered generateEnv" << std::endl;
	ObjectPtr obj = new Object;
	obj->setCoordinate(4,4,0);
	obj->setHealth(5);
	add(obj);
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
 *	Returns a vector of object pointers containing all objects in front of the passed object, currently only works at the origin
 */
vector<ObjectPtr> VirtualEnvironment::findObjectsInFrontOf(ObjectPtr &_obj)
{
	vector<ObjectPtr> front_objects;
	Pose temp_pose;
	for(unsigned int i=0;i<environment.size();i++)
	{
		if(environment[i]!=_obj)
		{
			temp_pose.setPoint(translatePose(environment[i]->getPose(),_obj->getPose().getTheta()));

			if(temp_pose.getY()>0) front_objects.push_back(environment[i]);
		}
	}
	return front_objects;
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
	cout << "found " << near_objects.size() << " near objects." << endl;
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
	x = ((float)cos(D2R(_degree))*_pose.getX()-(float)sin(D2R(_degree))*_pose.getY());
	y = ((float)sin(D2R(_degree))*_pose.getX()+(float)cos(D2R(_degree))*_pose.getY());
	theta = _pose.getTheta()+_degree;
	z = 0;
	if(x < .0001 && x > -.0001) x=0;
	if(y < .0001 && y > -.0001) y=0;
	return Pose::Pose(x,y,z,theta);
}

/**
 *	
 */
float VirtualEnvironment::distanceBetween(ObjectPtr &_obj1, ObjectPtr &_obj2)
{
	float delta_x = _obj1->getPose().getX()-_obj2->getPose().getX();
	float delta_y = _obj1->getPose().getY()-_obj2->getPose().getY();

	return sqrt((delta_x*delta_x)+(delta_y*delta_y));
}