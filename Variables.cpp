#include "Variables.h"

SDL_Window* gWindow = NULL;

SDL_Renderer* gRenderer = NULL;

SDL_Rect stretchRect = {0,0,SCREEN_WIDTH,SCREEN_HEIGHT};

Mix_Music *winner = NULL;
Mix_Music *loser = NULL;
Mix_Chunk *click = NULL;

TTF_Font *gFontHighScore = NULL;
TTF_Font *gFontNameInput = NULL;
TTF_Font *gFontTime = NULL;

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
LTexture gTimeOutput;
LTexture gTexTureInputName;

LButton gButtons_;
int countMineLeft;
int countTileLeft = rowSize * columnSize;
bool gameOver = false;
bool isWinning = false;
bool playAgain = false;
time_t start_t, end_t;
int diff;
int globalTime;

int mineCount = 10;
LButton gButtons[rowSize][columnSize];

string input = " ";
stringstream mineLeft;
string timeOutput;
string highscoreE[12];
string highscoreM[12];
string highscoreH[12];
int valueTimeE[6];
int valueTimeM[6];
int valueTimeH[6];

int board[rowSize][columnSize];

int sBoard[rowSize][columnSize];


