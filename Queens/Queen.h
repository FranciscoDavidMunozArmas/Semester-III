/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 7 de julio de 2020 17:16:14
 * @function Declaration of Queen
*/

#ifndef QUEEN_H
#define QUEEN_H

#include "Libraries/Matrix.h"

class Queen
{
public:
    Queen();
    Queen(int _size);
    void _print_table();
    void _start();
    virtual ~Queen();
protected:
private:
    int** _table;
    int _size;
    int _queens;
    Matrix _matrix;

    void _solve(int x, int y, int solution, int* solutions, int* _unique);
    bool _find_queen(int x, int y);
    bool _is_solve();
};

#endif
