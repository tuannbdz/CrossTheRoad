#include "lib.h"
#include "classes.h"
#include "console.h"
#include "ui.h"

void PLAYER::SetX(int v) {
    x = v;
}
void PLAYER::SetY(int v) {
    y = v;
}

void PLAYER::DrawItself() {
    sprite[0] = " 0 ";
    sprite[1] = "/|\\";
    sprite[2] = "/ \\";
    Console::gotoxy(x, y);
    cout << sprite[0];
    Console::gotoxy(x, y + 1);
    cout << sprite[1];
    Console::gotoxy(x, y + 2);
    cout << sprite[2];
}

void PLAYER::Move(int dir) {
    UI ui;
    ui.Init();
    if (dir == 0)
    {
        //ui.DrawRect(ui.frame, PLAYER::GetX() + 2, PLAYER::GetY(), 1, 3);
        ui.DrawRect(ui.frame, PLAYER::GetX(), PLAYER::GetY(), 3, 3);
        PLAYER::SetX(max(0, x - 3));
    }
    else
    if (dir == 1)
    {
        //ui.DrawRect(ui.frame, PLAYER::GetX(), PLAYER::GetY(), 1, 3);
        ui.DrawRect(ui.frame, PLAYER::GetX(), PLAYER::GetY(), 3, 3);
        PLAYER::SetX(x + 3);
    }
    else
    if(dir == 2)
    {
        ui.DrawRect(ui.frame, PLAYER::GetX(), PLAYER::GetY() + 2, 3, 1);
        PLAYER::SetY(max(0, y - 1));
    }
    else
    if (dir == 3)
    {
        ui.DrawRect(ui.frame, PLAYER::GetX(), PLAYER::GetY(), 3, 1);
        PLAYER::SetY(y + 1);
    }
    PLAYER::DrawItself();
}

void PLAYER::isCollide(const OBSTACLE*& ob) {

}
void GAME::ExitGame() {
    UI ui;
    ui.DrawTitle(10, 0);
    ui.DrawMenu(10, 0);
    ui.ChooseCommand(85, 18);
}
void GAME::StartGame() {
    int cX = 0, cY = 0;
    //Draw frame
    UI ui;
    ui.Init();
    ui.DrawFrame(cX, cY);
    PLAYER pl;
    pl.SetY(20);
    pl.SetX(15);
    pl.DrawItself();
    char cmd = '.';
    while (cmd != KEY_ESC) {
        cmd = toupper(_getch());
        if (cmd == KEY_UP || cmd == 'W') {
            pl.Move(2);
        }
        else
        if (cmd == KEY_DOWN || cmd == 'S') {
            pl.Move(3);
        }
        else
            if (cmd == KEY_RIGHT || cmd == 'A') {
                pl.Move(1);
        }
            else if (cmd == KEY_LEFT || cmd == 'D') {
                pl.Move(0);
            }
    }
}