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
	bool bg_music, g_music;
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
	//string data; //this is the filename that the user entered to save game process
	
public:
	Game();
	Game(int);
	~Game();
	void Init();
	void InitLevel(int);
	void Sound();

	void setMap();
	void setg_music(Menu& menu);
	void setbg_music(Menu& menu);

	Player& GetPlayer();
	vector<TLight>& GetTLight();
	int GetLevel();
	bool Getg_mucsic();
	bool Getbg_mucsic();

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

	template<class T>
	void Sound(std::vector<T*>& l_obj);

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
};

const int boardX = 10;
const int boardY = 6;