#include <stdio.h>
#include <stdlib.h>

//������ȡ��ַΪint(*)[2]Ϊ������������
//��ά������Ϊint* Ϊ��
//��������ָ���������  ����Ԫ�ص����ͣ���ȡ��������ַ ��ָ���������  ������鱾������͡�

int main()
{
	int(*p)[4] = {NULL};
	int arr[4] = { 1, 2, 3, 4 };
	p = &arr;
	printf("%d %d %d %d\n", p, p + 1, p + 2, p + 3);//������������
	printf("%d %d %d %d\n", &arr, &arr + 1, &arr + 2, &arr + 3);//ÿ��Ԫ�ص�ַ
	printf("%d %d %d %d\n",arr,arr+1,arr+2,arr+3);//ÿ��Ԫ�ص�ַ
	printf("%d %d %d %d\n", *p, *p + 1, *p + 2, *p + 3); //ÿ��Ԫ�ص�ַ
	printf("%d %d %d %d\n", *arr, *(arr + 1),*( arr + 2), *(arr + 3));//��ÿ��Ԫ�ص�ַ���н����ã���ȡ���õ�ַ�е�����
	printf("%d %d %d %d\n",*(*p),*(*p+1),*(*p+2),*(*p+3));//��ÿ��Ԫ�ص�ַ���н����ã���ȡ���õ�ַ�е�����
	
	
	//��ά�����ÿ��Ԫ�ض���һά���飬�������Ĵ洢��ԪӦ����һ��ָ��һά�����ָ��
	int(*pp)[4] = NULL;
	int str[2][4] = { 1, 2, 3, 4 ,5,6,7,8};
	pp = str;//int(*)[4]
	printf("%d %d\n",pp,pp+1);//����һ��һά����
	printf("%d\n",sizeof(str));
	printf("%p %p %p %p\n", str, str + 1, str + 2, str + 3);
	printf("%d %d %d %d\n", str, str + 1, str + 2, str + 3);
	printf("%d %d %d %d\n", *pp, (*pp + 1), (*pp + 2), (*pp + 3));
	printf("%d %d %d %d\n", **(pp+1), *(*(pp + 1) + 1), *(*(pp + 1) + 2), *(*(pp + 1) + 3));
	printf("%d %d %d %d\n", **pp, *(*pp + 1), *(*pp + 2), *(*pp + 3));
	//int(*ppp)[2][2] = NULL;
	//int b[2][2][2] = { { { 1, 2 }, { 3, 4 } }, { { 5, 6 }, { 7, 8 } } };
	//ppp = &str;//����int*����ŵ�����
	//printf("\n%d\n", *(*(*(ppp))));//ȡ��
	while(1);
	return 0;
}
#if 0
//ָ������
int main()
{
	int* p[2] = { NULL };//ָ��������ÿһ������ָ�룬
	int* a = NULL;
	int b = 6;
	a = &b;
	p[0] = a;
	printf("%d\n",*p);
	printf("%d\n",a);
	for (int i = 0; i < 2; i++)
	{
		p[i] = (int*)calloc(1,sizeof(int));
		if (p[i] == NULL)
		{
			printf("���ٿռ�ʧ�� %d",i);
			return -1;
		}
		*p[i] = i;
	}
	for (int i = 0; i < 2; i++)
	{
		printf("%d ",*p[i]);
	}
	while (1);
	return 0;
}
#endif