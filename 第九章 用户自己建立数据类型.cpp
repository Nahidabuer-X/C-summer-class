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
 结构体的普通变量,通过"."访问其成员
 结构体的指针变量,通过"->"访问其成员
 结构体指针:结构体类型 * 指针变量;

 结构体变量如何通过参数传递:结构体作为参数总是传指针(节约空间)
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



//struct Date
//{
//    int year;//年
//    int month;//月
//    int day;//日
//    //struct Date a;//错误,未定义完成
//    //struct Date* a;//可以包含一个指向自己的指针,应用很多,数据结构中经常使用
//};//结构体定义完成,它可以完成基本类型的所有事情

//struct Student
//{
//    int num;//学号
//    char name[20];//姓名
//    char sex;//性别 char sex[10]
//    int age;//年龄
//    struct Date birthday;//生日
//    char addr[100];//地址
//};

//struct Node
//{
//    int data;
//    struct Node* next;//指向下一个节点
//};

//int main()
//{
//    struct Student stu1 = {123,"刘备",'M',18,{161,6,10},"涿县"};
//
//    //把stu1年龄改为19
//    stu1.age = 19;
//    return 0;
//}



//把一个学生的信息(包括学号,姓名,性别,住址)放在一个结构体变量中,然后输出这个学生的信息
//struct Student
//{
//    int num;//学号
//    char name[20];//姓名
//    char sex[10];//性别
//    char addr[100];//住址
//};

//int main()
//{
//    struct Student stu1 = { 123,"张三","女","陕西,西安" };
//    printf("%d,%s,%s,%s\n", stu1.num, stu1.name, stu1.sex, stu1.addr);
//    return 0;
//}



//输入两个学生的学号,姓名,成绩,输出成绩较高的学生的学号,姓名,成绩
//struct Student
//{
//    int num;//学号
//    char name[20];//姓名
//    float score;//分数
//};

//int main()
//{
//    //struct Student stu1, stu2;
//    //scanf("%d%s%f", &stu1.num, &stu1.name, &stu1.score);
//    //scanf("%d%s%f", &stu2.num, &stu2.name, &stu2.score);
//    //struct Student temp;
//    //temp = stu1.score >= stu2.score ? stu1 : stu2;//temp保存分数更高的学生信息
//    //printf("%d %s %.1f", temp.num, temp.name, temp.score);
//
//    int a = 10;
//    int arr[10];
//    struct Student stu1;
//    struct Student brr[3];//定义一个struct Student结构体数组
//    struct Student crr[3] = { {123,"刘备",90},{124,"关羽",70} ,{125,"张飞",30} };
//    struct Student drr[] = { {123,"刘备",90},{124,"关羽",70} ,{125,"张飞",30} };
//
//    //输出crr的所有元素
//    for (int i = 0; i < sizeof(crr) / sizeof(crr[0]); i++)
//    {
//        printf("%d %s %.1f\n", crr[i].num, crr[i].name, crr[i].score);
//    }
//    return 0;
//}



//有三个候选人,每个选民只能投票选一人,要求编一个统计选票的程序,先后输入被选人的名字,最后输入各人得票结果
//struct Person//候选人
//{
//    char name[20];//姓名
//    int count;//票数
//};

//int main()
//{
//    struct Person arr[3] = { "刘备",0,"曹操",0,"孙权",0 };
//    char name[20];//从键盘获取投票的数据(名字)
//    int len = sizeof(arr) / sizeof(arr[0]);//候选人的数量
//    //模拟5个选民投票过程
//    int n = 5;//5个选民
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%s", &name);//从键盘读取的一个选票
//        //把选票和候选人进行对比
//        for (int j = 0; j < len; j++)
//        {
//            //if (name == arr[j].name)//错误的
//            if (strcmp(arr[j].name, name) == 0)//选票和候选人相同
//            {
//                arr[j].count++;//候选人的票数+1
//            }
//        }
//    }
//    //输出所有候选人的票数
//    for (int i = 0; i < len; i++)
//    {
//        printf("%s %d\n", arr[i].name, arr[i].count);
//    }
//    return 0;
//}



//struct Student
//{
//    char name[20];//姓名
//    int age;//年龄
//    double score;//分数
//};//32字节

//输出学生信息
//void Show(struct Student stu)//这种设计不好
//{
//    printf("%s %d %.1lf\n", stu.name, stu.name, stu.score);
//}

//void Show1(const struct Student* ps)
//{
//    printf("%s %d %.1lf\n", ps->name, ps->age, ps->score);
//}

//arr:数组起始地址
//len:数组长度
//void Show2(const struct Student* arr, int len)
//{
//    for (int i = 0; i < len; i++)
//    {
//        //printf("%s %d %.1lf\n", arr[i].name, arr[i].age, arr[i].score);
//        //printf("%s %d %.1lf\n", (arr + i)->name, (arr + i)->age, (arr + i)->score);
//        printf("%s %d %.1lf\n", arr->name, arr->age, arr->score); arr++;
//    }
//}

//int main()
//{
//    struct Student stu = { "刘备",18,90 };
//    struct Student arr[] = {"刘备",19,80,"曹操",20,90};
//    struct Student* p = &stu;
//    Show1(&stu);
//    //*p.score = 95;//错误,'.'(1)的优先级高于解引用(2)
//    //(*p).score = 95;//可以,但麻烦
//    p->score = 95;
//    Show1(&stu);
//    printf("------------\n");
//    Show2(arr, sizeof(arr) / sizeof(arr[0]));
//    /*p = arr;
//    p = &arr[0];
//    p = &arr[1];*/
//    return 0;
//}



//有n个学生的信息(包括学号,姓名,成绩),要求按照成绩的高低顺序输出各学生信息
/*
 123 刘备 80
 124 曹操 90
 125 关羽 70
 126 张飞 30
 127 孙权 100
*/
 
struct Student
{
    int num;//学号
    char name[20];//姓名
    double score;//成绩
};

//比较学生的分数.如果第一个大于第二个,就返回大于0的数字,等于返回0,小于返回小于0的数字
int Cmp_stu_sco(const void* vp1, const void* vp2)
{
    double temp = ((struct Student*)vp1)->score - ((struct Student*)vp2)->score;
    if (temp > 0)
    {
        return 1;
    }
    else if (temp < 0)
    {
        return -1;
    }
    else
        return 0;
}

//从键盘获取n个学生的数据
void Input(struct Student* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d%s%lf", &arr[i].num, &arr[i].name, &arr[i].score);
    }
}

//把n个学生按成绩进行排序
void ScoreSort(struct Student* arr, int n)
{
    qsort(arr, n, sizeof(struct Student), Cmp_stu_sco);
}

//输出n个学生的信息
void Show(const struct Student* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d %s %.1lf\n", arr[i].num, arr[i].name, arr[i].score);
    }
}

int main()
{
    struct Student arr[5];
    int len = sizeof(arr) / sizeof(arr[0]);
    Input(arr, len);//从键盘获取n个学生的数据
    ScoreSort(arr, len);//对分数进行排序
    printf("------------------\n");
    Show(arr, len);
    return 0;
}