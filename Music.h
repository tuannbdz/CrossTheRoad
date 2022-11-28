#pragma 
#include <iostream>
#include <thread>
#include <Windows.h>
#include "Console.h"
#include "Menu.h"
class Music
{
private:
	std::thread t_Sound;

	void music();
	void Initialize();

protected:
	bool bg_music, g_music, r_music, g_exit;
	int volume;

	Console* console;

public:
	Music(const short& width, const short& height, const std::wstring& title, const bool& cursor, const Color& color);
	Music();
	~Music();

	virtual void Run() = 0;
};

