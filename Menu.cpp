#include "Menu.h"

bool Menu::getgMusic() {
	return g_music;
}

bool Menu::getbgMusic() {
	return bg_music;
}

Menu::Menu()
{
	console = new Console();
	command = 0; 
	gameStarted = false;
	isRunning = true; 
	bg_music = true;
	g_music = true;
	g_play = true;
	g_exit = false;
	volume = 400;
	t_Sound = std::thread(&Menu::Music, this);

}


Menu::~Menu()
{
	g_exit = true;
	bg_music = true;
	g_music = false;
	g_play = false;

	Sleep(40);

	delete console;
	console = nullptr;

	t_Sound.join();
}



void Menu::setMenuStatus(bool gameStarted, bool isRunning)
{
	this->gameStarted = gameStarted; 
	this->isRunning = isRunning; 
	if(!this->isRunning && this->gameStarted)
		this->g_play = false;
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
	if(bg_music)
		buttons.push_back(Button("Background Music",	{ 75, 14 }, UNSELECTED_COLOR, "graphics/Menu/settings/bg_music_on.txt"));
	else
		buttons.push_back(Button("Background Music", { 75, 14 }, UNSELECTED_COLOR, "graphics/Menu/settings/bg_music_off.txt"));
	if(g_music)
		buttons.push_back(Button("Sound effect",		{ 75, 19 }, UNSELECTED_COLOR, "graphics/Menu/settings/sound_on.txt"));
	else
		buttons.push_back(Button("Sound effect", { 75, 19 }, UNSELECTED_COLOR, "graphics/Menu/settings/sound_off.txt"));
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
	//Graphics::ClearScreen();
	//buttons.clear();
	//Graphics::drawBlueGradientGraphics({ 10, 0 }, "graphics/Menu/title.txt");
	Graphics::DrawGraphics({ 58, 6 }, "graphics/Menu/load_game_frame.txt", Graphics::GetColor(Color::lightblue, Color::lightyellow));
	Console::SetFont(L"Consolas Bold"); 
	Graphics::DrawTexts("NAME", { 64, 8 }, Graphics::GetColor(Color::lightblue, Color::brightwhite));
	Graphics::DrawTexts("LEVEl", { 96, 8 }, Graphics::GetColor(Color::lightblue, Color::brightwhite));
	Graphics::DrawTexts("SCORE", { 110, 8 }, Graphics::GetColor(Color::lightblue, Color::brightwhite));
	Graphics::DrawTexts("BACK [B]", { 63, 36 - 4}, Graphics::GetColor(Color::lightblue, Color::brightwhite));
	Graphics::DrawTexts("RETURN [R]", { 85, 36 - 4}, Graphics::GetColor(Color::lightblue, Color::brightwhite));
	Graphics::DrawTexts("NEXT [N]", { 108, 36 - 4}, Graphics::GetColor(Color::lightblue, Color::brightwhite));
}

string Menu::HookLoadGame(short x, short y) {
	// Draw frame
	Graphics::DrawGraphics({ x, y }, "graphics/Menu/load_game_frame.txt", Graphics::GetColor(Color::lightblue, Color::lightyellow));
	Console::SetFont(L"Consolas Bold");
	Graphics::DrawTexts("NAME", { short(x + 6), short(y + 2) }, Graphics::GetColor(Color::lightblue, Color::brightwhite));
	Graphics::DrawTexts("LEVEl", { short(x + 38), short(y + 2) }, Graphics::GetColor(Color::lightblue, Color::brightwhite));
	Graphics::DrawTexts("SCORE", { short(x + 52), short(y + 2) }, Graphics::GetColor(Color::lightblue, Color::brightwhite));
	Graphics::DrawTexts("PREVIOUS PAGE [A]", { short(x + 5), short(y + 21) }, Graphics::GetColor(Color::lightblue, Color::brightwhite));
	Graphics::DrawTexts("RETURN [R]", { short(x + 27), short(y + 21) }, Graphics::GetColor(Color::lightblue, Color::brightwhite));
	Graphics::DrawTexts("NEXT PAGE [D]", { short(x + 45), short(y + 21) }, Graphics::GetColor(Color::lightblue, Color::brightwhite));

	// get file names	
	WIN32_FIND_DATAA data;
	//HANDLE hFind = FindFirstFileA("./save_game_files/*.bin", &data);
	HANDLE hFind = FindFirstFileA("./save_game_files/*.bin", &data);
	vector<string> files;
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			files.push_back(data.cFileName);
		} while (FindNextFileA(hFind, &data));

		FindClose(hFind);
	}

	Color unselectedColor = Graphics::GetColor(Color::lightblue, Color::brightwhite),
		selectedColor = Graphics::GetColor(Color::brightwhite, Color::lightblue);

	int maxLines = 19;
	// turn file names into buttons to display on the screen
	vector<vector<Button>> buttonsOfPage;
	vector<Button> buttons;
	short buttonPosY = y + 5, buttonPosX = x + 7;
	int buttonDist = 1;
	for (auto& fileName : files) {
		if (buttonPosY > y + 5 + maxLines - 1) {
			buttonsOfPage.push_back(buttons);
			buttons.clear();
			buttonPosY = y + 5;
		}
		Button b(fileName, { buttonPosX, buttonPosY });
		buttons.push_back(b);
		buttonPosY += buttonDist;
	}
	if (buttons.size() <= maxLines && buttons.size())
		buttonsOfPage.push_back(buttons);

	// if there's no file to load
	while (buttonsOfPage.size() == 0) {
		if (Console::KeyPress(KeyCode::R)) {
			return "";
		}
	}

	// now draw the buttons for the first page

	int currPage = 0;

	int currButton = 0, prevButton = 0;

	bool moveCursor = false;

DRAWPAGE:
	int lines = buttonsOfPage[currPage].size();

	for (auto& b : buttonsOfPage[currPage]) {
		b.Draw(unselectedColor);
	}
	// make the first file name selected by default
	buttonsOfPage[currPage][0].Draw(selectedColor);

	while (1) {
		if (moveCursor) {
			// draw the previous button unselected
			COORD prevPos = buttonsOfPage[currPage][prevButton].GetPos();
			Console::gotoxy(prevPos.X, prevPos.Y);
			buttonsOfPage[currPage][prevButton].Draw(unselectedColor);

			// draw current button selected
			COORD curPos = buttonsOfPage[currPage][currButton].GetPos();
			Console::gotoxy(curPos.X, curPos.Y);
			buttonsOfPage[currPage][currButton].Draw(selectedColor);
			moveCursor = false;
		}

		if (Console::KeyPress(KeyCode::UP) || Console::KeyPress(KeyCode::W)) {
			prevButton = currButton;
			currButton = (currButton + lines - 1) % lines;
			moveCursor = 1;
		}
		if (Console::KeyPress(KeyCode::DOWN) || Console::KeyPress(KeyCode::S)) {
			prevButton = currButton;
			currButton = (currButton + 1) % lines;
			moveCursor = 1;
		}
		if (Console::KeyPress(KeyCode::LEFT) || Console::KeyPress(KeyCode::A)) {
			if (currPage)
				currPage--;
			goto DRAWPAGE;
		}
		if (Console::KeyPress(KeyCode::RIGHT) || Console::KeyPress(KeyCode::D)) {
			if (currPage < buttonsOfPage.size() - 1)
				currPage++;
			goto DRAWPAGE;
		}
		if (Console::KeyPress(KeyCode::R)) {
			return "";
		}
		if (Console::KeyPress(KeyCode::ENTER)) {
			return buttons[currButton].GetText();
		}
	}
}

string Menu::Load() {
	return g_load;
}

void Menu::SetLoad(string fileName) {
	g_load = fileName;
}

void Menu::LoadGame() {
	string fileName = HookLoadGame(62, 13);
	if (fileName.size()) {
		setMenuStatus(true, false);
		g_load = fileName;
	}
	else {
		DrawMainMenu();
	}
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
	if (bg_music)
		Sound_on();
	else
		Sound_off();
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
		if (pY != cY) {
			Console::gotoxy(cX, pY);
			buttons[pC].DrawGraphics(UNSELECTED_COLOR);
		}

		Console::gotoxy(cX, cY);
		buttons[command].DrawGraphics(SELECTED_COLOR);

		//this_thread::sleep_for(milliseconds(50));
		if (Console::KeyPress(KeyCode::ENTER)) {
			this_thread::sleep_for(milliseconds(50));
			ExecuteCommands(mode);
		}
		else
			if (Console::KeyPress(KeyCode::UP) || Console::KeyPress(KeyCode::W)) {
				pY = cY;
				pC = command;
				command = (command - 1 + n) % n;
				cY = command + 5;
			}
			else
				if (Console::KeyPress(KeyCode::DOWN) || Console::KeyPress(KeyCode::S)) {
					pY = cY;
					pC = command;
					command = (command + 1) % n;
					cY = command + 5;
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
			//DrawLoadGame(); 
			LoadGame();

			break;
		case (int)MainMenuButtons::settings:
			//Graphics::RemoveArea({75, 14}, {125, 35});
			DrawSettings(); 
			ChooseCommand(75, 14, Mode::settings); 
			break;
		case (int)MainMenuButtons::about:
			DrawAbout();
			while (1)
			{
				if (Console::KeyPress(KeyCode::R)) {
					setMenuStatus(false, true);
					DrawMainMenu();
					return;
				}
			}
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
			bg_music = !bg_music;
			if (bg_music)
				Sound_on();
			else
				Sound_off();
			DrawSettings();
			ChooseCommand(75, 14, Mode::settings);
			break; 
		case (int)SettingButtons::sound: 
			g_music = !g_music;
			DrawSettings();
			ChooseCommand(75, 14, Mode::settings);
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

void Menu::Music()
{
	bool isOpen = false, isStop = false;
	console->OpenMusic(L"music/Start.mp3");

	while (g_play == true)
	{
		if (!bg_music && !isStop)
		{
			console->StopMusic();
			isStop = true;
			isOpen = false;
		}
		else if (bg_music && !isOpen)
		{
			console->PlayMusic(volume);
			isStop = false;
			isOpen = true;
		}
	}

	console->CloseMusic();
}

void Menu::Sound_on()
{
	PlaySound(L"music/Start.wav", NULL, SND_FILENAME | SND_ASYNC);
}

void Menu::Sound_off()
{
	PlaySound(0,0,0);
}





