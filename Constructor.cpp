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

    // text highscore
    gFont = TTF_OpenFont( "Font/DTM-Sans.ttf", 28 );
	if( gFont == NULL )
	{
		printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
		success = false;
	}
	else
    {
        // highscore easy
        string highscoreE[12];
        ifstream fileE( "Highscore/easy.txt");
        if(!fileE)
        {
            cout << "Can not open highscore data";
        }
        int countE = 0;
        while (!fileE.eof()){
            string line;
            getline(fileE, line);
            if (fileE)
            {
                highscoreE[countE] = line;
                countE++;
            }
        }

        SDL_Color textColor = { 255, 255, 255 };
		for(int i = 0; i < 12; i++)
        {
            if( !gTextTextureE[i].loadFromRenderedText( highscoreE[i], textColor ) )
            {
                cerr << "Failed to render text texture!\n";
                success = false;
            }
        }

		// highscore medium
		string highscoreM[12];
        ifstream fileM( "Highscore/medium.txt");
        if( !fileM)
        {
            cout << "Can not open highscore data";
        }
        int countM = 0;
        while (!fileM.eof()){
            string line;
            getline(fileM, line);
            if (fileM)
            {
                highscoreM[countM] = line;
                countM++;
            }
        }

        for(int i = 0; i < 12; i++)
        {
            if( !gTextTextureM[i].loadFromRenderedText( highscoreM[i], textColor ) )
            {
                cerr << "Failed to render text texture!\n";
                success = false;
            }
        }

        // highscore hard
		string highscoreH[12];
        ifstream fileH( "Highscore/hard.txt");
        if(!fileH)
        {
            cout << "Can not open highscore data";
        }
        int countH = 0;
        while (!fileH.eof()){
            string line;
            getline(fileH, line);
            if (fileH)
            {
                highscoreH[countH] = line;
                countH++;
            }
        }

        for(int i = 0; i < 12; i++)
        {
            if( !gTextTextureH[i].loadFromRenderedText( highscoreH[i], textColor ) )
            {
                cerr << "Failed to render text texture!\n";
                success = false;
            }
        }
    }

    //

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
        printf( "Failed to load HighScore\n ");
        success = false;
	}

	if( !gButtonHighScoreName.loadFromFile( "Image/name.jpg" )) {
        printf( "Failed to load HighScoreName\n ");
        success = false;
	}

	if( !gButtonHighscoreDiff.loadFromFile( "Image/highscore_diff.jpg" )) {
        printf( "Failed to load HighScoreName\n ");
        success = false;
	}

	if( !gButtonDifficult.loadFromFile( "Image/difficulty.jpg" )) {
        printf( "Failed to load Diffcult\n ");
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
        cout << "Failed to load background GameOver!\n";
        success = false;
    }

    if( !gButtonSpriteSheetTexture.loadFromFile( "Image/Tiles.png" ) )
    {
        cout << "Failed to load Tiles!\n";
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
    gButtonBackground.free();
    gButtonDifficult.free();
    gButtonGameOver.free();
    gButtonHighScore.free();
    gButtonHighscoreDiff.free();
    gButtonHighScoreName.free();
    gButtonMenu.free();
    gButtonNewGameMenu.free();


    for(int i = 0; i < 12; i++)
    {
        gTextTextureE[i].free();
    }
    for(int i = 0; i < 12; i++)
    {
        gTextTextureM[i].free();
    }
    for(int i = 0; i < 12; i++)
    {
        gTextTextureH[i].free();
    }

    TTF_CloseFont( gGameOver );
    TTF_CloseFont( gPlayAgainLose );
    TTF_CloseFont( gPlayAgainWin );
    TTF_CloseFont( gFont );

    gGameOver = NULL;
    gPlayAgainLose = NULL;
    gPlayAgainWin = NULL;
    gFont = NULL;

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
