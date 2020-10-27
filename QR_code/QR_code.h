/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 7 de julio de 2020 17:16:14
 * @function Declaration QR_code
*/

#ifndef QR_CODE_H
#define QR_CODE_H

#include <iostream>
#include "lib/QrCode.cpp"

using namespace std;
using qrcodegen::QrCode;

class QR_code
{
public:
    QR_code() {};
    void _create_QR(const char* _to_write);
protected:
private:
    void _print_QR(const QrCode& _code);
};

#endif
