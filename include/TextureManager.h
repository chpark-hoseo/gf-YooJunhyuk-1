#pragma once

#include <map>
#include "main.h"

class TextureManager
{
private:
    TextureManager() {}

    static TextureManager* instance;
    std::map<std::string, SDL_Texture*> m_textureMap;

public:
    ~TextureManager() {}

    static TextureManager* Instance()
    {
        if (instance == NULL)
        {
            instance = new TextureManager();
        }
        return instance;
    }

    bool Load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
    void Draw(std::string id, int x, int y, int width, int height,
        SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void DrawFrame(std::string id, int x, int y, int width, int height,
        int currentRow, int currentFrame,
        SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
};

typedef TextureManager TextureM;