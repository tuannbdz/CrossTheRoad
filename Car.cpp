#include "Car.h"

Car::Car() {
    x = 30;
    y = 17;
    dir = 1;
    speed = 2;
    sprite = Graphics::GetGraphicsR("graphics/Game/obstacles/car.txt");
    color = Graphics::GetColor(Color::gray, Color::lightgreen);
}

Car::Car(int _x, int _y) {
    x = _x;
    y = _y;
    dir = 1;
    speed = 2;
    sprite = Graphics::GetGraphicsR("graphics/Game/obstacles/car.txt");
    color = Graphics::GetColor(Color::gray, Color::lightgreen);
}

void Car::Sound()
{
    PlaySound(L"music/car.wav", NULL, SND_FILENAME | SND_ASYNC);
}

Car::~Car() {

}