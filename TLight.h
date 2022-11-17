#pragma once
#include "lib.h"
class TLight {
	short x, y;
	bool isGreen;
	vector<string> sprite;
public:
	TLight();
	TLight(int, int);

	int GetX();
	int GetY();
	bool IsGreen();
	vector<string>& GetSprite();

	void SetX(int);
	void SetY(int);
	void SetXY(int, int);
	void SetState(bool);
	void SetSprite(vector<string>&);
	void SetData(int, int, bool);

	void DrawSelf();

};

