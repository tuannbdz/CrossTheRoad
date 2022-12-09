#include "Game.h"

void Game::ProcessTLight() {
	int i = 0;
	while (t_running) {
		this_thread::sleep_for(milliseconds(500));
		i = (i + 1) % 50;
		for (auto& x : tlight) {
			if (i % x.GetTimeOut() == 0) {
				x.SetState(x.IsGreen() ^ 1);
			}
		}
	}
}

void Game::ProcessGame() {
	this_thread::sleep_for(milliseconds(10));
	while (isRunning() && t_running) {
		UpdatePlayer(); //update player's status
		UpdateGameStatus();
		UpdateTLight();
		if (GetLevel() == 1)
		{
			if (GetTLight()[0].IsGreen())
				UpdateBike();
			else DrawBike();

			if (GetTLight()[1].IsGreen())
				UpdateCar();
			else DrawCar();
		}
		else
		if (GetLevel() == 2) {
			if (GetTLight()[0].IsGreen())
				UpdateCar();
			else DrawCar();

			if (GetTLight()[1].IsGreen())
				UpdateTruck();
			else DrawTruck();

			if (GetTLight()[2].IsGreen())
				UpdateBike();
			else DrawBike();
		}
		else
		if (GetLevel() == 3)
		{
			if (GetTLight()[3].IsGreen())
				UpdateBike();
			else DrawBike();

			if (GetTLight()[2].IsGreen())
				UpdateCar();
			else DrawCar();

			if (GetTLight()[1].IsGreen())
				UpdateShark();
			else DrawShark();

			if (GetTLight()[0].IsGreen())
				UpdateTruck();
			else DrawTruck();
		}
	}
}

void Game::Init() {
	t_running = 1;
	g_running = 1;
	score = 0, level = 1;
	pl.SetState(1);
	InitLevel(level);

}

void Game::StartGame() {
	setg_music();
	DrawGame();
	//checks before assigning thread or else abort() will be called
	if (t_game.joinable())
		t_game.join();
	if (t_tlight.joinable())
		t_tlight.join();
	t_game = thread(&Game::ProcessGame, this);
	t_tlight = thread(&Game::ProcessTLight, this);

	while (isRunning()) {
		if (Console::KeyPress(KeyCode::ESC)) {
			if (t_running) {
				ExitGame();
			}
		}
		else
		if (Console::KeyPress(KeyCode::R)) {
			PauseGame();
		}
		else
		if (Console::KeyPress(KeyCode::L)) {
			SaveGame();
		}
		else
		if (Console::KeyPress(KeyCode::T)) {
			LoadGame();
		}
	}
	if (t_running)
	{
		t_running = 0;
		t_game.join();
		if (t_tlight.joinable()) t_tlight.join();
		GameOver();
	}
}

void Game::Run() {
BLOCK1:
	ClearData();
	//Init();
	if (menu.getIsRunning() && !menu.getGameStartedStatus()) {
		menu.Run();
	}
	if (menu.getGameStartedStatus() && !menu.getIsRunning()) {
		InitLevel(menu.getStartLevel()); 
		setbg_music();
		if (Getbg_mucsic())
			Sound();
		string fileName = menu.Load();
		if (fileName.size()) {
			ReadGame(fileName);
			menu.SetLoad("");
		}
		StartGame();
	}

	goto BLOCK1;
}

void Game::InitLevel(int _l) {
	t_running = 1;
	g_running = 1;
	level = _l;
	pl.SetState(1);
	setMap();

	if (level == 1) {
		numIdlePl = 1;
		pl.SetXY(78, 28);

		tlight.resize(2);
		tlight[0].SetXY(3, 11);
		tlight[1].SetXY(3, 22);
		tlight[0].SetTimeOut(2);
		tlight[1].SetTimeOut(3);

		bike.push_back(new Bike());
		bike.push_back(new Bike(50, 12));
		bike.push_back(new Bike(70, 12));
		bike.push_back(new Bike(90, 12));
		bike.push_back(new Bike(110, 12));
		bike.push_back(new Bike(130, 12));
		bike.push_back(new Bike(150, 12));

		car.push_back(new Car(35, 23));
		car.push_back(new Car(55, 23));
		car.push_back(new Car(80, 23));
		car.push_back(new Car(105, 23));
		car.push_back(new Car(130, 23));

		speed = 30;
	}
	else
	if (level == 2) {
		numIdlePl = 2;
		pl.SetXY(78, 30);

		tlight.resize(3);
		tlight[0].SetXY(3, 11);
		tlight[1].SetXY(3, 18);
		tlight[2].SetXY(3, 24);
		tlight[0].SetTimeOut(2);
		tlight[1].SetTimeOut(2);
		tlight[2].SetTimeOut(3);

		bike.push_back(new Bike(30, 25));
		bike.push_back(new Bike(50, 25));
		bike.push_back(new Bike(70, 25));
		bike.push_back(new Bike(90, 25));
		bike.push_back(new Bike(110, 25));
		bike.push_back(new Bike(130, 25));
		bike.push_back(new Bike(150, 25));

		car.push_back(new Car(35, 12));
		car.push_back(new Car(55, 12));
		car.push_back(new Car(80, 12));
		car.push_back(new Car(105, 12));
		car.push_back(new Car(130, 12));

		tr.push_back(new Truck(60, 18));
		tr.push_back(new Truck(90, 18));
		tr.push_back(new Truck(120, 18));
		tr.push_back(new Truck(150, 18));

		speed = 10;
	}
	else
	{
		numIdlePl = 3;
		pl.SetXY(78, 33);

		tlight.resize(4);
		tlight[0].SetXY(3, 28);
		tlight[1].SetXY(3, 23);
		tlight[2].SetXY(3, 17);
		tlight[3].SetXY(3, 12);

		tlight[0].SetTimeOut(2);
		tlight[1].SetTimeOut(3);
		tlight[2].SetTimeOut(3);
		tlight[3].SetTimeOut(3);

		tr.push_back(new Truck());
		tr.push_back(new Truck(60, 28));
		tr.push_back(new Truck(90, 28));
		tr.push_back(new Truck(120, 28));
		tr.push_back(new Truck(150, 28));

		shark.push_back(new Shark(0, 23));
		shark.push_back(new Shark(40, 23));
		shark.push_back(new Shark(80, 23));
		shark.push_back(new Shark(110, 23));

		car.push_back(new Car());
		car.push_back(new Car(55, 17));
		car.push_back(new Car(80, 17));
		car.push_back(new Car(105, 17));
		car.push_back(new Car(130, 17));

		bike.push_back(new Bike());
		bike.push_back(new Bike(50, 12));
		bike.push_back(new Bike(70, 12));
		bike.push_back(new Bike(90, 12));
		bike.push_back(new Bike(110, 12));
		bike.push_back(new Bike(130, 12));
		bike.push_back(new Bike(150, 12));

		
	}
}

void Game::setMap()
{
	g_board.clear(); 

	switch (level)
	{
	case 1: 
		g_board.push_back(L"██████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████"); 
		g_board.push_back(L"                                                                                                                          "); 
		g_board.push_back(L"                                                                                                                          "); 
		g_board.push_back(L"                                                                                                                          "); 
		g_board.push_back(L"▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄"); 
		g_board.push_back(L"                                                                                                                          "); 
		g_board.push_back(L"                                                                                                                          "); 
		g_board.push_back(L"                                                                                                                          ");
		g_board.push_back(L"                                                                                                                          ");
		g_board.push_back(L"                                                                                                                          ");
		g_board.push_back(L"  ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■  ");
		g_board.push_back(L"                                                                                                                          ");
		g_board.push_back(L"                                                                                                                          ");
		g_board.push_back(L"                                                                                                                          ");
		g_board.push_back(L"                                                                                                                          "); 
		g_board.push_back(L"  ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■  "); 
		g_board.push_back(L"                                                                                                                          ");
		g_board.push_back(L"                                                                                                                          ");
		g_board.push_back(L"                                                                                                                          ");
		g_board.push_back(L"                                                                                                                          ");
		g_board.push_back(L"                                                                                                                          ");
		g_board.push_back(L"▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄");
		g_board.push_back(L"                                                                                                                          ");
		g_board.push_back(L"                                                                                                                          ");
		g_board.push_back(L"                                                                                                                          ");
		g_board.push_back(L"██████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████");
		break; 
	case 2: 
		g_board.push_back(L"██████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████");
	    g_board.push_back(L"                                                                                                                          ");
		g_board.push_back(L"                                                                                                                          "); 
	    g_board.push_back(L"                                                                                                                          "); 
		g_board.push_back(L"▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄"); 
	    g_board.push_back(L"                                                                                                                          "); 
	    g_board.push_back(L"                                                                                                                          "); 
	    g_board.push_back(L"                                                                                                                          "); 
	    g_board.push_back(L"                                                                                                                          "); 
	    g_board.push_back(L"                                                                                                                          "); 
	    g_board.push_back(L"                                                                                                                          "); 
	    g_board.push_back(L"  ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■  "); 
	    g_board.push_back(L"                                                                                                                          "); 
	    g_board.push_back(L"                                                                                                                          "); 
	    g_board.push_back(L"                                                                                                                          "); 
	    g_board.push_back(L"                                                                                                                          "); 
	    g_board.push_back(L"                                                                                                                          "); 
	    g_board.push_back(L"  ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■  "); 
	    g_board.push_back(L"                                                                                                                          "); 
	    g_board.push_back(L"                                                                                                                          "); 
	    g_board.push_back(L"                                                                                                                          "); 
	    g_board.push_back(L"                                                                                                                          "); 
	    g_board.push_back(L"                                                                                                                          "); 
	    g_board.push_back(L"▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄"); 
	    g_board.push_back(L"                                                                                                                          "); 
	    g_board.push_back(L"                                                                                                                          "); 
	    g_board.push_back(L"                                                                                                                          "); 
	    g_board.push_back(L"██████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████"); 
		break; 
	case 3: 
		g_board.push_back(L"██████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████"); 
		g_board.push_back(L"                                                                                                                          "); 
		g_board.push_back(L"                                                                                                                          "); 
		g_board.push_back(L"                                                                                                                          "); 
		g_board.push_back(L"▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄"); 
		g_board.push_back(L"                                                                                                                          "); 
		g_board.push_back(L"                                                                                                                          "); 
		g_board.push_back(L"                                                                                                                          "); 
		g_board.push_back(L"                                                                                                                          "); 
		g_board.push_back(L"                                                                                                                          "); 
		g_board.push_back(L"  ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■  "); 
		g_board.push_back(L"                                                                                                                          "); 
		g_board.push_back(L"                                                                                                                          "); 
		g_board.push_back(L"                                                                                                                          "); 
		g_board.push_back(L"                                                                                                                          "); 
		g_board.push_back(L"  ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■  "); 
		g_board.push_back(L"                                                                                                                          "); 
		g_board.push_back(L"                                                                                                                          "); 
		g_board.push_back(L"                                                                                                                          "); 
		g_board.push_back(L"                                                                                                                          "); 
		g_board.push_back(L"                                                                                                                          "); 
		g_board.push_back(L"  ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■        ■■■■■■  "); 
		g_board.push_back(L"                                                                                                                          "); 
		g_board.push_back(L"                                                                                                                          "); 
		g_board.push_back(L"                                                                                                                          "); 
		g_board.push_back(L"                                                                                                                          "); 
		g_board.push_back(L"▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄"); 
		g_board.push_back(L"                                                                                                                          "); 
		g_board.push_back(L"                                                                                                                          "); 
		g_board.push_back(L"                                                                                                                          "); 
		g_board.push_back(L"██████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████"); 
		break; 
	}
}

void Game::setg_music() {
	this->g_music = menu.getgMusic();
}

void Game::setbg_music() {
	this->bg_music = menu.getbgMusic();
}

void Game::ResetGame() {
	Graphics::ClearScreen(); 

	for (auto& i : car)
		delete i;
	for (auto& i : tr)
		delete i;
	for (auto& i : shark)
		delete i;
	for (auto& i : bike)
		delete i;
	car.clear();
	tr.clear();
	shark.clear();
	bike.clear();
	g_board.clear();

	InitLevel(level);
}

Game::Game() {
	Init();
}

Game::Game(int _l) {
	InitLevel(_l);
}

Game::~Game(){
	for (auto& i : car)
		delete i;
	for (auto& i : tr)
		delete i;
	for (auto& i : shark)
		delete i;
	for (auto& i : bike)
		delete i;
	g_board.clear();
	car.clear();
	tr.clear();
	shark.clear();
	bike.clear();
}

Player& Game::GetPlayer() {
	return pl;
}

vector<TLight>& Game::GetTLight() {
	return tlight;
}

int Game::GetLevel() {
	return level;
}

bool Game::Getg_mucsic() {
	return g_music;
}

bool Game::Getbg_mucsic() {
	return bg_music;
}

void Game::Sound()
{
	PlaySound(L"music/bgmusic.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}

void Game::DrawGame() {
	Graphics::ClearScreen();

	Graphics::DrawGraphics({ 10, 2 }, "graphics/Game/levels/level_frame_start.txt", Graphics::GetColor(Color::lightblue, Color::brightwhite));
	Graphics::DrawGraphics(g_board, { 10, 6 }, 0, 0, g_board[0].size(), g_board.size(), Graphics::GetColor(Color::gray, Color::brightwhite));
	DrawLevel();
	DrawScore();

	Console::SetFont(L"Consolas Bold");
	//Draw instructions
	Console::SetColor(Graphics::GetColor(Color::brightwhite, Color::blue)); 
	Graphics::DrawGraphics({138, 22}, "graphics/Game/instruction_frame.txt", Graphics::GetColor(Color::brightwhite, Color::blue));
	Graphics::DrawTexts("There are 3 levels. Each level.", { 140, 23 }); 
	Graphics::DrawTexts("rewarded you 300 score.", { 140, 24 });
	Graphics::DrawTexts("Obstacle speed is increased", { 140, 25 });
	Graphics::DrawTexts("after each level.", { 140, 26 });
	Graphics::DrawTexts("Traffic lights are helpful.", { 140, 27 });

	Graphics::DrawGraphics({ 138, 2 }, "graphics/Game/controls.txt", Graphics::GetColor(Color::brightwhite, Color::blue));

	DrawIdlePl();
}

void Game::DrawEmptyBoard() {
	Graphics::DrawGraphics(g_board, { 10, 6 }, 0, 0, g_board[0].size(), g_board.size(), Graphics::GetColor(Color::gray, Color::brightwhite));
}

template <class T> void drawVector(vector<T*>& obj) {
	for (auto& o : obj)
		o->UpdateSprite();
}

void Game::ExitGame() {
	if (t_running == 0) return;
	//pause game for pop up
	if (t_running) {
		t_running = 0;
		if (t_game.joinable()) t_game.join();
		if (t_tlight.joinable()) t_tlight.join();
	}

	Graphics::DrawGraphics({ 48, 16 }, "graphics/Game/game_over/game_over_frame.txt", Graphics::GetColor(Color::brightwhite, Color::lightblue));
	Color unselectedColor = Graphics::GetColor(Color::brightwhite, Color::blue),
		selectedColor = Graphics::GetColor(Color::brightwhite, Color::yellow);
	Graphics::DrawTexts("EXIT GAME ?", { 60, 18 }, unselectedColor);

	Button b_yes("YES", { 60, 19 });
	Graphics::DrawTexts("YES", { 60, 19 }, unselectedColor);

	Button b_no("NO", { 60, 20 });
	Graphics::DrawTexts("NO", { 60, 20 }, unselectedColor);

	vector<Button>buttons = { b_yes, b_no };

	bool game_over_running = 1;

	int cY = 20, command = 0;
	int pY = cY, pC = command, cX = 56;


	do
	{
		int n = buttons.size();
		//reset color of previous command
		if (pY != cY) {
			Console::gotoxy(cX, pY);
			buttons[pC].Draw(unselectedColor);
		}

		Console::gotoxy(cX, cY);
		buttons[command].Draw(selectedColor);

		if (Console::KeyPress(KeyCode::ENTER)) {
			this_thread::sleep_for(milliseconds(50));
			if (command == 0)
			{
				g_running = 0;
				menu.setMenuStatus(0, 1);
			}
			else
			{
				Graphics::DrawGraphics(g_board, { 48, 16 }, 39, 10, 44, 11, Graphics::GetColor(Color::gray, Color::brightwhite));
				t_running = 1;
				t_game = thread(&Game::ProcessGame, this);
				t_tlight = thread(&Game::ProcessTLight, this);
			}
			game_over_running = false;
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

	} while (game_over_running);
	fflush(stdin);

}

bool Game::isCollide(const int& x1, const int& y1, const int& x2, const int& y2, const int& x3, const int& y3, const int& x4, const int& y4) {
	bool c1 = min(x2, x4) > max(x1, x3);
	bool c2 = min(y2, y4) > max(y1, y3);
	return c1 && c2;
}

bool Game::isRunning() {
	return g_running;
}

bool Game::isWinning() {
	return numIdlePl == 0;
}

void Game::ClearData() {
	for (auto& i : car)
		delete i;
	for (auto& i : tr)
		delete i;
	for (auto& i : shark)
		delete i;
	for (auto& i : bike)
		delete i;
	car.clear();
	tr.clear();
	shark.clear();
	bike.clear();
	idlePl.clear();
}

template <class T> void writeBin(ostream& out, T& data) {
	out.write(reinterpret_cast<char*>(&data), sizeof(data));
}

template <class T> void readBin(istream& in, T& data) {
	in.read(reinterpret_cast<char*>(&data), sizeof(data));
}

template <class T> void writeVector(ostream& out, vector<T*>& obj) {
	int vecSize = obj.size();
	writeBin(out, vecSize);
	for (auto& o : obj) {
		int oX = o->GetX(), oY = o->GetY(), oSp = o->GetSpeed(), oDir = o->GetDir();
		writeBin(out, oX);
		writeBin(out, oY);
		writeBin(out, oSp);
		writeBin(out, oDir);
	}
}

template <class T> void readVector(istream& in, vector<T*>& obj) {
	int vecSize;
	readBin(in, vecSize);
	obj.clear();
	obj.resize(vecSize);
	for (auto& o : obj) {
		o = new T();
		int oX, oY, oSp, oDir;
		readBin(in, oX);
		readBin(in, oY);
		readBin(in, oSp);
		readBin(in, oDir);
		o->SetData(oX, oY, oSp, oDir);
	}
}

void Game::SaveGame() {
	if (t_running == 0) return;
	t_running = 0;
	if(t_tlight.joinable()) t_tlight.join();
	if(t_game.joinable()) t_game.join();

	// save game
	// draw input board
	Graphics::DrawGraphics({ 50, 15 }, "graphics/game/save_game_input_board.txt", Graphics::GetColor(Color::brightwhite, Color::blue));
	Console::GotoXY({ 71, 18 });
	::FlushConsoleInputBuffer(Console::inputHandle());
	Console::setCursor(1);
	int curX = 71;
	string fileName;
	while (1) {
		Console::gotoxy(curX, 18);
		char c = _getch();
		if (c == KEY_DOWN) { // Down to return
			Graphics::DrawGraphics(g_board, { 50, 15 }, 41, 9, 48, 10, Graphics::GetColor(Color::gray, Color::brightwhite));
			//DrawEmptyBoard();
			Console::setCursor(0);
			t_running = 1;
			t_game = thread(&Game::ProcessGame, this);
			t_tlight = thread(&Game::ProcessTLight, this);
			return;
		}
		if (c == KEY_ENTER)
		{
			if (fileName.size() > 0)
				break;
			else {
				Graphics::DrawTexts("Filename must not be empty.", { 50, 23 }); 
				Sleep(1000); 
				Graphics::RemoveArea({ 50, 23 }, { 80, 23 });
				continue; 
			}
		}
		
		if (c == KEY_BACKSPACE){

			if (curX == 71)
				continue;
			::FlushConsoleInputBuffer(Console::inputHandle());
			Console::gotoxy(--curX, 18);
			Graphics::DrawTexts(" ", Graphics::GetColor(Color::brightwhite, Color::blue));
			Console::gotoxy(curX, 18);
			fileName.pop_back();
			continue;
		}
		if (fileName.size() < 17) {
			string cc;
			cc += c;
			Console::gotoxy(curX++, 18);
			Graphics::DrawTexts(cc, Graphics::GetColor(Color::brightwhite, Color::blue));
			fileName += c;
		}
	}

	ofstream out("save_game_files/" + fileName + ".bin", ios::binary);
	// write player
	int pX = pl.GetX(), pY = pl.GetY(), state = pl.GetState();
	writeBin(out, pX);
	writeBin(out, pY);
	writeBin(out, state);
	writeBin(out, score);
	writeBin(out, level);

	// write idlePl needed to pass current level
	writeBin(out, numIdlePl);

	// write current idle on this level
	int idlePlSize = idlePl.size();
	writeBin(out, idlePlSize);
	for (auto& i : idlePl)
		writeBin(out, i);

	// write traffic lights
	int tlsize = tlight.size();
	writeBin(out, tlsize);
	for (auto& l : tlight) {
		bool state = l.IsGreen();
		int lx = l.GetX();
		int ly = l.GetY();
		int timeOut = l.GetTimeOut();
		writeBin(out, lx);
		writeBin(out, ly);
		writeBin(out, timeOut);
		writeBin(out, state);
	}

	// write obstacles
	writeVector<Truck>(out, tr);
	writeVector<Car>(out, car);
	writeVector<Bike>(out, bike);
	writeVector<Shark>(out, shark);
	
	// write bool
	writeBin(out, g_running);
	writeBin(out, t_running);
	
	writeBin(out, bg_music);
	writeBin(out, g_music);
	
	out.close();
	Graphics::DrawGraphics(g_board, { 50, 15 }, 50 - boardX + 1, 15 - boardY, 44, 9, Graphics::GetColor(Color::gray, Color::brightwhite));

	Console::setCursor(0);
	t_running = 1;
	t_game = thread(&Game::ProcessGame, this);
	t_tlight = thread(&Game::ProcessTLight, this);
}

void Game::ReadGame(string fileName) {
	ifstream in("save_game_files/" + fileName, ios::binary);
	// read player
	int x, y, state;
	readBin(in, x);
	readBin(in, y);
	readBin(in, state);
	pl.SetData(x, y, state);

	readBin(in, score);
	readBin(in, level);

	// write idlePl needed to pass current level
	readBin(in, numIdlePl);

	// write current idle on this level
	int idlePlSize;
	readBin(in, idlePlSize);
	idlePl.resize(idlePlSize);
	for (auto& i : idlePl)
		readBin(in, i);

	// read traffic lights
	int tlightSize;
	readBin(in, tlightSize);
	tlight.resize(tlightSize);
	for (auto& l : tlight) {
		bool state;
		int lx, ly, timeOut;
		readBin(in, lx);
		readBin(in, ly);
		readBin(in, timeOut);
		readBin(in, state);
		l.SetData(lx, ly, state, timeOut);
	}

	// read obstacles
	readVector<Truck>(in, tr);
	readVector<Car>(in, car);
	readVector<Bike>(in, bike);
	readVector<Shark>(in, shark);

	// read bool
	readBin(in, g_running);
	readBin(in, t_running);

	readBin(in, bg_music);
	readBin(in, g_music);

	in.close();

	setMap();
}

void Game::LoadGame() {
	if (t_running == 0) return;
	t_running = 0;
	if (t_game.joinable()) t_game.join();
	if (t_tlight.joinable()) t_tlight.join();
	string fileName = menu.HookLoadGame(50, 6);
	if (fileName.size()) {
		ReadGame(fileName);
		DrawGame();
	} else
	//DrawGame();
		Graphics::DrawGraphics(g_board, { 50, 6 }, 50 - boardX, 6 - boardY, 63, 24, Graphics::GetColor(Color::gray, Color::brightwhite));
	//Graphics::DrawGraphics({ 58, 6 }, "graphics/Menu/load_game_frame.txt", Graphics::GetColor(Color::lightblue, Color::lightyellow));
	t_running = 1;
	t_game = thread(&Game::ProcessGame, this);
	t_tlight = thread(&Game::ProcessTLight, this);

}

void Game::PauseGame() {
	if (t_running) {
		t_running = 0;
		if (t_game.joinable()) t_game.join();
		if (t_tlight.joinable()) t_tlight.join();
		Graphics::DrawGraphics({ 48, 16 }, "graphics/Game/pause_frame.txt", Graphics::GetColor(Color::brightwhite, Color::blue));
		Graphics::DrawGraphics({ 55, 15 }, "graphics/Game/pause_text.txt", Graphics::GetColor(Color::brightwhite, Color::blue));
		
		Graphics::DrawTexts("GAME IS PAUSED.", { 60, 19 }, Graphics::GetColor(Color::brightwhite, Color::yellow));
		Graphics::DrawTexts("PRESS R TO RESUME.", { 60, 20 }, Graphics::GetColor(Color::brightwhite, Color::yellow));

	}
	else {
		Graphics::DrawGraphics(g_board, { 48, 15 }, 39, 9, 42, 11, Graphics::GetColor(Color::gray, Color::brightwhite));
		t_running = 1;
		t_game = thread(&Game::ProcessGame, this);
		t_tlight = thread(&Game::ProcessTLight, this);
	}
}

void Game::GameOver()
{
	ClearData();
	this_thread::sleep_for(milliseconds(20));
	for (int i = 0; i < 3; i++)
	{
		pl.SetSprite({ L"\\0/", L" | ", L"/ \\" });
		pl.Draw(); 
		this_thread::sleep_for(milliseconds(100));
		pl.SetSprite({ L" 0 ", L"/|\\", L"/ \\" });
		pl.Draw(); 
		this_thread::sleep_for(milliseconds(100));
	}
	//Graphics::ClearScreen(); 

	//--------------Draw animation
	DrawEmptyBoard();
	vector<string> firework = Graphics::GetGraphics("graphics/Game/game_over/firework_flying.txt");
	vector<string>effect1 = Graphics::GetGraphics("graphics/Game/game_over/firework_effect.txt"); 
	vector<string>effect2 = Graphics::GetGraphics("graphics/Game/game_over/firework_effect2.txt");

	short x_pos = 28, y_pos = 26 - (level == 1 ? 5 : level == 2 ? 3 : 0);
	Color color = Graphics::GetColor(Color::gray, Color::lightyellow),
		colorON = Graphics::GetColor(Color::gray, Color::lightyellow),
		colorOFF = Graphics::GetColor(Color::gray, Color::lightred); 

	int row = g_board.size(), col = g_board[0].size(); 
	int fw_row = firework.size(), fw_col = firework[0].size(); 
	int curCol = 18; 

	while (x_pos < 100 && y_pos >= 18)
	{
		Graphics::DrawGraphics(firework, { x_pos, y_pos }, color);

		Sleep(200); 
		//Graphics::RemoveArea({ x_pos, y_pos }, {short( x_pos + firework[0].size() + 1), (short)(y_pos + firework.size() - 1)});
		int d = y_pos - boardY + fw_row  - 1;
		Graphics::DrawGraphics(g_board, { x_pos, y_pos }, x_pos - boardX, y_pos - boardY, fw_col + 2, (d > g_board.size() ? g_board.size() - (y_pos - boardY) : fw_row), Graphics::GetColor(Color::gray, Color::brightwhite));
		//Graphics::DrawGraphics(g_board, { 10, 6 }, 0, 0, g_board[0].size(), g_board.size(), Graphics::GetColor(Color::gray, Color::brightwhite));

		x_pos += 10, y_pos -= 4; 
		curCol += fw_col + 2;
		row -= 4;
	}

	Console::SetFont(L"Consolas Bold");
	for (int i = 0; i < 4; ++i)
	{
		Graphics::DrawGraphics(effect1, { x_pos, y_pos }, colorON);
		Sleep(140);
		Graphics::DrawGraphics(g_board, { x_pos, y_pos }, curCol, row - fw_row - 1, fw_col + 40, fw_row, Graphics::GetColor(Color::gray, Color::brightwhite));
		Graphics::DrawGraphics(effect2, { x_pos, y_pos }, colorOFF);
		Sleep(140);
		Graphics::DrawGraphics(g_board, { x_pos, y_pos }, curCol, row - fw_row - 1, fw_col + 40, fw_row, Graphics::GetColor(Color::gray, Color::brightwhite));
	}
	//--------------End of animation
	Color unselectedColor = Graphics::GetColor(Color::brightwhite, Color::blue),
		selectedColor = Graphics::GetColor(Color::brightwhite, Color::yellow);

	//Graphics::drawBlueGradientGraphics({ 10, 0 }, "graphics/Menu/title.txt");
	Graphics::DrawGraphics({ 60, 16 }, "graphics/Game/game_over/game_over_frame.txt", Graphics::GetColor(Color::brightwhite, Color::lightblue));
	Graphics::DrawGraphics({ 64, 15 }, "graphics/Game/game_over/game_over_text.txt", Graphics::GetColor(Color::brightwhite, Color::lightblue));

	Button b_replay("REPLAY", { 73, 20 });
	Graphics::DrawTexts("REPLAY", { 73, 20 }, unselectedColor);

	Button b_menu("BACK TO MENU", { 73, 21 });
	Graphics::DrawTexts("BACK TO MENU", { 73, 21 }, unselectedColor);

	vector<Button>buttons = {b_replay, b_menu };

	bool game_over_running = 1;

	int cY = 20, command = 0;
	int pY = cY, pC = command, cX = 56;
	

	do
	{
		int n = buttons.size();
		//reset color of previous command
		if (pY != cY) {
			Console::gotoxy(cX, pY);
			buttons[pC].Draw(unselectedColor);
		}

		Console::gotoxy(cX, cY);
		buttons[command].Draw(selectedColor);

		if (Console::KeyPress(KeyCode::ENTER)) {
			this_thread::sleep_for(milliseconds(50));
			if (command == 0)
			{
				//replay
				menu.setMenuStatus(1, 0);
			}
			else
			{
				//back to menu
				menu.setMenuStatus(0, 1);
			}
			game_over_running = false;
		}
		else
			if (Console::KeyPress(KeyCode::UP) || Console::KeyPress(KeyCode::W)){
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

	} while (game_over_running);
	fflush(stdin);
}

void Game::UpdateGameStatus() {
	if (pl.GetState() == 0) {
		g_running = 0;
	}
	else if (pl.GetState() == 2) {
		if (numIdlePl > 1)
		{
			idlePl.push_back(pl.GetX());
			numIdlePl--;
			score += 100;
			DrawScore();
		}
		else
		{
			if(level ==  3) g_running = 0;
			else
			{
				ClearData();
				InitLevel(level + 1);
				score += 300;
				DrawGame();
			}
		}
		pl = Player(78, (level == 3 ? 33 : level == 2 ? 30 : 28));
	}
}

void Game::UpdatePlayer() {
	pl.Move();
	this_thread::sleep_for(milliseconds(speed));

	if (pl.GetY() == 7) {
		pl.SetState(2);
		return;
	}
	for (auto& i : car) {
		if (isCollide(pl.GetX(), pl.GetY(), pl.GetX() + 2, pl.GetY() + 3, i->GetX(), i->GetY(), i->GetBX(), i->GetBY())) {
			if(Getg_mucsic())
				i->Sound();
			pl.SetState(0);
			return;
		}
	}
	for (auto& i : tr) {
		if (isCollide(pl.GetX(), pl.GetY(), pl.GetX() + 2, pl.GetY() + 3, i->GetX(), i->GetY(), i->GetBX(), i->GetBY())) {
			if (Getg_mucsic())
				i->Sound();
			pl.SetState(0);
			return;
		}
	}
	for (auto& i : shark) {
		if (isCollide(pl.GetX(), pl.GetY(), pl.GetX() + 2, pl.GetY() + 3, i->GetX(), i->GetY(), i->GetBX(), i->GetBY())) {
			if (Getg_mucsic())
				i->Sound();
			pl.SetState(0);
			return;
		}
	}
	for (auto& i : bike) {
		if (isCollide(pl.GetX(), pl.GetY(), pl.GetX() + 2, pl.GetY() + 3, i->GetX(), i->GetY(), i->GetBX(), i->GetBY())) {
			if (Getg_mucsic())
				i->Sound();
			pl.SetState(0);
			return;
		}
	}

	for (auto& i : idlePl) {
		if (isCollide(pl.GetX(), pl.GetY(), pl.GetX() + 2, pl.GetY() + 2, i - 1, 7, i + 3, 10)) {
			pl.SetState(0);
			return;
		}
	}
}

void Game::UpdateCar() {
	for(auto &i : car)
		i->Move();
}

void Game::UpdateTruck() {
	for (auto& i : tr)
		i->Move();
}

void Game::UpdateBike() {
	for (auto& i : bike)
		i->Move();
}

void Game::UpdateShark() {
	for (auto& i : shark)
		i->Move();
}

void Game::UpdateTLight() {
	for (auto& t : tlight)
		t.DrawSelf();
}

void Game::DrawBike() {
	drawVector(bike);
}

void Game::DrawTruck() {
	drawVector(tr);
}

void Game::DrawCar() {
	drawVector(car);
}

void Game::DrawShark() {
	drawVector(shark);
}

void Game::DrawIdlePl() {
	Console::SetColor(Graphics::GetColor(Color::gray, Color::brightwhite));
	for (auto& x : idlePl) {
		Console::gotoxy(x, 7);
		cerr << " O ";
		Console::gotoxy(x, 8);
		cerr << "/|\\";
		Console::gotoxy(x, 9);
		cerr << "/ \\";
	}
}

void Game::DrawScore() {
	int t = score;
	vector <int> tmp;
	do {
		tmp.push_back(t % 10);
		t /= 10;
	} while (t);
	reverse(tmp.begin(), tmp.end());
	int preX = 10 + 110 - 1;
	int preY = 3;
	Graphics::RemoveArea({ short(preX), short(preY) }, { short(preX + 10), short(preY + 2) }, Graphics::GetColor(Color::lightblue, Color::brightwhite));
	for (auto& x : tmp)
	{
		Graphics::DrawGraphics(numberGraphics[x], {short(preX), short(preY)}, Graphics::GetColor(Color::lightblue, Color::brightwhite));
		preX += numberGraphics[x][0].size() + 1;
	}
}

void Game::DrawLevel() {
	int preX = 10 + 24;
	int preY = 3;
	//Graphics::DrawGraphics()
	Graphics::RemoveArea({ short(preX), short(preY) }, { short(preX + 3), short(preY + 2) }, Graphics::GetColor(Color::lightblue, Color::brightwhite));
	Graphics::DrawGraphics(numberGraphics[level], { short(preX), short(preY) }, Graphics::GetColor(Color::lightblue, Color::brightwhite));

}