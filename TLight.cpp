#include "TLight.h"
#include "Graphics.h"
#include "console.h"

TLight::TLight() {
	x = y = 0;
	isGreen = true;
	sprite = Graphics::GetGraphics("graphics/Game/traffic_light2.txt");
}
TLight::TLight(int _x, int _y) {
	x = _x, y = _y;
	isGreen = true;
	sprite = Graphics::GetGraphics("graphics/Game/traffic_light2.txt");
}

int TLight::GetX() { return x; }
int TLight::GetY() { return y; }
bool TLight::IsGreen() { return isGreen; }
vector<string>& TLight::GetSprite() { return sprite; }
int TLight::GetTimeOut() { return timeout; }

void TLight::SetX(int _x) { x = _x; }
void TLight::SetY(int _y) { y = _y; }
void TLight::SetXY(int _x, int _y) { x = _x, y = _y; }
void TLight::SetState(bool b) { isGreen = b; }
void TLight::SetSprite(vector<string>& s) { sprite = s; }
void TLight::SetData(int _x, int _y, bool b) { x = _x, y = _y, isGreen = b; }
void TLight::SetTimeOut(int _t) {
	timeout = _t;
}

void TLight::DrawSelf() {
	Graphics::DrawGraphics(sprite, { x,y }, Graphics::GetColor(Color::brightwhite, Color::black));
	if (isGreen)
		Graphics::DrawGraphics(sprite, { short(x + 1), short(y + 1) }, 1, 1, 1, 1, Graphics::GetColor(Color::brightwhite, Color::green));
	else
		Graphics::DrawGraphics(sprite, { short(x + 1), short(y + 2) }, 1, 2, 1, 1, Graphics::GetColor(Color::brightwhite, Color::red));
}
