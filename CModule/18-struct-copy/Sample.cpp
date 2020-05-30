#include <cstring>
#include <cstdlib>

//
// Created by 海盗的帽子 on 2020/5/30.
//结构体套指针需要，需要对结构体指针进行初始化
typedef struct Student {
    char *name;
    int age;
};

//结构体的偏移量
//1.获取内部元素的偏移量
//2.获取结构大小 sizeof
//3.结构体大小，根据每个偏移量计算出来的，结构体大小跟变量内存位置摆放有关
//4.内部偏移量字节对齐是针对后面这个数据来看的
//5.把最小字节数尽量的往后靠，结构体一旦定义了不要轻易挪动
struct Person {
    int number;//4 个字节
    char sex;//4 个字节 （字节对齐，针对age的字节）
    int age;// 4 个字节
    char name[10]; //10 个字节
    //以上总的字节数是 24 （22+补齐基本数据类型的倍数）
    //这里是一个一个往下加的，不是一起的算的
    struct Student student;
    //
};

void copyTo(Student *s1, Student *s2) {
    *s1 = *s2;//指针的赋值是浅拷贝
}

void deepCopy(Student* s1,Student* s2) {//深
    s2->name = (char *)malloc(sizeof(char )*20);
    strcpy(s2->name,s1->name);
}


int main() {
    Student stu = {"jack", 23};
//    stu.name = "A";

//   下面是错误的，相当于将 "B" 往这个指针的内存内拷贝数据
//    strcpy(stu.name,"B");
//  需要先这样
    stu.name = (char *) malloc(sizeof(char) * 20);


    Student s1 = {};
    Student s2 = {};

    copyTo(&s1, &s2);//指针的赋值运算是浅拷贝

}