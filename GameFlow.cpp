#include "GameFlow.h"
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

/********************************************//**
 *  GameFlow::GameFlow()
 * Constructor. Just sets the mindow and renderer to null. Nothing special
 ***********************************************/

GameFlow::GameFlow()
{
	mainRender = NULL;
	mainWindow = NULL;
}
/********************************************//**
 *  GameFlow::Init()
 * The initializer. The long short of this method is that it creates the window that SDL2 runs in. First it does some error checking, in particular it checks to make sure the Linear Scaling is set.
 * This program isn't designed for any other type of scaling so it has to be set to this. After the checks are done, the window called "Divine Bout" is created. It is made to fit a 1080p screen.
 * Once the window is made, the rendered is created. The renderer can either synched with the refresh rate or hardware. With that done, a default colour is given to the rendered and then one final check
 * is made to ensure PNG loading is possible
 ***********************************************/
bool GameFlow::init()
{
	bool flag = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Error in starting SDL");
		flag = false;
	}
	else
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Error in linear textures");
		}

		mainWindow = SDL_CreateWindow("Tic Tac Toe", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, ScreenW, ScreenH, SDL_WINDOW_SHOWN);
		if (mainWindow == NULL)
		{
			printf("Error in creating window");
			flag = false;
		}
		else
		{
			mainRender = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (mainRender == NULL)
			{
				printf("Error in creating renderer");
				flag = false;
			}
			else
			{
				SDL_SetRenderDrawColor(mainRender, 0xFF, 0xFF, 0xFF, 0xFF);
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("Sometihng went");//Think of a better error name 
					flag = false;
				}

			}
		}
	}
	return flag;
}
/********************************************//**
 *  GameFlow::~GameFlow()
 * Destructor. This would only be called when the game is exited.
 ***********************************************/

GameFlow::~GameFlow()
{
	SDL_DestroyRenderer(mainRender);
	SDL_DestroyWindow(mainWindow);
}