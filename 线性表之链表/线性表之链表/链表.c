#include "list.h"

int main()
{
	List* list = create_List();
	Tail_list(list, 7);//Î²²å
	for (int i = 0; i < 3; i++)
	{
		Tail_list(list, i);//Î²²å
	}
	Tail_list(list, 4);//Î²²å
	Tail_list(list, 34);//Î²²å
	Tail_list(list, 12);//Î²²å
	show_list(list);//ÏÔÊ¾
	putchar('\n');
	//insert_list(list, 4, 2);//Ö¸¶¨Î»ÖÃºó²åÈë
	//show_list(list);//ÏÔÊ¾
	//putchar('\n');	
	//deleteTail_list(list);//Î²É¾
	//show_list(list);//ÏÔÊ¾
	//
	//deleteFront_list(list);//Í·É¾
	deleteInsert_list(list,4);
	sort(&list);//ÅÅĞò
	Node*temp = find_list(list, 34);//ÕÒµ½Ö¸¶¨ÔªËØ²¢·µ»ØµØÖ·	
	printf("\n%d\n",&temp);
	
	show_list(list);//ÏÔÊ¾
	putchar('\n');
	printf("%d", size_list(list));
	clean_list(list);//Çå¿ÕÁ´±í
	
	show_list(list);//ÏÔÊ¾
	

	while (1);
	return 0;
}