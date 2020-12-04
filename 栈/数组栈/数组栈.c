#define _CRT_SECURE_NO_WARNINGS
#define Max 15

#include <stdio.h>
#include <stdlib.h>
//ջ�ṹ��
struct Stack
{
	int* stack;
	int stacktop;
};
//����ջ
struct Stack* createStack()
{
	struct Stack* newStack = (struct Stack*)malloc(sizeof(struct Stack));
	newStack->stack = (int*)malloc(sizeof(int)*Max);
	newStack->stacktop = -1;
	return newStack;
}
//��ջ
void push(struct Stack* stack,int data)
{
	if (stack->stacktop + 1 == 15)
	{
		printf("ջ�Ѿ�����\n");
		return;
	}
	stack->stacktop++;
	stack->stack[stack->stacktop] = data;
	
}
//��ջ
void pop(struct Stack* stack, int* data)
{
	if (stack->stacktop ==-1)
	{
		printf("ջ�Ѿ�������\n");
		return;
	}
	*data = stack->stack[stack->stacktop];
	stack->stacktop--;
}
int main()
{
	//int stack[10] = { 0 };
	//int stacktop = -1;
	//int num = 200;
	//while (num)
	//{
	//	stack[++stacktop] = num % 2;
	//	num = num /2;
	//}
	//while (stacktop != -1)
	//{
	//  α��ջ����û��ɾ��
	//	printf("%d",stack[stacktop--]);
	//}

	int num = 100;
	struct Stack* stack = createStack();
	int data = 0;
	while(num)
	{
		push(stack,num%2);
		num = num / 2;
	}
	
	while (stack->stacktop!=-1)
	{
		//  α��ջ����û��ɾ��
		pop(stack,&data);
		printf("%d",data);
	}
	printf("\n");
	system("pause");
	return 0;
}