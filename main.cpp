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

void StartGame(Menu& menu) {
    g->DrawGame(); 

    //checks before assigning thread or else abort() will be called
    if (t_game.joinable())
        t_game.join(); 
    t_game = thread(ProcessGame);

    while (g != NULL && g->isRunning()) {
        int Inst_command = tolower(_getch());
        switch (Inst_command) {
            case VK_ESCAPE: {
                if (t_running) g->ExitGame(t_game, g, menu);
                break;
            }
            case 'r': {
                g->PauseGame(t_game, &ProcessGame);
                break;
            }
        }
    }
    if (g != NULL && t_running)
    {
        g->GameOver(&ProcessGame, menu);
        if (!menu.getGameStartedStatus())
            g->ExitGame(t_game, g, menu);
    }
}

void RunGame() {
    Menu menu;
    
BLOCK1:
    g = new Game(); 
    
    if (menu.getIsRunning() && !menu.getGameStartedStatus())
    {
        menu.Run();
    }
    
    if (menu.getGameStartedStatus() && !menu.getIsRunning())
    {
        StartGame(menu);
    }
    //t_game = thread(ProcessGame);
    //menu= Menu();

    
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
