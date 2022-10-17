#pragma once
#include "lib.h"

class UI {
public:
	vector<string> listCommands{"New Game", "Load Game", "Scoreboard", "Settings", "Exit"};
	int command = 0;
	static void DrawTitle(int, int);
	static void DrawMenu(int, int);
	static void ChooseCommand(int, int);
};