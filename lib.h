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

