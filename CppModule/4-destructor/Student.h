//
// Created by 海盗的帽子 on 2020/5/31.
//

#ifndef C_CPP_SAMPLE_STUDENT_H
#define C_CPP_SAMPLE_STUDENT_H


class Student {
public:

    Student(){
        this->name = malloc(sizeof(char)*100);
    }

    //析构函数，在对象被回收的时候调用
    ~Student(){

        free(this->name);
        this->name = NULL;
    };

private:
    char* name;
};


#endif //C_CPP_SAMPLE_STUDENT_H
