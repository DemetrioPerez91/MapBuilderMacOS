//
//  main.cpp
//  MapBuilderPort
//
//  Created by User on 9/29/17.
//  Copyright © 2017 DemetrioPerez. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>

int main(int argc, const char * argv[]) {
   
    TMV = new TileMapViewer();
    TBA = new TileMapBuilderAccess();
    if (!TBA->init())
    {
        printf("failed to initialize TileMapBuilder");
    }
    else
    {
        
    }

    
    
    
    while (TBA->active)
    {
        TBA->editorInputManagement();
        //TMV->refresh();
    }
    
    
    
    return 0;
}
