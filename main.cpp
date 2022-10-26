#include "lib.h"
#include "console.h"
#include "ui.h"

int main() {
    srand(time(NULL));

    Console::fixFontColor(240);
    system("cls");
    Console::fixFontSize(16);
    Console::SetScreenBufferSize(180, 44);
    Console::SetWindowSize(180, 44);
    Console::DisableResizeWindow();

    UI ui;
    ui.DrawTitle(10, 0);
    ui.DrawMenu(10, 0);
    ui.ChooseCommand(85, 18);
    _getch();
    return 0;
}