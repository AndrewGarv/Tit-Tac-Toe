#include "Textures.h"
#include <string>
/********************************************//**
 *  Textures::Textures()
 * A self explanatory constructor. It sets the height and width to 0. Since a texture requires a rendered that will be created
 * elsewhere, this constructor will just set the texture to NULL
 ***********************************************/
Textures::Textures()
{
	TextureHeight = 0;
	TextureWidth = 0;
	HardwareTexture = NULL;//We need a bit more to actually create a texture so the constructor will just set it to null
}
/********************************************//**
 *  Textures::loadTex(std::string filename, const GameFlow &OBJ)
 * This function essentially creates the texture. It takes in a filename and a GameFlow object.
 * This function obtains the filename for the image we will be using and then uses IM_Load to place that image onto a surface. Once the surface
 * has been made we define what colour will be transparent with SetColorKey. In this case it will be the colour white. With all that done, we can finally create the
 * texture with CreateTextureFromSruface. We'll be using the renderer defined by the GameFlow object.
 * Once the texture has been made we set the texture variables TextureHeight and TextureWidth to match the size of the texture.
 * This is technically an optional step as we can always figure out the dimensions simply through "Texture->w" and so forth but it is good to keep
 * them in a somewhat permanent place.
 * With the texture made, HardwareTexture is set to the temporary texture we have been using thus far and any useless variables are deleted
 ***********************************************/
bool Textures::loadTex(std::string filename, const GameFlow& OBJ)
{
	SDL_Texture* finalTexture = NULL;
	SDL_Surface* finalSruface = IMG_Load(filename.c_str());
	if (finalSruface == NULL)
	{
		printf("Error 1");//Fill this in with an actual error message
	}
	else
	{
		SDL_SetColorKey(finalSruface, SDL_TRUE, SDL_MapRGB(finalSruface->format, 0, 0xFF, 0xFF));
		finalTexture = SDL_CreateTextureFromSurface(OBJ.mainRender, finalSruface);
		if (finalTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", filename.c_str(), SDL_GetError());
		}
		else
		{
			TextureHeight = finalSruface->h;
			TextureWidth = finalSruface->w;
		}
		HardwareTexture = finalTexture;
		SDL_FreeSurface(finalSruface);
		return HardwareTexture != NULL;//Remember that this function doesn't do the actual cutting. Basically it just loads a sprite sheet
	}

}
/********************************************//**
 *  Textures::Colourset
 * A simple method that just alters the colour of the texture. Will probably see little to no use in this project.
 ***********************************************/

void Textures::Colourset(Uint8 r, Uint8 g, Uint8 b)
{
	SDL_SetTextureColorMod(HardwareTexture, r, g, b);
}
/********************************************//**
 *  Textures::BlenderSet
 * A simple method that just turns on Alpha blending
 ***********************************************/
void Textures::BlenderSet(SDL_BlendMode blend)
{
	SDL_SetTextureBlendMode(HardwareTexture, blend);
}
/********************************************//**
 *  Textures::AlphaSet
 * A simple method that turns on the alpha, allowing for transparent like textures
 ***********************************************/
void Textures::AlphaSet(Uint8 alphatype)
{
	SDL_SetTextureAlphaMod(HardwareTexture, alphatype);
}
/********************************************//**
 *  Textures::render(const GameFlow& OBJ, int x, int y, SDL_Rect* cut, double angle, SDL_Point* centre, SDL_RendererFlip flipType)
 * A very important method. This renders whatever texture has been given to it onto the screen. There are several optional values that will alter the angle and orientation of the
 * texture. cut is technically optional however since I am uploading entire sprite sheets, it is mandatory to only use the cuts that are needed.
 ***********************************************/
void Textures::render(const GameFlow& OBJ, int x, int y, SDL_Rect* cut, double angle, SDL_Point* centre, SDL_RendererFlip flipType)
{
	SDL_Rect RenderSpace = { x, y, TextureWidth, TextureHeight };
	if (cut != NULL)//This function may take in a Srptie object and use something like Brynild as the cut instead of the cut I have up here now
	{
		RenderSpace.w = cut->w;
		RenderSpace.h = cut->h;
	}
	SDL_RenderCopyEx(OBJ.mainRender, HardwareTexture, cut, &RenderSpace, angle, centre, flipType);
}
/********************************************//**
 *  Textures::killTexture()
 * Not quite a destructor method but acts like one. This deallocates the texture when it is no longer in use. For enemies this would trigger whenever their HP runs out
 * It also resets the height and width to 0
 ***********************************************/
void Textures::killTexture()
{
	if (HardwareTexture != NULL)
	{
		SDL_DestroyTexture(HardwareTexture);
		HardwareTexture = NULL;
		TextureHeight = 0;
		TextureWidth = 0;
	}
}
/********************************************//**
 *  Textures::~Textures()
 * Destructor method
 ***********************************************/
Textures::~Textures()
{
	killTexture();
}
