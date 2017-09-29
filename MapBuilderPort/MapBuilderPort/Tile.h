#pragma once
#include "GameObject.h"
class Tile:public GameObject
{
public:
	Tile();
	~Tile();
	int tileSize;
	void setTileSize(int size);
	ObjectType getType()
	{
		return  TILE;
	}
	int tileType;
	int getTileWidth();
	int getTileHeight();
	void setTileCoordinates(int x,int y);
	//void OnCollision(GameObject * other){}
	void setTile(int setTile);
	
};

