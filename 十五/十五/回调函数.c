#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef double data;
typedef data(*p1)(data a, data b);

#if 0
//������10��Ԫ�ص�����,�ֱ�ΪA��B,���ʵ����ͬ�±�B��Ԫ��С��A��Ԫ�صĽ���:(ʹ�ûص�����ʵ��)
void change(int* a,int* b)
{
	int temp = 0;
	if (*b < *a)
	{
		temp = *b;
		*b = *a;
		*a= temp;
	}
}
void all(int* p, int*c, void (*change)(int*, int*))
{
	for (int i = 0; i < 10; i++)
	{
		change(p, c);
		p++;
		c++;
	}
}
int main()
{
	int a[10] = {4,3,1,7,5,9,220,12,47,66};//b<a�򽻻�
	int b[10] = {6,1,4,8,12,34,5,75,324,2};
	all(a, b, change);
	for (int i = 0; i < 10; i++)
	{
		printf("%3d ",a[i]);
	}
	printf("\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%3d ", b[i]);
	}
	while (1);
	return 0;
}
#endif

#if 0
//�򵥼�������ʵ�֣��ص�������
data add(data a, data b)
{
	return (a + b);
}
data sub(data a, data b)
{
	return (a - b);
}
data ride(data a, data b)
{
	return (a*b);
}
data divs(data a, data b)
{

	return (a / b);
}
data mod(data a, data b)
{
	return ((int)a % (int)b);
}
data calculator(char c, data a, data b,data(*p)(data a, data b))
{
	switch (c)
	{
	case '+':
		p = add;
		break;
	case '-':
		p = sub;
		break;
	case '*':
		p = ride;
		break;
	case '/':
		p = divs;
		break;
	case '%':
		p = mod;
		break;
	default:
		break;
	}
	if (p == NULL)
		return -1;
	
	return p(a, b);
}
int main()
{
	int a = 0;
	int b = 0;
	char c = 0;
	p1 p=NULL;
	puts("�����룺");
	scanf("%d %c %d",&a,&c,&b);
	data t=calculator(c,a,b,p);
	printf("%lf", t);
	while (1);
	return 0;
}
#endif