#include "GAME.h"

void GAME::Initialize() {
	t_running = 1;
	g_running = 1;
	//g_board = Graphics::GetGraphics("Map/frame.txt");
	pl = new Player(70, 33);
}

GAME::GAME()
{
	Initialize();
}

void GAME::DrawGame()
{
	Graphics::ClearScreen();
	Graphics::DrawGraphics({ 10, 2}, "graphics/Game/levels/level1_frame.txt", Graphics::GetColor(Color::lightblue, Color::brightwhite));
	Graphics::DrawGraphics({ 10, 6 }, "graphics/Game/maps/map_lvl3.txt", Graphics::GetColor(Color::gray, Color::white)); 
	Console::SetFont(L"Consolas Bold"); //but if Console::SetFont(L"Consolas"); is called, text is immediately changed to normal
	Graphics::DrawGraphics({ 138, 20 }, "graphics/Game/load_game_ingame.txt", Graphics::GetColor(Color::brightwhite, Color::blue));

	DrawControls(); 
	//system("pause >nul"); //tempory line, delete this
}

void GAME::DrawControls()
{
	Graphics::DrawGraphics({ 138, 2 }, "graphics/Game/controls.txt", Graphics::GetColor(Color::brightwhite, Color::blue));

}

void GAME::ExitGame(thread& t) {
	t_running = 0;
	t.join();
}

void GAME::PauseGame(thread& t) {
	if (t_running) {
		t_running = 0;
		t.join();
	}
	else {
		t_running = 1;
		t = thread(&GAME::ProcessGame, this);
	}
}

void GAME::UpdatePlayer() {
	pl->Move();
}

void GAME::ProcessGame() {
	this_thread::sleep_for(milliseconds(20));
	while (t_running) {
		UpdatePlayer();
	}
}

void GAME::Run()
{
	Menu menu;
	menu.Run(); //will be in Game class
	if (menu.getGameStartedStatus() && !menu.getIsRunning())
	{
		DrawGame(); 
		StartGame();
	}
}

void GAME::StartGame() {
	thread t_game(&GAME::ProcessGame, this);
	// a thread handles the in-game event
	//Graphics::DrawGraphics({ 0, 0 }, "graphics/Map/frame.txt", UNSELECTED_COLOR);
	while (1) {
		int Inst_command = tolower(_getch());
		switch (Inst_command)
		{
			case VK_ESCAPE:
			{
				if (t_running) ExitGame(t_game);
				break;
			}
			case 'r':
			{
				PauseGame(t_game);
				break;
			}
		}

	}
}