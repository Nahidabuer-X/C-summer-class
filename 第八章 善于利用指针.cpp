#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<complex>
#include<math.h>
#include <stdlib.h>


/*
 ָ��:���ǵ�ַ
 &������:��ȡ�ñ����ĵ�ַ(ָ��)
 ָ�����:����ָ��(��ַ)�ı���
   A *������:����һ��A���͵�ָ�����
 ��ָ���������ʱ���ֵ�*����˵���ñ�����һ��ָ�����
 ���ʹ��ָ�����? ��*p����p��ָ��ı���
 *p:��Ӧ��,��ӷ��ʷ�
 &������:1.��λ��.����4&3(100&011,��ͬ��λ��Ϊ1��Ϊ1,=000);2.ȡ��ַ.����&a;3.C++������
 ָ���Ӧ��
 �ܽ�:һ������Aͨ�����ú���B,���ﵽ�޸�A�б�����ֵ,1.���봫ָ��;2.������B�н�����.
 һά����arr������arr��ʾ��������ֻ���������
   1.�ڶ��������ͬһ����������sizeof.���� int arr[10];sizeof(arr)->40
   2.�ڶ��������ͬһ��������,&arr+1,��ʾ��������Ĵ�С,���� int arr[10],&arr,&arr+1
  �������,arr����ʾ�������ʼ��ַ(������Ԫ�صĵ�ַ)

 ָ�����������:ǰ�����ָ��ָ��һ������,ͬʱ����Ӧ�ñ��治Խ��
   p+����,p++,++p�Ϸ�
   p-����,p--,--p�Ϸ�
 ָ��Ĺ�ϵ����.>,<,>=,<=,==,!= .ǰ��,������ͬһ����������

 ������Ϊ��������:������������ʾ������Ԫ�صĵ�ַ
     ��������+���鳤��
*/

//int main()
//{
//	int a = 10;//4�ֽ�
//	a = 20;
//	int b = 20;
//	b = a;
//	&a;//��ȡa�ĵ�ַ
//	&b;//��ȡb�ĵ�ַ
//
//	printf("a�ĵ�ַ=%p,b�ĵ�ַ=%p\n", &a, &b);//%p:�����ַ(ָ��),��ʮ���������
//	//printf("a�ĵ�ַ=%d,b�ĵ�ַ=%d\n", &a, &b);//���12?Ϊʲô��
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	int b = 20;
//	int* p = &a;//һ��int��ַ(ָ��)��ֵ��һ��intָ�����
//	//��ȡa�ĵ�ַ,int &p=&a(int &p  C++����);int *p=&a;
//	p = &b;//��b�ĵ�ַ��ֵ��p
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
//	p = &b;//p����b�ĵ�ַ
//	*p = 200;
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	printf("%d,%d\n", a, &a);//a��ֵ,a�ĵ�ַ
//	int* p = &a;
//	printf("%d,%d,%d\n", *p, p, &a);//pָ��ı���a��ֵ,a�ĵ�ַ,p�ĵ�ַ
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 4 & 3;//��λ��  100&011=000
//	printf("%d\n", c);
//	printf("%p,%p,%p\n", &a, &b, &c);
//	printf("%d\n", a & b);//��λ��
//
//	int& d = a;//C++������,ǰ������������
//	return 0;
//}


//��������������ֵ(д�ɺ���)
void Swap_err1(int a, int b)//û�н����ɹ�,����
{
	int temp = a;
	a = b;
	b = temp;
}

void Swap_err2(int* p1, int* p2)//û�н����ɹ�,����,û�н�����
{
	int* temp;
	temp = p1;
	p1 = p2;
	p2 = temp;
}

void Swap(int* p1, int* p2)//û�н����ɹ�,����,û�н�����
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
//	printf("����ǰ%d,%d\n", a, b);
//	//Swap_err1(a, b);//����a,b
//	//Swap_err2(&a, &b);
//	Swap(&a, &b);
//	printf("������%d,%d\n", a, b);
//	return 0;
//}


//��η�������ֵ
//C����ֻ�ܷ���0������1������ֵ
//��һԪ���η���
//�ٶ�ǰ��d=b^2-4ac>0
//double Fun(int a, int b, int c)
//{
//	int d = b * b - 4 * a * c;
//	double x1, x2;
//	x1 = (-b + sqrt(d)) / (2 * a);
//	x2 = (-b - sqrt(d)) / (2 * a);
//	return x1;
//}

//x1,x2��Ϊ�������(��ָ��,�ڲ�������) ��������ʹ��
int Fun(int a, int b, int c, double* x1, double* x2)
{
	int d = b * b - 4 * a * c;
	*x1 = (-b + sqrt(d)) / (2 * a);
	*x2 = (-b - sqrt(d)) / (2 * a);
	return 2;//������
}

//int main()
//{
//	double x1;
//	double x2;
//	Fun(3, 5, 1, &x1, &x2);
//	printf("%lf,%lf\n", x1, x2);
//	return 0;
//}


//����ָ��,����ָ��,Ұָ��,��û��ָ��һ����Ч�ĵ�ַ
//int main()
//{
//	int* p;//����
//	*p = 10;
//	return 0;
//}


//ָ��ָ������Ԫ��
//int main()
//{
//	int arr[10] = { 1,3,5,7,9,11,13,15,17,19 };
//	//int* p = &arr[0];//��һ��Ԫ��int�ĵ�ַ
//	int* p = arr;//����һ�еȼ�
//	//printf("%d,%d\n", arr[0], *p);
//
//	//printf("%d\n", sizeof(arr));//��������Ĵ�С
//	//printf("%d,%d\n", &arr, &arr + 1);//&arr+1��ʾ����������Ĵ�С(�ֽ���)
//
//	//printf("%d\n", *p);
//	 
//	//ͨ��ָ������������������Ԫ��
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

//ָ���������е�����
//int main()
//{
//	int arr[10] = { 1,3,5,7,9,11,13,15,17,19 };
//	int* p = &arr[9];
//	//�Ӻ���ǰ������������Ԫ��
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


//��һ����������a,��10��Ԫ��,Ҫ����������е�ȫ��Ԫ��
//int main()
//{
//	int a[10];
//	int* p, i;
//	printf("������10������");
//	/*for ( i = 0; i < 10; i++)
//	{
//		scanf("%d", &a[i]);
//	}*/
//	//����Ԫ�������������±��ʾ
//	/*for (i = 0; i < 10; i++)
//	{
//		printf("%d ", a[i]);
//	}*/
//	//��ָ��ָ��ǰ������Ԫ��
//	/*for (p = a; p < (a + 10); p++)
//	{
//		printf("%d ", *p);
//	}*/
//	//���õ�д��
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
//	//p�Ѿ�����a��β��ָ��
//	p = a;
//	for (i = 0; i < 10; i++, p++)
//	{
//		printf("%d ", *p);
//	}
//	printf("\n");
//	return 0;
//}


//ָ��Ĺ�ϵ����
//int main()
//{
//	//int a = 10;
//	//int b = 20;
//	//int* p = &a;
//	//printf("%d\n", *(p + 1));//�����Ӧ��,��������������
//	//int* q = &b;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//��ͷ��β�������Ԫ��
//	//for (int* p = arr; p != &arr[10]; p++)//��׼ʹ��β��(β�͵ĺ���)��ַ(ָ��)
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


//������������Ԫ��
//p:�������ʼ��ַ,n:Ԫ�صĸ���
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


//������a�е�n���������෴˳����
//x:�������ʼ��ַ,n:Ԫ�صĸ���
void inv(int* x, int n)
{
	int temp;
	//for (int i = 0, j = n - 1; i < j; i++, j--)//��x��������������.û������
	//{
	//	temp = x[i];
	//	x[i] = x[j];
	//	x[j] = temp;
	//}
	for (int i = 0, j = n - 1; i < j; i++, j--)//��x����ָ��
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


//��ָ�뷽����10���������ɴ�С˳������(ѡ��)(�±�)
//arr:�������ʼ��ַ,n:Ԫ�صĸ���
void SelectSort1(int* arr, int n)
{
	int k;//��Сֵ���±�
	int temp;//��ʱ����
	for (int i = 0; i < n - 1; i++)//����
	{
		k = i;
		for (int j = i + 1; j < n; j++)//����Сֵ���±�
		{
			if (arr[j] < arr[k])//��Ҫ��������
			{
				k = j;
			}
		}
		if (k != i)//��"��һ��"ֵ����Сֵ����
		{
			temp = arr[i];
			arr[i] = arr[k];
			arr[k] = temp;
		}
	}
}

//��ָ�뷽����10���������ɴ�С˳������(ѡ��)(ָ��)
void SelectSort(int* arr, int n)
{
	int k;//��Сֵ���±�
	int temp;//��ʱ����
	for (int i = 0; i < n - 1; i++)//����
	{
		k = i;
		for (int j = i + 1; j < n; j++)//����Сֵ���±�
		{
			if (*(arr + j) < *(arr + k))//��Ҫ��������
			{
				k = j;
			}
		}
		if (k != i)//��"��һ��"ֵ����Сֵ����
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
//	int brr[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };//������,����Ϊһά����,ÿһ��Ϊһ��Ԫ��
//	int* p = arr;//arr�����;���int*
//	p = arr + 1;//arr+1�����ͻ���int*
//	int a = arr[0];//arr[0]��������int
//	//////////////////////////////////
//	//int** p2 = brr;//�����,˵��brr�����Ͳ���int**
//	int(*p2)[4] = brr;
//	int* p3 = brr[0];//brr[0]�ĺ����arr��ͬ(int*)
//	p2 = brr + 1;//brr+1��������int(*x)[4]
//	p3 = brr[0] + 1;//brr[0]+1��������int*
//	int b = brr[0][0];//brr[0][0]��������int
//	b = brr[0][0] + 1;//brr[0][0]+1��������int
//	return 0;
//}


//�����ά��������Ԫ�ص�ֵ
//void Show2(int brr[3][4])//3�Ǹ���Чֵ,��ͬ��һ��
//void Show2(int brr[][4])//��ͬ��һ��
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



/*
 �ַ�������ַ�������
 const:�������޸�(�����ε�)����
       int a = 10;//aû���κ�����,�ɶ���д
	   a = 20;//�Ϸ�
	   const int ca = 10;//ca�ƶ�,�������޸�ca��ֵ
	1.�������Ͷ���const��͸����.���� const int ca = 10;��ͬ�� int const ca = 10;
	2.constֻ������"ֱ��"�ұ�
*/


//int main()
//{
//	//����������
//	char str1[] = "hello world";//���ַ�������,���ַ���
//	//char* str2 = "hello world";//���ַ���,���ַ�������,��VS2022���﷨����,��VCcode�п���
//	const char* str2 = "hello world";
//	//printf("%s\n%s\n", str1, str2);
//	str1[0] = 'x';//������ÿһ��Ԫ�ض����޸�
//	//str2[0] = 'x';//��VScode�ܱ���,�����б���,��VS2022�﷨����,����ʹ���µ�IDE(������)
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	a = 20;
//	printf("%d\n", a);
//	const int ca = 10;
//	//ca = 20;//����
//	int const cb = 10;//��ca�ȼ�
//
//	int b = 20;
//	int* p = &a;
//	p = &b;//�޸�p������
//	*p = 100;//�޸�*p������
//	const int* p2 = &a;
//	p2 = &b;
//	//*p2 = 100;//����//constֻ������"ֱ��"�ұ�
//	int const* p3 = &a;//��ͬp2
//	int* const p4 = &a;
//	//p4 = &b;//����//constֻ������"ֱ��"�ұ�
//	*p4 = 100;
//	return 0;
//}


//�ַ�������ͨ��������:�ַ�������ͨ��'\0'�жϽ�β
//��ʹ�ÿ⺯��,ʵ���ַ�������   ||  ||
//des:Ŀ�ĵ�ַ.(n1:Ŀ�����鳤��.)   ||
//src:Դ�ַ����ĵ�ַ.(n2:Դ�ַ����ĳ���)
void Mystrcpy(char* des, const char* src)//�������޸�src. strcpy(һ��),strcmp(������)...�ȶ��������޸�
{
	int i;
	for (i = 0; src[i] != '\0'; i++)
	{
		des[i] = src[i];
	}
	des[i] = '\0';
}

//int main()
//{
//	char str1[] = "abcde";
//	char str2[100];
//	//����Mystrcpy,ʵ�ְ�str1���Ƶ�str2��
//	Mystrcpy(str2, str1);
//	printf("str2=%s\n", str2);
//	return 0;
//}


/*
 ָ������ָ��(�����кܳ���)
 ������
 ��׼�涨:������Ҳ��ʾ��������ڵ�ַ,��Max == &Max

 qsort:����������ݽ�������(����)��ô������αȽ��������ݵĴ�С(����ѧ��,�����Ƿ���,���,����)
      ����:��Ҫ�ṩ�����ݱȽϵ�����
 �ֲ�����:������ڴ�������ջ,��С(1M~10M),�ҵ��ڴ�64G
    10,000,000������,������Ҫ40M�ڴ�
 ��̬�ڴ�:
 void:û��,���η���ֵ�Ͳ����б�
 void*:û��������Ϣ��ָ��,���ָ�������¼��ַ
    ʹ�õĳ���:1.��Ҫ�������ڴ�ʱ;
	           2.��һ�������������ڴ��ڱ�ĺ����л���Ҫʹ��Ҳ��Ҫ;
			   3.��VS2022����Ҫʹ�ñ�����Ϊ����ĳ���
   ��δ�����̬�ڴ�:
             malloc:��Ҫ����<stdlib.h>,ʧ�ܷ���NULL,�ɹ����ص�ַ
             calloc:��malloc����,�����ÿ��Ԫ�س�ʼ��Ϊ0
             realoc:��Ҫ�����޸Ķ�̬�ڴ�Ĵ�С
   ����ͷŶ�̬�ڴ�:
               free:���û���ͷŶ�̬������ڴ������ڴ�й©(����C��C++���鷳������)
	�ڴ�й©:�����˵������ͷ�,���������ȥ���ڴ��ĳ����޷���ʹ��,�����ڴ����,�ٶȱ���
	й¶���ڴ�ʲô����»��ͷ�?:1.����(����)����.2.�ػ�(����)
*/


int Max(int a, int b)
{
	return a >= b ? a : b;
}

int Min(int a, int b)
{
	return a <= b ? a : b;
}

int Avg(int a, int b)
{
	return (a + b) / 2;
}


//int main()
//{
//	int(*pfun)(int, int);//pfunһ����ָ��,��ָ�����ָ����,��������Ϊint,int,����ֵΪint,��fpun��һ������ָ��
//	pfun = Max;
//	pfun = Min;
//	pfun = Avg;//��ͬ��pfun = &Avg;
//	printf("%d\n", pfun(10, 20));
//	printf("%d\n", Max(10, 20));//�鷳???
//	return 0;
//}


//����ֵ:��һ��>�ڶ���,���ش���0������
//����ֵ:��һ��=�ڶ���,����0
//����ֵ:��һ��<�ڶ���,����С��0������
int Cmp_int(const void* vp1, const void* vp2)
{
	//(int*)vp1, (int*)vp2;//��ԭ����
	return *(int*)vp1 - *(int*)vp2;
}

int Cmp_double(const void* vp1, const void* vp2)
{
	//return *(double*)vp1 - *(double*)vp2;//����,0.5-0.4 == 0.1 -> int 0
	double temp = *(double*)vp1 - *(double*)vp2;
	if (temp > 0)
		return 1;
	else if (temp < 0)
		return -1;
	else
		return 0;
}


//int main()
//{
//	int arr[] = { 1,3,5,9,0,12,13,41,22,10,51,6,8 };//��arr����
//	double brr[] = { 34.5,12.3,56.7,89.2,34.3,34.2 };//��brr����
//	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), Cmp_int);//�⺯��,��������
//	qsort(brr, sizeof(brr) / sizeof(brr[0]), sizeof(brr[0]), Cmp_double);
//	return 0;
//}


//int main()
//{
//	char arr[1000 * 1000];//���� ��С��1M
//	//char arr[1024 * 1024];//����     1M
//	//char arr[100000000] = "";//�������
//	printf("����\n");
//	return 0;
//}


char* GetMemory()
{
	//char str[] = "hello world";
	char* str = (char*)malloc(100 * sizeof(char));
	strcpy(str, "hello world");
	return str;//�Ѿ������ٵ��ڴ�
}

int main()
{
	/*char* p = GetMemroy();
	printf("%s\n", p);*/

	//��Ҫ����100M�ڴ�
	/*void* p = malloc(1024 * 1024 * 100);
	if (p == NULL)
	{
		printf("����ʧ��\n");
	}
	else
		printf("�ɹ�\n");
	getchar();*/
	
	//����100��int��Ԫ
	//int n = 100;
	//int* arr = (int*)calloc(n, sizeof(int));//arr���Կ�����100�����ȵ�int������
	//for (int i = 0; i < n; i++)
	//{
	//	arr[i] = i;
	//}

	/*char* p = GetMemory();
	printf("%s\n", p);
	free(p);*/

	//����10��int��Ԫ
	int n = 10;
	//int arr[n];//VS2022����������Ϊ���鳤��
	int* arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		arr[i] = i;
	}//ʹ�ù������ڴ治����?,��Ҫ2n����Ԫ .realloc
	arr = (int*)realloc(arr, 2 * n * sizeof(int));
	for (int i = 0; i < 2 * n; i++)
	{
		arr[i] = i;
	}
	free(arr);
	return 0;
}