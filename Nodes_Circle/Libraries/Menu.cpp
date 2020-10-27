/***********************************************************************
 * Module:  Array.cpp
 * Author:  USUARIO
 * Modified: jueves, 28 de mayo de 2020 19:07:11
 * Purpose: Implementation of the class Array
 ***********************************************************************/

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
#define ENTER 13

#pragma once

using namespace std;

/**
 * @brief options
 * @tparam T 
 * @param option 
 * @param index 
 * @return int
*/
template<typename T>
int Menu::options(T* option, int index) {
    int selection = 1;
    int key;
    bool flag = true;
    do {
        system("cls");
        screen.gotoxy(15, 4 + selection);
        printf(">");

        for (int i = 0; i < index; i++) {
            if (selection == i+1) {
                screen.gotoxy(16, 5 + i);
                cout << "  " << *(option + i);
            }
            else {
                screen.gotoxy(16, 5 + i);
                cout << *(option + i);
            }
        }

        do {
            key = getch();
        } while (key != UP && key != DOWN && key != ENTER);

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
        case ENTER:
            flag = false;
            break;
        }
    } while (flag);

    return selection;
}

/**
 * @brief options
 * @tparam T 
 * @param option 
 * @param index 
 * @param color 
 * @return int
*/
template<typename T>
int Menu::options(T* option, int index, int color) {
    int selection = 1;
    int key;
    bool flag = true;
    do {
        system("cls");
        screen.gotoxy(15, 4 + selection);
        printf(">");

        for (int i = 0; i < index; i++) {
            if (selection == i + 1) {
                screen.color_text(color);
                screen.gotoxy(16, 5 + i);
                cout << "  " << *(option + i);
            }
            else {
                screen.color_text(screen.LIGHT_GRAY);
                screen.gotoxy(16, 5 + i);
                cout << *(option + i);
            }
        }

        do {
            key = getch();
        } while (key != UP && key != DOWN && key != ENTER);

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
        case ENTER:
            flag = false;
            break;
        }
    } while (flag);
    screen.color_text(screen.LIGHT_GRAY);
    return selection;
}

/**
 * @brief options
 * @tparam T 
 * @param message 
 * @param option 
 * @param index 
 * @return int
*/
template<typename T>
int Menu::options(char* message, T* option, int index) {
    int selection = 1;
    int key;
    bool flag = true;
    do {
        system("cls");
        screen.gotoxy(15, 3);
        cout << message << endl;
        screen.gotoxy(15, 4 + selection);
        printf(">");

        for (int i = 0; i < index; i++) {
            if (selection == i + 1) {
                screen.gotoxy(16, 5 + i);
                cout << "  " << *(option + i);
            }
            else {
                screen.gotoxy(16, 5 + i);
                cout << *(option + i);
            }
        }

        do {
            key = getch();
        } while (key != UP && key != DOWN && key != ENTER);

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
        case ENTER:
            flag = false;
            break;
        }

    } while (flag);

    return selection;
}

/**
 * @brief options
 * @tparam T 
 * @param message 
 * @param option 
 * @param index 
 * @param color 
 * @return int
*/
template<typename T>
int Menu::options(char* message, T* option, int index, int color) {
    int selection = 1;
    int key;
    bool flag = true;
    do {
        system("cls");
        screen.gotoxy(15, 3);
        cout << message << endl;
        screen.gotoxy(15, 4 + selection);
        printf(">");

        for (int i = 0; i < index; i++) {
            if (selection == i + 1) {
                screen.color_text(color);
                screen.gotoxy(16, 5 + i);
                cout << "  " << *(option + i);
            }
            else {
                screen.color_text(screen.LIGHT_GRAY);
                screen.gotoxy(16, 5 + i);
                cout << *(option + i);
            }
        }

        do {
            key = getch();
        } while (key != UP && key != DOWN && key != ENTER);

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
        case ENTER:
            flag = false;
            break;
        }

    } while (flag);
    screen.color_text(screen.LIGHT_GRAY);
    return selection;
}
