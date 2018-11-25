#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define dlina 30
#define kolvotovarov 10

char nazvanie[kolvotovarov + 1][dlina] = {"", "����������� Nikon","�������� Xiaomi",
    "��������� Samsung","������� ��������� PlayStation","�������� HyperX",
    "����������� ������� JBL","������� ASUS","���������� ������ Siemens",
    "������� Canon","����������� Toshiba"};
int discount[kolvotovarov + 1];
int f = 0;
int kolichestvo[kolvotovarov + 1];

void skidki(int min_skidka, int max_skidka)
{
    int i;
    srand((unsigned int) time(0));
    discount[0] = 0;
    for (i = 1; i < kolvotovarov + 1; i++)
    {
        discount[i] = min_skidka + rand() % (max_skidka - min_skidka);
    }
}

void menu()
{
    printf("������ ������.\n");
    printf("������� 1, ����� ����������� �����.\n");
    printf("������� 2, ����� ������� ���������� � ������.\n");
    printf("������� 3, ����� �������� ���� ����� � ���.\n");
    printf("������� 4, ����� ������� ���.\n");
    printf("������� 5, ����� ���������� ����� ��������� �������.\n");
    printf("������� 0, ����� ����� �� ���������.\n");
}

void vivodimeni(int id)
{
    int i;
    if ((id != 1) && (id != 2) && (id != 3) && (id != 4) && (id != 5) &&
        (id != 6) && (id != 7) && (id != 8) && (id != 9) && (id != 10)) 
           printf("������ � ����� �����-����� �� ����������.\n");
    else
        {
            for (i = 0; i < dlina; i++) printf("%c", nazvanie[id][i]);
            printf("\n");
            f = 1;
        }
}



void main()
{
    int id = 0, punkt, i = 0;
    long itogo = 0;
    long prices[kolvotovarov + 1] = {-1, 34600, 25300,
    56700, 21400, 8100,
    9500, 54900, 46800,
    14700, 29900};
    skidki(1, 50);
    setlocale(LC_ALL, "Russian");
    menu();
    do
    {
        printf("�������� �����.\n");
	    scanf("%d", &punkt);
        switch(punkt)
        {
        case 1: 
                printf("������� �����-���.\n"); 
                scanf("%d", &id);
                break;
        case 2: 
                if (id == 0) printf("��� ������ ������������� �����.\n");
                else
                {
                    vivodimeni(id);
                    if (f == 1)
                    {
                        printf("���� �� ������� ������ ��� ������ - %d.\n", prices[id]);
                        printf("������ �� ����� - %d ���������.\n", discount[id]);
                    }
                }
                break;
        case 3: 
                if (id == 0) printf("��� ������ ������������� �����.\n");
                else
                {
                    kolichestvo[id]++;
                    printf("����� �������� � ���.\n");
                    itogo += (prices[id] - (prices[id] * discount[id] * 0.01));
                }
                break;
        case 4: 
                for (i = 0; i < kolvotovarov; i++)
                    if (kolichestvo[i] != 0)
                    {
                        vivodimeni(i);
                        printf("���� �� ������� ������ ��� ������ - %d ������.\n", prices[i]);
                        printf("���������� ����� ������� - %d.\n", kolichestvo[i]);
                        printf("����� ��������� ������ ��� ������ - %d ������.\n", (kolichestvo[i] * prices[i]));
                        printf("������ �� ����� - %d ���������.\n", discount[i]);
                        printf("------------------------------------------\n");
                    }
                break;
        case 5: 
                printf("����� ����� ����� ������� - %d ������ � ������ ���� ������.\n", itogo);
                break;
        case 0: 
                return;
        default: printf("������ �������� �����.\n");
        }
    } while(1); //����������� ����, ��� ��� � ���� ���� ����� ��� ������ �� ���������
}