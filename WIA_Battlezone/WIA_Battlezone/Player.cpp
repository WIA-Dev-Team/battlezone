/*	This file is part of WIA Battlezone.
 *
 *	WIA Battlezone is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	 WIA Battlezone is distributed in the hope that it will be useful,
 *	but lWITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with WIA Battlezone.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 *	@file Player.cpp
 *	@headerfile Player.h "Player.h"
 *	@author Justin Barnard
 *	@author Ben Hubler
 *	@date 4/26/2011
 *	@version 1.0.1
 */
#include "Player.h"

/**
 * Default Constructor
 * sets lives to 3 and score to zero
 */
Player::Player():tank()
{
	lives = 3;
	score = 0;	
};

/**
 *	Function to determine if tank is ready to fire
 *	@return a bool indicating if tank can fire
 */
bool Player::canFire()
{
	tank.canFire();
	// this must be changed
	return true;
};

/**
 *	Function to return a pointer to the tank
 *	@return a pointer to a tank
 */
Tank *Player::getTank()
{
	return &tank;
}

/**
 *	Function to return a pointer to the tanks position
 *	@return a pointer to the tanks pose
 */
Pose *Player::getPose()
{
	return &tank.getPose();
}