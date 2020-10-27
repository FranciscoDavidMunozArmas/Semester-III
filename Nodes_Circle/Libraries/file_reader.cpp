/***********************************************************************
 * Module:  File_reader.cpp
 * Author:  USUARIO
 * Modified: sábado, 6 de junio de 2020 15:26:07
 * Purpose: Implementation of the class File_reader
 ***********************************************************************/

#include "File_reader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <malloc.h>

#include "Array_dinamic.h"
#include "InstanceOf.cpp"

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

template<typename T>
void File_reader::_back_up(char* _origin_path, T* _data) {
	char* _backup_path = "../_back_up.txt";

	FILE* _original;
	FILE* _backup;
	T* _aux_backup;
	Array_dynamic _ad;

	_check_file(_original, _origin_path);
	_check_file(_backup, _backup_path);

	_aux_backup = _read_file(_original, _origin_path, _aux_backup);

	for (int i = 0; i < _ad._dynamic_size(_aux_backup); i++) {
		_write_in_file(_backup, _backup_path, *(_aux_backup + i));
	}
}

/**
 * @brief _delete_all
 * @param file_name 
*/
void File_reader::_delete_all(char* file_name) {
	remove(file_name);
}
