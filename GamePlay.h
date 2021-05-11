#pragma once

#include "Variables.h"
#include "Highscore.h"

void createTableWithMine();
bool checkWinning();
void mineManager();
void flagManager();
void playAgainManager(bool &quitGame);
void printNewhighscore();
void renderWinningscreen();
