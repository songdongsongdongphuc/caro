#include "color.h"

#include <iostream>
#include <Windows.h>
#include <map>

void TextColor(std::string back_ground, std::string word) {
	std::map < std::string, int > mau;
	mau["Black"] = 0;
	mau["Blue"] = 1;
	mau["Green"] = 2;
	mau["Cyan"] = 3;
	mau["Red"] = 4;
	mau["Purple"] = 5;
	mau["Yellow"] = 6;
	mau["White"] = 7;
	mau["Gray"] = 8;
	mau["Bright Blue"] = 9;
	mau["Bright Green"] = 10;
	mau["Bright Cyan"] = 11;
	mau["Bright Red"] = 12;
	mau["Bright Purple"] = 13;
	mau["Bright Yellow"] = 14;
	mau["Bright White"] = 15;

	int x = mau[back_ground] * 16 + mau[word];

	HANDLE color;
	color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, x);
}