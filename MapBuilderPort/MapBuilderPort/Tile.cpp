
#include "Tile.h"


Tile::Tile()
{
	
}

void Tile::setTileSize(int size)
{
	setSourceRect(0, 0, 16, 16);
	setDestRect(DestRect->x,DestRect->y,size,size);
	tileSize = size;
}

int Tile::getTileWidth()
{
	return DestRect->w;
}

int Tile::getTileHeight()
{
	return DestRect->y;
}

void Tile::setTileCoordinates(int x, int y)
{
	DestRect->x = x;
	DestRect->y = y;
}

void Tile::setTile( int new_tileType)
{
	tileType = new_tileType;
}

Tile::~Tile()
{
}
