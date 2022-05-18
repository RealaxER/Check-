#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef enum {true,false} bool;
void cpd(int** p, int n);
void enter(int* p, int n);
void show(int* p, int n);
void cpl(int** p, int nmoi, int *ncu);
void _add(int* p, int *n, int location, int value);

void test(int *ncu);

int main(int arg, int* pointer[])
{
	int* p = 0;
	static int n = 0;
	do
	{
		printf("\nNhap gia tri n : "); scanf_s("%d", &n);
		if ((n <= 0) && (n > 100)) {
			printf("\nNhap lai gia tri n > 0 va n <100 ");
		};
	} while (n <= 0 && n > 100);
	cpd(&p, n);
	enter(p, n);
	show(p, n);
	int n2;
	do
	{
		printf("\nNhap gia tri cap phat lai : "); scanf_s("%d", &n2);
	} while (n2 <= 0);
	cpl(&p, n2, &n);
	show(p, n);
	int location;
	printf("\nenter the location for add : ");
	scanf_s("%d", &location);
	int value;
	printf("\nenter the value for add : ");
	scanf_s("%d", &value);
	_add(&p, &n, location, value);
	show(p, n);
	//free(p);
	_getch();
}
void test(int *ncu)
{
	*ncu = 100;
}
void cpd(int**p, int n)
{
	*p = (int*) malloc(n * sizeof(int));
}
void enter(int* p, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\nNhap gia tri thu %d : ", i);
		scanf_s("%d", &p[i]);
	}
}
void show(int* p, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\nGia tri thu %d la : %d", i, p[i]);
	}
}
void cpl(int** p, int nmoi, int *ncu)
{
	 p = (int*)realloc(*p, nmoi * sizeof(int));
	*ncu = nmoi;
}
void _add(int** p, int* n, int location, int value)
{
	int temp = *n +1;
	cpl(*&p,temp, &n);
	printf("\nGia tri n : %d  ", n);
	for (int i = *n - 1; i > location; i--)
	{
		p = p[i - 1];
	}
	p[location] = value;
}