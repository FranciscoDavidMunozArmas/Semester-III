/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 28 de mayo de 2020 10:07:14
 * @function Implementation of Date
*/

#include "Date.h"
#include <ctime>
#include <vector>
#include <sstream>

#pragma once

using namespace std;

/**
 * @brief Date
 * @return
*/
Date::Date()
{
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);

	this->_year = timePtr->tm_year + 1900;
	this->_month = timePtr->tm_mon + 1;
	this->_day = timePtr->tm_mday;
	this->_hour = timePtr->tm_hour;
	this->_minute = timePtr->tm_min;
	this->_second = timePtr->tm_sec;
}

/**
 * @brief get_year
 * @return int
*/
int Date::get_year()
{
	return _year;
}

/**
 * @brief set_year
 * @param _year
*/
void Date::set_year(int _year)
{
	this->_year = _year;
}

/**
 * @brief get_day
 * @return int
*/
int Date::get_day()
{
	return _day;
}

/**
 * @brief set_day
 * @param _day
*/
void Date::set_day(int _day)
{
	this->_day = _day;
}

/**
 * @brief get_month
 * @return int
*/
int Date::get_month()
{
	return _month;
}

/**
 * @brief set_month
 * @param _month
*/
void Date::set_month(int _month)
{
	this->_month = _month;
}

/**
 * @brief get_hour
 * @return int
*/
int Date::get_hour()
{
	return _hour;
}

/**
 * @brief set_hour
 * @param _hour
*/
void Date::set_hour(int _hour)
{
	this->_hour = _hour;
}

/**
 * @brief get_minute
 * @return int
*/
int Date::get_minute()
{
	return _minute;
}

/**
 * @brief set_minute
 * @param _minute
*/
void Date::set_minute(int _minute)
{
	this->_minute = _minute;
}

/**
 * @brief get_second
 * @return int
*/
int Date::get_second()
{
	return _second;
}

/**
 * @brief set_second
 * @param _second
*/
void Date::set_second(int _second)
{
	this->_second = _second;
}

/**
 * @brief to_string
 * @return string
*/
string Date::to_string(void)
{
	ostringstream oss;
	oss <<_day << "/" << _month << "/" << _year << "\t\t" << _hour << ":" << _minute << ":" << _second;
	return oss.str();
}

/**
 * @brief create_key
 * @return 
*/
string Date::create_key() {
	ostringstream oss;
	oss << _year;

	if (_month < 10) {
		oss << 0 << _month;
	}
	else {
		oss << _month;
	}

	if (_day < 10) {
		oss << 0 << _day;
	}
	else {
		oss << _day;
	}

	if (_hour < 10) {
		oss << 0 << _hour;
	}
	else {
		oss << _hour;
	}

	if (_minute < 10) {
		oss << 0 << _minute;
	}
	else {
		oss << _minute;
	}

	if (_second < 10) {
		oss << 0 << _second;
	}
	else {
		oss << _second;
	}

	return oss.str();
}

/**
 * @brief ~Date
 * @return
*/
Date::~Date(){}
