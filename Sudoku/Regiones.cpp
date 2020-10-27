/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 7 de julio de 2020 17:16:14
 * @function Implementat of Regiones
*/

#include <iostream>
#include <math.h>
#include <sstream>

#include "Regiones.h"
#include "Ingreso.cpp"

/**
 * @brief 
 * @return Regiones
*/
Regiones::Regiones() {}

/**
 * @brief Regiones
 * @return 
*/
Regiones::Regiones(int** _cuadrado) {
    this->cuadrado = _cuadrado;
}

/**
 * @brief get_Region
 * @return int**
*/
int** Regiones::get_Region() {
    return cuadrado;
}

/**
 * @brief set_Region
 * @param _cuadrado 
*/
void Regiones::set_Region(int** _cuadrado) {
    this->cuadrado = _cuadrado;
}

/**
 * @brief llenar
 * @param a 
 * @param b 
 * @return int**
*/
int** Regiones::llenar(int a, int b) {
    int x = 0, k = 0, p = 1, j = 0, t = 0, s = 0, d = 0;
    x = (b - 1) / 2;
    t = ((a + 1) / 2);
    s = (a - x - 1) / 2;
    d = x;

    for (int g = 0; g < ((a + 1) / 2); g++) {
        j = g;
        k = g;
        for (int i = x; i >= j; i--) {
            *(*(cuadrado + i) + k) = p;
            if (k < (d - s)) {
                *(*(cuadrado + i) + (k + t)) = p;
            }
            if (k > (d + s)) {
                *(*(cuadrado + i) + (k - t)) = p;
            }
            if (i > (d + s)) {
                *(*(cuadrado + (i - t)) + k) = p;
            }
            if (i < (d - s)) {
                *(*(cuadrado + (i + t)) + k) = p;
            }

            k++;
            p++;
        }
        x++;
    }
    return cuadrado;
}

/**
 * @brief mostrar
 * @param a 
 * @param b 
*/
void Regiones::mostrar(int a, int b) {
    //system("cls");
    int x = 0, t = 0, s = 0;
    t = ((a + 1) / 2);
    x = (b - 1) / 2;
    s = (a - x - 1) / 2;

    for (int l = 0; l < a; l++) {
        printf("\n\t");
        for (int h = 0; h < b; h++) {
            if (h >= (x - s) && h <= (x + s) && l <= (x + s) && l >= (x - s)) {
                printf("\t %d", *(*(cuadrado + l) + h));
            }
        }
    }
}

/**
 * @brief iniciar
*/
void Regiones::iniciar() {
    int** cuadrado;
    Ingreso ingreso;
    int num;
    string dim;
    do {
        dim = ingreso.leer("Digite el tamanio del arreglo: ", 2);
        istringstream(dim) >> num;
    } while (num % 2 == 0 || num < 0);
    num = 2 * num - 1;
    cuadrado = (int**)calloc(num, sizeof(int*));
    for (int i = 0; i < num; i++) {
        *(cuadrado + i) = (int*)calloc(num, sizeof(int));
    }

    Regiones cubo = Regiones(cuadrado);
    cubo.llenar(num, num);
    system("cls");
    cubo.mostrar(num, num);
    cubo.mostrar(num, num);
    system("pause");
}

/**
 * @brief ~Regiones
 * @return 
*/
Regiones::~Regiones() {}
