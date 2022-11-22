#pragma once

#include "Button.h"
#include "common.h"

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
	//vector<string> title;

public: 
	void DrawMainMenu(); 
	void DrawSettings(); 
	void DrawLoadGame(); 
	void DrawAbout(); 
	void HookLoadGame();
	void LoadGame();
	void AddMainMenuButtons(); 
	void AddSettingButtons(); 

	Menu(); 
	void Run();

	void setButtons(const vector<Button>& newButtons);
	void setMenuStatus(bool gameStarted, bool isRunning); 
	bool getGameStartedStatus() const; 
	bool getIsRunning() const; 
	void ChooseCommand(int, int, Mode); 
	void ExecuteCommands(const Mode&); 

};
