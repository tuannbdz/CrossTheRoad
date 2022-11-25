#include "Game.h"

void Game::Init() {
	t_running = 1;
	g_running = 1;
	score = 0, level = 1;

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

void Game::DrawGame() {
	Graphics::ClearScreen();

	Graphics::DrawGraphics({ 10, 2 }, "graphics/Game/levels/level1/level1_frame_start.txt", Graphics::GetColor(Color::lightblue, Color::brightwhite));
	Graphics::DrawGraphics(g_board, { 10, 6 }, 0, 0, g_board[0].size(), g_board.size(), Graphics::GetColor(Color::gray, Color::brightwhite));

	Console::SetFont(L"Consolas Bold");
	Graphics::DrawGraphics({ 138, 20 }, "graphics/Game/load_game_ingame.txt", Graphics::GetColor(Color::brightwhite, Color::blue));
	Graphics::DrawGraphics({ 138, 2 }, "graphics/Game/controls.txt", Graphics::GetColor(Color::brightwhite, Color::blue));

	DrawIdlePl();
}

template <class T> void drawVector(vector<T*>& obj) {
	for (auto& o : obj)
		o->UpdateSprite();
}

void Game::ExitGame(thread& t, thread& tl, Game*& g, Menu& menu, void (*func)(), void (*func2)()) {
	//pause game for pop up
	if (t_running) {
		t_running = 0;
		if (t.joinable()) t.join();
		if (tl.joinable()) tl.join();
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
				g->g_running = 0;
				menu.setMenuStatus(0, 1);
				delete g;
				g = NULL;
			}
			else
			{
				Graphics::DrawGraphics(g_board, { 48, 16 }, 39, 10, 44, 11, Graphics::GetColor(Color::gray, Color::brightwhite));
				t_running = 1;
				t = thread(func);
				tl = thread(func2);
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

void Game::SaveGame(thread& t, thread& tl, void (*func)(), void (*func2)()) {
	if (t_running == 0) return;
	t_running = 0;
	if(tl.joinable()) tl.join();
	if(t.joinable()) t.join();

	// save game
	// draw input board
	Graphics::DrawGraphics({ 50, 15 }, "graphics/game/save_game_input_board.txt", Graphics::GetColor(Color::brightwhite, Color::blue));
	Console::GotoXY({ 71, 18 });
	::FlushConsoleInputBuffer(Console::inputHandle());
	Console::setCursor(1);
	//while (fileName.size() > 18 || fileName.size() < 1)
	//	getline(cin, fileName);
	const int inputSize = 18;
	char buffer[inputSize+1];
	cin.getline(buffer, inputSize+1);
	string fileName(buffer);
	Console::setCursor(0);

	ofstream out("save_game_files/" + fileName + ".bin", ios::binary);
	// write player
	int pX = pl.GetX(), pY = pl.GetY(), state = pl.GetState();
	writeBin(out, pX);
	writeBin(out, pY);
	writeBin(out, state);
	// write obstacles
	writeVector<Truck>(out, tr);
	writeVector<Car>(out, car);
	writeVector<Bike>(out, bike);
	writeVector<Shark>(out, shark);
	// write traffic lights
	for (auto &l : tlight) {
		bool state = l.IsGreen();
		writeBin(out, state);
	}

	out.close();
	Graphics::DrawGraphics(g_board, { 50, 15 }, 50 - boardX, 15 - boardY, 44, 9, Graphics::GetColor(Color::gray, Color::brightwhite));
	t_running = 1;
	t = thread(func);
	tl = thread(func2);
}

string Game::HookLoadGame(short x, short y) {
	// Draw frame
	Graphics::DrawGraphics({ x, y }, "graphics/Menu/load_game_frame.txt", Graphics::GetColor(Color::lightblue, Color::lightyellow));
	Console::SetFont(L"Consolas Bold");
	Graphics::DrawTexts("NAME", { short(x + 6), short(y + 2) }, Graphics::GetColor(Color::lightblue, Color::brightwhite));
	Graphics::DrawTexts("LEVEl", { short(x + 38), short(y + 2) }, Graphics::GetColor(Color::lightblue, Color::brightwhite));
	Graphics::DrawTexts("SCORE", { short(x + 52), short(y + 2) }, Graphics::GetColor(Color::lightblue, Color::brightwhite));
	Graphics::DrawTexts("PREVIOUS PAGE [A]", { short(x + 5), short(y + 30 - 4) }, Graphics::GetColor(Color::lightblue, Color::brightwhite));
	Graphics::DrawTexts("RETURN [R]", { short(x + 27), short(y + 30 - 4) }, Graphics::GetColor(Color::lightblue, Color::brightwhite));
	Graphics::DrawTexts("NEXT PAGE [D]", { short(x + 45), short(y + 30 - 4) }, Graphics::GetColor(Color::lightblue, Color::brightwhite));

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
	short buttonPosY = y+5, buttonPosX = x+7;
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
			if (currPage < buttonsOfPage.size()-1)
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

void Game::LoadGame(thread& t, thread& tl, void (*func)(), void (*func2)(), Game*& loadGame) {
	if (t_running == 0) return;
	t_running = 0;
	if (tl.joinable()) tl.join();
	if (t.joinable()) t.join();
	string fileName = HookLoadGame(50, 6);
	if (fileName.size()) {
		ifstream in("save_game_files/" + fileName, ios::binary);
		// read player
		int x, y, state;
		readBin(in, x);
		readBin(in, y);
		readBin(in, state);
		loadGame->pl.SetData(x, y, state);
		// read obstacles
		readVector<Truck>(in, tr);
		readVector<Car>(in, car);
		readVector<Bike>(in, bike);
		readVector<Shark>(in, shark);
		// read traffic lights
		for (auto& l : tlight) {
			bool state = l.IsGreen();
			readBin(in, state);
			l.SetState(state);
		}
		in.close();
		DrawGame();
	} else
		Graphics::DrawGraphics(g_board, { 50, 6 }, 50 - boardX, 6 - boardY, 63, 30, Graphics::GetColor(Color::gray, Color::brightwhite));
	//Graphics::DrawGraphics({ 58, 6 }, "graphics/Menu/load_game_frame.txt", Graphics::GetColor(Color::lightblue, Color::lightyellow));
	t_running = 1;
	t = thread(func);
	tl = thread(func2);

}

void Game::PauseGame(thread& t, thread& tl, void (*func)(), void (*func2)()) {
	if (t_running) {
		t_running = 0;
		if(t.joinable()) t.join();
		if(tl.joinable()) tl.join();
		Graphics::DrawGraphics({ 48, 16 }, "graphics/Game/pause_frame.txt", Graphics::GetColor(Color::brightwhite, Color::blue));
		Graphics::DrawGraphics({ 55, 15 }, "graphics/Game/pause_text.txt", Graphics::GetColor(Color::brightwhite, Color::blue));
		
		Graphics::DrawTexts("GAME IS PAUSED.", { 60, 19 }, Graphics::GetColor(Color::brightwhite, Color::yellow));
		Graphics::DrawTexts("PRESS R TO RESUME.", { 60, 20 }, Graphics::GetColor(Color::brightwhite, Color::yellow));

	}
	else {
		Graphics::DrawGraphics(g_board, { 48, 15 }, 39, 9, 42, 11, Graphics::GetColor(Color::gray, Color::brightwhite));
		t_running = 1;
		t = thread(func);
		tl = thread(func2);
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
	DrawGame();
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

void Game::UpdateGameStatus() {
	if (pl.GetState() == 0) {
		g_running = 0;
	}
	else if (pl.GetState() == 2) {
		if (numIdlePl > 0)
		{
			idlePl.push_back(pl.GetX());
			pl = Player(78, (level == 3 ? 33 : level == 2 ? 30 : 28));
		}
		else
		{
			g_running = 0;
		}
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
			pl.SetState(0);
			return;
		}
	}
	for (auto& i : tr) {
		if (isCollide(pl.GetX(), pl.GetY(), pl.GetX() + 2, pl.GetY() + 3, i->GetX(), i->GetY(), i->GetBX(), i->GetBY())) {
			pl.SetState(0);
			return;
		}
	}
	for (auto& i : shark) {
		if (isCollide(pl.GetX(), pl.GetY(), pl.GetX() + 2, pl.GetY() + 3, i->GetX(), i->GetY(), i->GetBX(), i->GetBY())) {
			pl.SetState(0);
			return;
		}
	}
	for (auto& i : bike) {
		if (isCollide(pl.GetX(), pl.GetY(), pl.GetX() + 2, pl.GetY() + 3, i->GetX(), i->GetY(), i->GetBX(), i->GetBY())) {
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