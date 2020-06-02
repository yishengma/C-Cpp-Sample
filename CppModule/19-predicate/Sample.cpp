//
// Created by 海盗的帽子 on 2020/6/2.
//
#include <set>
#include <vector>

class Compare {
public:
    //函数对象，仿函数：重载了 （） 运算符，一元谓词

    void operator()(int a) {

    }
};

//谓词：符合一定规定的函数，有几个参数就是几元谓词
//一元谓词
void print(int num) {

}

//回调函数和仿函数的区别


//二元谓词

//
void test() {
    std::vector<int> vec ;
    vec.push_back(11);
}

int main() {
    std::set<int> set1;
    set1.insert(12);

    //for_each 迭代器非常重要的一点，仿函数如果要保存记录，可以用返回值
    std::for_each(set1.begin(),set1.end(),Compare());
    std::for_each(set1.begin(),set1.end(),print);
}