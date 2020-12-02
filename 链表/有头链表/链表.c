#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node* next;
};
//表头
struct Node* createHead()
{
	struct Node* Nodehead = (struct Node*)malloc(sizeof(struct Node));
	Nodehead->next = NULL;
	return Nodehead;
}
//结点
struct Node* createNode(int data)
{
	struct Node* Noded = (struct Node*)malloc(sizeof(struct Node));
	Noded->data = data;
	Noded->next = NULL;
	return Noded;
}
//头结点插入
void insertHeaders(struct Node* head, int data)
{
	struct Node* NodeDian = createNode(data);
	NodeDian->next = head->next;
	head->next = NodeDian;
}
//指定结点
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
		printf("没有此结点");
	}
	else
	{
		struct Node* NewNode = createNode(data);
		NewNode->next = chaNode;
		ChaNode->next = NewNode;
	}
}
//尾
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
//删除指定节点
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
		printf("没有这个节点");
	}
	else
	{
		Dode->next = Dodet->next;
		free(Dodet);
		Dodet = NULL;
	}

}
//删除头结点
void DeletnNodeHead(struct Node* list)
{
	struct Node* head = list;
	struct Node* Node = head->next;
	if (head->next == NULL)
	{
		printf("没有链表");
	}
	else
	{
		head->next = Node->next;
		free(Node);
		Node = NULL;
	}
}
//删除尾巴
void deletFooter(struct Node* list)
{
	struct Node* Node = list;
	struct Node* Nodet = Node->next;
	if (Nodet == NULL)
	{
		printf("没有链表");
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
//打印
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
		insertHeaders(list, i);//头插法存储数据0、1、2、3、4、5、6、7、8、9
	}
	PrintfList(list);          //打印
	insertFooter(list,-100);   //尾插法存储数据
	PrintfList(list);          //打印
	deletFooter(list);         //尾删法
	PrintfList(list);          //打印
	DeletnNodeHead(list);      //头删法
	PrintfList(list);          //打印
	DeleteNode(list,5);        //指定删除      
	PrintfList(list);          //打印
	addSpecify(list, 3, -7);   //指定添加
	PrintfList(list);          //打印
	system("pause");
	return 0;
}