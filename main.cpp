#include "Game.h"

// Game object
Game* game = nullptr;

int main(int argc, char* argv[])
{
    game = new Game();

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