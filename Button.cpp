#include "Button.h"

void Button::Initialize()
{
	b_text = "\0";
	b_pos = { 0, 0 };
	b_color = Color::white;
}

Button::Button()
{
	Initialize();
}

Button::Button(const string& text)
{
	Initialize();
	b_text = text;
}

Button::Button(const string& text, const COORD& pos)
{
	Initialize();

	b_text = text;
	b_pos = pos;
}

Button::Button(const string& text, const COORD& pos, const Color& color)
{
	Initialize();

	b_text = text;
	b_pos = pos;
	b_color = color;
}

Button::Button(const string& text, const COORD& pos, const Color& color, const string& filename)
{
	Initialize();

	b_text = text;
	b_pos = pos;
	b_color = color;
	this->filename = filename; 
}

COORD Button::GetPos() {
	return b_pos;
}

string Button::GetText() {
	return b_text;
}

void Button::Draw()
{
	Graphics::DrawTexts(b_text, b_pos, b_color);
}

void Button::Draw(const Color& color)
{
	Graphics::DrawTexts(b_text, b_pos, color);
}

void Button::DrawGraphics()
{
	Graphics::DrawGraphics(b_pos, filename, b_color); 
}

void Button::DrawGraphics(const Color& color)
{
	Graphics::DrawGraphics(b_pos, filename, color);
}

void Button::DrawEffect(const Color& color)
{
	for (int i = 0; i < 4; ++i)
	{
		DrawGraphics();
		Sleep(140);
		DrawGraphics(color);
		Sleep(100);
	}
	//Draw(color);
}

void Button::SetText(const string& text)
{
	b_text = text;
}
void Button::SetFilename(const string& fn)
{
	filename = fn; 
}

void Button::SetColor(const Color& color)
{
	b_color = color;
}