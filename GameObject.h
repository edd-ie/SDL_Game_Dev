//
// Created by _edd.ie_ on 29/12/2024.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include <SDL.h>
#include "TextureManager.h"



class GameObject {
protected:
    std::string textureID;
    int currentFrame;
    int currentRow;
    int xPos;
    int yPos;
    int objWidth;
    int objHeight;
public:
    void load(int x, int y, int width, int height, std::string texture_id);
    void draw(SDL_Renderer* renderer);
    void update();
    void clean();
};

#endif //GAMEOBJECT_H
