//
// Created by _edd.ie_ on 26/12/2024.
//

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <map>



class TextureManager {
    std::map<std::string, SDL_Texture*> textureMap;

    //conversion to Singleton = can only have 1 instance in a program
    static TextureManager* instance;
    TextureManager() {
        textureMap = {};
    }
public:
    static TextureManager* Instance(){
        if(instance == nullptr)
        {
            instance = new TextureManager();
            return instance;
        }
        return instance;
    }

    ~TextureManager();

    bool load(std::string fileName,std::string id,
          SDL_Renderer* renderer);

    void draw(std::string id, int x, int y, int width, int height,
        SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);


    void drawFrame(std::string id, int x, int y, int width, int height,
        int currentRow, int currentFrame, SDL_Renderer* pRenderer,
        SDL_RendererFlip flip = SDL_FLIP_NONE);
};

typedef TextureManager TheTextureManager;

#endif //TEXTUREMANAGER_H
