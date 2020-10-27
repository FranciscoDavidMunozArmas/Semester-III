#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "List_Double.cpp"
#include "Libraries/Menu.cpp"
#include "Libraries/Input.cpp"
#include "Libraries/To_number.cpp"

using namespace std;

int option();
template<typename T>
void menu(List_Double<T> _list);

int option() {
    Menu _menu;
    char** _option = (char**)calloc(8, sizeof(char*));
    *(_option + 0) = "Introducir por cola";
    *(_option + 1) = "Introducir por cabeza";
    *(_option + 2) = "Introducir por indice";
    *(_option + 3) = "Imprimir";
    *(_option + 4) = "Borrar primer elemento";
    *(_option + 5) = "Borrar ultimo elemento";
    *(_option + 6) = "Borrar por indice";
    *(_option + 7) = "Salir";

    return _menu.options("Seleccione una opcion", _option , 8);
}

template<typename T>
void menu(List_Double<T>* _list) {
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
    {
        system("cls");
        int _index = to_int(_input.input_int_number("Ingrese el indice: "));
        system("cls");
        i = to_int(_input.input_int_number("Ingrese un numero: "));
        _list->add_in(i, _index);
    }
        break;
    case 4:
        system("cls");
        //_list->_print_node();
        cout << _list->to_string() << endl;
        system("pause");
        break;
    case 5:
        system("cls");
        _list->_delete_begin();
        system("pause");
        break;
    case 6:
        system("cls");
        _list->_delete_end();
        system("pause");
        break;
    case 7:
    {
        system("cls");
        int _index = to_int(_input.input_int_number("Ingrese el indice: "));
        _list->_delete_in(_index);
    }break;
    default:
        exit(0);
        break;
    }
}

int main()
{
    List_Double<int> _list;
    do {
        menu(&_list);
    } while (true);
    return 0;
}
