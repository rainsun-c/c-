#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#if(0)
int main22()
{
	FILE *pFlie = fopen("./file.txt","w+");//����ֵΪ�ļ�ָ�� ����·�����ļ���������������������
	if (pFlie == NULL)					   //�ж��Ƿ�򿪳ɹ�
	{
		perror("����ԭ��: ");
		return 0;
	}
	else
	{
		printf("ok");
	}


	FILE *pnew; 
	int ret=fopen_s(&pnew,"./new.txt","w");//����ֵΪint,��������ָ��,��·�����ļ���������������������
	if (ret)                              //�ж��Ƿ�򿪳ɹ�
	{
		perror("����ԭ��: ");
		return -1;
	}
	else
	{
		printf("new");
	}

	fclose(pFlie);
	fclose(pnew);//�п���Ҫ�й�
	while (1);
	return 0;
}


//ÿ�ιر��ļ��ļ���ָ��ָ���Ƿ������µ����λ�ã�
int main()
{   //w�������򴴽������ڼ���գ�w+
	FILE *pFlie = fopen("./file.txt", "w+");//����ֵΪ�ļ�ָ�� ����·�����ļ���������������������
	if (pFlie == NULL)					   //�ж��Ƿ�򿪳ɹ�
	{
		perror("����ԭ��: ");
		while (1);
		return 0;
	}
	char a[256] = "";
	sprintf(a,"������������");
	fputs(a,pFlie);//���ļ�д��һ�� ���ַ���������ֱ���ַ���Ҳ������char����
				   //������2���ַ���������
	rewind(pFlie);//�ļ�ָ��ָ��ص���ʼλ��
	//char str[256] = "";
	//fgets(str,100,pFlie);//��ȡ�ļ�������̨��������ַ��������飬��ȡ���ȣ�Ҫ��ȡ���ļ���
	//printf("%s",str);
	
	//while (!feof(pFlie))	//feof(�ļ�)Ϊ��0ֵ��Ϊ����
	//{
	//	char ch;
	//	ch=fgetc(pFlie);		//�ַ����
	//	printf("%c",ch);
	//}
     char ch='0';
	do 
	{
		ch=fgetc(pFlie);		//�ַ����
		printf("%c",ch);
	} while (ch != EOF);    //EOF�Ƿ�������������
	printf("\n%d\n", EOF);
	while (1);
	return 0;
}

int main()
{   //w�������򴴽������ڼ���գ�w+
	FILE *pFlie = fopen("./file.txt", "w+");//����ֵΪ�ļ�ָ�� ����·�����ļ���������������������
	if (pFlie == NULL)					   //�ж��Ƿ�򿪳ɹ�
	{
		perror("����ԭ��: ");
		while (1);
		return 0;
	}
	char a[256] = "";
	gets_s(a,50);
	fputs(a,pFlie);
	rewind(pFlie);      
	while (!feof(pFlie))      //��ȡʱһ��Ҫ���ļ�ָ��ָ�򣬻ص���Ҫ��ӡ��λ��
							  //�ļ�ָ��ָ������һ���ո�
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
{   //w�������򴴽������ڼ���գ�w+
	FILE *pFlie = fopen("./file.txt", "w+");//����ֵΪ�ļ�ָ�� ����·�����ļ���������������������
	if (pFlie == NULL)					   //�ж��Ƿ�򿪳ɹ�
	{
		perror("����ԭ��: ");
		while (1);
		return 0;
	}
	/*char str1[255]="����ŮŮ";
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

int main(int argc,char* argv[])//�ļ�����
{   //argc�����в���Ŀ��argv�����в�����
	//FILE *pFlie = fopen("./file.txt", "w+");
	//if (pFlie == NULL)					  
	//{
	//	perror("����ԭ��: ");
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
		FILE* pd = fopen(argv[1],"r");  //�ļ�Ҫ���ڲſ��Ը���
		if (pd == NULL)
		{
			perror("�����ǣ�");
			return -1;
		}

		while (!feof(pd))
		{
			char buf[512] = {0};
			fgets(buf,512,pd);//��pd�ļ��е��ַ�����ȡ��buf��
			strcat(total,buf);//��buf���ַ����ŵ�total��
		}
		fclose(pd);

		FILE* pe = fopen(argv[2], "w");
		if (pe == NULL)
		{
			perror("����ԭ��:");
			return - 1;
		}
		int c=fputs(total,pe);//��total�е��ַ������Ƶ��ļ�pe��
		printf("%d\n",c);
		if (!c)			//�ж��Ƿ��Ƴɹ�
		{
			printf("���Ƴɹ�������\n");
		}
		fclose(pe);
	}
	while (1);
	return 0;
}
int main222(int argc, char* argv[])//ͼƬ���ƣ�����Ҳ���ԣ�
{
	char total[512] = { 0 };
	if (argc == 3)
	{
		FILE* pd = fopen(argv[1], "r");  //�ļ�Ҫ���ڲſ��Ը���
		if (pd == NULL)
		{
			perror("�����ǣ�");
			return -1;
		}

		FILE* pe = fopen(argv[2], "w");
		if (pe == NULL)
		{
			perror("����ԭ��:");
			return -1;
		}
		while (1)
		{   //һ���ַ�һ���ַ��ĸ��ƣ�Ȼ��������µ��ļ�
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
		{10200,273,"�յ���"},
		{ 1020, 273, "�յ���" },
		{ 1200, 73, "��" },
		{ 0200, 27, "����" }

	};
	FILE* pd = fopen("./������.txt", "wb");//�ļ�Ҫ���ڲſ��Ը���
		if (pd == NULL)
		{
			perror("�����ǣ�");
			return -1;
		}
		fwrite(G, sizeof(G),1, pd);// д��ȥ
		rewind(pd);
		fclose(pd);
		FILE* pe = fopen("./������.txt", "rb");
		if (pe == NULL)
		{
			perror("����ԭ��:");
			return -1;
		}
		struct H g[5] = { 0 };
		fread(g,sizeof(g),1,pe); //������
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
	
	FILE* pd = fopen("./������.txt", "wb");//�ļ�Ҫ���ڲſ��Ը���
	if (pd == NULL)
	{
		perror("�����ǣ�");
		return -1;
	}

	FILE* pe = fopen("./������.txt", "rb");
	if (pe == NULL)
	{
		perror("����ԭ��:");
		return -1;
	}


	fclose(pe);
	while (1);
	return 0;
}
