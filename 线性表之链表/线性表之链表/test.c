#include "list.h"

List* create_List()//头结点  代表链表
{
	List* list = (List*)calloc(1,sizeof(List));
	assert(list!=NULL);
	list->data = -1;//头结点一般不放数据
	list->next = NULL;
	return list;
}
Node* create_Node(int data)//创建结点
{
	Node* node = (Node*)calloc(1, sizeof(Node));
	assert(node != NULL);
	node->data = data;
	node->next = NULL;
	return node;
}
void Tail_list(List* list,Data data)//尾插
{
	Node* node = create_Node(data);
	while (list->next != NULL)//找尾巴
	{
		list = list->next;
	}
	list->next = node;
}
void Front_list(List* list, Data data)//头插
{
	Node* node = create_Node(data);
	node->next = list->next;
	list->next = node;
}
void show_list(List* list)//显示
{
	Node* rep= list->next;
	while (rep!= NULL)
	{
		printf("%d ",rep->data);
		rep = rep->next;
	}
}
void insert_list(List* list, Data data,Data index)//指定位置后插入
{
	if (empty(list))
	{
		printf("链表为空无法指定插入");
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
		printf("\n没有指定元素,插入失败\n");
	}
}
void deleteFront_list(List* list)//头删
{
	if (empty(list))
	{
		printf("链表为空无法删除");
		return;
	}
	Node* newNode = list->next;
	list->next = newNode->next;
	free(newNode);
}
void deleteTail_list(List* list)//尾删
{
	if (empty(list))
	{
		printf("链表为空无法删除");
		return;
	}
	Node* rep = list;
	Node* rep1 = list->next;
	while (rep1->next!= NULL)//找尾巴
	{
		rep = rep1;
		rep1 = rep1->next;
	}
	rep->next = NULL;
	free(rep1);
}
void deleteInsert_list(List* list, Data index)//指定数据删除
{
	if (empty(list))
	{
		printf("链表为空无法指定删除");
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
	//如果最后一个也是要删除的，那就删除在最后的指定数
	if (rep1->data == index)
	{
		rep->next = NULL;
		free(rep1);
	}
	//只是删一个
	/*if (empty(list))
	{
		printf("链表为空无法指定删除");
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
bool empty(List* list)//判断是否为空
{
	return list->next == NULL;
}
void sort(List** list)//排序
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
void clean_list(List* list)//清空链表
{
	if (empty(list))
	{
		printf("链表为空不用置空\n");
		return;
	}
	while (list->next != NULL)
	{
		deleteFront_list(list);
	}
}
void delete_list(List* list)//删除链表
{
	//先删了元素，再释放置空
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
Node* find_list(List* list,Data data)//找到指定元素并返回地址
{
	if (empty(list))
	{
		printf("\n链表为空\n");
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