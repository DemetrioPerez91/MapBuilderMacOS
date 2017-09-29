#include "TileMapViewer.h"


TileMapViewer::TileMapViewer()
{
}


TileMapViewer::~TileMapViewer()
{
}

bool TileMapViewer::init()
{
	bool success= true;
	
		
	tileMapWindow = SDL_CreateWindow("TileMapViewer",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
	1000, 1000,
		SDL_WINDOW_SHOWN);
	if (tileMapWindow == NULL)
	{
		success = false;
		return success;
	}
	else
	{
		tileMapRenderer = SDL_CreateRenderer(tileMapWindow, -1, SDL_RENDERER_ACCELERATED);
		if (tileMapRenderer == NULL)
		{
			success = false;
			return success;
		}
		else
		{
			SDL_SetRenderDrawColor(tileMapRenderer, 104, 48, 48, 0);
			int imgFlags = IMG_INIT_PNG;
			if (!IMG_Init(imgFlags)&imgFlags)
			{
				success = false;
				return success;
			}
			else
			{
				tileMapSurface = SDL_GetWindowSurface(tileMapWindow);
				if (tileMapSurface == NULL)
				{
					success = false;
					return success;
				}
				else
				{
					SrcRect = new SDL_Rect();
					DestRect = new SDL_Rect();
					return success;
				}
			}
		}
	}
	return false;
}

void TileMapViewer::refresh()
{
	SrcRect->h=ResourceManager::atlasH;
	SrcRect->w= ResourceManager::atlasW;
	SrcRect->x = 0;
	SrcRect->y = 0;
	DestRect->x = 0;
	DestRect->y = 0;
	DestRect->h = 400;
	DestRect->w = 400;
	SDL_RenderCopy(tileMapRenderer, ResourceManager::getAtlas(), SrcRect, DestRect);
	SDL_RenderPresent(tileMapRenderer);
	
}
