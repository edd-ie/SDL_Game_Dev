//
// Created by _edd.ie_ on 29/12/2024.
//

#include "GameObject.h"
#include <utility>


void GameObject::load(int x, int y, int width, int height, std::string texture_id){
    xPos = x;
    yPos = y;
    objWidth = width;
    objHeight = height;
    textureID = std::move(texture_id); //Sends string to the function and the caller of the function will never use the string again
    currentRow = 1;
    currentFrame = 1;
}

void GameObject::draw(SDL_Renderer* renderer){
    TextureManager::Instance()->drawFrame(textureID,
        xPos, yPos,
        objWidth, objHeight,
        currentRow, currentFrame,
        renderer);
}

void GameObject::update() {
    xPos += 1;
}