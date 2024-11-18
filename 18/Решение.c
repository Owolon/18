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

typedef struct tm {
	int tm_sec;
	int tm_min;
	int tm_hour;
	int tm_mday;
	int tm_mon;
	int tm_year;
	int tm_wday;
	int tm_yday;
	int tm_isdst;
};
void put_point(Point z)
{
	printf("point%c (%.1f, %.1f)", z.name, z.x, z.y);
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

	printf("����� ��������� ���� > ");
	scanf_s("%d",&m);
	scanf_s("%d", &s);
	printf("�� ��������� ���� %d ����� � %d ������> ", m-mytime->tm_min, s-mytime->tm_sec);
}