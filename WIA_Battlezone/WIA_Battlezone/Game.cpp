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
 *	@headerfile "Game.h"
 *	@author Justin Barnard
 *	@date 4/21/2011
 *	@version 1.0
 */

#include "Game.h"
/**
 * Start Game Method intialize components
 */
Game::Game():virtualEnvironment(),renderEngine(),player()
{
	renderobjects.clear();
}
void Game::startGame()
{
	//initplayer.
	Tank *_tank;
	_tank = player.getTank();

	// init renderobjects vector with xml file
	renderEngine.initRenderObjects(&renderobjects, RENDERTYPEXML);
	virtualEnvironment.init(_tank, &renderobjects);
	renderEngine.drawobjects(virtualEnvironment.getEnvironment(),renderobjects);
	renderEngine.draw();
	//virtualEnvironment = VirtualEnvironment();

	//renderEngine.initRenderEngine();



};
bool Game::RequestFire()
{

 player.canFire();
 // this must be changed.
 return true;

}