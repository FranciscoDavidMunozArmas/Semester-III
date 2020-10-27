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

using namespace std;

////////////////////////////////////////////////////////////////////////
// Name:       File_reader::_check_file()
// Purpose:    Implementation of File_reader::_check_file()
// Return:     void
////////////////////////////////////////////////////////////////////////

void File_reader::_check_file(FILE* file, char* file_name)
{
	try {
		if ((file = fopen(file_name, "rb")) == NULL) {
			throw file_name;
		}
	}
	catch (char* file_name) {
		fclose(file);
		cout << "Error: No se puede abrir el archivo: " << file_name << endl;
		file = fopen(file_name, "wb");
		cout << "Archivo creado" << endl;
	}
	fclose(file);
}

////////////////////////////////////////////////////////////////////////
// Name:       File_reader::_write_in_file()
// Purpose:    Implementation of File_reader::_write_in_file()
// Return:     void
////////////////////////////////////////////////////////////////////////

template<typename T>
void File_reader::_write_in_file(FILE* file, char* file_name, T* data)
{
	_check_file(file, file_name);
	file = fopen(file_name, "ab");
	fwrite(data, sizeof(T), 1, file);
	fclose(file);
}

////////////////////////////////////////////////////////////////////////
// Name:       File_reader::_read_file()
// Purpose:    Implementation of File_reader::_read_file()
// Return:     void
////////////////////////////////////////////////////////////////////////

template<typename T>
void File_reader::_read_file(FILE* file, char* file_name, T* data)
{
	T item;
	int index;
	_check_file(file, file_name);
	file = fopen(file_name, "rb");

	fseek(file, 0, SEEK_END);
	index = ftell(file) / sizeof(T);;
	cout << index << endl;

	//*data = (T*)malloc(index*sizeof(T));

	fseek(file, 0, SEEK_SET);
	/*for (int i = 0; i < index; i++) {
		fread(&item, sizeof(T), 1, file);
		*(data + i) = item;
	}*/
	fread(data, sizeof(T), 1, file);

	fclose(file);
}

template<typename T>
void File_reader::_look_by_key(FILE* file, char* file_name, string key, T* data)
{
}

template<typename T>
void File_reader::_delete(FILE* file, char* file_name, string key)
{
}

template<typename T>
void File_reader::_update(FILE* file, char* file_name, T* _data_array, T data) {

}

void File_reader::_delete_all(char* file_name) {
	remove(file_name);
}
