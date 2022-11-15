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
	int GetState() { return state; };
	vector<wstring> getSprite() { return sprite; };
	void SetX(int);
	void SetY(int);
	void SetState(short);
	void SetSprite(vector<wstring>s); 
	void SetXY(int, int);
	void Move();
	//void isCollide(const OBSTACLE*&);
	~Player();
};