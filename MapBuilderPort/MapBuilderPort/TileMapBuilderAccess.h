#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "ResourceManager.h"
#include "MapBuilder.h"
#include "FileManager.h"
#include "InputManager.h"

class TileMapBuilderAccess
{
public:
	TileMapBuilderAccess();
	~TileMapBuilderAccess();

	enum GameModes
	{
		MainMenu,
		MapEditor,
		Game
	};
	bool active = true;
	int SCREEN_WIDTH = 650;
	int SCREEN_HEIGHT = 650;

	//EDITOR WIDNOW
	SDL_Window * gWindow = NULL;
	SDL_Surface * gScreenSurface = NULL;
	SDL_Renderer * gRenderer = NULL;
	SDL_Surface * loadSurface();

	bool init();
	void close();
	void refresh();
	void zoomIn();
	void zoomOut();
	void switchTilePlusVert();
	void switchTilePlus();
	void switchTileMinus();
	void switchTileMinusVert();
	void editorInputManagement();
	void multiViewport();
	void startMapBuilder();
	void checkForUpdate();
	void changeMaps();

};

