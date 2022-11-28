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
	int numIdlePl;
	Player pl;
	vector<TLight> tlight;
	vector< Bike* > bike;
	vector< Car* > car;
	vector< Shark* > shark;
	vector< Truck* > tr;
	vector<int> idlePl;
	
public:
	Game();
	Game(int);
	~Game();
	void Init();
	void InitLevel(int);

	void setMap(); 

	Player& GetPlayer();
	vector<TLight>& GetTLight();
	int GetLevel();

	void DrawGame();
	void DrawEmptyBoard();
	void ResetGame();
	void PauseGame(thread &, thread& ,void (*func)(), void (*func2)());
	void GameOver(void (*func)(), Menu& menu);
	void ExitGame(thread&, thread&, Game*& g, Menu& menu, void (*func)(), void (*func2)());
	void SaveGame(thread&, thread&, void (*func)(), void (*func2)());
	void LoadGame(thread&, thread&, void (*func)(), void (*func2)());
	void ClearData();
	bool isCollide(const int&, const int&, const int&, const int&, const int&, const int&, const int&, const int&);
	bool isRunning();
	bool isWinning();

	string HookLoadGame(short, short);

	void UpdateGameStatus();
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
	void DrawIdlePl();
	void DrawScore();
	void DrawLevel();
};

const int boardX = 10;
const int boardY = 6;