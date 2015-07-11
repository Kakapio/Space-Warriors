/* 
 * File:   Asteroid.h
 * Author: Roshan Patel
 *
 * Created on May 25, 2015, 6:10 PM
 */

#ifndef ASTEROID_H
#define	ASTEROID_H
#include <SDL.h>
#include <vector>
#include <cstdio>

class Asteroid {
public:
    Asteroid();
    int Init();
    int Render(SDL_Surface* dest);
    Asteroid(const Asteroid& orig);
    int Update();
    virtual ~Asteroid();
private:
    int posX;
    int posY;
    SDL_Surface* asteroid;
};

#endif	/* ASTEROID_H */

