
#include "MapBuilder.h"
SDL_Renderer * MapBuilder::gRenderer = NULL;
Tile * MapBuilder::TILES=NULL;
unsigned int MapBuilder::nTiles;
unsigned int MapBuilder::nCollums;
unsigned int MapBuilder::tileSize;
int MapBuilder::atlasY;
int MapBuilder::atlasX;
 int MapBuilder::currentTile=0;
MapBuilder::MapBuilder()
{
}

void MapBuilder::setRenderer(SDL_Renderer * renderer)
{
	gRenderer = renderer;
}

void MapBuilder::loadMap()
{
	int tileYCord = 0;
	int tileXCord = 0;
	nCollums = FileManager::GetInstance()->collumns;
	nTiles = FileManager::GetInstance()->tileNumbers.size();
	tileSize = FileManager::GetInstance()->size;
	TILES = new Tile[nTiles];
	for (unsigned int i = 0; i < nTiles; i++)
	{
		if (i % nCollums == 0&&i!=0)
		{
			tileYCord++;
			tileXCord = 0;
		}
		//TILES[i].tileType
		TILES[i].setTile(FileManager::GetInstance()->tileNumbers.at(i));
		TILES[i].initObject(ResourceManager::getAtlas(),gRenderer);
		TILES[i].setTileSize(tileSize);
		int x = TILES[i].tileType % ResourceManager::atlasCollumns *16;
		int y = TILES[i].tileType / ResourceManager::atlasCollumns *16;
		TILES[i].setSourceRect(x, y,16,16);
		TILES[i].setTileCoordinates(tileXCord *TILES[i].tileSize, tileYCord*TILES[i].tileSize);
		tileXCord++;

		
	}
}

void MapBuilder::drawBaseMap()
{

}
void MapBuilder::drawMap()
{
	for (unsigned int i = 0; i < nTiles; i++)
	{
		TILES[i].draw();
	}
}

void MapBuilder::increaseTileSize()
{
	if(tileSize<256)
		tileSize = tileSize*2;
	refreshMap();
}

void MapBuilder::decreaseTileSize()
{
	if (tileSize>4)
		tileSize = tileSize/2;
	refreshMap();
}
void MapBuilder::refreshMap()
{
	int tileYCord = 0;
	int tileXCord = 0;
	for (unsigned int i = 0; i < nTiles; i++)
	{
		
		TILES[i].setTileSize(tileSize);
		if (i % nCollums == 0 && i != 0)
		{
			tileYCord++;
			tileXCord = 0;
		}
		int x = TILES[i].tileType % ResourceManager::atlasCollumns * 16;
		int y = TILES[i].tileType / ResourceManager::atlasCollumns * 16;
		TILES[i].setSourceRect(x, y, 16, 16);
		TILES[i].setTileCoordinates(tileXCord *TILES[i].tileSize, tileYCord*TILES[i].tileSize);
		tileXCord++;
	}
	
}

//Change clicked Tile texture
void MapBuilder::paintSquare(int x, int  y) 
{
	
	
	int squareX = findCoordinate(x);
	int squareY = findCoordinate(y);

	int position = findPosition(squareX,squareY);
	if(position>=nTiles||squareX>=nCollums)
	{
		return;
	}
	else
	{
		TILES[position].tileType = currentTile;

		int rectX = TILES[position].tileType % ResourceManager::atlasCollumns * 16;
		int rectY = TILES[position].tileType / ResourceManager::atlasCollumns;
		TILES[position].setSourceRect(rectX, rectY * 16, 16, 16);
	}

}

//Find Tile array position
int  MapBuilder::findPosition(int x, int y)
{
	int position = 0;
	position = x;
	position = x + (y*nCollums);
	return position;
}
//Find Tile Clicking Coordinate
int MapBuilder::findCoordinate(int x)
{
	int x1 = 0;
	int x2 = 1;
	
	bool searching = true;
	while (searching)
	{
		if (x1 < 0 || x2 < 0)
			return 0;
		if(x1*tileSize <= x &&x<= x2 * tileSize)
		{
			searching = false;
		}
		else
		{
			x1++;
			x2++;
		}
	}
	return x1;
}
void MapBuilder::switchTileDown()
{
	if(currentTile + ResourceManager::atlasCollumns>ResourceManager::atlasSprites+1)
	{
		return;
	}
	int rectX = currentTile %ResourceManager::atlasCollumns * 16;
	currentTile = currentTile + ResourceManager::atlasCollumns;
	int rectY = currentTile / ResourceManager::atlasCollumns;
	
	TILES[0].setSourceRect(rectX, rectY * 16, 16, 16);

}

void MapBuilder::switchTileUp()
{
	if (currentTile-ResourceManager::atlasCollumns<0)
	{
		return;
	}
	int rectX = currentTile %ResourceManager::atlasCollumns * 16;
	
	currentTile = currentTile - ResourceManager::atlasCollumns;
	int rectY = currentTile / ResourceManager::atlasCollumns;

	TILES[0].setSourceRect(rectX, rectY * 16, 16, 16);
}
void MapBuilder::switchTileFwd()
{
	if(currentTile<=ResourceManager::atlasSprites)
	{
		currentTile++;
	}
	else
	{
		currentTile = 0;
	}
	int rectX = currentTile %ResourceManager::atlasCollumns * 16;
	int rectY = currentTile / ResourceManager::atlasCollumns;
	TILES[0].setSourceRect(rectX, rectY*16, 16, 16);
}
void MapBuilder::switchTileBck()
{
	if (currentTile>0)
	{
		currentTile--;
	}
	else
	{
		currentTile = ResourceManager::atlasSprites+1;
	}
	int rectX = currentTile %ResourceManager::atlasCollumns * 16;
	int rectY = currentTile / ResourceManager::atlasCollumns;
	
	TILES[0].setSourceRect(rectX, rectY*16, 16, 16);
}

void MapBuilder::saveMap()
{
	
	FileManager::GetInstance()->writeFile(TILES,nTiles);
}

void MapBuilder::swapMap()
{
	printf("Swapping MAPS");
}
MapBuilder::~MapBuilder()
{
	
}
