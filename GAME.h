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

class Game {
private:
	bool g_running, t_running;
	bool bg_music, g_music;
	int score, level;
	int speed;
	int numIdlePl;
	Menu menu;
	Player pl;
	vector<TLight> tlight;
	vector< Bike* > bike;
	vector< Car* > car;
	vector< Shark* > shark;
	vector< Truck* > tr;
	vector<int> idlePl;
	thread t_game;
	thread t_tlight;
public:
	Game();
	Game(int);
	~Game();
	void Init();
	void InitLevel(int);
	void Sound();
	void setMap();
	void setg_music();
	void setbg_music();
	Player& GetPlayer();
	vector<TLight>& GetTLight();
	int GetLevel();
	bool Getg_mucsic();
	bool Getbg_mucsic();
	void DrawGame();
	void DrawEmptyBoard();
	void ResetGame();
	void PauseGame();
	void GameOver();
	void ExitGame();
	void SaveGame();
	void LoadGame();
	void ClearData();
	bool isCollide(const int&, const int&, const int&, const int&, const int&, const int&, const int&, const int&);
	bool isRunning();
	bool isWinning();
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
	void Run();
	void StartGame();
	void ProcessGame();
	void ProcessTLight();
	void ReadGame(string);
};

const int boardX = 10;
const int boardY = 6;