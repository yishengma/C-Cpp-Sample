//
// Created by 海盗的帽子 on 2020/6/10.
//

#include <thread>
#include <iostream>
#include <mutex>

#include <stdlib.h>

//不带参数的线程
void hello_thread() {
    std::cout << "thead" << std::endl;
}

void simple_thread() {
    std::thread t1(hello_thread);
    t1.join();
    std::cout << "simple_thread" << std::endl;
}

//带参数的线程
int msum(int a,int b) {
    int c = a + b;
    std::cout << a << "+" << c << "=" << std::endl;
}

void var_thread() {
    std::thread t1(msum,1,2);
    t1.join();
    std::cout << "var_thread" << std::endl;

}

//join 函数
//主线等待子线程运行结束后方可执行下一步
void thread_1() {
    std::cout << "thread_1\n" << std::endl;
}


void thread_2() {
    std::cout << "thread_2\n" << std::endl;
}

void  join_test() {
    std::thread t1(thread_1);
    t1.join();
    std::thread t2(thread_2);
    t2.join();
}

//detach 是子线程，不用让main 等待
void detach_test() {
    std::thread t1(thread_1);
    std::thread t2(thread_2);

    t1.detach();
    t2.detach();
}
//数据同步
std::mutex mt;
int data = 1;

void add_thead(int a) {
    for (int i = 0; i < 100; ++i) {
        mt.lock();
        data += a;
        std::cout << "add data = " << data << std::endl;
        mt.unlock();
    }
    std::cout << "add data =" << data << std::endl;

}

void sub_thread(int b) {
    for (int i = 0; i < 100; ++i) {
        mt.lock();
        data-=b;
        std::cout << "sub data = " << data << std::endl;
        mt.unlock();
    }
    std::cout << " data = " << data << std::endl;

}

int mutex_test() {
    std::thread t1(add_thead,1);
    std::thread t2(sub_thread,1);
    t1.detach();
    t2.detach();
}


int main() {
    mutex_test();

    std::cout << "main\n" << std::endl;
    getchar();

}