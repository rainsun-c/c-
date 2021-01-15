#include "seq.h"


int main()
{
	sequence sequence_list = {NULL};
	init_sequence(&sequence_list);
	//show_sequence(&sequence_list);
	//tail_sequence(&sequence_list, 2);//尾插入
	//tail_sequence(&sequence_list, 5);//尾插入
	//tail_sequence(&sequence_list, 7);//尾插入
	//show_sequence(&sequence_list);
	//front_sequence(&sequence_list, 6);//头插入
	//putchar('\n');
	//show_sequence(&sequence_list);
	//insert_sequence(&sequence_list, 9, 2);
	//putchar('\n');
	//show_sequence(&sequence_list);
	//removTail_sequence(&sequence_list);//尾删除
	//putchar('\n');
	//show_sequence(&sequence_list);
	//removFront_sequence(&sequence_list);//头删除
	//putchar('\n');
	//show_sequence(&sequence_list);
	//removInsert_sequence(&sequence_list, 2);//指定 删除
	//putchar('\n');
	//show_sequence(&sequence_list);
	//front_sequence(&sequence_list, 4);//头插入
	//front_sequence(&sequence_list, 4);//头插入
	//front_sequence(&sequence_list, 11);//头插入
	//find(&sequence_list, 4);//查找指定数据
	//sort_sequence(&sequence_list);
	//putchar('\n');
	//show_sequence(&sequence_list);
	//find(&sequence_list,4);//查找指定数据
	//removInsertData(&sequence_list, 4);//删除指定的全部数据
	//putchar('\n');
	//show_sequence(&sequence_list);
	for (int i = 0; i < 10; i++)
	{
		tail_sequence(&sequence_list, i);//尾插入
	}
	show_sequence(&sequence_list);
	while (1);
	return 0;
}