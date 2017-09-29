#include "ResourceManager.h"

//Tiles
std::string url = "Data\\Tiles\\";
std::string extention = ".png";
std::string ResourceManager::atlasURL;
std::string ResourceManager::MainMenuUrl = "Data\\screens\\MapSplash.png";

const int  ResourceManager::n_sprites;
SDL_Texture *ResourceManager::TILES[n_sprites];
SDL_Renderer *ResourceManager::renderer;
SDL_Texture *ResourceManager::atlas;
SDL_Texture *ResourceManager::MainMenu;
int ResourceManager::atlasH;
int ResourceManager::atlasW;
int ResourceManager::atlasSprites;
int ResourceManager::atlasCollumns;
int ResourceManager::atlasLines;
int ResourceManager::nTiles;


ResourceManager::ResourceManager()
{
	
}
void ResourceManager::setRenderer(SDL_Renderer * iRenderer){
	renderer= iRenderer;
}
//Set tiles to NULL
void ResourceManager::startUpTileTextures()
{
	//Set arrays as NULL
	for (int i = 0; i < n_sprites; i++)
	{
		TILES[i] = NULL;
	}
	std::string temp;




}
//Load atlas texture
void ResourceManager::loadAtlas()
{
	atlas = loadTexture(atlasURL);
	if(atlas ==NULL)
	{
		printf("COULD NOT LOAD ATLAS");
	}

	SDL_QueryTexture(atlas,NULL,NULL,&atlasW,&atlasH);

	atlasSprites = (atlasW*atlasH) / 256;
	atlasLines = atlasH / 16;
	atlasCollumns = atlasW / 16;

}
//Load one TEXTURE at a time remember to use  SDL_SetTextureBlendMode(mimiTexture, SDL_BLENDMODE_BLEND);
SDL_Texture * ResourceManager::loadTexture(std::string path)
{
	SDL_Texture * temp =NULL;
	temp = IMG_LoadTexture(renderer, path.c_str()); ;
	if(temp==NULL)
	{
		printf("Could not load texture \n SDL ERROR: %s", SDL_GetError());
		return NULL;
	}
	else
	{
		printf("TEXTURE LOADED %s \n",path.c_str() );
	}
	//SDL_SetTextureBlendMode(mimiTexture, SDL_BLENDMODE_BLEND);
	return temp;
}

//Getters

//Get tile texture from array
SDL_Texture * ResourceManager::getSprite(int index)
{
	return TILES[index];
}

//Get atlas
SDL_Texture * ResourceManager::getAtlas()
{
	return  atlas;
}

void ResourceManager::loadTextures()
{
	MainMenu=loadTexture(MainMenuUrl);
}
ResourceManager::~ResourceManager()
{
}
