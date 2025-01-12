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
    int currentFrame=0;
    int currentRow=0;
    int xPos=0;
    int yPos=0;
    int objWidth=0;
    int objHeight=0;
public:
    virtual ~GameObject() = default;

    virtual void load(int x, int y, int width, int height, std::string texture_id);
    virtual void draw(SDL_Renderer* renderer);
    virtual void update();
    // virtual void clean();
};

#endif //GAMEOBJECT_H
