//
//  main.cpp
//  MapBuilderPort
//
//  Created by User on 9/29/17.
//  Copyright © 2017 DemetrioPerez. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include "TileMapBuilderAccess.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    if (SDL_Init(SDL_INIT_EVERYTHING)<0)
    {
       std::cout <<SDL_GetError();
    }

    
    return 0;
}
