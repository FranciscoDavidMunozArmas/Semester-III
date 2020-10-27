#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <new>

#include "Banner.h"
#include "Array_dinamic.cpp"
#include "Screen.cpp"

using namespace std;

Banner::Banner() {}


void Banner::_banner_right_left(string _text, int x, int y) {
	Array_dynamic _ad;
	Screen screen;
	char* _banner;
	ostringstream oss;

	_banner = (char*)malloc(_text.length() * sizeof(char));
	strcpy(_banner, _text.c_str());

	int _index = _text.length() - 1;
	for (char aux: _text) {
		screen.gotoxy(x + _index, y);
		oss << aux;
		cout << oss.str();
		_index--;
		Sleep(100);
	}

	for (int i = 0; i < _ad._dynamic_size(_banner); i++) {
		for (int j = 0; j < _ad._dynamic_size(_banner) - 1; j++) {
			*(_banner + j) = *(_banner + j + 1);
			if (j + 1 == _ad._dynamic_size(_banner) - 1 && i == 0) {
				*(_banner + j + 1) = ' ';
			}
		}
		screen.gotoxy(x, y);
		cout << _banner;
		Sleep(100);
	}
}

void Banner::_banner_right_left_left_right(string _text, int x, int y) {
	Array_dynamic _ad;
	Screen screen;
	char* _banner;
	ostringstream oss;

	_banner = (char*)malloc(_text.length() * sizeof(char));
	strcpy(_banner, _text.c_str());

	int _index = _text.length() - 1;
	for (char aux : _text) {
		screen.gotoxy(x + _index, y);
		oss << aux;
		cout << oss.str();
		_index--;
		Sleep(100);
	}

	Sleep(200);

	for (int i = 0; i < _ad._dynamic_size(_banner); i++) {
		for (int j = _ad._dynamic_size(_banner) - 1; j >= i; j--) {
			*(_banner + j) = *(_banner + j - 1);
		}
		*(_banner + i) = ' ';
		screen.gotoxy(x, y);
		cout << _banner;
		Sleep(100);
	}
}

void Banner::_banner_left_right(string _text, int x, int y) {
	Array_dynamic _ad;
	Screen screen;
	char* _banner = (char*)malloc(_text.length() * sizeof(char));
	strcpy(_banner, _text.c_str());
	ostringstream oss;

	for (int i = 0; i < _ad._dynamic_size(_banner); i++) {
		screen.gotoxy(x + i, y);
		cout << *(_banner + i);
		Sleep(100);
	}

	for (int i = 0; i < _ad._dynamic_size(_banner); i++) {
		screen.gotoxy(x + i, y);
		cout << " ";
		Sleep(100);
	}
}

Banner::~Banner() {}
