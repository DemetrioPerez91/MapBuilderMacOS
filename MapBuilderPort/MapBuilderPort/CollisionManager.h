#pragma once
#include <vector>
#include "SDL2\SDL.h"
class GameObject;
class CollisionManager
{
public:
	//Collection of pointers for collision detection
	static int firstFreePosition;
	static GameObject * pointerArrays[1000];
	static std::vector<GameObject*>pointerList;
	static int RegisterPointer(GameObject*pointer);
	static void ManageCollisions(GameObject*pointer);
	static void UnregisterPointer(int  handler);
	static int getFirstFreePosition();
	CollisionManager();
	~CollisionManager();
	//Methods
	static  bool isSquare1InsideSquare2(GameObject*pointer1, GameObject*pointer2);
};

