﻿#include "Game.h"

void Game::Init() {
	t_running = 1;
	g_running = 1;
	score = 0, level = 3; 
	//g_board = Graphics::GetGraphics("Map/frame.txt");

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

	pl.SetXY(70, 33);

	setMap(); 
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

void Game::ResetGame() {
	Graphics::ClearScreen(); 
	//DrawGame(); 

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

	t_running = 1;
	g_running = 1;
	//g_board = Graphics::GetGraphics("Map/frame.txt");

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

	pl = Player(70, 33);
}

Game::Game() {
	Init();
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

void Game::DrawGame() {
	Graphics::ClearScreen();
	Graphics::DrawGraphics({ 10, 2 }, "graphics/Game/levels/level1/level1_frame_start.txt", Graphics::GetColor(Color::lightblue, Color::brightwhite));
	//Graphics::DrawGraphics({ 10, 6 }, "graphics/Game/maps/map_lvl3.txt", Graphics::GetColor(Color::gray, Color::white));
	Graphics::DrawGraphics(g_board, { 10, 6 }, 0, 0, g_board[0].size(), g_board.size(), Graphics::GetColor(Color::gray, Color::brightwhite));
	Console::SetFont(L"Consolas Bold"); //but if Console::SetFont(L"Consolas"); is called, text is immediately changed to normal
	Graphics::DrawGraphics({ 138, 20 }, "graphics/Game/load_game_ingame.txt", Graphics::GetColor(Color::brightwhite, Color::blue));
	Graphics::DrawGraphics({ 138, 2 }, "graphics/Game/controls.txt", Graphics::GetColor(Color::brightwhite, Color::blue));
}


void Game::ExitGame(thread& t, Game* & g, Menu& menu) {
	t_running = 0;
	if (t.joinable())
		t.join();
	menu.setMenuStatus(0, 1); 
	delete g; 
	g = NULL; 
}

bool Game::isCollide(const int& x1, const int& y1, const int& x2, const int& y2, const int& x3, const int& y3, const int& x4, const int& y4) {
	bool c1 = min(x2, x4) > max(x1, x3);
	bool c2 = min(y2, y4) > max(y1, y3);
	return c1 && c2;
}

bool Game::isRunning() {
	return g_running;
}
void Game::PauseGame(thread& t, void (*func)()) {
	if (t_running) {
		t_running = 0;
		t.join();
		Graphics::DrawGraphics({ 48, 15 }, "graphics/Game/pause_frame.txt", Graphics::GetColor(Color::gray, Color::lightblue));
		Graphics::DrawTexts("GAME IS PAUSED.", { 60, 19 }, Graphics::GetColor(Color::gray, Color::brightwhite));
		Graphics::DrawTexts("PRESS R TO RESUME.", { 60, 20 }, Graphics::GetColor(Color::gray, Color::brightwhite));
	}
	else {
		Graphics::DrawGraphics(g_board, { 48, 15 }, 39, 9, 42, 11, Graphics::GetColor(Color::gray, Color::brightwhite));
		t_running = 1;
		t = thread(func);
	}
}

void Game::GameOver(void (*func)(), Menu& menu)
{
	pl.SetSprite({ L"\\0/", L" |", L"/ \\" });
	pl.Draw(); 
	Sleep(100); 
	Graphics::ClearScreen(); 

	//--------------Draw animation
	vector<string> firework = Graphics::GetGraphics("graphics/Game/game_over/firework_flying.txt");
	vector<string>effect1 = Graphics::GetGraphics("graphics/Game/game_over/firework_effect.txt"); 
	vector<string>effect2 = Graphics::GetGraphics("graphics/Game/game_over/firework_effect2.txt");

	short x_pos = 3, y_pos = 30;
	Color color = Graphics::GetColor(Color::brightwhite, Color::red),
		colorON = Graphics::GetColor(Color::brightwhite, Color::lightblue),
		colorOFF = Graphics::GetColor(Color::brightwhite, Color::lightred); 

	while (x_pos < 100 && y_pos >= 5)
	{
		Graphics::DrawGraphics(firework, { x_pos, y_pos }, color);
		Sleep(140); 
		Graphics::RemoveArea({ x_pos, y_pos }, {short( x_pos + 10), (short)(y_pos + 9) }); 
		x_pos += 10, y_pos -= 4; 
	}

	Console::SetFont(L"Consolas Bold");
	for (int i = 0; i < 4; ++i)
	{
		Graphics::DrawGraphics(effect1, { x_pos, y_pos }, colorON);
		Sleep(140);
		Graphics::RemoveArea({ (short)(x_pos + 40), y_pos }, { (short)(x_pos + 55), (short)(y_pos + 10) });
		Graphics::DrawGraphics(effect2, { x_pos, y_pos }, colorOFF);
		Sleep(140);
		Graphics::RemoveArea({ (short)(x_pos + 40), y_pos }, { (short)(x_pos + 55), (short)(y_pos + 10) });
	}
	//--------------End of animation
	Color unselectedColor = Graphics::GetColor(Color::brightwhite, Color::blue),
		selectedColor = Graphics::GetColor(Color::brightwhite, Color::yellow);

	Graphics::drawBlueGradientGraphics({ 10, 0 }, "graphics/Menu/title.txt");
	Graphics::DrawGraphics({ 70, 15 }, "graphics/Game/game_over/game_over_frame.txt", Graphics::GetColor(Color::brightwhite, Color::lightblue));

	Button b_replay("REPLAY", { 83, 20 });
	Graphics::DrawTexts("REPLAY", { 83, 20 }, unselectedColor);

	Button b_menu("BACK TO MENU", { 83, 21 });
	Graphics::DrawTexts("BACK TO MENU", { 83, 21 }, unselectedColor);

	vector<Button>buttons = {b_replay, b_menu };
	bool game_over_running = 1;

	int cY = 20, command = 0;
	int pY = cY, pC = command, cX = 56;


	do
	{
		int n = buttons.size();
		//reset color of previous command
		Console::gotoxy(cX, pY);
		buttons[pC].Draw(unselectedColor);

		Console::gotoxy(cX, cY);
		buttons[command].Draw(selectedColor);

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
			if (command == 0)
			{
				ResetGame();
				menu.setMenuStatus(1, 0); 
			}
			else
			{
				menu.setMenuStatus(0, 1); 
			}
			game_over_running = false;
			break;
		}

	} while (game_over_running);
}

void Game::UpdatePlayer() {
	pl.Move();
	for (auto& i : car) {
		if (isCollide(pl.GetX(), pl.GetY(), pl.GetX() + 2, pl.GetY() + 2, i->GetX(), i->GetY(), i->GetBX(), i->GetBY())) {
			pl.SetState(0);
			goto ed;
		}
	}
	for (auto& i : tr) {
		if (isCollide(pl.GetX(), pl.GetY(), pl.GetX() + 2, pl.GetY() + 2, i->GetX(), i->GetY(), i->GetBX(), i->GetBY())) {
			pl.SetState(0);
			goto ed;
		}
	}
	for (auto& i : shark) {
		if (isCollide(pl.GetX(), pl.GetY(), pl.GetX() + 2, pl.GetY() + 2, i->GetX(), i->GetY(), i->GetBX(), i->GetBY())) {
			pl.SetState(0);
			goto ed;
		}
	}
	for (auto& i : bike) {
		if (isCollide(pl.GetX(), pl.GetY(), pl.GetX() + 2, pl.GetY() + 2, i->GetX(), i->GetY(), i->GetBX(), i->GetBY())) {
			pl.SetState(0);
			goto ed;
		}
	}
ed:
	if (pl.GetState() == 0) g_running = 0;
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