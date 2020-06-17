//
// Created by 海盗的帽子 on 2020/6/17.
//

/**
 绑定器和函数对象 operator()
 1.C++ STL中绑定器
 bind1st : operator() 的第一个形参绑定成一个确定的值
 bind2nd : operator() 的第二个形参绑定成一个确定的值

 2.c++11 从Boost 库中引入bind 绑定器和 function 函数对象机制

 3.lambda 表达式底层依赖函数对象的机制实现的
 */

#include <iostream>
#include <vector>

using namespace std;

template<typename Container>
void showContainer(Container &con) {
    //typename 告知 Container 是个类型
    typename Container::iterator it = con.begin();
    for (; it != con.end(); it++) {
        cout << *it << "\"";
    }
    cout << endl;

}

int main() {
    vector<int> vec;
    srand(time(nullptr));
    for (int i = 0; i < 20; ++i) {
        vec.push_back(rand() % 100 + 1);
    }
    showContainer(vec);
    sort(vec.begin(), vec.end());
    showContainer(vec);

    //greator 是一个二元函数对象
    //大到小排序
    sort(vec.begin(), vec.end(), greater<int>());
    showContainer(vec);

    //把 70 按顺序插入 vec 容器中
    //需要绑定器
    //绑定器+一个二元函数对象=一个一元函数对象

    auto it = find_if(vec.begin(), vec.end(), bind1st(greater<int>(), 70));
    if (it != vec.end()) {
        vec.insert(it, 70);
    }
    showContainer(vec);

}

template<typename Iterator, typename Compare>
Iterator find_iff(Iterator first, Iterator last, Compare compa) {
    for (; first != last; first++) {
        if (compa(*first)) {
            return first;
        }
    }
    return last;
}

template<typename Compare, typename T>
class _bingd1st{
public:
    _bingd1st(Compare comp, T val) : _comp(comp), _val(val) {

    }

    bool operator()(const T &second) {
        return _comp(_val,second);
    }

private:
Compare _comp;
T _val;

};

template<typename Compare, typename T>
_bingd1st<Compare,T> bind1stt(Compare comp,const T &val) {
    return _bingd1st<Compare,T>(comp,val);
}
