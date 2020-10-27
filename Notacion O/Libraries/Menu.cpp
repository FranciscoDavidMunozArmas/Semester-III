/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 28 de mayo de 2020 10:07:14
 * @function Implementation of Menu
*/

#include "Menu.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>
#include <mmsystem.h>

#include "Screen.cpp"

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13
#define ESCAPE 27

#pragma once

using namespace std;

template<typename T>
int Menu::options_vetical(T* option, int index, int x, int y) {
    int selection = 1;
    int key;
    bool flag = true;
    do {
        for (int i = 0; i < index; i++) {
            if (selection == i + 1) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
                screen.gotoxy(x, y + i);
                cout << *(option + i);
            }
            else {
                screen.gotoxy(x, y + i);
                cout << *(option + i);
            }
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        }

        do {
            key = getch();
        } while (key != UP && key != DOWN && key != ENTER && key != ESCAPE);

        switch (key) {
        case UP:
            selection--;
            if (selection <= 0) {
                selection = index;
            }
            break;
        case DOWN:
            selection++;
            if (selection > index) {
                selection = 1;
            }
            break;
        case ESCAPE:
        {
            selection = -1;
            flag = false;
        }
            break;
        case ENTER:
            flag = false;
            break;
        }
    } while (flag);

    return selection;
}

template<typename T>
int Menu::options_horizontal(T* option, int index, int x, int y) {
    int selection = 1;
    int key;
    bool flag = true;
    do {
        for (int i = 0; i < index; i++) {
            if (selection == i + 1) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
                screen.gotoxy(x * i, y);
                cout << *(option + i);
            }
            else {
                screen.gotoxy(x * i, y);
                cout << *(option + i);
            }
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        }

        do {
            key = getch();
        } while (key != LEFT && key != RIGHT && key != ENTER && key != ESCAPE);

        switch (key) {
        case LEFT:
            selection--;
            if (selection <= 0) {
                selection = index;
            }
            break;
        case RIGHT:
            selection++;
            if (selection > index) {
                selection = 1;
            }
            break;
        case ESCAPE:
        {
            selection = -1;
            flag = false;
        }
        case ENTER:
            flag = false;
            break;
        }
    } while (flag);

    return selection;
}
