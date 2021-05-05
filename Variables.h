#pragma once

#include <SDL_mixer.h>
#include <sstream>
#include <fstream>
#include <time.h>
#include "Constances.h"
#include "Texture.h"
#include "Button.h"
#include "thread"

extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;

extern Mix_Music *winner;
extern Mix_Music *loser;
extern Mix_Chunk *click;

extern TTF_Font *gFontHighScore;
extern TTF_Font *gFontNameInput;
extern TTF_Font *gFontTime;

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
extern LTexture gTimeOutput;
extern LTexture gNewHighscore;

extern LTexture gTexTureInputName;


extern LButton gButtons[rowSize][columnSize];
extern LButton gButtons_;
extern int countMineLeft;
extern int countTileLeft;
extern int mineCount;
extern bool gameOver;
extern bool isWinning;
extern bool playAgain;
extern bool HighscoreStatus;
extern int diff;
extern int globalTime;

extern string input;
extern stringstream mineLeft;
extern string timeOutput;
extern string newHighscore;
extern string highscoreE[12];
extern string highscoreM[12];
extern string highscoreH[12];
extern int valueTimeE[6];
extern int valueTimeM[6];
extern int valueTimeH[6];

extern int board[rowSize][columnSize];

extern int sBoard[rowSize][columnSize];
