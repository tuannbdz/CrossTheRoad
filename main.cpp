#include "Game.h"
#include "common.h"
#include <fcntl.h>
#include <io.h>
#include <stdio.h>
vector<wstring>g_board;
bool t_running;
thread t_game;
Game *g = new Game();

void ProcessGame() {
    this_thread::sleep_for(milliseconds(10));
    while (g->isRunning() && t_running) {
        g->UpdatePlayer();
        g->UpdateCar();
        g->UpdateTruck();
        g->UpdateBike();
        g->UpdateShark();
    }
}

void StartGame() {
    t_game = thread(ProcessGame);
    while (g->isRunning()) {
        int Inst_command = tolower(_getch());
        switch (Inst_command) {
            case VK_ESCAPE: {
                if (t_running) g->ExitGame(t_game);
                break;
            }
            case 'r': {
                g->PauseGame(t_game, &ProcessGame);
                break;
            }
        }
    }
    if (t_running) g->ExitGame(t_game);
}

void RunGame() {
    Menu menu;
    BLOCK1:
    menu.Run();
    if (menu.getGameStartedStatus() && !menu.getIsRunning()) {
        g->DrawGame();
        StartGame();
    }
    g->ResetGame();
    menu= Menu();
    goto BLOCK1;
}

int main() {
    _setmode(_fileno(stdout), _O_U16TEXT);
    srand(time(NULL));
    Console* console = new Console(1312, 700, L"Cross The Road", false, Graphics::GetColor(Color::brightwhite, Color::black)); 
    RunGame();
    delete console; 
    delete g;
    system("pause >nul"); 
    return 0;
}
