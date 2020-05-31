//
// Created by 海盗的帽子 on 2020/5/31.
//

#include "Sample.h"
#include <iostream>
class A {
public:
    int a;
    double b;
    char c;

};

class B {
    int a;
    double b;
    char c;
    static double d;

};

class C {
    int a;
    double b;
    char c;
    static double d;

};

class D {
private:
    int age;
public:
    void change() const  {//const 在 （） 之后主要用来限制 this 关键字
//        this->age = 0;不能对类的属性进行修改
//this = const C* c const;

    }
};

//对象的大小与结构体的计算大小相似
//static 静态变量和方法并没有算到类的大小中
//类的大小只与普通属性有关
int main() {
    std::cout<<" A 的大小" << sizeof(A) << std::endl;
    std::cout<<" B 的大小" << sizeof(B) << std::endl;
    std::cout<<" C 的大小" << sizeof(C) << std::endl;

    //this 指针：代表当前的对象，因为类的方法存放在代码区，大家一起共享，所以要用 this 区分

    //
}