#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <chrono>
#include <iomanip>
#include <string>


using namespace std;
using namespace std::chrono;

#pragma comment(lib, "winmm.lib")

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORd(i, a, b) for(int i = a; i >= b; i--)
#define sp _getch()
#define KEY_ENTER 13
#define KEY_ESC 27
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_SPACE 32
#define KEY_BACKSPACE 8

const int color[12] = { 7, 1, 3, 4, 5, 8, 9, 11, 12, 13, 14, 15 };
const int SubText = 25;
const int Title = 30;
const int N = 5;
extern int numPlayers;
extern int textColorIndex;
extern int boardColorIndex;
extern int Command;
extern int width;
extern int height;
extern int totalCells;
extern int numItems;
extern int numPairs;
extern int cellsLeft;
extern bool** isFree;
extern bool* isChosen;
extern bool isMusicOn;
extern bool preMusic;
extern int cX, cY, iX, iY, nBG;
extern string background[30];

struct PAIR
{
    int fi = 0;
    int se = 0;
};

struct VECTOR
{
    int size = 0;
    PAIR arr[1000];
    void Push_back(PAIR v)
    {
        arr[size++] = v;
    }
    void Clear()
    {
        size = 0;
    }
    bool isEmpty()
    {
        return (size == 0);
    }
};

struct PLAYER {
    string name;
    double points = 0;
};

