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
 *	@author Aarron Parker
 *	@author Justin Barnard
 *	@date 4/26/2011
 *	@version 1.0.1
 */
#include <iostream>
#include "UserInput.h"
#include "Game.h"

using namespace std;

int main(int argc, char* argv[])
{
	UserInput uikey;
	list<UserInputKey::UserInputKey>::iterator uikeyiter;
	list<UserInputKey::UserInputKey>::iterator uikeyend;
	list<UserInputKey::UserInputKey> *userinputkey;
	userinputkey = uikey.getKeysDown();
	uikeyiter = userinputkey->begin();
	uikeyend = userinputkey->end();
	Game game;
	game.startGame();

	bool gameloop = true;
	while(gameloop)
	{		
		uikey.updateKeysDown();
		uikeyiter = userinputkey->begin();
		uikeyend = userinputkey->end();
		while(uikeyiter != uikeyend)
		{
			if(char(*uikeyiter) == UserInputKey::Q_KEY)
			{
				gameloop = false;
			}
			if(char(*uikeyiter) == UserInputKey::A_KEY)
			{
				game.rotateTank(-0.1);
			}
			if(char(*uikeyiter) == UserInputKey::D_KEY)
			{
				game.rotateTank(0.1);
			}
			if(char(*uikeyiter) == UserInputKey::W_KEY)
			{
				game.moveTank(0.1);
			}
			if(char(*uikeyiter) == UserInputKey::S_KEY)
			{
				game.moveTank(-0.1);
			}
			game.RenderEnvironment();
			uikeyiter++;
		}
	}
	return (0);
}

