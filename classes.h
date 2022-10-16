#pragma once
#include "lib.h"
/*
LEFT - 0
RIGHT - 1
UP - 2
DOWN - 3
*/
class OBSTACLE {
	int x, y;
	int speed;
	int dir;
};

class TRUCK : public OBSTACLE{
public:
	TRUCK();
};

class CAR : public OBSTACLE {
public:
	CAR();
};

class BIKE : public OBSTACLE {
public:
	BIKE();
};

class ANIMAL : public OBSTACLE {
public:
	ANIMAL();
};

class CHAR {
	int x, y;
	short state;
public:
	CHAR();
	static void Move(int);
	static void isCollide(const OBSTACLE*&);
};

class GAME {
public:
	GAME();
	static void DrawGame();
	static void ResetGame();
	static void StartGame();
	static void ExitGame();
	static void LoadGame();
	static void SaveGame();
	static void PauseGame();
	static void ResumeGame();
	static void UpdatePosChar();
	static void UpdatePosObstacle();
	~GAME();

};