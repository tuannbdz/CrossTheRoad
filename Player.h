#include "lib.h"
#include "console.h"
#include "graphics.h"

#pragma once

class Player {
	short x, y;
	short state;
	Color color;
	vector<wstring> sprite;
public:
	Player();
	Player(int, int);
	void Draw();
	int GetX() { return x; };
	int GetY() { return y; };
	vector<wstring> getSprite() { return sprite; };
	void SetX(int);
	void SetY(int);
	void SetXY(int, int);
	void Move();
	//void isCollide(const OBSTACLE*&);
	~Player();
};