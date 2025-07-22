#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<complex>
#include<math.h>
#include<stdlib.h>


/*
 用户自定义数据类型
     比如保存50个学生的信息(姓名(字符数组),年龄(int),分数(double))
   自定义一个学生的数据类型
   自定义数据类型
     struct类型名
     {
          成员列表
     };
 利用自定义类型来创建变量

 自定义结构体
*/


//struct Student
//{
//    char name[20];//姓名
//    int age;//年龄
//    double score;//分数
//};//定义(申明)完成,该类型和基本类型一致(基本类型能做的事情,它都可以)

//int main()
//{
//    struct Student stu1;//定义一个Student类型的变量stu1,没有初始化
//    struct Student stu2 = { "刘备",18,90 };
//	return 0;
//}


struct Date
{
    int year;//年
    int month;//月
    int day;//日
    //struct Date a;//错误,未定义完成
    //struct Date* a;//可以包含一个指向自己的指针,应用很多,数据结构中经常使用
};//结构体定义完成,它可以完成基本类型的所有事情

struct Student
{
    int num;//学号
    char name[20];//姓名
    char sex;//性别 char sex[10]
    int age;//年龄
    struct Date birthday;//生日
    char addr[100];//地址
};

struct Node
{
    int data;
    struct Node* next;//指向下一个节点
};

int main()
{
    struct Student stu1 = { 123,"刘备",'M',18,161,6,10,"涿郡 涿县" };
    return 0;
}