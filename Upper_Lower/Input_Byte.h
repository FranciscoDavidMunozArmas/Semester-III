/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 7 de julio de 2020 17:16:14
 * @function Declaration of Input_Byte
*/

#ifndef INPUT_BYTE_H
#define INPUT_BYTE_H

#include <iostream>

using namespace std;

class Input_Byte
{
public:
    Input_Byte();
    string _input(char* _msg);
    virtual ~Input_Byte();
protected:
private:
    string _delete(string str_delete);
    char _upper_lower(char _letter);
};

#endif
