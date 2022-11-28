#include "Game.h"
#include "common.h"
#include <fcntl.h>
#include <io.h>
#include <stdio.h>

vector<wstring>g_board;
bool t_running;
thread t_game;
thread t_tlight;
Game *g = new Game();

void ProcessTLight() {
    int i = 0;
    while (t_running) {
        this_thread::sleep_for(milliseconds(500));
        i = (i + 1) % 50;
        for (auto& x : g->GetTLight()) {
            if (i % x.GetTimeOut() == 0) {
                x.SetState(x.IsGreen() ^ 1);
            }
        }
    }
}

void ProcessGame() {
    this_thread::sleep_for(milliseconds(10));
    while (g->isRunning() && t_running) {
        g->UpdatePlayer(); //update player's status
        g->UpdateGameStatus();
        g->UpdateTLight();
        if (g->GetLevel() == 1)
        {
            if (g->GetTLight()[0].IsGreen())
                g->UpdateBike();
            else g->DrawBike();

            if (g->GetTLight()[1].IsGreen())
                g->UpdateCar();
            else g->DrawCar();
        }
        else
        if (g->GetLevel() == 2) {
            if (g->GetTLight()[0].IsGreen())
                g->UpdateCar();
            else g->DrawCar();

            if (g->GetTLight()[1].IsGreen())
                g->UpdateTruck();
            else g->DrawTruck();

            if (g->GetTLight()[2].IsGreen())
                g->UpdateBike();
            else g->DrawBike();
        }
        else
        if (g->GetLevel() == 3)
        {
            if (g->GetTLight()[3].IsGreen())
                g->UpdateBike();
            else g->DrawBike();

            if (g->GetTLight()[2].IsGreen())
                g->UpdateCar();
            else g->DrawCar();

            if (g->GetTLight()[1].IsGreen())
                g->UpdateShark();
            else g->DrawShark();

            if (g->GetTLight()[0].IsGreen())
                g->UpdateTruck();
            else g->DrawTruck();
        }
    }
}

void StartGame(Menu& menu) {
    g->setg_music(menu);
    g->DrawGame(); 
    //checks before assigning thread or else abort() will be called
    if (t_game.joinable())
        t_game.join(); 
    t_game = thread(ProcessGame);
    t_tlight = thread(ProcessTLight);

    while (g != NULL && g->isRunning()) {
        if(Console::KeyPress(KeyCode::ESC)){
            if (t_running) {
                g->ExitGame(t_game, t_tlight, g, menu, &ProcessGame, &ProcessTLight);
            }
        }
        else
        if (Console::KeyPress(KeyCode::R)){
            g->PauseGame(t_game, t_tlight, &ProcessGame, &ProcessTLight);
        }
       else
        if (Console::KeyPress(KeyCode::L)) {
            g->SaveGame(t_game, t_tlight, &ProcessGame, &ProcessTLight);
        }
        else
        if (Console::KeyPress(KeyCode::T)) {
            g->LoadGame(t_game, t_tlight, &ProcessGame, &ProcessTLight);
        }
    }
    if (g != NULL && t_running)
    {
        t_running = 0;
        t_game.join();
        if(t_tlight.joinable()) t_tlight.join();
        g->GameOver(&ProcessGame, menu);
    }
}

void RunGame() {
    Menu menu;
    
BLOCK1:
    g = new Game(); 
    
    if (menu.getIsRunning() && !menu.getGameStartedStatus()) {
        menu.Run();
    }
    
    if (menu.getGameStartedStatus() && !menu.getIsRunning()) {
        g->setbg_music(menu);
        if (g->Getbg_mucsic())
            g->Sound();
        StartGame(menu);
    }
    
    goto BLOCK1;
}
void runLobby(){
    Graphics::ClearScreen();
    Graphics::drawBlueGradientGraphics({ 10, 0 }, "graphics/Menu/title.txt");
    Menu menu;
    menu.DrawMainMenu();
    menu.ChooseCommand(75, 14, Mode::mainMenu);
}
void runGame(){}

void run() {
START:
    g = new Game();
    runLobby();
    runGame();
    goto START;
}

int main() {
    _setmode(_fileno(stdout), _O_U16TEXT);
    srand(time(NULL));
    Console* console = new Console(1312, 700, L"Cross The Road", false, Graphics::GetColor(Color::brightwhite, Color::black)); 
    RunGame();
    delete console; 
    delete g;
    //system("pause >nul"); 
    return 0;
}
