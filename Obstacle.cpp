#include "Obstacle.h"
#include "console.h"
#include "Game.h"

int Obstacle::GetX() {
    return x;
}

int Obstacle::GetY() {
    return y;
}

int Obstacle::GetBX() {
    return x + sprite[0].size();
}

int Obstacle::GetBY() {
    return y + sprite.size();
}

void Obstacle::SetX(int _x) {
    x = _x;
}
void Obstacle::SetY(int _y) {
    x = _y;
}
void Obstacle::SetXY(int _x, int _y) {
    x = _x;
    y = _y;
}
void Obstacle::Draw() {
    Console::SetColor(color);
    for (int i = 0; i < sprite.size(); i++)
    {
        Console::gotoxy(x, y + i);
        for (auto j : sprite[i])
            wcout << (wchar_t)j;
    }
}

void Obstacle::Draw(int cx, int cy, int st, int ed) {
    Console::SetColor(color);
    for (int i = 0; i < sprite.size(); i++)
    {
        Console::gotoxy(cx, cy + i);
        for (int j = st; j <= ed; j++)
            wcout << (wchar_t)sprite[i][j];
    }
}
void Obstacle::Move() {
    if (dir == 0) {
        //in range
        if (x + sprite[0].size() >= boardX + g_board[0].size()) {
            int d = boardX + g_board[0].size() - x;
            Obstacle::Draw(x, y, 0, d - 1);
        }
        else
        if (x - boardX - speed >= 0) {
                Graphics::DrawGraphics(g_board, { SHORT(x + sprite[0].size()), y }, x - boardX + sprite[0].size(), y - boardY, speed + 1, sprite.size(), Graphics::GetColor(Color::gray, Color::brightwhite));
                Obstacle::Draw();
        }
        else{
                Graphics::DrawGraphics(g_board, { SHORT(x + sprite[0].size()), y }, x - boardX + sprite[0].size(), y - boardY, speed + 1, sprite.size(), Graphics::GetColor(Color::gray, Color::brightwhite));
                Obstacle::Draw(boardX + 1, y, boardX - x, sprite[0].size() - 1);
        }

        if (x + sprite[0].size() - 1 <= boardX) {
            Graphics::DrawGraphics(g_board, { SHORT(boardX), y }, 0, y - boardY, 2, sprite.size(), Graphics::GetColor(Color::gray, Color::brightwhite));
            x = 140;
        }
        x -= speed;
    }
    else
    {
        int ls = x, rs = x + sprite[0].size() - 1;
        int lb = boardX, rb = boardX + g_board[0].size() - 1;
        if (ls <= lb && lb < rs) {
            int d = rs - lb;
            Obstacle::Draw(lb + 1, y, sprite[0].size() - d, sprite[0].size() - 1);
        }
        else
            if (lb < ls && rs < rb) {
                Graphics::DrawGraphics(g_board, { SHORT(max(lb + 1, x - speed)), y }, max(lb + 1, x - speed - boardX), y - boardY, min(x - boardX, speed), sprite.size(), Graphics::GetColor(Color::gray, Color::brightwhite));
                Obstacle::Draw();
            }
            else
                if (ls < rb && rs >= rb) {
                    Graphics::DrawGraphics(g_board, { SHORT(max(lb + 1, x - speed)), y }, max(lb + 1, x - speed - boardX), y - boardY, min(x - boardX, speed), sprite.size(), Graphics::GetColor(Color::gray, Color::brightwhite));
                    Obstacle::Draw(x, y, 0, sprite[0].size() -  2 - (rs - rb));
                }
        if (ls >= rb)
        {
            x = 0;
        }
        else
        if (ls + speed >= rb) {
             Graphics::DrawGraphics(g_board, { x, y }, x - boardX, y - boardY, rb - ls, sprite.size(), Graphics::GetColor(Color::gray, Color::brightwhite));
             x = 0;
        }
        x += speed;
    }
    //this_thread::sleep_for(nanoseconds(1));
}