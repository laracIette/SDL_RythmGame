#pragma once

#include "ButtonTemplate.h"

namespace RythmGame::Game::Menu::StartScreen::Button
{

    class SettingsButton : public ButtonTemplate
    {

    public:
    /**
        SettingsButton inherits from ButtonTemplate
    */
        SettingsButton() : ButtonTemplate(
            "assets/Skins/BaseSkin/Menu/StartScreen/SettingsButton.png",
            TopRight
        )
        {}
    };

}