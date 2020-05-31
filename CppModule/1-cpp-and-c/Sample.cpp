//
// Created by 海盗的帽子 on 2020/5/31.
//

//c++ 代码中可以混编c代码，c++里面写c代码也可以调用
//c++ 面向对象，c 面向过程

#include <iostream>

using namespace std;//命名空间（java 中的内部类）

//指针交换
void swap(int* a,int* b) {
    int temp = 0;
    temp = *a;
    *b = *a;
    *a = temp;
}

//引用交换
void swap(int& a,int& b) {
    int temp = a;
    a = b;
    b = temp;
}

struct Student{
    int age;
};

//常量引用，不能修改和不能重新赋值
void change(const Student s) {
//    s = NULL;
//    s.age = 10;
}

//函数重载和默认参数
int add(int num1,int num2 = 200) {

}
//在 c 中不允许函数的重载，因此使用 extern C {}; 变异
int add(int num1,int num2,int num3) {

}

int main_() {

    std::cout << "Hello world" << std::endl;

    const int number = 10;//常量

    //常量
//    int* numer = &number;//不能通过地址修改值，
//在 c 是可以修改的，在c 中是可以的


    int a = 100;
    int b = 200;
    //引用：四驱模型值的拷贝，引用其实是地址赋值，可以看成同一块内存空间的别名
    swap(a,b);//


    int a1 = 100;
    int& b1 = a;//相当于给 a 指向的内存取另一个别名


    //常量引用
//    change()
}