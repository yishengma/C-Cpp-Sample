//
// Created by 海盗的帽子 on 2020/5/31.
//
#include <iostream>
#include "Student.h"


int main() {
    Student* student= new Student;
    student->setAge(10);
    student->setName("ABC");

    std::cout<< student->getName() << std::endl;
    //开发过程中直接写在 Student.cpp 是一个单独的cpp 文件
    //在编译成 so 库过后不存在，因此需要头文件

}