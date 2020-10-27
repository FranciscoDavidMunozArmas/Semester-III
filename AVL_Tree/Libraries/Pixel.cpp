/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 28 de mayo de 2020 10:07:14
 * @function Implementation of Pixel
*/

#include<windows.h>
#include<iostream>

#include "Pixel.h"

#pragma once

/**
 * @brief Pixel
 * @return 
*/
Pixel::Pixel(){
    _console = GetConsoleWindow();
    _hdc = GetDC(_console);
    _size = 1;
}

/**
 * @brief Pixel
 * @param _size 
 * @return 
*/
Pixel::Pixel(int _size){
    _console = GetConsoleWindow();
    _hdc = GetDC(_console);
    this->_size = _size;
}

/**
 * @brief set_pixel_size
 * @param _size 
*/
void Pixel::set_pixel_size(int _size){
    this->_size = _size;
}

/**
 * @brief draw_pixel
 * @param red 
 * @param green 
 * @param blue 
 * @param x 
 * @param y 
*/
void Pixel::draw_pixel(int red, int green, int blue, int x, int y){
    COLORREF COLOR= RGB(red,green,blue);
    for(int i = 0; i < _size; i++){
        for(int j = 0; j < _size; j++){
            SetPixel(_hdc,i + x*_size,j + y*_size,COLOR);
        }
    }
}

/**
 * @brief get_pixel
 * @param x 
 * @param y 
 * @return COLORREF
*/
COLORREF Pixel::get_pixel(int x, int y){
    GetPixel(_hdc, x, y);
}

/**
 * @brief end_pixel
*/
void Pixel::end_pixel(){
    ReleaseDC(_console, _hdc);
}

Pixel::~Pixel() {}
