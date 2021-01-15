#include "seq.h"

void init_sequence(sequence* list)     //初始化
{
	list->capacity = sequence_max;
	list->base = (Data*)calloc(list->capacity, sizeof(int));
	list->c_size = 0;
	assert(list->base!=NULL);
}
void show_sequence(sequence* list)    //输出数据
{
	for (int i = 0; i < list->c_size; i++)
	{
		printf("%d ",list->base[i]);
	}
}
void tail_sequence(sequence* list, Data data)//尾插入
{
	assert(list != NULL);
#if 0
//自动扩容
	if (list->c_size >= list->capacity)
	{
		list->base = (Data*)realloc(list->base,sizeof(int)*sequence_max + sequence_add);
		if (list->base == NULL)
		{
			printf("内存不足，扩容失败\n");
			return -1;
		}
		list->capacity = list->capacity + sequence_add;
	}
#endif
	if (judge(list))
	{
		printf("\n容量不足\n");
		return ;
	}
	list->base[list->c_size] = data;
	list->c_size++;
}
void front_sequence(sequence* list, Data data)//头插入
{
#if 0
	//自动扩容
	if (list->c_size >= list->capacity)
	{
		list->base = (Data*)realloc(list->base, sizeof(int)*sequence_max + sequence_add);
		if (list->base == NULL)
		{
			printf("内存不足，扩容失败\n");
			return -1;
		}
		list->capacity = list->capacity + sequence_add;
	}
#endif
	if (judge(list))
	{
		printf("\n容量不足\n");
		return;
	}
	move(list,list->c_size-1,0);//从头开始移动要移动c_size-1次
	list->base[0] = data;
	list->c_size++;
}
void insert_sequence(sequence* list, Data data, Data index)//指定位置插入(位置pose从0开始算)
{
	if (judge(list))
	{
		printf("\n容量不足\n");
		return;
	}
	move(list, list->c_size -1,index);//从插入位置开始移动要移动c_size-index次(往后移动)
	list->base[index] = data;
	list->c_size++;
}
void removTail_sequence(sequence* list)//尾删除
{
	if (list->c_size == 0)
	{
		printf("\n没有元素不能删除\n");
		return ;
	}
	list->c_size--;
}
void removFront_sequence(sequence* list)//头删除
{
	if (list->c_size == 0)
	{
		printf("\n没有元素不能删除\n");
		return;
	}
	moveFront(list, 0, list->c_size - 1);
	list->c_size--;
}
void removInsert_sequence(sequence* list,Data index)//指定 删除
{
	if (list->c_size == 0)
	{
		printf("\n没有元素不能删除\n");
		return;
	}
	if (index > list->c_size || index < 0)
	{
		printf("\n位置选择有误，删除失败\n");
		return;
	}
	else
	{
		moveFront(list, index, list->c_size - 1);//将要删除位置覆盖 
		list->c_size--;
	}
}
int judge(sequence* list)//判断是否满了
{
	if (list->capacity <= list->c_size)
	{
		printf("\n容量不足\n");
		return 1;
	}
	return 0;
}
void sort_sequence(sequence* list)//排序（按小到大）
{

	for (int i = 0; i < list->c_size; i++)
	{
		for (int j = 0; j<list->c_size ; j++)
		{
			if (list->base[i]<list->base[j])
			{
				int temp = list->base[i];
				list->base[i] = list->base[j];
				list->base[j] = temp;
			}
		}
		
	}
}
void move(sequence* list,Data c,Data p)//（从哪里移到哪里）往后移动
{
	for (int i = c; i >=p; i--)
	{
		list->base[i + 1] = list->base[i];
	}
}
void moveFront(sequence* list, Data c, Data p)//（从哪里移到哪里）往前移动
{
	for (int i = c+1; i <= p; i++)
	{
		list->base[i - 1] = list->base[i];
	}
}
int judge_size(sequence* list)//判断是有东西
{
	if (list->c_size == 0)
	{
		return 1;
	}
	return 0;
}
void find(sequence* list, Data data)//查找指定数据
{
	if (judge_size(list))
	{
		printf("\n现在没有元素，无法查找\n");
		return;
	}
	int count = list->c_size;
	while (count)
	{
		if (list->base[count] == data)
		{
			printf("\n%d在%d的位置上\n",data,count);
		}
		count--;
	}
}
void removInsertData(sequence* list, Data data)//删除指定的全部数据
{
	if (judge_size(list))
	{
		printf("\n现在没有元素，无法删除\n");
		return;
	}
	for (int i = 0; i < list->c_size; i++)
	{
		if (list->base[i] == data)
		{
			moveFront(list, i, list->c_size - 1);
			list->c_size--;
			i--;
		}
	}
}
void dilatation_sequence(sequence* list)//扩容
{
	if (list->c_size >= list->capacity)
	{
		list->base = (Data*)realloc(list->base, sizeof(int)*sequence_max + sequence_add);
		if (list->base == NULL)
		{
			printf("内存不足，扩容失败\n");
			return ;
		}
		list->capacity = list->capacity + sequence_add;
	}
}