#include "../include/Game.h"

bool Game::Init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (m_pWindow != 0)
        {
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if (m_pRenderer != 0)
            {
                SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
                if (!TextureM::Instance()->Load("Assets/animate-alpha.png", "animate", m_pRenderer))
                {
                    return false;
                }
            }
            else
            {
                return false; // ������ ���� ����
            }
        }
        else
        {
            return false; // ������ ���� ����
        }
    }
    else
    {
        return false; // SDL �ʱ�ȭ ����
    }

    m_bRunning = true;
    return true;
}

void Game::Render()
{
    SDL_RenderClear(m_pRenderer);
    TextureM::Instance()->Draw("animate", 0, 0, 128, 82, m_pRenderer);
    TextureM::Instance()->DrawFrame("animate", 100, 100, 128, 82, 0, m_currentFrame, m_pRenderer);
    SDL_RenderPresent(m_pRenderer);
}

void Game::Update()
{
    m_currentFrame = ((SDL_GetTicks() / 100) % 6);
}

bool Game::Running()
{
    return m_bRunning;
}

void Game::HandleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            m_bRunning = false;
            break;
        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                //g_bLeftMousePressed = true;
            }
            break;

        case SDL_MOUSEBUTTONUP:
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                //g_bLeftMousePressed = false;
            }
            break;

        }
    }
}

void Game::Clean()
{
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}