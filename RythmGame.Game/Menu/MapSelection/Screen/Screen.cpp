#include "Screen.h"

namespace RythmGame::Game::Menu::MapSelection
{

    Screen::Screen()
    {
        background = new Image(
            "assets/Skins/BaseSkin/Menu/MapSelection/background.png",
            {0, 0, 1920, 1080},
            {Default::WIDTH/2, Default::HEIGHT/2, Default::WIDTH, Default::HEIGHT}
        );

        for( const auto &entry : std::filesystem::directory_iterator( "assets/Maps" ) )
        {
            songs.push_back(
                new SongTile(
                    entry.path()
                )
            );
        }
    }

    Screen::~Screen()
    {
    }

    void Screen::Draw()
    {
        background->Draw();

        for( SongTile *song : songs )
        {
            song->Draw( 2 );
        }
    }

// returns Song * if a SongTile is LeftClicked
// else returns 0
    Song *Screen::Update()
    {
        for( SongTile *song : songs )
        {
            song->GetSong()->GetBackground()->Hoover();
            if( song->GetSong()->GetBackground()->IsLeftClicked() )
            {
                return song->GetSong();
            }
        }

        return 0;
    }
}