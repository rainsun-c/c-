#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* front;
	struct Node* tail;
};

////�������
struct Node* createNode(int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->front = NULL;
	newNode->tail = NULL;
	return newNode;
}
//��������
struct Node* LIST()
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->front = newNode;
	newNode->tail = newNode;
	return newNode;
}
//��ͷ����
void addNodeHead(struct Node* head,int data)
{
	struct Node* newNode = createNode(data);
	struct Node* frontNode = head->tail;

	head->tail = newNode;
	newNode->front = head;
	frontNode->front = newNode;
	newNode->tail = frontNode;

}
//β���
void addNodeLast(struct Node* head,int data)
{
	struct Node* newNode = createNode(data);
	struct Node* tailNode = head->front;

	tailNode->tail = newNode;
	newNode->front = tailNode;
	newNode->tail = head;
	head->front= newNode;
}
//ָ������
void insertNodeByAppoin(struct Node* head,int data,int posData)
{
	struct Node* posNode = head->tail;
	struct Node* posNodeLeft = head;
	if (head->front == head->tail)
	{
		printf("����ΪNULL���޷�����\n");
		return;
	}
	else
	{
		struct Node* posNode = head->tail;
		struct Node* posNodeLeft = head;
		while (posNode->data != posData)
		{
			posNodeLeft = posNode;
			posNode = posNodeLeft->tail;
			if (posNode == head)
			{
				printf("û���ҵ�ָ��λ�ã��޷�����\n");
					return;
			}
		}
		struct Node* newNode = createNode(data);
		posNodeLeft->tail = newNode;
		newNode->front = posNodeLeft;
		posNode->front = newNode;
		newNode->tail = posNode;
	}
}
//ͷ���ɾ��
void deleteNodeHead(struct Node* head)
{
	if (head->front == head->tail)
	{
		printf("����û������!\n");
		return;
	}
	struct Node* frontNode = head->tail;
	struct Node* nextNode = frontNode->tail;
	head->tail = nextNode;
	nextNode->front = head;
	free(frontNode);
	frontNode = NULL;
}
//β���
void deteleNodeLast(struct Node* head)
{
	if (head->front == head->tail)
	{
		printf("����û������!\n");
		return;
	}
	struct Node* tailNode = head->front;
	struct Node* nextNode = tailNode->front;
	head->front= nextNode;
	nextNode->tail = head;
	free(tailNode);
	tailNode = NULL;
}
//ָ��ɾ��
void assignNodedelete(struct Node* head,int postData)
{
	if (head->front == head->tail)
	{
		printf("����û������!\n");
		return;
	}
	struct Node* frontNode = head->tail;
	struct Node* nextNode = frontNode->tail;
	while (nextNode->data != postData)
	{
		frontNode = nextNode;
		nextNode = frontNode->tail;
		if (nextNode == head)
		{
			printf("û���������\n");
			return ; 
		}
	}
	struct Node* newNode = nextNode->tail;
	frontNode->tail = newNode;
	newNode->front = frontNode;
	free(nextNode);
	nextNode = NULL;
}
//��ӡ
void printfList(struct Node* head)
{
	if (head->front == head->tail)
	{
		printf("����Ϊ���޷���ӡ��\n");
		return;
	}
	else
	{
		struct Node* movNode = head->tail;
		while (movNode != head)
		{
			printf("%d->",movNode->data);
			movNode = movNode->tail;
		}
	}
	printf("\n");
}
int main()
{
	struct Node* head = LIST();
	addNodeLast(head, 1);
	addNodeLast(head, 2);
	addNodeLast(head, 3);
	addNodeLast(head, 4);
	addNodeHead(head,-10);
	insertNodeByAppoin(head,-10,1);
	printfList(head);
	deleteNodeHead(head);
	printfList(head);
	deteleNodeLast(head);
	printfList(head);
	assignNodedelete(head, 3);
	printfList(head);
	while (1);
	return 0;
}