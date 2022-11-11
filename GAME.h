#pragma once

#include "lib.h"
#include "Menu.h"
#include "Player.h"
#include "common.h"

//#include "Console.h" //not supposed to include them here so this is temporary
//#include "Graphics.h"

class Game {
private:
	bool g_running;
	//bool t_running;
	Player pl;
	//string data; //this is the filename that the user entered to save game process
	
public:
	Game();
	~Game();
	void Init();

	Player getPlayer();

	void DrawGame();
	void StartGame();
	void PauseGame(thread &, void (*func)());
	void ExitGame(thread &);

	void UpdatePlayer();
};

const int boardX = 10;
const int boardY = 6;