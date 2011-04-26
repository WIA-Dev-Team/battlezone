//
/* file: CS325GraphicsDriver.cpp
/* author: djbouvier
/* date: 12 April 2011 
 */

#include <iostream>
#include <Windows.h>
#include "vector3D.h"
#include "cs325graphics.h"
#include "Pose.h"
#include "Object.h"
#include "RenderObject.h"
#include <list>
#include "Tank.h"
#include "RenderEngine.h"
#include "UserInput.h"
#include "Game.h"

#define SCREEN_TEST 100
#define ROTATE_TEST 100
#define MOVE_TEST 100

//const string RENDERTYPEXML="RenderTypes.xml";
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
			if(char(*uikeyiter) == UserInputKey::ENTER_KEY)
			{
				//Do game stuff
				cout << "Run Game Stuff" << endl;
				game.startGame();
			}
			uikeyiter++;
		}
	}
	return (0);
}

