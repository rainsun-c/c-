#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#if 0
//1，自己实现strchr和strstr
char* my_strchr(char*p, char p1)
{
	assert(p != NULL);//断言，即p不等于NULL，如果是空则报错
	assert(p1 != NULL);
	while (*p!='\0')
	{
		if (*p == p1)
		{
			return p;
		}
		p++;
	}
	return (char*)-1;
}

char* my_strstr(char* p,char* p1)
{
	assert(p != NULL);
	assert(p1 != NULL);
	int count = 0;
	int size = 0;
	for ( ; *p1 != '\0'; p1++)
	{
		size++;
	}
	while (*p!= '\0'&&*p1!= '\0')
	{
		if (*p == *p1)
		{
			count++;
		}
		else
		{
			count = 0;
		}
		if (count == size)
		{
			return p+size;
		}
		p++;
		p1++;
	}
	return (char*)-1;
}
int main()
{
	char str1[] = "bakbvvnd";
	char str2[] = "ek";

	char* t=my_strstr(str1,str2);
	printf("%s\n", strstr(str1,str2));

	char* p=my_strchr(str1,'b');
	printf("%s", p);
	while (1);
	return 0;
}
#endif

#if 0
//比较strcmp
int my_strcmp(char* p,char* p1)
{
	assert(p != NULL);
	assert(p1 != NULL);
	while (*p != '\0'&&*p1 != '\0')
	{
		if (*p > *p1)
		{
			return 1;
		}
		if (*p < *p1)
		{
			return -1;
		}
		if (*p==*p1)
		{
			p++;
			p1++;
		}
	}
	return 0;
}

int main()
{
	char str[50] = "bsuksca";
	char str1[] = "sgvs";
	int temp = my_strcmp(str, str1);
	printf("%d", temp);
	/*int t=strcmp(str,str1);
	printf("%d",t);*/
	while (1);
	return 0;
}
#endif

#if 0
//字符串长度
int my_strlen(char* p)
{
	int count = 0;
	assert(p!=NULL);
	while (*p++!='\0')
	{
		count++;
	}
	return count;
}
int main()
{
	char str[] = "dsiuhas";
	int temp = my_strlen(str);
	printf("%d",temp);
	while (1);
	return 0;
}
#endif

#if 0
//字符串复制
char* my_strcpy(char* p, char* p1)
{
	char* t = p;
	assert(p != NULL);
	assert(p1 != NULL);
	while (*p1!='\0')
	{
		*p++=*p1++;
	}
	*p = '\0';
	return t;
}
int main()
{
	char str1[30] = "abcdest";
	char str2[23] = "qwer";
	char* temp=my_strcpy(str1,str2);
	printf("%s",temp);
	while (1);
	return 0;
}
#endif

#if 0
//字符串拼接
char* my_strcat(char* p,char* p1)
{
	char* temp = p;
	assert(p != NULL);
	assert(p1 != NULL);
	while (*p != '\0')
	{
		p++;
	}
	while (*p1)
	{
		*p = *p1;
		p++;
		p1++;
	}
	*p = '\0';
	return temp;
}
int main()
{
	char str1[20] = "fsgsew";
	char str2[] = "nbdal";
	my_strcat(str1, str2);
	puts(str1);
	while (1);
	return 0;
}
#endif