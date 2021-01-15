#define sequence_max 10
#define sequence_add 5
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int Data;
typedef struct
{
	Data* base;
	int c_size;
	int capacity;
}sequence;
void init_sequence(sequence* list);//初始化顺序表
void show_sequence(sequence* list);//输出顺序表
void tail_sequence(sequence* list, Data data);//尾插入
void front_sequence(sequence* list, Data data);//头插入
void insert_sequence(sequence* list, Data data, Data index);//指定位置插入(位置index从0开始算)
void removTail_sequence(sequence* list);//尾删除
void removFront_sequence(sequence* list);//头删除
void removInsert_sequence(sequence* list, Data index);//指定 删除
void sort_sequence(sequence* list);//排序（按小到大）
void find(sequence* list, Data data);//查找指定数据
void removInsertData(sequence* list, Data data);//删除指定的全部数据
void move(sequence* list, Data c, Data p);//从后移动（哪里移到到哪里）
void moveFront(sequence* list, Data c, Data p);//从前移动（哪里移到到哪里）
int judge(sequence* list);//判断是否满了
int judge_size(sequence* list);//判断是有东西
void dilatation_sequence(sequence* list);//扩容