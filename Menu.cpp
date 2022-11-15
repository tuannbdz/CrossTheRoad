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
	buttons.push_back(Button("New Game", { 75, 14 },	UNSELECTED_COLOR, "graphics/Menu/buttons/new_game.txt"));
	buttons.push_back(Button("Load Game",{ 75, 19 },	UNSELECTED_COLOR, "graphics/Menu/buttons/load_game.txt"));
	buttons.push_back(Button("Settings", { 75, 24 },	UNSELECTED_COLOR, "graphics/Menu/buttons/Settings.txt"));
	buttons.push_back(Button("About",	   { 75, 29 },	UNSELECTED_COLOR, "graphics/Menu/buttons/about.txt"));
	buttons.push_back(Button("Exit",	   { 75, 34 },	UNSELECTED_COLOR, "graphics/Menu/buttons/Exit.txt"));
}

void Menu::AddSettingButtons()
{
	buttons.push_back(Button("Background Music",	{ 75, 14 }, UNSELECTED_COLOR, "graphics/Menu/settings/bg_music.txt"));
	buttons.push_back(Button("Sound effect",		{ 75, 19 }, UNSELECTED_COLOR, "graphics/Menu/settings/sound.txt"));
	buttons.push_back(Button("Level",				{ 75, 24 }, UNSELECTED_COLOR, "graphics/Menu/settings/level.txt"));
	buttons.push_back(Button("Return",			{ 75, 29 }, UNSELECTED_COLOR, "graphics/Menu/settings/return.txt"));
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
	Graphics::DrawGraphics({ 58, 6 }, "graphics/Menu/load_game_frame.txt", Graphics::GetColor(Color::lightblue, Color::lightyellow));
	Console::SetFont(L"Consolas Bold"); 
	Graphics::DrawTexts("NAME", { 64, 8 }, Graphics::GetColor(Color::lightblue, Color::brightwhite));
	Graphics::DrawTexts("LEVEl", { 96, 8 }, Graphics::GetColor(Color::lightblue, Color::brightwhite));
	Graphics::DrawTexts("SCORE", { 110, 8 }, Graphics::GetColor(Color::lightblue, Color::brightwhite));
	Graphics::DrawTexts("BACK [B]", { 63, 36 }, Graphics::GetColor(Color::lightblue, Color::brightwhite));
	Graphics::DrawTexts("RETURN [R]", { 85, 36 }, Graphics::GetColor(Color::lightblue, Color::brightwhite));
	Graphics::DrawTexts("NEXT [N]", { 108, 36 }, Graphics::GetColor(Color::lightblue, Color::brightwhite));
}

void Menu::HookLoadGame()
{
	int c; 
	do
	{
		c = toupper(_getch());
		//load game more stuffs here
		if (c == 'R')
		{
			setMenuStatus(false, true);
			DrawMainMenu();
			return;
		}
	} while (c != 'R');
}

void Menu::DrawAbout()
{
	Graphics::ClearScreen();
	buttons.clear();
	Console::SetFont(L"Consolas Bold"); 
	Graphics::drawBlueGradientGraphics({ 10, 0 }, "graphics/Menu/title.txt");
	Graphics::DrawGraphics({ 58, 15 }, "graphics/Menu/about_screen.txt", Graphics::GetColor(Color::lightblue, Color::lightyellow));

}

void Menu::Run()
{
	//AddMainMenuButtons(); 
	DrawMainMenu(); 
	ChooseCommand(75, 14, Mode::mainMenu); 

}

void Menu::ChooseCommand(int cX, int cY, Mode mode)
{
	//pY : previous Y, cY = current Y the command is at
	int pY = cY;
	int pC = command;
	
	do
	{
		int n = buttons.size(); 
		//reset color of previous command
		Console::gotoxy(cX, pY);
		buttons[pC].DrawGraphics(UNSELECTED_COLOR); 

		Console::gotoxy(cX, cY);
		buttons[command].DrawGraphics(SELECTED_COLOR);

		int c = toupper(_getch());
		switch (c)
		{
		case 'W':case KEY_UP:
			pY = cY;
			pC = command;
			command = (command - 1 + n) % n;
			cY = command + 5;
			break;
		case 'S':case KEY_DOWN:
			pY = cY;
			pC = command;
			command = (command + 1) % n;
			cY = command + 5;
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
	int c; 

	if (mode == Mode::mainMenu)
	{
		switch (command)
		{
			case (int)MainMenuButtons::newGame:
			buttons[command].DrawEffect(SELECTED_COLOR);
			setMenuStatus(true, false); 
			return; 
		case (int)MainMenuButtons::loadGame:
			DrawLoadGame(); 
			HookLoadGame(); 

			break;
		case (int)MainMenuButtons::settings:
			//Graphics::RemoveArea({75, 14}, {125, 35}); 
			DrawSettings(); 
			ChooseCommand(75, 14, Mode::settings); 
			break;
		case (int)MainMenuButtons::about:
			DrawAbout(); 
			//hookabout() or sth
			do
			{
				c = toupper(_getch());

				if (c == 'R')
				{
					setMenuStatus(false, true);
					DrawMainMenu();
					return;
				}
			} while (c != 'R');

			break;
		case (int)MainMenuButtons::exit:
			exit(0);
			break; 
		}
	}
	else if (mode == Mode::settings)
	{
		switch (command)
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

void Menu::setButtons(const vector<Button>& newButtons)
{
	buttons.clear(); 
	for (Button button : newButtons)
	{
		buttons.push_back(button); 
	}
}
