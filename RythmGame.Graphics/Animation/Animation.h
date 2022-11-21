#pragma once

#include <filesystem>
#include <string>
#include <SDL.h>
#include <vector>
#include <chrono>

#include "../../RythmGame.Game/Utils/Point.h"
#include "../../RythmGame.Game/Utils/Time.h"

#include "../Image/Image.h"


using namespace RythmGame::Game::Utils;
using namespace RythmGame::Graphics;


namespace RythmGame::Graphics
{

    class Animation
    {
        std::vector<Image *> images;
        int indice;
        std::chrono::high_resolution_clock::time_point lastImageTime;

    public:
        Animation( std::string path, GPU_Rect *dest );
        ~Animation();

        void Draw();

        float X();
        float Y();
        float W();
        float H();

        void SetX( float x );
        void SetY( float y );
        void SetW( float w );
        void SetH( float h );
    };

}