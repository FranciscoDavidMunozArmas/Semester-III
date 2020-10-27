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

        for (int i = 0; i < index; i++) {
            if (selection == i+1) {
                screen.color_text(screen.YELLOW);
                screen.gotoxy(16, 5 + i);
                cout << *(option + i);
            }
            else {
                screen.gotoxy(16, 5 + i);
                cout << *(option + i);
            }
            screen.color_text(screen.LIGHT_GRAY);
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

    delete option;

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

        for (int i = 0; i < index; i++) {
            if (selection == i + 1) {
                screen.gotoxy(16, 5 + i);
                screen.color_text(color);
                cout << *(option + i);
            }
            else {
                screen.gotoxy(16, 5 + i);
                cout << *(option + i);
            }
            screen.color_text(screen.LIGHT_GRAY);
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

    delete option;

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
        screen.gotoxy(15, 3);
        cout << message << endl;

        for (int i = 0; i < index; i++) {
            if (selection == i + 1) {
                screen.color_text(screen.YELLOW);
                screen.gotoxy(16, 5 + i);
                cout << *(option + i);
            }
            else {
                screen.gotoxy(16, 5 + i);
                cout << *(option + i);
            }
            screen.color_text(screen.LIGHT_GRAY);
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
    
    delete option;
    delete message;
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

        for (int i = 0; i < index; i++) {
            if (selection == i + 1) {
                screen.color_text(color);
                screen.gotoxy(16, 5 + i);
                cout << *(option + i);
            }
            else {
                screen.gotoxy(16, 5 + i);
                cout << *(option + i);
            }
            screen.color_text(screen.LIGHT_GRAY);
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
    
    delete option;
    delete message;
    return selection;
}

/**
 * @brief yes_no_option
 * @param message
 * @param color
 * @return int
*/
int Menu::yes_no_option(char* message, int color) {
    char** _yes_no = (char**)malloc(2*sizeof(char*));
    *(_yes_no + 0) = "SI";
    *(_yes_no + 1) = "NO";

    return options(message, _yes_no, 2, color);
}

/**
 * @brief yes_no_option
 * @param message
 * @return int
*/
int Menu::yes_no_option(char* message) {
    char** _yes_no = (char**)malloc(2 * sizeof(char*));
    *(_yes_no + 0) = "SI";
    *(_yes_no + 1) = "NO";

    return options(message, _yes_no, 2);
}

/**
 * @brief yes_no_option
 * @param color
 * @return int
*/
int Menu::yes_no_option(int color) {
    char** _yes_no = (char**)malloc(2 * sizeof(char*));
    *(_yes_no + 0) = (char*)"SI";
    *(_yes_no + 1) = (char*)"NO";

    return options(_yes_no, 2, color);
}

/**
 * @brief yes_no_option
 * @return
*/
int Menu::yes_no_option() {
    char** _yes_no = (char**)malloc(2 * sizeof(char*));
    *(_yes_no + 0) = (char*)"SI";
    *(_yes_no + 1) = (char*)"NO";

    return options(_yes_no, 2);
}
