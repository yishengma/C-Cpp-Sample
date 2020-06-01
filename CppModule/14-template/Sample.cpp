//
// Created by 海盗的帽子 on 2020/6/1.
//

int add(int num1, int num2) {
    return num1 + num2;
}

double add(double num1, double num2) {
    return num1 + num2;
}

//当普通函数和模板函数同时存在的时候，优先会调用普通函数
float add(float num1, float num2) {
    return num1 + num2;
}

//模版函数
template<typename T>
T add(T num1, T num2) {
    return num1 + num2;
}

//so是很难被反编译，比java安全
//1.编译的时候，c和c++编译器会对 cpp ,c 文件做一些优化（模板函数）
//2.java 有small -> class ，也会生成c/c++ 能够认识的一套代码
//3.链接 obj , .等文件，链接其他模板 cmake 中的链接
//4.最会就会生成 .dll , .so .exe 文件



template<class T>
class Callback{
public:
    void onError(){

    }

    void onSucceed(T result){

    }
};

class HttpCallback : public Callback<int> {

};

template<class T>
class HttpsCallback : public Callback<T> {

};

int main() {
    HttpsCallback<int>* callback = new HttpsCallback<int>();
    callback->onError();
}