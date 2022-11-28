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
	void SetY(int);
	void SetXY(int, int);
	void SetSpeed(int);
	void SetDir(int);
	void SetData(int, int, int, int);

	virtual void Sound() = 0;

	int GetX();
	int GetY();
	int GetSpeed();
	int GetDir();
	int GetBX();
	int GetBY();

	void Draw();
	void Draw(int, int, int, int);
	void UpdateSprite();
	void Move();

};

