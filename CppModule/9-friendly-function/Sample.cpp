//
// Created by 海盗的帽子 on 2020/5/31.
//

class Person{
private:
    int age;
public:
    Person(int age) {
        this->age = age;
    }

    //友元函数的声明
    friend void friend_change(Person* p,int age);
};

//友元函数的定义，可以修改private 属性，不需要使用类命名空间
void friend_change(Person* p,int age) {
    //修改一下age 的值
    //在类的内部才能访问私有属性
//    p->age = age;
}

class FriendA {
public:
    friend class FriendB;//B是A的友元类
private:
    int a;
public:
    int getA() {
        return a;
    }
};

class FriendB {
public:
    FriendA friendA;
    void setAge(int number) {
        friendA.a = number;//可以修改a
    }

};