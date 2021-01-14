#include <stdio.h>
#include <stdlib.h>

//数组名取地址为int(*)[2]为整个数组类型
//二维数组名为int* 为；
//数组名所指向的类型是  数组元素的类型，而取数组名地址 所指向的类型是  这个数组本身的类型。

int main()
{
	int(*p)[4] = {NULL};
	int arr[4] = { 1, 2, 3, 4 };
	p = &arr;
	printf("%d %d %d %d\n", p, p + 1, p + 2, p + 3);//跳过整个数组
	printf("%d %d %d %d\n", &arr, &arr + 1, &arr + 2, &arr + 3);//每个元素地址
	printf("%d %d %d %d\n",arr,arr+1,arr+2,arr+3);//每个元素地址
	printf("%d %d %d %d\n", *p, *p + 1, *p + 2, *p + 3); //每个元素地址
	printf("%d %d %d %d\n", *arr, *(arr + 1),*( arr + 2), *(arr + 3));//对每个元素地址进行解引用，即取出该地址中的数据
	printf("%d %d %d %d\n",*(*p),*(*p+1),*(*p+2),*(*p+3));//对每个元素地址进行解引用，即取出该地址中的数据
	
	
	//二维数组的每个元素都是一维数组，所以最大的存储单元应该是一个指向一维数组的指针
	int(*pp)[4] = NULL;
	int str[2][4] = { 1, 2, 3, 4 ,5,6,7,8};
	pp = str;//int(*)[4]
	printf("%d %d\n",pp,pp+1);//跳过一个一维数组
	printf("%d\n",sizeof(str));
	printf("%p %p %p %p\n", str, str + 1, str + 2, str + 3);
	printf("%d %d %d %d\n", str, str + 1, str + 2, str + 3);
	printf("%d %d %d %d\n", *pp, (*pp + 1), (*pp + 2), (*pp + 3));
	printf("%d %d %d %d\n", **(pp+1), *(*(pp + 1) + 1), *(*(pp + 1) + 2), *(*(pp + 1) + 3));
	printf("%d %d %d %d\n", **pp, *(*pp + 1), *(*pp + 2), *(*pp + 3));
	//int(*ppp)[2][2] = NULL;
	//int b[2][2][2] = { { { 1, 2 }, { 3, 4 } }, { { 5, 6 }, { 7, 8 } } };
	//ppp = &str;//类型int*，存放的数组
	//printf("\n%d\n", *(*(*(ppp))));//取出
	while(1);
	return 0;
}
#if 0
//指针数组
int main()
{
	int* p[2] = { NULL };//指针数组中每一个都是指针，
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
			printf("开辟空间失败 %d",i);
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