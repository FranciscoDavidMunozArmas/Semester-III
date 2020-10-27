/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 7 de julio de 2020 17:16:14
 * @function Main
*/

#include <windows.h>
#include <fstream>
#include <string>
#include <iostream>
#include "Printer.cpp"

using namespace std;

int main(int argc,char *argv[])
{
    Printer _printer;
    basic_ifstream<TCHAR> in(TEXT("Maze.txt"));
    _printer.print_file(in);
    in.close();
return 0;
}
