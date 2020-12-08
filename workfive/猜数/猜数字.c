#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main()
{
	int num = 0;
	int input = 0;
	srand((unsigned)time(NULL));
	num = (int)rand() % 100+1;
	do{
		printf("请输入猜测的数字\n");
		scanf("%d", &input);
		if (input < num)
		{
			printf("小了\n");
			printf("请重新输入\n");
		}
		else if (input > num)
		{
			printf("大了\n");
			printf("请重新输入\n");
		}
	} while (input - num);
	printf("恭喜你，对了\n");
	while (1);
	return 0;
}