//
// Created by _edd.ie_ on 21/12/2024.
//

#ifndef GAME_H
#define GAME_H

#include<SDL.h>
#include<iostream>

class Game {
    SDL_Window* gWindow = 0; //
    SDL_Renderer* gRenderer = 0;
    bool running;
public:
    Game() {
        running = false;
    }
    ~Game()= default;

    void init(const char* title, int xPos, int yPos, int width,
        int height, int flags){
        
        // attempt to initialize SDL
        if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
        {
            
            // init the window
            gWindow = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
            
            if(gWindow != 0){
                gRenderer = SDL_CreateRenderer(gWindow, -1, 0);
                if(gRenderer != 0)
                {
                    std::cout << "renderer creation success\n";
                    SDL_SetRenderDrawColor(gRenderer,255,255,255,255);
                    running = true;
                }
                else std::cout << "renderer init fail\n";
            }
            else std::cout << "window init fail\n";
        }
        else std::cout << "SDL init fail\n";
    }

    void render() {
        SDL_RenderClear(gRenderer); // clear the renderer to the draw color
        SDL_RenderPresent(gRenderer); // draw to the screen
    }

    void update(){}
    void handleEvents() {
        SDL_Event event;
        if(SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    running = false;
                break;
                default:
                    break;
            }
        }
    }

    void clean() {
        std::cout << "cleaning game\n";
        SDL_DestroyWindow(gWindow);
        SDL_DestroyRenderer(gRenderer);
        SDL_Quit();
    }

    bool isRunning() const {
        return running;
    }
};

#endif //GAME_H
