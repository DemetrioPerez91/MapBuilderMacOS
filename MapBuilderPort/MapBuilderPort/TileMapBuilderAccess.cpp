/*
#include "TileMapBuilderAccess.h"


TileMapBuilderAccess::TileMapBuilderAccess()
{
}


TileMapBuilderAccess::~TileMapBuilderAccess()
{
}

void TileMapBuilderAccess::multiViewport()
{
	SDL_Rect topLeftViewport;
	topLeftViewport.x = 0;
	topLeftViewport.y = 0;
	topLeftViewport.w = SCREEN_WIDTH / 2;
	topLeftViewport.h = SCREEN_HEIGHT / 2;
	SDL_RenderSetViewport(gRenderer, &topLeftViewport);
	SDL_RenderPresent(gRenderer);

	SDL_Rect topRightViewport;
	topRightViewport.x = SCREEN_WIDTH / 2;
	topRightViewport.y = 0;
	topRightViewport.w = SCREEN_WIDTH / 2;
	topRightViewport.h = SCREEN_HEIGHT / 2;
	SDL_RenderSetViewport(gRenderer, &topRightViewport);
	SDL_RenderPresent(gRenderer);

	SDL_Rect bottomViewport;
	bottomViewport.x = 0;
	bottomViewport.y = SCREEN_HEIGHT / 2;
	bottomViewport.w = SCREEN_WIDTH;
	bottomViewport.h = SCREEN_HEIGHT / 2;
	SDL_RenderSetViewport(gRenderer, &bottomViewport);
	SDL_RenderPresent(gRenderer);
}

	
//Activate MapBuilder mode
void TileMapBuilderAccess::startMapBuilder()
{
	FileManager::GetInstance()->map = FileManager::ZELDA;
	FileManager::GetInstance()->loadFile();
	ResourceManager::atlasURL = FileManager::GetInstance()->atlasURL;
	ResourceManager::loadAtlas();
	MapBuilder::loadMap();
	MapBuilder::drawMap();
	SDL_RenderPresent(gRenderer);
}

//Check for changes in the current tileMap and files and if there are so, refresh()
void TileMapBuilderAccess::checkForUpdate()
{
	if (FileManager::GetInstance()->checkForUpdates() == 1)
	{
		refresh();
	}
	else
	{
		return;
	}

}

//Initiate SDL essentials	
bool TileMapBuilderAccess::init()
{
	bool success = true;
	if (SDL_Init(SDL_INIT_TIMER)<0)
	{
		success = false;
		return success;
	}
	else
	{
		if (SDL_Init(SDL_INIT_VIDEO)<0)
		{
			success = false;
			return success;
		}
		else
		{
			gWindow = SDL_CreateWindow("TileMapBuilder",
				SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
				SCREEN_WIDTH, SCREEN_HEIGHT,
				SDL_WINDOW_SHOWN);
			if (gWindow == NULL)
			{
				success = false;
				return success;
			}
			else
			{
				gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
				if (gRenderer == NULL)
				{
					success = false;
					return success;
				}
				else
				{
					SDL_SetRenderDrawColor(gRenderer, 104, 48, 48, 0);
					int imgFlags = IMG_INIT_PNG;
					if (!IMG_Init(imgFlags)&imgFlags)
					{
						success = false;
						return success;
					}
					else
					{
						gScreenSurface = SDL_GetWindowSurface(gWindow);
						if (gScreenSurface == NULL)
						{
							success = false;
							return success;
						}
						else
						{
							ResourceManager::setRenderer(gRenderer);
							ResourceManager::startUpTileTextures();
							MapBuilder::setRenderer(gRenderer);
							startMapBuilder();
							return success;
						}
					}

				}
			}
		}
	}
}

//Reload current map from save state
void TileMapBuilderAccess::refresh()
{
	FileManager::GetInstance()->loadFile();
	ResourceManager::atlasURL = FileManager::GetInstance()->atlasURL;
	ResourceManager::loadAtlas();
	SDL_RenderClear(gRenderer);
	MapBuilder::loadMap();
	MapBuilder::drawMap();
	SDL_RenderPresent(gRenderer);
}

//Expand map image
void TileMapBuilderAccess::zoomIn()
{
	MapBuilder::increaseTileSize();
	SDL_RenderClear(gRenderer);
	MapBuilder::drawMap();
	SDL_RenderPresent(gRenderer);
}
void TileMapBuilderAccess::zoomOut()
{
	MapBuilder::decreaseTileSize();
	SDL_RenderClear(gRenderer);
	MapBuilder::drawMap();
	SDL_RenderPresent(gRenderer);
}

//Select tilesto be painted
void TileMapBuilderAccess::switchTileMinus()
{
	MapBuilder::switchTileBck();
	SDL_RenderClear(gRenderer);
	MapBuilder::drawMap();
	SDL_RenderPresent(gRenderer);
}
void TileMapBuilderAccess::switchTileMinusVert()
{
	MapBuilder::switchTileUp();
	SDL_RenderClear(gRenderer);
	MapBuilder::drawMap();
	SDL_RenderPresent(gRenderer);
}
void TileMapBuilderAccess::switchTilePlus()
{
	MapBuilder::switchTileFwd();
	SDL_RenderClear(gRenderer);
	MapBuilder::drawMap();
	SDL_RenderPresent(gRenderer);
}
void TileMapBuilderAccess::switchTilePlusVert()
{
	MapBuilder::switchTileDown();
	SDL_RenderClear(gRenderer);
	MapBuilder::drawMap();
	SDL_RenderPresent(gRenderer);
}

void TileMapBuilderAccess::changeMaps()
{
	switch (FileManager::GetInstance()->map)
	{
	case FileManager::ZELDA:
		FileManager::GetInstance()->map = FileManager::POKEMON;
		break;
	case FileManager::POKEMON:
		FileManager::GetInstance()->map = FileManager::ZELDA;
		break;
	default:
		break;
	}
	refresh();
}

//Process all in-game/editor inputs
void TileMapBuilderAccess::editorInputManagement()
{
	InputManager::processInput();

	switch (InputManager::gameStates)
	{
	case InputManager::CHECK_FOR_CHANGES:
		checkForUpdate();
		break;
	case InputManager::REFRESH:
		refresh();
		break;
	case InputManager::ZOOM_IN:
		zoomIn();
		break;
	case InputManager::ZOOM_OUT:
		zoomOut();
		break;
	case InputManager::SWITCH_TILE_PLUS_VERT:
		switchTilePlusVert();
		break;
	case InputManager::SWITCH_TILE_MINUS_VERT:
		switchTileMinusVert();
		break;
	case InputManager::SWITCH_TILE_PLUS:
		switchTilePlus();
		break;
	case InputManager::SWITCH_TILE_MINUS:
		switchTileMinus();
		break;
	case InputManager::SAVE_MAP:
		printf("SAVING...\n");
		MapBuilder::saveMap();
		break;
	case InputManager::SWITCH_MAP:
		changeMaps();
		break;
	case InputManager::QUIT:
		active = false;
		break;
	default:
		break;

	}
	if (InputManager::click)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		MapBuilder::paintSquare(x, y);
		SDL_RenderClear(gRenderer);
		MapBuilder::drawMap();
		SDL_RenderPresent(gRenderer);

	}

}
*/




