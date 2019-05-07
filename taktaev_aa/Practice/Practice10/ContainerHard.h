#pragma once
#include <iostream>

using namespace std;

class Container<T*, maxsize>
{
	T** arr;
	int realsize;
public:
	Container();
	Container(const Container& a);
	~Container();
	bool IsFull() const;
	bool IsEmpty() const;
	int Find(T a) const;
	void Add(T a);
	void Delete(T a);
	void print();
};
