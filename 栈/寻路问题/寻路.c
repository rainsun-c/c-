#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
//坐标结构体
typedef struct 
{
	int x;
	int y;
}Coord;

Coord Stack[100];	   //栈，用来保存数据
int** map=NULL;        //地图
int stacktop = -1;	   //栈顶
int size=0;            //尺寸
int** Map(int x,int y) //开辟地图空间
{
	int** map = (int**)malloc(sizeof(int*)*x);//开辟空间二维数据空间
	int i = 0;
	for (i = 0; i < y; i++)
	{
		map[i] = (int*)malloc(sizeof(int)*y);//开辟一维数据空间
	}
	return map;
}
void createMap()
{
	printf("输入迷宫大小\n");
	int i = 0;
	int j = 0;
	scanf("%d",&size);
	map = Map(size + 2, size + 2);
	printf("输入迷宫\n");
	for (i = 1; i <= size ; i++)
	{
		for (j = 1; j <= size ; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	//围边框
	for (i = 0; i <= size + 1; i++)
	{
		map[0][i] = map[size + 1][i] = 1;
		map[i][0] = map[i][size + 1] = 1;
	}
}

int findPath()
{
	Coord offset[4];
	//右
	offset[0].x = 0;
	offset[0].y = 1;
	//下
	offset[1].x = 1;
	offset[1].y = 0;
	//左
	offset[2].x = -1;
	offset[2].y = 0;
	//上
	offset[3].x =0 ;
	offset[3].y = -1;
	//入口
	Coord come = { 1, 1 };
	//将走过的地方置1
	map[1][1] = 1;
	//移动值
	int option = 0;
	//停止值
	int endOption = 3;
	while (come.x != size || come.y != size)
	{
		//存储位置
		int rowNum, colsNum;
		//当移动值小于终止值
		while (option <= endOption)
		{
			//保存移动的下一个位置
			rowNum = come.x + offset[option].x;
			colsNum = come.y + offset[option].y;
			//判断能不能走（1表示墙，能不能走继续换方向）
			if (map[rowNum][colsNum] == 0)
			{
				break;
			}
			//换位置
			option++;
		}
		//还没超过终止值时
		if (option <= endOption)
		{
			//保存位置
			Stack[++stacktop] = come;
			//将移动完的位置保存到初始点，现在已一个点重新定义起始位
			come.x = rowNum;
			come.y = colsNum;
			//将走过的路封住，即置1
			map[rowNum][colsNum] = 1;
			//保存后，将移动位置变到原来位置
			option = 0;
		}
		else
		{   
			//回到上一步去
			if (stacktop == -1)
			{
				//无路可走
				return 0;
			}
			//出栈的方式回退到上一步
			Coord next = Stack[stacktop];
			stacktop--;
			//方向处理
			if (next.x == come.x)
			{
				//行没变，左右走的
				option = 2 + next.y - come.y;
			}
			else
			{
				option = 3 + next.x - come.x;
			}
			//回退到上一步
			come = next;
		}
	}
	return 1;
}

void printfStack()
{
	printf("路径方式：\n");
	Coord Mov;
	while (stacktop != -1)
	{
		Mov = Stack[stacktop];
		stacktop--;
		printf("%d,%d->",Mov.x,Mov.y);
	}
	printf("\n");
}
int main()
{
	createMap();
	if (findPath())
	{
		printfStack();
	}
	else
	{
		printf("没有路径\n");
	}
	system("pause");
	return 0;
}