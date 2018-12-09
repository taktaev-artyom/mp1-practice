#include <stdio.h>
#include <locale.h>
#define k 10
#define N 5

void choose(int a[], int n)
{
    int i, j, min, minidx, tmp;
    for(i = 0; i < n; i++)
    {
        min = a[i];
        minidx = i;
        for(j = i + 1; j < n; j++)
        {
            if (a[j] < min)
            {
                minidx = j;
                min = a[j];
            }
        }
        tmp = a[i];
	    a[i] = a[minidx];
        a[minidx] = tmp;
    }
}
 
void insert(int a[], int n)
{
    int i, j, tmp;
    for(i = 1; i < n; i++)
    {
        j = i - 1;
        tmp = a[i];
        while ((j >= 0) && (a[j] > tmp))
        {
            a[j + 1] = a[j];
            a[j] = tmp;
            j--;
        }
    } 
}

void bubblesort(int a[], int n)
{
    int i, j, tmp;
    for (i = 0; i < n; i++)
    {
        for (j = 1; j < n - i; j++)
        {
            if (a[j - 1] > a[j])
            {
                tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
            }
        }
    }
}

void countingsort(int a[], int n)
{
    int i, j, b = 0;
    int count[k];
    for (i = 0; i < k; i++) count[i] = 0;
    for (i = 0; i < n; i++) count[a[i]]++;
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < count[i]; j++)
        {
            a[b] = i;
            b++;
        }
    }
}

void quicksplit(int a[], int *i, int *j, int p)
{
    do 
    {
        while (a[*i] < p) i++;
        while (a[*j] > p) j--;
        if (*i < *j)
        {
            int tmp = a[*i];
            a[*i] = a[*j];
            a[*j] = tmp;
        }
    } while (*i <= *j);
}

void quicksort(int a[], int n1, int n2)
{
    int pidx = (n1 + n2) / 2;
    int i = n1, j = n2;
    quicksplit(a, &i, &j, a[pidx]);
    if (j > n1) quicksort(a, n1, j);
    if (i < n2) quicksort(a, i, n2);
}

void mergesort(int a[], int l, int r)
{
    int m;
	if (l >= r) return;
    m = (l + r) / 2;
    mergesort(a, l, m);
    mergesort(a, m+1, r);
    merge(a, l, m, r);
}

void merge(int a[], int l, int m, int r)
{
    int i = 0, j = m + 1, s = 0; 
    while ((i < m) && (j < r)) 
        if (a[i] < a[j]) a[s++] = a[i++];
        else a[s++] = a[j++];
    while (i < m) a[s++] = a[i++];
    while (j < r) a[s++] = a[j++];
}

void scan(int a[], int n)
{
    int i;
    printf("¬ведите массив:\n");
    for (i = 0; i < n; i++) scanf("%d", &(a[i]));
}

void print(int a[], int n)
{
    int i;
    printf("¬аш массив:\n");
    for (i = 0; i < n - 1; i++) printf("%d", a[i]);
    printf("%d\n", a[n - 1]);
}

int menu()
{
    int r;
    printf("¬ыберите вид сортировки:\n");
    printf("1.—ортировка выбором.\n");
    printf("2.—ортировка вставками.\n");
    printf("3.ѕузырькова¤ сортировка.\n");
    printf("4.—ортировка подсчЄтом.\n");
    printf("5.Ѕыстра¤ сортировка.\n");
    printf("6.—ортировка сли¤нием.\n");
    scanf("%d", &r);
    return r;
}

int choose(int rezhim)
{
	switch (rezhim)
    {
    case 1:
        choose(a,N);
        break;
    case 2:
        insert(a,N);
        break;
    case 3:
        bubblesort(a,N);
        break;
    case 4:
        countingsort(a,N);
        break;
    case 5:
        quicksort(a, 0, N - 1);
        break;
    case 6:
        mergesort(a, 0, N - 1);
        break;
    default: printf("ќшибка в выборе сортировки\n");
             return;
}

void main()
{
    int a[N];
    setlocale(LC_ALL, "Russian");
    scan(a,N);
    print(a,N);
    choose(menu());
}