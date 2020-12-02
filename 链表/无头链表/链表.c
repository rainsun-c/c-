#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};
struct Node *list;
//创建结点
struct Node* createNode(int data)
{
	struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
	NewNode->data = data;
	NewNode->next = NULL;
	return NewNode;
}
//头添加
void createHead(struct Node**list, int data)
{
	struct Node* NewNode = createNode(data);
	NewNode->next = (*list);
	(*list) = NewNode;
}
//添加头结点
void insertHeaders(struct Node** list, int data)
{
	struct Node* MoveNode = (*list);
	if ((*list) == NULL)
	{
		printf("没有链表\n");
		return;
	}
	else
	{
		struct Node* NewNode = createNode(data);
		NewNode->next = (*list);
		(*list) = NewNode;
	}
}
//添加尾节点
void insertFooter(struct Node** list, int data)
{
	struct Node* NewNode = (*list);
	if (NewNode == NULL)
	{
		printf("没有链表\n");
		return;
	}
	else
	{
		struct Node* NewNodeT = NewNode->next;
		while (NewNodeT)
		{
			NewNode = NewNodeT;
			NewNodeT = NewNode->next;
		}
		struct Node* wNodeTwo = createNode(data);
		NewNode->next = wNodeTwo;
	}
}
//指定位置前插入
void addSpecify(struct Node** list, int data, int post)
{
	struct Node* MovNode = (*list);
	if (MovNode == NULL)
	{
		printf("没有链表\n");
		return;
	}
	else
	{
		struct Node* MovNodeT = MovNode->next;
		while (MovNodeT!=NULL&&MovNodeT->data!=post)
		{
			MovNode = MovNodeT->next;
			MovNodeT = MovNode;
		}
		if (MovNodeT == NULL)
		{
			printf("没有这个数\n");
			return;
		}
		else
		{
			struct Node* NewNode = createNode(data);
			NewNode->next = MovNodeT->next;
			MovNodeT->next = NewNode;
		}
		
	}
}
//头删
void DeletnNodeHead(struct Node** list)
{
	struct Node* newNode = (*list);
	if ((*list) == NULL)
	{
		printf("没有链表");
		return;
	}
	else
	{
		(*list)=newNode->next;
		free(newNode);
		newNode = NULL;
	}
}
//尾删
void deletFooter(struct Node** list)
{
	struct Node* newNode = (*list);
	struct Node* newNodet = newNode->next;
	if (newNode == NULL)
	{
		printf("没有链表");
		return;
	}
	else
	{
		while (newNodet->next)
		{
			newNode = newNodet;
			newNodet = newNode->next;
		}
		newNode->next = NULL;
		free(newNodet);
		newNodet = NULL; 
	}
}
//指定删除
void DeleteNode(struct Node** list, int data)
{
	struct Node* newNode = (*list);
	struct Node* newNodet = newNode->next;
	if (newNode == NULL)
	{
		printf("没有链表");
		return;
	}
	else
	{
		while (newNodet->data!=data&&newNodet->next!=NULL)
		{
			newNode = newNodet;
			newNodet = newNode->next;
		}
		if (newNodet->next == NULL)
		{
			printf("没有这个数据");
			return;
		}
		else
		{
			newNode->next = newNodet->next ;
			free(newNodet);
			newNodet = NULL;
		}
	}
}
//打印链表
void printfList(struct Node** list)
{
	struct Node* New = (*list);
	while (New)
	{
		printf("%d\t", New->data);
		New = New->next;
	}
	printf("\n");
}
int main()
{	
	int i = 0;
	struct Node *list = NULL;  //指向头结点
	for (i = 0; i < 10; i++)
	{
		createHead(&list, i);
	}
	printfList(&list);
	DeleteNode(&list, 4);
	printfList(&list);

	while (1);
	return 0;
}