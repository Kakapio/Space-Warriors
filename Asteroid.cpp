/*
* File:   Asteroid.cpp
* Author: Roshan Patel
*
* Created on May 25, 2015, 6:10 PM
*/

#include "Asteroid.h"
#include <SDL2/SDL.h>

Asteroid::Asteroid()
{
	asteroid = NULL;
}

int Asteroid::Init()
{
	asteroid = SDL_LoadBMP("data/images/asteroid.bmp");
	posX = 50;
	posY = 50;

	if (asteroid == NULL)
	{
		printf("Asteroid didn't load!! \n");
		return -1;
	}
}

int Asteroid::Render(SDL_Surface* dest)
{
	Update();
	SDL_Rect rect;
	rect.x = posX;
	rect.y = posY;
	SDL_BlitSurface(asteroid, NULL, dest, &rect);
	return 0;
}

int Asteroid::Update()
{

}

Asteroid::Asteroid(const Asteroid& orig) {
}

Asteroid::~Asteroid()
{
	SDL_FreeSurface(asteroid);
}

