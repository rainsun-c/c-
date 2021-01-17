#include "list.h"

List* create_List()//ͷ���  ��������
{
	List* list = (List*)calloc(1,sizeof(List));
	assert(list!=NULL);
	list->data = -1;//ͷ���һ�㲻������
	list->next = NULL;
	return list;
}
Node* create_Node(int data)//�������
{
	Node* node = (Node*)calloc(1, sizeof(Node));
	assert(node != NULL);
	node->data = data;
	node->next = NULL;
	return node;
}
void Tail_list(List* list,Data data)//β��
{
	Node* node = create_Node(data);
	while (list->next != NULL)//��β��
	{
		list = list->next;
	}
	list->next = node;
}
void Front_list(List* list, Data data)//ͷ��
{
	Node* node = create_Node(data);
	node->next = list->next;
	list->next = node;
}
void show_list(List* list)//��ʾ
{
	Node* rep= list->next;
	while (rep!= NULL)
	{
		printf("%d ",rep->data);
		rep = rep->next;
	}
}
void insert_list(List* list, Data data,Data index)//ָ��λ�ú����
{
	if (empty(list))
	{
		printf("����Ϊ���޷�ָ������");
		return ;
	}
	int p = 0;
	Node* node = create_Node(data);
	Node* rep = list;
	while (rep->next!=NULL)
	{
		if (rep->data == index)
		{
			p = 1;
			break;
		}
		rep = rep->next;
	}
	if (p == 1)
	{
		node->next = rep->next;
		rep->next = node;
	}
	else
	{
		printf("\nû��ָ��Ԫ��,����ʧ��\n");
	}
}
void deleteFront_list(List* list)//ͷɾ
{
	if (empty(list))
	{
		printf("����Ϊ���޷�ɾ��");
		return;
	}
	Node* newNode = list->next;
	list->next = newNode->next;
	free(newNode);
}
void deleteTail_list(List* list)//βɾ
{
	if (empty(list))
	{
		printf("����Ϊ���޷�ɾ��");
		return;
	}
	Node* rep = list;
	Node* rep1 = list->next;
	while (rep1->next!= NULL)//��β��
	{
		rep = rep1;
		rep1 = rep1->next;
	}
	rep->next = NULL;
	free(rep1);
}
void deleteInsert_list(List* list, Data index)//ָ������ɾ��
{
	if (empty(list))
	{
		printf("����Ϊ���޷�ָ��ɾ��");
		return;
	}
	Node* rep = list;
	Node* rep1 = list->next;
	while (rep1->next!= NULL)
	{
		if (rep1->data == index)
		{
			rep->next = rep1->next;
			free(rep1);
			rep1 = rep->next;
		}
		rep = rep1;
		rep1=rep1->next;
	}
	//������һ��Ҳ��Ҫɾ���ģ��Ǿ�ɾ��������ָ����
	if (rep1->data == index)
	{
		rep->next = NULL;
		free(rep1);
	}
	//ֻ��ɾһ��
	/*if (empty(list))
	{
		printf("����Ϊ���޷�ָ��ɾ��");
		return;
	}
	Node* rep = list;
	Node* rep1 = list->next;
	while (rep1->data != index&&rep1->next != NULL)
	{
		rep = rep1;
		rep1 = rep1->next;
	}
	rep->next = rep1->next;
	free(rep1);*/
}
bool empty(List* list)//�ж��Ƿ�Ϊ��
{
	return list->next == NULL;
}
void sort(List** list)//����
{
	for (Node* i = (*list)->next; i != NULL; )
	{
		for (Node* j = (*list)->next; j != NULL; )
		{
			if ((i->data) < (j->data))
			{
				int temp = (j->data);
				(j->data) = (i->data);
				(i->data) = temp;
			}
			j = j->next;
		}
		i = i->next;
	}
}
void clean_list(List* list)//�������
{
	if (empty(list))
	{
		printf("����Ϊ�ղ����ÿ�\n");
		return;
	}
	while (list->next != NULL)
	{
		deleteFront_list(list);
	}
}
void delete_list(List* list)//ɾ������
{
	//��ɾ��Ԫ�أ����ͷ��ÿ�
	clean_list(list);
	free(list);
	list = NULL;
}
int size_list(List* list)
{
	int size = 0;
	Node* rep = list;
	while (rep->next!=NULL)
	{
		rep = rep->next;
		size++;
	}
	return size;
}
Node* find_list(List* list,Data data)//�ҵ�ָ��Ԫ�ز����ص�ַ
{
	if (empty(list))
	{
		printf("\n����Ϊ��\n");
		return NULL;
	}
	Node* rep = list;
	Node* rep1 = list->next;
	while (rep1->next != NULL)
	{
		if (rep1->data == data)
		{
			return rep1;
		}
		rep = rep1;
		rep1 = rep1->next;
	}
	return NULL;
}