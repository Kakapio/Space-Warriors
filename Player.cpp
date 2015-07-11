/* 
 * File:   Player.cpp
 * Author: Roshan Patel
 * 
 * Created on April 18, 2015, 6:37 PM
 */

#include "Player.h"
#include <SDL.h>

Player::Player() 
{
    score = 0;
    posX = 0;
    posY = 0;
    moveSpeed = 1;
    shield = 0;
    hyperLaserTime = 0;
    ship = NULL;
    
    arrowKeys [SHIP_UP] = false;
    arrowKeys [SHIP_DOWN] = false;
    arrowKeys [SHIP_LEFT] = false;
    arrowKeys [SHIP_RIGHT] = false;
}

int Player::Init()
{
    ship = SDL_LoadBMP ("data/images/playerShip.bmp");
    
    if (ship == NULL)
    {
        return -1;
    }
}

int Player::Render(SDL_Surface* dest)
{
    Update();
    SDL_Rect rect;
    rect.x = posX;
    rect.y = posY;
    SDL_BlitSurface( ship, NULL, dest, &rect);
    return 0;
}

void Player::ShipHandle(SDL_Event* event) 
{/*
  * if the key is up, subtract from y.
  * if the key is down, add to y.
  * if the key is right, add to x.
  * if the key is left, subtract from x.
  */
    if (event->type == SDL_KEYDOWN || event->type == SDL_KEYUP)
    {
        if (event->key.keysym.sym == SDLK_w || event->key.keysym.sym == SDLK_UP)
        {
            arrowKeys[SHIP_UP] = event->key.state == SDL_PRESSED;
        }
        
        if (event->key.keysym.sym == SDLK_s || event->key.keysym.sym == SDLK_DOWN)
        {
            arrowKeys[SHIP_DOWN] = event->key.state == SDL_PRESSED;
        }
        
        if (event->key.keysym.sym == SDLK_a || event->key.keysym.sym == SDLK_LEFT)
        {
            arrowKeys[SHIP_LEFT] = event->key.state == SDL_PRESSED;
        }
        
        if (event->key.keysym.sym == SDLK_d || event->key.keysym.sym == SDLK_RIGHT)
        {
            arrowKeys[SHIP_RIGHT] = event->key.state == SDL_PRESSED;
        }
    }
}

int Player::Update()
{
    if (arrowKeys[SHIP_UP])
    {
        posY -= moveSpeed;
    }
    
    if (arrowKeys[SHIP_DOWN])
    {
        posY += moveSpeed;
    }
    
    if (arrowKeys[SHIP_LEFT])
    {
        posX -= moveSpeed;
    }
    
    if (arrowKeys[SHIP_RIGHT])
    {
        posX += moveSpeed;
    }
    
    if (posX > 781)
    {
        posX = 781;
    }
    
    if (posX < 0)
    {
        posX = 0;
    }
    
    if (posY > 573)
    {
        posY = 573;
    }
    
    if (posY < 0)
    {
        posY = 0;
    }
}

Player::Player(const Player& orig) 
{
}

Player::~Player() 
{
    SDL_FreeSurface(ship);
}

