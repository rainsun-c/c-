#define _CRT_SECURE_NO_WARNINGS
#define Max 15

#include <stdio.h>
#include <stdlib.h>
//栈结构体
struct Stack
{
	int* stack;
	int stacktop;
};
//创建栈
struct Stack* createStack()
{
	struct Stack* newStack = (struct Stack*)malloc(sizeof(struct Stack));
	newStack->stack = (int*)malloc(sizeof(int)*Max);
	newStack->stacktop = -1;
	return newStack;
}
//入栈
void push(struct Stack* stack,int data)
{
	if (stack->stacktop + 1 == 15)
	{
		printf("栈已经满了\n");
		return;
	}
	stack->stacktop++;
	stack->stack[stack->stacktop] = data;
	
}
//出栈
void pop(struct Stack* stack, int* data)
{
	if (stack->stacktop ==-1)
	{
		printf("栈已经出完了\n");
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
	//  伪出栈，并没有删除
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
		//  伪出栈，并没有删除
		pop(stack,&data);
		printf("%d",data);
	}
	printf("\n");
	system("pause");
	return 0;
}