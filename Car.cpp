#include "Car.h"

Car::Car() {
    x = 30;
    y = 17;
    dir = 1;
    speed = 2;
    sprite = Graphics::GetGraphicsR("graphics/Game/obstacles/car.txt");
<<<<<<< HEAD
    color = Graphics::GetColor(Color::gray, Color::lightgreen);
=======
    color = Graphics::GetColor(Color::gray, Color::lightblue);
>>>>>>> 39e1c0814813d05c2dfce5e6abfee7451e5384b5
}

Car::Car(int _x, int _y) {
    x = _x;
    y = _y;
    dir = 1;
    speed = 2;
    sprite = Graphics::GetGraphicsR("graphics/Game/obstacles/car.txt");
<<<<<<< HEAD
    color = Graphics::GetColor(Color::gray, Color::lightgreen);
=======
    color = Graphics::GetColor(Color::gray, Color::lightblue);
>>>>>>> 39e1c0814813d05c2dfce5e6abfee7451e5384b5
}

Car::~Car() {

}