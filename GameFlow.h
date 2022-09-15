/********************************************//**
 *  GmaeFlow
 * This class is responsible for creating and maintaining the SDL window that the game runs in. For the most pare there will only ever be one GameFlow object made at once.
 ***********************************************/
#pragma once
#ifndef GAMEFLOW_H
#define GAMEFLOW_H
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
class Textures;
extern int aiba;
class GameFlow
{
public:
	GameFlow();
	~GameFlow();
	bool init();
	SDL_Renderer* mainRender;
	SDL_Window* mainWindow;
	Textures* PlayerImage;
	int ScreenW = 1020;//The screens width and height is set for 1080p
	int ScreenH = 803;
};
#endif
