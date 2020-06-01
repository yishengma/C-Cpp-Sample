//
// Created by 海盗的帽子 on 2020/5/31.
//

#include "Student.h"

int Student::tag = 0;

Student::Student(char* name):age(0) {
    this->name = name;
}

Student::Student(char *name, int age) {
    this->name = name;
    this->age = age;
}
//析构函数
Student::~Student() {

}
//拷贝构造函数
Student::Student(const Student &student) {

}
void Student::setAge(int age){

}
void Student::setName(){

}

char* Student::getName(){

}

//const 方法
void Student::print() const {

}

void Student::changeTag() {

}

//实现友元方法
void changeAge(Student* student,int age) {
    student->age = age;
}









