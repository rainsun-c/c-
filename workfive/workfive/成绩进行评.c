#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main()
{
	float score = 0;
	int a = 0;
	printf("������ѧ���ɼ�:\n");
	scanf("%f",&score);
	if (0 <= score&&score < 60.0)
		a = 5;
	else if (score <= 69.0 && score >= 60.0)
		a = 1;
	else if (score <= 79.0 && score >69.0)
		a = 2;
	else if (score < 90.0 && score > 79.0)
		a = 3;
	else if (score<=100&&score >= 90.0)
		a = 4;
	else
		a = 7;
	switch (a)
	{
		case 1:
			printf("ѧ���ȼ�ΪD\n");
			break;
		case 2:
			printf("ѧ���ȼ�ΪC\n");
			break;
		case 3:
			printf("ѧ���ȼ�ΪB\n");
			break;
		case 4:
			printf("ѧ���ȼ�ΪA\n");
			break;
		case 5:
			printf("ѧ���ȼ�ΪE\n");
			break;
		default:
			printf("�������\n");
			break;
	}
	while (1);
	return 0;
}