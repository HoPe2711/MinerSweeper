#include "Highscore.h"

void getHighscoreE()
{
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

    fileE.close();
}

void getHighscoreM()
{
    ifstream fileM( "Highscore/medium.txt");
    if(!fileM)
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

    fileM.close();
}

void getHighscoreH()
{
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

    fileH.close();
}

void renderTextHighScoreE()
{
    gTextTextureE[0].render(xNamePos, yPos0);
    gTextTextureE[1].render(xTimePos, yPos0);
    gTextTextureE[2].render(xNamePos, yPos1);
    gTextTextureE[3].render(xTimePos, yPos1);
    gTextTextureE[4].render(xNamePos, yPos2);
    gTextTextureE[5].render(xTimePos, yPos2);
    gTextTextureE[6].render(xNamePos, yPos3);
    gTextTextureE[7].render(xTimePos, yPos3);
    gTextTextureE[8].render(xNamePos, yPos4);
    gTextTextureE[9].render(xTimePos, yPos4);
    gTextTextureE[10].render(xNamePos, yPos5);
    gTextTextureE[11].render(xTimePos, yPos5);
}

void renderTextHighScoreM()
{
    gTextTextureM[0].render(xNamePos, yPos0);
    gTextTextureM[1].render(xTimePos, yPos0);
    gTextTextureM[2].render(xNamePos, yPos1);
    gTextTextureM[3].render(xTimePos, yPos1);
    gTextTextureM[4].render(xNamePos, yPos2);
    gTextTextureM[5].render(xTimePos, yPos2);
    gTextTextureM[6].render(xNamePos, yPos3);
    gTextTextureM[7].render(xTimePos, yPos3);
    gTextTextureM[8].render(xNamePos, yPos4);
    gTextTextureM[9].render(xTimePos, yPos4);
    gTextTextureM[10].render(xNamePos, yPos5);
    gTextTextureM[11].render(xTimePos, yPos5);
}

void renderTextHighScoreH()
{
    gTextTextureH[0].render(xNamePos, yPos0);
    gTextTextureH[1].render(xTimePos, yPos0);
    gTextTextureH[2].render(xNamePos, yPos1);
    gTextTextureH[3].render(xTimePos, yPos1);
    gTextTextureH[4].render(xNamePos, yPos2);
    gTextTextureH[5].render(xTimePos, yPos2);
    gTextTextureH[6].render(xNamePos, yPos3);
    gTextTextureH[7].render(xTimePos, yPos3);
    gTextTextureH[8].render(xNamePos, yPos4);
    gTextTextureH[9].render(xTimePos, yPos4);
    gTextTextureH[10].render(xNamePos, yPos5);
    gTextTextureH[11].render(xTimePos, yPos5);
}
