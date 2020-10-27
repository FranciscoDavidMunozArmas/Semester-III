/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 7 de julio de 2020 17:16:14
 * @function Declaration of Sudoku
*/

#ifndef SUDOKU_H
#define SUDOKU_H

class Sudoku
{
public:
    Sudoku() {};
    int** _init(int);
    void _print_sudoku(int**);
    int** _fill(int**);
    int _control_iterations(int, int, int, int, int**);
    void _print();
    void _verify_movements(int, int);
    bool _cuadrante(int**, int, int, int);
    void resolver_sudoku();

    virtual ~Sudoku();
protected:
private:
    int** matriz;
    int _cont_stop;
    int num_random;
    int _cont1;
    int _cont2;
};

#endif // SUDOKU_H
