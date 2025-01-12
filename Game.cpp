//
// Created by _edd.ie_ on 22/12/2024.
//

#include<iostream>
#include "Game.h"

#include "Enemy.h"
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

                if(TheTextureManager::Instance()->
                    load("resources/pack/Effect Block-Sheet.png", "animate", renderer))
                {
                    auto* obj = new GameObject();
                    GameObject* player1 = new Player();
                    GameObject* enemy1 = new Enemy();

                    obj->load(100, 100, 32, 32, "animate");
                    player1->load(300, 300, 32, 32, "animate");
                    enemy1->load(0, 0, 32, 32, "animate");


                    gameObjects.push_back(obj);
                    gameObjects.push_back(player1);
                    gameObjects.push_back(enemy1);

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

    // loop through our objects and draw them
    for(auto & gameObject : gameObjects){
        gameObject->draw(renderer);
    }

    SDL_RenderPresent(renderer); // draw to the screen
}

void Game::update() {
    currentFrame = static_cast<int>(((SDL_GetTicks() / 100) % 5));
    for(auto & gameObject : gameObjects){
        gameObject->update();
    }
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