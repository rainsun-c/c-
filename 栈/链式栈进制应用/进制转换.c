#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};
struct stack
{
	int size;
	struct Node* stacktop;
};
int count(struct stack* stack)
{
	return stack->size;
}
struct Node* createNode(int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
struct stack* createStack()
{
	struct stack* newStack = (struct stack*)malloc(sizeof(struct stack));
	newStack->size = 0;
	newStack->stacktop = NULL;
	return newStack;
}
void into(struct stack* stack, int data)
{
	struct Node* newNode = createNode(data);
	if (stack->size == 0)
	{
		stack->stacktop = newNode;
	}
	else
	{
		newNode->next = stack->stacktop;
		stack->stacktop = newNode;
	}
	stack->size++;
}
void pull(struct stack* stack)
{
	if (count(stack) == 0)
	{
		printf("这个栈还没有数据");
	}
	else
	{
		struct Node* newNode = stack->stacktop;
		stack->stacktop = newNode->next;
		free(newNode);
		newNode = NULL;
		stack->size--;
	}
}
void printfStack(struct stack* stack)
{
	struct Node* movNode = stack->stacktop;
	if (count(stack) == 0)
	{
		printf("这个栈还没有数据");
	}
	else
	{
		while (movNode)
		{
			if (movNode->data > 9)
			{
				movNode->data = movNode->data + 55;
				printf("%c", movNode->data);
			}
			else
			{
				printf("%d", movNode->data);
			}
			movNode = movNode->next;
		}
	}
	printf("\n");
}
void erjinzhi(struct stack* stack, int num)
{
	while (num)
	{
		into(stack, num % 2);
		num = num / 2;
	}
	printfStack(stack);
	while (count(stack))
	{
		pull(stack);
	}
}
void bajinzhi(struct stack* stack, int num)
{
	while (num)
	{
		into(stack, num % 8);
		num = num / 8;
	}
	printfStack(stack);
	while (count(stack))
	{
		pull(stack);
	}
}
void shiliujinzhi(struct stack* stack, int num)
{
	while (num)
	{
		into(stack, num % 16);
		num = num / 16;
	}
	printfStack(stack);
	while (count(stack))
	{
		pull(stack);
	}
}
int main()
{
	struct stack* stack = createStack();
	int select = 0;
	int num = 0;
	printf("选择转化的进制\n");
	printf("2、 选择二进制     8、 选择八进制    16、选择十六进制\n");
	do
	{
		scanf("%d", &select);
		switch (select)
		{
		case 0:
			printf("退出转换\n");
			break;
		case 2:
			scanf("%d", &num);
			erjinzhi(stack, num);
			break;
		case 8:
			scanf("%d", &num);
			bajinzhi(stack, num);
			break;
		case 16:
			scanf("%d", &num);
			shiliujinzhi(stack, num);
			break;
		default:
			printf("输入错误，请重新输入\n");
		}
	} while (select);
	system("pause");
	return 0;
}