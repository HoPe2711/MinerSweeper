#include "Constructor.h"

bool init()
{
    bool success = true;
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
    {
        cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << endl;
        success = false;
    }
    else
    {
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            cout << "Warning: Linear texture filtering not enabled!";
        }
        gWindow = SDL_CreateWindow( "Minesweeper", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            cout << "Window could not be created! SDL Error: " << SDL_GetError() << endl;
            success = false;
        }
        else
        {
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( gRenderer == NULL )
            {
                cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << endl;
                success = false;
            }
            else
            {
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
                    success = false;
                }
                if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
                {
                    cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << endl;
                    success = false;
                }
                if( TTF_Init() == -1 )
                {
                    cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << endl;
                    success = false;
                }
            }
        }
    }

    return success;
}


bool loadMedia()
{
    bool success = true;

    gGameOver = TTF_OpenFont( "Font/DTM-Sans.ttf", 40 );
    if( gGameOver == NULL )
    {
        cout << "Failed to load DTM-Sans font! SDL_ttf Error: " << TTF_GetError() << endl;
        success = false;
    }
    else
    {
        SDL_Color textColor = { 140, 140, 140 };
        if( !gTextTexture.loadFromRenderedText( "GAME OVER :(", textColor ) )
        {
            cout << "Failed to render text texture!\n";
            success = false;
        }
    }

    gPlayAgainWin = TTF_OpenFont( "Font/DTM-Sans.ttf", 40 );
    if( gPlayAgainWin == NULL )
    {
        cout << "Failed to load DTM-Sans font! SDL_ttf Error: " << TTF_GetError() << endl;
        success = false;
    }
    else
    {
        SDL_Color playAgainWin = { 255, 255, 255 };
        if( !gPlayAgainWinTexture.loadFromRenderedText( "Press s to play again!", playAgainWin ) )
        {
            cout << "Failed to render text texture!\n";
            success = false;
        }
    }

    gPlayAgainLose = TTF_OpenFont( "Font/DTM-Sans.ttf", 40 );
    if( gPlayAgainLose == NULL )
    {
        cout << "Failed to load DTM-Sans font! SDL_ttf Error: " << TTF_GetError() << endl;
        success = false;
    }
    else
    {
        SDL_Color playAgainLose = { 140, 140, 140 };
        if( !gPlayAgainLoseTexture.loadFromRenderedText( "Press s to play again!", playAgainLose ) )
        {
            cout << "Failed to render text texture!\n";
            success = false;
        }
    }

    if( !gButtonNewGameMenu.loadFromFile( "Image/MenuNewgame.jpg" ) )
	{
		printf( "Failed to load button sprite texture!\n" );
		success = false;
	}
	if( !gButtonBackground.loadFromFile( "Image/background.jpg" )) {
        printf( "Failed to load button menu\n ");
        success = false;
	}

	if( !gButtonHighScore.loadFromFile( "Image/highscore.jpg" )) {
        printf( "Failed to load button menu\n ");
        success = false;
	}

	if( !gButtonHighScoreName.loadFromFile( "Image/name.jpg" )) {
        printf( "Failed to load button menu\n ");
        success = false;
	}

	if( !gButtonDifficult.loadFromFile( "Image/difficulty.jpg" )) {
        printf( "Failed to load button menu\n ");
        success = false;
	}

    if ( !gWinningTexture.loadFromFile( "Image/Winner.png" ) )
    {
        cout << "Failed to load winning texture!\n";
        success = false;
    }

    if ( !gBackgroundTexture.loadFromFile( "Image/background.jpg" ) )
    {
        cout << "Failed to load background texture!\n";
        success = false;
    }

    if ( !gButtonGameOver.loadFromFile( "Image/gameover.jpg" ) )
    {
        cout << "Failed to load background texture!\n";
        success = false;
    }

    if( !gButtonSpriteSheetTexture.loadFromFile( "Image/Tiles.png" ) )
    {
        cout << "Failed to load sprites texture!\n";
        success = false;
    }
    else
    {
        for( int i = 0; i < BUTTON_SPRITE_TOTAL; i++ )
        {
            gSpriteClips[ i ].x = i * 32;
            gSpriteClips[ i ].y = 0;
            gSpriteClips[ i ].w = TILE_SIZE;
            gSpriteClips[ i ].h = TILE_SIZE;
        }
        for (int i = 0; i < rowSize; i++)
        {
            for (int j = 0; j < columnSize; j++)
            {
                gButtons[i][j].setPosition(j * TILE_SIZE + DISTANCE_BETWEEN, i * TILE_SIZE + DISTANCE_BETWEEN);
            }
        }
    }

    winner = Mix_LoadMUS( "Sounds/winner.wav" );
    if( winner == NULL )
    {
        cout << "Failed to load winner sound effect! SDL_mixer Error: " << Mix_GetError() << endl;
        success = false;
    }

    loser = Mix_LoadMUS( "Sounds/loser.wav" );
    if( loser == NULL )
    {
        cout << "Failed to load loser sound effect! SDL_mixer Error: " << Mix_GetError() << endl;
        success = false;
    }

    click = Mix_LoadWAV( "Sounds/click.wav" );
    if( click == NULL )
    {
        cout << "Failed to load click sound effect! SDL_mixer Error: " << Mix_GetError() << endl;
        success = false;
    }

    return success;
}

void close()
{
    gButtonSpriteSheetTexture.free();
    gMineLeftTexture.free();
    gBackgroundTexture.free();
    gWinningTexture.free();
    gTextTexture.free();

    TTF_CloseFont( gGameOver );
    TTF_CloseFont( gPlayAgainLose );
    TTF_CloseFont( gPlayAgainWin );
    gGameOver = NULL;
    gPlayAgainLose = NULL;
    gPlayAgainWin = NULL;

    Mix_FreeMusic( winner );
    Mix_FreeMusic( loser );
    Mix_FreeChunk( click );
    winner = NULL;
    loser = NULL;
    click = NULL;

    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}
