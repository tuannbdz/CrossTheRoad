#include "Menu.h"

Menu::Menu()
{
	command = 0; 
	gameStarted = false;
	isRunning = true; 
}

void Menu::setMenuStatus(bool gameStarted, bool isRunning)
{
	this->gameStarted = gameStarted; 
	this->isRunning = isRunning; 
}

bool Menu::getGameStartedStatus() const
{
	return gameStarted; 
}

bool Menu::getIsRunning() const
{
	return isRunning;
}
void Menu::AddMainMenuButtons()
{
	this->buttons.push_back(Button("New Game", { 75, 14 },	UNSELECTED_COLOR, "graphics/Menu/buttons/new_game.txt"));
	this->buttons.push_back(Button("Load Game",{ 75, 19 },	UNSELECTED_COLOR, "graphics/Menu/buttons/load_game.txt"));
	this->buttons.push_back(Button("Settings", { 75, 24 },	UNSELECTED_COLOR, "graphics/Menu/buttons/Settings.txt"));
	this->buttons.push_back(Button("About",	   { 75, 29 },	UNSELECTED_COLOR, "graphics/Menu/buttons/about.txt"));
	this->buttons.push_back(Button("Exit",	   { 75, 34 },	UNSELECTED_COLOR, "graphics/Menu/buttons/Exit.txt"));
}

void Menu::AddSettingButtons()
{
	this->buttons.push_back(Button("Background Music",	{ 75, 14 }, UNSELECTED_COLOR, "graphics/Menu/settings/bg_music.txt"));
	this->buttons.push_back(Button("Sound effect",		{ 75, 19 }, UNSELECTED_COLOR, "graphics/Menu/settings/sound.txt"));
	this->buttons.push_back(Button("Level",				{ 75, 24 }, UNSELECTED_COLOR, "graphics/Menu/settings/level.txt"));
	this->buttons.push_back(Button("Return",			{ 75, 29 }, UNSELECTED_COLOR, "graphics/Menu/settings/return.txt"));
}

void Menu::DrawMainMenu()
{
	Graphics::ClearScreen(); 
	buttons.clear(); 
	Console::SetFont(L"Consolas");

	AddMainMenuButtons(); 
	Graphics::drawBlueGradientGraphics({ 10, 0 }, "graphics/Menu/title.txt");

	Graphics::DrawGraphics({ 68, 11 }, "graphics/Menu/frame.txt", Graphics::GetColor(Color::brightwhite, Color::blue)); 
	for (int i = 0; i < buttons.size(); ++i)
		buttons[i].DrawGraphics(); 

}

void Menu::DrawSettings()
{
	Graphics::ClearScreen();
	buttons.clear(); 
	Console::SetFont(L"Consolas");

	Graphics::drawBlueGradientGraphics({ 45, 0 }, "graphics/Menu/settings/settings.txt");
	Graphics::DrawGraphics({ 68, 11 }, "graphics/Menu/frame.txt", Graphics::GetColor(Color::brightwhite, Color::blue));
	AddSettingButtons(); 
	for (int i = 0; i < buttons.size(); ++i)
		buttons[i].DrawGraphics();
}

void Menu::DrawLoadGame()
{
	Graphics::ClearScreen();
	buttons.clear();
	Graphics::drawBlueGradientGraphics({ 10, 0 }, "graphics/Menu/title.txt");
	Graphics::DrawGraphics({ 58, 6 }, "graphics/Menu/load_game_frame.txt", Graphics::GetColor(Color::lightblue, Color::lightaqua));
	Console::SetFont(L"Consolas Bold"); 
	Graphics::DrawTexts("NAME", { 64, 8 }, Graphics::GetColor(Color::lightblue, Color::brightwhite));
	Graphics::DrawTexts("LEVEl", { 96, 8 }, Graphics::GetColor(Color::lightblue, Color::brightwhite));
	Graphics::DrawTexts("SCORE", { 110, 8 }, Graphics::GetColor(Color::lightblue, Color::brightwhite));
	Graphics::DrawTexts("BACK [B]", { 63, 36 }, Graphics::GetColor(Color::lightblue, Color::brightwhite));
	Graphics::DrawTexts("RETURN [R]", { 85, 36 }, Graphics::GetColor(Color::lightblue, Color::brightwhite));
	Graphics::DrawTexts("NEXT [N]", { 108, 36 }, Graphics::GetColor(Color::lightblue, Color::brightwhite));
	system("pause >nul"); 
}

void Menu::DrawAbout()
{
	Graphics::ClearScreen();
	buttons.clear();
	Console::SetFont(L"Consolas Bold"); 
	Graphics::drawBlueGradientGraphics({ 10, 0 }, "graphics/Menu/title.txt");
	Graphics::DrawGraphics({ 58, 15 }, "graphics/Menu/about_screen.txt", Graphics::GetColor(Color::lightblue, Color::lightaqua));

}

void Menu::Run()
{
	AddMainMenuButtons(); 
	DrawMainMenu(); 
	ChooseCommand(75, 14, Mode::mainMenu); 

}

void Menu::ChooseCommand(int cX, int cY, Mode mode)
{
	int pY = cY;
	int pC = this->command;
	
	do
	{
		int n = buttons.size(); 
		//reset color of previous command
		Console::gotoxy(cX, pY);
		buttons[pC].DrawGraphics(UNSELECTED_COLOR); 

		Console::gotoxy(cX, cY);
		buttons[this->command].DrawGraphics(SELECTED_COLOR);

		int c = toupper(_getch());
		switch (c)
		{
		case 'W':case KEY_UP:
			pY = cY;
			pC = this->command;
			this->command = (this->command - 1 + n) % n;
			cY = this->command + 5;
			break;
		case 'S':case KEY_DOWN:
			pY = cY;
			pC = this->command;
			this->command = (this->command + 1) % n;
			cY = this->command + 5;
			break;
		case KEY_ENTER: case KEY_SPACE:
			ExecuteCommands(mode); 
			break;
		}

	} while (isRunning);
}

void Menu::ExecuteCommands(const Mode& mode)
{
	int n = buttons.size();


	if (mode == Mode::mainMenu)
	{
		switch (this->command)
		{
			case (int)MainMenuButtons::newGame:
			buttons[this->command].DrawEffect(SELECTED_COLOR);
			setMenuStatus(true, false); 
			return; 
		case (int)MainMenuButtons::loadGame:
			DrawLoadGame(); 
			//hookloadgame() or sth
			setMenuStatus(false, false); 
			return; 
			break;
		case (int)MainMenuButtons::settings:
			//Graphics::RemoveArea({75, 14}, {125, 35}); 
			DrawSettings(); 
			ChooseCommand(75, 14, Mode::settings); 
			break;
		case (int)MainMenuButtons::about:
			DrawAbout(); 
			//hookabout() or sth
			setMenuStatus(false, false);
			return; 
			break;
		case (int)MainMenuButtons::exit:
			exit(0);
			break; 
		}
	}
	else if (mode == Mode::settings)
	{
		switch (this->command)
		{
		case (int)SettingButtons::bg_music: 
			break; 
		case (int)SettingButtons::sound: 
			break; 
		case (int)SettingButtons::level: 
			break; 
		case (int)SettingButtons::returnToMain:
			Graphics::RemoveArea({ 75, 14 }, { 125, 35 });
			DrawMainMenu();
			ChooseCommand(75, 14, Mode::mainMenu);
			break;
		}

	}
}