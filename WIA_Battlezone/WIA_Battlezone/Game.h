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
 *	@file Game.h
 */
#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "RenderEngine.h"
#include "VirtualEnvironment.h"
#include "RenderObject.h"
#include "UserInput.h"

const string RENDERTYPEXML="RenderTypes.xml";

/**
 *	A class used to control all functionality of the battlezone game.
 *	@author Justin Barnard
 *	@author Ben Hubler
 *	@date 4/26/2011
 *	@version 1.0.2
 */
class Game
{
public:
	Game();
	void startGame();
	void RenderEnvironment();
	bool RequestFire();
	void moveTank(float _speed);
	void rotateTank(float _degrees);

private:
	VirtualEnvironment virtualEnvironment;
	RenderEngine renderEngine;
	Player player;
	vector<RenderObject> renderobjects;
};
#endif
