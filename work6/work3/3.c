#include <stdio.h>
//3�������ʾ1~100֮����Ա�n����������������
//����ʱn�ɼ������롣Ҫ��ÿһ����ʾ5����������ͳ��һ���ж��ٸ������ܱ�n������(��׼������)
int main()
{
	int count = 0;//����
	int input = 0;//����ֵ
	scanf_s("%d",&input);
	for (int i = 1; i <= 100; i++)
	{
		if (i % input == 0)
		{
			count++;
			printf("%d\t",i);
			if (count % 5 == 0)   //ÿ5������
			{
				printf("\n");
			}
		}
	}
	while (1);
	return 0;
}