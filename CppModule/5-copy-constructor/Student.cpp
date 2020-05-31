//
// Created by 海盗的帽子 on 2020/5/31.
//

#include "Student.h"

Student getStudent(char *name) {
    Student stu(name);
    return stu;
}

void printStudent(Student student) {//这个对象是方法栈中的新的对象，调用的是拷贝构造函数
    //方法结束后会调用拷贝构造函数
    //这里是浅拷贝
}

int main() {
    Student stu1("ABC",20);

    //如果是指针的赋值不会调用拷贝构造函数
    //是赋值，把里面所有定义的属性赋值，c/c++ 编译器帮我们做，内部调用的是拷贝构造函数
    Student stu2 = stu1;



    Student stu3("ABC",40);

    Student stu4;//生命变量，调用默认构造函数，但是会赋值，和c类似
    stu4 = stu3;//不会调用拷贝构造函数


    //第二种场景，作为参数返回的时候会调用拷贝构造函数
    Student stu5 = getStudent("AV");//方法里面的对象被析构了，调用了拷贝构造函数


    //第三种场景,作为参数传递的时候会调用拷贝构造函数
    printStudent(stu4);
}