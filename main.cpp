#include "lib.h"
#include "console.h"
#include "ui.h"

int main() {
    srand(time(NULL));
    system("cls");
    Console::fixFontSize(16);
    Console::SetScreenBufferSize(180, 44);
    Console::SetWindowSize(180, 44);
    Console::DisableResizeWindow();
    UI::DrawTitle(10, 0);
    UI::DrawMenu(10, 0);
    UI::ChooseCommand(85, 18);
    _getch();
    //cout << "CMM";
    return 0;
}