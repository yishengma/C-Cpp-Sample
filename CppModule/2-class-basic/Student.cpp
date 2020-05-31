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