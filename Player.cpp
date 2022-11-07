#include "Player.h"
#include "GAME.h"

Player::Player(int _x, int _y) {
    x = _x;
    y = _y;
    state = 1;
    sprite.resize(3);
    sprite[0] = " 0 ";
    sprite[1] = "/|\\";
    sprite[2] = "/ \\";
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
    cout << sprite[0];
    Console::gotoxy(x, y + 1);
    cout << sprite[1];
    Console::gotoxy(x, y + 2);
    cout << sprite[2];
}

void Player::Move() {
    vector<string> s = getSprite();

    if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W'))
    {
        GAME::DrawGame();
        //Graphics::DrawGraphic({ x, y }, { x, y }, Graphics::GetGraphics("graphics/Map/frame.txt"), 3, 3, UNSELECTED_COLOR);
        y--;
    }
    if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S'))
    {
        GAME::DrawGame();
        //Graphics::DrawGraphic({ x, y }, { x, y }, Graphics::GetGraphics("graphics/Map/frame.txt"), 3, 3, UNSELECTED_COLOR);
        ++y;
    }
    if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A'))
    {
        GAME::DrawGame();
        //Graphics::DrawGraphic({ x, y }, { x, y }, Graphics::GetGraphics("graphics/Map/frame.txt"), 3, 3, UNSELECTED_COLOR);
        x -= 2;
    }
    if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D'))
    {
        GAME::DrawGame();
        //Graphics::DrawGraphic({ x, y }, { x, y }, Graphics::GetGraphics("graphics/Map/frame.txt"), 3, 3, UNSELECTED_COLOR);
        x += 2;
    }

    Player::Draw();
    this_thread::sleep_for(milliseconds(61));
}

//void Player::isCollide(const OBSTACLE*& ob) {
//
//}