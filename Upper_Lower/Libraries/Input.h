/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 28 de mayo de 2020 10:07:14
 * @function Declaration of Input
*/

#if !defined(__Input_Input_h)
#define __Input_Input_h

#include <iostream>

class Input {
public:
	enum Case
	{
		UPPER_CASE,
		LOWER_CASE
	};

	std::string input(std::string input_phrase);
	std::string input_number(std::string input_phrase);
	std::string input_int_number(std::string input_phrase);
	std::string input_only_numbers(std::string input_phrase);
	std::string input_only_int(std::string input_phrase);
	std::string input_only_letters(std::string input_phrase);
	std::string input_only_letters(std::string input_phrase, Case _case);
private:
	std::string _delete(std::string string_for_delete);
};

#endif