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

  �ݹ�:ֱ�ӻ��ӵ��ú�������
    ������:1.�߽�����;2.ǰ����;3.���ض�
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

//int main()
//{
//	printf("%d��1�ĸ���:%d\n", 123, Count(123));
//	printf("%d��1�ĸ���:%d\n", 12121, Count(12121));
//	printf("%d��1�ĸ���:%d\n", 11111, Count(11111));
//	return 0;
//}


//��5��ѧ������һ��,�ʵ�5��ѧ��������,��˵�ȵ�4��ѧ����2�ꡣ�ʵ�4��ѧ������,
//��˵�ȵ�3��ѧ����2�ꡣ�ʵ�3��ѧ��, ��˵�ȵ�2��ѧ����2�ꡣ�ʵ�2��ѧ��, ˵�ȵ�1��ѧ����
//2�ꡣ����ʵ�1��ѧ��, ��˵��10�ꡣ���ʵ�5��ѧ�����

//ѭ��ʵ��
int Age_for(int n)
{
	int temp = 10;
	for (int i = 1; i < n; i++)
	{
		temp += 2;
	}
	return temp;
}
//�ݹ�ʵ��
//Age(1):���һ���˵�����
//Age(2):��ڶ����˵�����
//Age(n):���n���˵�����
//Age(n-1):���n-1���˵�����
int Age(int n)//���n���˵�����
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


//��׳�
//0!==1,1!==1,n!=n*(n-1)!
long long Fac(int n)//Fac(n)��n�Ľ׳�
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


//��ŵ��,��n������,��a,ͨ��b,�Ƶ�c
void Hanoi(int n, char a, char b, char c)
{
	if (n == 1)//ֻ��һ������,ֱ�Ӵ�a�Ƶ�c
	{
		printf("%c->%c\n", a, c);
	}
	else
	{
		Hanoi(n - 1, a, c, b);//�������n-1�����Ӵ�aͨ��c�Ƶ�b
		printf("%c->%c\n", a, c);//���������һ����a�Ƶ�c
		Hanoi(n - 1, b, a, c);//��b�����n-1������,��bͨ��a�Ƶ�c
	}
}

int main()
{
	Hanoi(3,'A','B','C');
	return 0;
}