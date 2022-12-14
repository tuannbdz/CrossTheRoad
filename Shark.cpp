#include "Shark.h"

Shark::Shark() {
    x = 30;
    y = 23;
    dir = 1;
    speed = 1;
    sprite = Graphics::GetGraphics("graphics/Game/obstacles/shark.txt");
    color = Graphics::GetColor(Color::gray, Color::lightaqua);
}

Shark::Shark(int _x, int _y) {
    x = _x;
    y = _y;
    dir = 1;
    speed = 1;
    sprite = Graphics::GetGraphics("graphics/Game/obstacles/shark.txt");
    color = Graphics::GetColor(Color::gray, Color::lightaqua);
}

void Shark::Sound()
{
    PlaySound(L"music/dinosour.wav", NULL, SND_FILENAME | SND_ASYNC);
}

Shark::~Shark() {

}