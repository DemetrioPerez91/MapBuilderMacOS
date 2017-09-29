#include "InputManager.h"
SDL_Event e;
int InputManager::gameStates;
int InputManager::heroController;
bool InputManager::click= false;
InputManager::InputManager()
{

}

void InputManager::processInput()
{
	gameStates = 0;
	while (SDL_PollEvent(&e) != 0)
	{
		
		switch (e.type)
		{
			
			case SDL_WINDOWEVENT:
				switch (e.window.event) {
					case SDL_WINDOWEVENT_FOCUS_GAINED:
						gameStates = CHECK_FOR_CHANGES;
						break;
					default :
						break;
				}
				break;
			case SDL_QUIT:
				gameStates = QUIT;
				break;
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym)
				{
					case SDLK_RETURN:
						gameStates = REFRESH;
						break;
					case SDLK_2:
						gameStates = ZOOM_IN;
						printf("ZOOM IN\n");
						break;
					case SDLK_1:
						gameStates= ZOOM_OUT;
						printf("ZOOM OUT\n");
						break;
					case SDLK_UP:
					case SDLK_w:
						gameStates = SWITCH_TILE_MINUS_VERT;
							break;
					case SDLK_DOWN:
					case SDLK_s:
						gameStates = SWITCH_TILE_PLUS_VERT;
						break;
					case SDLK_LEFT:
					case SDLK_a:
						printf("Switch Tile\n");
						gameStates = SWITCH_TILE_MINUS;
						break;
					case SDLK_RIGHT:
					case SDLK_d:
						gameStates = SWITCH_TILE_PLUS;
						break;
					case SDLK_SPACE:
						gameStates = SAVE_MAP;
						break;
					case SDLK_m:
						gameStates = SWITCH_MAP;
						break;
					default:
						break;
				}
				break; 
			case SDL_MOUSEBUTTONDOWN:
				printf("mouse\n");
				click = true;
				break;
			case SDL_MOUSEBUTTONUP:
				click = false;
				break;

			default:
				break;
		}
	}
}
InputManager::~InputManager()
{
}
