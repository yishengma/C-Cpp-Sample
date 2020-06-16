//
// Created by 海盗的帽子 on 2020/6/16.
//
#include <iostream>

using namespace std;

class Test {
public:
    Test(int a = 10) : a(a) {
        cout << "Test " << a << "赋值函数" << endl;
    }

    ~Test() {
        cout << "Test " << a << "析构函数" << endl;
    }

    Test(const Test &test) {
        cout << "Test " << a << "拷贝函数" << endl;
    }

    Test &operator=(const Test &text) {
        a = text.a;
        cout << "Test " << text.a << "赋值函数" << endl;
    }

private:
    int a;
};

Test t1(1);//全局变量先构造，在 main 函数之前

int main() {
    cout << "main" << endl;
    Test t2(20);

    Test t3 = t2;

    //静态局部变量，先分配内存，但是程序执行的时候才初始化
    //这里优化（Test t4(30)）
    static Test t4 = Test(30);

    t2 = Test(4);//临时对象构造，拷贝构造，析构

    t2 = (Test)30;//临时对象构造，拷贝构造，析构

    t2 = 40;//临时对象构造，拷贝构造，析构

    Test *p1 = new Test(50);//堆上对象构造，拷贝构造，只有delete 的时候释放

    Test *p2 = new Test[2];

//    Test *p = &(Test(40));
//    Test &ref = Test(50);

    delete p1;
    delete[] p2;
}