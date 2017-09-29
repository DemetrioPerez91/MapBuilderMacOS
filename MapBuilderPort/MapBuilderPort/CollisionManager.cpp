#include "stdafx.h"
#include "CollisionManager.h"
#include "GameObject.h"
/*
	This class goes through a Pointer Vector and loops through 
	them to see if there are any new intersections; if so, the 
	pointers involved run their OnCollission Methods passign 
	through each other their pointers to work with them.
*/
std::vector<GameObject*> CollisionManager::pointerList;
int CollisionManager::firstFreePosition;
GameObject* CollisionManager::pointerArrays[1000];

CollisionManager::CollisionManager()
{
	for (int i = 0; i < 100; i++)
	{
		pointerArrays[i] = NULL;
	}
}


CollisionManager::~CollisionManager()
{
}

int CollisionManager::RegisterPointer(GameObject*pointer)
{
	firstFreePosition = getFirstFreePosition();
   	pointerArrays[firstFreePosition] = pointer;
	return firstFreePosition;
}

void CollisionManager::ManageCollisions(GameObject*pointer)
{
	int temp = getFirstFreePosition()-1;
	for (int i = 0; i <temp ;i++)
	{
		for (int j = i; j <temp;j++)
		{
			if(pointer==pointerArrays[j])
			{
				continue;
			}
 			if (isSquare1InsideSquare2(pointer, pointerArrays[j]))
			{
          		pointer->OnCollision(pointerArrays[j]);
				pointerArrays[j]->OnCollision(pointer);
			
			}
		}
	}
}

//Compare coordinates in order to find out if pointers are intersecting each other
bool CollisionManager::isSquare1InsideSquare2(GameObject*pointer1, GameObject*pointer2)
{
	SDL_Rect *temp1;
	SDL_Rect *temp2;
	temp1 = pointer1->getDestRect();
	temp2 = pointer2->getDestRect();
	//first pointer coordinates
	int temp1_X1 = temp1->x;
	int temp1_X2 = temp1->x + temp1->w;
	int temp1_Y1 = temp1->y;
	int temp1_Y2 = temp1->y + temp1->h;

	//second pointer coordinates
	int temp2_X1 = temp2->x;
	int temp2_X2 = temp2->x + temp2->w;
	int temp2_Y1 = temp2->y;
	int temp2_Y2 = temp2->y + temp2->h;

	if(temp1_X1<=temp2_X2&&temp1_X1>=temp2_X1)
	{
		if (temp1_Y1<=temp2_Y2&&temp1_Y1 >= temp2_Y1)
		{
		//	printf("collission");
			return true;
		}
		if (temp1_Y2 >= temp2_Y1&&temp1_Y2 <= temp2_Y2)
		{
		//	printf("collission");
			return true;
		}
	}

	if (temp1_X2 >= temp2_X1&&temp1_X2 <= temp2_X2)
	{
		if (temp1_Y1 <= temp2_Y2&&temp1_Y1 >= temp2_Y1)
		{
		//	printf("collission");
			return true;
		}
		if(temp1_Y2>=temp2_Y1&&temp1_Y2<=temp2_Y2)
		{
		//	printf("collission");
			return true;
		}
	}

	return false;
}

int CollisionManager::getFirstFreePosition()
{
	int position =0;
	for (int i = 0; i < 100;i++)
	{
		if (pointerArrays[i] == NULL) {
			position = i;
			break;
		}
	}
	return position;
}

void CollisionManager::UnregisterPointer(int position)
{
   	pointerArrays[position] = NULL;
}