#pragma once

#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include "../../RythmGame.Game/Utils/Metrics.h"

using namespace RythmGame::Game::Utils;

namespace RythmGame::Framework
{

    class Window
    {

    public:
        Window();
        ~Window();

        SDL_Window *window;
        SDL_Renderer *renderer;
    };

    extern Window *window;

}
