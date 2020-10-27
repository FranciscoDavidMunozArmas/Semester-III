/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 28 de mayo de 2020 10:07:14
 * @function Declaration of PDF_Creator
*/

#ifndef PDF_CREATOR_H
#define PDF_CREATOR_H

#include <iostream>

using namespace std;

class PDF_Creator
{
public:

    enum PAPER_FORMAT {
        A6, A5, A4, A3, A2, A1, A0
    };

    const int BLACK = 0;
    const int RED = 1000;

    PDF_Creator(const char* _pdf_name);
    void _set_font_size(int _size);
    void _set_text(const char* _text);
    void _set_size(PAPER_FORMAT _format);
    void _set_size(int _width, int _height);
    void _set_aligment(bool _alignment);
    void _set_color(int _color);
    void _save_pdf();
    ~PDF_Creator();
protected:
private:
    string _pdf;
    string _text;
    int _font_size;
    int _color;
    int _width;
    int _height;
    bool _alignment;
};

#endif
