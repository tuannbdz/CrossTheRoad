#include "GAME.h"

void GAME::Init() {
	t_running = 1;
	g_running = 1;
	//g_board = Graphics::GetGraphics("Map/frame.txt");
	//pl = new Player(70, 33);
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

GAME::GAME() {
	Init();
}

void GAME::DrawGame() {
	Graphics::ClearScreen();
	Graphics::DrawGraphics({ 10, 2}, "graphics/Game/levels/level1_frame.txt", Graphics::GetColor(Color::lightblue, Color::brightwhite));
	Graphics::DrawGraphics({ 10, 6 }, "graphics/Game/maps/map_lvl3.txt", Graphics::GetColor(Color::gray, Color::white)); 
	Console::SetFont(L"Consolas Bold"); //but if Console::SetFont(L"Consolas"); is called, text is immediately changed to normal
	Graphics::DrawGraphics({ 138, 20 }, "graphics/Game/load_game_ingame.txt", Graphics::GetColor(Color::brightwhite, Color::blue));
	Graphics::DrawGraphics({ 138, 2 }, "graphics/Game/controls.txt", Graphics::GetColor(Color::brightwhite, Color::blue));
}


void GAME::ExitGame(thread& t) {
	t_running = 0;
	t.join();
}

void GAME::PauseGame(thread& t, void (*func)()) {
	if (t_running) {
		t_running = 0;
		t.join();
	}
	else {
		t_running = 1;
		//t = thread(&GAME::ProcessGame, this);
		t = thread(func);
	}
	//t_running = !t_running;
}

void GAME::UpdatePlayer() {
	pl.Move();
}


void GAME::StartGame() {
	//thread t_game(&GAME::ProcessGame, this);
	//// a thread handles the in-game event
	////Graphics::DrawGraphics({ 0, 0 }, "graphics/Map/frame.txt", UNSELECTED_COLOR);
	//while (1) {
	//	int Inst_command = tolower(_getch());
	//	switch (Inst_command)
	//	{
	//		case VK_ESCAPE:
	//		{
	//			if (t_running) ExitGame(t_game);
	//			break;
	//		}
	//		case 'r':
	//		{
	//			PauseGame(t_game);
	//			break;
	//		}
	//	}

	//}
}