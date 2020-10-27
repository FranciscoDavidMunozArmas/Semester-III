#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "Queue.cpp"
#include "Libraries/Menu.cpp"
#include "Libraries/Input.cpp"
#include "Libraries/To_number.cpp"

using namespace std;

int option();
template<typename T>
void menu(Queue<T>* _queue);

int option() {
    Menu _menu;
    char** _option = (char**)calloc(5, sizeof(char*));
    *(_option + 0) = "Introducir";
    *(_option + 1) = "Desencolar";
    *(_option + 2) = "Limpiar";
    *(_option + 3) = "Imprimir";
    *(_option + 4) = "Salir";

    return _menu.options("Seleccione una opcion", _option, 5);
}

template<typename T>
void menu(Queue<T>* _queue) {
    Input _input;
    char _answer;
    int i;

    switch (option()) {
    case 1:
        do {
            system("cls");
            i = to_int(_input.input_int_number("Ingrese un numero: "));
            _queue->enqueue(i);
            fflush(stdin);
            cout << "Quiere continuar? (S/N): ";
            scanf("%c", &_answer);
            fflush(stdin);
        } while (tolower(_answer) != 'n');
        break;
    case 2:
    {
        system("cls");
        if (!_queue->_is_empty()) {
            cout << _queue->dequeue() << endl;
        }
        else {
            cout << "Cola Vacia" << endl;
        }
        system("pause");
    }
    break;
    case 3:
    {
        system("cls");
        _queue->_clear_all();
        system("pause");
    }
    break;
    case 4:
        system("cls");
        cout << _queue->to_string() << endl;
        system("pause");
        break;
    default:
        _queue->~Queue();
        cout << endl << endl << endl << endl;
        exit(0);
        break;
    }
}

int main()
{
    Queue<int> _queue;

    while (true) {
        menu(&_queue);
    }
}
