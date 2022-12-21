#pragma once

#include "Button.h"
#include "common.h"

enum class MainMenuButtons {
	newGame, 
	loadGame, 
	settings, 
	about, 
	exit
};

enum class SettingButtons {
	bg_music, 
	sound, 
	level,
	returnToMain
};

enum class Mode {
	mainMenu, 
	settings
};

class Menu
{
	int command; 
	bool gameStarted, isRunning;
	bool bg_music,  g_music, g_play, g_exit;
	string g_load;
	int startLevel; 
	vector<Button>buttons; 
	int volume;
	Console* console;
public: 
	void DrawMainMenu(); 
	void DrawSettings(); 
	void DrawLoadGame(); 
	void DrawAbout(); 
	string HookLoadGame(short, short);
	void LoadGame();
	void AddMainMenuButtons(); 
	void AddSettingButtons(); 
	void Sound_on();
	void Sound_off();
	Menu(); 
	~Menu();
	void Run();
	bool getgMusic();
	bool getbgMusic();
	bool getIsRunning() const; 
	bool getGameStartedStatus() const;
	int getStartLevel() const; 
	void setButtons(const vector<Button>& newButtons);
	void setMenuStatus(bool gameStarted, bool isRunning); 
	void ChooseCommand(int, int, Mode); 
	void ExecuteCommands(const Mode&); 
	string Load();
	void SetLoad(string);
};
