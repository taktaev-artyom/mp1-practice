#include "VectorSTR.h"
Vector::Vector()
{
	n = 0;
	mas = nullptr;
}
Vector::Vector(int _n)
{
	n = _n;
	mas = new double[n];
}
Vector::Vector(const Vector& x)
{
	n = x.n;
	for (int i = 0; i < n; i++)
	{
		mas[i] = x.mas[i];
	}
}
Vector::~Vector()
{
	delete[]mas;
}
Vector& Vector::operator+(const Vector& x)
{
	if (n != x.n) throw 1;
	for (int i = 0; i < n; i++)
	{
		mas[i] = mas[i] + x.mas[i];
	}
	return *this;
}
Vector& Vector::operator-(const Vector& x)
{
	if (n != x.n) throw 2;
	for (int i = 0; i < n; i++)
	{
		mas[i] = mas[i] - x.mas[i];
	}
	return *this;
}
double Vector::operator*(const Vector& x)
{
	if (n != x.n) throw 3;
	double rez = 0;
	for (int i = 0; i < n; i++)
	{
		rez += mas[i] * x.mas[i];
	}
	return rez;

}
Vector& Vector::operator+(double k)
{
	for (int i = 0; i < n; i++)
	{
		mas[i] = mas[i] + k;
	}
	return *this;
}
Vector& Vector::operator-(double k)
{
	for (int i = 0; i < n; i++)
	{
		mas[i] = mas[i] - k;
	}
	return *this;
}
Vector& Vector::operator*(double k) 
{
	for (int i = 0; i < n; i++)
	{
		mas[i] = mas[i] * k;
	}
	return *this;
}
Vector& Vector::operator+=(const Vector& x)
{
	if (n != x.n) throw 4;
	for (int i = 0; i < n; i++)
	{
		mas[i] += x.mas[i];
	}
	return *this;
}
Vector& Vector::operator-=(const Vector& x)
{
	if (n != x.n) throw 5;
	for (int i = 0; i < n; i++)
	{
		mas[i] -= x.mas[i];
	}
	return *this;
}
Vector& Vector::operator*=(const Vector& x)
{
	if (n != x.n) throw 6;
	for (int i = 0; i < n; i++)
	{
		mas[i] *= x.mas[i];
	}
	return *this;
}
const Vector& Vector::operator=(const Vector& x)
{
	n = x.n;
	mas = new double[n];
	for (int i = 0; i < n; i++)
	{
		mas[i] = x.mas[i];
	}
	return *this;
}
double& Vector::operator[](int i)
{
	if (!mas) throw 7;
	return mas[i];
}
double Vector::Vector_Len()
{
	return sqrt((*this) * (*this));
}
void Vector::Output()
{
    for (int i = 0; i < n; i++)
        std::cout << mas[i] << " ";
	std::cout << std::endl;
}