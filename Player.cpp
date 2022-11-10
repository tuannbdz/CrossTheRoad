#include "Player.h"
#include "GAME.h"
#include "common.h"

Player::Player(int _x, int _y) {
    x = _x;
    y = _y;
    state = 1;
    sprite.resize(3);
    sprite[0] = L" 0 ";
    sprite[1] = L"/|\\";
    sprite[2] = L"/ \\";
    color = Graphics::GetColor(Color::gray, Color::brightwhite);
}

Player::~Player() {

}
void Player::SetX(int v) {
    x = v;
}
void Player::SetY(int v) {
    y = v;
}

void Player::Draw() {
    Console::SetColor(color);
    Console::gotoxy(x, y);
    wcout << sprite[0];
    Console::gotoxy(x, y + 1);
    wcout << sprite[1];
    Console::gotoxy(x, y + 2);
    wcout << sprite[2];
}

void Player::Move() {
     Console::gotoxy(160, 33);
    if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W'))
    {
        Graphics::DrawGraphics(g_board, {x,y}, x - 10, y - 6, 3, 3, Graphics::GetColor(Color::gray, Color::white));
        y--;
    }
    if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S'))
    {
        Graphics::DrawGraphics(g_board, {x, y}, x - 10, y - 6, 3, 3, Graphics::GetColor(Color::gray, Color::white));
        ++y;
    }
    if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A'))
    {
        Graphics::DrawGraphics(g_board, {x, y}, x - 10, y - 6, 3, 3, Graphics::GetColor(Color::gray, Color::white));
        x -= 2;
    }
    if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D'))
    {
        Graphics::DrawGraphics(g_board, {x, y}, x - 10, y - 6, 3, 3, Graphics::GetColor(Color::gray, Color::white));
        x += 2;
    }

    Player::Draw();
    this_thread::sleep_for(milliseconds(61));
}

//void Player::isCollide(const OBSTACLE*& ob) {
//
//}