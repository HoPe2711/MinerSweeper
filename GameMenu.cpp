#include "GameMenu.h"
void startGame()
{

    bool quit = false;
    int ok = 0;
    int prev = 0;
    SDL_Event e;

    gButtonNewGameMenu.render(0, 0);

    while( !quit )
    {
        while( SDL_PollEvent( &e ) != 0 )
        {

            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }

            //Handle button events
            switch(ok)
            {
            case 0:
                if(gButtons_.handleEvent_(&e, 203, 210, 437, 282))
                {
                    //gButtonBackground.render(0, 0);
                    gButtonHighScoreName.render(0,0);
                    //gButtonMenu.render(150, 150);
                    ok = 1 ;
                    prev = 1;
                }
                else if (gButtons_.handleEvent_(&e, 203, 354, 437, 426))
                {
                    gButtonHighScore.render(0, 0);

                    ok = 1;
                    prev = 2;
                }
                else if (gButtons_.handleEvent_(&e, 203, 480, 437, 552))
                {
                    quit = true;
                    ok = 1;
                    prev = 3;
                }
                break;
            case 1:
                if( prev == 1 )
                {
                    if( gButtons_.handleEvent_(&e, 43, 583, 163, 610) )
                    {
                        ok = 0;
                        gButtonNewGameMenu.render(0, 0);
                    }

                    if(gButtons_.handleEvent_(&e, 476, 580, 604, 611))
                    {
                        ok = 2;
                        gButtonDifficult.render(0, 0);
                        prev = 1;
                    }
                }

                if( prev == 2 )
                {
                    if (gButtons_.handleEvent_(&e, 42, 576, 158, 602))
                    {
                        ok = 0;
                        gButtonNewGameMenu.render(0, 0);
                    }
                }

                break;
            case 2:
                if( prev == 1 )
                {

                    if( gButtons_.handleEvent_(&e, 51, 584, 169, 611) )
                    {
                        ok = 1;
                        gButtonHighScoreName.render(0, 0);

                    }

                    if ( gButtons_.handleEvent_(&e, 200, 182, 439, 243)) {
                        mineCount = 10;
                        countMineLeft = mineCount;
                        ok = 3;
                    }

                    if ( gButtons_.handleEvent_(&e, 200, 318, 439, 379) ) {
                        mineCount = 15;
                        countMineLeft = mineCount;
                        ok = 3;
                    }

                    if ( gButtons_.handleEvent_(&e, 200, 448, 439, 510) ) {
                        mineCount = 20;
                        countMineLeft = mineCount;
                        ok = 3;
                    }
                }
                break;
            }
            SDL_RenderPresent( gRenderer );
            if( ok == 3 ) break;
        }
        if( ok == 3 ) break;
        SDL_RenderPresent( gRenderer );
    }
    while( !quit )
    {
        createTableWithMine();
        while ( !gameOver && !quit && !isWinning)
        {
            while( SDL_PollEvent( &e ) != 0 )
            {
                if( e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
                {
                    quit = true;
                }
                for (int i = 0; i < rowSize; i++)
                {
                    for (int j = 0; j < columnSize; j++)
                    {
                        gButtons[i][j].handleEvent( &e );
                    }
                }
                isWinning = checkWinning();
            }
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
            SDL_RenderClear( gRenderer );
            gBackgroundTexture.render(0, 0, &stretchRect);
            for( int i = 0; i < rowSize; i++ )
            {
                for ( int j = 0; j < columnSize; j++ )
                {
                    gButtons[i][j].render(i, j);
                }
            }
            mineManager();
            flagManager();
            SDL_RenderPresent( gRenderer );
        }
        playAgainManager( quit );
    }
}
