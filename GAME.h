#pragma once

#include "lib.h"
#include "Menu.h"
#include "Player.h"

//#include "Console.h" //not supposed to include them here so this is temporary
//#include "Graphics.h"

class GAME {
private:
	bool g_running;
	bool t_running;
	Player* pl;
	//string data; //this is the filename that the user entered to save game process
	
public:
	GAME();
	void Run();
	static void DrawGame();
	static void DrawControls(); 
	void StartGame();
	void ProcessGame();
	void ExitGame(thread &);
	void PauseGame(thread &);
	void Initialize();
	void UpdatePlayer();

};
