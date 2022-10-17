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