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
		printf("������²������\n");
		scanf("%d", &input);
		if (input < num)
		{
			printf("С��\n");
			printf("����������\n");
		}
		else if (input > num)
		{
			printf("����\n");
			printf("����������\n");
		}
	} while (input - num);
	printf("��ϲ�㣬����\n");
	while (1);
	return 0;
}