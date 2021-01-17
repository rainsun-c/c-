#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
typedef int Data;
typedef struct//学科
{
	char subject_name[10];
	int subject_score;
}Subject;
typedef struct _student//学生
{
	char name[10];
	int id;
	Subject* subject;
	struct _student* next;
}Student;
//typedef struct//班级
//{
//	Student* stu;
//	int c_size;
//}sequence;

void muen();//菜单
Student* create_Node(int id, char name[10], char xuek[10], int score);//创建结点
void show_list(Student* list);//显示
Student* create_list();//创建链表
void Tail_list(Student* list, int id, char name[10], char xuek[10], int score);//尾插
void deleteInsert_list(Student* list, char name[10]);//指定学生名字删除
bool empty(Student* list);//判断是否为空
Student* find_list(Student* list, char name[10]);//找到指定元素并返回地址
void alter_list(Student* list, char name[10], int score);//修改
int size_list(Student* list);//统计人数
void sort(Student** list);//排序
void alone_list(Student* list, char name[10]);//单独显示
Student* create_stu(int id, char name[10]);//创建结点
void regist_stu(Student* list, int id, char name[10]);//添加成员
void sort_num(Student** list);//排序