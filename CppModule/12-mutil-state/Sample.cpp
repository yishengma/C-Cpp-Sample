//
// Created by 海盗的帽子 on 2020/6/1.
//
#include <string>
#include <iostream>

class Person {
private:
    char *name;
    int age;
public:
    Person(char *name, int age) {
        this->name = name;
        this->age = age;
    };

    ~Person();

private:

};

class Child {

};

//c++ 中的多继承，但不能存在二义性
class Student : public Person, public Child {
private:
    char *courseName;
public:
    Student(char *name, int age, char *courseName) : Person(name, age), courseName(courseName) {

    }
};


//虚继承，二义性
class A {
public:
    char *name;
};

//虚继承，保证继承过来的相同熟悉或者函数只存在一份拷贝
class B : virtual public A {

};

class C : virtual public A {

};

class D : public B, public C {

};

//3.c++ 中的多态
class Activity{
public:
    void onCreate(){
        std::cout<<"Activity 中的 onCreate"<<std::endl;
    }
};

class MainActivity : public Activity{
public:
    virtual void onCreate(){//
        std::cout<<"MainActivity 中的 onCreate"<<std::endl;
    }
};

class WelcomeActivity : public Activity{
public:
    virtual void onCreate(){//
        std::cout<<"WelcomeActivity 中的 onCreate"<<std::endl;
    }
};

void startActivity(Activity* activity) {
    activity->onCreate();
}

void printActivity() {
    Activity* a1 = new MainActivity();//父类 = new 子类
    Activity* a2 = new WelcomeActivity();

    //c++ 默认情况下是不存在多态的，没有virtual方法
    //程序在编译器期间并不知道运行的状态，只有在真正运行的过程中才会去找需要运行的方法
    startActivity(a1);
    startActivity(a2);

    //c++ 多态
    //动态多态：子父类
    //静态多态：函数的重载


}

int main() {
    D *d = new D();
//    d->name;//具有二义性，使用 virtual 继承
    d->name;

    printActivity();

}
