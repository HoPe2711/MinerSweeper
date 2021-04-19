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
TTF_Font *font = NULL;

SDL_Rect gSpriteClips[ BUTTON_SPRITE_TOTAL ];
LTexture gButtonSpriteSheetTexture;
LTexture gButtonNewGameMenu;
LTexture gButtonMenu;
LTexture gButtonBackground;
LTexture gButtonHighScore;
LTexture gButtonHighScoreName;
LTexture gButtonDifficult;

LTexture gWinningTexture;
LTexture gBackgroundTexture;

LTexture gTextTexture;
LTexture gMineLeftTexture;
LTexture gPlayAgainWinTexture;
LTexture gPlayAgainLoseTexture;

LButton gButtons_;
int countMineLeft = mineCount;
int countTileLeft = rowSize * columnSize;
bool gameOver = false;
bool isWinning = false;

LButton gButtons[rowSize][columnSize];

stringstream mineLeft;

int board[rowSize][columnSize];

int sBoard[rowSize][columnSize];


