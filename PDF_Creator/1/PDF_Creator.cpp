/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 7 de julio de 2020 17:16:14
 * @function Implementation of PDF_Creator
*/

#include "PDF_Creator.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>

#include "File_reader.cpp"

#pragma once

using namespace std;

/**
 * @brief PDF_Creator
 * @param _pdf_name 
 * @return 
*/
PDF_Creator::PDF_Creator(const char* _pdf_name)
{
	_pdf = _pdf_name;
	_text = "";
	_font_size = 10;
	_color = this->BLACK;
	this->_width = 595;
	this->_height = 842;
	this->_alignment = true;
}

/**
 * @brief _set_text
 * @param _text 
*/
void PDF_Creator::_set_text(const char* _text) {
	ostringstream oss;
	oss << _text;
	this->_text += oss.str();
}

/**
 * @brief _set_color
 * @param _color 
*/
void PDF_Creator::_set_color(int _color) {
	if (_color < 0) {
		_color = 0;
	}

	this->_color = _color;
}

/**
 * @brief _set_size
 * @param _format 
*/
void PDF_Creator::_set_size(PAPER_FORMAT _format) {
	switch (_format)
	{
	case PDF_Creator::A6:
		_width = 298;
		_height = 420;
		break;
	case PDF_Creator::A5:
		_width = 420;
		_height = 595;
		break;
	case PDF_Creator::A4:
		_width = 595;
		_height = 842;
		break;
	case PDF_Creator::A3:
		_width = 842;
		_height = 1191;
		break;
	case PDF_Creator::A2:
		_width = 1191;
		_height = 1684;
		break;
	case PDF_Creator::A1:
		_width = 1864;
		_height = 2384;
		break;
	case PDF_Creator::A0:
		_width = 2384;
		_height = 3370;
		break;
	default:
		break;
	}
}

/**
 * @brief _set_size
 * @param _width 
 * @param _height 
*/
void PDF_Creator::_set_size(int _width, int _height) {
	this->_height = _height;
	this->_width = _width;
}

/**
 * @brief _set_font_size
 * @param _size 
*/
void PDF_Creator::_set_font_size(int _size) {
	this->_font_size = _size;
}

/**
 * @brief _set_aligment
 * @param _alignment 
*/
void PDF_Creator::_set_aligment(bool _alignment) {
	this->_alignment = _alignment;
}

/**
 * @brief _save_pdf
*/
void PDF_Creator::_save_pdf() {
	char* _aux_path = "_auxiliar.txt";
	FILE* file;
	File_reader _fr;

	file = fopen(_aux_path, "wt");
	fputs(_text.c_str(), file);
	fclose(file);

	if (!_alignment) {
		int aux = _width;
		_width = _height;
		_height = aux;
	}

	ostringstream oss;
	oss << "txt2pdf.exe " << _aux_path << " " << _pdf << " -oao -pfs" << _font_size << " -pps" << 0 << " -ptc" << _color << " -width" << _width << " -height" << _height;

	system(oss.str().c_str());

	_fr._delete_all(_aux_path);
}

PDF_Creator::~PDF_Creator(){
}
