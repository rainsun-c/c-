#include <stdio.h>
#include <stdlib.h>

int main()
{
	int zm = 0;       //字母
	int digtal = 0;   //数字
	int t = 0;        //空格
	int other = 0;    //其他
	char a = 0;
	while ((a = getchar()) != '\n')
	{

		if (a >= 48 && a <= 57)
		{
			digtal++;
		}
		else
		if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122))
		{
			zm++;
		}
		else
		if (a == ' ')
		{
			t++;
		}
		else
			other++;
	}
		printf("字母：%d\n", zm);
		printf("数字：%d\n", digtal);
		printf("其他：%d\n", other);
		printf("空格：%d\n", t);
	while (1);
	return 0;
}

