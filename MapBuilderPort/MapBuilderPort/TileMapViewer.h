#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "ResourceManager.h"
#include "FileManager.h"
#include "InputManager.h"
class TileMapViewer
{
public:
	TileMapViewer();
	~TileMapViewer();
	//TILEMAP WINDOW
	SDL_Window * tileMapWindow = NULL;
	SDL_Surface * tileMapSurface = NULL;
	SDL_Texture * tileMapTexture = NULL;
	SDL_Renderer * tileMapRenderer = NULL;
	SDL_Rect * SrcRect = NULL;
	SDL_Rect * DestRect = NULL;
	bool init();
	void refresh();
	void switchMap();
};

