#pragma once

#include <string>

#include "../../../RythmGame.Graphics/Text/Text.h"
#include "../../Utils/Point.h"

using namespace RythmGame::Graphics;
using namespace RythmGame::Game::Utils;


namespace RythmGame::Game::Gameplay
{

    class Combo : public Text
    {
        int combo;

    public:
        Combo() : Text( "0", {0, (float)Default::HEIGHT, 50, 60}, BottomLeft )
        {
            combo = 0;
        }

        int GetCombo();
        void SetCombo( int combo );
        void AddCombo( int combo = 1 );
    };

}