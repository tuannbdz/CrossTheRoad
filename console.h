#pragma once
#include "lib.h"
#include <windows.h>

class Console {
public:
	static void DisableResizeWindow();
	static void SetWindowSize(SHORT width, SHORT height);
	static void SetScreenBufferSize(SHORT width, SHORT height);
	static void fixFontColor(int fontColor);
	static void fixFontSize(int fontSize);
	static void setCursor(bool visible);
	static void gotoxy(int pX, int pY);
};
