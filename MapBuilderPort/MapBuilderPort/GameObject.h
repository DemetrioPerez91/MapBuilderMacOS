#pragma once
#include <SDL2/SDL.h>
#include "ResourceManager.h"
#include "CollisionManager.h"

class GameObject
{
public:
	//Getters and setters	
	SDL_Texture * getTexture();
	void setTexture(SDL_Texture * resource);
	void setRenderer(SDL_Renderer * inRenderer);
	void setSourceRect(int x, int y, int h, int w);
	void setDestRect(int x, int y, int h, int w);
	void initObject(SDL_Texture *surface, SDL_Renderer * screen);
	int CollisionHandler;
	SDL_Rect * getDestRect();
	SDL_Rect * getSrcRect();
	int life = 1;
	void draw();
	GameObject();
	GameObject(SDL_Texture *surface, SDL_Renderer * screen);
	~GameObject();
	enum ObjectType
	{
		TILE,NPC,PC
	};
	virtual void OnCollision(GameObject*other) = 0;
	virtual ObjectType getType()=0;
protected:
	//Inherited variables
	SDL_Rect * DestRect =NULL;
	SDL_Rect * SrcRect = NULL;
	SDL_Renderer * renderer = NULL;
	SDL_Texture *  texture = NULL;
};
