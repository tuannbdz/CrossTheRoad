#include "lib.h"
#include "console.h"
#include "graphics.h"

#pragma once

class Player {
	short x, y;
	short state;
	Color color;
	vector<string> sprite;
public:
	Player(int, int);
	void Draw();
	int GetX() { return x; };
	int GetY() { return y; };
	vector<string> getSprite() { return sprite; };
	void SetX(int);
	void SetY(int);
	void Move();
	//void isCollide(const OBSTACLE*&);
	~Player();
};