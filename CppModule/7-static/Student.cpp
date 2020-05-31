//
// Created by 海盗的帽子 on 2020/5/31.
//

#include "Student.h"
//初始化必须这么写
int Student::age = 12;

//静态可以直接用类名操作，
//静态的属性必须初始化（实现）
//
static void setAge(int age) {
    Student::age = age;
}