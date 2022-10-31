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

void UI::DrawGameScreen(int pX, int pY) {
	Console::gotoxy(5, 5);
	cout << "Game Screen\n";
	Console::gotoxy(pX, pY);
}

void UI::DrawRect(vector<string>& obj, int x, int y, int w, int h) {
	FOR(i, y, y + h - 1)
		FOR(j, x, x + w - 1) {
		Console::gotoxy(j, i);
		//cout << i << " " << j << '\n';
		cout << obj[i][j];
	}
}