#include "Run.h"

std::chrono::high_resolution_clock::time_point RythmGame::Game::Utils::offsetTime;

float RythmGame::Game::Utils::deltaTime;
float RythmGame::Game::Utils::velocity;
bool  RythmGame::Game::Utils::isHorizontal;

InputManager RythmGame::Game::Events::inputManager;
ImageManager RythmGame::Graphics::imageManager;

HitSoundManager *RythmGame::Sound::hitSoundManager;

namespace RythmGame::Game
{
    Run::Run()
    {
        hitSoundManager = new HitSoundManager();

        currentTime = std::chrono::system_clock::now();

        isRunning = true;

        startScreen        = new StartScreen::Screen();
        mapSelectionScreen = new MapSelection::Screen();

        isSettings = false;

        player = new Player();

        velocity = 0.3f;

        isHorizontal = true;

        map = new Map();
    }

    Run::~Run()
    {
    }

    void Run::Init()
    {
        deltaTime = 0;
        lastFrameTime = currentTime;

        gameState = STARTSCREEN;
    }

    void Run::Update()
    {

        if( inputManager.HandleEvents() ) isRunning = false;

        if( gameState == STARTSCREEN )
        {
            startScreen->Update();

            if( startScreen->StartGame() )
            {
                gameState = MAPSELECTION;
            }
        }
        if( gameState == MAPSELECTION )
        {
            Song *tempSong{ mapSelectionScreen->Update() };
            if( tempSong )
            {
                map->Init( tempSong );
                map->Start();
                gameState = GAMEPLAY;
            }
        }
        if( gameState == GAMEPLAY )
        {
            if( inputManager.PressedNoLock( inputManager.keyboard.Escape ) )
            {
                inputManager.SetKeyLock( inputManager.keyboard.Escape, true );
                map->Pause();
            }

            player->Input();
            map->Update();
        }

        if( inputManager.PressedNoLock( inputManager.keyboard.S ) )
        {
            inputManager.SetKeyLock( inputManager.keyboard.S, true );

            isSettings = !isSettings;
        }

        if( isSettings )
        {
            settingsWindow->UpdateWindow();
        }


        if( inputManager.LeftClickedNoLock() )  inputManager.SetButtonLock( inputManager.mouse.Left,  true );
        if( inputManager.RightClickedNoLock() ) inputManager.SetButtonLock( inputManager.mouse.Right, true );

        hitSoundManager->Update();
    }


    void Run::Render()
    {
        SDL_SetRenderDrawColor( window->renderer, 0, 0, 0, 255 );
        SDL_RenderClear( window->renderer );


        switch( gameState )
        {
        case STARTSCREEN:
            startScreen->Draw();
            break;

        case MAPSELECTION:
            mapSelectionScreen->Draw();
            break;

        case GAMEPLAY:
            map->Draw();
            player->Draw();
            break;

        default:
            break;
        }

        if( isSettings )
        {
            settingsWindow->DrawWindow();
        }

        SDL_RenderPresent( window->renderer );
    }

    void Run::Clear()
    {
        SDL_DestroyWindow( window->window );
        SDL_DestroyRenderer( window->renderer );
        TTF_CloseFont( optionFont );
        TTF_CloseFont( categoryTitleFont );
        TTF_Quit();
        map->Close();
        hitSoundManager->Close();
        Mix_CloseAudio();
        SDL_Quit();
    }

}