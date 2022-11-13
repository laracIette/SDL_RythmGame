#pragma once

#include "HitObject.h"


namespace RythmGame::Game::Hit
{

    class Ghost : public HitObject
    {
    public:
        Ghost()
        : HitObject(
            "assets/Skins/BaseSkin/HitObjects/Ghosts",
            {0, 0, 50, 50},
            {0, 0, 50, 50}
        )
        {}

        void Init()
        {
            (IsHitObjectHorizontal()) ? yOffset += getHitObjectOffsetHeight() : xOffset -= getHitObjectOffsetHeight();
            endTime = time;
        }
    };

}