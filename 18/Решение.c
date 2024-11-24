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
//�� ������
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
	printf("���������� ����� %02d:%02d:%02d \n",mytime->tm_hour, mytime->tm_min, mytime->tm_sec);

	printf("���� ����� ��������� ���� > ");
	scanf_s("%d",&m);
	printf("������� > ");
	scanf_s("%d", &s);
	printf("�� ��������� ���� %d ����� � %d ������\n", m-mytime->tm_min, s-mytime->tm_sec);

	int size;
	printf("������� ������ ������� > ");
	scanf_s("%d", &size);
	Motocikl *masiv;
	masiv = (Motocikl*)malloc(size * sizeof(Motocikl));
	if (masiv == NULL)
	{
		printf("������ ��������� ������.\n");
	}
	else
	{
		printf("�������.\n");
	}


	Motocikl c;
	
	for (int i = 0; i < size; i++)
	{
		printf("������� �������� ����� > ");
		scanf_s("%s", c.marka, (int)sizeof(c.marka));
		printf("������� %s\n", c.marka);
		system("pause");
		printf("������� ��� ������� > ");
		scanf_s("%d", &c.year);
		printf("������� %d\n", c.year);
		system("pause");
		printf("������� ���� ����������� (dd_mm_gggg) > ");
		scanf_s("%s", c.data, (int)sizeof(c.data));
		printf("������� %s\n", c.data);
		system("pause");
		printf("������� �������� > ");
		scanf_s("%d", &c.mohnost);
		printf("������� %d\n", c.mohnost);
		system("pause");
		printf("������� ��������� ���������, ������� ����������� > ");
		scanf_s("%s", c.povr, (int)sizeof(c.povr));
		printf("������� %s\n", c.povr);

		printf("%s %d %s %s %d\n", c.marka, c.year, c.data, c.povr, c.mohnost);\
		masiv[i] = {c.marka, c.year, c.data, c.povr, c.mohnost};
		masiv++;
	}
	for (;;)
	{

	}
}