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
 *	@file UserInput.cpp
 *	@headerfile UserInput.h "UserInput.h"
 *	@author Ben Hubler
 *	@date 4/20/2011
 *	@version 1.0.1
 */
#include "UserInput.h"
#include <Windows.h>
/**
 *	Default constructor 
 *	Populates the inputkeys filed with all possible input keys
 */
UserInput::UserInput()
{
	inputkeys.push_back(UserInputKey::A_KEY);
	inputkeys.push_back(UserInputKey::D_KEY);
	inputkeys.push_back(UserInputKey::ENTER_KEY);
	inputkeys.push_back(UserInputKey::Q_KEY);
	inputkeys.push_back(UserInputKey::SPACE_KEY);
	inputkeys.push_back(UserInputKey::S_KEY);
	inputkeys.push_back(UserInputKey::W_KEY);
	keysdown.clear();
}

/**
 *	Function to update keysdown list of currently depressed keys
 */
void UserInput::updateKeysDown()
{
	keysdown.clear();
	if(GetAsyncKeyState(UserInputKey::A_KEY))
	{
		keysdown.push_front(UserInputKey::A_KEY);
	}
	if(GetAsyncKeyState(UserInputKey::D_KEY))
	{
		keysdown.push_front(UserInputKey::D_KEY);
	}
	if(GetAsyncKeyState(UserInputKey::ENTER_KEY))
	{
		keysdown.push_front(UserInputKey::ENTER_KEY);
	}
	if(GetAsyncKeyState(UserInputKey::Q_KEY))
	{
		keysdown.push_front(UserInputKey::Q_KEY);
	}
	if(GetAsyncKeyState(UserInputKey::SPACE_KEY))
	{
		keysdown.push_front(UserInputKey::SPACE_KEY);
	}
	if(GetAsyncKeyState(UserInputKey::S_KEY))
	{
		keysdown.push_front(UserInputKey::S_KEY);
	}
	if(GetAsyncKeyState(UserInputKey::W_KEY))
	{
		keysdown.push_front(UserInputKey::W_KEY);
	}

}

/**
 *	Function to return a pointer to the keysdown list
 *	@return a list of UserInputKey signifying they have been depressed
 */
list<UserInputKey::UserInputKey>* UserInput::getKeysDown()
{
	updateKeysDown();
	return &keysdown;
}