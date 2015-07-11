/* 
 * File:   Game.cpp
 * Author: Roshan Patel
 * 
 * Created on April 18, 2015, 2:07 PM
 */

#include "Game.h"
#include "Asteroid.h"

Game::Game() 
{
    win = NULL;
    screen = NULL;
}

int Game::Init()
{
    
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {//If video fails, send error.
        return -1;
    }

    win = SDL_CreateWindow ("Space Warriors",
    /*Make windows for game
     * 800x600 screen
     * Position = center
    */                      SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED,
                            800,600,
                            SDL_WINDOW_SHOWN);
    
    if (win == NULL)
    {
        return -1;
    }
    
    screen = SDL_GetWindowSurface(win);
    
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255) );
    
    if (playerShip.Init() == -1)
    {
        return -1;
    }

    Asteroid t;
    asteroids.push_back(t);
    
    if(asteroids[0].Init() == -1) 
    {
        return 1;
    }    
    return 0;
}

void Game::FPSLimit()
{
    static unsigned int lastTime = 0;
    const int fps = 60;
    unsigned int curTime = SDL_GetTicks();
    int delay = 1000/fps - (curTime - lastTime);
    lastTime = curTime;
    
    if(delay < 0) return;
    SDL_Delay(delay);
    
}

int Game::Run ()
{
    while (HandleEvents() == 0)
    {
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255) );
        
        for(int i = 0; i < asteroids.size(); ++i)
        {
            asteroids[i].Render(screen);
        }
        
        playerShip.Render(screen);
        SDL_UpdateWindowSurface(win);
        FPSLimit();
    }
    return 0;
}

int Game::HandleEvents()
{
    SDL_Event event; //The event we get from the queue
    
    while(SDL_PollEvent(&event))
    { //while we can still Poll for events, Poll the event.
        
        playerShip.ShipHandle(&event);
        
        if(event.type == SDL_QUIT)
        { //if the event is quit
            return -1; //return -1 (which is our "quit" signal)
        }
       
    }
    return 0; //no quit event? Okay, we tell it to continue.
}

Game::Game(const Game& orig) 
{
    //Can't use copy constructor
}

Game::~Game() 
{
    SDL_DestroyWindow(win);
    SDL_Quit();
}