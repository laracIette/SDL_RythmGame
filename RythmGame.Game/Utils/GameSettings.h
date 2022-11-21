#pragma once

#include <SDL_ttf.h>

#define White (RGB){255, 255, 255}
#define Black (RGB){  0,   0,   0}
#define Red   (RGB){255,   0, 255}
#define Green (RGB){  0, 255,   0}
#define Blue  (RGB){  0,   0, 255}


namespace RythmGame::Game::Utils
{

    struct RGB
    {
        unsigned char r, g, b;

        inline RGB operator+( RGB a )
        {
            return {(unsigned char)(r+a.r), (unsigned char)(g+a.g), (unsigned char)(b+a.b)};
        }
        inline RGB operator-( RGB a )
        {
            return {(unsigned char)(r-a.r), (unsigned char)(g-a.g), (unsigned char)(b-a.b)};
        }
        inline RGB operator/( int n )
        {
            return {(unsigned char)(r/n), (unsigned char)(g/n), (unsigned char)(b/n)};
        }
    };

    extern float velocity;
    extern bool isHorizontal;

    template<typename T>
    static RGB getSongDifficultyColor( T diff )
    {
        RGB ret = Black;

        if     ( diff <= 1 ) ret = White;
        else if( diff <= 2 ) ret = (White + Green)/2;
        else if( diff <= 3 ) ret = Green;
        else if( diff <= 4 ) ret = (Green + Blue)/2;
        else if( diff <= 5 ) ret = Blue;
        else if( diff <= 6 ) ret = (Blue + Red)/2;
        else if( diff <= 7 ) ret = Red;
        else if( diff <= 8 ) ret = (Red + Black)/2;

        return ret;
    }

    extern TTF_Font *police;
}