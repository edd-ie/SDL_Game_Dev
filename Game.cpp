//
// Created by _edd.ie_ on 22/12/2024.
//

#include<iostream>
#include "Game.h"
#include "TextureManager.h"


Game::Game() {
    running = false;
    currentFrame = 0;
    mainWindow = nullptr;
    renderer = nullptr;
}

Game::~Game() = default;


void Game::init(const char* title, int xPos, int yPos, int width,
        int height, int flags){

    // attempt to initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        // init the window
        mainWindow = SDL_CreateWindow(title, xPos, yPos, width, height, flags);

        if(mainWindow != nullptr){
            std::cout << "window creation success\n";
            renderer = SDL_CreateRenderer(mainWindow, -1, 0);
            if(renderer != nullptr)
            {
                std::cout << "renderer creation success\n";
                SDL_SetRenderDrawColor(renderer,0,0,0,255);
                running = true;

                if(!TheTextureManager::Instance()->load("resources/pack/Effect Block-Sheet.png", "animate", renderer))
                {
                    std::cout << "failed to load animation texture\n";
                }

            }
            else std::cout << "renderer init fail\n";
        }
        else std::cout << "window init fail\n";
    }
    else std::cout << "SDL init fail\n";
}

void Game::render() {
    SDL_RenderClear(renderer); // clear the renderer to the draw color

    TheTextureManager::Instance()->draw("animate", 0,0, 32, 32,  renderer);
    TheTextureManager::Instance()->drawFrame("animate", 100,100, 32, 32, 1, currentFrame, renderer);

    SDL_RenderPresent(renderer); // draw to the screen
}

void Game::update() {
    currentFrame = static_cast<int>(((SDL_GetTicks() / 100) % 5));
}

void Game::handleEvents() {
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

void Game::clean() {
    std::cout << "cleaning game\n";
    SDL_DestroyWindow(mainWindow);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

bool Game::isRunning() const {
    return running;
}