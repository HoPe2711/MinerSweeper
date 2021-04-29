#pragma once

#include "Texture.h"
#include "Button.h"
#include "thread"

const int TILE_SIZE = 32;
const int BUTTON_SPRITE_TOTAL = 12;
const int rowSize = 10;
const int columnSize = 10;
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;
const int xNamePos = 130;
const int xTimePos = 435;
const int yPos0 = 220-25;
const int yPos1 = 277-25;
const int yPos2 = 334-25;
const int yPos3 = 390-25;
const int yPos4 = 447-25;
const int yPos5 = 505-25;
const int DISTANCE_BETWEEN = (SCREEN_WIDTH - rowSize * TILE_SIZE) / 2;
const int directionx[8]={0,-1,1,0,1,-1,-1,1};
const int directiony[8]={-1,0,0,1,1,-1,1,-1};

const string pathE = "Highscore/easy.txt";
const string pathM = "Highscore/medium.txt";
const string pathH = "Highscore/hard.txt";
