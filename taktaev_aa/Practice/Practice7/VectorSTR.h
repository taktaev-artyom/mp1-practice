#pragma once
struct Vector
{
	double* mas;
	int n;
	Vector();
	Vector(int n);
	Vector(const Vector& x);
	~Vector();
	Vector& operator+(const Vector& x);
	Vector& operator-(const Vector& x);
	double operator*(const Vector& x);
	Vector& operator+(int k);
	Vector& operator-(int k);
	Vector& operator*(int k);
	Vector& operator+=(const Vector& x);
	Vector& operator-=(const Vector& x);
	Vector& operator*=(int k);
	const Vector& operator=(const Vector& x);
};
double Vector_Len(Vector& x);