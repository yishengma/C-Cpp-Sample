//
// Created by 海盗的帽子 on 2020/6/16.
//

#include <ostream>
#include <iostream>
using namespace std;
class Text {
public:



    Text(int ma = 10) : ma(ma) {
        cout << "Test " << ma << "普通构造函数" << endl;
    }

    virtual ~Text() {
        cout << "Test " << ma << "析构函数" << endl;
    }

    Text(const Text& text):ma(text.ma) {
        cout << "Test " << ma << "拷贝函数" << endl;
    }

    Text& operator = (const Text& text) {
        cout << "Test " << ma << "赋值函数" << endl;
    }


private:
    int ma;
};


int main() {

    Text t1;
    cout << "------------" << endl;
    Text t2(t1);
    cout << "------------" << endl;
    Text t3 = t1;//这里不是赋值，而是拷贝
    cout << "------------" << endl;
    //显示生成临时对象,临时对象的生成周期为所在语句
    //和Text(40)没有区别
    //C++编译器对于对象的构造的优化，用临时对象生成新对象的时候
    //临时对象就不产生了，直接构造新对象就可以了，
    Text t4 = Text(20);
    cout << "------------" << endl;


    t4 = t2;
    cout << "------------" << endl;
    //t4 已经存在，这个临时对象就会产生
    //先构造，再赋值构造，析构
    t4 = Text(40);
    cout << "------------" << endl;

    //int -> Text(int)
    //同上
    t4 = (Text)30;
    cout << "------------" << endl;
    //int -> Text(int)
    //同上
    //隐式生成临时对象
    t4 = 30;


    //这里不能用一个指针保存临时对象
//    Text *p = &(Text(40));
//    Text &ref = Text(50);
    const Text &ret = Text(50);
    //只能读，不能写


}
