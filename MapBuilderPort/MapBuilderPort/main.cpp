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
#include "TileMapViewer.h"

TileMapBuilderAccess * TBA = NULL;
TileMapViewer *TMV = NULL;
int main(int argc, const char * argv[]) {
    // insert code here...
    TMV = new TileMapViewer();
    TBA = new TileMapBuilderAccess();
    if (!TBA->init())
    {
        printf("failed to initialize TileMapBuilder\n");
    }
    else
    {
        while (TBA->active)
        {
            TBA->editorInputManagement();
        }
    }
    return 0;
}
