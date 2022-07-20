#pragma once

#include "main.h"
#include "TextureManager.h"

class Game
{
private:
    int m_currentFrame;
    bool m_bRunning;

    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;

public:
    Game() {}
    ~Game() {}

    bool Init(const char* title, int xpos, int ypos, int width, int height, int flags);
    void Render();
    void Update();
    bool Running();
    void HandleEvents();
    void Clean();
};