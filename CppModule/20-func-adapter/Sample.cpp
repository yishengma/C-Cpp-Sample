//
// Created by 海盗的帽子 on 2020/6/2.
//

#include <iostream>
#include <set>
#include <vector>
#include <functional>
//预定函数对象和函数适配器
//

class Equal{
private:
    int equal_number;
public:
    Equal(int equal_number){
        this->equal_number = equal_number;
    };
public:
    bool operator() (const int& num) {
        return num == equal_number;
    }
};
int main() {
    //less 就是预定好的函数对象
    //常见的 less greater plus equals_to
    //
    std::set<std::string,std::less<std::string>> s;

    //函数适配器，将两个参数进行绑定

    std::vector<int> v;
    v.push_back(11);
    v.push_back(12);
    v.push_back(13);
    v.push_back(14);

    int cout = count_if(v.begin(),v.end(),Equal(2));
    std::cout << cout << std::endl;


    //函数适配器
     cout = count_if(v.begin(),v.end(),bind2nd(std::equal_to<int>(),2));


}