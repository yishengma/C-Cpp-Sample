//
// Created by 海盗的帽子 on 2020/5/31.
//

//真正的开发过程中，cpp 或者 c 文件最终会编译成 dll 或者 so 库调用
//所以为了确保能够正常被调用，我们一般需要定义.h 头文件

//实现的方法的使用要命名空间 xxx::xxxx()
#ifndef C_CPP_SAMPLE_STUDENT_H
#define C_CPP_SAMPLE_STUDENT_H
class Student {
private://私有，包装，影响下面所有属性
    char* name;
    int age;
public://

    void setAge(int age);
    void setName(char *name);

    int getAge();
    char* getName();
};
#endif //C_CPP_SAMPLE_STUDENT_H
