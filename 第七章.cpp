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

int main()
{
	printf("%d中1的个数:%d\n", 123, Count(123));
	printf("%d中1的个数:%d\n", 12121, Count(12121));
	printf("%d中1的个数:%d\n", 11111, Count(11111));
	return 0;
}