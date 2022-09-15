#pragma once
#include <string>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "GameFlow.h"
#include "Textures.h"
class Tile
{
public:
	int posX, posY;
	int tileState = 2;
	static const int TileW = 339;
	static const int TileH = 267;
	enum ExOh {X,O,N};
	ExOh tileDec;
	Textures blank;
	Textures Ex;
	Textures Oh;
	SDL_Point mPosition;
	Tile();
	Tile(const GameFlow& OBJ);
	Tile(const GameFlow& OBJ, int x, int y);
	void InputHandle(SDL_Event& e, bool controller);
	void score(bool controller);
	void render(const GameFlow& OBJ);//Consider having the render method alter the game logic array that determines winners
	~Tile();
};

