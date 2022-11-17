#include "Game.h"

void Game::Init() {
	t_running = 1;
	g_running = 1;
	score = 0, level = 3;
	InitLevel(level);
	setMap(); 
}

void Game::InitLevel(int _l) {
	t_running = 1;
	g_running = 1;
	score = 0;
	level = _l;
	setMap();
	if (level == 1) {

	}
	if (level == 2) {

	}
	else
	{
		pl.SetXY(78, 33);

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

		tl.resize(4);
		tl[0].SetXY(0, 28);
		tl[1].SetXY(0, 23);
		tl[2].SetXY(0, 17);
		tl[3].SetXY(0, 12);
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

vector<TLight>& Game::GetTLight() {
	return tl;
}

void Game::DrawGame() {
	Graphics::ClearScreen();

	Graphics::DrawGraphics({ 10, 2 }, "graphics/Game/levels/level1/level1_frame_start.txt", Graphics::GetColor(Color::lightblue, Color::brightwhite));
	Graphics::DrawGraphics(g_board, { 10, 6 }, 0, 0, g_board[0].size(), g_board.size(), Graphics::GetColor(Color::gray, Color::brightwhite));

	Console::SetFont(L"Consolas Bold");
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

void writeBin(ostream& out, int& data) {
	out.write(reinterpret_cast<char*>(&data), sizeof(data));
}

void readBin(istream& in, int& data) {
	in.read(reinterpret_cast<char*>(&data), sizeof(data));
}

template <class T> void writeVector(vector<T*>& obj, ostream& out) {
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

template <class T> void readVector(vector<T*>& obj, istream& in) {
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
void Game::writeFile() {
	ofstream out("saveGame.txt", ios::binary);
	// write player
	int pX = pl.GetX(), pY = pl.GetY(), state = pl.GetState();
	writeBin(out, pX);
	writeBin(out, pY);
	writeBin(out, state);
	// write obstacles
	writeVector<Truck>(tr, out);
	writeVector<Car>(car, out);
	writeVector<Bike>(bike, out);
	writeVector<Shark>(shark, out);
	out.close();
}
void Game::readFile(Game*& g) {
	ifstream in("saveGame.txt", ios::binary);
	int x, y, state;
	readBin(in, x);
	readBin(in, y);
	readBin(in, state);
	g->pl.SetData(x, y, state);
	readVector<Truck>(tr, in);
	readVector<Car>(car, in);
	readVector<Bike>(bike, in);
	readVector<Shark>(shark, in);
	in.close();
}

void Game::SaveGame(thread& t, void (*func)()) {
	if (t_running) {
		t_running = 0;
		t.join();
		writeFile();
	}
	else {
		DrawGame();
		t_running = 1;
		t = thread(func);
	}
}

void Game::LoadGame(thread& t, void (*func)(), Game*& loadGame) {
	if (t_running) {
		t_running = 0;
		t.join();
	}
	else {
		readFile(loadGame);
		t_running = 1;
		DrawGame();
		t = thread(func);

	}
}

void Game::PauseGame(thread& t, void (*func)()) {
	if (t_running) {
		t_running = 0;
		t.join();
		Graphics::DrawGraphics({ 48, 16 }, "graphics/Game/pause_frame.txt", Graphics::GetColor(Color::brightwhite, Color::blue));
		Graphics::DrawGraphics({ 55, 15 }, "graphics/Game/pause_text.txt", Graphics::GetColor(Color::brightwhite, Color::blue));
		
		Graphics::DrawTexts("GAME IS PAUSED.", { 60, 19 }, Graphics::GetColor(Color::brightwhite, Color::yellow));
		Graphics::DrawTexts("PRESS R TO RESUME.", { 60, 20 }, Graphics::GetColor(Color::brightwhite, Color::yellow));
	}
	else {
		Graphics::DrawGraphics(g_board, { 48, 15 }, 39, 9, 42, 11, Graphics::GetColor(Color::gray, Color::brightwhite));
		t_running = 1;
		t = thread(func);
	}
}

void Game::GameOver(void (*func)(), Menu& menu)
{
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
	vector<string> firework = Graphics::GetGraphics("graphics/Game/game_over/firework_flying.txt");
	vector<string>effect1 = Graphics::GetGraphics("graphics/Game/game_over/firework_effect.txt"); 
	vector<string>effect2 = Graphics::GetGraphics("graphics/Game/game_over/firework_effect2.txt");

	short x_pos = 28, y_pos = 26;
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
		Graphics::DrawGraphics(g_board, { x_pos, y_pos }, curCol, row - fw_row - 1, fw_col + 3, fw_row, Graphics::GetColor(Color::gray, Color::brightwhite));
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
				ResetGame();
				menu.setMenuStatus(1, 0);
			}
			else
			{
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

void Game::UpdatePlayer() {
	pl.Move();
	this_thread::sleep_for(milliseconds(speed));
	for (auto& i : car) {
		if (isCollide(pl.GetX(), pl.GetY(), pl.GetX() + 2, pl.GetY() + 3, i->GetX(), i->GetY(), i->GetBX(), i->GetBY())) {
			pl.SetState(0);
			goto ed;
		}
	}
	for (auto& i : tr) {
		if (isCollide(pl.GetX(), pl.GetY(), pl.GetX() + 2, pl.GetY() + 3, i->GetX(), i->GetY(), i->GetBX(), i->GetBY())) {
			pl.SetState(0);
			goto ed;
		}
	}
	for (auto& i : shark) {
		if (isCollide(pl.GetX(), pl.GetY(), pl.GetX() + 2, pl.GetY() + 3, i->GetX(), i->GetY(), i->GetBX(), i->GetBY())) {
			pl.SetState(0);
			goto ed;
		}
	}
	for (auto& i : bike) {
		if (isCollide(pl.GetX(), pl.GetY(), pl.GetX() + 2, pl.GetY() + 3, i->GetX(), i->GetY(), i->GetBX(), i->GetBY())) {
			pl.SetState(0);
			goto ed;
		}
	}
ed:
	if (pl.GetState() == 0)
	{
		g_running = 0;
		this_thread::sleep_for(milliseconds(10));
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