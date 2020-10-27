/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date viernes, 21 de agosto de 2020 10:07:14
 * @function Main
*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "BR_Tree.cpp"
#include "Libraries/Menu.cpp"
#include "Libraries/Input.cpp"
#include "Libraries/To_number.cpp"

using namespace std;

int option();
template<typename T>
void menu(BR_Tree<T>* _stack);

/**
 * @brief option
 * @return int
*/
int option() {
    Menu _menu;
    char** _option = (char**)calloc(5, sizeof(char*));
    *(_option + 0) = "Introducir";
    *(_option + 1) = "Borrar";
    *(_option + 2) = "Buscar";
    *(_option + 3) = "Imprimir";
    *(_option + 4) = "Salir";

    return _menu.options("Seleccione una opcion", _option, 5);
}

/**
 * @brief menu
 * @tparam T
 * @param _tree
*/
template<typename T>
void menu(BR_Tree<T>* _tree) {
    Input _input;
    char _answer;
    int i;

    switch (option()) {
    case 1:
        do {
            system("cls");
            i = to_int(_input.input_int_number("Ingrese un numero: "));
            _tree->_add(i);
            fflush(stdin);
            cout << "Quiere continuar? (S/N): ";
            scanf("%c", &_answer);
            fflush(stdin);
        } while (tolower(_answer) != 'n');
        break;
    case 2:
    {
        system("cls");
        if (!_tree->_is_empty()) {
            i = to_int(_input.input_int_number("Ingrese un numero: "));
            _tree->_delete(i);
        }
        else {
            cout << "Arbol Vacio" << endl;
        }
    }
    break;
    case 3:
    {
        system("cls");
        int* _aux;
        if (!_tree->_is_empty()) {
            i = to_int(_input.input_int_number("Ingrese un numero: "));
            _aux = _tree->_look(i);
            if (_aux == NULL) {
                cout << "No existe" << endl;
            }
            else {
                cout << "Dato recuperado: " << (int)_aux << endl;
            }
        }
        else {
            cout << "Arbol Vacio" << endl;
        }
    }
    break;
    case 4:
        system("cls");
        _tree->_print();
        cout << endl;
        break;
    default:
        cout << endl << endl << endl << endl;
        exit(0);
        break;
    }
    system("pause");
    system("cls");
}

int main()
{
    BR_Tree<int> _tree;
    while (true) {
        menu(&_tree);
    }
}
