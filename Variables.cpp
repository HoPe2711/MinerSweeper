#include "Variables.h"

SDL_Window* gWindow = NULL;

SDL_Renderer* gRenderer = NULL;

SDL_Rect stretchRect = {0,0,SCREEN_WIDTH,SCREEN_HEIGHT};

Mix_Music *winner = NULL;
Mix_Music *loser = NULL;
Mix_Chunk *click = NULL;

TTF_Font *gGameOver = NULL;
TTF_Font *gPlayAgainWin = NULL;
TTF_Font *gPlayAgainLose = NULL;
TTF_Font *gFont = NULL;

SDL_Rect gSpriteClips[ BUTTON_SPRITE_TOTAL ];
LTexture gButtonSpriteSheetTexture;
LTexture gButtonNewGameMenu;
LTexture gButtonMenu;
LTexture gButtonBackground;
LTexture gButtonHighScore;
LTexture gButtonHighScoreName;
LTexture gButtonHighscoreDiff;
LTexture gButtonDifficult;
LTexture gButtonGameOver;

LTexture gWinningTexture;
LTexture gBackgroundTexture;

LTexture gTextTexture;
LTexture gTextTextureE[12];
LTexture gTextTextureM[12];
LTexture gTextTextureH[12];
LTexture gMineLeftTexture;
LTexture gPlayAgainWinTexture;
LTexture gPlayAgainLoseTexture;

LButton gButtons_;
int countMineLeft;
int diff;
int countTileLeft = rowSize * columnSize;
bool gameOver = false;
bool isWinning = false;
bool playAgain = false;
time_t start_t, end_t;

int mineCount = 10;
LButton gButtons[rowSize][columnSize];

stringstream mineLeft;

int board[rowSize][columnSize];

int sBoard[rowSize][columnSize];


