#include "GamePlay.h"
#include <ctime>

void createTableWithMine ()
{
    srand(time(NULL));
    int mine = 0;
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < columnSize; j++)
        {
            sBoard[i][j] = 10;
            board[i][j] = 0;
        }
    }
    while (mine < mineCount)
    {
        int i = rand() % rowSize;
        int j = rand() % columnSize;
        if ( board[i][j] == 0 )
        {
            mine ++;
            board[i][j]=9;
        }

    }
    for (int i=0; i<rowSize; i++)
        for (int j=0; j<columnSize; j++)
            if (board[i][j]==9)
            for (int k=0; k<8; k++){
                    int u = i + directionx[k];
                    int v = j + directiony[k];
                    if (u<rowSize && v<columnSize && u>=0 && v>=0 && board[u][v]!=9) ++board[u][v];
                }
}

bool checkWinning ()
{
    bool win = false;
    if (countTileLeft == mineCount)
    {
        win = true;
    }
    return win;
}

void mineManager()
{
    if ( !gameOver && !isWinning )
    {
        SDL_Color textColor = { 140, 140, 140, 255 };
        mineLeft.str ( "" );
        mineLeft << "Mine left: " << countMineLeft;
        if( !gMineLeftTexture.loadFromRenderedText( mineLeft.str().c_str(), textColor ) )
        {
            cout << "Unable to render mine left texture!\n";
        }
        gMineLeftTexture.render( ( SCREEN_WIDTH - gMineLeftTexture.getWidth() ) / 2, 0 );
    }
}

string convertTime(int time){
    int minute = time / 60;
    int sec = time % 60;
    string Stime = "";
    if(sec < 10)
    {
        Stime = to_string(minute) + ":0" + to_string(sec);
    }
    else
    {
        Stime = to_string(minute) + ":" + to_string(sec);
    }

    return Stime;
}

void flagManager()
{
    if ( isWinning && !gameOver)
    {
        ofstream outfileE("outfileE.txt", std::ios::app);
        string testtime = "1:00"; int test_time = 60;
        outfileE << testtime << " " << test_time << endl;
        outfileE.close();

        SDL_RenderPresent( gRenderer );
        SDL_Delay(500);
        Mix_PlayMusic(winner, 0);
        gWinningTexture.render( 0, 0 , &stretchRect );
        //gPlayAgainWinTexture.render( ( SCREEN_WIDTH - gPlayAgainWinTexture.getWidth() ) / 2, SCREEN_HEIGHT - gPlayAgainWinTexture.getHeight() );

        //nhap vao highscore


    }

    if ( gameOver )
    {
        gTextTexture.render( ( SCREEN_WIDTH - gTextTexture.getWidth() ) / 2, 0 );
        Mix_PlayMusic(loser, 0);
        for( int i = 0; i < rowSize; i++ )
        {
            for ( int j = 0; j < columnSize; j++ )
            {
                sBoard[i][j] = board[i][j];
                gButtons[i][j].render(i, j);
            }
        }
        //gPlayAgainLoseTexture.render( ( SCREEN_WIDTH - gPlayAgainLoseTextu    re.getWidth() ) / 2, SCREEN_HEIGHT - gPlayAgainLoseTexture.getHeight() );
        SDL_RenderPresent( gRenderer );
        SDL_Delay(3000);
        gButtonGameOver.render(0, 0);
    }
}

void playAgainManager(bool &quitGame)
{
    SDL_Event e;
    while( SDL_PollEvent( &e ) != 0 )
    {
        if( gButtons_.handleEvent_(&e, 228, 458, 412, 479) )
        {
            Mix_HaltMusic();
            countMineLeft = mineCount;
            countTileLeft = rowSize * columnSize;
            gameOver = false;
            isWinning = false;
            quitGame = false;
            playAgain = true;
        }
        else if ( e.key.keysym.sym == SDLK_ESCAPE || e.type == SDL_QUIT ) quitGame = true;
    }
}
