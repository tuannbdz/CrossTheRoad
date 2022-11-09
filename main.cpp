#include "GAME.h"
#include "common.h"
string g_board_dir = "graphics/Game/maps/map_lvl3.txt";
GAME *g = new GAME;
vector<string>g_board;
bool t_running = 1;

void InitGraphics() {
    g_board = Graphics::GetGraphics(g_board_dir);
    //g_board.push_back("abc");
}

void UpdatePlayer() {
    g->pl->Move();
}

void ProcessGame() {
    this_thread::sleep_for(milliseconds(20));
    while (t_running) {
        UpdatePlayer();
    }
}

void DrawGame() {
    Graphics::ClearScreen();
    Graphics::DrawGraphics({ 10, 2 }, "graphics/Game/levels/level1_frame.txt", Graphics::GetColor(Color::lightblue, Color::brightwhite));
    Graphics::DrawGraphics({ 10, 6 }, "graphics/Game/maps/map_lvl3.txt", Graphics::GetColor(Color::gray, Color::white));
    Console::SetFont(L"Consolas Bold"); //but if Console::SetFont(L"Consolas"); is called, text is immediately changed to normal
    Graphics::DrawGraphics({ 138, 20 }, "graphics/Game/load_game_ingame.txt", Graphics::GetColor(Color::brightwhite, Color::blue));

    Graphics::DrawGraphics({ 138, 2 }, "graphics/Game/controls.txt", Graphics::GetColor(Color::brightwhite, Color::blue));
    //DrawControls();
}

void ExitGame(thread& t) {
    t_running = 0;
    t.join();
}

void PauseGame(thread& t) {
    if (t_running) {
        t_running = 0;
        t.join();
    }
    else {
        t_running = 1;
        t = thread(ProcessGame);
    }
}

void StartGame() {
    thread t_game(ProcessGame);
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

void RunGame() {
    InitGraphics();
    Menu menu;
    menu.Run();
    //BLOCK1:
    if (menu.getGameStartedStatus() && !menu.getIsRunning())
    {
        DrawGame();
        StartGame();
    }
}

int main() {
    srand(time(NULL));
    Console* console = new Console(1312, 700, L"Cross The Road", false, Graphics::GetColor(Color::brightwhite, Color::black)); 
    RunGame();
    delete console; 
    system("pause >nul"); 
    return 0;
}
