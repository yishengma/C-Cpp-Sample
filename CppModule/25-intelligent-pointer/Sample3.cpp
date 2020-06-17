//
// Created by 海盗的帽子 on 2020/6/17.
//
#include <thread>
#include <iostream>

using namespace std;

class A {

};

void handle_A(A *p) {

}

void handle_B(weak_ptr<A> p) {

    shared_ptr<A> sp = p.lock();
    if(sp != nullptr) {
        //调用 sp 的方法
        //弱智能指针通过 p.lock 获取sp方法

    }else {
        std::cout << "不能调用了" << std::endl;
    }
}


int main() {
    {
        //A *p = new A();
        shared_ptr<A> p(new A());
//    thread t1(handle_A, p);
        thread t1(handle_B, weak_ptr<A>(p));
        t1.detach();
    }
}

//智能指针的删除器 deletor
//unique_ptr  shared_ptr
//

//自定义删除器
template<typename T>
class Deletor {
public:
    void operator() (T* ptr) const {
        delete [] ptr;
    }
};
int test() {
    unique_ptr<int,Deletor<int>>(new int[100]);

    //lambda 表达式 函数对象
    unique_ptr<int,function<void(int*)>> ptr1 (new int [100],[](int*p)->void{
        delete[] p;
    });

}