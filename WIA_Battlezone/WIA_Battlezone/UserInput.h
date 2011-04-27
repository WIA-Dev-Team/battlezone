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
 *	@file UserInput.h
 */

#ifndef USERINPUT_H
#define USERINPUT_H

#include <list>


/**
 *	@namespace UserInputKey
 *	This namespace is used to clarify the enum UserInputKey
 *	@author Ben Hubler
 *	@date 4/20/2011
 *	@version 1.0.0
 */
namespace UserInputKey
{
	enum UserInputKey
	{
		Q_KEY = 0x51,
		W_KEY = 0x57,
		S_KEY = 0x53,
		A_KEY = 0x41,
		D_KEY = 0x44,
		ENTER_KEY = 0x0D,
		SPACE_KEY = 0x20
	};
}

using namespace std;
/**
 *	A class that is used to retrieve asynchronous input from the user.
 *	@author Ben Hubler
 *	@date 4/20/2011
 *	@version 1.0.0
 */
class UserInput
{
public:
	UserInput();
	list<UserInputKey::UserInputKey>* getKeysDown();
	void updateKeysDown();
private:
	list<UserInputKey::UserInputKey> inputkeys;
	list<UserInputKey::UserInputKey> keysdown;
};

#endif