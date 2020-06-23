//
// Created by 海盗的帽子 on 2020/6/23.
//

#include <iostream>
#include <thread>
#include <list>

using namespace std;

//c++ thread 模拟三个窗口卖票
int ticketsCount = 100; //100 张 三个窗口
std::mutex mtx ;//全局的互斥锁

//存在一个问题，出了问题unlock 不执行
void sellTicket(int index) {
    while  (ticketsCount > 0) {
        mtx.lock();
        //临界期代码段-》 原子操作
        //锁+ 双重判断
        //
        if(ticketsCount > 0) {
            cout << "窗口：" << index << "卖出第：" << ticketsCount << "张票" << endl;
            ticketsCount -- ;
        }
        mtx.unlock();
        std::this_thread::sleep_for(std::chrono::microseconds(100));
    }
}

//lock_guard
void sellTicket2(int index) {
    while  (ticketsCount > 0) {
        {
            lock_guard<std::mutex> lock(mtx);
            //{}限定 lock_guard 的作用域
            if(ticketsCount > 0) {
                cout << "窗口：" << index << "卖出第：" << ticketsCount << "张票" << endl;
                ticketsCount -- ;
            }
        }
        std::this_thread::sleep_for(std::chrono::microseconds(100));
    }
}


int main() {
    list<std::thread> list;
    for (int i = 0; i < 3; ++i) {
        list.emplace_back(sellTicket2, i);
    }

    for (std::thread &t : list) {
        t.detach();
    }
    getchar();
}

