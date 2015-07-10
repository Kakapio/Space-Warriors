/*
* File:   main.cpp
* Author: Roshan Patel
*
* Created on April 16, 2015, 9:36 PM
*/

#include "Game.h"
#include <cstdlib>
#include <stdio.h>

int main(int argc, char** argv)
{
	Game game;
	game.Init();
	game.Run();
	return 0;
}