#include "Highscore.h"

void getHighscoreE()
{
    fstream fileE;
    fileE.open(pathE, ios::in | ios::out);

    if(!fileE)
    {
        cout << "Can not open highscore data";
    }
    int countE = 0, i = 0, j = 0;
    while (!fileE.eof()){
        string line;
        int num;

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
    ifstream fileM(pathM);
    if(!fileM)
    {
        cout << "Can not open highscore data";
    }
    int countM = 0, i = 0, j = 0;
    while (!fileM.eof()){
        string line;
        int num;

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
    ifstream fileH(pathH);
    if(!fileH)
    {
        cout << "Can not open highscore data";
    }
    int countH = 0, i = 0, j = 0;
    while (!fileH.eof()){
        string line;
        int num;

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

int convertString(string str)
{
    int tempt = stoi(str);

    return tempt;
}

void processHighscoreE()
{
//    for(int i = 0; i < 6; i++)
//    {
//        if (globalTime < valueTimeE[i])
//        {
//            valueTimeE[i] = globalTime;
//        }
//    }

//    cout << globalTime << endl;

    fstream fileE;
    fileE.open(pathE, ios::in | ios::out);
    fileE.seekg(0);

    int j = 0, k = 0;
    for(int i = 0; i < 18; i++)
    {
        if (i % 3 != 2)
        {
            fileE << highscoreE[j] << endl;
            j++;
        }
        else
        {
            if (k != 5)
                fileE << 300 << endl;
            else
                fileE << 300;
            k++;
        }
    }

    fileE.close();
}

void processHighscoreM()
{
//    for(int i = 0; i < 6; i++)
//    {
//        if (globalTime < valueTimeE[i])
//        {
//            valueTimeM[i] = globalTime;
//        }
//    }

//    cout << globalTime << endl;

    fstream fileM;
    fileM.open(pathM, ios::in| ios::out);
    fileM.seekg(0);

    int j = 0, k = 0;
    for(int i = 0; i < 18; i++)
    {
        if (i % 3 != 2)
        {
            fileM << highscoreM[j] << endl;
            j++;
        }
        else
        {
            if (k != 5)
                fileM << 300 << endl;
            else
                fileM << 300;
            k++;
        }
    }

    fileM.close();
}

void processHighscoreH()
{
//    for(int i = 0; i < 6; i++)
//    {
//        if (globalTime < valueTimeE[i])
//        {
//            valueTimeH[i] = globalTime;
//        }
//    }

//    cout << globalTime << endl;

    fstream fileH;
    fileH.open(pathH, ios::in| ios::out);
    fileH.seekg(0);

    int j = 0, k = 0;
    for(int i = 0; i < 18; i++)
    {
        if (i % 3 != 2)
        {
            fileH << highscoreH[j] << endl;
            j++;
        }
        else
        {
            if (k != 5)
                fileH << 300 << endl;
            else
                fileH << 300;
            k++;
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
