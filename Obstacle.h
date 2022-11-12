#pragma once
#include "graphics.h";
#include "lib.h"


class Obstacle
{
protected:
	short x, y;
	int speed;
	Color color;
	vector<string> sprite;
	int dir;
public:
	void SetX(int);
	int GetX();
	int GetY();
	int GetBX();
	int GetBY();
	void SetY(int);
	void SetXY(int, int);
	void Draw();
	void Draw(int, int, int, int);
	void Move();
};

