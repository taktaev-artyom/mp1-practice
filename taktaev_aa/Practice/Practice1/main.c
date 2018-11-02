#include <locale.h>
#include <math.h>
#include <stdio.h>

void main() 
{
	float h, w, d, VZad, VBok, VKrish, VDver, VPolk, Massa, pDSP, pDVP, pDer;
	setlocale(LC_ALL, "Russian");
	printf("����� ���������� � �������������� v1.0.\n ��������, ��� �� ������������ � ����������� ���������� �������� ��������� ������ �������� �����.\n");
	printf("������� ������ ����� � �\n");
	scanf("%f", &h);
	if ((h < 1.8) || (h > 2.2)) 
	{
		printf("������� �������� ������");
		return;
	}
	printf("������� ������ ����� � �\n");
	scanf("%f", &w);
	if ((w < 0.8) || (w > 1.2)) 
	{
		printf("������� �������� ������");
		return;
	}
	printf("������� ������� ����� � �\n");
	scanf("%f", &d);
	if ((d < 0.5) || (d > 0.9)) 
	{
		printf("������� �������� �������");
		return;
	}
	printf("������� ��������� ���, ��� � ������ �� ������� ����� ������(� ��/�^3)\n");
	scanf("%f %f %f", &pDSP, &pDVP, &pDer);
	if ((pDSP <= 0) || (pDVP <= 0) || (pDer <= 0)) 
	{
		printf("���� �� ��������� �������� ��������� �������. ��������� ���� ������");
		return;
	}
	VZad = w * h * 0.005;
	VBok = 2.0 * h * d * 0.015;
	VKrish = 2.0f * w * d * 0.015;
	VDver = w * h * 1.0;
	VPolk = floor((h - 2 * 0.015) / (0.4 + 0.015)) * (w - 2 * 0.015) * (d - 0.005);
	Massa = VZad * pDVP + VBok * pDSP + VKrish * pDSP + VDver * pDer + VPolk * pDSP;
	printf("����� ������ ����� ����� %.2f ��\n", Massa);
	
}