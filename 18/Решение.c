#define _CRT_SECURE_NO_DEPRECATE 
#define DEREF_NULL_PTR
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <locale.h>

struct point {
	float x;
	float y;
	char name;
};
typedef struct point Point;
//ДЗ стракт
struct moto {
	char marka[50];
	int year;
	char data[10];
	int mohnost;
	char povr[10];
};
typedef struct moto Motocikl;

void put_point(Point z)
{
	printf("point %c (%.1f, %.1f)\n", z.name, z.x, z.y);
}
float dist(Point z, Point w)
{
	float AB;
	AB = sqrt(pow(z.x - w.x, 2) + pow(z.y - w.y, 2));
	return AB;  
}
float sist(Point z, Point w)
{
	Point M;
	M.x = (z.x + w.x / 2);   

	M.y= (z.y + w.y / 2 );
	return 0;
}
int full_el(int size, Motocikl *masiv)
{
	int g = 0;
	for (int i = 1; i < size + 1; i++)
	{
		printf("Введите название марки > ");
		scanf_s("%s", masiv[i].marka, (int)sizeof(masiv[i].marka));
		printf("Введите год выпуска > ");
		scanf_s("%d", &masiv[i].year);
		printf("Введите дату регистрации (dd_mm_gggg) > ");
		scanf_s("%s", masiv[i].data, (int)sizeof(masiv[i].data));
		printf("Введите мощность > ");
		scanf_s("%d", &masiv[i].mohnost);
		printf("Введите состояние мотоцикла, наличие повреждений > ");
		scanf_s("%s", masiv[i].povr, (int)sizeof(masiv[i].povr));
		printf("%s %d %s %s %d\n", masiv[i].marka, masiv[i].year, masiv[i].data, masiv[i].povr, masiv[i].mohnost);
		printf("Записано чисел %d\n", i);
	}
	g++;
	return g;
}
void main()
{
	setlocale(LC_CTYPE, "RUS");
	Point b, a;
	a = (Point) { 1.f, 2.f, 'A' };
	b.name = 'B'; b.x = 5; b.y = -3;
	printf("point %c (%.1f, %.1f)", b.name, b.x, b.y);
	system("pause");
	put_point(b);
	int m,s;
	struct tm* mytime;
	time_t t;
	t = time(NULL);
	mytime = localtime(&t);
	printf("Московское время %02d:%02d:%02d \n",mytime->tm_hour, mytime->tm_min, mytime->tm_sec);

	printf("Ввод минут окончания пары > ");
	scanf_s("%d",&m);
	printf("Секунды > ");
	scanf_s("%d", &s);
	printf("До окончания пары %d минут и %d секунд\n", m-mytime->tm_min, s-mytime->tm_sec);

	int size;
	printf("Введите размер массива > ");
	scanf_s("%d", &size);
	Motocikl *masiv;
	masiv = (Motocikl*)malloc(size * sizeof(Motocikl));
	if (masiv == NULL)
	{
		printf("Ошибка выделения памяти.\n");
	}
	else
	{
		printf("Успешно.\n");
	}


	//Motocikl c;
	full_el(size, masiv);
	for (int j = 0; j < size ;j++)
	{
		printf("%s %d %d %s %s", masiv[j].data, masiv[j].year, masiv[j].mohnost, masiv[j].marka, masiv[j].povr);
	}
}