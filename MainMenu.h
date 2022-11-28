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
void DrawMainMenu();
void DrawSettings();
void DrawLoadGame();
void DrawAbout();
void HookLoadGame();
void LoadGame();
void AddMainMenuButtons();
void AddSettingButtons();
void Music();
void Sound_on();
void Sound_off();
void Sound();

bool getgMusic();
bool getbgMusic();
void setButtons(const vector<Button>& newButtons);
void setMenuStatus(bool gameStarted, bool isRunning);
bool getGameStartedStatus();
bool getIsRunning();
void ChooseCommand(int, int, Mode);
void ExecuteCommands(const Mode&);