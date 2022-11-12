#include "Bike.h"

Bike::Bike() {
    x = 30;
    y = 12;
    dir = 0;
    speed = 1;
    sprite = Graphics::GetGraphicsR("graphics/Game/obstacles/bike.txt");
    color = Graphics::GetColor(Color::gray, Color::brightwhite);
}

Bike::Bike(int _x, int _y) {
    x = _x;
    y = _y;
    dir = 0;
    speed = 1;
    sprite = Graphics::GetGraphicsR("graphics/Game/obstacles/bike.txt");
    color = Graphics::GetColor(Color::gray, Color::brightwhite);
}

Bike::~Bike() {

}