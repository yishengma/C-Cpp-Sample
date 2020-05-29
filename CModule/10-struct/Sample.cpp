//
// Created by 海盗的帽子 on 2020/5/29.
//

#include <cstring>
#include <cstdlib>
#include <stdio.h>
struct Work {
    char name[10];
    int level;
};
struct Worker{
    char name[10];
    int age;
    double salary;
    struct Work work;//结构体的嵌套
    Work work3;
}jack;//这里会有一个默认初始值

int struct_pointer() {
    struct Worker worker = {"name",10,100.3};
    Worker* worker_p = &worker;
//    worker_p->name = "23";
    strcpy(worker_p->name,"Worker pointer");
    worker_p->age = 11;


    Worker* worker1 = (Worker*)malloc(sizeof(Worker));
    free(worker1);
}


int struct_array() {
    //静态内存开辟
    Worker worker[10];

    //动态内存开辟
    Worker* worker_p = (Worker*)malloc(sizeof(Worker)*10);

    strcpy(worker_p[1].name,"Worker name");
}

struct WorkSize {
    char name[18];
    int age;
    double level;
};

int struct_size() {
    int size = sizeof(WorkSize);
    printf("大小：%d",size);

   //计算的规则
   //1.基本数据类型按照最大的字节去计算
   //2.然后加上非基本数据类型的
   //3.字节对齐为 最大字节数 的倍数
}

//int main() {
//    //这里的没有默认初始值
//    struct Worker worker = {"Name",10,100.0};
////    worker.name = "Ethan";
//    strcpy(worker.name,"Joker");
//    worker.age = 10;
//
//}