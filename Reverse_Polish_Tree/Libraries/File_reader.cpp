/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 28 de mayo de 2020 10:07:14
 * @function Implementation of File_reader
*/

#include "File_reader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include <malloc.h>
#include <sstream>

#include "Array_dinamic.h"
#include "InstanceOf.cpp"
#include "Date.cpp"

#pragma once

using namespace std;

/**
 * @brief _check_file
 * @param file
 * @param file_name
*/
void File_reader::_check_file(FILE* file, char* file_name)
{
	try {
		if ((file = fopen(file_name, "rb")) == NULL) {
			throw file_name;
		}
	}
	catch (char* file_name) {
		fclose(file);
		//cout << "Error: No se puede abrir el archivo: " << file_name << endl;
		file = fopen(file_name, "wb");
		//cout << "Archivo creado" << endl;
	}
	fclose(file);
}

/**
 * @brief _write_in_file
 * @tparam T
 * @param file
 * @param file_name
 * @param data
*/
template<typename T>
void File_reader::_write_in_file(FILE* file, char* file_name, T* data)
{
	_check_file(file, file_name);
	file = fopen(file_name, "ab");
	fwrite(data, sizeof(T), 1, file);
	fclose(file);
}

/**
 * @brief _read_file
 * @tparam T
 * @param file
 * @param file_name
 * @param data
 * @return T
*/
template<typename T>
T* File_reader::_read_file(FILE* file, char* file_name, T* data)
{
	int index;
	_check_file(file, file_name);
	file = fopen(file_name, "rb");

	fseek(file, 0, SEEK_END);
	index = ftell(file) / sizeof(T);

	data = (T*)malloc(index*sizeof(T));

	fseek(file, 0, SEEK_SET);
	for (int i = 0; i < index; i++) {
		fread((data + i), sizeof(T), 1, file);
	}

	fclose(file);

	return data;
}

/**
 * @brief _look_by_key
 * @tparam T
 * @param file
 * @param file_name
 * @param key
 * @param data
*/
template<typename T>
void File_reader::_look_by_key(FILE* file, char* file_name, string key, T* data) {}

/**
 * @brief _delete
 * @tparam T
 * @param file
 * @param file_name
 * @param _element
*/
template<typename T>
void File_reader::_delete(FILE* file, char* file_name, T& _element)
{
	Array_dynamic _ad;
	T* _auxiliar_array;
	_auxiliar_array = _read_file(file,file_name, _auxiliar_array);

	_delete_all(file_name);

	for (int i = 0; i < _ad._dynamic_size(_auxiliar_array); i++) {
		if (!((_element) == *(_auxiliar_array + i))) {
			_write_in_file(file, file_name, (_auxiliar_array + i));
		}
	}

	free(_auxiliar_array);
}

/**
 * @brief _update
 * @tparam T
 * @param file
 * @param file_name
 * @param _data_update
*/
template<typename T>
void File_reader::_update(FILE* file, char* file_name, T* _data_update) {
	Array_dynamic _ad;
	T* _auxiliar_array;
	_auxiliar_array = _read_file(file, file_name, _auxiliar_array);

	_delete_all(file_name);

	for (int i = 0; i < _ad._dynamic_size(_auxiliar_array); i++) {
		if (*(_data_update) == *(_auxiliar_array + i)) {
			_write_in_file(file, file_name, _data_update);
		} else {
			_write_in_file(file, file_name, (_auxiliar_array + i));
		}
	}

	free(_auxiliar_array);
}

/**
 * @brief _back_up
 * @param _origin_path
*/
void File_reader::_back_up(char* _origin_path) {
	Date _date;
	FILE* file;

	ostringstream _path;
	ostringstream oss;
	ostringstream _file;

	_file << _date.create_key() << "_back_up.txt";
	_path << "..\\BackUp\\" << _file.str();

	oss << "copy " << _origin_path << " " << _path.str();

	file = fopen("../back_up.txt", "at");
	fputs(_file.str().c_str(), file);
	fputs("\n", file);
	fclose(file);

	_check_file(file, _origin_path);
	system("cls");
	system(oss.str().c_str());

	system("pause");
}

/**
 * @brief _write_txt_file
 * @param file_name
 * @param data
*/
template<typename T>
void File_reader::_write_txt_file(const char* file_name, T* data) {
	FILE* file;
	Array_dynamic _ad;
	ostringstream oss;
	for (int i = 0; i < _ad._dynamic_size(data); i++) {
		oss << *(data + i);
	}

	file = fopen(file_name, "at");
	fputs(oss.str().c_str(), file);
	fclose(file);
}

void File_reader::_add_line(char* file_name) {
	FILE* file;
	file = fopen(file_name, "at");
	fputs("\n", file);
	fclose(file);
}

/**
 * @brief _read_txt_file
 * @param file_name
 * @param data
 * @return
*/
char** File_reader::_read_txt_file(char* file_name, char** data) {
	ifstream _in;
	Array_dynamic _ad;
	string _aux;

	_in.open(file_name, ios::in);

	int _index = 0;

	try {
		if (_in.fail()) {
			throw file_name;
		}

		data = (char**)malloc((1 + _index) * sizeof(char*));

		while (!_in.eof()) {
			getline(_in, _aux);
			data = _ad._resize(data, (_index + 1));
			*(data + _index) = (char*)malloc(_aux.size() * sizeof(char));
			strcpy(*(data + _index), _aux.c_str());
			_index++;
		}
	}
	catch (char* file_name) {
		system("cls");
		cout << endl << "ERROR: NO SE PUEDE LEER EL ARCHIVO '" << file_name << "'"<< endl;
		system("pause");
	}

	_in.close();

	return data;
}

/**
 * @brief _restore_data
 * @param _original_path
 * @param _backup_file_path
*/
void File_reader::_restore_data(char* _original_path, char* _backup_file_path) {
	Date _date;
	FILE* file;

	ostringstream oss;

	oss << "copy ..\\BackUp\\" << _backup_file_path << " " << _original_path;

	_check_file(file, _backup_file_path);
	system("cls");
	system(oss.str().c_str());


	cout << endl << "RESTAURADO: " << _original_path << endl;
	system("pause");
}

/**
 * @brief _delete_all
 * @param file_name
*/
void File_reader::_delete_all(char* file_name) {
	remove(file_name);
}
