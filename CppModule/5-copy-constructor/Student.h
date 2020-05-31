//
// Created by 海盗的帽子 on 2020/5/31.
//

#ifndef C_CPP_SAMPLE_STUDENT_H
#define C_CPP_SAMPLE_STUDENT_H


class Student {
public:

    Student() {

    }
    Student(char * name):Student(name,0){

    }

    Student(char*name,int age){

    }
    //拷贝构造函数，对象会有一个默认的拷贝构造函数，用来对象之间的赋值
    //这里默认是浅拷贝
    Student(const Student& student) {//常量引用
        //在动态内存上一定要用深拷贝
        //
    }

};




#endif //C_CPP_SAMPLE_STUDENT_H
