#pragma once

const int TILE_SIZE = 32;
const int BUTTON_SPRITE_TOTAL = 12;
const int mineCount = 10;
const int rowSize = 10;
const int columnSize = 10;
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;
const int DISTANCE_BETWEEN = (SCREEN_WIDTH - rowSize * TILE_SIZE) / 2;
const int directionx[8]={0,-1,1,0,1,-1,-1,1};
const int directiony[8]={-1,0,0,1,1,-1,1,-1};

