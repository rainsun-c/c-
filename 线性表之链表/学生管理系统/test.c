#include "student.h"
//{
//	printf("*********************************\n");
//	printf("* [1]学生添加    [2]学生删除    *\n");
//	printf("* [3]显示全部    [4]修改        *\n");
//	printf("* [5]学生登记    [6]排序        *\n");
//	printf("* [7]单独显示    [8]查看人数    *\n");
//	printf("* [9]退出        [10]清屏       *\n");
//	printf("* [11]显示菜单   [12]学号排序    *\n");
//	printf("*********************************\n");
//}
int main()
{
	muen();
	printf("\n 学号  姓名  学科  分数\n");
	Student* list = create_list();
	int size = 0;
	int select = -1;
	int p = 0;
	int h = 0, s = 0;
	char m[10]=" ", x[10]=" ";
	while (1)
	{
		printf("select>");
		scanf_s("%d", &select);
		switch (select)
		{
		case 1:
			//printf("请输入要添加的学生信息,遇到-1结束\n");
			//while ( scanf("%d", &h)&& h != -1)
			//{
			//	scanf("%s %s %d", m, x, &s);
			//	Tail_list(list, h, m, x, s);//学生成绩录入
			//}
			
			Tail_list(list, 1, "张三", "数学", 89);
			Tail_list(list, 4, "李四", "数学", 73);
			Tail_list(list, 9, "王五", "数学", 93);
			Tail_list(list, 3, "函数", "数学", 90);
			break;
		case 2:
			printf("请输入要删除的学生信息\n");
			scanf_s("%s\n",m);
			deleteInsert_list(list, m);//指定学生名字删除
			break;
		case 3:
			show_list(list);
			break;
		case 4:
			printf("请输入要删除的学生信息\n");
			scanf("%s %d\n", m, &s);
			alter_list(list,m, s);//修改
			break;
		case 5:
			printf("请输要添加学生的学号与姓名,遇到-1停止\n");
			while (scanf_s("%d", &h)&&h!=-1)
			{
				scanf_s("%s", m);
				regist_stu(list, h, m);
			}
			
			break;
		case 6:
			sort(&list);//排序
			break;
		case 7:
			printf("请输入要显示的学生信息\n");
			scanf_s("%s",m);
			alone_list(list,m);//单独显示
			break;
		case 8:
			size = size_list(list);//统计人数
			printf("\n人数为%d\n", size);
			break;
		case 9:
			exit(0);
			break;
		case 10:
			system("cls");
			break;
		case 11:
			muen();
			break;
		case 12:
			sort_num(&list);//排序
			break;
			
		}
		
	}
	while (1);
	return 0;
}
//&(list->id), list->name, list->subject->subject_name, &(list->subject->subject_score)