#pragma once
#include <iostream>
#include <string>

using namespace std;

class Employee
{
	Passport passport;
	Education education;
	EmployeeParameters parameters;
public:
	
};

/////////////////////////////////////////////////////////////////////////

class Passport
{
	Name name;
	unsigned series;
	unsigned id;
	string issued_by;
	Date issued_in;
	Date date_of_birth;
	Address place_of_registration;
public:
	
};

/////////////////////////////////////////////////////////////////////////

class Name
{
	string name;
	string surname;
	string patronymic;
public:

};

/////////////////////////////////////////////////////////////////////////

class Date
{
	unsigned day;
	unsigned mon;
	unsigned year;
public:
	Date(unsigned, unsigned, unsigned);
	Date(const Date&);
	const Date& operator=(const Date&);
	Date operator-(const Date&);
	bool operator>(const Date&);
	bool operator==(const Date&);
	friend std::ostream& operator<<(std::ostream&, const Date&);
};

/////////////////////////////////////////////////////////////////////////

class Address
{
	string country;
	string subject;
	string locality;
	string street;
	char house_number;
	char flat_number;
public:
};

/////////////////////////////////////////////////////////////////////////

class Education
{
	string institute;
	Date date_of_receiving;
	Name graduate_name;
	string type_of_education;
	string specialty;
public:

};

/////////////////////////////////////////////////////////////////////////

class EmployeeParameters
{
	string subdivision;
	string position;
	double salary;
	Date date_of_employment;
	Date date_of_last_appointment;
public:

};