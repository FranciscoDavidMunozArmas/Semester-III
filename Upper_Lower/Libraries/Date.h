/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 28 de mayo de 2020 10:07:14
 * @function Declaration of Date
*/

#if !defined(__Date_h)
#define __Date_h

#include <iostream>

using namespace std;

class Date
{
public:

	Date();
	int get_year(void);
	int get_day(void);
	int get_month(void);
	int get_hour(void);
	int get_minute(void);
	int get_second(void);

	void set_year(int _year);
	void set_day(int _day);
	void set_month(int _month);
	void set_hour(int _day);
	void set_minute(int _minute);
	void set_second(int _second);
	string create_key();
	string to_string();
	~Date();

protected:
private:
	int _year;
	int _month;
	int _day;
	int _hour;
	int _minute;
	int _second;
};
#endif
