#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void complete(int num)
{
	switch (num)
	{
	case 0:
		printf("���Գ�:ʯͷ\n");
		break;
	case 1:
		printf("���Գ�:����\n");
		break;
	case 2:
		printf("���Գ�:��\n");
		break;
	}
}
int main()
{
	int people = 0;
	int num = 0;
	int a = 0;
	srand((unsigned)time(NULL));
	num =(int) rand() % 3;
	printf("����ʯͷ0������1����2\n");
	scanf("%d", &people);
	a = people - num;
	switch (a)
	{
	case 0: 
		complete(num);
		printf("ƽ��\n");
		break;
	case -1:
		complete(num);
		printf("���Ӯ\n");
		break;
	case -2:
		complete(num);
		printf("����Ӯ\n");
		break;
	case 1:
		complete(num);
		printf("����Ӯ\n");
		break;
	case 2:
		complete(num);
		printf("���Ӯ\n");
		break;
	default:
		break;
	}
	while (1);
	return 0;
}
