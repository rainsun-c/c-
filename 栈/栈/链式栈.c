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
	newStack->size=0;
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
		newNode->next=stack->stacktop;
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
			printf("%d",movNode->data);
			movNode = movNode->next;
		}
	}
	printf("\n");
}

int main()
{
	struct stack* stack = createStack();
		into(stack, 1);
		into(stack, 2);
		into(stack, 3);
		into(stack, 4);
		printfStack(stack);
		pull(stack);
		pull(stack);
		pull(stack);
		printfStack(stack);
	system("pause");
	return 0;
}