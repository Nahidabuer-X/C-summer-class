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
int main()
{
	int arr[10] = { 1,3,5,7,9,11,13,15,17,19 };
	//int* p = &arr[0];//��һ��Ԫ��int�ĵ�ַ
	int* p = arr;//����һ�еȼ�
	printf("%d,%d\n", arr[0], *p);

	printf("%d\n", sizeof(arr));//��������Ĵ�С
	printf("%d,%d\n", &arr, &arr + 1);//&arr+1��ʾ����������Ĵ�С(�ֽ���)
	return 0;
}