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
data calculator( data a, data b,p1 p)//typedef data(*p1)(data a, data b);
{//typedef double data;
	return p(a,b);
}
int main()
{
	int a = 0;
	int b = 0;
	char c = 0;
	p1 p=NULL;       //typedef data(*p1)(data a, data b);
	puts("�����룺");
	scanf("%d %c %d",&a,&c,&b);
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
	data t=calculator(a,b,p);
	printf("%lf", t);
	while (1);
	return 0;
}
#endif
//����ָ������ʵ�ּ�����
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

int main()
{
	char c = '\0';
	int a = 0;
	int b = 0;
	p1 p[5] = { add, sub,ride, divs, mod };
	puts("�����룺");
	scanf("%d %c %d", &a, &c, &b);
	switch (c)
	{
	case '+':
		printf("%lf", (*p[0])(a,b));
		break;
	case '-':
		printf("%lf", (*p[1])(a, b));
		break;
	case '*':
		printf("%lf", (*p[2])(a, b));
		break;
	case '/':
		printf("%lf", (*p[3])(a, b));
		break;
	case '%':
		printf("%lf", (*p[4])(a, b));
		break;
	default:
		break;
	}
	while (1);
	return 0;
}