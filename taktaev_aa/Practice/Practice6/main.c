#include "Vector.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

void main()
{
	int num1, num2;
	int f = 0;
	Vector x, y, sum, diff;
	double scal, ang, lenX, lenY;
	printf("Enter the first vector's dimension:\n");
	scanf("%d", &num1);
	x = create(num1);
	printf("Enter the second vector's dimension:\n");
	scanf("%d", &num2);
	y = create(num2);
	sum = addition(x, y, &f);
	if (f == 1) return;
	diff = subtraction(x, y, &f);
	if (f == 1) return;
	scal = scalar(x, y, &f);
	if (f == 1) return;
	ang = angle(x, y, &f);
	if (f == 1) return;
	lenX = length(x, &f);
	lenY = length(y, &f);
	printf("A sum of vector x and vector y is ", sum,"\n");
	printf("A difference of vector x and vector y is ", diff, "\n");
	printf("A scalar product of vector x and vector y is ", scal, "\n");
	printf("An angle between vector x and vector y ", ang, "\n");
	printf("A length of vector x is ", lenX, "\n");
	printf("A length of vector y is ", lenY, "\n");
	deleteV(x);
	deleteV(y);
	deleteV(sum);
	deleteV(diff);
}