#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

enum play
{
	ʯͷ,
	����,
	��
};
int main()
{
	int people = 0;
	int num = 0;
	int s = 0;
	srand((unsigned)time(NULL));
	num = rand() % 3;
	printf("���������ʯͷ����\n");
	scanf("%d", people);
	if (people < num)
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
		printf("����Ӯ\n");
	}
	else if (people > num)
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
		printf("���Ӯ\n");
	}
	else
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
		printf("ƽ��\n");
	}
	while (1);
	return 0;
}
