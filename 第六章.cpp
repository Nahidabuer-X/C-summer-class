#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>


/*
 数组:多个同类型的数据
  定义:类型 数组名[长度]
 初始化:在定义的同时,赋值(经常考试),只初始化一部分则剩余部分为0
 数组长度是否可以是变量?
 编译器不一定完全遵循标准
 如何使用数组元素?
	 通过下标访问,下标从0开始,例如arr[2] = 10;
	 下标可以使用变量吗?可以
	 [数字]:这个数字,在定义时表示数组长度(前面有类型),使用时表示下标(前面没有类型)
 数组arr长度公式:sizeof(arr)/sizeof(arr[0]).注意条件,arr不能是形参
*/


//int main()
//{
//	//int a = 10;//定义一个int类型的变量a并初始化为10
//	//int arr[10]; //定义一个int类型的数组arr，长度为10
//	//int brr[10] = { 1,2,3,4,5,6,7,8,9,10 }; //初始化
//	//int crr[10] = { 1,2,3,4,5 }; // 1,2,3,4,5,0,0,0,0,0
//	//int drr[] = { 1,2,3,4,5,6,7,8,9,10 }; //自动推断长度为10,刚好放下所有的元素
//
//	//int a = 10;
//	//int arr[a];// 在C99中允许使用变量长度数组,VS2022数组长度为变量是错误的
//	//动态内存
//
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	arr[2] = 10;//把arr下标为2的元素修改为10
//	/*int a = 4;
//	arr[a] = 100;*/
//	//输出arr的所有元素
//	//printf("%d\n", arr[10]);//错误,越界
//	//printf不能直接输出整个数组
//	for(int i=0;i<10;i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	/*int a = 10;
//	a = 30;
//	printf("%d\n", a);*/
//	return 0;
//}


//对10给数组元素依次赋值为1,2,3,4,5,6,7,8,9,10,要求按逆序输出
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("%d,%d,%d\n", sizeof(arr), sizeof(arr[0]), sizeof(arr) / sizeof(arr[0]));
//	for (int i = 9; i >= 0; --i)//bug,长度
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//用数组求斐波那契数列问题
//int main()
//{
//	int arr[40] = { 1,1 };//保存斐波那契数列前40项的值
//	arr[2] = arr[0] + arr[1];//2
//	arr[3] = arr[1] + arr[2];//3
//	arr[4] = arr[2] + arr[3];//5
//	for (int i = 2; i < sizeof(arr) / sizeof(arr[0]); ++i)
//	{
//		arr[i] = arr[i - 1] + arr[i - 2];
//	}
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//有10个地区的面积,要求对它们按由小到大的顺序排列
//利用冒泡排序:从头到尾,两两比较,大的往后,小的往前,直到所有数据有序
//int main()
//{
//	int arr[] = { 3,7,9,0,1,23,45,6,12,25,68,79,80,55 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	int temp;
//	for (int i = 0; i < len -1; ++i)//循环的趟数
//	{
//		for (int j = 0; j + 1 < len - i; ++j)//每一趟需要从头到"尾"(不包括一句有序的数据)遍历
//		{
//			if (arr[j] > arr[j + 1])//交换
//			{
//				temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//	for (int i = 0; i < len; ++i)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


/*
 二维数组
	 定义:类型 数组名[行][列];例如 int arr[3][4];//定义一个3行4列的二维数组
	 初始化:在定义的同时,赋值(经常考试),只初始化一部分则剩余部分为0
	 访问元素:通过行,列下标访问,下标从0开始
*/


//int main()
//{
//	//int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//int brr[3][4];//定义一个3行4列的二维数组brr
//	int brr[3][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
//	//int crr[3][4] = { 1,2,3,4,5,6,7,8,9 };//行优先,剩余部分为零
//	//int drr[][4] = { 1,2,3,4,5,6,7,8,9,10 };//自动推导
//	//int err[][] = { 1,2,3,4,5,6,7,8,9 };//错误
//
//	brr[1][2] = 100;
//	//输出brr的所有元素
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			printf("%d ", brr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}


//                    0 1 2
//1 2 3            0  1 2 3
//4 5 6            1  4 5 6


//矩阵逆置:行列互换
//                    0 1
//1 4              0  1 4
//2 5              1  2 5
//3 6              2  3 6


//(0,0)->(0,0)
//(0,1)->(1,0)
//(0,2)->(2,0)
//(1,0)->(0,1)
//(1,1)->(1,1)
//(1,2)->(2,1)
//(i,j)->(j,i)
//int main()
//{
//	int a[2][3] = { {1,2,3}, {4,5,6} };
//	int b[3][2];//保存逆置后的矩阵
//	for (int i = 0; i < 2; ++i)
//	{
//		for (int j = 0; j < 3; ++j)
//		{
//			b[j][i] = a[i][j];//逆置
//		}
//	}
//	for (int i = 0; i < 3; ++i)
//	{
//		for (int j = 0; j < 2; ++j)
//		{
//			printf("%d ", b[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}


//有一个3x4的矩阵,要求编程序求出其中最大的那个元素的值,以及其所在的行和列
//int main()
//{
//	int a[3][4] = { 3,6,8,9,5,12,7,34,6,0,13,25 };
//	int max = a[0][0];//假设第一个元素最大
//	int row = 0, col = 0;//假设最大元素在第0行第0列
//	//遍历二维数组
//	for (int i = 0; i < 3; ++i)
//	{
//		for (int j = 0; j < 4; ++j)
//		{
//			if (max < a[i][j])
//			{
//				max = a[i][j];
//				row = i;
//				col = j;
//			}
//		}
//	}
//	printf("最大元素为:%d,所在行:%d,所在列:%d\n", max, row, col);
//	return 0;
//}


/*
 字符数组:非常重要,用的多,考的多
	 定义:char 数组名[长度];
	 字符串:用""包括的字符序列,可以是0个及以上的字符.字符串末尾有个隐藏的'\0'作为结尾标记
		 有两种形式的字符串:1.用""包括
						   2.有'\0'的字符数组

*/


//int main()
//{
//	char str1[10];//定义一个长度为10的字符数组,没有初始化,随机值,"烫烫烫.."
//	//printf("%s\n", str1);
//	str1[0] = 'l';
//	str1[1] = ' ';
//	//....
//	char str2[10] = { 'l',' ','a','m' };//初始化一部分,剩余部分为0
//	char str3[10] = "absde";
//	//printf("%s\n", str1);//%s输出字符串,错误,str1不是字符串
//	//printf("%s\n", str3);//是字符串
//	//printf("%s\n", str2);//是字符串
//	
//	//0的表现
//	printf("%d,%d,%d,%d\n", false, 0, '\0', NULL);
//
//	return 0;
//}


//字符数组和字符串
//int main()
//{
//	char str1[10];//字符数组,不是字符串
//	char str2[10] = "abcde";//字符数组,是字符串
//	char str3[] = "abcde";//字符数组,是字符串,长度为6
//	char str4[] = { 'a','b','c','d','e' };//字符数组,不是字符串,长度为5
//	char str5[10] = { 'a','b','c','d','e' };//字符数组,是字符串
//	printf("%s\n", str1);
//	printf("%s\n", str2);
//	printf("%s\n", str3);
//	printf("%s\n", str4);
//	printf("%s\n", str5);
//	return 0;
//}


//输出是字符数组,但不是字符串
//int main()
//{
//	char str[] = { 'a','b','c','d','e' };//是字符数组,不是字符串
//	//printf("%s\n", str);//错误,%s输出字符串,str不是字符串
//	for (int i = 0; i < sizeof(str) / sizeof(str[0]); ++i)//当作数组来处理
//	{
//		putchar(str[i]);
//	}
//	return 0;
//}


//已知字符串,输出
//int main()
//{
//	char c[16] = { 'l',' ','a','m',' ','a',' ','s','t','u','d','e','n','t','.' };
//	printf("%s\n", c);
//	return 0;
//}


//输出菱形.
//1.字符数组
//int main()
//{
//	char c[5][5] = { {' ',' ','*',' ',' '},{' ','*',' ','*',' '},{'*',' ',' ',' ','*'},{' ','*',' ','*',' '},{' ',' ','*',' ',' '} };
//	for (int i = 0; i < 5; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			putchar(c[i][j]);//printf("%c",c[i]);
//		}
//		putchar('\n');
//	}
//	return 0;
//}
//2.字符串
//int main()
//{
//	char c[5][6] = { "  *  "," * * ","*   *"," * * ","  *  " };
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%s\n", c[i]);
//	}
//	return 0;
//}



//字符数组的输入
//int main()
//{
//	char c[6];
//	for (int i = 0; i < 6; i++)//从键盘读取六个字符
//	{
//		scanf("%c", &c[i]);//getchar
//	}
//	for (int i = 0; i < 6; i++)//输出六个字符
//	{
//		printf("%c", c[i]);//putchar
//	}
//	return 0;
//}


//字符串的输入
//int main()
//{
//	char c[6];
//	scanf("%s", &c);//scanf("%s",c);//&c等同c
//	printf("%s\n", c);
//	return 0;
//}


/*
 字符串处理函数:
   puts:输出一个字符串,并自动加换行
   gets:输入一个字符串,已经被废除了,不安全,fgets替代它
   scanf_s:读取字符或字符串后面必须跟大小
   strcpy:字符串赋值(拷贝)
   strcat:字符串连结,注意,两个都必须是字符串,第一个字符串长度必须足够大
   strcmp:字符串比较,不能直接使用>,<(逻辑错误)
	 比较:从头到尾依次比较每个字符,直到分出大小或两个字符串结束
   strlen:求字符串的长度."abc"->3(不包括'\0')
	 注意和sizeof区分.
	 sizeof(a):求a占用的字节数
   strlwr:把字符串所有的大写转小写,已经废除.容易泄露
   strupr:把字符串所有的小写转大写,已经废除.
   isupper:判断字符是否为大写字母
*/


//自己实现把字符串中的所有大写字符转为小写
void Mystrlwr(char str[])
{
	for (int i = 0; str[i] != '\0'; i++)//遍历字符串
	{
		//if('A' <= str[i]&&str[i]<='Z')//不专业,可能不连续.//假如有个这样的编码:'A','1','B','2'.....
		if (isupper(str[i]))//是大写字母
		{
			str[i] = tolower(str[i]);//大写字母转小写字母
		}
	}
}


//int main()
//{
//	//char str1[100] = "abcde xyz";
//	////gets(str);
//	//char str2[10];
//	////scanf("%s", str2);
//	//fgets(str2,10,stdin);//stdin:标准输入,即键盘
//	//puts(str2);
//
//	//char str[100];
//	//scanf_s("%s", str,100);//100字符数组的最大容量 ,C99建议函数,未规定
//	//printf("%s", str);
//
//	//int a = 10;
//	//int b = a;
//	//char str1[] = "abcde";
//	////把str1复制给str2
//	////char str2[10]=str1;//错误的
//	//char str2[10];
//	////str2 = str1;//错误的
//	//strcpy(str2, str1);
//	//printf("str2=%s\n", str2);
//
//	////字符串连结
//	//char str1[10] = "abcde";//一般这个格子给大一点,不然容易越界
//	//char str2[20] = "xyz";
//	////str1=str1+str2//"abcdexyz"
//	//strcat(str1, str2);
//	//printf("%s\n", str1);
//
//	/*char str1[20] = "abcde";
//	char str2[20] = "xyz";
//	char str3[20] = "abcde";*/
//	//字符串比较不能使用>,<,==,应该改为strcmp
//	/*if (str1 > str2)
//	{
//		printf("%s>%s\n", str1, str2);
//	}
//	else
//		printf("%s<%s\n", str1, str2);
//	if (str2 > str3)
//	{
//		printf("%s>%s\n", str2, str3);
//	}
//	else
//		printf("%s<%s\n", str2, str3);*/
//	/*int n1 = strcmp(str1, str2);
//	if (n1 > 0)
//	{
//		printf("%s>%s\n", str1, str2);
//	}
//	else if (n1 == 0)
//	{
//		printf("%s=%s\n", str1, str2);
//	}
//	else
//		printf("%s<%s\n", str1, str2);
//	int n2 = strcmp(str2, str3);
//	if (n1 > 0)
//	{
//		printf("%s>%s\n", str2, str3);
//	}
//	else if (n1 == 0)
//	{
//		printf("%s=%s\n", str2, str3);
//	}
//	else
//		printf("%s<%s\n", str2, str3);*/
//
//	//int n1 = strcmp("abcde", "abcdd");//>0
//	//printf("%d\n", n1);
//	//int n2 = strcmp("abcde", "abcde");//=0
//	//printf("%d\n", n2);
//	//int n3 = strcmp("abcde", "abcdf");//<0
//	//printf("%d\n", n3);
//
//	/*char str[] = "abcde";
//	printf("%zd\n", strlen(str));*/
//
//	//char str1[10] = "abcde";
//	//char str2[] = "abcde";
//	//char str3[10] = "abcde\0\nf";
//	//char str4[] = "abcde\0\nf";
//	//printf("%zd,%zd\n", strlen(str1), sizeof(str1));//5,10
//	//printf("%zd,%zd\n", strlen(str2), sizeof(str2));//5,6
//	//printf("%zd,%zd\n", strlen(str3), sizeof(str3));//5,10
//	//printf("%zd,%zd\n", strlen(str4), sizeof(str4));//5,9
//	//printf("%zd\n", sizeof(1));
//	//printf("%zd\n", strlen(1));//错误
//
//	char str[] = "abCDEF78xyz CD";
//	Mystrlwr(str);
//	printf("%s\n", str);
//	return 0;
//}


//输入一行字符,统计有多少个单词,单词之间用空格分开
//int main()
//{
//	char str[100];
//	//scanf("%s", str);//不能读空格
//	fgets(str,100,stdin);//从键盘最多读取不超过100个字符可以有空格
//	//printf("%s\n", str);
//	int n = 0;//统计单词个数
//	for (int i = 0; str[i] != '\0'; i++)
//	{
//		if (isalpha(str[i]) && !isalpha(str[i + 1]))//判断标准:当前是字母+下一个不是字母
//		{
//			n++;
//		}
//	}
//	printf("%d\n", n);
//	return 0;
//}


//有三个字符串,要求找出其中"最大"者
//int main()
//{
//	char str[3][20];//假定每个字符串的长度不超过19(20-1'\0')
//	char max[20] = "";//保存最大的字符串
//	//从键盘获取三个字符串
//	int i;
//	for (i = 0; i < 3; i++)
//	{
//		fgets(str[i], 20, stdin);//这个输入必须用换行分割,它可以读空格进去
//	}
//	//依次比较大小
//	for (i = 0; i < 3; i++)
//	{
//		if (strcmp(max, str[i]) < 0)//str[i]更大,需要更新数据
//		{
//			strcpy(max, str[i]);
//		}
//	}
//	printf("最大的字符串是%s\n", max);
//	return 0;
//}