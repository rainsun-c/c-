#include "list.h"

int main()
{
	List* list = create_List();
	Tail_list(list, 7);//β��
	for (int i = 0; i < 3; i++)
	{
		Tail_list(list, i);//β��
	}
	Tail_list(list, 4);//β��
	Tail_list(list, 34);//β��
	Tail_list(list, 12);//β��
	show_list(list);//��ʾ
	putchar('\n');
	//insert_list(list, 4, 2);//ָ��λ�ú����
	//show_list(list);//��ʾ
	//putchar('\n');	
	//deleteTail_list(list);//βɾ
	//show_list(list);//��ʾ
	//
	//deleteFront_list(list);//ͷɾ
	deleteInsert_list(list,4);
	sort(&list);//����
	Node*temp = find_list(list, 34);//�ҵ�ָ��Ԫ�ز����ص�ַ	
	printf("\n%d\n",&temp);
	
	show_list(list);//��ʾ
	putchar('\n');
	printf("%d", size_list(list));
	clean_list(list);//�������
	
	show_list(list);//��ʾ
	

	while (1);
	return 0;
}