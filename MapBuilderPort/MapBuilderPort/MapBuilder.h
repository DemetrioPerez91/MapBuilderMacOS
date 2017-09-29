#pragma once
#include "Tile.h"
#include "FileManager.h"
class MapBuilder
{
public:
	MapBuilder();
	~MapBuilder();
	//Variables
	static SDL_Renderer * gRenderer;
	static void setRenderer(SDL_Renderer * renderer);
	static SDL_Texture * getTileTexture(int i);
	static Tile * TILES;
	static int atlasW;
	static int atlasH;
	static int atlasY;
	static int atlasX;
	static unsigned int nCollums;
	static unsigned int nTiles;
	static int currentTile;


	//Methods
	static void swapMap();
	static void switchTileUp();
	static void switchTileDown();
	static void drawBaseMap();
	static void loadMap();
	static void drawMap();	
	static unsigned int tileSize;	
	static void increaseTileSize();
	static void decreaseTileSize();
	static void refreshMap();
	static void	paintSquare(int x,int  y);
	static int findCoordinate(int x);
	static int findPosition(int x, int y);
	static void switchTileFwd();
	static void switchTileBck();
	static void saveMap();


};


