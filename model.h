#pragma once
#include <iostream>
#include <conio.h>
#include "Consola.h"

using namespace std;

class model
{
public:
	int getkey();
	void xyputstr(int x, int y, const char* str);
	void fillbox(int x1, int y1, int x2, int y2, int color);
};

