/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 7 de julio de 2020 17:16:14
 * @function Declaration of Matrix
*/

#ifndef MATRIX_H
#define MATRIX_H

#include "Array_dinamic.h"

class Matrix
{
public:
    Matrix();
    template<typename T>
    T** create_matrix(T** _matrix, int size);
    template<typename T>
    T** create_matrix(T** _matrix, int width, int height);
    template<typename T>
    T** set_cero(T** _matrix);
    template<typename T>
    void _print_matrix(T** _matrix);

    virtual ~Matrix();

protected:
private:
    Array_dynamic _ad;
};

#endif
