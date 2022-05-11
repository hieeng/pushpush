#include "model.h"
int model::getkey() {
	int ch = _getch();
	return (ch != 0xe0) ? ch : (0xe000 | _getch());
}
void model::xyputstr(int x, int y, const char* str) {
	gotoxy(x, y);
	cout << str;
}
void model::fillbox(int x1, int y1, int x2, int y2, int color){
	textbackground(color);
	for (int y = y1; y <= y2; ++y)
		for (int x = x1; x <= x2; ++x) {
			gotoxy(x, y);
			putchar(' ');
		}
}