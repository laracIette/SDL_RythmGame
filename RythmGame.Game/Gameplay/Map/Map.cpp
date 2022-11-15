#include "Map.h"

namespace RythmGame::Game::Gameplay
{

    Map::Map( std::string path )
    {
        std::ifstream file( path + "easy.txt" );
        std::string temp;
        std::string nTemp;

        unsigned char nSteps;

        while( getline( file, temp ) )
        {
        // quick verification that this is not an empty line
            if( temp == "" ) continue;

            HitObject *hitObject;

            nSteps = 0;
            switch( temp[0] - '0' )
            {
            case NOTE:
            {
                hitObject = new Note();

                for( int i{ 4 }; i < temp.size(); ++i )
                {
                    if( (temp[i] != ';') )
                    {
                        nTemp += temp[i];
                    }
                    else
                    {
                        switch( nSteps )
                        {
                        case 0:
                            hitObject->time = std::stoi( nTemp );
                            break;

                        case 1:
                            hitObject->isUp = std::stoi( nTemp );
                            break;

                        default:
                            break;
                        }
                        nTemp.clear();
                        nSteps++;
                    }
                }
                break;
            }

            case HOLD:
            {
                hitObject = new Hold();

                for( int i{ 4 }; i < temp.size(); ++i )
                {
                    if( (temp[i] != ';') )
                    {
                        nTemp += temp[i];
                    }
                    else
                    {
                        switch( nSteps )
                        {
                        case 0:
                            hitObject->time = std::stoi( nTemp );
                            break;

                        case 1:
                            hitObject->isUp = std::stoi( nTemp );
                            break;

                        case 2:
                            hitObject->endTime = std::stoi( nTemp );
                            break;

                        default:
                            break;
                        }
                        nTemp.clear();
                        nSteps++;
                    }
                }
                break;
            }

            case DOUBLE:
            {
                hitObject = new Double();

                for( int i{ 4 }; i < temp.size(); ++i )
                {
                    if( (temp[i] != ';') )
                    {
                        nTemp += temp[i];
                    }
                    else
                    {
                        hitObject->time = std::stoi( nTemp );

                        nTemp.clear();
                    }
                }
                break;
            }

            case MASH:
            {
                hitObject = new Mash();

                for( int i{ 4 }; i < temp.size(); ++i )
                {
                    if( (temp[i] != ';') )
                    {
                        nTemp += temp[i];
                    }
                    else
                    {
                        switch( nSteps )
                        {
                        case 0:
                            hitObject->time = std::stoi( nTemp );
                            break;

                        case 1:
                            hitObject->endTime = std::stoi( nTemp );
                            break;

                        default:
                            break;
                        }
                        nTemp.clear();
                        nSteps++;
                    }
                }
                break;
            }

            case GHOST:
            {
                hitObject = new Ghost();

                for( int i{ 4 }; i < temp.size(); ++i )
                {
                    if( (temp[i] != ';') )
                    {
                        nTemp += temp[i];
                    }
                    else
                    {
                        switch( nSteps )
                        {
                        case 0:
                            hitObject->time = std::stoi( nTemp );
                            break;

                        case 1:
                            hitObject->isUp = std::stoi( nTemp );
                            break;

                        default:
                            break;
                        }
                        nTemp.clear();
                        nSteps++;
                    }
                }
                break;
            }

            case COIN:
            {
                hitObject = new Coin();

                for( int i{ 4 }; i < temp.size(); ++i )
                {
                    if( (temp[i] != ';') )
                    {
                        nTemp += temp[i];
                    }
                    else
                    {
                        switch( nSteps )
                        {
                        case 0:
                            hitObject->time = std::stoi( nTemp );
                            break;

                        case 1:
                            hitObject->isUp = std::stoi( nTemp );
                            break;

                        default:
                            break;
                        }
                        nTemp.clear();
                        nSteps++;
                    }
                }
                break;
            }

            case HAMMER:
            {
                hitObject = new Hammer();

                for( int i{ 4 }; i < temp.size(); ++i )
                {
                    if( (temp[i] != ';') )
                    {
                        nTemp += temp[i];
                    }
                    else
                    {
                        switch( nSteps )
                        {
                        case 0:
                            hitObject->time = std::stoi( nTemp );
                            break;

                        case 1:
                            hitObject->isUp = std::stoi( nTemp );
                            break;

                        default:
                            break;
                        }
                        nTemp.clear();
                        nSteps++;
                    }
                }
                break;
            }

            case CHAINSAW:
            {
                hitObject = new Chainsaw();

                for( int i{ 4 }; i < temp.size(); ++i )
                {
                    if( (temp[i] != ';') )
                    {
                        nTemp += temp[i];
                    }
                    else
                    {
                        switch( nSteps )
                        {
                        case 0:
                            hitObject->time = std::stoi( nTemp );
                            break;

                        case 1:
                            hitObject->isUp = std::stoi( nTemp );
                            break;

                        default:
                            break;
                        }
                        nTemp.clear();
                        nSteps++;
                    }
                }
                break;
            }

            default:
            /* create error type (maybe) */
                break;
            }

            hitObject->type      = temp[0]-'0';
            hitObject->direction = temp[2]-'0';

            hitObjects.push_back( hitObject );
        }

        file.close();

        for( HitObject *hitObject : hitObjects )
        {
            hitObject->Init();
        }

        isPaused = true;

        music = new Music( path + "song.mp3" );

        horizontalForeground = new Image(
            "assets/Skins/BaseSkin/foreground0.png",
            {0, 0, 1920, 1080},
            {(float)WIDTH/2, (float)HEIGHT/2, (float)WIDTH, (float)HEIGHT}
        );
        verticalForeground = new Image(
            "assets/Skins/BaseSkin/foreground1.png",
            {0, 0, 1920, 1080},
            {(float)WIDTH/2, (float)HEIGHT/2, (float)WIDTH, (float)HEIGHT}
        );

        score    = new Score( {(float)WIDTH, 0, 50, 60} );
        combo    = new Combo( {0, (float)HEIGHT, 50, 60} );
        accuracy = new Accuracy( {(float)WIDTH/2, 0, 50, 60} );

    }

    Map::~Map()
    {
    }

    void Map::Start()
    {
        isPaused = false;

        offsetTime = currentTime;

        for( unsigned int &acc : accuracyHits ) acc = 0;

        score->SetScore( 0 );
        combo->SetCombo( 0 );

        highestCombo = 0;

        music->SetVolume( 0 );
        music->Play();
    }

    void Map::Update()
    {
        if( isPaused ) return;

        int j{ 0 };
        for( int i{ 0 }; i < hitObjects.size(); ++i )
        {
            hitObjects[j]->Update();

            if( (hitObjects[j]->type == CHAINSAW) && hitObjects[j]->IsHit() )
            {
                combo->SetCombo( 0 );
                std::cout << "hit" << std::endl;
            }

            tempAcc = hitObjects[j]->GetHitValue();

            if( tempAcc == 0 )      score->AddScore( 300 );
            else if( tempAcc == 1 ) score->AddScore( 100 );
            else if( tempAcc == 2 ) score->AddScore( 50 );

            if( (tempAcc >= 0) && (tempAcc <= 3) && (hitObjects[j]->type != COIN) )
            {
                accuracyHits[tempAcc]++;
                combo->AddCombo();
            }
            else if( (tempAcc == 25) && (hitObjects[j]->type == COIN) )
            {
                score->AddScore( 25 );
            }
            else if( (tempAcc == 10) && (hitObjects[j]->type == MASH) )
            {
                score->AddScore( 10 );
            }

            if( hitObjects[j]->Erase() )
            {
                if( !hitObjects[j]->IsHit() && (hitObjects[j]->type != COIN) && (hitObjects[j]->type != CHAINSAW) )
                {
                    combo->SetCombo( 0 );
                    accuracyHits[3]++;
                }
                hitObjects.erase( hitObjects.begin() + j-- );
            }

            j++;

            if( combo->GetCombo() > highestCombo ) highestCombo = combo->GetCombo();
        }

        SetAccuracy();

    }

    void Map::Draw()
    {
        for( HitObject *hitObject : hitObjects )
        {
            hitObject->DrawHitObject();
        }

        (isHorizontal) ? horizontalForeground->Draw() : verticalForeground->Draw();

        score->Draw();
        combo->Draw();
        accuracy->Draw();
    }

    void Map::Pause()
    {
        if( !isPaused )
        {
            isPaused = true;
            pausedTime = currentTime;

            music->Pause();
        }
        else
        {
            isPaused = false;

            offsetTime += currentTime - pausedTime;


            music->Resume();
        }
    }

    void Map::Close()
    {
        music->Close();
    }

    void Map::SetAccuracy()
    {
        if( accuracyHits[0] + accuracyHits[1] + accuracyHits[2] + accuracyHits[3] == 0 )
            accuracy->SetAccuracy( 100 );

        else if( accuracyHits[0] + accuracyHits[1] + accuracyHits[2] == 0 )
            accuracy->SetAccuracy( 0 );

        else
            accuracy->SetAccuracy(
                100 *
                (float)(6*accuracyHits[0] + 2*accuracyHits[1] + accuracyHits[2]) /
                (float)(6*(accuracyHits[0] + accuracyHits[1] + accuracyHits[2] + accuracyHits[3]))
        );
    }

}