#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node* next;
};
//����
struct List
{
	int size;
	struct Node* front;
	struct Node* last;
};
struct List* createList()
{
	struct List* newList = (struct List*)malloc(sizeof(struct List));
	newList->front = NULL;
	newList->last = NULL;
	newList->size = 0;
	return newList;
}
struct Node* crerateNode(int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->next = NULL;
	newNode->data = data;
	return newNode;
}
//ͷ���
void headNode(struct List* list,int data)
{
	struct Node* newNode = crerateNode(data);
	if (list->size == 0)
	{
		list->last = newNode;
	}
	else
	{
		newNode->next = list->front;
	}
	list->front = newNode;
	list->size++;
}
//β���
void lastNode(struct List* list, int data)
{
	struct Node* newNode = crerateNode(data);
	if (list->size == 0)
	{
		list->front = newNode;
		list->last = newNode;
	}
	else
	{
		list->last->next = newNode;
		list->last = newNode;
	}
	list->size++;
}
//ָ��λ��֮ǰ����(�ܲ�����ͷβ)
void assignNode(struct List* list, int data, int post)
{
	if (list->size == 0)
	{
		printf("��û����\n");
		return;
	}
	else
	{
		struct Node* findNode = list->front;
		struct Node* findNodet = findNode->next;
		while (findNodet->next != NULL&&findNodet->data != post)
		{
			findNode = findNodet;
			findNodet = findNode->next;
		}
		if (findNodet->next == NULL)
		{
			printf("û�������\n");
			return;
		}
		else
		{
			struct Node* newNode = crerateNode(data);
			newNode->next = findNodet;
			findNode->next = newNode;
			list->size++;
		}
	}
}
//ͷɾ��
void deleteNodehead(struct List* list)
{
	if (list->size == 0)
	{
		printf("��û����,����ɾ��\n");
		return;
	}
	else
	{
		struct Node* movNode = list->front;
		struct Node* movNodet = movNode->next;
		list->front = movNodet;
		list->size--;
		free(movNode);
		movNode = NULL;
	}
}
//βɾ��
void deleteLastNode(struct List* list)
{
	if (list->size == 0)
	{
		printf("��û����,����ɾ��\n");
		return;
	}
	else
	{
		struct Node* newNode = list->front;
		struct Node* newNodet = newNode->next;
		while (newNodet->next)
		{
			newNode = newNodet;
			newNodet = newNode->next;
		}
		newNode->next = NULL;
		list->last = newNode;
		free(newNodet);
		newNodet = NULL;
		list->size--;
	}
}
//ָ����ֵɾ��
void assignNodeMid(struct List* list,int post)
{
	if (list->size == 0)
	{
		printf("��û����,����ɾ��\n");
		return;
	}
	else
	{
		struct Node* movNode = list->front;
		struct Node* movNodet = movNode->next;
		while (movNodet->next!=NULL&&movNodet->data!=post)
		{
			movNode = movNodet;
			movNodet=movNode->next;
		}
		if (movNode->next == NULL)
		{
			printf("û��������ݣ��޷�ɾ��\n");
		}
		else
		{
			movNode->next = movNodet->next;
			free(movNodet);
			movNodet = NULL;
			list->size--;
		}
	}
}
//��ӡ
void printfList(struct List* list)
{
	struct Node* move = list->front;
	while (move)
	{
		printf("%d->",move->data);
		move = move->next;
	}
}
int main()
{
	struct List* List = createList();
	headNode(List, 1);
	headNode(List, 2);
	headNode(List, 3);
	headNode(List, 4);
	printfList(List);
	printf("\n");
	lastNode(List, 10);
	assignNode(List, -4, 3);
	printfList(List);
	printf("\n");
	deleteNodehead(List);
	printfList(List);
	printf("\n");
	deleteLastNode(List);
	printfList(List);
	printf("\n");
	assignNodeMid(List,2);
	printfList(List);
	printf("\n");
	while (1);
	return 0;
}