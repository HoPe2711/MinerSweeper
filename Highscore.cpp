#include "Highscore.h"

string convertTime(int time)
{
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

void getHighscoreE()
{
    fstream fileE;
    fileE.open(pathE, ios::in);
    if(!fileE)
    {
        cout << "Can not open highscore data";
    }
    int countE = 0, i = 0, j = 0;
    while (!fileE.eof())
    {
        string line;
        int num;
        if (countE == 18) break;
        if (fileE)
        {
            if (countE % 3 != 2)
            {
                getline(fileE, line);
                highscoreE[j] = line;
                j++;
            }
            else
            {
                fileE >> num;
                valueTimeE[i] = num;
                fileE.ignore(1);
                i++;
            }
            countE++;
        }
    }
    fileE.close();
}

void getHighscoreM()
{
    fstream fileM;
    fileM.open(pathM, ios::in);
    if(!fileM)
    {
        cout << "Can not open highscore data";
    }
    int countM = 0, i = 0, j = 0;
    while (!fileM.eof())
    {
        string line;
        int num;
        if (countM == 18) break;
        if (fileM)
        {
            if (countM % 3 != 2)
            {
                getline(fileM, line);
                highscoreM[j] = line;
                j++;
            }
            else
            {
                fileM >> num;
                valueTimeM[i] = num;
                fileM.ignore(1);
                i++;
            }
            countM++;
        }
    }
    fileM.close();
}

void getHighscoreH()
{
    fstream fileH;
    fileH.open(pathH, ios::in);
    if(!fileH)
    {
        cout << "Can not open highscore data";
    }
    int countH = 0, i = 0, j = 0;
    while (!fileH.eof())
    {
        string line;
        int num;
        if (countH == 18) break;
        if (fileH)
        {
            if (countH % 3 != 2)
            {
                getline(fileH, line);
                highscoreH[j] = line;
                j++;
            }
            else
            {
                fileH >> num;
                valueTimeH[i] = num;
                fileH.ignore(1);
                i++;
            }
            countH++;
        }
    }
    fileH.close();
}

void processHighscoreE()
{
    int pos = 6;
    for(int i = 0; i < 6; i++)
    {
        if (globalTime < valueTimeE[i])
        {
            pos = i;
            statusHighscore = true;
            break;
        }
    }

    fstream fileE;
    fileE.open(pathE, ios::out);
    fileE.seekg(0);

    for (int i=0; i<pos; i++)
    {
        fileE << highscoreE[i*2] << endl << highscoreE[i*2+1] << endl;
        fileE << valueTimeE[i] << endl;
    }

    fileE << input << endl << convertTime(globalTime) << endl;
    fileE << globalTime << endl;

    for (int i=pos; i<5; i++)
    {
        fileE << highscoreE[i*2] << endl << highscoreE[i*2+1] << endl;
        fileE << valueTimeE[i] << endl;
    }
    for(int i = 0; i < 12; i++)
    {
        gTextTextureE[i].free();
    }

    fileE.close();
}

void processHighscoreM()
{
    int pos = 6;
    for(int i = 0; i < 6; i++)
    {
        if (globalTime < valueTimeM[i])
        {
            pos = i;
            statusHighscore = true;
            break;
        }
    }

    fstream fileM;
    fileM.open(pathM, ios::out);
    fileM.seekg(0);

    for (int i=0; i<pos; i++)
    {
        fileM << highscoreM[i*2] << endl << highscoreM[i*2+1] << endl;
        fileM << valueTimeM[i] << endl;
    }

    fileM << input << endl << convertTime(globalTime) << endl;
    fileM << globalTime << endl;

    for (int i=pos; i<5; i++)
    {
        fileM << highscoreM[i*2] << endl << highscoreM[i*2+1] << endl;
        fileM << valueTimeM[i] << endl;
    }
    for(int i = 0; i < 12; i++)
    {
        gTextTextureM[i].free();
    }

    fileM.close();
}

void processHighscoreH()
{
    int pos = 6;
    for(int i = 0; i < 6; i++)
    {
        if (globalTime < valueTimeH[i])
        {
            pos = i;
            statusHighscore = true;
            break;
        }
    }

    fstream fileH;
    fileH.open(pathH, ios::out);
    fileH.seekg(0);

    for (int i=0; i<pos; i++)
    {
        fileH << highscoreH[i*2] << endl << highscoreH[i*2+1] << endl;
        fileH << valueTimeH[i] << endl;
    }

    fileH << input << endl << convertTime(globalTime) << endl;
    fileH << globalTime << endl;

    for (int i=pos; i<5; i++)
    {
        fileH << highscoreH[i*2] << endl << highscoreH[i*2+1] << endl;
        fileH << valueTimeH[i] << endl;
    }
    for(int i = 0; i < 12; i++)
    {
        gTextTextureH[i].free();
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
