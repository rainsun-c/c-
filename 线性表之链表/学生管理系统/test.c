#include "student.h"
//{
//	printf("*********************************\n");
//	printf("* [1]ѧ�����    [2]ѧ��ɾ��    *\n");
//	printf("* [3]��ʾȫ��    [4]�޸�        *\n");
//	printf("* [5]ѧ���Ǽ�    [6]����        *\n");
//	printf("* [7]������ʾ    [8]�鿴����    *\n");
//	printf("* [9]�˳�        [10]����       *\n");
//	printf("* [11]��ʾ�˵�   [12]ѧ������    *\n");
//	printf("*********************************\n");
//}
int main()
{
	muen();
	printf("\n ѧ��  ����  ѧ��  ����\n");
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
			//printf("������Ҫ��ӵ�ѧ����Ϣ,����-1����\n");
			//while ( scanf("%d", &h)&& h != -1)
			//{
			//	scanf("%s %s %d", m, x, &s);
			//	Tail_list(list, h, m, x, s);//ѧ���ɼ�¼��
			//}
			
			Tail_list(list, 1, "����", "��ѧ", 89);
			Tail_list(list, 4, "����", "��ѧ", 73);
			Tail_list(list, 9, "����", "��ѧ", 93);
			Tail_list(list, 3, "����", "��ѧ", 90);
			break;
		case 2:
			printf("������Ҫɾ����ѧ����Ϣ\n");
			scanf_s("%s\n",m);
			deleteInsert_list(list, m);//ָ��ѧ������ɾ��
			break;
		case 3:
			show_list(list);
			break;
		case 4:
			printf("������Ҫɾ����ѧ����Ϣ\n");
			scanf("%s %d\n", m, &s);
			alter_list(list,m, s);//�޸�
			break;
		case 5:
			printf("����Ҫ���ѧ����ѧ��������,����-1ֹͣ\n");
			while (scanf_s("%d", &h)&&h!=-1)
			{
				scanf_s("%s", m);
				regist_stu(list, h, m);
			}
			
			break;
		case 6:
			sort(&list);//����
			break;
		case 7:
			printf("������Ҫ��ʾ��ѧ����Ϣ\n");
			scanf_s("%s",m);
			alone_list(list,m);//������ʾ
			break;
		case 8:
			size = size_list(list);//ͳ������
			printf("\n����Ϊ%d\n", size);
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
			sort_num(&list);//����
			break;
			
		}
		
	}
	while (1);
	return 0;
}
//&(list->id), list->name, list->subject->subject_name, &(list->subject->subject_score)