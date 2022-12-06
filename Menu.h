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
	bool bg_music,  g_music, g_play, g_exit;
	string g_load;

	std::thread t_Sound;

	vector<Button>buttons; 

	int volume;

	Console* console;
	//vector<string> title;
	
public: 
	void DrawMainMenu(); 
	void DrawSettings(); 
	void DrawLoadGame(); 
	void DrawAbout(); 
	string HookLoadGame(short, short);
	void LoadGame();
	void AddMainMenuButtons(); 
	void AddSettingButtons(); 
	void Music();
	void Sound_on();
	void Sound_off();
	void Sound();

	Menu(); 
	~Menu();
	void Run();

	bool getgMusic();
	bool getbgMusic();
	void setButtons(const vector<Button>& newButtons);
	void setMenuStatus(bool gameStarted, bool isRunning); 
	bool getGameStartedStatus() const; 
	bool getIsRunning() const; 
	void ChooseCommand(int, int, Mode); 
	void ExecuteCommands(const Mode&); 

	string Load();
	void SetLoad(string);
};
