#pragma once
#include <iostream>

using namespace std;

template <typename T, int maxsize>
class Container
{
	T* arr;
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

template<typename T, int maxsize>
Container<T, maxsize>::Container()
{
	realsize = 0;
	arr = new T[maxsize];
}

template<typename T, int maxsize>
Container<T, maxsize>::Container(const Container<T, maxsize>& a)
{
	arr = new T[maxsize];
	realsize = a.realsize;
	for (int i = 0; i < realsize; i++)
		arr[i] = a.arr[i];
}

template<typename T, int maxsize>
Container<T, maxsize>::~Container()
{
	delete[] arr;
}

template<typename T, int maxsize>
bool Container<T, maxsize>::IsFull() const
{
	return (realsize == maxsize);
}

template<typename T, int maxsize>
bool Container<T, maxsize>::IsEmpty() const
{
	return (realsize == 0);
}

template<typename T, int maxsize>
int Container<T, maxsize>::Find(T a) const
{
	if (IsEmpty()) throw "Container is empty(nothing to find)";
	for (int i = 0; i < realsize; i++)
		if (arr[i] == a) return i;
	throw "There is no such element";
}

template<typename T, int maxsize>
void Container<T, maxsize>::Add(T a)
{
	if (IsFull()) throw "Container is full(cannot add an element)";
	arr[realsize++] = a;
}

template<typename T, int maxsize>
void Container<T, maxsize>::Delete(T a)
{
	if (IsEmpty()) throw "Container is empty(nothing to delete)";
	arr[Find(a)] = arr[realsize-1];
	realsize--;
}

template<typename T, int maxsize>
void Container<T, maxsize>::print()
{
	if (IsEmpty()) throw "Container is empty(nothing to print)";
	for (int i = 0; i < realsize; i++)
		cout << "Element[" << i << "] = " << arr[i] << endl;
}

///////////////////////////////////////////////////////////////////////////////

template <typename T, int maxsize>
class Container<T*, maxsize>
{
	T* arr;
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

template<typename T, int maxsize>
Container<T*, maxsize>::Container()
{
	realsize = 0;
	arr = new T[maxsize];
}

template<typename T, int maxsize>
Container<T*, maxsize>::Container(const Container<T*, maxsize>& a)
{
	arr = new T*[maxsize];
	realsize = a.realsize;
	for (int i = 0; i < realsize; i++)
		arr[i] = new T(*(a.arr[i]));
}

template<typename T, int maxsize>
Container<T*, maxsize>::~Container()
{
	delete[] arr;
}