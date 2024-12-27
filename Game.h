//
// Created by _edd.ie_ on 21/12/2024.
//

#ifndef GAME_H
#define GAME_H

#include<SDL.h>

class TextureManager;

class Game {
    // Window
    SDL_Window* mainWindow;
    SDL_Renderer* renderer;

    // Drawing
    int currentFrame;

    bool running;
public:
    Game();
    ~Game();

    void init(const char* title, int xPos, int yPos, int width,
        int height, int flags);

    void render();
    void update();
    void handleEvents();
    void clean();
    bool isRunning() const;
};




#endif //GAME_H
