#include "seq.h"


int main()
{
	sequence sequence_list = {NULL};
	init_sequence(&sequence_list);
	//show_sequence(&sequence_list);
	//tail_sequence(&sequence_list, 2);//β����
	//tail_sequence(&sequence_list, 5);//β����
	//tail_sequence(&sequence_list, 7);//β����
	//show_sequence(&sequence_list);
	//front_sequence(&sequence_list, 6);//ͷ����
	//putchar('\n');
	//show_sequence(&sequence_list);
	//insert_sequence(&sequence_list, 9, 2);
	//putchar('\n');
	//show_sequence(&sequence_list);
	//removTail_sequence(&sequence_list);//βɾ��
	//putchar('\n');
	//show_sequence(&sequence_list);
	//removFront_sequence(&sequence_list);//ͷɾ��
	//putchar('\n');
	//show_sequence(&sequence_list);
	//removInsert_sequence(&sequence_list, 2);//ָ�� ɾ��
	//putchar('\n');
	//show_sequence(&sequence_list);
	//front_sequence(&sequence_list, 4);//ͷ����
	//front_sequence(&sequence_list, 4);//ͷ����
	//front_sequence(&sequence_list, 11);//ͷ����
	//find(&sequence_list, 4);//����ָ������
	//sort_sequence(&sequence_list);
	//putchar('\n');
	//show_sequence(&sequence_list);
	//find(&sequence_list,4);//����ָ������
	//removInsertData(&sequence_list, 4);//ɾ��ָ����ȫ������
	//putchar('\n');
	//show_sequence(&sequence_list);
	for (int i = 0; i < 10; i++)
	{
		tail_sequence(&sequence_list, i);//β����
	}
	show_sequence(&sequence_list);
	while (1);
	return 0;
}