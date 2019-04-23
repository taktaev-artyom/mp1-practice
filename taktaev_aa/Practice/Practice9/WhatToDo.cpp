#include "WhatToDo.h"

Time::Time()
{
	hour = 0;
	min = 0;
}

Time::Time(unsigned int _hour, unsigned int _min)
{
	if ((_hour >= 24) || (_hour < 0))
	{
		throw "Hour error";
	}
	if ((_min > 59) || (_min < 0))
	{
		throw "Minute error";
	}
	hour = _hour;
	min = _min;
}

Time::Time(const Time & _Time)
{
	hour = _Time.hour;
	min = _Time.min;
}

const Time & Time::operator=(const Time & _Time)
{
	hour = _Time.hour;
	min = _Time.min;
}

std::ostream & operator<<(std::ostream & x, const Time & _Time)
{
	if (_Time.hour < 10)
		x << "0" << _Time.hour << ":";
	else
		x << _Time.hour << ":";
	if (_Time.min < 10)
		x << "0" << _Time.min;
	else
		x << _Time.min;
	return x;
}

/////////////////////////////////////////////////////////////////////////

Date::Date()
{
	day = 0;
	mon = 0;
	year = 0;
}

Date::Date(unsigned int _day, unsigned int _mon, unsigned int _year)
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
			throw "February error";
	}
	else
	{
		if ((_mon == 2) && (_day > 28))
			throw "February error (leap year)";
	}
	if ((_mon == 4) || (_mon == 6) || (_mon == 9) || (_mon == 11))
	{
		if (_day >= 31)
			throw "Invalid date - month";
	}
	day = _day;
	mon = _mon;
	year = _year;
}

Date::Date(const Date & _Date)
{
	day = _Date.day;
	mon = _Date.mon;
	year = _Date.year;
}

unsigned int Date::getDate_day()
{
	return day;
}

unsigned int Date::getDate_mon()
{
	return mon;
}

unsigned int Date::getDate_year()
{
	return year;
}

Date Date::putDate_day(unsigned int _day)
{
	if (((year % 400) == 0) || ((year % 100 != 0) && (year % 4 == 0)))
	{
		if ((mon == 2) && (_day > 29))
			throw "February error";
	}
	if (_day > 31)
	{
		throw "Day error (must be <= 31)";
	}
	else if ((mon == 4) || (mon == 6) || (mon == 9) || (mon == 11))
	{
		if (_day >= 31)
			throw "Day error (look at month number)";
	}
	day = _day;
	return *this;
}

Date Date::putDate_mon(unsigned int _mon)
{
	if (_mon > 12)
	{
		throw "Month error";
	}
	mon = _mon;
	return *this;
}

Date Date::putDate_year(unsigned int _year)
{
	year = _year;
	return *this;
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

Task::Task()
{
	id = 0;
}

Task::~Task()
{
	id = 0;
	task = nullptr;
}

Time Task::set_start(Time x)
{
	return Time();
}

Time Task::set_end(Time x)
{
	return Time();
}
 
/////////////////////////////////////////////////////////////////////////

Type1::Type1()
{
	id = 1;
	task = nullptr;
}

Type1::~Type1()
{
	id = 1;
	task = nullptr;
}

Time Type1::get_start()
{
	return Time();
}

Time Type1::get_end()
{
	return Time();
}

void Type1::print()
{
	std::cout << " " << task << " " << date << std::endl;
}

Type2::Type2()
{
	id = 2;
}

Type2::~Type2()
{
	id = 2;
	task = nullptr;
}

Time Type2::get_start()
{
	return time_1;
}

Time Type2::set_start(Time x)
{
	time_1 = x;
	return x;
}

Time Type2::set_end(Time x)
{
	time_2 = x;
	return x;
}

Time Type2::get_end()
{
	return time_2;
}

void Type2::print()
{
	std::cout << " " << task << " " << date << " start:" << time_1 << " end:" << time_2 << std::endl;
}