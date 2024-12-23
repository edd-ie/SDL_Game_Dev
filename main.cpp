//
// Created by _edd.ie_ on 23/12/2024.
//

#include <iostream>
#include "Game.h"

#include <windows.h> // for debugging remove this when publishing


// Game object
Game* game = nullptr;

int main(int argc, char* argv[])
{
    //For debugging remove this when publishing
    AllocConsole();
    freopen("CON","w", stdout);

    // Game object
    game = new Game();
    std::cout << "game init attempt...\n";

    game->init("Chapter 1", 100, 100,
        640, 480,
        SDL_WINDOW_RESIZABLE);

    while(game->isRunning())
    {
        game->handleEvents();
        game->update();
        game->render();
    }
    game->clean();

    return 0;
}