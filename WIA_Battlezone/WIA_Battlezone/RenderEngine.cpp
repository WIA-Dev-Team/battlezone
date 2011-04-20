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
 *	@file RenderEngine.cpp
 *	@headerfile RenderEngine.h "RenderEngine.h"
 *	@author Ben Hubler
 *	@date 4/19/2011
 *	@version 1.0.1
 */
#include <Windows.h>
#include "RenderEngine.h"
#include "xmlParser\tinystr.h"
#include "xmlParser\tinyxml.h"
#include "point3d.h"

const float PI=3.14159265;
/**
 *	Default constructor
 */
RenderEngine::RenderEngine(int _argc, char* _argv[])
{
	currentx = 0.0;
	currentz = 0.0;
	currangle.setXY(1,0);
	window = new CS325Graphics(_argc, _argv);
	window->SetViewDirection(currangle);
	window->SetViewPosition(Point2D(currentx, currentz));
	renderobjects.clear();
}

RenderEngine::RenderEngine(int _argc, char* _argv[], string _renderobjectfile)
{
	currentx = 0.0;
	currentz = 0.0;
	currangle.setXY(1,0); 
	window = new CS325Graphics(_argc, _argv);
	initRenderEngine(_renderobjectfile);
	window->SetViewDirection(Vector2D(1,0));
	window->SetViewPosition(Point2D(currentx, currentz));
}

RenderEngine::~RenderEngine()
{
	delete window;
	//add code to properly delete renderobjects vector of pointers
}
void RenderEngine::initRenderEngine(string _renderobjectfile)
{
	TiXmlElement *rootxml;
	TiXmlElement *objectxml;
	TiXmlElement *linexml;
	TiXmlElement *pointxml;
	int *objectid = new int();
	int *x = new int();
	int *y = new int();
	int *z = new int();
	double *maxdist = new double();

	TiXmlDocument renderobjectsxml(_renderobjectfile.c_str());
	renderobjectsxml.LoadFile();
	rootxml = renderobjectsxml.RootElement();
	objectxml = rootxml->FirstChildElement("object");
	
	while(objectxml != 0)
	{
		objectxml->Attribute("id", objectid);
		objectxml->Attribute("maxdist", maxdist);
		RenderObject *renderobject = new RenderObject(*objectid, *maxdist);
		linexml = objectxml->FirstChildElement("line");
		while(linexml != 0)
		{
			pointxml = linexml->FirstChildElement("point");
			pointxml->Attribute("x",x);
			pointxml->Attribute("y",y);
			pointxml->Attribute("z",z);
			renderobject->addPoint(Point(float(*x),float(*y),float(*z)));
			pointxml = pointxml->NextSiblingElement();
			pointxml->Attribute("x",x);
			pointxml->Attribute("y",y);
			pointxml->Attribute("z",z);
			renderobject->addPoint(Point(float(*x),float(*y),float(*z)));
			linexml = linexml->NextSiblingElement("line");
		}
		renderobjects.push_back(*renderobject);
		objectxml = objectxml->NextSiblingElement("object");
	}
	delete objectid;
	delete x;
	delete y;
	delete z;
}

void RenderEngine::drawobject(int _objectid, Pose _position)
{
	vector<RenderObject>::iterator iter;
	list<Point>::iterator piter;
	Point3D point1;
	Point3D point2;
	iter = renderobjects.begin();
	while(iter != renderobjects.end())
	{
		if(iter->getObjectID() == _objectid)
		{
			piter = iter->getPointsBegin();
			while(piter != iter->getPointsEnd())
			{
				point1.setXYZ(piter->getX() + _position.getX(), 
					piter->getY() - _position.getY(),
					piter->getZ() - _position.getZ());
				piter++;
				point2.setXYZ(piter->getX() + _position.getX(), 
					piter->getY() - _position.getY(),
					piter->getZ() - _position.getZ());
				window->DrawLineInSpace(point1,point2);
				piter++;
			}
		}
		iter++;
	}
}

void RenderEngine::draw()
{
	bool run = true;
	// Rotation testing
	float delta = .1 * PI / 180;
	//for(int i = 0; i < 450; i++)
	while(run)
	{
		window->DrawLineInSpace(Point3D(0,-1,0),Point3D(1,-1,0));
		drawobject(1, Pose(100, 0, 80, 0));
		drawobject(2, Pose(120, 0, 100, 0));
		drawobject(1, Pose(80, 0, 100, 0));
		drawobject(2, Pose(100, 0, 100, 0));
		window->SetViewDirection(currangle);
		currangle.setAngle(currangle.getAngle() + delta);
		cout << currangle.getAngle() * 180 / PI << endl;
		window->DisplayNow();
		Sleep(5);
		if(GetAsyncKeyState(0x51) & 0x8000)
			run = false;
	}

	 
	float speed = .5;
	currangle.setXY(1,1);
	for(int i = 0; i < 400; i++)
	{
		cout << currangle.getAngle() * 180 / PI << endl;
		currentz = currentz + speed * currangle.getY();
		window->SetViewPosition(Point2D(currentx, currentz));
		drawobject(1, Pose(100, 0, 80, 0));
		drawobject(2, Pose(120, 0, 100, 0));
		drawobject(1, Pose(80, 0, 100, 0));
		drawobject(2, Pose(100, 0, 100, 0));
		window->DisplayNow();
		cout << currentz << endl;
		Sleep(25);
	}
		
	Sleep(10000);
}