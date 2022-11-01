#pragma once

#include "Button.h"

const enum class MainMenuButtons {
	newGame, 
	loadGame, 
	settings, 
	about, 
	exit
};

const enum class SettingButtons {
	bg_music, 
	sound, 
	level,
	returnToMain
};

const enum class Mode {
	mainMenu, 
	settings
};
class Menu
{
	int command = 0; 
	vector<Button>buttons; 

	void DrawMainMenu(); 
	void drawSettings(); 
	void AddMainMenuButtons(); 
	void AddSettingButtons(); 
public: 
	void Run();
	void ChooseCommand(int, int, Mode); 
	void ExecuteCommands(const Mode&); 
};

