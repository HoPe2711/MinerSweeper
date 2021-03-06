#include "Variables.h"

void reveal(int i, int j)
{
    if (sBoard[i][j] == 10 || sBoard[i][j] == 11)
    {
        if (sBoard[i][j] == 11)
        {
            countMineLeft++;
        }
        sBoard[i][j] = board[i][j];
        countTileLeft--;
        if (sBoard[i][j] == 0)
        {
            for (int k=0; k<8; k++)
            {
                int u = i + directionx[k];
                int v = j + directiony[k];
                if (u<rowSize && v<columnSize && u>=0 && v>=0) reveal(u,v);
            }
        }
    }
}

LButton::LButton()
{
    mPosition.x = 0;
    mPosition.y = 0;
}

void LButton::setPosition( int x, int y )
{
    mPosition.x = x;
    mPosition.y = y;
}

void LButton::handleEvent( SDL_Event* e )
{
    if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
    {
        int x, y;
        SDL_GetMouseState( &x, &y );

        int i = (y - DISTANCE_BETWEEN)/TILE_SIZE;
        int j = (x - DISTANCE_BETWEEN)/TILE_SIZE;

        bool inside = true;

        if( x < mPosition.x )
        {
            inside = false;
        }
        else if( x > mPosition.x + TILE_SIZE )
        {
            inside = false;
        }
        else if( y < mPosition.y )
        {
            inside = false;
        }
        else if( y > mPosition.y + TILE_SIZE )
        {
            inside = false;
        }

        if ( inside )
        {
            if ( e->type == SDL_MOUSEBUTTONDOWN )
            {
                Mix_PlayChannel(-1, click, 0);
                switch ( e->button.button )
                {
                case SDL_BUTTON_LEFT:
                {
                    reveal(i, j);
                    if (board[i][j] == 9)
                    {
                        gameOver = true;
                    }
                    break;
                }
                case SDL_BUTTON_RIGHT:
                {
                    if (sBoard[i][j] >= 10)
                    {
                        if (sBoard[i][j] == 10)
                        {
                            if (countMineLeft == 0) break;
                            sBoard[i][j] = 11;
                            countMineLeft--;
                        }
                        else
                        {
                            sBoard[i][j] = 10;
                            countMineLeft++;
                        }
                    }
                    break;
                }
                }
            }
        }
    }
}

bool LButton::handleEvent_( SDL_Event* e, int a, int b, int w, int h )
{
    //If mouse event happened
    if( e->type == SDL_MOUSEBUTTONDOWN )
    {
        //Get mouse position
        int x, y;
        SDL_GetMouseState( &x, &y );

        //Check if mouse is in button
        bool inside = true;

        //Mouse is left of the button
        if( x < a )
        {
            inside = false;
        }
        //Mouse is right of the button
        else if( x > w )
        {
            inside = false;
        }
        //Mouse above the button
        else if( y < b )
        {
            inside = false;
        }
        //Mouse below the button
        else if( y > h )
        {
            inside = false;
        }

        //Mouse is outside button
        return inside;
    }

    return false;


}

void LButton::render(int i, int j)
{
    gButtonSpriteSheetTexture.render( mPosition.x, mPosition.y, &gSpriteClips[ sBoard[i][j] ] );
}
