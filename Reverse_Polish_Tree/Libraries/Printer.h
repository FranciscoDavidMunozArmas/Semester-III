/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 28 de mayo de 2020 10:07:14
 * @function Implementation of Printer
*/

#ifndef PRINTER_H
#define PRINTER_H

#include <windows.h>
#include <fstream>

using namespace std;

class Printer
{
public:
    Printer();
    void print_file(basic_ifstream<TCHAR>& _file);
    virtual ~Printer();
protected:
private:
    void _out_text_xy(HDC hdc, int x, int y, basic_string<TCHAR> msg);
};

#endif
