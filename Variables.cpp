#include "Variables.h"

SDL_Window* gWindow = NULL;

SDL_Renderer* gRenderer = NULL;

SDL_Rect stretchRect = {0,0,SCREEN_WIDTH,SCREEN_HEIGHT};

Mix_Music *winner = NULL;
Mix_Music *loser = NULL;
Mix_Chunk *click = NULL;

TTF_Font *gFontHighScore = NULL;
TTF_Font *gFontNameInput = NULL;
TTF_Font *gFontNewHighscore = NULL;

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
LTexture gNewHighscore;
LTexture gNewHighscoreBackground;

LButton gButtons_;
LButton gButtons[rowSize][columnSize];

int countMineLeft;
int countTileLeft = rowSize * columnSize;
int diff;
int globalTime;
int mineCount;

bool gameOver = false;
bool isWinning = false;
bool playAgain = false;
bool statusHighscore = false;

stringstream mineLeft;
string input = " ";
string timeOutput;
string newHighscore;

string highscoreE[12];
string highscoreM[12];
string highscoreH[12];
int valueTimeE[6];
int valueTimeM[6];
int valueTimeH[6];

int board[rowSize][columnSize];

int sBoard[rowSize][columnSize];


