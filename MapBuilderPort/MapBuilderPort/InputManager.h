#pragma once
#include "SDL2\SDL.h"
#include "SDL2\SDL_image.h"

class InputManager
{
	

public:
	InputManager();
	~InputManager();
	static void processInput();
	static int gameStates;
	static int heroController;
	static bool click;
	static enum HEROCONTROLS
	{
		LEFT = 1, RIGHT, UP,DOWN,SHOOT
	};
	static enum GameState
	{
		PAUSE,
		REFRESH,
		ZOOM_IN,
		ZOOM_OUT,
		PAINT,
		SWITCH_TILE_PLUS,
		SWITCH_TILE_MINUS,
		SWITCH_TILE_MINUS_VERT,
		SWITCH_TILE_PLUS_VERT,
		SAVE_MAP,
		SWITCH_MAP,
		CHECK_FOR_CHANGES,
		QUIT
	};
	static struct mouseState
	{
		bool click = false;
	};
};

