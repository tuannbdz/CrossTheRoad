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
	int command; 
	bool gameStarted, isRunning; 
	vector<Button>buttons; 

	void DrawMainMenu(); 
	void DrawSettings(); 
	void DrawLoadGame(); 
	void DrawAbout(); 
	void AddMainMenuButtons(); 
	void AddSettingButtons(); 
public: 
	Menu(); 
	void Run();

	void setMenuStatus(bool gameStarted, bool isRunning); 
	bool getGameStartedStatus() const; 
	bool getIsRunning() const; 
	void ChooseCommand(int, int, Mode); 
	void ExecuteCommands(const Mode&); 
};

