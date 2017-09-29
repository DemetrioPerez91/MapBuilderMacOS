#ifndef RESOURCE_MANAGER
#define RESOURCE_MANAGER
#pragma once
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include <string>

class ResourceManager
{

public:
	ResourceManager();
	~ResourceManager();

	//Variables
	const static int n_backgrounds=2;
	const static int n_sprites=45;
	static SDL_Texture * TILES[n_sprites];
	static SDL_Renderer * renderer;
	static SDL_Texture * atlas;
	static SDL_Texture * MainMenu;
	static int atlasW;
	static int atlasH;
	static int atlasSprites;
	static int atlasCollumns;
	static int atlasLines;
	static std::string atlasURL;
	static int nTiles;
	static std::string MainMenuUrl;
	//Methods
	static void startUpTileTextures();
	static SDL_Texture * getSprite(int index);
	static SDL_Texture * loadTexture(std::string url);
	static SDL_Texture * getAtlas();
	static void setRenderer(SDL_Renderer * iRenderer);
	static void loadTextures();
	static void loadAtlas();

};
#endif



