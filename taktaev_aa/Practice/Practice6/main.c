#include "Vector.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

void main()
{
	int num;
	Vector x;
	printf("Enter the vector's dimension:\n");
	scanf("%d", &num);
	x = create(num);
}