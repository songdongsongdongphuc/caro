#include "play.h"
#include "../table/table.h"
#include "../color/color.h"
#include "../goto/goto.h"

#include <iostream>
#include <conio.h>

using namespace std;

int come[50][50];
int row, collum;

bool win(int x, int y, int x_go, int y_go) {
	int sum = 0;
	for (int i = 0; i < 5; ++i) {
		if (x < 1 || x > collum || y < 1 || y > row) return 0;
		sum += come[x][y];
		x += x_go;
		y += y_go;
	}
	return (sum == 5) || (sum == -5);
}

bool check(int x, int y) {
	for (int i = -4; i <= 0; ++i) if (win(x + i, y + i, 1, 1)) return 1;
	for (int i = -4; i <= 0; ++i) if (win(x + i, y - i, 1, -1)) return 1;
	for (int i = -4; i <= 0; ++i) if (win(x + i, y, 1, 0)) return 1;
	for (int i = -4; i <= 0; ++i) if (win(x, y + i, 0, 1)) return 1;
	return 0;
}

bool play_caro(const int& ro, const int& co) {
	row = ro;
	collum = co;
	int len = 1;
	int x_pos = 20;
	int y_pos = 5;
	draw_color_table(x_pos - 2, y_pos - 2, collum, row, len, "Black", "Bright White");
	
	for (int i = 1; i <= row; ++i) {
		for (int j = 1; j <= collum; ++j) {
			come[i][j] = 0;
		}
	}

	int x = x_pos, y = y_pos;
	int x_now = 1, y_now = 1;
	GotoXY(x, y);
	bool role = 0;
	while (true) {
		char c;
		if (role) {
			while (c = _getch()) {
				if (c == '5') {
					if (come[x_now][y_now]) continue;
					TextColor("Black", "Bright Blue");
					cout << 'o';
					come[x_now][y_now] = 1;
					GotoXY(x, y);
					break;
				}
				if (c == '4' && x_now > 1) {
					--x_now;
					x -= len * 3 + 1;
					GotoXY(x, y);
				}
				if (c == '6' && x_now < collum) {
					++x_now;
					x += len * 3 + 1;
					GotoXY(x, y);
				}
				if (c == '8' && y_now > 1) {
					--y_now;
					y -= len+ 1;
					GotoXY(x, y);
				}
				if (c == '2' && y_now < row) {
					++y_now;
					y += len + 1;
					GotoXY(x, y);
				}
			}
		}
		else {
			while (c = _getch()) {
				if (c == ' ') {
					if (come[x_now][y_now]) continue;
					TextColor("Black", "Bright Red");
					cout << 'x';
					come[x_now][y_now] = -1;
					GotoXY(x, y);
					break;
				}
				if (c == 'a' && x_now > 1) {
					--x_now;
					x -= len * 3 + 1;
					GotoXY(x, y);
				}
				if (c == 'd' && x_now < collum) {
					++x_now;
					x += len * 3 + 1;
					GotoXY(x, y);
				}
				if (c == 'w' && y_now > 1) {
					--y_now;
					y -= len + 1;
					GotoXY(x, y);
				}
				if (c == 's' && y_now < row) {
					++y_now;
					y += len + 1;
					GotoXY(x, y);
				}
			}
		}
		if (check(x_now, y_now)) return role;
		role ^= 1;
	}

	return 0;
}