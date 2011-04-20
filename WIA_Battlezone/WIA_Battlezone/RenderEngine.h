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

#ifndef RENDERENGINE_H
#define RENDERENGINE_H

/**	
 *	@file RenderEngine.h
 */
#include <windows.h>
#include <vector>
#include <string>
#include "RenderObject.h"
#include "Object.h"
#include "cs325graphics.h"

using namespace std;

/** 
 *	A class that is used as a wrapper to render view in battlezone game
 *	@author Ben Hubler
 *	@date 4/19/2011
 *	@version 1.0.1
 */
class RenderEngine
{
public:
	RenderEngine(int _argc, char* _argv[]);
	RenderEngine(int _argc, char* _argv[], string _renderobjectfile);
	~RenderEngine();
	void addRenderObject(RenderObject _renderobject);
	void initRenderEngine(string _renderobjectfile);
	void drawobject(int _objectid, Pose _position);
	void draw();
private:
	vector<RenderObject> renderobjects;
	CS325Graphics *window;
	float currentx;
	float currentz;
	Vector2D currangle;
};

#endif