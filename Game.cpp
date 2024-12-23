//
// Created by _edd.ie_ on 22/12/2024.
//
#include "Game.h"
#include<iostream>
#include<SDL_image.h>

Game::Game() {
    running = false;
    gTexture = nullptr;
    gWindow = nullptr;
    gRenderer = nullptr;
}

Game::~Game() = default;


void Game::init(const char* title, int xPos, int yPos, int width,
        int height, int flags){

    // attempt to initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        // init the window
        gWindow = SDL_CreateWindow(title, xPos, yPos, width, height, flags);

        if(gWindow != nullptr){
            std::cout << "window creation success\n";
            gRenderer = SDL_CreateRenderer(gWindow, -1, 0);
            if(gRenderer != nullptr)
            {
                std::cout << "renderer creation success\n";
                SDL_SetRenderDrawColor(gRenderer,0,0,0,255);
                running = true;

                if (SDL_Surface* pTempSurface =  IMG_Load("resources/pack/Effect Block-Sheet.png");
                    pTempSurface == nullptr) std::cout << "surface fail\n";
                else {
                    gTexture = SDL_CreateTextureFromSurface(gRenderer, pTempSurface);
                    SDL_FreeSurface(pTempSurface);

                    SDL_QueryTexture(gTexture, nullptr, nullptr,
                        &sourceRectangle.w, &sourceRectangle.h);

                    destinationRectangle.x = sourceRectangle.x = 0;
                    destinationRectangle.y = sourceRectangle.y = 0;
                    sourceRectangle.w = 32;
                    sourceRectangle.h = 32;
                    destinationRectangle.w = 50;
                    destinationRectangle.h = 50;
                }

            }
            else std::cout << "renderer init fail\n";
        }
        else std::cout << "window init fail\n";
    }
    else std::cout << "SDL init fail\n";
}

void Game::render() {
    SDL_RenderClear(gRenderer); // clear the renderer to the draw color

    SDL_RenderCopyEx(gRenderer, gTexture, &sourceRectangle,
        &destinationRectangle, 0, 0, SDL_FLIP_HORIZONTAL);

    SDL_RenderPresent(gRenderer); // draw to the screen
}

void Game::update() {
    sourceRectangle.x = 32 * static_cast<int>((SDL_GetTicks() / 200) % 5);
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
    SDL_DestroyWindow(gWindow);
    SDL_DestroyRenderer(gRenderer);
    SDL_Quit();
}

bool Game::isRunning() const {
    return running;
}