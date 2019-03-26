#include "Vector.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

Vector create(int n)
{
	Vector x;
	int i;
	x.n = n;
	x.mas = (double*)malloc(x.n * sizeof(double));
	printf("Please enter values of vector's components:\n");
	for (i = 0; i < x.n; i++)
	{
		scanf("%lf", &x.mas[i]);
	}
	return x;
}
void deleteV(Vector x)
{
	x.n = 0;
	free(x.mas);
}
Vector addition(Vector a, Vector b)
{
	Vector rez = create(a.n);
	Vector error = create(0);
	int i;
	if (a.n != b.n)
	{
		printf("Vectors' dimensions are not equal!\n");
		return error;
	}
	for (i = 0; i < a.n; i++)
	{
		rez.mas[i] = a.mas[i] + b.mas[i];
	}
	return rez;
}
Vector subtraction(Vector a, Vector b)
{
	Vector rez = create(a.n);
	Vector error = create(0);
	int i;
	if (a.n != b.n)
	{
		printf("Vectors' dimensions are not equal!\n");
		return error;
	}
	for (i = 0; i < a.n; i++)
	{
		rez.mas[i] = a.mas[i] - b.mas[i];
	}
	return rez;
}
double scalar(Vector a, Vector b)
{
	double rez = 0;
	int i;
	if (a.n != b.n)
	{
		printf("Vectors' dimensions are not equal!\n");
		return -0.5723807128034712;
	}
	for (i = 0; i < a.n; i++)
	{
		rez += a.mas[i] * b.mas[i];
	}
	return rez;
}
double angle(Vector a, Vector b)
{
	double cos;
	if ((length(a) == 0) || (length(b) == 0))
	{
		printf("ERROR/n");
	}
	cos = scalar(a, b) / (length(a) * length(b));
	return acos(cos * 180 / M_PI);
}
double length(Vector x)
{
	double rez = 0;
	return sqrt(scalar(x, x));
}
