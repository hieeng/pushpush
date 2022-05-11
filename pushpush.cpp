// day1113.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>
#include "consola.h"
#include "keycode.h"

using namespace std;

int getkey()
{
	int ch = _getch();
	return (ch != 0xe0) ? ch : (0xe000 | _getch());
}

void xyputstr(int x, int y, const char* str)
{
	gotoxy(x, y);
	cout << str;
}

void fillbox(int x1, int y1, int x2, int y2, int color)
{
	textbackground(color);
	for (int y = y1; y <= y2; ++y)
		for (int x = x1; x <= x2; ++x) {
			gotoxy(x, y);
			putchar(' ');
		}
}
///////////////////////////////////////////////////////////////
#define MAP_HEIGHT 10
#define MAP_WIDTH 10
#define MAP_X1  4
#define MAP_Y1  4

int mapData[MAP_HEIGHT][MAP_WIDTH] = {
   { 1, 1, 1, 1, 1, 1,1,1,1,1 },
   { 1, 1, 4, 1, 1, 0,0,0,0,1 },
   { 1, 0, 0, 0, 1, 0,0,0,0,1 },
   { 1, 0, 2, 0, 0, 0,0,0,0,1 },
   { 1, 0, 0, 0, 0, 0,0,0,0,1 },
   { 1, 1, 1, 1, 0, 0,0,0,0,1 },
   { 1, 0, 0, 0, 0, 0,0,0,0,1 },
   { 1, 0, 0, 0, 0, 0,0,0,0,1 },
   { 1, 0, 0, 0, 0, 0,0,0,0,1 },
   { 1, 1, 1, 1, 1, 1,1,1,1,1 }
};
const char* cellSymbol[] = { "  ", "▒", "●", NULL, "※", NULL };

void drawCell(int col, int row) {
	int cell = mapData[row][col];
	textbackground((cell == 1) ? DARKGRAY : YELLOW);
	gotoxy((MAP_X1 + col + 1) * 2, MAP_Y1 + row + 1);
	puts(cellSymbol[cell]);
}

void drawCharacter(int mx, int my)
{
	textbackground(YELLOW);
	gotoxy((MAP_X1 + mx + 1) * 2, MAP_Y1 + my + 1);
	puts("♀");
}

void drawMap() {
	for (int row = 0; row < MAP_HEIGHT; ++row)
		for (int col = 0; col < MAP_WIDTH; ++col)
			drawCell(col, row);
}
////////////////////////////////////////////////////////////////////

int main() {
	int x = 6, y = 6;
	int key, oldx, oldy;
	_setcursortype(_NOCURSOR);
	drawMap();
	do {
		drawCharacter(x, y);
		key = getkey();
		oldx = x;
		oldy = y;
		switch (key)
		{
		case M_UPKEY: if (y > 0) y--; break;
		case M_DOWNKEY: if (y < MAP_HEIGHT - 1) y++; break;
		case M_LEFTKEY: if (x > 0) x--; break;
		case M_RIGHTKEY: if (x < MAP_WIDTH - 1) x++; break;
		}
		if (mapData[y][x] != 0) {
			x = oldx;
			y = oldy;
		}
		// erase old charactor
		if (oldx != x || oldy != y)
			drawMap();
	} while (key != M_ESCKEY);

}
