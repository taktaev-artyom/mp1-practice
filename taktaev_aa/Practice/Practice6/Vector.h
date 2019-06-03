#pragma once

#define M_PI 3.14159265358979323846
#define _CRT_SECURE_NO_WARNINGS

typedef struct 
{
    int n;//razmer
    double* mas;
}Vector;

Vector create(int n);
void deleteV(Vector x);
int addition(Vector a, Vector b, Vector* res);
int subtraction(Vector a, Vector b, Vector* res);
int scalar(Vector a, Vector b, double* res);
int angle(Vector a, Vector b, double* res);
int length(Vector x, double* res);
