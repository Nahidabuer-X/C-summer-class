#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include <complex>


/*
 �⺯��:��Ĺ�˾(΢��)�Ѿ�ʵ�ֺõ�,����ֱ��ʹ��
 �Զ��庯��:�Լ�����ͬ��Ŀ�����Աʵ�ֵ�
 ����:
   1.���ܸ�����
   2.��ߴ����ʹ����
  ����ֵ ������(�����б�)
  {
      ������
  }
  ������:ÿ����������Ҫһ����һ�޶�������(��ʶ��)
  void:û��,�������η���ֵ(����д)���߲����б�(����ʡ��)
  ����������ɺ�,�������Զ�ִ��
  ����ֵ:��������Ľ��ͨ������ֵ���ظ���������
  ���ú���.
  �������������ں���ʹ��(����)�ĺ���,��ô��ǰ������к�������
  ��������û������,���������������ƺ����ڲ����ܶ�����һ������
*/


void Max1()//��������
{
	int a;
	int b;
	scanf("%d%d", &a, &b);
	int c = a >= b ? a : b;//���ֵ
	printf("%d\n", c);
}

void Max2(int a,int b)//a,b��Ϊ��ʽ����,�β�,ע�����Ѿ�������,������ͨ��scanf��ȡ
{
	int c = a >= b ? a : b;
	printf("%d\n", c);
}

int Max4(int a, int b)//a,b��Ϊ��ʽ����,�β�,ע�����Ѿ�������,������ͨ��scanf��ȡ
{
	int c = a >= b ? a : b;
	return c;//����c
}

int Max3(int a, int b,int c )
{
	int d = Max4(a, b);//int d = void(û��)
	int e = Max4(c, d);
	return e;
	//Max2(Max2(a, b), c);
}


//�����������ֵ
//int main(void)//��ʽ
//int main()//����һ�еȼ�
//{
//	//int a;
//	//int b;
//	//scanf("%d%d", &a, &b );
//	//int c = a >= b ? a : b;//���ֵ
//	//printf("%d\n", c);
//
//	//Max1();//��������
//	//pow(5, 3);
//	//int a = 10;
//	//printf("%d\n", a);
//
//	//int x = Max4(10, 20);
//	//int a = 100;
//	//int b = 200;
//	//int y = Max4(a, b);//a,bʵ�ʲ���,ʵ��
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

//int main()//�������Ķ���
//{
//	/*int Max(int a, int b);
//	return a >= b ? a : b;*///�����,������main�����ڲ�������һ������
//	return 0;
//}

//void A()
//{
//	//void B()//�����,������A�����ж�����һ������B
//	//{
//	//	printf("B\n");
//	//}
//	printf("A\n");
//}


//ͳ��һ��������1�ĸ���(��������)
//����:123->1 ;12121->3 ;11111->5
//n:��Ҫͳ�Ƶ�����
//����ֵ:����1�ĸ���
int Count(int n)
{
	int sum = 0;//ͳ��1�ĸ���
	while (n != 0)
	{
		if (n % 10 == 1)//�ø�λ
		{
			sum++;
		}
		n /= 10;
	}
	return sum;
}

int main()
{
	printf("%d��1�ĸ���:%d\n", 123, Count(123));
	printf("%d��1�ĸ���:%d\n", 12121, Count(12121));
	printf("%d��1�ĸ���:%d\n", 11111, Count(11111));
	return 0;
}