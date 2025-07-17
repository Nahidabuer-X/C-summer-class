#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<complex>
#include<math.h>


/*
 指针:就是地址
 &变量名:获取该变量的地址(指针)
 指针变量:保存指针(地址)的变量
   A *变量名:定义一个A类型的指针变量
 在指针变量定义时出现的*用来说明该变量是一个指针变量
 如何使用指针变量? 答*p访问p所指向的变量
 *p:解应用,间接访问符
 &的作用:1.按位与.例如4&3(100&011,相同的位都为1才为1,=000);2.取地址.例如&a;3.C++的引用
 指针的应用
 总结:一个函数A通过调用函数B,来达到修改A中变量的值,1.必须传指针;2.必须在B中解引用.
 一维数组arr的名字arr表示整个数组只在如下情况
   1.在定义数组的同一个函数中求sizeof.例如 int arr[10];sizeof(arr)->40
   2.在定义数组的同一个函数中,&arr+1,表示整个数组的大小,例如 int arr[10],&arr,&arr+1
*/

//int main()
//{
//	int a = 10;//4字节
//	a = 20;
//	int b = 20;
//	b = a;
//	&a;//获取a的地址
//	&b;//获取b的地址
//
//	printf("a的地址=%p,b的地址=%p\n", &a, &b);//%p:输出地址(指针),以十六进制输出
//	//printf("a的地址=%d,b的地址=%d\n", &a, &b);//间隔12?为什么呢
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	int b = 20;
//	int* p = &a;//一个int地址(指针)赋值给一个int指针变量
//	//获取a的地址,int &p=&a(int &p  C++引用);int *p=&a;
//	p = &b;//把b的地址赋值给p
//	//&p;
//	char c;
//	double d;
//	char* p1 = &c;
//	double* p2 = &d;
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	int b = 20;
//	int* p = &a;
//	*p = 100;//a = 100; ?
//	p = &b;//p保存b的地址
//	*p = 200;
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	printf("%d,%d\n", a, &a);//a的值,a的地址
//	int* p = &a;
//	printf("%d,%d,%d\n", *p, p, &a);//p指向的变量a的值,a的地址,p的地址
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 4 & 3;//按位与  100&011=000
//	printf("%d\n", c);
//	printf("%p,%p,%p\n", &a, &b, &c);
//	printf("%d\n", a & b);//按位与
//
//	int& d = a;//C++的引用,前面有数据类型
//	return 0;
//}


//交换两个变量的值(写成函数)
void Swap_err1(int a, int b)//没有交换成功,错误
{
	int temp = a;
	a = b;
	b = temp;
}

void Swap_err2(int* p1, int* p2)//没有交换成功,错误,没有解引用
{
	int* temp;
	temp = p1;
	p1 = p2;
	p2 = temp;
}

void Swap(int* p1, int* p2)//没有交换成功,错误,没有解引用
{
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

//int main()
//{
//	int a, b;
//	scanf("%d%d", &a, &b);
//	printf("交换前%d,%d\n", a, b);
//	//Swap_err1(a, b);//交换a,b
//	//Swap_err2(&a, &b);
//	Swap(&a, &b);
//	printf("交换后%d,%d\n", a, b);
//	return 0;
//}


//如何返回两个值
//C语言只能返回0个或者1各返回值
//解一元二次方程
//假定前题d=b^2-4ac>0
//double Fun(int a, int b, int c)
//{
//	int d = b * b - 4 * a * c;
//	double x1, x2;
//	x1 = (-b + sqrt(d)) / (2 * a);
//	x2 = (-b - sqrt(d)) / (2 * a);
//	return x1;
//}

//x1,x2称为输出参数(传指针,内部解引用) 工作经常使用
int Fun(int a, int b, int c, double* x1, double* x2)
{
	int d = b * b - 4 * a * c;
	*x1 = (-b + sqrt(d)) / (2 * a);
	*x2 = (-b - sqrt(d)) / (2 * a);
	return 2;//两个根
}

//int main()
//{
//	double x1;
//	double x2;
//	Fun(3, 5, 1, &x1, &x2);
//	printf("%lf,%lf\n", x1, x2);
//	return 0;
//}


//悬空指针,悬挂指针,野指针,并没有指向一个有效的地址
//int main()
//{
//	int* p;//错误
//	*p = 10;
//	return 0;
//}


//指针指向数组元素
int main()
{
	int arr[10] = { 1,3,5,7,9,11,13,15,17,19 };
	//int* p = &arr[0];//第一个元素int的地址
	int* p = arr;//和上一行等价
	printf("%d,%d\n", arr[0], *p);

	printf("%d\n", sizeof(arr));//整个数组的大小
	printf("%d,%d\n", &arr, &arr + 1);//&arr+1表示加整个数组的大小(字节数)
	return 0;
}