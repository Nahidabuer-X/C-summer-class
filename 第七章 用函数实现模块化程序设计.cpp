#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include <complex>


/*
 库函数:别的公司(微软)已经实现好的,我们直接使用
 自定义函数:自己或者同项目组的组员实现的
 函数:
   1.功能更清晰
   2.提高代码的使用率
  返回值 函数名(参数列表)
  {
      函数体
  }
  函数名:每个函数都需要一个独一无二的名字(标识符)
  void:没有,可以修饰返回值(必须写)或者参数列表(可以省略)
  函数定义完成后,并不能自动执行
  返回值:函数计算的结果通过返回值返回给函数调用
  调用函数.
  如果函数定义放在函数使用(调用)的后面,那么在前面必须有函数申明
  函数调用没有限制,但函数定义有限制函数内部不能定义另一个函数

  递归:直接或间接调用函数本身
    三部分:1.边界条件;2.前进段;3.返回段
*/


void Max1()//函数定义
{
	int a;
	int b;
	scanf("%d%d", &a, &b);
	int c = a >= b ? a : b;//最大值
	printf("%d\n", c);
}

void Max2(int a,int b)//a,b称为形式参数,形参,注意它已经有数据,不能再通过scanf读取
{
	int c = a >= b ? a : b;
	printf("%d\n", c);
}

int Max4(int a, int b)//a,b称为形式参数,形参,注意它已经有数据,不能再通过scanf读取
{
	int c = a >= b ? a : b;
	return c;//返回c
}

int Max3(int a, int b,int c )
{
	int d = Max4(a, b);//int d = void(没有)
	int e = Max4(c, d);
	return e;
	//Max2(Max2(a, b), c);
}


//两个数的最大值
//int main(void)//显式
//int main()//和上一行等价
//{
//	//int a;
//	//int b;
//	//scanf("%d%d", &a, &b );
//	//int c = a >= b ? a : b;//最大值
//	//printf("%d\n", c);
//
//	//Max1();//函数调用
//	//pow(5, 3);
//	//int a = 10;
//	//printf("%d\n", a);
//
//	//int x = Max4(10, 20);
//	//int a = 100;
//	//int b = 200;
//	//int y = Max4(a, b);//a,b实际参数,实参
//	//printf("%d,%d\n", x, y);
//
//	/*double n = pow(5, 3);
//	double m = sqrt(10);
//	printf("%lf %lf\n", n, m);*/
//
//	int z = Max3(100, 20, 300);
//	printf("%d\n", z);
//	return 0;
//}


float Add(float a, float b);

//int main()
//{
//	float a = Add(12.5, 23.5);
//	printf("%f\n", a);
//	return 0;
//}

float Add(float a, float b)
{
	return a+b;
}


//int main()//主函数的定义
//{
//	/*int Max(int a, int b);
//	return a >= b ? a : b;*///错误的,不能在main函数内部定义另一个函数
//	return 0;
//}

//void A()
//{
//	//void B()//错误的,不能在A定义中定义另一个函数B
//	//{
//	//	printf("B\n");
//	//}
//	printf("A\n");
//}


//统计一个数字中1的个数(经常考试)
//例如:123->1 ;12121->3 ;11111->5
//n:需要统计的数字
//返回值:返回1的个数
int Count(int n)
{
	int sum = 0;//统计1的个数
	while (n != 0)
	{
		if (n % 10 == 1)//得个位
		{
			sum++;
		}
		n /= 10;
	}
	return sum;
}

//int main()
//{
//	printf("%d中1的个数:%d\n", 123, Count(123));
//	printf("%d中1的个数:%d\n", 12121, Count(12121));
//	printf("%d中1的个数:%d\n", 11111, Count(11111));
//	return 0;
//}


//有5个学生坐在一起,问第5个学生多少岁,他说比第4个学生大2岁。问第4个学生岁数,
//他说比第3个学生大2岁。问第3个学生, 又说比第2个学生大2岁。问第2个学生, 说比第1个学生大
//2岁。最后问第1个学生, 他说是10岁。请问第5个学生多大。

//循环实现
int Age_for(int n)
{
	int temp = 10;
	for (int i = 1; i < n; i++)
	{
		temp += 2;
	}
	return temp;
}
//递归实现
//Age(1):求第一个人的年龄
//Age(2):求第二个人的年龄
//Age(n):求第n个人的年龄
//Age(n-1):求第n-1个人的年龄
int Age(int n)//求第n个人的年龄
{
	if (n == 1)
	{
		return 10;
	}
	else
		return Age(n - 1) + 2;
}

//int main()
//{
//	printf("%d\n", Age(5));
//	return 0;
//}


//求阶乘
//0!==1,1!==1,n!=n*(n-1)!
long long Fac(int n)//Fac(n)求n的阶乘
{
	if (n == 0 || n == 1)
	{
		return 1;
	}
	return n * Fac(n - 1);
}

//int main()
//{
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d!=%lld\n", i, Fac(i));
//	}
//	return 0;
//}


//汉诺塔,把n个盘子,从a,通过b,移到c
void Hanoi(int n, char a, char b, char c)
{
	if (n == 1)//只有一个盘子,直接从a移到c
	{
		printf("%c->%c\n", a, c);
	}
	else
	{
		Hanoi(n - 1, a, c, b);//把上面的n-1个盘子从a通过c移到b
		printf("%c->%c\n", a, c);//把最下面的一个从a移到c
		Hanoi(n - 1, b, a, c);//把b上面的n-1个盘子,从b通过a移到c
	}
}

//int main()
//{
//	Hanoi(3,'A','B','C');
//	return 0;
//}


/*
 数组作为参数传递结论:一定要传数组名和数组长度
*/


//一维数组作为参数传递,错误应用
//求一个数组中的最大值
//int Max(int arr[10])//经常考试,数组作为参数传递最大的错误,这个10是没有意义的
int Max_err(int arr[])
{
	int tmp = arr[0];//保存最大值
	for (int i = 1; i < 10; i++)
	{
		if (tmp < arr[i])
		{
			tmp = arr[i];
		}
	}
	return tmp;
}

//arr:数组名
//n:数组长度
int Max(int arr[],int n)//arr本质是指针,不是数组
{
	//在Max函数内部,不能使用sizeof(arr) / sizeof(arr[0])
	int tmp = arr[0];//保存最大值
	for (int i = 1; i < n; i++)
	{
		if (tmp < arr[i])
		{
			tmp = arr[i];
		}
	}
	return tmp;
}

//int main()
//{
//	int arr[] = { 1,5,2,7,8,9,10,4,6,3,11,12 };
//	//int a = Max_err(arr);//数组作为参数传递时,只传数组的起始地址
//	int a = Max(arr, sizeof(arr) / sizeof(arr[0]));
//	printf("数组最大值为%d\n", a);
//	return 0;
//}


//arr:数组名
//n:数组长度
//求arr的平均值
double Avg(double arr[], int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum / n;
}

//int main()
//{
//	/*double arr[] = { 67,78,89.5,100,99,80 };
//	printf("%lf\n", Avg(arr, sizeof(arr) / sizeof(arr[0])));*/
//
//	double score1[5] = { 98.5,97,91.5,60,55 };
//	double score2[10] = { 67.5,89.5,99,69.5,77,89.5,76.5,54,60,99.5 };
//	printf("第一个班平均分: %.2lf\n", Avg(score1, sizeof(score1) / sizeof(score1[0])));
//	printf("第二个班平均分: %.2lf\n", Avg(score2, sizeof(score2) / sizeof(score2[0])));
//	return 0;
//}


//用选择法对数组中10个整数按由大到小排序(每次都在待排序中找最小值,和待排序第一个值交换)
//arr:数组名,n:数组长度
void SelectSort(int arr[], int n)
{
	int k;//最小值下标
	int temp;
	for (int i = 0; i < n - 1; i++)//排序的趟数
	{
		k = i;
		for (int j = i; j < n; j++)
		{
			if (arr[j] < arr[k])//找到更小值,需要更新数据
			{
				k = j;
			}
		}
		if (i != k)
		{
			temp = arr[i];
			arr[i] = arr[k];
			arr[k] = temp;
		}
	}
}

//输出长度为n的数组arr所有元素
void Show_arr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//int main()
//{
//	int arr[] = { 3,6,8,9,12,34,7,45,3,90,78,66,43 };
//	SelectSort(arr, sizeof(arr) / sizeof(arr[0]));
//	Show_arr(arr, sizeof(arr) / sizeof(arr[0]));
//	return 0;
//}


//输出row行col列的二维数组arr
void Show(int arr[][4], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

//求3*4二维数组的最大值
int Max34(int arr[3][4], int row, int col)
{
	int temp = arr[0][0];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] > temp)
			{
				temp = arr[i][j];
			}
		}
	}
	return temp;
}

//int main()
//{
//	int arr[][4] = { 1,2,3,4,5,6,7,8,9 };
//	Show(arr, 3, 4);
//	printf("%d\n", Max34(arr, 3, 4));
//	return 0;
//}



/*
 全局变量:定义在函数外部的变量.尽量少用,学习时不允许用(不安全)
 局部变量:定义在函数内部的变量,包括形参
                           作用域                                生命周期                默认值
 全局变量:     定义开始到整个文件结束都可以使用       从程序运行开始创建,程序结束才销毁  0(不要使用)
 局部变量: 只在本函数内部使用(优点,可以防止名字污染)     从进入函数创建,函数结束销毁     无效(随机值)
 static:静态,修饰变量或者函数
 普通局部变量:        在函数内部使用                     从进入函数创建,函数结束销毁        无
 静态局部变量:        在函数内部使用                 从第一次进入函数创建,程序结束销毁   0(不要使用)

 存储类别:自动的(auto)(在c语言不再使用,C++用的多),静态的(static),寄存器的(register)(C不使用),外部的(extern)(C++引用c语言的代码)
 register:建议编译器对这个变量进行优化,这个变量会多次使用,建议把它从内存加载到寄存器
*/


//int g_a = 10;//全局变量

//int main()
//{
//	int a = 10;//局部变量
//	return 0;
//}

void Show1()
{
	static int a = 0;;//静态变量,创建后就不死(这一句代码只有第一次进入函数时调用,其他时间都不执行)
	++a;
	printf("%d\n", a);
}

//int main()
//{
//	Show1();//此时输出1
//	Show1();//此时输出2
//	static int c;
//	printf("%d\n", c);//输出0
//}