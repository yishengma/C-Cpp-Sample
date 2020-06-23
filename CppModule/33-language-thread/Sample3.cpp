//
// Created by 海盗的帽子 on 2020/6/23.
//

//多线程编程两个问题
//-线程间的互斥问题
//保证临界区代码段的原子操作 -》 互斥锁 -》 无锁cas
//-线程间的同步通信问题
//生产者-消费者模型
#include <iostream>
#include <thread>
#include <condition_variable>
#include <queue>
//c++ std 容器都是线程不安全的
std::mutex mtx;//定义互斥锁，定义线程间的互斥
std::condition_variable cv;//定义条件变量做线程同步通信
using namespace std;
class Queue {
public:
    void put(int val) {
        unique_lock<std::mutex> lck(mtx);
        while (!que.empty()) {
            //生产者应该进入阻塞状态，并且把 mtx 互斥锁释放
            cv.wait(lck);
        }

        que.push(val);
        //通知其他线程
//        cv.notify_one()
        cv.notify_all();
        cout << "生产者 生产：" << val << "号物品" << endl;
    }

    int get() {
        unique_lock<std::mutex> lck(mtx);
        while (que.empty()) {
            cv.wait(lck);
        }
        int val = que.front();
        que.pop();
        cv.notify_all();
        cout << "消费者 消费：" << val << "号物品" << endl;
        return val;
    }
private:
    queue<int> que;
};
void producer(Queue* queue) {
    for (int i = 0; i < 10; ++i) {
        queue->put(i);
        std::this_thread::sleep_for(std::chrono::microseconds (111));
    }
}

void consumer(Queue* queue) {
    for (int i = 0; i < 10; ++i) {
        queue->get();
        std::this_thread::sleep_for(std::chrono::microseconds (222));
    }
}

int main() {
    Queue* queue = new Queue();
    std::thread t1(producer,queue);
    t1.detach();

    std::thread t2(consumer,queue);
    t2.detach();

    getchar();
}

/**
 unique_lock
 condition_variable

 lock_guard/unique_lock

    lock_guard 不能用在函数参数传递或者返回过程，内部是 scoped_lock ,没有拷贝构造函数

    unique_lock 不仅可以使用在简单的临界区代码段的互斥锁操作中，还能用在函数调用的过程中


 cv.notify_all() 通知在 cv 上等待的线程，条件成立了，线程执行

 */


