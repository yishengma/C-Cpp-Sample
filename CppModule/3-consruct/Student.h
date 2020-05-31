//
// Created by 海盗的帽子 on 2020/5/31.
//

#ifndef C_CPP_SAMPLE_STUDENT_H
#define C_CPP_SAMPLE_STUDENT_H
class Student {
public:
    Student(){
        //空参数构造函数
    };
    Student(char * name){
        //一个参数构造函数
    };
    Student(char* name,int age){
        //两个参数构造函数
    };

    //构造函数参数初始化
    Student(char *name,int age,int level):age(0){

    }

    //构造函数调用构造函数
    Student(char* name,int age,int level,int rank):Student(name,age){

    }
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
