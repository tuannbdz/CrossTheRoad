#pragma once
#include "lib.h"
#include "common.h"

const enum class Color
{
	black,
	blue,
	green,
	aqua,
	red,
	purple,
	yellow,
	white,
	gray,
	lightblue,
	lightgreen,
	lightaqua,
	lightred,
	lightpurple,
	lightyellow,
	brightwhite
};

class Graphics
{
public:
	static void DrawTexts(const wstring& text, const COORD& pos, const Color& color);
	static void DrawTexts(const wstring& text, const COORD& pos);
	static void DrawTexts(const wstring& text, const Color& color);
	static void DrawTexts(const wstring& text);

	static void DrawTexts(const string& text, const COORD& pos, const Color& color);
	static void DrawTexts(const string& text, const COORD& pos);
	static void DrawTexts(const string& text, const Color& color);
	static void DrawTexts(const string& text);

	static void RemoveArea(const COORD& s_pos, const COORD& e_pos);
	static void ClearScreen(); 
	static vector<string> GetGraphics(const string& filename);
	static vector<string> GetGraphicsR(const string& filename);
	static void DrawGraphics(COORD pos, const string& filename, const Color& color);
	static void DrawGraphicsR(COORD pos, const string& filename, const Color& color);
	static Color GetColor(const Color& background, const Color& text);
	static void drawBlueGradientGraphics(COORD pos, const string& filename);

	static void DrawGraphics(const vector<wstring>&, COORD, const Color&);
	static void DrawGraphics(const vector<string>&, COORD, const Color&);
	static void DrawGraphics(const vector<wstring>&, COORD, int, int, int, int, const Color&);
	static void DrawGraphics(const vector<string>&, COORD, int, int, int, int, const Color&);

	const vector<vector<wstring>>numberGraphics = {
		zero, one, two, three, four, five, six, seven, eight, nine
	};
	
	const vector<wstring> zero =
	{
		L"█▀█",
		L"█▄█"
	};

	const vector<wstring> one =
	{
		L"▄█",
		L" █"
	};

	const vector<wstring> two =
	{
		L"▀█",
		L"█▄"

	};

	const vector<wstring> three =
	{
		L"▀██",
		L"▄▄█"
	};
	const vector<wstring> four =
	{
		L"█ █",
		L"▀▀█"

	};
	const vector<wstring> five =
	{
		L"█▀",
		L"▄█"

	};
	const vector<wstring> six =
	{
		L"█▄▄",
		L"█▄█"

	};
	const vector<wstring> seven =
	{
		L"▀▀█",
		L"  █"

	};
	const vector<wstring> eight =
	{
		L"▄▀▀▄",
		L"▄▀▀▄"
		L"▀▄▄▀"
	};

	const vector<wstring> nine =
	{
		L"█▀█",
		L"▀▀█"
	};
};

const Color UNSELECTED_COLOR = Graphics::GetColor(Color::brightwhite, Color::blue);
const Color SELECTED_COLOR = Graphics::GetColor(Color::brightwhite, Color::yellow);
const Color DEFAULT_COLOR = Graphics::GetColor(Color::brightwhite, Color::black);