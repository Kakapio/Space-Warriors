/* 
 * File:   Game.h
 * Author: Roshan Patel
 *
 * Created on April 18, 2015, 2:07 PM
 */

#ifndef GAME_H
#define	GAME_H
#include <SDL2/SDL.h>
#include "Player.h"
#include <vector>
#include "Asteroid.h"

class Game {
public:
    Game();
    virtual ~Game();
    int Init();
    int Run();
private:
    Game(const Game& orig);
    SDL_Window* win;
    int HandleEvents();
    SDL_Surface* screen;
    Player playerShip;
    std::vector<Asteroid> asteroids;
    void FPSLimit();

};

#endif	/* GAME_H */

