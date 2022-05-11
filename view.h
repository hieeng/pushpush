#pragma once
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include "Consola.h"
#include "keycode.h"
#include "myData.h"
#include "model.h"

using namespace std;

class view
{
	int lv = 0;
	model _model;
public:
	myData _data;
	void drawCell(int col, int row);
	void drawCharacter(int mx, int my);
	void drawMap();
	void scolor(unsigned short text = 15, unsigned short back = 16);
	int mainChoose(int x, int y);
	int showStartScreen();
	void showGameScreen();
	void mapReset();
	boolean check();
};

