#pragma once
#include <iostream>
class monom
{
public:
	double koeff;
	int degree;
	monom* next;
	monom();
	monom(double, int);
	~monom();
};
class polynom
{
	monom* head;
public:
	polynom();
	~polynom();
	monom* Search(int);
	void Add(double, int);
	void Delete(monom*);
	void DeleteAll();
	polynom& Input();
	void Output();
	polynom& operator+(double);
	polynom& operator+(const polynom&);
	polynom& operator*(double);
	polynom& operator*(const polynom&);
	polynom& operator/(const monom&);
	polynom& operator/(double);
	polynom& operator/(const polynom&);
};