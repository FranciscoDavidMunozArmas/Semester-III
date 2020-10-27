/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 28 de mayo de 2020 10:07:14
 * @function Declaration of Array
*/

#if !defined(__Array_h)
#define __Array_h

using namespace std;

template<class T, int _size>
void set_cero(T (&r)[_size]);
template<class T, int _size>
void input(char* _input_phrase, T (&r)[_size]);
template<class T, int _size>
void process(T (&r)[_size], int number);
template<class T, int _size>
void print_array(T (&r)[_size]);
template<class T, int N>
int _size(T(&r)[N]);

#endif
