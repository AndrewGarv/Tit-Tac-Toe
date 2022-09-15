/********************************************//**
 *  Textures
 * This class is responsible for managing each texture within the program. It contains the "render" method which is one of the most used methods in the entire program.
 * Every image in the game will have a corresponding texture object made for it.
 ***********************************************/
#pragma once
#ifndef TEXTURES_H
#define TEXTURES_H
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "GameFlow.h"
class Textures
{
public:
	Textures();//Constructor 
	bool loadTex(std::string filename, const GameFlow& OBJ);
	void Colourset(Uint8 r, Uint8 g, Uint8 b);
	void BlenderSet(SDL_BlendMode blend);
	void AlphaSet(Uint8 alphaType);
	void render(const GameFlow& OBJ, int x, int y, SDL_Rect* cut = NULL, double angle = 0.0, SDL_Point* centre = NULL, SDL_RendererFlip flipType = SDL_FLIP_NONE);
	void killTexture();
	~Textures();//Destructor

private:
	int TextureWidth;//Width of the texture
	int TextureHeight;//Height of the texture
	SDL_Texture* HardwareTexture;
};


#endif