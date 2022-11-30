#include "Truck.h"

Truck::Truck() {
    x = 30;
    y = 28;
    dir = 0;
    speed = 2;
    sprite = Graphics::GetGraphics("graphics/Game/obstacles/truck.txt");
    color = Graphics::GetColor(Color::gray, Color::brightwhite);
}

Truck::Truck(int _x, int _y) {
    x = _x;
    y = _y;
    dir = 0;
    speed = 2;
    sprite = Graphics::GetGraphics("graphics/Game/obstacles/truck.txt");
    color = Graphics::GetColor(Color::gray, Color::brightwhite);
}

void Truck::Sound() 
{
    PlaySound(L"music/truck.wav", NULL, SND_FILENAME | SND_ASYNC);
}

Truck::~Truck() {

}