//
// Created by _edd.ie_ on 12/01/2025.
//

#ifndef ENEMY_H
#define ENEMY_H
#include "GameObject.h"

class Enemy : public GameObject
{
public:
    void load(int x, int y, int width, int height, std::string textureID) override;
    void draw(SDL_Renderer* renderer) override;
    void update() override;
    // void clean() override;
};

#endif //ENEMY_H
