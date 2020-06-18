//
// Created by 海盗的帽子 on 2020/6/18.
//
#include <iostream>
using namespace std;
/**
 模版的完全特例化和非（部分）完成模版的实参推演

 */

template<typename T>
bool compare(T a,T b) {

}

//上述模版的完全特例化，因为const char* 类型是确定的
template<>
bool compare(const char* a,const char* b) {

}

template<typename T>
class Vector{
public:
    Vector() {}
};

//对char* 类型的完全特例化版本
template<>
class Vector<char*> {
public:
    Vector() {}
};

//针对指针类型的部分特例化版本
template<typename Tp>
class Vector<Tp*>{
public:
    Vector() {}
};

//有两个变量的函数指针的部分特例化
template<typename  R,typename A,typename B>
class Vector<R(*)(A,B)> {
public:
    Vector() {}
};

//函数类型的部分特例化
template<typename  R,typename A,typename B>
class Vector<R(A,B)> {
public:
    Vector() {}
};

//注意区分函数类型和函数指针类型



//模版的实参推演
//模板的实参推演
template<typename T>
void func(T a) {
    cout << typeid(a).name() << endl;
}

