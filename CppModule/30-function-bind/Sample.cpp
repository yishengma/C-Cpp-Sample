//
// Created by 海盗的帽子 on 2020/6/18.
//
/**

bind 绑定器=>返回的结果还是一个函数对象
参数占位符 placeholders::_1
 */
#include <string>
#include <iostream>
#include <vector>
#include <thread>

using namespace std;
using namespace placeholders;
void hello(string str) { cout << str << endl; }
int sum(int a, int b) { return a + b; }
class Test
{
public:
    int sum(int a, int b) { return a + b; }
};
int main() {
    bind(hello, "hello bind!")();
    cout << bind(sum, 10, 20)() << endl;
    cout << bind(&Test::sum, Test(), 20, 30)() << endl;

    bind(hello, _1)("hello bind 2!");
    cout << bind(sum, _1, _2)(200, 300) << endl;

    function<void(string)> func1 = bind(hello, _1);
    func1("hello china!");
    func1("hello shan xi!");
    func1("hello si chuan!");
}
class Thread
{
public:
    Thread(function<void(int)> func, int no) :_func(func), _no(no) {}
    thread start()
    {
        thread t(_func, _no); // _func(_no)
        return t;
    }
private:
    function<void(int)> _func;
    int _no;
};

class ThreadPool
{
public:
    ThreadPool() {}
    ~ThreadPool()
    {
        for (int i = 0; i < _pool.size(); ++i)
        {
            delete _pool[i];
        }
    }
    void startPool(int size)
    {
        for (int i = 0; i < size; ++i)
        {
            _pool.push_back(
                    new Thread(bind(&ThreadPool::runInThread, this, _1), i));
        }

        for (int i = 0; i < size; ++i)
        {
            _handler.push_back(_pool[i]->start());
        }

        for (thread &t : _handler)
        {
            t.join();
        }
    }
private:
    vector<Thread*> _pool;
    vector<thread> _handler;

    //线程不能接收成员方法函数
    //
    void runInThread(int id)
    {
        cout << "call runInThread! id:" << id << endl;
    }
};