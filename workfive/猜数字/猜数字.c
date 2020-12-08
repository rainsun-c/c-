#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

enum play
{
	石头,
	剪刀,
	布
};
int main()
{
	int people = 0;
	int num = 0;
	int s = 0;
	srand((unsigned)time(NULL));
	num = rand() % 3;
	printf("请输剪刀、石头、布\n");
	scanf("%d", people);
	if (people < num)
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
		printf("电脑赢\n");
	}
	else if (people > num)
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
		printf("玩家赢\n");
	}
	else
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
		printf("平局\n");
	}
	while (1);
	return 0;
}
