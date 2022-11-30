#include "Music.h"

void Music::music()
{
	bool isOpen = false, isStop = false;
	console->OpenMusic(L"music/Menu.mp3");

	while (r_music == true)
	{
		if (!bg_music && !isStop)
		{
			console->StopMusic();
			isStop = true;
			isOpen = false;
		}
		else if (bg_music && !isOpen)
		{
			console->PlayMusic(volume);
			isStop = false;
			isOpen = true;
		}
	}

	console->CloseMusic();
}

void Music::Initialize()
{
	console = nullptr;
	r_music = true;
	bg_music = true;
	g_music = true;
	g_exit = false;
	volume = 400;
	t_Sound = std::thread(&Music::music, this);
}

Music::Music(const short& width, const short& height, const std::wstring& title, const bool& cursor, const Color& color)
{
	Initialize();
	console = new Console(width, height, title, cursor, color);
}

Music::Music()
{
	Initialize();
	console = new Console();
}

Music::~Music()
{
	g_exit = true;

	bg_music = false;
	g_music = false;
	r_music = false;

	Sleep(40);

	delete console;
	console = nullptr;

	t_Sound.join();
}

