//
// Created by 海盗的帽子 on 2020/5/29.
//

#include <stdio.h>
struct Worker{

};
typedef Worker Farmer ;//取别名
//同下
typedef struct Person {

}Person;

union Student{
    char name[10];
    int age;
};

enum Type{
    TEXT,
    IMAGE
};

//int main() {
//    //最多只能出现一个，
//    //大小计算（不用累加，找最大值）
//    //扩大为基本数据类型整除
//    Student student;
//    printf("Student%d",sizeof(Student));
//}