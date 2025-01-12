//
// Created by _edd.ie_ on 12/01/2025.
//

#include "Enemy.h"
#include <utility>

void Enemy::load(int x, int y, int width, int height, std::string textureID){
    GameObject::load(x, y, width, height, std::move(textureID));
}

void Enemy::draw(SDL_Renderer* renderer){
    GameObject::draw(renderer);
}

void Enemy::update() {
    yPos += 1;
    xPos += 1;
    currentFrame = static_cast<int>((SDL_GetTicks() / 100) % 6);
}

