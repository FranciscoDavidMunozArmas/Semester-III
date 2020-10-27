/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 7 de julio de 2020 17:16:14
 * @function Declaration of Horse_ride
*/

#ifndef HORSE_RIDE_H
#define HORSE_RIDE_H

#include "Libraries/Matrix.h"

class Horse_ride
{
public:
    Horse_ride();
    Horse_ride(int _table_size);
    void _init_position(int x, int y);
    void _jump(int x, int y, int _jump_index, int _solution, int _pos, int* _total_sol);
    void _start();
    void _print_table();

    int _get_next_position(int x, int y, int _move);

    ~Horse_ride();
protected:
private:
    Matrix _matrix;

    int _startX;
    int _startY;
    int _size;
    int** _movement;
    int** table;

    int** _horse_move();
};

#endif
