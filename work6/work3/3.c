#include <stdio.h>
//3，输出显示1~100之间可以被n整除的所有整数，
//运行时n由键盘输入。要求每一行显示5个数，并且统计一共有多少个整数能被n整除。(不准用数组)
int main()
{
	int count = 0;//计数
	int input = 0;//输入值
	scanf_s("%d",&input);
	for (int i = 1; i <= 100; i++)
	{
		if (i % input == 0)
		{
			count++;
			printf("%d\t",i);
			if (count % 5 == 0)   //每5个换行
			{
				printf("\n");
			}
		}
	}
	while (1);
	return 0;
}