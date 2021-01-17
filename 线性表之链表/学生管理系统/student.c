#include "student.h"

void muen()//菜单
{
	printf("*********************************\n");
	printf("* [1]学生添加    [2]学生删除    *\n");
	printf("* [3]显示全部    [4]修改        *\n");
	printf("* [5]学生登记    [6]排序        *\n");
	printf("* [7]单独显示    [8]查看人数    *\n");
	printf("* [9]退出        [10]清屏       *\n");
	printf("* [11]显示菜单   [12]学号排序    *\n");
	printf("*********************************\n");
}
Student* create_Node(int id, char name[10], char xuek[10], int score)//创建结点
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
Student* create_list()//创建链表
{
	Student* stu = (Student*)calloc(1, sizeof(Student));
	assert(stu != NULL);
	stu->next = NULL;
	return stu;
}
void show_list(Student* list)//显示
{
	Student* rep = list->next;
	printf("\n 学号     姓 名    学 科    分数\n");
	while (rep != NULL)
	{
		printf("  %-3d     %-3s     %-3s      %-3d\n", rep->id, rep->name, rep->subject->subject_name, rep->subject->subject_score);
		rep = rep->next;
	}
}
void Tail_list(Student* list, int id, char name[10], char xuek[10], int score)//尾插
{
	Student* node = create_Node(id,name,xuek,score);
	while (list->next != NULL)//找尾巴
	{
		list = list->next;
	}
	list->next = node;
}
void deleteInsert_list(Student* list, char name[10])//指定学生名字删除
{
	if (empty(list))
	{
	printf("链表为空无法指定删除");
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
bool empty(Student* list)//判断是否为空
{
	return list->next == NULL;
}
void alter_list(Student* list, char name[10], int score)//修改
{
	Student* t = find_list(list, name);//找到指定元素并返回地址
	t->subject->subject_score = score;
}
void alone_list(Student* list, char name[10])//单独显示
{
	Student* rep = find_list(list, name);
	printf("\n 学号     姓名    学科    分数\n");
	printf("  %-3d     %-3s     %-3s    %-3d\n", rep->id, rep->name, rep->subject->subject_name, rep->subject->subject_score);
}
Student* find_list(Student* list, char name[10])//找到指定元素并返回地址
{
	if (empty(list))
	{
		printf("\n链表为空\n");
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
int size_list(Student* list)//统计人数
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
void sort(Student** list)//成绩排序
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
void sort_num(Student** list)//学号排序
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
	while (list->next != NULL)//找尾巴
	{
		list = list->next;
	}
	list->next = node;
}

Student* create_stu(int id, char name[10])//创建结点
{
	Student* stu = (Student*)calloc(1, sizeof(Student));
	assert(stu != NULL);
	stu->id = id;
	strcpy_s(stu->name, 10, name);
	stu->next = NULL;
	stu->subject = (Subject*)calloc(1, sizeof(Subject));
	assert(stu->subject != NULL);
	strcpy_s(stu->subject->subject_name, 10,"数学");
	stu->subject->subject_score = 0;
	return stu;
}