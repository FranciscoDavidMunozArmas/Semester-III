/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 7 de julio de 2020 17:16:14
 * @function Main
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "Libraries/Input.h"
#include "Libraries/To_number.cpp"

#include "Knapsack_Item.cpp"
#include "Knapsack.cpp"

using namespace std;

int main()
{
    Input _input;
    double _weight;
    int _value;
    char _answer;

    do {
        _weight = to_double(_input.input_number("Introduce la capacidad de la mochila: "));
    } while (_weight == 0);

    Knapsack _pack(_weight);

    do {
        int _item_value;
        double _item_weight;

        do {
            _item_weight = to_double(_input.input_number("\nEl peso del objeto: "));
        } while (_item_weight == 0);

        _item_value = to_int(_input.input_int_number("El valor del objeto: "));
        Knapsack_Item _item(_item_weight, _item_value);

        _pack._set_item(_item);

        printf("Desea continuar? (S/N): ");
        fflush(stdin);
        scanf("%c", &_answer);
        fflush(stdin);

    } while (_answer != 'N' && _answer != 'n');

    _pack._start_Knapsack();
}

    /*Knapsack_Item _item_1(12, 4);
    Knapsack_Item _item_2(2, 2);
    Knapsack_Item _item_3(1, 2);
    Knapsack_Item _item_4(4, 10);
    Knapsack_Item _item_5(1, 1);*/

    /*Knapsack_Item _item_1(100, 4);
    Knapsack_Item _item_2(155, 2);
    Knapsack_Item _item_3(50, 2);
    Knapsack_Item _item_4(112, 10);
    Knapsack_Item _item_5(70, 1);
    Knapsack_Item _item_6(80, 6);
    Knapsack_Item _item_7(60, -1);
    Knapsack_Item _item_8(18, 0);
    Knapsack_Item _item_9(110, 8);
    Knapsack_Item _item_10(55, 4);*/

    /*Knapsack_Item _item_1(42, 10);
    Knapsack_Item _item_2(23, 6);
    Knapsack_Item _item_3(21, 7);
    Knapsack_Item _item_4(15, 5);
    Knapsack_Item _item_5(7, 5);*/

    //Knapsack _pack(15);
    //Knapsack _pack(700);
    //Knapsack _pack(60);
