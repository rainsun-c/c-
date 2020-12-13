
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//空地 0，墙 1，目的地 2，箱子 3 ，人 4，地图大小 10；
enum x
{
	Space,
	Wall,
	Goal,
	Box,
	People,
	Max=10
};
int z = 0;//层
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
	{//空地 0，墙 1，目的地 2，箱子 3 ，人 4，地图大小 10；
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

//d打印
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
				printf("■");
				break;
			case Goal:
				printf("※");
				break;
			case Box:
				printf("○");
				break;
			case People:
				printf("♀");
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
	//找人
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
		//上
	case 'W':
	case 'w':
	case 72:
		//空地Space 0，墙Wall 1，目的地Goal 2，箱子 Box3 ，人People 4，地图大小 10；
		//当前面是空地，目的地，可以走的
		if (a[z][i - 1][j] == Space || a[z][i - 1][j] == Goal)
		{
			//向上走
			a[z][i - 1][j] += People;
			//把原来位置干掉
			a[z][i][j] -= People;
		}
		//当上面是箱子或者箱子在目的地上
		else if (a[z][i - 1][j] == Box+Goal || a[z][i - 1][j] == Box)
		{
			//箱子上面是什么？是目的地还是空地
			if (a[z][i - 2][j] == Goal || a[z][i - 2][j] == Space)
			{
				a[z][i - 2][j] += Box;
				a[z][i - 1][j] -= Box;
				a[z][i - 1][j] += People;
				a[z][i][j] -= People;
			}
		}
		break;
		//下
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
		//左
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
		//右
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
	printf("过关\n");
	while (1);
	return 0;
}