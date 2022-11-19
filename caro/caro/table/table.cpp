#include "table.h"
#include "../color/color.h"
#include "../goto/goto.h"

#include <iostream>
#include <Windows.h>

using namespace std;

void draw_table(int x, int y, int c, int r, int c_size, int r_size) {
	int cnt = 0;
	
	GotoXY(x, y + (++cnt));
	cout << char(201);
	for (int i = 1; i <= c; ++i) {
		for (int j = 0; j < c_size; ++j) cout << char(205);
		cout << char(i == c ? 187 : 203);
	}

	for (int z = 1; z <= r; ++z) {
		for (int k = 0; k < r_size; ++k) {
			GotoXY(x, y + (++cnt));
			cout << char(186);
			for (int i = 1; i <= c; ++i) {
				for (int j = 0; j < c_size; ++j) cout << ' ';
				cout << char(186);
			}
		}
		GotoXY(x, y + (++cnt));
		cout << char(z == r ? 200 : 204);
		for (int i = 1; i <= c; ++i) {
			for (int j = 0; j < c_size; ++j) cout << char(205);
			cout << char(z == r ? i == c ? 188 : 202 : i == c ? 185 : 206);
		}
	}
	return;
}

void draw_color_table(int x, int y, int c, int r, int sz, string back_ground, string word) {
	
	TextColor(back_ground, word);
	draw_table(x, y, c, r , sz * 3, sz);
	return;
}