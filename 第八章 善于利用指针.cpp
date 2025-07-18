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
  其他情况,arr都表示数组的起始地址(数组首元素的地址)

 指针的算术运算:前提这个指针指向一个数组,同时程序应该保存不越界
   p+整数,p++,++p合法
   p-整数,p--,--p合法
 指针的关系运算.>,<,>=,<=,==,!= .前提,必须在同一个数组里面

 数组作为参数传递:数组名仅仅表示数组首元素的地址
     传数组名+数组长度
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
//int main()
//{
//	int arr[10] = { 1,3,5,7,9,11,13,15,17,19 };
//	//int* p = &arr[0];//第一个元素int的地址
//	int* p = arr;//和上一行等价
//	//printf("%d,%d\n", arr[0], *p);
//
//	//printf("%d\n", sizeof(arr));//整个数组的大小
//	//printf("%d,%d\n", &arr, &arr + 1);//&arr+1表示加整个数组的大小(字节数)
//
//	//printf("%d\n", *p);
//	 
//	//通过指针输出访问数组的所有元素
//	/*for (int i = 0; i < 10; i++, p++)
//	{
//		printf("%d ", *p);
//	}*/
//	/*for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", *p++);
//	}*/
//	//for (int i = 0; i < 10; i++)
//	//{
//	//	printf("%d ", *(p + i));//*(p + 1)
//	//}
//	return 0;
//}

//指针在数组中的运算
//int main()
//{
//	int arr[10] = { 1,3,5,7,9,11,13,15,17,19 };
//	int* p = &arr[9];
//	//从后往前输出数组的所有元素
//	/*for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", *p);
//		p--;
//	}*/
//	/*for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", *p--);
//	}*/
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p - i));
//	}
//}


//有一个整形数组a,有10个元素,要求输出数组中的全部元素
//int main()
//{
//	int a[10];
//	int* p, i;
//	printf("请输入10个整数");
//	/*for ( i = 0; i < 10; i++)
//	{
//		scanf("%d", &a[i]);
//	}*/
//	//数组元素用数组名和下标表示
//	/*for (i = 0; i < 10; i++)
//	{
//		printf("%d ", a[i]);
//	}*/
//	//用指针指向当前的数组元素
//	/*for (p = a; p < (a + 10); p++)
//	{
//		printf("%d ", *p);
//	}*/
//	//更好的写法
//	/*p = a;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *p++);
//	}*/
//	//for ( i = 0; i < 10; i++)
//	//{
//	//	printf("%d ", *(a + i)); //printf("%d ", *(p + i));
//	//}
//
//	p = a;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", p++);
//	}
//	//p已经到达a的尾后指针
//	p = a;
//	for (i = 0; i < 10; i++, p++)
//	{
//		printf("%d ", *p);
//	}
//	printf("\n");
//	return 0;
//}


//指针的关系运算
//int main()
//{
//	//int a = 10;
//	//int b = 20;
//	//int* p = &a;
//	//printf("%d\n", *(p + 1));//错误的应用,必须在数组里面
//	//int* q = &b;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//从头到尾输出数组元素
//	//for (int* p = arr; p != &arr[10]; p++)//标准使用尾后(尾巴的后面)地址(指针)
//	//{
//	//	printf("%d ", *p);
//	//}
//	//for (int* p = arr; p < &arr[10]; p++)
//	/*for (int* p = arr; p <= &arr[9]; p++)
//	{
//		printf("%d ", *p);
//	}*/
//	return 0;
//}


//输出数组的所有元素
//p:数组的起始地址,n:元素的个数
void Show(int* p, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");
}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	Show(arr, sizeof(arr) / sizeof(arr[0]));
//	return 0;
//}


//将数组a中的n个整数按相反顺序存放
//x:数组的起始地址,n:元素的个数
void inv(int* x, int n)
{
	int temp;
	//for (int i = 0, j = n - 1; i < j; i++, j--)//把x当作数组名操作.没有问题
	//{
	//	temp = x[i];
	//	x[i] = x[j];
	//	x[j] = temp;
	//}
	for (int i = 0, j = n - 1; i < j; i++, j--)//把x当作指针
	{
		temp = *(x + i);
		*(x + i) = *(x + j);
		*(x + j) = temp;
	}
}

//int main()
//{
//	int arr[] = { 1,3,5,7,9,11,13,15,17,19 };
//	inv(arr, sizeof(arr) / sizeof(arr[0]));
//	Show(arr, sizeof(arr) / sizeof(arr[0]));
//	return 0;
//}


//用指针方法对10个整数按由大到小顺序排序(选择法)(下标)
//arr:数组的起始地址,n:元素的个数
void SelectSort1(int* arr, int n)
{
	int k;//最小值的下标
	int temp;//临时变量
	for (int i = 0; i < n - 1; i++)//趟数
	{
		k = i;
		for (int j = i + 1; j < n; j++)//找最小值的下标
		{
			if (arr[j] < arr[k])//需要更新数据
			{
				k = j;
			}
		}
		if (k != i)//把"第一个"值和最小值交换
		{
			temp = arr[i];
			arr[i] = arr[k];
			arr[k] = temp;
		}
	}
}

//用指针方法对10个整数按由大到小顺序排序(选择法)(指针)
void SelectSort(int* arr, int n)
{
	int k;//最小值的下标
	int temp;//临时变量
	for (int i = 0; i < n - 1; i++)//趟数
	{
		k = i;
		for (int j = i + 1; j < n; j++)//找最小值的下标
		{
			if (*(arr + j) < *(arr + k))//需要更新数据
			{
				k = j;
			}
		}
		if (k != i)//把"第一个"值和最小值交换
		{
			temp = *(arr + i);
			*(arr + i) = *(arr + k);
			*(arr + k) = temp;
		}
	}
}

//int main()
//{
//	int arr[] = { 11,3,5,27,9,101,123,65,77,19 };
//	//SelectSort1(arr, sizeof(arr) / sizeof(arr[0]));
//	SelectSort(arr, sizeof(arr) / sizeof(arr[0]));
//	Show(arr, sizeof(arr) / sizeof(arr[0]));
//	return 0;
//}



//int main()
//{
//	int arr[4];
//	int brr[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };//行优先,想象为一维数组,每一行为一个元素
//	int* p = arr;//arr的类型就是int*
//	p = arr + 1;//arr+1的类型还是int*
//	int a = arr[0];//arr[0]的类型是int
//	//////////////////////////////////
//	//int** p2 = brr;//错误的,说明brr的类型不是int**
//	int(*p2)[4] = brr;
//	int* p3 = brr[0];//brr[0]的含义和arr相同(int*)
//	p2 = brr + 1;//brr+1的类型是int(*x)[4]
//	p3 = brr[0] + 1;//brr[0]+1的类型是int*
//	int b = brr[0][0];//brr[0][0]的类型是int
//	b = brr[0][0] + 1;//brr[0][0]+1的类型是int
//	return 0;
//}


//输出二维数组所有元素的值
//void Show2(int brr[3][4])//3是个无效值,等同下一行
//void Show2(int brr[][4])//等同下一行
void Show2(int(*brr)[4])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", brr[i][j]);
		}
		printf("\n");
	}
}

void Show3(int(*brr)[4], int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", brr[i][j]);
		}
		printf("\n");
	}
}


//int main()
//{
//	int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
//	/*for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			printf("%d ", a[i][j]);
//		}
//		printf("\n");
//	}*/
//	//Show2(a);
//	Show3(a, 3);
//	return 0;
//}