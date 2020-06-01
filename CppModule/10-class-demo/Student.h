//
// Created by 海盗的帽子 on 2020/5/31.
//

#ifndef C_CPP_SAMPLE_STUDENT_H
#define C_CPP_SAMPLE_STUDENT_H


class Student {
private:
    int age;
    char* name;
public:
    static int tag;
public:
    Student();
    Student(char* name);
    Student(char* name,int age);

    ~Student();

    Student(const Student& student);
public:
    void setAge(int age);
    void setName();

    char* getName();
    void print() const;

    static void changeTag();

    friend void changeAge(Student* student,int age);

};


#endif //C_CPP_SAMPLE_STUDENT_H
