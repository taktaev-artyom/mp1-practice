 #include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <locale.h> 
#define N 10 
void main ()
{ 
	int chisloC[N]; 
	int baserng[N]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int chislo4[N]; 
	int i, j, cifri=0, korovi = 0, biki = 0, x, y, proverka = 0, pr = 0, f=0; 
	setlocale(LC_ALL, "Russian"); 
	srand((unsigned int)time(0)); 
	printf("���� '���� � ������'. �������:\n 1. �� ��������� ���������� ������ �����, ������� ����� ����������� � ����.\n 2.��������� ���������� ��� ����� ��� ������������� ����.\n 3.����� �� ��������� ������� ���, �� ��� ��������� ���������� �����(���������� ��������� ����, �� �� �������� ��������) � ���������� �����(��������� ���� �� ������ �������).\n");
	do
	{
		printf("	������� ���������� ���� � �����:\n");
		scanf("%d", &cifri);
	} while((cifri < 1) || (cifri > 10)); 
	printf("	��������� %d-������� �����...\n", cifri); 
	i = 0;
	while (i < cifri) 
	{ 
		if (i == 0) x = 1 + rand() % 9; //������ ����� ! = 0
		else x = rand() % 10; 
		if (baserng[x] != -1) //��������� � ������� ������ �� ���� -1, ����� ��� ����� �������������� � ��������� �����
		{ 
			chisloC[i] = x; 
			baserng[x] = -1;
			i++; 
		} 
	} 
	//for (i = 0 ; i < cifri; i++) printf("%d", chisloC[i]); //��������
	do 
	{  
		printf("������� %d-������� ����� ��� ������������� ����:\n", cifri); 
		scanf("%d", &y); 
		proverka = 0; 
		korovi = 0;
		biki = 0;
		pr = y; //����� �� ������� ���������� �
		while (pr > 0)
		{
			pr = pr / 10;
			proverka++;
		}
		if (proverka != cifri)
		{
			printf("� ��������� ����� ������ ���� %d ������(�)!\n", cifri);
			continue;
		}
		pr = y;
		for (i = cifri-1; i >=0; i--) //�������� ������� ��������� � ������ ��� �������� (�������� % � /)
		{ 
			chislo4[i] = pr % 10; 
			pr = pr / 10;
		}
		f = 0;
		for (i = 0; i < cifri; i++) 
		{
			for (j = (i+1); j < cifri; j++)
			if (chislo4[i] == chislo4[j]) 
			{
				printf("����� ������ ���� ��� ��������!\n");
				f = 1;
			}
		}
		if (f == 1) continue;//����� ������������ ��� ��������� ����������� ��������� �����
		for (i = 0; i < cifri; i++) 
		{ 
			for (j = 0; j < cifri; j++) 
			{ 
				if ((chisloC[i] == chislo4[j]) && (i == j)) biki++; 
				if ((chisloC[i] == chislo4[j]) && (i != j)) korovi++;
			} 
		} 
		printf("���������� ����� - %d;\nK��������� ����� - %d.\n", korovi, biki); 
	} while (biki != cifri); 
	printf("����������! �� ��������!\n"); 
}