//
// Created by _edd.ie_ on 21/12/2024.
//

#ifndef GAME_H
#define GAME_H

#include<SDL.h>

class Game {
    // Window
    SDL_Window* gWindow;
    SDL_Renderer* gRenderer;

    // Drawing
    SDL_Texture* gTexture;
    SDL_Rect sourceRectangle; // the first rectangle
    SDL_Rect destinationRectangle; // another rectangle

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
