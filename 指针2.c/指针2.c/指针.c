#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	指针int* p 可以进行*（p+i）， 但是不可以自加*(p++)自加就是会改变P指针的指向，
之后对它进行释放就会越界访问，释放不掉自己想要free的空间导致内存泄露。
每一次的增加和减小的步长都是由类型大小决定

内存:动态内存是指在堆上分配的内存，而静态内存是指在栈上分配的内存。
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
////动态内存分配
int main22()
{
	int* p = (int*)malloc(sizeof(int)* 4);//malloc
	if (p == NULL)
	{
		printf("申请失败\n");
		return -1;
	}
	memset(p,0,sizeof(int)*4);//内存设置
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", *(p+i));
	}
	int *p1 = calloc(3,sizeof(int));//calloc（个数，单位大小）自动初始化为0（与malloc一样）
	for (int i = 0; i < 3; i++)
	{
		printf("%d ", *(p1 + i));
	}

	p = realloc(p,sizeof(int)*6);//扩充空间，产生新的空间，返回值为指针。
	if (p == NULL)
	{
		printf("开辟失败");
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
		大端模式：数据的高字节保存在内存的低地址中，而数据的低字节保存在内存的高地址中
 这样的存储模式有点儿类似于把数据当作字符串顺序处理：地址由小向大增加，
而数据从高位往低位放；这种存放方式符合人类的正常思维

		小端模式：数据的高字节保存在内存的高地址中，而数据的低字节保存在内存的低地址中
 这种存储模式将地址的高低和数据位权有效地结合起来，高地址部分权值高，低地址部分权值低，和我们的逻辑方法一致。
*/

int main44()
{	//[ ]的优先级高于*
	int*p =(int*)malloc(sizeof(int)*3);
	for (int i = 0; i < 3; i++)
	{
		*(p + i)= 1;
	}
	printf("%d",*p++);//*++优先级一样先*p再p++
	while (1);
	return 0;
}
////数组指针（用来放数组的）
int main55()
{	//[ ]的优先级高于*	
	int a[3] = { 1, 4, 3 };
	int(* p)[3]=&a;            //指针数组 ；类型为int* [3]   数组指针对数组取地址
	printf("%d\n",*p);        //首地址
	printf("%d\n", **p);      //首元素1
	printf("%d",*(*p)+1);     //先（*p）=1然后1+1=2
	printf("%d", *((*p) + 1));//第二个数

	int b[2][3] = { 1,2,3,4,5,6 };
	int(* P2)[3]=b;                  //当指向二维数组时，不需要对数组名取地址,切记
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ",*(*(P2+i)+j));//确定行再确定列
		}
	}
	while (1);
	return 0;
}
//指针数组(每个元素都是指针的数组)
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