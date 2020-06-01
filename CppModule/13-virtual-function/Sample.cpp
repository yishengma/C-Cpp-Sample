//
// Created by 海盗的帽子 on 2020/6/1.
//
#include <iostream>
//跟java 的抽象类一个概念
class BaseActivity {
public:
    //普通函数
    void startActivity(){
        initView();
        initData();
    }
    //子类需要继承的
    //类似Java中的抽象方法
    //纯虚函数
    virtual void initData() = 0;
    virtual void initView() = 0;
};

class MainActivity : public BaseActivity {
public:
    void initData() {
        std::cout<<"MainActivity initData"<<std::endl;
    }

    void initView() {
        std::cout<<"MainActivity initView"<<std::endl;
    }
};

//所有的函数都是虚函数，那么就可以认为是接口
class ClickListener {
public:
    virtual void onClick() = 0;
};

class ImageClickListener : public ClickListener {
    void onClick() override {
      std::cout << "ImageClickListener" << std::endl;
    }
};

//类回调
void click(ClickListener* clickListener){
    clickListener->onClick();
};

//函数指针
void click(void print()){
    print();
};

int main() {
    //回调可以用，
    //函数指针作为回调
    //纯虚函数累进行回调
    ClickListener* listener = new ImageClickListener();
    listener->onClick();

    //构造函数顺序：父类-》子类
    //析构函数顺序：子类-》父类
}