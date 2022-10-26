#include "lib.h"
#include "classes.h"
#include "ui.h"

void HUMAN::Move(int dir) {

}

void HUMAN::isCollide(const OBSTACLE*& ob) {

}
void GAME::ExitGame() {
    UI::DrawTitle(10, 0);
    UI::DrawMenu(10, 0);
    UI::ChooseCommand(85, 18);
}
void GAME::StartGame() {
    cout << "Hello";
    int n;
    cin >> n;
}