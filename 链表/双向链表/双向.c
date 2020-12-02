#include <stdio.h>
#include <stdlib.h>


//双向链表
struct Node
{
	int data;
	struct Node* first;
	struct Node* last;
};
struct List
{
	int size;
	struct Node* front;
	struct Node* tail;
};
//创建结点
struct Node* createNode(int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->first = NULL;
	newNode->last = NULL;
	return newNode;
}
//创建链表
struct List* LIST()
{
	struct List* newNode = (struct List*)malloc(sizeof(struct List));
	newNode->front = NULL;
	newNode->tail = NULL;
	newNode->size = 0;
	return newNode;
}
//头添加
void addNodehHead(struct List* list,int data)
{
	struct Node* newNode = createNode(data);
	if (list->size == 0)
	{
		list->front = newNode;
		list->tail = newNode;
	}
	else
	{
		newNode->last = list->front;
		list->front->first = newNode;
		list->front = newNode;
	}
	list->size++;
}
//尾添加
void addNodeLast(struct List* list, int data)
{
	struct Node* newNode = createNode(data);
	if (list->size == 0)
	{
		list->front = newNode;
		list->tail = newNode;
	}
	else
	{
		newNode->first = list->tail;
		list->tail->last = newNode;
		list->tail = newNode;
	}
	list->size++;
}
//指定插入
void assignNode(struct List* list,int data,int post)
{
	struct Node* newNode = createNode(data);
	if (list->size == 0)
	{
		list->front = newNode;
		list->tail = newNode;
	}
	else
	{
		struct Node* findNode = list->front;
		struct Node* findNodet = findNode->last;
		while (findNodet->last!=NULL&&findNodet->data!=post)
		{
			findNode = findNodet;
			findNodet = findNode->last;
		}
		if (findNode->last == NULL)
		{
			printf("没有该指定数据");
			return;
		}
		else
		{
			findNode->last = newNode;
			newNode->first = findNode;
			findNodet->first = newNode;
			newNode->last = findNodet;
			list->size++;
		}
		
	}
}
//头结点删除
void deleteNodeHead(struct List* list)
{
	if (list->size == 0)
	{
		printf("链表还没有数据\n");
		return;
	}
	else
	{
		struct Node* newNode = list->front;
		struct Node* newNodet = newNode->last;
		list->front = newNodet;
		newNodet->first = NULL;
		free(newNode);
		newNode = NULL;
		list->size--;
	}
}
//尾结点删除
void deleteNodeLast(struct List* list)
{
	if (list->size == 0)
	{
		printf("链表还没有数据\n");
		return;
	}
	else
	{
		struct Node* newNode = list->tail;
		struct Node* newNodet = newNode->first;
		list->tail = newNodet;
		newNodet->last = NULL;
		free(newNode);
		newNode = NULL;
		list->size--;
	}
}
//指定删除
void deleteAssignNode(struct List* list,int post)
{
	if (list->size == 0)
	{
		printf("链表还没有数据\n");
		return;
	}
	else
	{
		struct Node* newNode = list->front;
		struct Node* newNodet = newNode->last;
		while (newNodet->last != NULL&&newNodet->data != post)
		{
			newNode = newNodet;
			newNodet = newNode->last;
		}
		if (newNodet->last == NULL)
		{
			printf("链表中没有这个数\n");
			return ;
		}
		else
		{
			newNode->last = newNodet->last;
			newNodet->last->first = newNode->last;
			list->size--;
			free(newNodet);
			newNodet = NULL;
		}
	}
}
//打印
void firstPrintfList(struct List* list)
{
	
	if (list->size == 0)
	{
		printf("该链表没有数据");
		return;
	}
	else
	{
		struct Node* movNode = list->front;
		while (movNode)
		{
			printf("%d->",movNode->data);
			movNode = movNode->last;
		}
	}
	printf("\n");
}
void lastPrintfList(struct List* list)
{
	if (list->size == 0)
	{
		printf("该链表没有数据");
		return;
	}
	else
	{
		struct Node* movNode = list->tail;
		while (movNode)
		{
			printf("%d->", movNode->data);
			movNode = movNode->first;
		}
	}
	printf("\n");
}
int main()
{
	struct List* list = LIST();
	addNodehHead(list, 1);
	addNodehHead(list, 2);
	addNodehHead(list, 3);
	addNodehHead(list, 4);
	addNodehHead(list, 5);
	addNodeLast(list,-10);
	assignNode(list,-100,4);
	firstPrintfList(list);
	deleteNodeHead(list);
	firstPrintfList(list);
	deleteNodeLast(list);
	firstPrintfList(list);
	deleteAssignNode(list,2);
	firstPrintfList(list);
	while (1);
	return 0;
}