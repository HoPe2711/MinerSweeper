#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <sstream>
#include <string>
#include "Variables.h"
#include "Constructor.h"
#include "GamePlay.h"
#include "GameMenu.h"
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
            startGame();
        }
    }

    close();
    return 0;
}




