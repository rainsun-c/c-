#include <stdio.h>
#include <stdlib.h>

int main()
{
	int zm = 0;       //��ĸ
	int digtal = 0;   //����
	int t = 0;        //�ո�
	int other = 0;    //����
	char a = 0;
	while ((a = getchar()) != '\n')
	{

		if (a >= 48 && a <= 57)
		{
			digtal++;
		}
		else
		if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122))
		{
			zm++;
		}
		else
		if (a == ' ')
		{
			t++;
		}
		else
			other++;
	}
		printf("��ĸ��%d\n", zm);
		printf("���֣�%d\n", digtal);
		printf("������%d\n", other);
		printf("�ո�%d\n", t);
	while (1);
	return 0;
}

