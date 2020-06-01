
//
// Created by 海盗的帽子 on 2020/6/1.
//

class Person {
private://本类中使用
    char* name;
    int age;
protected://子类中能使用
    int level;
public:
    Person(char* name,int age) {

    }
};

//类继承修饰符 public
//1.public 继承：基类 public 成员，protected 成员，private 成员的访问属性在派生类中分别变成：public, protected, private
//
//2.protected 继承：基类 public 成员，protected 成员，private 成员的访问属性在派生类中分别变成：protected, protected, private
//
//3.private 继承：基类 public 成员，protected 成员，private 成员的访问属性在派生类中分别变成：private, private, private
class Student : public Person {

public:
    Student(char* name,int age):Person(name,age){

    }
};
