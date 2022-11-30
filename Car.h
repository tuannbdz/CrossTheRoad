#pragma once
#include "Obstacle.h"
class Car : public Obstacle
{
public:
	Car();
	Car(int, int);
	~Car();
	void Sound();
};

