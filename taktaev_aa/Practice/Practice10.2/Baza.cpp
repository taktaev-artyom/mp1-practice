#include "Baza.h"
#include <iostream>
#include <string>

using namespace std;

Date::Date(unsigned _day, unsigned _mon, unsigned _year)
{
	if (_day > 31)
	{
		throw "Day error";
	}
	if (_mon > 12)
	{
		throw "Month error";
	}
	if ((_year % 400 == 0) || ((_year % 100 != 0) && (_year % 4 == 0)))
	{
		if ((_mon == 2) && (_day > 29))
			throw "February error (leap year)";
	}
	else
	{
		if ((_mon == 2) && (_day > 28))
			throw "February error (non-leap year)";
	}
	if ((_mon == 4) || (_mon == 6) || (_mon == 9) || (_mon == 11))
	{
		if (_day >= 31)
			throw "Day error (there is 30 days in this month)";
	}
	day = _day;
	mon = _mon;
	year = _year;
}

Date::Date(const Date& _Date)
{
	day = _Date.day;
	mon = _Date.mon;
	year = _Date.year;
}

const Date& Date::operator=(const Date & _Date)
{
	day = _Date.day;
	mon = _Date.mon;
	year = _Date.year;
	return *this;
}

bool Date::operator==(const Date& _Date)
{
	if ((day == _Date.day) && (mon == _Date.mon) && (year == _Date.year))
		return true;
	return false;
}

std::ostream & operator<<(std::ostream & x, const Date & _Date)
{
	if (_Date.day < 10)
		x << "0" << _Date.day << ".";
	else
		x << _Date.day << ".";
	if (_Date.mon < 10)
		x << "0" << _Date.mon << ".";
	else
		x << _Date.mon << ".";
	x << _Date.year;
	return x;
}

/////////////////////////////////////////////////////////////////////////


