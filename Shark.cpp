#include "Shark.h"

Shark::Shark() {
    x = 30;
    y = 23;
    dir = 1;
    speed = 1;
    sprite = Graphics::GetGraphics("graphics/Game/obstacles/shark.txt");
    color = Graphics::GetColor(Color::gray, Color::brightwhite);
}

Shark::Shark(int _x, int _y) {
    x = _x;
    y = _y;
    dir = 1;
    speed = 1;
    sprite = Graphics::GetGraphics("graphics/Game/obstacles/shark.txt");
    color = Graphics::GetColor(Color::gray, Color::brightwhite);
}

Shark::~Shark() {

}