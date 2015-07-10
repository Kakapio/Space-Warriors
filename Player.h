/*
* File:   Player.h
* Author: Roshan Patel
*
* Created on April 18, 2015, 6:37 PM
*/

#ifndef PLAYER_H
#define	PLAYER_H

enum
{
	SHIP_UP = 0,
	SHIP_DOWN,
	SHIP_RIGHT,
	SHIP_LEFT
};

#include <SDL2/sdl.h>

class Player {
public:
	Player();
	virtual ~Player();
	int Init();
	int Render(SDL_Surface* dest);
	int MoveShip(int x, int y);
	int Shoot();
	void ShipHandle(SDL_Event*); //Allow ship to handle events
	int Update();
private:
	Player(const Player& orig);
	int score;
	int posX;
	int posY;
	int moveSpeed;
	unsigned char shield;
	unsigned char hyperLaserTime;
	SDL_Surface* ship;
	bool arrowKeys[4];
};

#endif	/* PLAYER_H */

