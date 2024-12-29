//
// Created by _edd.ie_ on 29/12/2024.
//

#include "Player.h"

#include <utility>

void Player::load(int x, int y, int width, int height, std::string textureID){
    GameObject::load(x, y, width, height, std::move(textureID));
}

void Player::draw(SDL_Renderer* renderer){
    GameObject::draw(renderer);
}

void Player::update() {
    xPos += 1;
}

