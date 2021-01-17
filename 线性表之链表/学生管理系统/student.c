#include "student.h"

void muen()//�˵�
{
	printf("*********************************\n");
	printf("* [1]ѧ�����    [2]ѧ��ɾ��    *\n");
	printf("* [3]��ʾȫ��    [4]�޸�        *\n");
	printf("* [5]ѧ���Ǽ�    [6]����        *\n");
	printf("* [7]������ʾ    [8]�鿴����    *\n");
	printf("* [9]�˳�        [10]����       *\n");
	printf("* [11]��ʾ�˵�   [12]ѧ������    *\n");
	printf("*********************************\n");
}
Student* create_Node(int id, char name[10], char xuek[10], int score)//�������
{
	Student* stu = (Student*)calloc(1, sizeof(Student));
	assert(stu != NULL);
	stu->id = id;
	strcpy_s(stu->name,10,name);
	stu->next = NULL;
	stu->subject = (Subject*)calloc(1, sizeof(Subject));
	assert(stu->subject!= NULL);
	strcpy_s(stu->subject->subject_name,10, xuek);
	stu->subject->subject_score = score;
	return stu;
}
Student* create_list()//��������
{
	Student* stu = (Student*)calloc(1, sizeof(Student));
	assert(stu != NULL);
	stu->next = NULL;
	return stu;
}
void show_list(Student* list)//��ʾ
{
	Student* rep = list->next;
	printf("\n ѧ��     �� ��    ѧ ��    ����\n");
	while (rep != NULL)
	{
		printf("  %-3d     %-3s     %-3s      %-3d\n", rep->id, rep->name, rep->subject->subject_name, rep->subject->subject_score);
		rep = rep->next;
	}
}
void Tail_list(Student* list, int id, char name[10], char xuek[10], int score)//β��
{
	Student* node = create_Node(id,name,xuek,score);
	while (list->next != NULL)//��β��
	{
		list = list->next;
	}
	list->next = node;
}
void deleteInsert_list(Student* list, char name[10])//ָ��ѧ������ɾ��
{
	if (empty(list))
	{
	printf("����Ϊ���޷�ָ��ɾ��");
	return;
	}
	Student* rep = list;
	Student* rep1 = list->next;
	while (strcmp(rep1->name,name)&&rep1->next != NULL)
	{
	rep = rep1;
	rep1 = rep1->next;
	}
	rep->next = rep1->next;
	free(rep1);
}
bool empty(Student* list)//�ж��Ƿ�Ϊ��
{
	return list->next == NULL;
}
void alter_list(Student* list, char name[10], int score)//�޸�
{
	Student* t = find_list(list, name);//�ҵ�ָ��Ԫ�ز����ص�ַ
	t->subject->subject_score = score;
}
void alone_list(Student* list, char name[10])//������ʾ
{
	Student* rep = find_list(list, name);
	printf("\n ѧ��     ����    ѧ��    ����\n");
	printf("  %-3d     %-3s     %-3s    %-3d\n", rep->id, rep->name, rep->subject->subject_name, rep->subject->subject_score);
}
Student* find_list(Student* list, char name[10])//�ҵ�ָ��Ԫ�ز����ص�ַ
{
	if (empty(list))
	{
		printf("\n����Ϊ��\n");
		return NULL;
	}
	Student* rep = list;
	Student* rep1 = list->next;
	while (rep1->next != NULL)
	{
		if (!strcmp(rep1->name,name))
		{
			return rep1;
		}
		rep = rep1;
		rep1 = rep1->next;
	}
	return NULL;
}
int size_list(Student* list)//ͳ������
{
	int size = 0;
	Student* rep = list;
	while (rep->next != NULL)
	{
		rep = rep->next;
		size++;
	}
	return size;
}
void sort(Student** list)//�ɼ�����
{
	for (Student* i = (*list)->next; i != NULL;)
	{
		for (Student* j = (*list)->next; j != NULL;)
		{
			if ((i->subject->subject_score) > (j->subject->subject_score))
			{
				int temp = (j->subject->subject_score);
				(j->subject->subject_score) = (i->subject->subject_score);
				(i->subject->subject_score) = temp;
			}
			j = j->next;
		}
		i = i->next;
	}
}
void sort_num(Student** list)//ѧ������
{
	for (Student* i = (*list)->next; i != NULL;)
	{
		for (Student* j = (*list)->next; j != NULL;)
		{
			if ((i->id) < (j->id))
			{
				int temp = (j->id);
				(j->id) = (i->id);
				(i->id) = temp;
			}
			j = j->next;
		}
		i = i->next;
	}
}
void regist_stu(Student* list,int id,char name[10])
{
	Student* node = create_stu(id, name);
	while (list->next != NULL)//��β��
	{
		list = list->next;
	}
	list->next = node;
}

Student* create_stu(int id, char name[10])//�������
{
	Student* stu = (Student*)calloc(1, sizeof(Student));
	assert(stu != NULL);
	stu->id = id;
	strcpy_s(stu->name, 10, name);
	stu->next = NULL;
	stu->subject = (Subject*)calloc(1, sizeof(Subject));
	assert(stu->subject != NULL);
	strcpy_s(stu->subject->subject_name, 10,"��ѧ");
	stu->subject->subject_score = 0;
	return stu;
}