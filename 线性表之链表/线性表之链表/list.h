#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
//��ͷ����
typedef int Data;
typedef struct _Node
{
	Data data;
	struct _Node* next;
}Node,List;

List* create_List();//ͷ���  ��������
Node* create_Node(int data);//�������
void Tail_list(List* list, Data data);//β��
void Front_list(List* list, Data data);//ͷ��
void insert_list(List* list, Data data, Data index);//ָ��λ�ú����
void deleteTail_list(List* list);//βɾ
void deleteFront_list(List* list);//ͷɾ
void deleteInsert_list(List* list, Data index);//ָ��ɾ��
void show_list(List* list);//��ʾ
bool empty(List* list);//�ж��Ƿ�Ϊ��
void sort(List** list);//����
void clean_list(List* list);//�������
void delete_list(List* list);//ɾ������
int size_list(List* list);//���㳤��
Node* find_list(List* list, Data data);//�ҵ�ָ��Ԫ�ز����ص�ַ
