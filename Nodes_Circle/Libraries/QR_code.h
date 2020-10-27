
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
