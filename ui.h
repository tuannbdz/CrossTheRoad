#pragma once
#include "lib.h"

class UI {
	vector<string> listCommands{"New Game", "Load Game", "Scoreboard", "Settings", "Exit"};
	int command = 0;
public:
	vector<string> frame;
	//static void 
	UI();
	void DrawTitle(int, int);
	void DrawMenu(int, int);
	void DrawFrame(int, int);
	void DrawGameScreen(int, int);
	void ChooseCommand(int, int);
	void DrawRect(vector<string>&, int, int, int, int);
};