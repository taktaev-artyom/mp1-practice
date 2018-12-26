﻿#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <locale.h> 
#define dlina 30 
#define kolvotovarov 10 

char nazvanie[kolvotovarov][dlina] = {"Фотоаппарат Nikon","Смартфон Xiaomi", 
    "Телевизор Samsung","Игровая приставка PlayStation","Наушники HyperX", 
    "Портативная колонка JBL","Ноутбук ASUS","Стиральная машина Siemens", 
    "Принтер Canon","Холодильник Toshiba"}; 
char codes[kolvotovarov][5] = {"1337", "1487", "1234", "8008", "1508", "1221", 
    "1256", "0007", "0124", "1488"}; 
int discount[kolvotovarov]; 
int f = 0; 
int kolichestvo[kolvotovarov]; 

void skidki(int min_skidka, int max_skidka) 
{ 
    int i; 
    srand((unsigned int) time(0)); 
    for (i = 0; i < kolvotovarov; i++) 
    { 
        discount[i] = min_skidka + rand() % (max_skidka - min_skidka); 
    } 
} 

void menu() 
{ 
    printf("Начало работы.\n"); 
    printf("Введите 1, чтобы сканировать товар.\n"); 
    printf("Введите 2, чтобы вывести информацию о товаре.\n"); 
    printf("Введите 3, чтобы добавить этот товар в чек.\n"); 
    printf("Введите 4, чтобы вывести чек.\n"); 
    printf("Введите 5, чтобы рассчитать общую стоимость покупки.\n"); 
    printf("Введите 0, чтобы выйти из программы.\n"); 
} 

int findcodeid(int id) 
{ 
    int i, f1 = 0; 
    for (i = 0; i < kolvotovarov; i++) 
    { 
        if (atoi(codes[i]) == id) break; 
        f1 = 1; 
    } 
    if (f1 == 1) return i; 
} 

void vivodimeni(int id) 
{ 
    int i, j; 
    if ((id != 1337) && (id != 1487) && (id != 1234) && (id != 8008) && (id != 1508) && 
    (id != 1221) && (id != 1256) && (id != 0007) && (id != 0124) && (id != 1488)) 
    printf("Товара с таким штрих-кодом не существует.\n"); 
    else 
    { 
        for (j = 0; j < kolvotovarov; j++) 
        for (i = 0; i < dlina; i++) if (atoi(codes[j]) == id) printf("%c", nazvanie[j][i]); 
        printf("\n"); 
        f = 1; 
    } 
} 



void main() 
{ 
    int id = 0, punkt, i = 0, newid; 
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
        printf("Выберите пункт.\n"); 
        scanf("%d", &punkt); 
        switch(punkt) 
        { 
        case 1: 
            printf("Введите штрих-код.\n"); 
            scanf("%d", &id); 
            break; 
       case 2: 
            if (id == 0) printf("Для начала просканируйте товар.\n"); 
            else 
            { 
                vivodimeni(id); 
                if (f == 1) 
                { 
                    newid = findcodeid(id); 
                    printf("Цена за единицу товара без скидки - %d.\n", prices[newid]); 
                    printf("Скидка на товар - %d процентов.\n", discount[newid]); 
                } 
            } 
            break; 
        case 3: 
            if (id == 0) printf("Для начала просканируйте товар.\n"); 
            else 
            { 
                kolichestvo[newid]++; 
                printf("Товар добавлен в чек.\n"); 
                itogo += (prices[newid] - (prices[newid] * discount[newid] * 0.01)); 
            } 
            break; 
        case 4: 
            for (i = 0; i < kolvotovarov; i++) 
            if (kolichestvo[i] != 0) 
            { 
                vivodimeni(atoi(codes[i])); 
                printf("Цена за единицу товара без скидки - %d рублей.\n", prices[i]); 
                printf("Количество таких товаров - %d.\n", kolichestvo[i]); 
                printf("Общая стоимость товара без скидки - %d рублей.\n", (kolichestvo[i] * prices[i])); 
                printf("Скидка на товар - %d процентов.\n", discount[i]); 
                printf("------------------------------------------\n"); 
            } 
            break; 
        case 5: 
            printf("Общая сумма вашей покупки - %d рублей с учетом всех скидок.\n", itogo); 
            break; 
        case 0: 
            return; 
        default: printf("Введен неверный пункт.\n"); 
        } 
    } while(1); //бесконечный цикл, так как в меню есть пункт для выхода из программы 
}