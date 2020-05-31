//
// Created by 海盗的帽子 on 2020/5/31.
//


#include "Student.h"

void Student::setAge(int age) {
    this->age = age;
}
void Student::setName(char *name) {
    this->name = name;
}
int Student::getAge() {
    return age;
}
char* Student::getName() {
    return name;
}


void main() {
    Student stu1 ;//1.默认调用空参数的构造函数

    Student stu2("ABC",10);//2.调用两个参数的构造函数

    Student* stu3 = new Student("ABC",20);//3.使用 new 关键字

    Student* stu4 = (Studen*)malloc(sizeof(Student));//4.使用malloc的方式，并没有调用空参数的构造函数








}