/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 25 de julio de 2020 17:16:14
 * @function Implementation of Controller
*/

#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "Libraries/Input.cpp"
#include "Libraries/Menu.cpp"

#include "Controller.h"
#include "Reverse_Polish.cpp"

using namespace std;

/**
 * @brief Controller
 * @return
*/
Controller::Controller() {}

/**
 * @brief menu
 * @param flag
*/
void Controller::menu(bool* flag) {
	Reverse_Polish _rp;
	Input _input;
	string _data;

	switch (_option()) {
	case 1:
		do {
			system("cls");
			_data = _input.input("Escriba la expresion: ");
		} while (!_rp.is_infix(_data));
		_rp._set_expression(_data);
		_rp._pre_order();
		_rp._solve();
		break;
	case 2:
		do {
			system("cls");
			_data = _input.input("Escriba la expresion: ");
		} while (!_rp.is_infix(_data));
		_rp._set_expression(_data);
		_rp._post_order();
		_rp._solve();
		break;
	case 3:
		do {
			system("cls");
			_data = _input.input("Escriba la expresion: ");
		} while (!_rp.is_infix(_data));
		_rp._set_expression(_data);
		cout << "Prefija: ";
		_rp._pre_order();
		cout << "Postfija: ";
		_rp._post_order();
		_rp._solve();
		break;
	case 4:
		do {
			system("cls");
			_data = _input.input("Escriba la expresion: ");
		} while (!_rp.is_infix(_data));
		_rp._set_expression(_data);
		_rp.print();
		break;
	default:
		cout << endl << endl;
		*flag = false;
		break;
	}
	_rp.~Reverse_Polish();
	cout << endl << endl;
	system("pause");

}

/**
 * @brief _option
 * @return int
*/
int Controller::_option() {
	Menu _menu;
	char** _options = (char**)malloc(5*sizeof(char*));
	*(_options + 0) = "Prefija";
	*(_options + 1) = "Posfija";
	*(_options + 2) = "Ambas";
	*(_options + 3) = "Mostrar Arbol";
	*(_options + 4) = "Salir";

	return _menu.options(_options, 5);
}

/**
 * @brief ~Controller
 * @return
*/
Controller::~Controller() {}

