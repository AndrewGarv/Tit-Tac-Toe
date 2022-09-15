#include "Tile.h"
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>

Tile::Tile()
{
	tileDec = N;
}

Tile::Tile(const GameFlow& OBJ)
{
	posX = 0;
	posY = 0;
	blank.loadTex("EmptyBlock.png", OBJ);
	Ex.loadTex("XBlock.png", OBJ);
	Oh.loadTex("OBlock.png", OBJ);
}

Tile::Tile(const GameFlow& OBJ, int x, int y)
{
	posX = x;
	posY = y;
	blank.loadTex("EmptyBlock.png", OBJ);
	Ex.loadTex("XBlock.png", OBJ);
	Oh.loadTex("OBlock.png", OBJ);
	tileDec = N;
}

void Tile::InputHandle(SDL_Event& e, bool controller)
{
	if (controller == false)
	{
		tileDec = O;//This is so when the render method is called it knows what to render. I prefer to use a Switch case
		
		return;
	}
	if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		bool inside = true;
		if (x < posX)
		{
			inside = false;
		}
		else if (x > posX + TileW)
		{
			inside = false;
		}
		else if (y < posY)
		{
			inside = false;
		}
		else if (y > posY + TileH)
		{
			inside = false;
		}

		if (inside)
		{
			switch (e.type)
			{
			case SDL_MOUSEBUTTONDOWN:
				score(controller);
				if (controller == true)
				{
					tileDec = X;//TODO: Try and remember why the hell you did this. DONE! This is for the render method
					
				}
				break;
			}
		}
	}
}

void Tile::score(bool controller)//Remember that the actual AI and winner determining will happen in Source.
{
	if (controller == true)
	{
		tileState = 0;
	}
	else
	{
		tileState = 1;
	}
}



void Tile::render(const GameFlow& OBJ)
{
	switch (tileDec)
	{
	case X:  Ex.render(OBJ, posX, posY); SDL_RenderPresent(OBJ.mainRender); break;
	case O:  Oh.render(OBJ, posX, posY); SDL_RenderPresent(OBJ.mainRender); break;
	case N:  blank.render(OBJ, posX, posY); SDL_RenderPresent(OBJ.mainRender); break;
	}
}

Tile::~Tile()
{
	blank.killTexture();
}