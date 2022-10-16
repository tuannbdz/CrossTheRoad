#include "lib.h"

int numPlayers = 0;
int textColorIndex = 0;
int boardColorIndex = 6;
int Command = 0;
int width = 10, height = 5;
int totalCells = 0, cellsLeft = 0;
int numItems = 0, numPairs = 0;
bool** isFree;
bool* isChosen;
bool isMusicOn = 1;
bool preMusic = 0;

int cX = 26, cY = 5;
int iX, iY;

string background[30];
int nBG = 0;

PLAYER p[6];

