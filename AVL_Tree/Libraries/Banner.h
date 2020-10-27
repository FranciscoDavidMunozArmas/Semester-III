/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 28 de mayo de 2020 10:07:14
 * @function Declaration of Banner
*/

#ifndef BANNER_H
#define BANNER_H

#include <iostream>

using namespace std;

class Banner
{
public:
    Banner();
    void _banner_right_left(string _text, int x, int y);
    void _banner_right_left_left_right(string _text, int x, int y);
    void _banner_left_right(string _text, int x, int y);
    virtual ~Banner();
protected:
private:
};

#endif
