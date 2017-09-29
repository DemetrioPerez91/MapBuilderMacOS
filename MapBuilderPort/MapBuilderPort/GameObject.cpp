
#include "GameObject.h"
//#include "CollisionManager.h"

GameObject::GameObject(SDL_Texture *surface, SDL_Renderer * screen)
{

}
GameObject::GameObject()
{
	
}

void GameObject::initObject(SDL_Texture *surface, SDL_Renderer * screen)
{
	setTexture(surface);
	DestRect = new SDL_Rect();
	setRenderer(screen);
	SrcRect = new SDL_Rect();
}
//Draw object
void GameObject::draw()
{
	SDL_RenderCopy(renderer, texture, SrcRect,DestRect );
}

//Set Game Object Renderer
void GameObject::setRenderer(SDL_Renderer * iRenderer)
{
	renderer = iRenderer;
}

//Set Game Objecct texture
void GameObject::setTexture(SDL_Texture *resource)
{
	texture = resource;
}

//Set Source rectangle for the source image to be loaded in
void GameObject::setSourceRect(int x, int y, int h, int w)
{
	SrcRect->x = x;
	SrcRect->y = y;
	SrcRect->h = h;
	SrcRect->w = w;
}

//Set Destination rectangle for the instance's texture to be copied into
void GameObject::setDestRect(int x, int y, int h, int w)
{
	DestRect->x = x;
	DestRect->y = y;
	DestRect->h = h;
	DestRect->w = w;
}

//Get the instance's texture
SDL_Texture * GameObject::getTexture() 
{
	return texture;
}

//Get Rectangles
SDL_Rect * GameObject::getDestRect() { return DestRect; }
SDL_Rect * GameObject::getSrcRect() { return SrcRect; }

GameObject::~GameObject()
{
	//CollisionManager::UnregisterPointer(CollisionHandler);
}
