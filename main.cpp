#include "Game.h"
#include "common.h"
#include <fcntl.h>
#include <io.h>
#include <stdio.h>

vector<wstring>g_board;
Game* Game::instance = nullptr;
int main() {
    _setmode(_fileno(stdout), _O_U16TEXT);
    srand(time(NULL));
    Console* console = new Console(1312, 700, L"Cross The Road", false, Graphics::GetColor(Color::brightwhite, Color::black)); 

    Game* g = Game::GetInstance();
    g->Run();

    //system("pause >nul"); 
    delete console; 
    Game::DeleteInstance();
    return 0;
}
