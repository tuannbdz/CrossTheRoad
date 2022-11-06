#include "GAME.h"


GAME::GAME()
{
	
}

void GAME::DrawGame()
{
	Graphics::ClearScreen();
	Graphics::DrawGraphics({ 10, 2}, "graphics/Game/levels/level1_frame.txt", Graphics::GetColor(Color::lightblue, Color::brightwhite));
	Graphics::DrawGraphics({ 10, 6 }, "graphics/Game/maps/map_lvl3.txt", Graphics::GetColor(Color::gray, Color::white)); 
	Console::SetFont(L"Consolas Bold"); //but if Console::SetFont(L"Consolas"); is called, text is immediately changed to normal
	Graphics::DrawGraphics({ 138, 20 }, "graphics/Game/load_game_ingame.txt", Graphics::GetColor(Color::brightwhite, Color::blue));

	DrawControls(); 
	system("pause >nul"); //tempory line, delete this
}

void GAME::DrawControls()
{
	Graphics::DrawGraphics({ 138, 2 }, "graphics/Game/controls.txt", Graphics::GetColor(Color::brightwhite, Color::blue));

}

void GAME::ExitGame() {

}

void GAME::Run()
{
	Menu menu;
	menu.Run(); //will be in Game class
	if (menu.getGameStartedStatus() && !menu.getIsRunning())
	{
		DrawGame(); 
	}
}