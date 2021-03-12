#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <sstream>
#include <string>
#include "Variables.h"
#include "Constructor.h"
#include "GamePlay.h"

int main(int argc, char* argv[])
{
    if( !init() )
    {
        cout << "Failed to initialize!\n";
    }
    else
    {
        if( !loadMedia() )
        {
            cout << "Failed to load media!\n";
        }
        else
        {
            bool quit = false;
            SDL_Event e;
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
    }
    close();
    return 0;
}




