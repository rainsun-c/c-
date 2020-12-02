#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};
struct Node *list;
//�������
struct Node* createNode(int data)
{
	struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
	NewNode->data = data;
	NewNode->next = NULL;
	return NewNode;
}
//ͷ���
void createHead(struct Node**list, int data)
{
	struct Node* NewNode = createNode(data);
	NewNode->next = (*list);
	(*list) = NewNode;
}
//���ͷ���
void insertHeaders(struct Node** list, int data)
{
	struct Node* MoveNode = (*list);
	if ((*list) == NULL)
	{
		printf("û������\n");
		return;
	}
	else
	{
		struct Node* NewNode = createNode(data);
		NewNode->next = (*list);
		(*list) = NewNode;
	}
}
//���β�ڵ�
void insertFooter(struct Node** list, int data)
{
	struct Node* NewNode = (*list);
	if (NewNode == NULL)
	{
		printf("û������\n");
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
//ָ��λ��ǰ����
void addSpecify(struct Node** list, int data, int post)
{
	struct Node* MovNode = (*list);
	if (MovNode == NULL)
	{
		printf("û������\n");
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
			printf("û�������\n");
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
//ͷɾ
void DeletnNodeHead(struct Node** list)
{
	struct Node* newNode = (*list);
	if ((*list) == NULL)
	{
		printf("û������");
		return;
	}
	else
	{
		(*list)=newNode->next;
		free(newNode);
		newNode = NULL;
	}
}
//βɾ
void deletFooter(struct Node** list)
{
	struct Node* newNode = (*list);
	struct Node* newNodet = newNode->next;
	if (newNode == NULL)
	{
		printf("û������");
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
//ָ��ɾ��
void DeleteNode(struct Node** list, int data)
{
	struct Node* newNode = (*list);
	struct Node* newNodet = newNode->next;
	if (newNode == NULL)
	{
		printf("û������");
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
			printf("û���������");
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
//��ӡ����
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
	struct Node *list = NULL;  //ָ��ͷ���
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