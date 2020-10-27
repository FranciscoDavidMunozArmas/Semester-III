#include "QR_code.h"
#include "lib/QrCode.cpp"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
using qrcodegen::QrCode;
using qrcodegen::QrSegment;

void QR_code::_create_QR(const char* _code) {
	const QrCode::Ecc correction_LV = QrCode::Ecc::MEDIUM;
	const QrCode _qr = QrCode::encodeText(_code, correction_LV);

	_print_QR(_qr);
}

void QR_code::_print_QR(const QrCode& _code) {
	int _border = 2;

	for (int y = -_border; y < _code.getSize() + _border; y++) {
		for (int x = -_border; x < _code.getSize() + _border; x++) {
			int _pixel = (_code.getModule(x, y)) ? 32 : 219;
			cout << (char)_pixel << (char)_pixel;
		}
		cout << endl;
	}
	cout << endl;
}
