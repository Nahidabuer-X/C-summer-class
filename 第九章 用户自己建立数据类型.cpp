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

 枚举:如果一个变量只有几种情况,就可以使用枚举
      enum 枚举类型名{枚举列表};
    考点和使用注意事项:
    1.枚举元素默认从0开始,也就是第一个值为0,后面的值依次增1
    2.枚举值在定义时可以修改,后面的值是前面的值+1
    3.枚举值是常量,只有在定义时能修改,其他不能
    4.枚举值可以进行比较
 总结:枚举值虽然是数字,在定义时可以修改,但最好使用默认,如果一定要修改,请避免出现相同的枚举值,且在程序中应该使用枚举值,不使用数字

 typedef:类型定义.它的作用是把一个旧类型名起一个新的名字
      给一个复杂的类型起一个简单的名字
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
 
//struct Student
//{
//    int num;//学号
//    char name[20];//姓名
//    double score;//成绩
//};
//
////比较学生的分数.如果第一个大于第二个,就返回大于0的数字,等于返回0,小于返回小于0的数字
//int Cmp_stu_sco(const void* vp1, const void* vp2)
//{
//    double temp = ((struct Student*)vp1)->score - ((struct Student*)vp2)->score;
//    if (temp > 0)
//    {
//        return 1;
//    }
//    else if (temp < 0)
//    {
//        return -1;
//    }
//    else
//        return 0;
//}
//
////从键盘获取n个学生的数据
//void Input(struct Student* arr, int n)
//{
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d%s%lf", &arr[i].num, &arr[i].name, &arr[i].score);
//    }
//}
//
////把n个学生按成绩进行排序
//void ScoreSort(struct Student* arr, int n)
//{
//    qsort(arr, n, sizeof(struct Student), Cmp_stu_sco);
//}
//
////输出n个学生的信息
//void Show(const struct Student* arr, int n)
//{
//    for (int i = 0; i < n; i++)
//    {
//        printf("%d %s %.1lf\n", arr[i].num, arr[i].name, arr[i].score);
//    }
//}
//
//int main()
//{
//    struct Student arr[5];
//    int len = sizeof(arr) / sizeof(arr[0]);
//    Input(arr, len);//从键盘获取n个学生的数据
//    ScoreSort(arr, len);//对分数进行排序
//    printf("------------------\n");
//    Show(arr, len);
//    return 0;
//}



////有n个结构体变量,内含学生学号,姓名和3门课程的成绩
////要求输出平均成绩最高的学生的信息(包括学号,姓名,3门课程的平均成绩)
//struct Student
//{
//    int num;//学号
//    char name[20];//姓名
//    float score[3];//3科成绩
//    float avg;//该生平均分
//};
//
////读取学生信息
////arr:数字名;n:数组长度(学生数量)
//void Input(struct Student* arr, int n)
//{
//    printf("请输入%d个学生的信息:\n", n);
//    printf("  学号,姓名,科目一成绩,科目二成绩,科目三成绩\n");
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d%s%f%f%f", &arr[i].num, &arr[i].name, &arr[i].score[0], &arr[i].score[1], &arr[i].score[2]);
//        arr[i].avg = (arr[i].score[0] + arr[i].score[1] + arr[i].score[2]) / 3;
//    }
//}
//
////要求输出平均成绩最高的学生信息
//void ShowMax(const struct Student* arr, int n)
//{
//    int max = 0;//平均分最高的学生下标
//    float avg = arr[0].avg;//保存最高的平均分
//    for (int i = 0; i < n; i++)
//    {
//        if (arr[i].avg > avg)
//        {
//            avg = arr[i].avg;
//            max = i;
//        }
//    }
//    //'\'这个称为续行符
//    printf("平均分最高的学生信息为:\n\
//    学号:%d 姓名:%s 成绩1=%.1f 成绩2=%.1f 成绩3=%.1f 平均分=%.1f\n", arr[max].num, arr[max].name, arr[max].score[0], arr[max].score[1], arr[max].score[2], arr[max].avg);
//}
//
//int main()
//{
//    struct Student arr[5];
//    int len = sizeof(arr) / sizeof(arr[0]);
//    Input(arr, len);//读取数据
//    ShowMax(arr, len);//输出平均分最高的学生信息
//    return 0;
//}



//枚举

//enum Weekday { mon, tue, wed = 5, thu, fri, sat, sun };//星期,定义数据类型
//
//int main()
//{
//    enum Weekday d1 = mon;
//    /*if (d1 == sun)
//    {
//        printf("d1==sun\n");
//    }*/
//    printf("%d,%d,%d,%d,%d,%d,%d", mon, tue, wed, thu, fri, sat, sun);
//    return 0;
//}


//枚举不恰当的应用//////////////////////////
//口袋中有红,黄,蓝,白,黑5种颜色的球若干个.每次从口袋中先后取出3个球,问得到3种不同颜色的球的可能取法,输出每种排列的可能情况
//书上例文不太好必须是.c文件才能运行,还啰嗦,暂时不放上来
//int main()
//{
//    const char* arr[] = { "红色","黄色","蓝色","白色","黑色" };
//    int count = 0;//统计数量
//    const int n = 5;//5种不同颜色的球
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            for (int k = 0; k < n; k++)
//            {
//                if (i != j && i != k && j != k)
//                {
//                    //printf("%d %d %d\n", i, j, k);
//                    printf("%s %s %s\n", arr[i], arr[j], arr[k]);
//                    count++;
//                }
//            }
//        }
//    }
//    printf("一共%d种\n", count);
//    return 0;
//}



//枚举恰当的应用
//enum Status { ok, out_range, no_mem, busy, unkuow };//状态类型:成功,越界,内存不足,繁忙,未知错误
//
//enum Status Fun1()
//{
//    //...
//    return ok;
//}
//
//enum Status Fun2()
//{
//    //...
//    return out_range;
//}
//
//enum Status Fun3()
//{
//    //...
//    return no_mem;
//}
//
//enum Status Fun4()
//{
//    //...
//    return busy;
//}
//
//enum Status Fun4()
//{
//    //...
//    return unkuow;
//}
//
//int main()
//{
//    
//    return 0;
//}



//typedef
struct Student
{
    int num;
    char name[20];
};

typedef struct Student Student;//Student就是struct Student
typedef unsigned long long int uint64;//u:无符号; int:整数; 64:64位即8字节

//struct A
//{
//    char b;
//    float c;
//};
//
//typedef struct A A;

//或者这样写
typedef struct A
{
    char b;
    float c;
}A;//把struct A起一个新的名字A

int main()
{
    struct Student stu1;
    //Student stu2;//在C++可以,在C不可以
    Student stu3;
    unsigned long long int a = 100;
    uint64 b;
    return 0;
}