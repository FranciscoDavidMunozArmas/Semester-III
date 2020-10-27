/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 28 de mayo de 2020 10:07:14
 * @function Implementation of QR_code
*/

#include "QR_code.h"
#include "lib/QrCode.cpp"
#include "Pixel.cpp"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
using qrcodegen::QrCode;
using qrcodegen::QrSegment;

/**
 * @brief _create_QR
 * @param _code 
*/
void QR_code::_create_QR(const char* _code) {
	const QrCode::Ecc correction_LV = QrCode::Ecc::MEDIUM;
	const QrCode _qr = QrCode::encodeText(_code, correction_LV);

	_print_QR(_qr);
}

/**
 * @brief _print_QR
 * @param _code 
*/
void QR_code::_print_QR(const QrCode& _code) {
	int _border = 2;
	Pixel _brush(5);
	for (int y = -_border; y < _code.getSize() + _border; y++) {
		for (int x = -_border; x < _code.getSize() + _border; x++) {
			if (_code.getModule(x, y)) {
				_brush.draw_pixel(0 ,0 ,0 , x + _border, y + _border);
			}
			else {
				_brush.draw_pixel(255, 255, 255, x + _border, y + _border);
			}
		}
	}

	cin.ignore();
}
