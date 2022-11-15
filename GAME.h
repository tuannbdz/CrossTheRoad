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
	int score, level;

	//bool t_running;
	Player pl;
	vector< Truck* > tr;
	vector< Car* > car;
	vector< Bike* > bike;
	vector< Shark* > shark;
	//string data; //this is the filename that the user entered to save game process
	
public:
	Game();
	~Game();
	void Init();

	Player getPlayer();

	void DrawGame();
	void StartGame(Menu& menu);
	void ResetGame();
	void PauseGame(thread &, void (*func)());
	void GameOver(void (*func)(), Menu& menu);
	void ExitGame(thread &, Game* & g, Menu& menu);
	bool isCollide(const int&, const int&, const int&, const int&, const int&, const int&, const int&, const int&);
	bool isRunning();

	void UpdatePlayer();
	void UpdateTruck();
	void UpdateBike();
	void UpdateCar();
	void UpdateShark();
	void setMap(); 
};

const int boardX = 10;
const int boardY = 6;