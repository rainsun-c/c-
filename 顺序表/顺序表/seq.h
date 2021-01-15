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
void init_sequence(sequence* list);//��ʼ��˳���
void show_sequence(sequence* list);//���˳���
void tail_sequence(sequence* list, Data data);//β����
void front_sequence(sequence* list, Data data);//ͷ����
void insert_sequence(sequence* list, Data data, Data index);//ָ��λ�ò���(λ��index��0��ʼ��)
void removTail_sequence(sequence* list);//βɾ��
void removFront_sequence(sequence* list);//ͷɾ��
void removInsert_sequence(sequence* list, Data index);//ָ�� ɾ��
void sort_sequence(sequence* list);//���򣨰�С����
void find(sequence* list, Data data);//����ָ������
void removInsertData(sequence* list, Data data);//ɾ��ָ����ȫ������
void move(sequence* list, Data c, Data p);//�Ӻ��ƶ��������Ƶ������
void moveFront(sequence* list, Data c, Data p);//��ǰ�ƶ��������Ƶ������
int judge(sequence* list);//�ж��Ƿ�����
int judge_size(sequence* list);//�ж����ж���
void dilatation_sequence(sequence* list);//����