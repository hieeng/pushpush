#include "view.h"
void view::drawCell(int col, int row) {
	int cell = _data.mapData[lv][row][col];
	textbackground((cell == 1) ? DARKGRAY : BLACK);
	gotoxy((MAP_X1 + col + 1) * 2, MAP_Y1 + row + 1);
	puts(_data.cellSymbol[cell]);
	gotoxy(57, 15);
	cout << _data.step;
	gotoxy(50, 9);
	cout << "���ӷ��� : " << lv;
}
void view::drawCharacter(int mx, int my)
{
	textbackground(BLACK);
	gotoxy((MAP_X1 + mx + 1) * 2, MAP_Y1 + my + 1);
	puts("��");
}
void view::drawMap() {
	for (int row = 0; row < MAP_HEIGHT; ++row)
		for (int col = 0; col < MAP_WIDTH; ++col)
			drawCell(col, row);
}
void view::scolor(unsigned short text, unsigned short back) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}
void view::mapReset() {	//���ʱ�ȭ
	for (int i = 0; i < MAP_HEIGHT; i++)
		for (int j = 0; j < MAP_WIDTH; j++)
			_data.mapData[lv][i][j] = _data.temp[lv][i][j];
}
int view::mainChoose(int x, int y) {	//�ʱ�ȭ�� ����
	int mum = 1;
	int put;
	int max = 0;
	while (true)
	{
		scolor(15, 0); max = 0;
		gotoxy(x, y); cout << "�ѤѤѤѤѤѤѤѤ�" << endl;
		gotoxy(x, y + 1); cout << "�� PushPush Game ��" << endl;
		gotoxy(x, y + 2); cout << "�ѤѤѤѤѤѤѤѤ�" << endl;
		gotoxy(x, y + 3 + max); max++; if (mum == max) { scolor(12, 0); cout << "  ��"; scolor(15, 0); }
		else cout << " �� "; cout << "  ���� ����";
		gotoxy(x, y + 3 + max); max++; if (mum == max) { scolor(12, 0); cout << "  ��"; scolor(15, 0); }
		else cout << " �� "; cout << "  ���� ���";
		gotoxy(x, y + 3 + max); max++; if (mum == max) { scolor(12, 0); cout << "  ��"; scolor(15, 0); }
		else cout << " �� "; cout << "  ���� ����";

		put = _getch();
		if (put == 224) {
			put = _getch();
			if (put == 72) { mum--; if (mum < 1)mum = max; }
			if (put == 80) { mum++; if (mum > max)mum = 1; }
		}
		if (put == 13) {
			for (int end = 0; end < max; end++)
				if (mum == end)return end;	//���� ���θ޴�
		}
		if (put == 13 && mum == max || put == 27) return -1; //����
	}
}
int view::showStartScreen() {	//�ʱ�ȭ�� �����ֱ�
	while (true) {
		system("cls");
		int mm = 0;
		gotoxy(1, 1); cout << "OOP term project";
		mm = mainChoose(5, 3);
		if (mm == 1) {
			showGameScreen();
		}
		else if (mm == 2) {
			system("cls");
			cout << "�ϸ� ����Ű�� ������ ���� �ؿ� �־� �ݷ� ����� �ȴ�." << endl;
			cout << "\n\n�������� ����Ű�� ��������" << endl;
			while (mm != 13) mm = _getch();
		}//���ӹ��
		else if (mm == -1) return 0;
	}
}

void view::showGameScreen() {	//����ȭ�� �����ֱ�
	int x = 6, y = 6;
	_data.step = 0;
	int key, oldx, oldy;
	system("cls");
	_setcursortype(_NOCURSOR);
	drawMap();
	gotoxy(50, 10);
	cout << "�ٽ��ϱ� : R";
	gotoxy(50, 11);
	cout << "�����ܰ� : T";
	gotoxy(50, 12);
	cout << "�����ܰ� : E";
	gotoxy(50, 13);
	cout << "����ȭ�� : ESC";
	gotoxy(50, 15);
	cout << "���� : ";
	do {
		int dx = 0, dy = 0;
		drawCharacter(x, y);
		key = _model.getkey();
		oldx = x;
		oldy = y;
		_data.step++;
		switch (key)
		{
		case M_UPKEY: if (y > 0) dy--; break;
		case M_DOWNKEY: if (y < MAP_HEIGHT - 1) dy++; break;
		case M_LEFTKEY: if (x > 0) dx--; break;
		case M_RIGHTKEY: if (x < MAP_WIDTH - 1) dx++; break;
		case 114: {	//�ٽ��ϱ�
			mapReset();
			_data.step = 0;
			x = 6; y = 6;
			gotoxy(57, 15);
			cout << "      ";
			drawCharacter(x, y);
			drawMap();
			break;
		}
		case 116: {	//���������� ����
			mapReset();
			if (lv < 9)
				lv++;
			_data.step = 0;
			x = 6; y = 6;
			gotoxy(57, 15);
			cout << "     ";
			drawCharacter(x, y);
			drawCharacter(x, y);
			drawMap();
			break;
		}
		case 101: {	//���������� ����
			mapReset();
			if (lv != 0)
				lv--;
			_data.step = 0;
			x = 6; y = 6;
			gotoxy(57, 15);
			cout << "      ";
			drawCharacter(x, y);
			drawCharacter(x, y);
			drawMap();
			break;
		}
		}

		x += dx;
		y += dy;

		switch (_data.mapData[lv][y][x]) {
		case 1: {x = oldx; y = oldy; }; break;
		case 2: {	//��
			if (_data.mapData[lv][y + dy][x + dx] == 0) {	//�ް�����  ���
			_data.mapData[lv][y + dy][x + dx] = 2;	//������� ������
			_data.mapData[lv][y][x] = 0;	//���� �� ����
		}
			else if (_data.mapData[lv][y + dy][x + dx] == 4) {	//�ް����� ����
				_data.mapData[lv][y + dy][x + dx] = 8;	//������ ����
				_data.mapData[lv][y][x] = 0;	//���� �����
			}
			else if (_data.mapData[lv][y + dy][x + dx] == 1) {	//�ް����� ��
				x = oldx; y = oldy;
			}
			else if (_data.mapData[lv][y + dy][x + dx] == 2) {	//�ް����� ��
				if (_data.mapData[lv][y + dy + dy][x + dx + dx] == 4) {		//�� �ڰ� ����
					_data.mapData[lv][y + dy][x + dx] = 2;
					_data.mapData[lv][y + dy + dy][x + dx + dx] = 8;
					_data.mapData[lv][y][x] = 0;
				}
				else if (_data.mapData[lv][y + dy][x + dx] == 2) {	//
					if (_data.mapData[lv][y + dy + dy][x + dx + dx] == 1) {	//
						x = oldx; y = oldy;
					}
					_data.mapData[lv][y + dy][x + dx] = 2;
					_data.mapData[lv][y + dy + dy][x + dx + dx] = 2;
					_data.mapData[lv][y][x] = 0;
				}
				else
					x = oldx; y = oldy;
			}
			else if (_data.mapData[lv][y + dy][x + dx] == 8) {	//�ް����� ����
				if (_data.mapData[lv][y + dy + dy][x + dx + dx] == 4) {	//�� �ڰ� ����
					_data.mapData[lv][y + dy + dy][x + dx + dx] = 8;
					_data.mapData[lv][y + dy][x + dx] = 8;
					_data.mapData[lv][y][x] = 0;
				}
				else if(_data.mapData[lv][y + dy + dy][x + dx + dx] == 1)	//�� �ڰ� ��
					x = oldx; y = oldy;
			}
			break;
		}
		case 8: {	//����
			if (_data.mapData[lv][y + dy][x + dx] == 0) {	//�ް����� ���
				_data.mapData[lv][y + dy][x + dx] = 2;	
				_data.mapData[lv][y][x] = 4;	
			}
			else if (_data.mapData[lv][y + dy][x + dx] == 4) {	//�ް����� ����
				_data.mapData[lv][y + dy][x + dx] = 8;
				_data.mapData[lv][y][x] = 4;
			}
			else if (_data.mapData[lv][y + dy][x + dx] == 8) {	//�ް����� ����
				if (_data.mapData[lv][y + dy + dy][x + dx + dx] == 4) {	//�� �ް����� ����
					_data.mapData[lv][y + dy + dy][x + dx + dx] = 8;
					_data.mapData[lv][y + dy][x + dx] = 8;
					_data.mapData[lv][y][x] = 4;
				}
				else if (_data.mapData[lv][y + dy + dy][x + dx + dx] == 0) {	//�� �ް����� ���
					_data.mapData[lv][y + dy + dy][x + dx + dx] = 2;
					_data.mapData[lv][y + dy][x + dx] = 8;
					_data.mapData[lv][y][x] = 4;
				}
				else if(_data.mapData[lv][y + dy + dy][x + dx + dx] == 1)	//�� �ް����� ��
					x = oldx; y = oldy;
			}
			else if (_data.mapData[lv][y + dy][x + dx] == 2) {	//�ް����� ��
				if (_data.mapData[lv][y + dy + dy][x + dx + dx] == 4) {	//�� �ް����� ����
					_data.mapData[lv][y + dy + dy][x + dx + dx] = 8;
					_data.mapData[lv][y + dy][x + dx] = 0;
					_data.mapData[lv][y][x] = 4;
				}
				else if (_data.mapData[lv][y + dy + dy][x + dx + dx] == 0) {	//�� �ް����� ���
					_data.mapData[lv][y + dy + dy][x + dx + dx] = 2;
					_data.mapData[lv][y + dy][x + dx] = 2;
					_data.mapData[lv][y][x] = 4;
				}
			}
			else if (_data.mapData[lv][y + dy][x + dx] == 1) {	//�ް����� ��
				x = oldx; y = oldy;
			}
			break;
		}
		}
		// erase old charactor
		if (oldx != x || oldy != y)
			drawMap();
		if (check() == true) {
			PlaySound(L"good.wav", 0, SND_FILENAME | SND_ASYNC);
			mapReset();
			_data.step = 0;
			gotoxy(50, 15);
			cout << "���� :      ";
			lv++;
			if (lv == 10) {
				system("cls");
				gotoxy(50, 12); cout << "�ѤѤѤѤѤѤѤ�" << endl;
				gotoxy(50, 13); cout << "�� Game Clear ��" << endl;
				gotoxy(50, 14); cout << "�ѤѤѤѤѤѤѤ�" << endl;
			}
			drawMap();
			x = 6; y = 6;
			drawCharacter(x, y);
		}
	} while (key != M_ESCKEY);
}
boolean view::check() {
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			if (_data.mapData[lv][i][j] == 2)
				return false;
			if (i == MAP_HEIGHT - 1 && j == MAP_WIDTH - 1) {
				_data.mapData[lv][i][j] = _data.temp[lv][i][j];
				return true;
			}
		}
	}
}
