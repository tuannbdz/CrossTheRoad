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
	const vector<vector<wstring>>numberGraphics = {
		zero, one, two, three, four, five, six, seven, eight, nine
	};

	const vector<wstring> zero =
	{
		L"█▀█",
		L"█▄█"
	};

	const vector<wstring> one =
	{
		L"▄█",
		L" █"
	};

	const vector<wstring> two =
	{
		L"▀█",
		L"█▄"

	};

	const vector<wstring> three =
	{
		L"▀██",
		L"▄▄█"
	};
	const vector<wstring> four =
	{
		L"█ █",
		L"▀▀█"

	};
	const vector<wstring> five =
	{
		L"█▀",
		L"▄█"

	};
	const vector<wstring> six =
	{
		L"█▄▄",
		L"█▄█"

	};
	const vector<wstring> seven =
	{
		L"▀▀█",
		L"  █"

	};
	const vector<wstring> eight =
	{
		L"▄▀▀▄",
		L"▄▀▀▄"
		L"▀▄▄▀"
	};

	const vector<wstring> nine =
	{
		L"█▀█",
		L"▀▀█"
	};
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
	void ExitGame(thread&, thread&, Game*& g, Menu& menu, void (*func)(), void (*func2)());
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