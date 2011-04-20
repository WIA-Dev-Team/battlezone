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
 *	attempts to move the passed tank to the passed pose. 
 *	returns false if failed.
 */
bool VirtualEnvironment::move(TankPtr &_tank, Pose &_pose)
{
	return false;
}

/**
 *	fires the passed tank's gun, detects if it hits an object
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
 *	Create's a deep copy of passed object.
 */
void VirtualEnvironment::add(Object &_obj)
{
	ObjectPtr obj = new Object(_obj);
	environment.push_back(obj);
}

/**
 *	Find's the object in the environment, remvoes from vector,
 *	and deletes the object itself. Given a pointer to an object.
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
 *	Find's the object in the environment, remvoes from vector,
 *	and deletes the object itself. Given the index of the object
 *	in the vector. This is cheaper than passing the pointer 
 *	to the object.
 */
void VirtualEnvironment::remove(const int &_object_index)
{
	if(_object_index >= environment.size() || _object_index < 0) return;
	delete environment[_object_index];
	environment.erase(environment.begin()+_object_index);
}

/**
 *	parses through the environment vector and removes all 
 *	destroyed objects
 */
void VirtualEnvironment::prune()
{
	for(int i = 0;i < environment.size();i++)
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
	//obj->setHealth(5);
	add(obj);
	//std::cout << "health: " << obj->getHealth() << std::endl;
}

/**
 *	returns the index of the object pointer in the environments
 *	vector of objects, -1 if object not found.
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