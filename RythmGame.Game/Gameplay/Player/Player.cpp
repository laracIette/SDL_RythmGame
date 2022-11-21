#include "Player.h"

namespace RythmGame::Game::Gameplay
{

    Player::Player()
    {
        for( int i{ 0 }; i < nIMAGES; ++i )
        {
            images[i] = new Image(
                "assets/Skins/BaseSkin/Player/Player" + std::to_string( i ) + ".png",
                getRectPointer(1920/2, 1080/2, 120, 120)
            );
        }
    }
    Player::~Player()
    {
    }

    void Player::Input()
    {
        for( bool &b : isImageShown ) b = false;

        if( !inputManager.KeyLock( inputManager.flipKey ) && inputManager.Pressed( inputManager.flipKey ) )
        {
            inputManager.SetKeyLock( inputManager.flipKey, true );

            (isHorizontal) ? isHorizontal = false : isHorizontal = true;
        }


        (isHorizontal) ? isImageShown[HorizontalDefault] = true
                       : isImageShown[VerticalDefault] = true;



        if( inputManager.Left2Pressed() )
        {
            (isHorizontal) ? isImageShown[UpLeft] = true : isImageShown[UpRight] = true;
        }
        if( inputManager.Left1Pressed() )
        {
            (isHorizontal) ? isImageShown[DownLeft] = true : isImageShown[UpLeft] = true;
        }
        if( inputManager.Right1Pressed() )
        {
            (isHorizontal) ? isImageShown[UpRight] = true : isImageShown[DownLeft] = true;
        }
        if( inputManager.Right2Pressed() )
        {
            (isHorizontal) ? isImageShown[DownRight] = true : isImageShown[DownRight] = true;
        }

    }

    void Player::Draw()
    {
        for( int i{ 0 }; i < nIMAGES; ++i )
        {
            if( isImageShown[i] ) images[i]->Draw();
        }
    }

}