//
// Created by _edd.ie_ on 29/12/2024.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

class Player : public GameObject { // inherit from GameObject
public:
    void load(int x, int y, int width, int height, std::string textureID);
    void draw(SDL_Renderer* renderer);
    void update();
    void clean();
};

#endif //PLAYER_H
