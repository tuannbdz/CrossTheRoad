#include "lib.h"
#include "ui.h"
#include "console.h"
#include "classes.h"

UI::UI() {
	ifstream fi("frame.txt");
	string s;
	int i = 0;
	while (getline(fi, s)) {
		frame.push_back(s);
		i++;
	}
	fi.close();
}
void UI::DrawTitle(int pX, int pY) {
	ifstream fi("title.txt");
	string t;
	vector<string> s;
	while (getline(fi, t)) {
		s.push_back(t);
	}
	fi.close();
	//corner top left position
	int cX = 3, cY = 0;
	for (int i = 0; i < s.size(); i++) {
		Console::gotoxy(cX, cY + i);
		cout << s[i];
	}
	Console::gotoxy(pX, pY);
}
void UI::DrawFrame(int pX, int pY) {
	for (int i = 0; i < this->frame.size(); i++) {
		Console::gotoxy(pX, pY + i);
		cout << this->frame[i];
	}
}
void UI::DrawMenu(int pX, int pY) {
	int cX = 85, cY = 18;
	vector<string> s = this->listCommands;
	for (int i = 0; i < s.size(); i++) {
		Console::gotoxy(cX, cY + i);
		cout << s[i];
	}
	Console::gotoxy(pX, pY);
}
void UI::DrawGameScreen(int pX, int pY) {
	Console::gotoxy(5, 5);
	cout << "Game Screen\n";
	Console::gotoxy(pX, pY);
}
void UI::ChooseCommand(int cX, int cY) {
	int n = this->listCommands.size();
	int pY = cY;
	int pC = this->command;
	Console::setCursor(0);
	do
	{
		//reset color of previous command
		Console::gotoxy(cX, pY);
		Console::fixFontColor(240);
		cout << this->listCommands[pC];
		
		Console::gotoxy(cX, cY);
		Console::fixFontColor(31);
		cout << this->listCommands[this->command];

		int c = toupper(_getch());
		switch (c)
		{
			case 'W':case KEY_UP:
			{
				pY = cY;
				pC = this->command;
				this->command = (this->command - 1 + n) % n;
				cY = this->command + 18;
				Console::gotoxy(cX, cY);
				break;
			}
			case 'S':case KEY_DOWN:
			{
				pY = cY;
				pC = this->command;
				this->command = (this->command + 1) % n;
				cY = this->command + 18;
				Console::gotoxy(cX, cY);
				break;
			}
			case KEY_ENTER: case KEY_SPACE:
			{
				if (this->command == n - 1) exit(0);
				if (this->command == 0) {
					Console::fixFontColor(241);
					system("cls");
					DrawGameScreen(0, 0);
					GAME::StartGame();
				}
				break;
			}
		}

	} while (1);
}
void UI::DrawRect(vector<string>& obj, int x, int y, int w, int h) {
	FOR(i, y, y + h - 1)
		FOR(j, x, x + w - 1) {
		Console::gotoxy(j, i);
		//cout << i << " " << j << '\n';
		cout << obj[i][j];
	}
}