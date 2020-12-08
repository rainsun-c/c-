#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void complete(int num)
{
	switch (num)
	{
	case 0:
		printf("电脑出:石头\n");
		break;
	case 1:
		printf("电脑出:剪刀\n");
		break;
	case 2:
		printf("电脑出:布\n");
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
	printf("请输石头0、剪刀1、布2\n");
	scanf("%d", &people);
	a = people - num;
	switch (a)
	{
	case 0: 
		complete(num);
		printf("平均\n");
		break;
	case -1:
		complete(num);
		printf("玩家赢\n");
		break;
	case -2:
		complete(num);
		printf("电脑赢\n");
		break;
	case 1:
		complete(num);
		printf("电脑赢\n");
		break;
	case 2:
		complete(num);
		printf("玩家赢\n");
		break;
	default:
		break;
	}
	while (1);
	return 0;
}
