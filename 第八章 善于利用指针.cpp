#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<complex>
#include<math.h>


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