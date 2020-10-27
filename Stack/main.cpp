#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "Stack.cpp"
#include "Libraries/Menu.cpp"
#include "Libraries/Input.cpp"
#include "Libraries/To_number.cpp"

using namespace std;

int option();
template<typename T>
void menu(Stack<T>* _stack);

int option() {
    Menu _menu;
    char** _option = (char**)calloc(5, sizeof(char*));
    *(_option + 0) = "Introducir";
    *(_option + 1) = "Pop";
    *(_option + 2) = "Limpiar";
    *(_option + 3) = "Imprimir";
    *(_option + 4) = "Salir";

    return _menu.options("Seleccione una opcion", _option , 5);
}

template<typename T>
void menu(Stack<T>* _stack) {
    Input _input;
    char _answer;
    int i;

    switch (option()) {
    case 1:
        do {
            system("cls");
            i = to_int(_input.input_int_number("Ingrese un numero: "));
            _stack->_push(i);
            fflush(stdin);
            cout << "Quiere continuar? (S/N): ";
            scanf("%c", &_answer);
            fflush(stdin);
        } while (tolower(_answer) != 'n');
        break;
    case 2:
    {
        system("cls");
        if (!_stack->_is_empty()) {
            cout << _stack->_pop() << endl;
        }
        else {
            cout << "Pila vacia" << endl;
        }
        system("pause");
    }
        break;
    case 3:
    {
        system("cls");
        _stack->_clear_all();
        system("pause");
    }
        break;
    case 4:
        system("cls");
        cout << _stack->to_string() << endl;
        system("pause");
        break;
    default:
        _stack->~Stack();
        cout << endl << endl << endl << endl;
        exit(0);
        break;
    }
}

int main()
{
    Stack<int> _stack;
    while (true) {
        menu(&_stack);
    }
}
