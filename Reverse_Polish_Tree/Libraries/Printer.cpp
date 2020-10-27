/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 28 de mayo de 2020 10:07:14
 * @function Declaration of Printer
*/

#include <windows.h>
#include <fstream>
#include <string>
#include <iostream>

#include "Printer.h"

#pragma once

/**
 * @brief Printer
 * @return 
*/
Printer::Printer() {}

/**
 * @brief print_file
 * @param _file 
*/
void Printer::print_file(basic_ifstream<TCHAR>& _file) {
	PRINTDLG _printer_dialog;
	DOCINFO _document;
	basic_string<TCHAR> _line;
	int y = 300;

	memset(&_printer_dialog, 0, sizeof(PRINTDLG));
	memset(&_document, 0, sizeof(DOCINFO));

	_document.cbSize = sizeof(DOCINFO);
	_document.lpszDocName = TEXT("Imprimiendo");

	_printer_dialog.lStructSize = sizeof(PRINTDLG);
	_printer_dialog.Flags = PD_PAGENUMS | PD_RETURNDC;
	_printer_dialog.nFromPage = 1;
	_printer_dialog.nToPage = 1;
	_printer_dialog.nMinPage = 1;
	_printer_dialog.nMaxPage = 0xFFFF;

	if (_file.fail()) {
		cout << "Fallo la impresion" << endl;
		system("pause");
		system("cls");
		return;
	}

	if (PrintDlg(&_printer_dialog)) {
		if (_printer_dialog.hDC) {
			if (StartDoc(_printer_dialog.hDC, &_document) != SP_ERROR) {
				cout << "Imprimiendo" << endl;
				StartPage(_printer_dialog.hDC);
				while (!_file.eof()) {
					getline(_file, _line);
					_out_text_xy(_printer_dialog.hDC, 500, y, _line.c_str());
					y += 100;
				}

				EndPage(_printer_dialog.hDC);
				EndDoc(_printer_dialog.hDC);
			}
		}
	}
}

/**
 * @brief _out_text_xy
 * @param hdc 
 * @param x 
 * @param y 
 * @param msg 
*/
void Printer::_out_text_xy(HDC hdc, int x, int y, basic_string<TCHAR> msg) {
	TextOut(hdc, x, y, msg.c_str(), static_cast<int>(msg.length()));
}

/**
 * @brief ~Printer 
 * @return 
*/
Printer::~Printer() {}
