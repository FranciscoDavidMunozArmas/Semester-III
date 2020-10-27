/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 7 de julio de 2020 17:16:14
 * @function Main
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <graphics.h>

#include "1/PDF_Creator.cpp"

using namespace std;

int main() {

    /*File_reader _fr;
    FILE* file;
    string _data = "hola mundo";
    _fr._write_in_file(file, "test.txt", &_data);
    //string _aux = "txt2pdf.exe test.txt respuestas.pdf -oao -pfs10 -pps0 -ptc1000 -width595 -height842";
    string _aux = "copy test.txt copy.txt";
    system(_aux.c_str());*/

    PDF_Creator _pdf("test.pdf");
    _pdf._set_font_size(10);
    _pdf._set_size(_pdf.A0);
    _pdf._set_text("Propietario: sdasa\nMonto : $12391023921\t2020");
    _pdf._save_pdf();
}
