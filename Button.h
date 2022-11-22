#pragma once
#include "Graphics.h"
#include "Console.h"
#include "lib.h"

class Button
{
private:
	string b_text;
	COORD b_pos;
	Color b_color;
	string filename; 
	const HANDLE g_handle = GetStdHandle(STD_OUTPUT_HANDLE);

	void Initialize();
public:
	Button();
	Button(const string& text);
	Button(const string& text, const COORD& pos);
	Button(const string& text, const COORD& pos, const Color& color);
	Button(const string& text, const COORD& pos, const Color& color, const string& filename);

	COORD GetPos();
	string GetText();

	void Draw();
	void Draw(const Color& color);
	void DrawGraphics();
	void DrawGraphics(const Color& color);
	void DrawEffect(const Color& color);
	void SetText(const string& text);
	void SetColor(const Color& color);
};

