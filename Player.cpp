#include "Player.h"
#include "GAME.h"
#include "common.h"

Player::Player() {
    x = 0;
    y = 0;
    state = 1;
    sprite.resize(3);
    sprite[0] = L" 0 ";
    sprite[1] = L"/|\\";
    sprite[2] = L"/ \\";
    color = Graphics::GetColor(Color::gray, Color::brightwhite);
}

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

void Player::SetSprite(vector<wstring>s)
{
    sprite.clear(); 
    for (wstring line : s)
        sprite.push_back(line); 
}

void Player::SetX(int a) {
    x = a;
}
void Player::SetY(int b) {
    y = b;
}
void Player::SetXY(int a, int b) {
    x = a, y = b;
}
void Player::SetState(short _s) {
    state = _s;
}
void Player::SetData(int _x, int _y, int _state) {
    x = _x;
    y = _y;
    state = _state;
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
    //Console::gotoxy(160, 33);
    //wcout << x << " " << y << '\n';
    if (y-boardY-1 > 0 && (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W'))) {
        Graphics::DrawGraphics(g_board, {x,y}, x - boardX, y - boardY, 3, 3, Graphics::GetColor(Color::gray, Color::brightwhite));
        y--;
    }
    if (y-boardY+4 < g_board.size() && (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S'))) {
        Graphics::DrawGraphics(g_board, {x, y}, x - boardX, y - boardY, 3, 3, Graphics::GetColor(Color::gray, Color::brightwhite));
        ++y;
    }
    if (x-boardX-2 >= 0  && (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A'))) {
        Graphics::DrawGraphics(g_board, {x, y}, x - boardX, y - boardY, 3, 3, Graphics::GetColor(Color::gray, Color::brightwhite));
        x -= 2;
    }
    if (x-boardX+4 < g_board[0].size() && (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D'))) {
        Graphics::DrawGraphics(g_board, {x, y}, x - boardX, y - boardY, 3, 3, Graphics::GetColor(Color::gray, Color::brightwhite));
        x += 2;
    }

    Player::Draw();
    this_thread::sleep_for(milliseconds(10));
}

//void Player::isCollide(const OBSTACLE*& ob) {
//
//}