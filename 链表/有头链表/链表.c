#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node* next;
};
//��ͷ
struct Node* createHead()
{
	struct Node* Nodehead = (struct Node*)malloc(sizeof(struct Node));
	Nodehead->next = NULL;
	return Nodehead;
}
//���
struct Node* createNode(int data)
{
	struct Node* Noded = (struct Node*)malloc(sizeof(struct Node));
	Noded->data = data;
	Noded->next = NULL;
	return Noded;
}
//ͷ������
void insertHeaders(struct Node* head, int data)
{
	struct Node* NodeDian = createNode(data);
	NodeDian->next = head->next;
	head->next = NodeDian;
}
//ָ�����
void addSpecify(struct Node* list, int data, int find)
{
	struct Node* ChaNode = list;
	struct Node* chaNode = list->next;
	while (chaNode->next!=NULL&&chaNode->data!=find)
	{
		ChaNode = chaNode;
		chaNode = ChaNode->next;
	}
	if (ChaNode->next == NULL)
	{
		printf("û�д˽��");
	}
	else
	{
		struct Node* NewNode = createNode(data);
		NewNode->next = chaNode;
		ChaNode->next = NewNode;
	}
}
//β
void insertFooter(struct Node* list, int data)
{
	struct Node* newNode = createNode(data);
	struct Node* movNode = list->next;
	while (movNode->next)
	{
		movNode = movNode->next;
	}
	movNode->next = newNode;
}
//ɾ��ָ���ڵ�
void DeleteNode(struct Node* list,int data)
{
	struct Node* Dode = list;
	struct Node* Dodet = list->next;
	while (Dodet->next!=NULL&&Dodet->data!=data)
	{
		Dode = Dodet;
		Dodet = Dode->next;
	}
	if (Dodet->next == NULL)
	{
		printf("û������ڵ�");
	}
	else
	{
		Dode->next = Dodet->next;
		free(Dodet);
		Dodet = NULL;
	}

}
//ɾ��ͷ���
void DeletnNodeHead(struct Node* list)
{
	struct Node* head = list;
	struct Node* Node = head->next;
	if (head->next == NULL)
	{
		printf("û������");
	}
	else
	{
		head->next = Node->next;
		free(Node);
		Node = NULL;
	}
}
//ɾ��β��
void deletFooter(struct Node* list)
{
	struct Node* Node = list;
	struct Node* Nodet = Node->next;
	if (Nodet == NULL)
	{
		printf("û������");
		return;
	}
	while (Nodet ->next!= NULL)
	{
		Node = Nodet;
		Nodet = Node->next;
	}
	Node->next = NULL;
	free(Nodet);
	Nodet = NULL;
}
//��ӡ
void PrintfList(struct Node* list)
{
	struct Node* PNode = list->next;
	while (PNode)
	{
		printf("%d-->",PNode->data);
		PNode = PNode->next;
	}
	printf("\n");
}
int main()
{
	int i = 0;                      
	struct Node* list = createHead();                       
	for (i = 0; i < 10; i++)
	{
		insertHeaders(list, i);//ͷ�巨�洢����0��1��2��3��4��5��6��7��8��9
	}
	PrintfList(list);          //��ӡ
	insertFooter(list,-100);   //β�巨�洢����
	PrintfList(list);          //��ӡ
	deletFooter(list);         //βɾ��
	PrintfList(list);          //��ӡ
	DeletnNodeHead(list);      //ͷɾ��
	PrintfList(list);          //��ӡ
	DeleteNode(list,5);        //ָ��ɾ��      
	PrintfList(list);          //��ӡ
	addSpecify(list, 3, -7);   //ָ�����
	PrintfList(list);          //��ӡ
	system("pause");
	return 0;
}