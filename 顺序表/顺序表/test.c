#include "seq.h"

void init_sequence(sequence* list)     //��ʼ��
{
	list->capacity = sequence_max;
	list->base = (Data*)calloc(list->capacity, sizeof(int));
	list->c_size = 0;
	assert(list->base!=NULL);
}
void show_sequence(sequence* list)    //�������
{
	for (int i = 0; i < list->c_size; i++)
	{
		printf("%d ",list->base[i]);
	}
}
void tail_sequence(sequence* list, Data data)//β����
{
	assert(list != NULL);
#if 0
//�Զ�����
	if (list->c_size >= list->capacity)
	{
		list->base = (Data*)realloc(list->base,sizeof(int)*sequence_max + sequence_add);
		if (list->base == NULL)
		{
			printf("�ڴ治�㣬����ʧ��\n");
			return -1;
		}
		list->capacity = list->capacity + sequence_add;
	}
#endif
	if (judge(list))
	{
		printf("\n��������\n");
		return ;
	}
	list->base[list->c_size] = data;
	list->c_size++;
}
void front_sequence(sequence* list, Data data)//ͷ����
{
#if 0
	//�Զ�����
	if (list->c_size >= list->capacity)
	{
		list->base = (Data*)realloc(list->base, sizeof(int)*sequence_max + sequence_add);
		if (list->base == NULL)
		{
			printf("�ڴ治�㣬����ʧ��\n");
			return -1;
		}
		list->capacity = list->capacity + sequence_add;
	}
#endif
	if (judge(list))
	{
		printf("\n��������\n");
		return;
	}
	move(list,list->c_size-1,0);//��ͷ��ʼ�ƶ�Ҫ�ƶ�c_size-1��
	list->base[0] = data;
	list->c_size++;
}
void insert_sequence(sequence* list, Data data, Data index)//ָ��λ�ò���(λ��pose��0��ʼ��)
{
	if (judge(list))
	{
		printf("\n��������\n");
		return;
	}
	move(list, list->c_size -1,index);//�Ӳ���λ�ÿ�ʼ�ƶ�Ҫ�ƶ�c_size-index��(�����ƶ�)
	list->base[index] = data;
	list->c_size++;
}
void removTail_sequence(sequence* list)//βɾ��
{
	if (list->c_size == 0)
	{
		printf("\nû��Ԫ�ز���ɾ��\n");
		return ;
	}
	list->c_size--;
}
void removFront_sequence(sequence* list)//ͷɾ��
{
	if (list->c_size == 0)
	{
		printf("\nû��Ԫ�ز���ɾ��\n");
		return;
	}
	moveFront(list, 0, list->c_size - 1);
	list->c_size--;
}
void removInsert_sequence(sequence* list,Data index)//ָ�� ɾ��
{
	if (list->c_size == 0)
	{
		printf("\nû��Ԫ�ز���ɾ��\n");
		return;
	}
	if (index > list->c_size || index < 0)
	{
		printf("\nλ��ѡ������ɾ��ʧ��\n");
		return;
	}
	else
	{
		moveFront(list, index, list->c_size - 1);//��Ҫɾ��λ�ø��� 
		list->c_size--;
	}
}
int judge(sequence* list)//�ж��Ƿ�����
{
	if (list->capacity <= list->c_size)
	{
		printf("\n��������\n");
		return 1;
	}
	return 0;
}
void sort_sequence(sequence* list)//���򣨰�С����
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
void move(sequence* list,Data c,Data p)//���������Ƶ���������ƶ�
{
	for (int i = c; i >=p; i--)
	{
		list->base[i + 1] = list->base[i];
	}
}
void moveFront(sequence* list, Data c, Data p)//���������Ƶ������ǰ�ƶ�
{
	for (int i = c+1; i <= p; i++)
	{
		list->base[i - 1] = list->base[i];
	}
}
int judge_size(sequence* list)//�ж����ж���
{
	if (list->c_size == 0)
	{
		return 1;
	}
	return 0;
}
void find(sequence* list, Data data)//����ָ������
{
	if (judge_size(list))
	{
		printf("\n����û��Ԫ�أ��޷�����\n");
		return;
	}
	int count = list->c_size;
	while (count)
	{
		if (list->base[count] == data)
		{
			printf("\n%d��%d��λ����\n",data,count);
		}
		count--;
	}
}
void removInsertData(sequence* list, Data data)//ɾ��ָ����ȫ������
{
	if (judge_size(list))
	{
		printf("\n����û��Ԫ�أ��޷�ɾ��\n");
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
void dilatation_sequence(sequence* list)//����
{
	if (list->c_size >= list->capacity)
	{
		list->base = (Data*)realloc(list->base, sizeof(int)*sequence_max + sequence_add);
		if (list->base == NULL)
		{
			printf("�ڴ治�㣬����ʧ��\n");
			return ;
		}
		list->capacity = list->capacity + sequence_add;
	}
}