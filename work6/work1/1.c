#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand((unsigned)time(NULL));
	int count = 0;   //计数
	int num = 0;     //随机的数字
	int max = 0;     //最大值
	int a = 0;       //暂时存放
	for (count = 0; count < 20; count++)
	{
		num = rand() % 91 + 10;
		a = num;
		printf("%d\t", a);
		if (a > max)
		{
			max = a;
		}
		if (count == 9)
		{
			printf("\n");
		}
	}
	printf("\n");
	printf("最大=%d\n",max);
	system("pause");
	return 0;
}