#pragma once

#include "lib.h"
#include "Menu.h"
#include "Player.h"
#include "common.h"
#include "Truck.h"
#include "Car.h"
#include "Bike.h"
#include "Shark.h"
//#include "Console.h" //not supposed to include them here so this is temporary
//#include "Graphics.h"

class Game {
private:
	bool g_running;
	int level;
	int speed;
	//bool t_running;
	Player pl;
	vector< Truck* > tr;
	vector< Car* > car;
	vector< Bike* > bike;
	vector< Shark* > shark;
	//string data; //this is the filename that the user entered to save game process
	
public:
	Game();
	Game(int);
	~Game();
	void Init(int);
	void Init();
	void LoadMap1();
	void LoadMap2();
	void LoadMap3();

	Player getPlayer();

	void DrawGame();
	void ResetGame();
	void PauseGame(thread &, void (*func)());
	void ExitGame(thread &);
	bool isCollide(const int&, const int&, const int&, const int&, const int&, const int&, const int&, const int&);
	bool isRunning();

	void UpdatePlayer();
	void UpdateTruck();
	void UpdateBike();
	void UpdateCar();
	void UpdateShark();
};

const int boardX = 10;
const int boardY = 6;