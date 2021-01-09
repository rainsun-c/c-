#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#if(0)
int main22()
{
	FILE *pFlie = fopen("./file.txt","w+");//返回值为文件指针 （“路径和文件名”，“操作条件”）
	if (pFlie == NULL)					   //判断是否打开成功
	{
		perror("错误原因: ");
		return 0;
	}
	else
	{
		printf("ok");
	}


	FILE *pnew; 
	int ret=fopen_s(&pnew,"./new.txt","w");//返回值为int,（传二级指针,“路径和文件名”，“操作条件”）
	if (ret)                              //判断是否打开成功
	{
		perror("错误原因: ");
		return -1;
	}
	else
	{
		printf("new");
	}

	fclose(pFlie);
	fclose(pnew);//有开就要有关
	while (1);
	return 0;
}


//每次关闭文件文件的指向指针是否又重新到最初位置？
int main()
{   //w不存在则创建，存在即清空，w+
	FILE *pFlie = fopen("./file.txt", "w+");//返回值为文件指针 （“路径和文件名”，“操作条件”）
	if (pFlie == NULL)					   //判断是否打开成功
	{
		perror("错误原因: ");
		while (1);
		return 0;
	}
	char a[256] = "";
	sprintf(a,"哈哈哈哈大了");
	fputs(a,pFlie);//向文件写入一个 ‘字符’，可以直接字符，也可以是char变量
				   //汉字是2个字符‘’不行
	rewind(pFlie);//文件指向指针回到初始位置
	//char str[256] = "";
	//fgets(str,100,pFlie);//读取文件到控制台，（存放字符串的数组，读取长度，要读取的文件）
	//printf("%s",str);
	
	//while (!feof(pFlie))	//feof(文件)为非0值（为正）
	//{
	//	char ch;
	//	ch=fgetc(pFlie);		//字符输出
	//	printf("%c",ch);
	//}
     char ch='0';
	do 
	{
		ch=fgetc(pFlie);		//字符输出
		printf("%c",ch);
	} while (ch != EOF);    //EOF是非正数（负数）
	printf("\n%d\n", EOF);
	while (1);
	return 0;
}

int main()
{   //w不存在则创建，存在即清空，w+
	FILE *pFlie = fopen("./file.txt", "w+");//返回值为文件指针 （“路径和文件名”，“操作条件”）
	if (pFlie == NULL)					   //判断是否打开成功
	{
		perror("错误原因: ");
		while (1);
		return 0;
	}
	char a[256] = "";
	gets_s(a,50);
	fputs(a,pFlie);
	rewind(pFlie);      
	while (!feof(pFlie))      //读取时一定要将文件指针指向，回到需要打印的位置
							  //文件指针指向会多退一个空格
	{
		char ch[256] = "";
		fgets(ch,100,pFlie);
		printf("%s",ch);
	}
	fclose(pFlie);
	while (1);
	return 0;
}

int main()
{   //w不存在则创建，存在即清空，w+
	FILE *pFlie = fopen("./file.txt", "w+");//返回值为文件指针 （“路径和文件名”，“操作条件”）
	if (pFlie == NULL)					   //判断是否打开成功
	{
		perror("错误原因: ");
		while (1);
		return 0;
	}
	/*char str1[255]="男男女女";
	char str2[234] = "skbfsj";*/
	char str1[255] = "";
	char str2[234] = "";
	gets(str1);
	gets(str2);
	fprintf_s(pFlie,"%s %s",str1,str2);
	/*fprintf(pFlie, "%s %s", str1, str2);*/
	rewind(pFlie);
	char str3[255] = "";
	char str4[234] = "";
	fscanf(pFlie,"%s %s",str3,str4);
	printf("%s\n%s",str3,str4);
	fclose(pFlie);
	while (1);
	return 0;
}

int main(int argc,char* argv[])//文件复制
{   //argc命令行参数目，argv命令行参数组
	//FILE *pFlie = fopen("./file.txt", "w+");
	//if (pFlie == NULL)					  
	//{
	//	perror("错误原因: ");
	//	while (1);
	//	return 0;
	//}

	//printf("%d",argc);
	//for (int i = 0; i < argc; i++)
	//{
	//	puts(argv[i]);
	//}
	char total[512] = { 0 };
	if (argc == 3)
	{
		FILE* pd = fopen(argv[1],"r");  //文件要存在才可以复制
		if (pd == NULL)
		{
			perror("错误是：");
			return -1;
		}

		while (!feof(pd))
		{
			char buf[512] = {0};
			fgets(buf,512,pd);//将pd文件中的字符串读取到buf中
			strcat(total,buf);//将buf的字符串放到total中
		}
		fclose(pd);

		FILE* pe = fopen(argv[2], "w");
		if (pe == NULL)
		{
			perror("错误原因:");
			return - 1;
		}
		int c=fputs(total,pe);//将total中的字符串复制到文件pe中
		printf("%d\n",c);
		if (!c)			//判断是否复制成功
		{
			printf("复制成功。。。\n");
		}
		fclose(pe);
	}
	while (1);
	return 0;
}
int main222(int argc, char* argv[])//图片复制（文字也可以）
{
	char total[512] = { 0 };
	if (argc == 3)
	{
		FILE* pd = fopen(argv[1], "r");  //文件要存在才可以复制
		if (pd == NULL)
		{
			perror("错误是：");
			return -1;
		}

		FILE* pe = fopen(argv[2], "w");
		if (pe == NULL)
		{
			perror("错误原因:");
			return -1;
		}
		while (1)
		{   //一个字符一个字符的复制，然后黏贴到新的文件
			char ch = fgetc(pd);
			fputc(ch, pe);
			if (feof(pd))
			{
				break;
			}
		}
		fclose(pd);
		fclose(pe);
	}
	while (1);
	return 0;
}
struct H
{
	int id;
	int age;
	char name[20];
};
int main()
{
	struct H G[5] = {
		{10200,273,"收到货"},
		{ 1020, 273, "收到货" },
		{ 1200, 73, "收" },
		{ 0200, 27, "到货" }

	};
	FILE* pd = fopen("./二进制.txt", "wb");//文件要存在才可以复制
		if (pd == NULL)
		{
			perror("错误是：");
			return -1;
		}
		fwrite(G, sizeof(G),1, pd);// 写进去
		rewind(pd);
		fclose(pd);
		FILE* pe = fopen("./二进制.txt", "rb");
		if (pe == NULL)
		{
			perror("错误原因:");
			return -1;
		}
		struct H g[5] = { 0 };
		fread(g,sizeof(g),1,pe); //读出来
		for (int i = 0; i < 5; i++)
		{
			printf("%d %d %s\n",g[i].age,g[i].id,g[i].name);
		}
		
		fclose(pe);
		while (1);
		return 0;
}
#endif

int main()
{
	
	FILE* pd = fopen("./二进制.txt", "wb");//文件要存在才可以复制
	if (pd == NULL)
	{
		perror("错误是：");
		return -1;
	}

	FILE* pe = fopen("./二进制.txt", "rb");
	if (pe == NULL)
	{
		perror("错误原因:");
		return -1;
	}


	fclose(pe);
	while (1);
	return 0;
}
