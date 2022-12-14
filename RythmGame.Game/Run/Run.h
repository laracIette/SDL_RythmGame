#pragma once

#include "../Utils/Time.h"
#include "../Utils/Metrics.h"
#include "../Utils/GameSettings.h"

#include "../Events/InputManager.h"

#include "../Gameplay/Player/Player.h"
#include "../Gameplay/Map/Map.h"

#include "../Menu/StartScreen/Screen/Screen.h"
#include "../Menu/MapSelection/Screen/Screen.h"

#include "../../RythmGame.Sound/HitSoundManager/HitSoundManager.h"

#include "../../RythmGame.Graphics/RenderQueue/RenderQueue.h"

#include "../Settings/Window/Window.h"
#include "../FPS/Window/Window.h"
#include "../Exit/Window/Window.h"


using namespace RythmGame::Game::Events;
using namespace RythmGame::Game::Gameplay;
using namespace RythmGame::Game::Menu;
using namespace RythmGame::Game::Utils;
using namespace RythmGame::Framework;
using namespace RythmGame::Graphics;
using namespace RythmGame::Sound;


namespace RythmGame::Game
{

    enum GameStates {
        STARTSCREEN = 0,
        MAPSELECTION,
        GAMEPLAY
    };

    class Run
    {
        bool isRunning;

        Player *player;
        Map    *map;

        StartScreen::Screen  *startScreen;
        MapSelection::Screen *mapSelectionScreen;

        FPS::Window  *fpsWindow;
        Exit::Window *exitWindow;

        bool isSettings, isExit;

        int gameState;

    public:
        Run();
        ~Run();

        void Init();

        void Update();

        void Render();
        void Clear();

        bool Running() { return isRunning; }

    };

}