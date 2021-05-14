#include "GameMenu.h"
#include "Highscore.h"
#include <chrono>
#include <thread>

bool quit1 = false;

void loadHighScore()
{
    SDL_Color textColor = { 255, 255, 255 };

    getHighscoreE();
    getHighscoreM();
    getHighscoreH();

    for(int i = 0; i < 12; i++)
    {
        gTextTextureE[i].loadFromRenderedText( highscoreE[i], textColor, gFontHighScore );
        gTextTextureM[i].loadFromRenderedText( highscoreM[i], textColor, gFontHighScore );
        gTextTextureH[i].loadFromRenderedText( highscoreH[i], textColor, gFontHighScore );
    }
}

void count_time(int test_time)
{
    while (!gameOver && !isWinning && !quit1)
    {

        SDL_Delay(1000);
        ++test_time;
        globalTime = test_time;
    }
}

void startGame(bool &quit )
{
    quit = false;
    int ok = 0;
    int prev = 0;
    playAgain = false;
    statusHighscore = false;
    SDL_Event e;
    loadHighScore();
    gButtonNewGameMenu.render(0, 0);
    bool saveRender = true;
    Mix_PlayMusic(theme_ost, 1);
    while( !quit )
    {
        while( SDL_PollEvent( &e ) != 0 )
        {

            //User requests quit
            if( e.type == SDL_QUIT )
            {
                Mix_PlayChannel(-1, click, 0);
                quit = true;
                return;
            }

            //Handle button events
            switch(ok)
            {
            case 0:

                if(gButtons_.handleEvent_(&e, 203, 210, 437, 282))
                {
                    SDL_RenderClear( gRenderer );
                    Mix_PlayChannel(-1, click, 0);
                    gButtonHighScoreName.render(0,0);
                    saveRender = true;
                    SDL_StartTextInput();
                    ok = 1 ;
                    prev = 1;

                }
                else if (gButtons_.handleEvent_(&e, 203, 354, 437, 426))
                {
                    SDL_RenderClear( gRenderer );
                    Mix_PlayChannel(-1, click, 0);
                    gButtonHighscoreDiff.render(0, 0);
                    ok = 1;
                    prev = 2;

                }
                else if (gButtons_.handleEvent_(&e, 203, 480, 437, 552))
                {
                    Mix_PlayChannel(-1, click, 0);
                    SDL_Delay(80);
                    quit = true;
                    return;
                }
                break;
            case 1:

                if( prev == 1 )
                {
                    if( gButtons_.handleEvent_(&e, 43, 583, 163, 610) )
                    {
                        SDL_RenderClear( gRenderer );
                        Mix_PlayChannel(-1, click, 0);
                        ok = 0;
                        gButtonNewGameMenu.render(0, 0);
                        SDL_StopTextInput();
                    }

                    else if((e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN) || gButtons_.handleEvent_(&e, 476, 580, 604, 611) )
                    {
                        Mix_PlayChannel(-1, click, 0);
                        ok = 2;
                        gButtonDifficult.render(0, 0);
                        prev = 1;
                        SDL_StopTextInput();
                    }
                    else if ( e.type == SDL_TEXTINPUT )
                    {

                        if (input.size() < 15)
                        {
                            input += e.text.text;
                            saveRender = true;
                        }
                    }
                    else
                    {
                        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_BACKSPACE && input.size()>1 )
                        {
                            input.pop_back();
                            saveRender = true;
                        }
                    }
                    if (saveRender)
                    {
                        Mix_PlayChannel(-1, click, 0);
                        SDL_Color textColor = { 0, 0, 0 };
                        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                        SDL_RenderClear( gRenderer );
                        gButtonHighScoreName.render(0,0);
                        gTexTureInputName.loadFromRenderedText( input, textColor, gFontNameInput);
                        gTexTureInputName.render(100,240);
                        saveRender = false;
                    }
                }

                else if( prev == 2 )
                {
                    if (gButtons_.handleEvent_(&e, 51, 584, 169, 611))
                    {
                        SDL_RenderClear( gRenderer );
                        Mix_PlayChannel(-1, click, 0);
                        ok = 0;
                        gButtonNewGameMenu.render(0, 0);
                    }

                    else if(gButtons_.handleEvent_(&e, 200, 182, 439, 243))
                    {
                        SDL_RenderClear( gRenderer );
                        Mix_PlayChannel(-1, click, 0);
                        ok = 2;
                        prev = 2;
                        gButtonHighScore.render(0, 0);
                        renderTextHighScoreE();
                    }
                    else if(gButtons_.handleEvent_(&e, 200, 318, 439, 379))
                    {
                        SDL_RenderClear( gRenderer );
                        Mix_PlayChannel(-1, click, 0);
                        ok = 2;
                        prev = 2;
                        gButtonHighScore.render(0, 0);
                        renderTextHighScoreM();
                    }
                    else if( gButtons_.handleEvent_(&e, 200, 448, 439, 510) )
                    {
                        SDL_RenderClear( gRenderer );
                        Mix_PlayChannel(-1, click, 0);
                        ok = 2;
                        prev = 2;
                        gButtonHighScore.render(0, 0);
                        renderTextHighScoreH();
                    }
                }

                break;
            case 2:

                if( prev == 1 )
                {

                    if( gButtons_.handleEvent_(&e, 51, 584, 169, 611) )
                    {
                        SDL_RenderClear( gRenderer );
                        Mix_PlayChannel(-1, click, 0);
                        ok = 1;
                        saveRender = true;
                        SDL_StartTextInput();
                        gButtonHighScoreName.render(0, 0);

                    }
                    //easy
                    else if ( gButtons_.handleEvent_(&e, 200, 182, 439, 243))
                    {
                        Mix_PlayChannel(-1, click, 0);
                        diff = 0;
                        mineCount = 10;
                        countMineLeft = mineCount;
                        ok = 3;
                    }
                    //medium
                    else if ( gButtons_.handleEvent_(&e, 200, 318, 439, 379) )
                    {
                        Mix_PlayChannel(-1, click, 0);
                        diff = 1;
                        mineCount = 15;
                        countMineLeft = mineCount;
                        ok = 3;
                    }
                    //hard
                    else if ( gButtons_.handleEvent_(&e, 200, 448, 439, 510) )
                    {
                        Mix_PlayChannel(-1, click, 0);
                        diff = 2;
                        mineCount = 20;
                        countMineLeft = mineCount;
                        ok = 3;
                    }
                }

                else if ( prev == 2 )
                {
                    if( gButtons_.handleEvent_(&e, 42, 576, 158, 602) )
                    {
                        SDL_RenderClear( gRenderer );
                        Mix_PlayChannel(-1, click, 0);
                        ok = 1;
                        gButtonHighscoreDiff.render(0, 0);

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
    thread highscore(count_time, 0);
    globalTime = 0;
    Mix_HaltMusic( );
    while( !quit )
    {
        createTableWithMine();
        while ( !gameOver && !quit && !isWinning)
        {

            while( SDL_PollEvent( &e ) != 0 )
            {
                if( e.type == SDL_QUIT )
                {
                    quit = true;
                    quit1 = true;
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

            SDL_Color textColor = { 255, 255, 255 };
            timeOutput = "Time: " + convertTime(globalTime);
            if( !gTimeOutput.loadFromRenderedText( timeOutput, textColor, gFontNameInput ) )
            {
                cout << "Unable to render mine left texture!\n";
            }
            gTimeOutput.render( 430, 0 );
            mineManager();
            if ( !gameOver && isWinning)
            {
                switch(diff)
                {
                case 0:
                    processHighscoreE();
                    break;
                case 1:
                    processHighscoreM();
                    break;
                case 2:
                    processHighscoreH();
                    break;
                }
            }
            flagManager();
            SDL_RenderPresent( gRenderer );

        }
        playAgainManager( quit );

        if(playAgain) break;
    }
    highscore.join();
}
