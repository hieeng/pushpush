#pragma once
#include <iostream>


#define MAP_HEIGHT 20
#define MAP_WIDTH 20
#define MAP_LEVEL 10
#define MAP_X1  4
#define MAP_Y1  4

class myData
{
public:
	const char* cellSymbol[9] = { "  ", "��", "��", NULL, "��", NULL, NULL, NULL, "��" };

	int step = 0;

	int temp[MAP_LEVEL][MAP_HEIGHT][MAP_WIDTH];
	int mapData[MAP_LEVEL][MAP_HEIGHT][MAP_WIDTH] = {
		{//7,7 ĳ���� ����
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 1, 4, 1, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0 },
			{ 0, 0, 1, 1, 1, 2, 0, 2, 4, 1, 0 },
			{ 0, 0, 1, 4, 0, 2, 0, 1, 1, 1, 0 },
			{ 0, 0, 1, 1, 1, 1, 2, 1, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 4, 1, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 1, 1, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		},//1
		{
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1 },
			{ 0 ,0, 0, 0, 0, 1, 0, 2, 2, 1, 0, 1, 4, 1 },
			{ 0 ,0, 0, 0, 0, 1, 0, 2, 0, 1, 1, 1, 4, 1 },
			{ 0 ,0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 4, 1 },
			{ 0 ,0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1 },
			{ 0 ,0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1 },
			{ 0 ,0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0 },
		},//2
		{
			{ 0, 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0 ,0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0 ,0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0 },
			{ 0 ,0 ,0, 1, 0, 2, 0, 4, 4, 1, 0, 0, 0, 0, 0 },
			{ 0 ,0 ,0, 1, 0, 1, 0, 4, 4, 1, 0, 0, 0, 0, 0 },
			{ 0 ,0 ,0, 1, 0, 1, 2, 1, 1, 1, 0, 0, 0, 0, 0 },
			{ 0 ,0 ,0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
			{ 0 ,0 ,0, 1, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0 },
			{ 0 ,0 ,0, 1, 1, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0 },
			{ 0 ,0 ,0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0 },
			{ 0 ,0 ,0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
		},//3
		{
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
			{ 0 ,0, 0, 0, 1, 1, 0, 1, 1, 4, 4, 1, 0, 0 },
			{ 0 ,0, 0, 0, 1, 0, 2, 2, 0, 2, 4, 1, 0, 0 },
			{ 0 ,0, 0, 0, 1, 0, 0, 0, 2, 0, 8, 1, 0, 0 },
			{ 0 ,0, 0, 0, 1, 1, 1, 1, 0, 0, 4, 1, 0, 0 },
			{ 0 ,0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0 },
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
		},//4
		{
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 0, 2, 0, 0, 1, 0, 0, 0 },
			{ 0 ,0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0 },
			{ 0 ,0, 0, 0, 1, 4, 1, 0, 1, 0, 0, 1, 0, 0 },
			{ 0 ,0, 0, 0, 1, 4, 2, 0, 0, 1, 0, 1, 0, 0 },
			{ 0 ,0, 0, 0, 1, 4, 0, 0, 0, 2, 0, 1, 0, 0 },
			{ 0 ,0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
		},//5
		{
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 1, 1, 1, 0, 2, 1, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 1, 0, 2, 2, 4, 1, 1, 0, 0, 0, 0 },
			{ 0 ,0, 0, 1, 0, 2, 4, 4, 0, 1, 0, 0, 0, 0 },
			{ 0 ,0, 0, 1, 0, 2, 4, 4, 0, 1, 0, 0, 0, 0 },
			{ 0 ,0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0 },
			{ 0 ,0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
		},//6
		{
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0 },
			{ 0 ,0, 0, 0, 0, 1, 0, 1, 2, 0, 0, 4, 1, 0 },
			{ 0 ,0, 0, 0, 0, 1, 0, 2, 0, 2, 4, 4, 1, 0 },
			{ 0 ,0, 0, 0, 0, 1, 0, 2, 0, 4, 1, 1, 1, 0 },
			{ 0 ,0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		},//7
		{
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 0, 2, 0, 0, 1, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 0, 0, 2, 0, 1, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 0, 4, 1, 1, 1, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 1, 4, 1, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 0, 4, 1, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 0, 4, 1, 1, 1, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 0, 2, 0, 0, 1, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 0, 0, 2, 0, 1, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		},//8
		{
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 0, 0, 0, 2, 0, 1, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 0, 0, 1, 2, 0, 1, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 0, 4, 4, 2, 0, 1, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 0, 4, 4, 1, 1, 1, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 0, 2, 1, 1, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 },
		},//9
		{
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 1, 1, 0, 0, 4, 1, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 0, 2, 2, 0, 4, 1, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 0, 0, 0, 2, 4, 1, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 0, 2, 1, 0, 4, 1, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 0, 0, 0, 1, 4, 1, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 0, 2, 2, 0, 4, 1, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0 },
			{ 0 ,0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0 },
			{ 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		}//10
	};
	void copy() {
		for (int x = 0; x < MAP_LEVEL; x++)
			for (int y = 0; y < MAP_HEIGHT; y++)
				for (int z = 0; z < MAP_WIDTH; z++)
					temp[x][y][z] = mapData[x][y][z];
	}
};