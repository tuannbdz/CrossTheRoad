#pragma once

#include "lib.h"
#include "Menu.h"
//#include "Console.h" //not supposed to include them here so this is temporary
//#include "Graphics.h"
class GAME {
private: 
	string data; //this is the filename that the user entered to save game process

public:
	GAME();
	static void Run();
	static void ExitGame();
	static void DrawGame();
	static void DrawControls(); 

	/*
	static void ResetGame();
	static void LoadGame();
	static void SaveGame();
	static void PauseGame();
	static void ResumeGame();
	static void UpdatePosChar();
	static void UpdatePosObstacle();
	~GAME();*/

};
