//
// Created by _edd.ie_ on 26/12/2024.
//
#include "TextureManager.h"

TextureManager* TextureManager::instance = nullptr;


bool TextureManager::load(std::string fileName,std::string id,
          SDL_Renderer* renderer) {
    SDL_Surface* temp_surface = IMG_Load(fileName.c_str());

    if(temp_surface == nullptr){
        return false;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, temp_surface);
    SDL_FreeSurface(temp_surface);

    if(texture == nullptr){
        // reaching here means something went wrong
        return false;
    }

    // everything went ok, add the texture to our list
    textureMap[id] = texture;
    return true;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height,
    SDL_Renderer* pRenderer, SDL_RendererFlip flip) {
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = destRect.w = width;

    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;
    SDL_RenderCopyEx(pRenderer, textureMap[id], &srcRect,
    &destRect, 0, nullptr, flip);
}


void TextureManager::drawFrame(std::string id, int x, int y, int width, int height,
    int currentRow, int currentFrame, SDL_Renderer* pRenderer,
    SDL_RendererFlip flip) {

    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = width * currentFrame;
    srcRect.y = height * (currentRow - 1);

    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(pRenderer, textureMap[id], &srcRect,
    &destRect, 0, 0, flip);
}