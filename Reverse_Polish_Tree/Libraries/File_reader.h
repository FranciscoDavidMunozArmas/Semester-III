/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 28 de mayo de 2020 10:07:14
 * @function Declaration of File_reader
*/

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
   T* _read_file(FILE* file, char* file_name, T* data);
   template<typename T>
   void _look_by_key(FILE* file, char* file_name, string key, T* data);
   template<typename T>
   void _delete(FILE* file, char* file_name, T& key);
   template<typename T>
   void _update(FILE* file, char* file_name, T* _data_update);

   template<typename T>
   void _write_txt_file(const char* file_name, T* data);
   void _add_line(char* file_name);
   char** _read_txt_file(char* file_name, char** data);

   void _back_up(char* _orign_path);
   void _restore_data(char* _original_path, char* _backup_file_path);

   void _delete_all(char* file_name);
protected:
private:

};

#endif
