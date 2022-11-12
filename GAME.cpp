#include "Game.h"

void Game::Init() {
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

	pl.SetXY(70, 33);

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

}

void Game::ResetGame() {
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
	Graphics::DrawGraphics({ 10, 2}, "graphics/Game/levels/level1_frame.txt", Graphics::GetColor(Color::lightblue, Color::brightwhite));
	Graphics::DrawGraphics({ 10, 6 }, "graphics/Game/maps/map_lvl3.txt", Graphics::GetColor(Color::gray, Color::white)); 
	Console::SetFont(L"Consolas Bold"); //but if Console::SetFont(L"Consolas"); is called, text is immediately changed to normal
	Graphics::DrawGraphics({ 138, 20 }, "graphics/Game/load_game_ingame.txt", Graphics::GetColor(Color::brightwhite, Color::blue));
	Graphics::DrawGraphics({ 138, 2 }, "graphics/Game/controls.txt", Graphics::GetColor(Color::brightwhite, Color::blue));
}


void Game::ExitGame(thread& t) {
	t_running = 0;
	t.join();
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
	}
	else {
		t_running = 1;
		t = thread(func);
	}
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