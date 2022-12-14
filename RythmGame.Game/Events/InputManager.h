#pragma once

#include "KeyboardEvents.h"
#include "MouseEvents.h"

#include "../Utils/Time.h"

#include <iostream>

namespace RythmGame::Game::Events
{

    class InputManager
    {
        KeyboardEvents keyboard;
        MouseEvents mouse;

        SDL_Event event;

        int leftKey1{ keyboard.D };
        int leftKey2{ keyboard.F };
        int rightKey1{ keyboard.J };
        int rightKey2{ keyboard.K };

        int flipKey{ keyboard.Space };

    public:
        bool HandleEvents()
        {
            if( mouse.wheel.x != 0 )
            {
                if( mouse.wheel.x > 0.1 )
                {
                    mouse.wheel.x -= deltaTime/25;
                }
                else if( mouse.wheel.x < -0.1 )
                {
                    mouse.wheel.x += deltaTime/25;
                }
                else
                {
                    mouse.wheel.x = 0;
                }
            }
            if( mouse.wheel.y != 0 )
            {
                if( mouse.wheel.y > 0.1 )
                {
                    mouse.wheel.y -= deltaTime/25;
                }
                else if( mouse.wheel.y < -0.1 )
                {
                    mouse.wheel.y += deltaTime/25;
                }
                else
                {
                    mouse.wheel.y = 0;
                }
            }

            SDL_GetMouseState( &mouse.pos.x, &mouse.pos.y );

            while( SDL_PollEvent( &event ) )
            {
                switch( event.type )
                {
                case SDL_QUIT:
                    return 1;

                case SDL_KEYDOWN:
                    for( int i{ 0 }; i < keyboard.KEYS; ++i )
                    {
                        if( event.key.keysym.sym != keyboard.keyCode[i] ) continue;

                        keyboard.keyPressed[i] = true;
                        break;
                    }
                    break;

                case SDL_KEYUP:
                    for( int i{ 0 }; i < keyboard.KEYS; ++i )
                    {
                        if( event.key.keysym.sym != keyboard.keyCode[i] ) continue;

                        keyboard.keyPressed[i] = false;
                        SetKeyLock( i, false );
                        break;
                    }
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    for( int i{ 0 }; i < mouse.BUTTONS; ++i )
                    {
                        if( event.button.button != mouse.buttonCode[i] ) continue;

                        mouse.buttonClicked[i] = true;
                        break;
                    }
                    break;

                case SDL_MOUSEBUTTONUP:
                    for( int i{ 0 }; i < mouse.BUTTONS; ++i )
                    {
                        if( event.button.button != mouse.buttonCode[i] ) continue;

                        mouse.buttonClicked[i] = false;
                        SetButtonLock( i, false );
                        break;
                    }
                    break;

                case SDL_MOUSEWHEEL:
                if( (mouse.wheel.x > -10) && (mouse.wheel.x < 10) )
                {
                    mouse.wheel.x += event.wheel.x*deltaTime;
                }
                if( (mouse.wheel.y > -10) && (mouse.wheel.y < 10) )
                {
                    mouse.wheel.y += event.wheel.y*deltaTime;
                }

                default:
                    break;
                }
            }
            return 0;
        }


        bool Pressed( int key )    { return keyboard.keyPressed[key]; }
        bool Clicked( int button ) { return mouse.buttonClicked[button]; }

        bool KeyLock(    int key )    { return keyboard.keyLock[key]; }
        bool ButtonLock( int button ) { return mouse.buttonLock[button]; }

        void SetKeyLock(    int key,    bool lock ) { keyboard.keyLock[key]    = lock; }
        void SetButtonLock( int button, bool lock ) { mouse.buttonLock[button] = lock; }

        bool LeftClicked()  { return Clicked( MouseLeft() ); }
        bool RightClicked() { return Clicked( MouseRight() ); }

        bool LeftLock()  { return ButtonLock( MouseLeft() ); }
        bool RightLock() { return ButtonLock( MouseRight() ); }

        bool LeftClickedNoLock()  { return (LeftClicked()  && !LeftLock()); }
        bool RightClickedNoLock() { return (RightClicked() && !RightLock()); }


        bool Left1Pressed()  { return Pressed( leftKey1 ); }
        bool Left2Pressed()  { return Pressed( leftKey2 ); }
        bool Right1Pressed() { return Pressed( rightKey1 ); }
        bool Right2Pressed() { return Pressed( rightKey2 ); }
        bool FlipPressed()   { return Pressed( flipKey ); }

        bool Left1Lock()  { return KeyLock( leftKey1 ); }
        bool Left2Lock()  { return KeyLock( leftKey2 ); }
        bool Right1Lock() { return KeyLock( rightKey1 ); }
        bool Right2Lock() { return KeyLock( rightKey2 ); }
        bool FlipLock()   { return KeyLock( flipKey ); }

        void LockLeft1()  { SetKeyLock( leftKey1,  true ); }
        void LockLeft2()  { SetKeyLock( leftKey2,  true ); }
        void LockRight1() { SetKeyLock( rightKey1, true ); }
        void LockRight2() { SetKeyLock( rightKey2, true ); }
        void LockFlip()   { SetKeyLock( flipKey, true ); }

        bool OnlyLeft1Pressed() { return (Left1Pressed()  && !Left2Pressed()); }
        bool OnlyLeft2Pressed() { return (!Left1Pressed() && Left2Pressed()); }

        bool OnlyRight1Pressed() { return (Right1Pressed()  && !Right2Pressed()); }
        bool OnlyRight2Pressed() { return (!Right1Pressed() && Right2Pressed()); }

        bool LeftPressed()  { return (Left1Pressed()  || Left2Pressed()); }
        bool RightPressed() { return (Right1Pressed() || Right2Pressed()); }

        bool OnlyLeftPressed()     { return (!RightPressed() && LeftPressed()); }
        bool OnlyRightPressed()    { return (RightPressed()  && !LeftPressed()); }
        bool RightAndLeftPressed() { return (RightPressed()  && LeftPressed()); }
        bool NothingPressed()      { return !(RightPressed() || LeftPressed()); }

        bool PressedNoLock( int key ) { return (Pressed( key ) && !KeyLock( key )); }

        bool Left1PressedNoLock()  { return (Left1Pressed()  && !Left1Lock()); }
        bool Left2PressedNoLock()  { return (Left2Pressed()  && !Left2Lock()); }
        bool Right1PressedNoLock() { return (Right1Pressed() && !Right1Lock()); }
        bool Right2PressedNoLock() { return (Right2Pressed() && !Right2Lock()); }

        bool EscapePressed()   { return Pressed( keyboard.Escape ); }
        bool SettingsPressed() { return ((PressedNoLock( keyboard.LCtrl ) || PressedNoLock( keyboard.RCtrl )) && PressedNoLock( keyboard.S )); }

        void LockSettings() { SetKeyLock( keyboard.S, true ); }

        float MousePosX() { return unsize<float>(mouse.pos.x); }
        float MousePosY() { return unsize<float>(mouse.pos.y); }

        int MouseLeft()  { return mouse.Left; }
        int MouseRight() { return mouse.Right; }

        bool MouseInRect( Rect _dest )
        {
            return MouseInRect( _dest.x, _dest.y, _dest.w, _dest.h );
        }

        bool MouseInRect( float x, float y, float w, float h )
        {
            if( (MousePosX() > x) && (MousePosX() < (x + w))
             && (MousePosY() > y) && (MousePosY() < (y + h)) )
            {
                return 1;
            }

            return 0;
        }

        float WheelMovementY() { return mouse.wheel.y; }
        float WheelMovementX() { return mouse.wheel.x; }
    };

    extern InputManager *inputManager;

}