#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<complex>
#include<math.h>
#include<stdlib.h>



/*
 '\0':是字符串的结尾标记,但在文件中是不可见或者用NUL表示
 文件:
     文件概念
         输入流:从外存到内存.例如从硬盘打开一本书,播放一个电影
         输出流:从内存到外存.例如保存文档
         输入设备:触摸板,触摸屏,鼠标,键盘(标准输入设备)
         输出设备:屏幕(标准输入设备),打印机
        文件分类:
                文本(ASCII)文件:能直接查看的文件,都是文本(字符)数据
                二进制文件:不能直接查看,都是二进制数据.
     文件操作
         文件类型指针:FILE*, 文件操作中的唯一凭证
         fopen:打开,一定注意文件路径中\的写法.例如D:\\1.txt
         fclose:关闭文件
         fwrite:把内存的数据往文件中写.(fputc)
         fread:从文件中读取数据到内存,返回值很重要
         fseek:改变文件读写位置标记
     文件读写位置标记.光标(图形界面的说明).读写时自动移动
         顺序读写
         随机读写:改变文件读写位置标记(光标)
*/



//int main()
//{
//    //printf("D\1.txt")错误的路径
//    //printf("D:\\1.txt");//在字符串中'\'表示转义字符,如果需要表示字符本身需要写两个
//    FILE* fw = fopen("D:\\1.txt", "w");//创建一个D:\\1.txt
//    const char* str = "hello hhh";
//    fwrite(str, sizeof(char), strlen(str), fw);//没有写'\0'
//    fwrite(str, sizeof(char), strlen(str)+1, fw);//有写'\0'
//    fclose(fw);
//    return 0;
//}



//从键盘输入一些字符,并逐个把它们送到磁盘上去,直到用户输入一个'#'为止
//int main()
//{
//    FILE* fw = fopen("D:\\1.txt", "w");//写打开失败的原因:文件路径错误
//    //FILE* fr = fopen("D:\\1.txt", "r");//读打开失败的原因:1.文件不存在;2.文件路径错误
//    if (fw == NULL)
//    {
//        printf("打开文件失败,请检查文件路径是否正确\n");
//        return 0;
//    }
//    char ch;
//    while ((ch = getchar()) != '#')
//    {
//        //fwrite(&ch, sizeof(char), 1, fw);//应用更广
//        fputc(ch, fw);//只能输出字符,可替代
//    }
//    fclose(fw);
//    return 0;
//}



//从文件中读取字符串
//int main()
//{
//    FILE* fr = fopen("D:\\1.txt", "r");
//    if (fr == NULL)
//    {
//        printf("打开文件失败,请检查文件路径是否正确\n");
//        return 0;
//    }
//    char buf[100];//存放读取的数据
//    int len = fread(buf, sizeof(char), 100, fr);
//    printf("%d %s\n", len, buf);
//    fclose(fr);
//    return 0;
//}



//将一个文件中的数据复制到另一个文件中
//fputc:往文件写一个字符(只能读写文本文件,其他可能会出错,速度慢)
//fgetc:从文件读一个字符(只能读写文本文件,其他可能会出错,速度慢)
//int main()
//{
//    FILE* fr = fopen("D:\\file1.dat", "r");
//    FILE* fw = fopen("D:\\file2.dat", "w");
//    if (fr == NULL || fw == NULL)
//    {
//        printf("打开文件失败,请检查文件路径是否正确\n");
//        return 0;
//    }
//    //从fr读数据写到fw
//    char ch;
//    /*while ((ch = fgetc(fr)) != EOF)
//    {
//        fputc(ch, fw);
//    }*/
//    while (fread(&ch, sizeof(char), 1, fr) > 0)
//    {
//        fwrite(&ch, sizeof(char), 1, fw);
//    }
//    fclose(fr);
//    fclose(fw);
//    return 0;
//}



//从键盘输入10个学生的有关数据,然后把他们转存到磁盘文件上去
typedef struct Student
{
    char name[20];//姓名
    int num;//学号
    int age;//年龄
    char addr[100];//地址
}Student;

//从键盘获取n个学生信息,存放到arr数组
void Input(Student* arr, int n)
{
    printf("请输入%d个学生信息:\n",n);
    printf("姓名 学号 年龄 地址");
    for (int i = 0; i < n; i++)
    {
        scanf("%s%d%d%s", &arr[i].name, &arr[i].num, &arr[i].age, &arr[i].addr);
    }
}

//把arr的数据保存到文件
void Save(Student* arr, int n)
{
    FILE* fw = fopen("1.txt", "wb");//相对路径,1.txt和当前源文件在同一个目录(文件夹).b:二进制
    if (fw == NULL)
    {
        printf("打开文件失败,请检查文件路径是否正确\n");
        return;//退出函数
    }
    //把数据写入文件
    /*for (int i = 0; i < n; i++)
    {
        fwrite(&arr[i], sizeof(Student), 1, fw);
    }*/
    fwrite(arr, sizeof(Student), n, fw);
    fclose(fw);
}

//写二进制数据
//int main()
//{
//    Student stu[10];
//    int len = sizeof(stu) / sizeof(stu[0]);//长度
//    Input(stu, len);
//    Save(stu, len);
//    return 0;
//}

//读二进制文件的数据(从二进制文件读取学生输出信息并输出到屏幕)
void Show()
{
    FILE* fr = fopen("1.txt", "rb");
    if (fr == NULL)
    {
        printf("打开文件失败,请检查文件路径是否正确\n");
        return;//退出函数
    }
    Student stu;//保存从文件读取的数据
    while (fread(&stu, sizeof(Student), 1, fr) > 0)
    {
        //把stu的数据输出到屏幕
        printf("%s %d %d %s\n", stu.name, stu.num, stu.age, stu.addr);
    }
    fclose(fr);
}

//int main()
//{
//    Show();
//    return 0;
//}



//fseek的简单应用
//把D:\\1.txt文件的内容(前提有该文件,并有数据).读两次并输出到屏幕
//int main()
//{
//    FILE* fr = fopen("D:\\1.txt", "r");
//    if (fr == NULL)
//    {
//        printf("打开文件失败,请检查文件路径是否正确\n");
//        return -1;//退出函数
//    }
//    char buf1[100] = "";
//    int len1;
//    char buf2[100] = "";
//    int len2;
//    //len1 = fread(buf1, sizeof(char), 100, fr);
//    //len2 = fread(buf2, sizeof(char), 100, fr);//第二次读取为空的原因是已经到达文件末尾
//
//    len1 = fread(buf1, sizeof(char), 100, fr);
//    //fseek(fr, 0, SEEK_SET);//文件开头作为参照
//    //fseek(fr, -len1, SEEK_CUR);//当前文件位置指针作为参照点
//    fseek(fr, -len1, SEEK_END);//文件末尾作为参照点
//    len2 = fread(buf2, sizeof(char), 100, fr);
//
//    printf("%d %s\n", len1, buf1);
//    printf("%d %s\n", len2, buf2);
//    return 0;
//}



//在磁盘文件上存有10个学生数据.要求第1,3,5,7,9个学生数据输入计算机,并在屏幕上显示出来.
//int main()
//{
//    FILE* fr = fopen("1.txt", "rb");
//    if (fr == NULL)
//    {
//        printf("打开文件失败,请检查文件路径是否正确\n");
//        return -1;//退出函数
//    }
//    Student stu;
//    int len;
//    for (int i = 0; i < 5; i++)//读五个学生信息(1,3,5,7,9)
//    {
//        len = fread(&stu, sizeof(Student), 1, fr);
//        if (len < 1)
//        {
//            printf("文件结束了\n");
//            break;
//        }
//        printf("%s %d %d %s\n", stu.name, stu.num, stu.age, stu.addr);
//        fseek(fr, sizeof(Student), SEEK_CUR);//跳过一个学生
//    }
//    fclose(fr);
//    return 0;
//}