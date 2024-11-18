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

void put_point(Point z)
{
	printf("point %c (%.1f, %.1f)", z.name, z.x, z.y);
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
	printf("До окончания пары %d минут и %d секунд> ", m-mytime->tm_min, s-mytime->tm_sec);
}