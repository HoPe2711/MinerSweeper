#pragma once

#include <SDL_mixer.h>
#include <sstream>
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

extern SDL_Rect stretchRect;
extern SDL_Rect gSpriteClips[ BUTTON_SPRITE_TOTAL ];

extern LTexture gButtonSpriteSheetTexture;
extern LTexture gButtonNewGameMenu;
extern LTexture gButtonMenu;
extern LTexture gButtonBackground;
extern LTexture gButtonHighScore;
extern LTexture gButtonHighScoreName;
extern LTexture gButtonDifficult;

extern LTexture gWinningTexture;
extern LTexture gBackgroundTexture;
extern LTexture gTextTexture;
extern LTexture gMineLeftTexture;
extern LTexture gPlayAgainWinTexture;
extern LTexture gPlayAgainLoseTexture;

extern LButton gButtons[rowSize][columnSize];
extern LButton gButtons_;
extern int countMineLeft;
extern int countTileLeft;
extern bool gameOver;
extern bool isWinning;

extern stringstream mineLeft;

extern int board[rowSize][columnSize];

extern int sBoard[rowSize][columnSize];
