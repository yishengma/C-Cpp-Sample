//
// Created by 海盗的帽子 on 2020/5/31.
//


#include <cstdlib>
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


int main() {
    Student stu1 ;//1.默认调用空参数的构造函数，在栈内开辟的内存

    Student stu2("ABC",10);//2.调用两个参数的构造函数，，在栈内开辟的内存

    Student* stu3 = new Student("ABC",20);//3.使用 new 关键字，会调用构造函数和析构函数
    delete stu3;//new 和 delete 配套

    Student* stu4 = (Student*)malloc(sizeof(Student));//4.使用malloc的方式，并没有调用空参数的构造函数和析构函数
    free(stu4);//malloc 和 free 配套








}