#pragma once

#include <string>

#include "../Image.h"

namespace RythmGame::Graphics
{

    class ImageTopRight : public Image
    {

    public:
        ImageTopRight( std::string _path, Rect _dest, int _type, int _priority ) :
            Image(
                _path,
                _dest,
                _type,
                _priority
            )
        {}

        void Draw()
        {
            Image::Draw( {dest.x - dest.w*zoom, dest.y, dest.w*zoom, dest.h*zoom} );
        }


        void Hoover()
        {
            if( inputManager->MouseInRect( dest.x - dest.w*zoom, dest.y, dest.w*zoom, dest.h*zoom ) )
            {
                isHoover = true;
            }
            else
            {
                isHoover = false;
            }
        }

    };

}