#pragma once

#include <SDL_mixer.h>
#include <sstream>
#include <fstream>
#include <time.h>
#include "Constances.h"
#include "Texture.h"
#include "Button.h"

extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;

extern Mix_Music *winner;
extern Mix_Music *loser;
extern Mix_Chunk *click;

extern TTF_Font *gGameOver;
extern TTF_Font *gPlayAgainWin;
extern TTF_Font *gPlayAgainLose;
extern TTF_Font *gFont;

extern SDL_Rect stretchRect;
extern SDL_Rect gSpriteClips[ BUTTON_SPRITE_TOTAL ];

extern LTexture gButtonSpriteSheetTexture;
extern LTexture gButtonNewGameMenu;
extern LTexture gButtonMenu;
extern LTexture gButtonBackground;
extern LTexture gButtonHighScore;
extern LTexture gButtonHighScoreName;
extern LTexture gButtonHighscoreDiff;
extern LTexture gButtonDifficult;
extern LTexture gButtonGameOver;

extern LTexture gWinningTexture;
extern LTexture gBackgroundTexture;
extern LTexture gTextTexture;
extern LTexture gTextTextureE[12];
extern LTexture gTextTextureM[12];
extern LTexture gTextTextureH[12];
extern LTexture gMineLeftTexture;
extern LTexture gPlayAgainWinTexture;
extern LTexture gPlayAgainLoseTexture;


extern LButton gButtons[rowSize][columnSize];
extern LButton gButtons_;
extern int countMineLeft;
extern int countTileLeft;
extern int diff;
extern bool gameOver;
extern bool isWinning;
extern int mineCount;
extern bool playAgain;
extern time_t start_t, end_t;

extern stringstream mineLeft;

extern int board[rowSize][columnSize];

extern int sBoard[rowSize][columnSize];
