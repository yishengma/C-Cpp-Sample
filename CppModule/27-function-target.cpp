//
// Created by 海盗的帽子 on 2020/6/17.
//

/**
 C++ 绑定器和函数对象

 bind function
 c++ STL bind1st 和 bind2nd

 function ： 绑定器，函数对象，lambda表达式，只能使用在一条语句
 作用：
 - 保留

 */

#include <iostream>
#include <map>

using namespace std;

void hello1() {
    cout << "hello1" << endl;
}

void hello2(string str) {
    cout << "hello2" << str << endl;
}

class Test {
public:
    void hello(string str) {
        cout << "Test" << str << endl;
    }
};

int main() {

    //从 function的类模版定义处，看到希望用一个函数类型实例化
    function<void()> func = hello1;
    func();


    function<void(string)> func2 = hello2;
    func2("aaaa");

    function<void(Test *, string)> func3 = &Test::hello;
    Test *test = new Test();
    func3(test, "sss");

}

void addOne() {};

void addTwo() {};

void addThree() {};

void addFour() {};

void test_func() {
    int choice = 0;

    //不支持开闭原则
//    while (true) {
//        cin >> choice;
//        switch (choice) {
//            case 1:
//                break;
//            case 2:
//                break;
//            case 3:
//                break;
//            case 4:
//                break;
//        }
//    }

    map<int, function<void()>> actionMap;
    actionMap.insert({1, addOne});
    actionMap.insert({2, addTwo});
    actionMap.insert({3, addThree});
    actionMap.insert({4, addFour});

    switch (true) {
        cin >> choice;
        auto it = actionMap.find(choice);
        if (it == actionMap.end()) {

        }else {
            //第二个参数
            it->second();
        }
    }

}