/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 28 de mayo de 2020 10:07:14
 * @function Declaration of Pixel
*/

#ifndef PIXEL_H
#define PIXEL_H

#include<windows.h>
#include<windows.h>

class Pixel
{
    public:
        Pixel();
        Pixel(int _size);
        void set_pixel_size(int _size);
        void draw_pixel(int red, int green, int blue, int x, int y);
        COLORREF get_pixel(int x, int y);
        void end_pixel();
        virtual ~Pixel();

    protected:
    private:
        int _size;
        HWND _console;
        HDC _hdc;
};

#endif // PIXEL_H
