//
// Created by 海盗的帽子 on 2020/5/31.
//

#ifndef C_CPP_SAMPLE_STUDENT_H
#define C_CPP_SAMPLE_STUDENT_H


class Student {
public:
//    static int age = 0;
    //静态属性在 C++ 中必须初始化，这里只能定义
    static int age;

    static void setAge(int age);
};


#endif //C_CPP_SAMPLE_STUDENT_H
