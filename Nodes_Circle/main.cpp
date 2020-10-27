#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "List_Circle.cpp"
#include "Libraries/Menu.cpp"
#include "Libraries/Input.cpp"
#include "Libraries/To_number.cpp"

using namespace std;

int option();
template<typename T>
void menu(List_Circle<T> _list);

int option() {
    Menu _menu;
    char** _option = (char**)calloc(6, sizeof(char*));
    *(_option + 0) = "Introducir por cola";
    *(_option + 1) = "Introducir por cabeza";
    *(_option + 2) = "Imprimir";
    *(_option + 3) = "Borrar primer elemento";
    *(_option + 4) = "Borrar ultimo elemento";
    *(_option + 5) = "Salir";

    return _menu.options("Seleccione una opcion", _option , 6);
}

template<typename T>
void menu(List_Circle<T>* _list) {
    Input _input;
    char _answer;
    int i;

    switch (option()) {
    case 1:
        do {
            system("cls");
            i = to_int(_input.input_int_number("Ingrese un numero: "));
            _list->add_end(i);
            fflush(stdin);
            cout << "Quiere continuar? (S/N): ";
            scanf("%c", &_answer);
            fflush(stdin);
        } while (_answer != 'N' && _answer != 'n');
        break;
    case 2:
        do {
            system("cls");
            i = to_int(_input.input_int_number("Ingrese un numero: "));
            _list->add_begin(i);
            fflush(stdin);
            cout << "Quiere continuar? (S/N): ";
            scanf("%c", &_answer);
            fflush(stdin);
        } while (_answer != 'N' && _answer != 'n');
        break;
    case 3:
        system("cls");
        //_list->_print_node();
        cout << _list->to_string() << endl;
        system("pause");
        break;
    case 4:
        system("cls");
        _list->_delete_begin();
        system("pause");
        break;
    case 5:
        system("cls");
        _list->_delete_end();
        system("pause");
        break;
    default:
        exit(0);
        break;
    }
}

int main()
{
    List_Circle<int> _list;
    do {
        menu(&_list);
    } while (true);
    return 0;
}
