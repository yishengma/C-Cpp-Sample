//
// Created by 海盗的帽子 on 2020/6/23.
//

/**
 thread mutex condition_variable
 lock_quard
 unique_lock
 atomic
 sleep_for

 语言层面的 thread 底层
 window : createThread
 linux : pthread_create

 //strace ./a.out 可查看
 */

#include <thread>
#include <iostream>
//一.创建一个线程 std::thread
//通过可变参数传递参数

//二.子线程如何结束
//子线程函数执行完就结束

//三.主线程如何处理子线程
//join
//detach

void threadHandle1(int time) {
    //让子线程睡眠 2 s
    std::this_thread::sleep_for(std::chrono::seconds(time));
    std::cout << "hello thread1" << std::endl;
}

void threadHandle2(int time) {
    //让子线程睡眠 2 s
    std::this_thread::sleep_for(std::chrono::seconds(time));
    std::cout << "hello thread2" << std::endl;
}

int main() {
    //创建了一个线程对象，传入一个线程函数，新线程就开始运行了
    std::thread t1(threadHandle1,2);
    //主线程等待子线程结束
    //主线程继续往下执行
    //主线程需要等待子线程完成
    t1.join();


    std::thread t2(threadHandle1,3);
    //把子线程设置为分离线程
    //主线程不需要等待子线程完成
    t2.detach();

    std::cout << "main thread done" << std::endl;
}
