
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
int main()
{
	int zm = 0;
	int digtal = 0;
	int t = 0;
	int other = 0;
	char* p = (char*)malloc(sizeof(char)* 256);
	int i = 0;
	p = gets(p);
	while (*(p + i) != '\0')
	{
		if (*(p + i) == ' ')
		{
			t++;
		}
		else if ((*(p + i) >= 65 && *(p + i) <= 90) || (*(p + i) >= 97 && *(p + i) <= 122))
		{
			zm++;
		}
		else if (*(p + i) >= 48 && *(p + i) <= 57)
		{
			digtal++;
		}
		else
		{
			other++;
		}
		i++;
	}
	printf("字母：%d\n", zm);
	printf("数字：%d\n", digtal);
	printf("其他：%d\n", other);
	printf("空格：%d\n", t);
	while (1);
	return 0;
}
