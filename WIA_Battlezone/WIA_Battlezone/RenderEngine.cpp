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
 *	@author Ben Hubler
 *	@date 4/16/2011
 *	@version 1.0
 */

#include "RenderEngine.h"
#include "RenderType.h"
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
	scalefactor = 200;
}

RenderEngine::RenderEngine(int _argc, char* _argv[], string _renderobjectfile, int _scalefactor)
{
	currentx = 0.0;
	currentz = 0.0;
	currangle.setXY(1,0); 
	window = new CS325Graphics(_argc, _argv);
	resetRenderEngine(_renderobjectfile);
	window->SetViewDirection(Vector2D(1,0));
	window->SetViewPosition(Point2D(currentx, currentz));
	scalefactor = _scalefactor;
}

RenderEngine::~RenderEngine()
{
	delete window;
	//add code to properly delete renderobjects vector of pointers
}
void RenderEngine::resetRenderEngine(string _renderobjectfile)
{
	TiXmlElement *rootxml;
	TiXmlElement *objectxml;
	TiXmlElement *linexml;
	TiXmlElement *pointxml;
	int *objectid = new int();
	int *x = new int();
	int *y = new int();
	int *z = new int();

	TiXmlDocument renderobjectsxml(_renderobjectfile.c_str());
	renderobjectsxml.LoadFile();
	rootxml = renderobjectsxml.RootElement();
	objectxml = rootxml->FirstChildElement("object");
	
	while(objectxml != 0)
	{
		objectxml->Attribute("id",objectid);
		RenderType *renderobject = new RenderType(*objectid);
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
	vector<RenderType>::iterator iter;
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
				point1.setXYZ((piter->getX() / scalefactor) + _position.getX() / scalefactor, 
					(piter->getY() / scalefactor) - _position.getY() / scalefactor,
					(piter->getZ() / scalefactor) - _position.getZ() / scalefactor);
				piter++;
				point2.setXYZ((piter->getX() / scalefactor) + _position.getX() / scalefactor, 
					(piter->getY() / scalefactor) - _position.getY() / scalefactor, 
					(piter->getZ() / scalefactor) - _position.getZ() / scalefactor);
				window->DrawLineInSpace(point1,point2);
				piter++;
			}
		}
		iter++;
	}
}

void RenderEngine::draw()
{
	// Rotation testing
	float delta = .1 * PI / 180;
	for(int i = 0; i < 3600; i++)
	{
		window->DrawLineInSpace(Point3D(0,-1,0),Point3D(1,-1,0));
		drawobject(1, Pose(100, 20, -100, 0));
		drawobject(2, Pose(-100, 20, -100, 0));
		drawobject(1, Pose(-100, 20, 100, 0));
		drawobject(2, Pose(100, 20, 100, 0));
		window->SetViewDirection(currangle);
		currangle.setAngle(currangle.getAngle() + delta);
		cout << currangle.getAngle() * 180 / PI << endl;
		window->DisplayNow();
		Sleep(5);
	}

	// 
	//float speed = .5;
	//currangle.setXY(1,1);
	//for(int i = 0; i < 200; i++)
	//{
	//	cout << currangle.getAngle() * 180 / PI << endl;
	//	currentx = currentx + speed * currangle.getX() / scalefactor;
	//	currentz = currentz + speed * currangle.getY() / scalefactor;
	//	window->SetViewPosition(Point2D(currentx, currentz));
	//	drawobject(1, Pose(100, 0, -100, 0));
	//	drawobject(2, Pose(-100, 0, -100, 0));
	//	drawobject(1, Pose(-100, 0, 100, 0));
	//	drawobject(2, Pose(100, 0, 100, 0));
	//	window->DisplayNow();
	//	Sleep(25);
	//}
		
	Sleep(10000);
}