#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	ָ��int* p ���Խ���*��p+i���� ���ǲ������Լ�*(p++)�ԼӾ��ǻ�ı�Pָ���ָ��
֮����������ͷžͻ�Խ����ʣ��ͷŲ����Լ���Ҫfree�Ŀռ䵼���ڴ�й¶��
ÿһ�ε����Ӻͼ�С�Ĳ������������ʹ�С����

�ڴ�:��̬�ڴ���ָ�ڶ��Ϸ�����ڴ棬����̬�ڴ���ָ��ջ�Ϸ�����ڴ档
*/
int main11()
{
	int* p;
	int num[3] = {0};
	p = num;
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d",(p+i));
	}
	for (int i = 0; i < 3; i++)
	{
		printf("%d ", num[i]);
	}
	while (1);
	return 0;
}
////��̬�ڴ����
int main22()
{
	int* p = (int*)malloc(sizeof(int)* 4);//malloc
	if (p == NULL)
	{
		printf("����ʧ��\n");
		return -1;
	}
	memset(p,0,sizeof(int)*4);//�ڴ�����
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", *(p+i));
	}
	int *p1 = calloc(3,sizeof(int));//calloc����������λ��С���Զ���ʼ��Ϊ0����mallocһ����
	for (int i = 0; i < 3; i++)
	{
		printf("%d ", *(p1 + i));
	}

	p = realloc(p,sizeof(int)*6);//����ռ䣬�����µĿռ䣬����ֵΪָ�롣
	if (p == NULL)
	{
		printf("����ʧ��");
		return -1;
	}
	*(p + 4) = 6;
	*(p + 5) = 8;
	printf("\n");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", *(p + i));
	}
	free(p);
	p = NULL;
	while (1);
	return 0;
}
union t
{
	int a;
	unsigned int b : 1;
};
int main33()
{
	union t T = { 20 };
	printf("%d",T.b);
	while (1);
	return 0;
}
/*
		���ģʽ�����ݵĸ��ֽڱ������ڴ�ĵ͵�ַ�У������ݵĵ��ֽڱ������ڴ�ĸߵ�ַ��
 �����Ĵ洢ģʽ�е�������ڰ����ݵ����ַ���˳������ַ��С������ӣ�
�����ݴӸ�λ����λ�ţ����ִ�ŷ�ʽ�������������˼ά

		С��ģʽ�����ݵĸ��ֽڱ������ڴ�ĸߵ�ַ�У������ݵĵ��ֽڱ������ڴ�ĵ͵�ַ��
 ���ִ洢ģʽ����ַ�ĸߵͺ�����λȨ��Ч�ؽ���������ߵ�ַ����Ȩֵ�ߣ��͵�ַ����Ȩֵ�ͣ������ǵ��߼�����һ�¡�
*/

int main44()
{	//[ ]�����ȼ�����*
	int*p =(int*)malloc(sizeof(int)*3);
	for (int i = 0; i < 3; i++)
	{
		*(p + i)= 1;
	}
	printf("%d",*p++);//*++���ȼ�һ����*p��p++
	while (1);
	return 0;
}
////����ָ�루����������ģ�
int main55()
{	//[ ]�����ȼ�����*	
	int a[3] = { 1, 4, 3 };
	int(* p)[3]=&a;            //ָ������ ������Ϊint* [3]   ����ָ�������ȡ��ַ
	printf("%d\n",*p);        //�׵�ַ
	printf("%d\n", **p);      //��Ԫ��1
	printf("%d",*(*p)+1);     //�ȣ�*p��=1Ȼ��1+1=2
	printf("%d", *((*p) + 1));//�ڶ�����

	int b[2][3] = { 1,2,3,4,5,6 };
	int(* P2)[3]=b;                  //��ָ���ά����ʱ������Ҫ��������ȡ��ַ,�м�
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ",*(*(P2+i)+j));//ȷ������ȷ����
		}
	}
	while (1);
	return 0;
}
//ָ������(ÿ��Ԫ�ض���ָ�������)
int main45()
{
	int *p[3] = { NULL };
	for (int i = 0; i < 3; i++)
	{
		p[i] = (int*)malloc(sizeof(int));
		/*memset(p[i],0,sizeof(int));*/
		*p[i] = i;
	}
	for (int i = 0; i < 3; i++)
	{
		printf("%d", *p[i]);
	}
	while (1);
	return 0;
}