/*Project: Tic Tac Toe
Written by: Ki-jana "Andrew-Marquise" Garvey
Last Modified: September 15th 2022

Description: A tic tac toe program. 
.*/


#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <random>
#include <ctime>
#include <iostream>
#include "GameFlow.h"
#include "Textures.h"
#include "Tile.h"
using namespace std;
//Screen dimension constants
const int SCREEN_WIDTH = 884;
const int SCREEN_HEIGHT = 589;
int aiba;

SDL_Event e;
Tile bi[3][3];
enum GameState { Begin, Exit, Hard, Score };

GameState Title(GameFlow tester)//TODO: Resize where the logo shows up. YOU DID IT! Now change the resolution to something better
{
	printf("Reached here");
	Textures Logo;
	Logo.loadTex("LogoScreen.png", tester);
	GameState option;
	SDL_Event e;
	bool next = false;
	SDL_SetRenderDrawColor(tester.mainRender, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(tester.mainRender);
	Logo.render(tester, (0), (0));
	SDL_RenderPresent(tester.mainRender);
	while (!next)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			switch (e.type)
			{
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym)
				{
				case SDLK_UP: option = Begin; next = true; break;
				case SDLK_DOWN: option = Exit; next = true; break;
				}
			}
		}
		SDL_RenderClear(tester.mainRender);
	}
	Logo.killTexture();
	return option;
}

bool Winner()
{
	for (int i = 0; i < 3; i++)
	{
		if (bi[i][0].tileDec == bi[i][1].tileDec &&
			bi[i][1].tileDec == bi[i][2].tileDec &&
			bi[i][0].tileDec != 2)
		{
			return true;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (bi[0][i].tileDec == bi[1][i].tileDec &&
			bi[1][i].tileDec == bi[2][i].tileDec &&
			bi[0][i].tileDec != 2)
		{
			return true;
		}
	}

	if (bi[0][0].tileDec == bi[1][1].tileDec &&
		bi[1][1].tileDec == bi[2][2].tileDec &&
		bi[0][0].tileDec != 2)
	{
		return true;
	}

	if (bi[0][2].tileDec == bi[1][1].tileDec &&
		bi[1][1].tileDec == bi[2][0].tileDec &&
		bi[0][2].tileDec != 2)
	{
		return true;
	}

	return false;

}

void CoreGame(GameFlow tester)
{
	Tile board[]{ Tile(tester, 0, 0), Tile(tester, 340, 0), Tile(tester, 680, 0), Tile(tester, 0, 268), Tile(tester, 340, 268), Tile(tester, 680, 268), Tile(tester, 0, 535),
	 Tile(tester, 340, 535), Tile(tester, 680, 535) };
	bool next = false;
	bool state = true;
	int moves = 0;
	int temp1;
	int temp2;
	int iterator = 0;
	Textures EndScreen;
	Textures BadEnd;
	Textures DrawEnd;
	EndScreen.loadTex("GameOver.png", tester);
	BadEnd.loadTex("LoseScreen.png", tester);
	DrawEnd.loadTex("DrawScreen.png", tester);
	for (int col = 0; col < 3; col++)
	{
		for (int row = 0; row < 3; row++)
		{
			bi[row][col] = board[iterator];
			iterator++;
		}
	}
	SDL_SetRenderDrawColor(tester.mainRender, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(tester.mainRender);
	SDL_Event f;
	while (!next)
	{
		bi[0][0].render(tester);
		bi[0][1].render(tester);
		bi[0][2].render(tester);
		bi[1][0].render(tester);
		bi[1][1].render(tester);
		bi[1][2].render(tester);
		bi[2][0].render(tester);
		bi[2][1].render(tester);
		bi[2][2].render(tester);
		while (SDL_PollEvent(&f) != 0)
		{
			printf("Player is Deciding \n");
			switch (f.type)
			{
			case SDL_MOUSEBUTTONDOWN: bi[0][0].InputHandle(f, true); bi[0][1].InputHandle(f, true); bi[0][2].InputHandle(f, true);
				bi[1][0].InputHandle(f, true); bi[1][1].InputHandle(f, true); bi[1][2].InputHandle(f, true); 
				bi[2][0].InputHandle(f, true); bi[2][1].InputHandle(f, true); bi[2][2].InputHandle(f, true); state = false; moves++; break;
			}
		}
		if (state == false)
		{

			if (Winner() == true)
			{
				next = true;
				printf("GAME OVER");
				bi[0][0].render(tester);
				bi[0][1].render(tester);
				bi[0][2].render(tester);
				bi[1][0].render(tester);
				bi[1][1].render(tester);
				bi[1][2].render(tester);
				bi[2][0].render(tester);
				bi[2][1].render(tester);
				bi[2][2].render(tester);
				SDL_Delay(4000);
				SDL_RenderClear(tester.mainRender);
				EndScreen.render(tester, (0), (0));
				SDL_RenderPresent(tester.mainRender);
				SDL_Delay(4000);

				break;
			}
			state = true;
			do
			{
				printf("Computer is Deciding \n");
				srand((unsigned)time(0));
				int result1 = 0 + (rand() % 3);
				int result2 = 0 + (rand() % 3);
				temp1 = result1;
				temp2 = result2;
			} while (bi[temp1][temp2].tileDec != 2 && moves < 9);//This AI technically works but it can take an obnoxiously long time to do its move. Not satisfied with it but I'll get back to it
			bi[temp1][temp2].InputHandle(f, false);
			moves++;
			if (moves >= 9)
			{
				next = true;
				printf("DRAW GAME");
				bi[0][0].render(tester);
				bi[0][1].render(tester);
				bi[0][2].render(tester);
				bi[1][0].render(tester);
				bi[1][1].render(tester);
				bi[1][2].render(tester);
				bi[2][0].render(tester);
				bi[2][1].render(tester);
				bi[2][2].render(tester);
				SDL_Delay(4000);
				SDL_RenderClear(tester.mainRender);
				DrawEnd.render(tester, (0), (0));
				SDL_RenderPresent(tester.mainRender);
				SDL_Delay(4000);

				break;
			}
			if (Winner() == true)
			{
				next = true;
				printf("GAME OVER");
				bi[0][0].render(tester);
				bi[0][1].render(tester);
				bi[0][2].render(tester);
				bi[1][0].render(tester);
				bi[1][1].render(tester);
				bi[1][2].render(tester);
				bi[2][0].render(tester);
				bi[2][1].render(tester);
				bi[2][2].render(tester);
				SDL_Delay(4000);
				SDL_RenderClear(tester.mainRender);
				BadEnd.render(tester, (0), (0));
				SDL_RenderPresent(tester.mainRender);
				SDL_Delay(4000);
			}


			//Random Number generator
		}
		
	}

}

int main(int argc, char* args[])
{
	printf("Entry into program succesful\n");
	GameFlow game;
	if (game.init() == true)
	{
		printf("  SDL is ready ");
	}
	
	switch (Title(game))
	{
	case Begin:
		game.init(); CoreGame(game);
	}
	return 0;
}