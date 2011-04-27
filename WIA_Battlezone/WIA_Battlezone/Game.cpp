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
 *	@file Game.cpp
 *	@headerfile Game.h "Game.h"
 *	@author Justin Barnard
 *	@author Ben Hubler
 *	@date 4/26/2011
 *	@version 1.0.2
 */

#include "Game.h"

/**
 *	Default constructor
 */
Game::Game():virtualEnvironment(),renderEngine(),player()
{
	renderobjects.clear();
}

/**
 * Start Game Method intialize components
 */
void Game::startGame()
{
	Tank *_tank;
	_tank = player.getTank();

	// init renderobjects vector with xml file
	renderEngine.initRenderObjects(&renderobjects, RENDERTYPEXML);
	virtualEnvironment.init(_tank, &renderobjects);
	renderEngine.drawobjects(virtualEnvironment.getEnvironment(),renderobjects);
	renderEngine.draw();
};

/** 
 *	Function to return bool if player can fire
 *	@return a bool if player can fire
 */
bool Game::RequestFire()
{

 player.canFire();
 // this must be changed.
 return true;

}

/** 
 *	Function to move player tank
 *	@param _speed is a float representing the distance the tank will move forward during this cycle
 */
void Game::moveTank(float _speed)
{
	//if(virtualEnvironment.move(_speed))
	{
		renderEngine.move(_speed);
	}
}

/**
 *	Function to rotate player tank
 *	@param _degree is a float representing the amount in degrees a tank will rotate during this cycle
 */
void Game::rotateTank(float _degrees)
{
	//if(virtualEnvironment.move(_degrees))
	{
		renderEngine.rotate(_degrees);
	}
}

/**
 *	Function to refresh the game window
 */
void Game::RenderEnvironment()
{
	Tank *_tank;
	_tank = player.getTank();
	renderEngine.drawobjects(virtualEnvironment.getEnvironment(),renderobjects);
	renderEngine.draw();
}