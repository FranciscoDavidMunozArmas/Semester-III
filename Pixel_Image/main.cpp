/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 7 de julio de 2020 17:16:14
 * @function Main
*/

#include <windows.h>
#include <iostream>
#include <cstdio>
#include <vector>

#include "1/bitmap_image.hpp"
#include "Pixel.cpp"

using namespace std;

int main(){
    Pixel _pixel(1);
    bitmap_image image("dog.bmp");

    int width = image.height();
    int height = image.width();

    rgb_t color;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            color = image.get_pixel(i, j);
            _pixel.draw_pixel((int)color.red, (int)color.green, (int)color.blue, i, j);
        }
   }

   cin.ignore();
}
