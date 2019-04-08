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
	mas = new double[n];
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
	Vector* rez = new Vector(n);
	for (int i = 0; i < n; i++)
	{
		rez->mas[i] = mas[i] + x.mas[i];
	}
	return *rez;
}
Vector& Vector::operator-(const Vector& x)
{
	if (n != x.n) throw 2;
	Vector* rez = new Vector(n);
	for (int i = 0; i < n; i++)
	{
		rez->mas[i] = mas[i] - x.mas[i];
	}
	return *rez;
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
	Vector* rez = new Vector(n);
	for (int i = 0; i < n; i++)
	{
		rez->mas[i] = mas[i] + k;
	}
	return *rez;
}
Vector& Vector::operator-(double k)
{
	Vector* rez = new Vector(n);
	for (int i = 0; i < n; i++)
	{
		rez->mas[i] = mas[i] - k;
	}
	return *rez;
}
Vector& Vector::operator*(double k) 
{
	Vector* rez = new Vector(n);
	for (int i = 0; i < n; i++)
	{
		rez->mas[i] = mas[i] * k;
	}
	return *rez;
}
Vector& Vector::operator+=(const Vector& x)
{
	if (n != x.n) throw 4;
	Vector* rez = new Vector(*this);
	for (int i = 0; i < n; i++)
	{
		rez->mas[i] += x.mas[i];
	}
	return *rez;
}
Vector& Vector::operator-=(const Vector& x)
{
	if (n != x.n) throw 5;
	Vector* rez = new Vector(*this);
	for (int i = 0; i < n; i++)
	{
		rez->mas[i] -= x.mas[i];
	}
	return *rez;
}
double Vector::operator*=(const Vector& x)
{
	double rez = 0;
    rez = (*this) * x;
    return rez;
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