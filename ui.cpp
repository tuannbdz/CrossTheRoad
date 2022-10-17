#include "lib.h"
#include "ui.h"
#include "console.h"
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
void UI::DrawMenu(int pX, int pY) {
	int cX = 85, cY = 18;
	UI* ui = new UI;
	vector<string> s = ui->listCommands;
	for (int i = 0; i < s.size(); i++) {
		Console::gotoxy(cX, cY + i);
		cout << s[i];
	}
	delete ui;
	Console::gotoxy(pX, pY);
}

void UI::ChooseCommand(int cX, int cY) {
	UI* ui = new UI;
	int n = ui->listCommands.size();
	int pY = cY;
	int pC = ui->command;
	Console::setCursor(0);
	do
	{
		//reset color of previous command
		Console::gotoxy(cX, pY);
		Console::fixFontColor(7);
		cout << ui->listCommands[pC];
		
		Console::gotoxy(cX, cY);
		Console::fixFontColor(6);
		cout << ui->listCommands[ui->command];

		int c = toupper(_getch());
		switch (c)
		{
			case 'W':case KEY_UP:
			{
				pY = cY;
				pC = ui->command;
				ui->command = (ui->command - 1 + n) % n;
				cY = ui->command + 18;
				Console::gotoxy(cX, cY);
				break;
			}
			case 'S':case KEY_DOWN:
			{
				pY = cY;
				pC = ui->command;
				ui->command = (ui->command + 1) % n;
				cY = ui->command + 18;
				Console::gotoxy(cX, cY);
				break;
			}
			case KEY_ENTER: case KEY_SPACE:
			{
				if (ui->command == n - 1) exit(0);
				break;
			}
		}

	} while (1);
	delete ui;
}
