#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main()
{
	float score = 0;
	int a = 0;
	printf("请输入学生成绩:\n");
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
			printf("学生等级为D\n");
			break;
		case 2:
			printf("学生等级为C\n");
			break;
		case 3:
			printf("学生等级为B\n");
			break;
		case 4:
			printf("学生等级为A\n");
			break;
		case 5:
			printf("学生等级为E\n");
			break;
		default:
			printf("输入错误\n");
			break;
	}
	while (1);
	return 0;
}