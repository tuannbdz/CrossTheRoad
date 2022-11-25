#pragma once

#include "lib.h"
#include "Menu.h"
#include "Player.h"
#include "common.h"
#include "Truck.h"
#include "Car.h"
#include "Bike.h"
#include "Shark.h"
#include "TLight.h"
//#include "Console.h" //not supposed to include them here so this is temporary
//#include "Graphics.h"

class Game {
private:
	bool g_running;
	int score, level;
	int speed;
	Player pl;
	vector<TLight> tlight;
	vector< Bike* > bike;
	vector< Car* > car;
	vector< Shark* > shark;
	vector< Truck* > tr;
	//string data; //this is the filename that the user entered to save game process
	
public:
	Game();
	Game(int);
	~Game();
	void Init();
	void InitLevel(int);

	void setMap(); 

	Player& GetPlayer();
	vector<TLight>& GetTLight();

	void DrawGame();
	void ResetGame();
	void PauseGame(thread &, thread& ,void (*func)(), void (*func2)());
	void GameOver(void (*func)(), Menu& menu);
<<<<<<< HEAD
	void ExitGame(thread&, thread&, Game*& g, Menu& menu, void (*func)(), void (*func2)());
=======
	void ExitGame(thread &, thread&, Game* & g, Menu& menu, void (*func)(), void (*func2)());
>>>>>>> 39e1c0814813d05c2dfce5e6abfee7451e5384b5
	void SaveGame(thread&, thread&, void (*func)(), void (*func2)());
	void LoadGame(thread&, thread&, void (*func)(), void (*func2)(), Game*&);
	bool isCollide(const int&, const int&, const int&, const int&, const int&, const int&, const int&, const int&);
	bool isRunning();

	string HookLoadGame(short, short);

	void UpdatePlayer();
	void UpdateTruck();
	void UpdateBike();
	void UpdateCar();
	void UpdateShark();
	void UpdateTLight();

	

	void DrawTruck();
	void DrawBike();
	void DrawCar();
	void DrawShark();
};

const int boardX = 10;
const int boardY = 6;