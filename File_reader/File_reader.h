/***********************************************************************
 * Module:  File_reader.h
 * Author:  USUARIO
 * Modified: sábado, 6 de junio de 2020 15:26:07
 * Purpose: Declaration of the class File_reader
 ***********************************************************************/

#if !defined(__File_Reader_File_reader_h)
#define __File_Reader_File_reader_h

#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

class File_reader
{
public:
   void _check_file(FILE *file, char* file_name);
   template<typename T>
   void _write_in_file(FILE* file, char* file_name, T* data);
   template<typename T>
   void _read_file(FILE* file, char* file_name, T* data);
   template<typename T>
   void _look_by_key(FILE* file, char* file_name, string key, T* data);
   template<typename T>
   void _delete(FILE* file, char* file_name, string key);
   template<typename T>
   void _update(FILE* file, char* file_name, string key, T data);

   void _delete_all(char* file_name);
protected:
private:

};

#endif
