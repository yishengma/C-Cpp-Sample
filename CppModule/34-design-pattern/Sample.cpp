//
// Created by 海盗的帽子 on 2020/6/23.
//

#include <mutex>
std::mutex mtx;
class Singleton {
public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            std::lock_guard<std::mutex> lockGuard(mtx);
            if (instance == nullptr) {
                //开辟内存             开辟内存
                //构造对象             给 instance 赋值
                //给 instance 赋值     构造对象
                instance = new Singleton();
            }
        }
        return instance;
    }
private:
    static Singleton* volatile instance;//唯一的类的实力对象
    //构造函数私有化
    Singleton(){}

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};



class SingleTon2 {
public:
    static SingleTon2* getInstance() {
        //函数静态变量初始化，在汇编指令上已经自动添加线程互斥指令
        //g++ -o run Sample2.cpp
       static SingleTon2 instance;
       return &instance;
    }
private:
    //构造函数私有化
    SingleTon2(){}

    SingleTon2(const SingleTon2&) = delete;
    SingleTon2& operator=(const SingleTon2&) = delete;
};


int main() {
    SingleTon2* p1 = SingleTon2::getInstance();
//    Singleton* p2 = Singleton::getInstance();
//    Singleton* p3 = Singleton::getInstance();

}