#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
typedef int Data;
typedef struct//ѧ��
{
	char subject_name[10];
	int subject_score;
}Subject;
typedef struct _student//ѧ��
{
	char name[10];
	int id;
	Subject* subject;
	struct _student* next;
}Student;
//typedef struct//�༶
//{
//	Student* stu;
//	int c_size;
//}sequence;

void muen();//�˵�
Student* create_Node(int id, char name[10], char xuek[10], int score);//�������
void show_list(Student* list);//��ʾ
Student* create_list();//��������
void Tail_list(Student* list, int id, char name[10], char xuek[10], int score);//β��
void deleteInsert_list(Student* list, char name[10]);//ָ��ѧ������ɾ��
bool empty(Student* list);//�ж��Ƿ�Ϊ��
Student* find_list(Student* list, char name[10]);//�ҵ�ָ��Ԫ�ز����ص�ַ
void alter_list(Student* list, char name[10], int score);//�޸�
int size_list(Student* list);//ͳ������
void sort(Student** list);//����
void alone_list(Student* list, char name[10]);//������ʾ
Student* create_stu(int id, char name[10]);//�������
void regist_stu(Student* list, int id, char name[10]);//��ӳ�Ա
void sort_num(Student** list);//����