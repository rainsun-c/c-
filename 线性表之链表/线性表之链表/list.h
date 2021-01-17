#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
//有头链表
typedef int Data;
typedef struct _Node
{
	Data data;
	struct _Node* next;
}Node,List;

List* create_List();//头结点  代表链表
Node* create_Node(int data);//创建结点
void Tail_list(List* list, Data data);//尾插
void Front_list(List* list, Data data);//头插
void insert_list(List* list, Data data, Data index);//指定位置后插入
void deleteTail_list(List* list);//尾删
void deleteFront_list(List* list);//头删
void deleteInsert_list(List* list, Data index);//指定删除
void show_list(List* list);//显示
bool empty(List* list);//判断是否为空
void sort(List** list);//排序
void clean_list(List* list);//清空链表
void delete_list(List* list);//删除链表
int size_list(List* list);//计算长度
Node* find_list(List* list, Data data);//找到指定元素并返回地址
