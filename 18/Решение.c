#define _CRT_SECURE_NO_DEPRECATE 
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


	Motocikl c;
	
	for (int i = 0; i < size; i++)
	{
		printf("Введите название марки > ");
		scanf_s("%s", c.marka, (int)sizeof(c.marka));
		printf("Введено %s\n", c.marka);
		system("pause");
		printf("Введите год выпуска > ");
		scanf_s("%d", &c.year);
		printf("Введено %d\n", c.year);
		system("pause");
		printf("Введите дату регистрации (dd_mm_gggg) > ");
		scanf_s("%s", c.data, (int)sizeof(c.data));
		printf("Введено %s\n", c.data);
		system("pause");
		printf("Введите мощность > ");
		scanf_s("%d", &c.mohnost);
		printf("Введено %d\n", c.mohnost);
		system("pause");
		printf("Введите состояние мотоцикла, наличие повреждений > ");
		scanf_s("%s", c.povr, (int)sizeof(c.povr));
		printf("Введено %s\n", c.povr);

		printf("%s %d %s %s %d\n", c.marka, c.year, c.data, c.povr, c.mohnost);\
		masiv[i] = {c.marka, c.year, c.data, c.povr, c.mohnost};
		masiv++;
	}
	for (;;)
	{

	}
}