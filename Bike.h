#pragma once
#include "Obstacle.h"

class Bike : public Obstacle
{
public:
	Bike();
	Bike(int, int);
	~Bike();
	void Sound();
};
