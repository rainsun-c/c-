
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//�յ� 0��ǽ 1��Ŀ�ĵ� 2������ 3 ���� 4����ͼ��С 10��
enum x
{
	Space,
	Wall,
	Goal,
	Box,
	People,
	Max=10
};
int z = 0;//��
int a[3][Max][Max]= {
	{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 1, 1, 1, 1, 0, 0, 0,
		1, 1, 1, 1, 0, 2, 1, 0, 0, 0,
		1, 2, 3, 0, 0, 3, 1, 0, 0, 0,
		1, 1, 1, 0, 4, 0, 1, 1, 1, 0,
		0, 0, 1, 0, 0, 0, 3, 2, 1, 0,
		0, 0, 1, 0, 1, 1, 1, 1, 1, 0,
		0, 0, 1, 3, 1, 0, 0, 0, 0, 0,
		0, 0, 1, 2, 1, 0, 0, 0, 0, 0,
		0, 0, 1, 1, 1, 0, 0, 0, 0, 0
	},
	{//�յ� 0��ǽ 1��Ŀ�ĵ� 2������ 3 ���� 4����ͼ��С 10��
		0, 1, 1, 1, 1, 1, 1, 0, 0, 0,
		0, 1, 0, 2, 1, 0, 1, 0, 0, 0,
		1, 1, 0, 3, 1, 2, 1, 0, 0, 0,
		1, 2, 3, 4, 0, 3, 1, 0, 0, 0,
		1, 0, 0, 0, 0, 0, 1, 0, 0, 0,
		1, 1, 0, 1, 1, 1, 1, 0, 0, 0,
		0, 1, 0, 1, 0, 0, 0, 0, 0, 0,
		0, 1, 1, 1, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	},
	{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	}
};

//d��ӡ
void print()
{
	
	for (int i = 0; i < Max; i++)
	{
		for (int j = 0; j < Max; j++)
		{
			switch (a[z][i][j])
			{
			case Space:
				printf("  ");
				break;
			case Wall:
				printf("��");
				break;
			case Goal:
				printf("��");
				break;
			case Box:
				printf("��");
				break;
			case People:
				printf("��");
				break;
			case Goal + Box:
				printf("O ");
				break;
			case Goal + People:
				printf("P ");
				break;
			}
		}
		printf("\n");
	}
}
void mov()
{
	int i = 0;
	int j = 0;
	//����
	for (i = 0; i < Max; i++)
	{
		for (j = 0; j < Max; j++)
		{
			if (a[z][i][j] == People || a[z][i][j] == People+Goal)
			{
				goto t;
			}
		}
	}
t:;
	char key = _getch();
	switch (key)
	{
		//��
	case 'W':
	case 'w':
	case 72:
		//�յ�Space 0��ǽWall 1��Ŀ�ĵ�Goal 2������ Box3 ����People 4����ͼ��С 10��
		//��ǰ���ǿյأ�Ŀ�ĵأ������ߵ�
		if (a[z][i - 1][j] == Space || a[z][i - 1][j] == Goal)
		{
			//������
			a[z][i - 1][j] += People;
			//��ԭ��λ�øɵ�
			a[z][i][j] -= People;
		}
		//�����������ӻ���������Ŀ�ĵ���
		else if (a[z][i - 1][j] == Box+Goal || a[z][i - 1][j] == Box)
		{
			//����������ʲô����Ŀ�ĵػ��ǿյ�
			if (a[z][i - 2][j] == Goal || a[z][i - 2][j] == Space)
			{
				a[z][i - 2][j] += Box;
				a[z][i - 1][j] -= Box;
				a[z][i - 1][j] += People;
				a[z][i][j] -= People;
			}
		}
		break;
		//��
	case 'S':
	case 's':
	case 80:
		if (a[z][i+1][j] == Space || a[z][i][j] == Goal)
		{
			a[z][i + 1][j] += People;
			a[z][i][j] -= People;
		}
		else if (a[z][i + 1][j] == Box || a[z][i + 1][j] == Box + Goal)
		{
			if (a[z][i + 2][j] == Goal || a[z][i + 2][j] == Space)
			{
				a[z][i + 2][j] += Box;
				a[z][i + 1][j] -= Box;
				a[z][i + 1][j] += People;
				a[z][i][j] -= People;
			}
		}
		break;
		//��
	case 'A':
	case 'a':
	case 75:
		if (a[z][i][j-1] == Space || a[z][i][j-1] == Goal)
		{
			a[z][i][j-1] += People;
			a[z][i][j] -= People;
		}
		else if (a[z][i][j-1] == Box || a[z][i][j-1] == Box + Goal)
		{
			if (a[z][i][j-2] == Goal || a[z][i][j-2] == Space)
			{
				a[z][i][j-2] += Box;
				a[z][i][j-1] -= Box;
				a[z][i][j-1] += People;
				a[z][i][j] -= People;
			}
		}
		break;
		//��
	case 'D':
	case 'd':
	case 77:
		if (a[z][i][j+1] == Space || a[z][i][j+1] == Goal)
		{
			a[z][i][j+1] += People;
			a[z][i][j] -= People;
		}
		else if (a[z][i][j+1] == Box || a[z][i][j+1] == Box + Goal)
		{
			if (a[z][i][j+2] == Goal || a[z][i][j+2] == Space)
			{
				a[z][i][j+2] += Box;
				a[z][i][j+1] -= Box;
				a[z][i][j+1] += People;
				a[z][i][j] -= People;
			}
		}
		break;
	}
}
int judge()
{
	int i = 0;
	int j = 0;
	for (i = 0; i < Max; i++)
	{
		for (j = 0; j < Max; j++)
		{
			if (a[z][i][j]==Box)
			{
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	while (1)
	{
		if (judge())
		{

			print();
			mov();
			system("cls");
		}
		else
		{
			z=z+1;
			if (z == 2)
			{
				break;
			}
		}
	}
	printf("����\n");
	while (1);
	return 0;
}