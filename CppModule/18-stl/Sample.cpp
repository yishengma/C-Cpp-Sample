//
// Created by 海盗的帽子 on 2020/6/1.
//

#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>

class Student {
public:
    Student(){

    }
    int age;
};

//谓词，按照特定规则所编写的函数
bool compare(const Student &left, const Student &right) {
    return left.age > right.age;
}

//函数对象
struct comparefuction {
    //函数重载了（）运算符，函数对象，仿函数
};

//int main() {
//    std::vector<int> v;
//    v.insert(v.begin(), 12);
//    v.insert(v.end(), 21);
//    for (int i = 0; i < v.size(); ++i) {
//        std::cout << v[i] << std::endl;
//        std::cout << v.at(i) << std::endl;
//    }
//
//    for (std::vector<int>::iterator it; it != v.end(); it++) {
//        std::cout << (*it) << std::endl;
//    }
//
//
//    v.front() = 33;//引用当左值
//
//
//    //并不支持角标插入获取值
//    //也没有迭代器
//    std::stack<int> s;
//    s.push(11);
//    s.push(22);
//    s.push(33);
//
//    while (!s.empty()) {
//        s.pop();
//    }
//
//
//    //队列
//    std::queue<int> q;
//    q.push(11);
//    q.push(22);
//    q.push(33);
//
//    while (!q.empty()) {
//        q.pop();
//        q.back();
//    }
//
//    //优先级队列
//    std::priority_queue<int> pq;
//
//
//
//    //list,链表
//    std::list<int> l;
//    l.push_back(11);
//    l.push_front(22);
//
//    l.erase(l.begin());
//
//    l.back() = 33;
//
//    for (std::list<int>::iterator it; it != l.end(); it++) {
//        std::cout << (*it) << std::endl;
//    }
//
//    //set(红黑树，会对你存入的数据进行排序，但是不允许元素相同)
//
//    std::set<int> st;
//    std::set<int, std::less<int>> st1;
//    st.insert(1);
//
//    //返回两个参数
////    std::pair<std::set<int,std::greater<int>>>
//
//
//    std::map<int, std::string> m;
//    m.insert(std::pair<int, std::string>(01, "01"));
//    m[1] = "01";
//    for (std::map<int, std::string>::iterator i = m.begin(); i != m.end(); i++) {
//
//    }
//    for (auto i = m.begin();i != m.end();i++) {
//
//    }
//
//    //查找
//    auto i = m.find(01);
//    if (i!=m.end()) {
//        std::cout << "" << std::endl;
//    }
//
//
//    //一多的数据
//    std::multimap<int,std::string> mm;
//    mm.insert(std::pair<int,std::string>(1,"11"));
//    mm.insert(std::pair<int,std::string>(1,"22"));
//    mm.insert(std::pair<int,std::string>(1,"33"));
//
//    auto mi = mm.find(1);
//    if (mi != mm.end()) {
//
//
//    }
//

//    std::cout << "放进集合：" << s1.age << std::endl;
//
//}

int main() {
    //容器对象的拷贝构造函数
    //在java 中是把对象添加到集合

    //在c++ 会调用对象的拷贝构造函数，存进入的是另一个对象
    //第一个错误：没有默认的构造函数
    //第二个错误：需要进行深拷贝，否则会多次调用析构函数造成问题
    std::vector<Student> ss;
    Student student;
    student.age = 100;
    ss.insert(ss.begin(),student);//调用的是拷贝构造函数
    student.age = 200;
    Student s1 = *ss.begin();
    std::cout << s1.age << std::endl;
}