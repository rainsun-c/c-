#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
//����ṹ��
typedef struct 
{
	int x;
	int y;
}Coord;

Coord Stack[100];	   //ջ��������������
int** map=NULL;        //��ͼ
int stacktop = -1;	   //ջ��
int size=0;            //�ߴ�
int** Map(int x,int y) //���ٵ�ͼ�ռ�
{
	int** map = (int**)malloc(sizeof(int*)*x);//���ٿռ��ά���ݿռ�
	int i = 0;
	for (i = 0; i < y; i++)
	{
		map[i] = (int*)malloc(sizeof(int)*y);//����һά���ݿռ�
	}
	return map;
}
void createMap()
{
	printf("�����Թ���С\n");
	int i = 0;
	int j = 0;
	scanf("%d",&size);
	map = Map(size + 2, size + 2);
	printf("�����Թ�\n");
	for (i = 1; i <= size ; i++)
	{
		for (j = 1; j <= size ; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	//Χ�߿�
	for (i = 0; i <= size + 1; i++)
	{
		map[0][i] = map[size + 1][i] = 1;
		map[i][0] = map[i][size + 1] = 1;
	}
}

int findPath()
{
	Coord offset[4];
	//��
	offset[0].x = 0;
	offset[0].y = 1;
	//��
	offset[1].x = 1;
	offset[1].y = 0;
	//��
	offset[2].x = -1;
	offset[2].y = 0;
	//��
	offset[3].x =0 ;
	offset[3].y = -1;
	//���
	Coord come = { 1, 1 };
	//���߹��ĵط���1
	map[1][1] = 1;
	//�ƶ�ֵ
	int option = 0;
	//ֵֹͣ
	int endOption = 3;
	while (come.x != size || come.y != size)
	{
		//�洢λ��
		int rowNum, colsNum;
		//���ƶ�ֵС����ֵֹ
		while (option <= endOption)
		{
			//�����ƶ�����һ��λ��
			rowNum = come.x + offset[option].x;
			colsNum = come.y + offset[option].y;
			//�ж��ܲ����ߣ�1��ʾǽ���ܲ����߼���������
			if (map[rowNum][colsNum] == 0)
			{
				break;
			}
			//��λ��
			option++;
		}
		//��û������ֵֹʱ
		if (option <= endOption)
		{
			//����λ��
			Stack[++stacktop] = come;
			//���ƶ����λ�ñ��浽��ʼ�㣬������һ�������¶�����ʼλ
			come.x = rowNum;
			come.y = colsNum;
			//���߹���·��ס������1
			map[rowNum][colsNum] = 1;
			//����󣬽��ƶ�λ�ñ䵽ԭ��λ��
			option = 0;
		}
		else
		{   
			//�ص���һ��ȥ
			if (stacktop == -1)
			{
				//��·����
				return 0;
			}
			//��ջ�ķ�ʽ���˵���һ��
			Coord next = Stack[stacktop];
			stacktop--;
			//������
			if (next.x == come.x)
			{
				//��û�䣬�����ߵ�
				option = 2 + next.y - come.y;
			}
			else
			{
				option = 3 + next.x - come.x;
			}
			//���˵���һ��
			come = next;
		}
	}
	return 1;
}

void printfStack()
{
	printf("·����ʽ��\n");
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
		printf("û��·��\n");
	}
	system("pause");
	return 0;
}