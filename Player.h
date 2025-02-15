//
// Created by _edd.ie_ on 29/12/2024.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

class Player : public GameObject { // inherit from GameObject
public:
    void load(int x, int y, int width, int height, std::string textureID) override;
    void draw(SDL_Renderer* renderer) override;
    void update() override;
    // void clean() override;
};

#endif //PLAYER_H
