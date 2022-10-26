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
public:
	void DrawItself();
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

class PLAYER {
	int x, y;
	short state;
	vector<string> sprite;
public:
	PLAYER() {
		x = 0;
		y = 0;
		state = 1;
		sprite.resize(3);
		sprite[0] = " 0 ";
		sprite[1] = "/|\\";
		sprite[2] = "/ \\";
	};
	void DrawItself();
	int GetX() { return x; };
	int GetY() { return y; };
	void SetX(int);
	void SetY(int);
	void Move(int);
	void isCollide(const OBSTACLE*&);
	~PLAYER() {
	}
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