//
// Created by 海盗的帽子 on 2020/6/1.
//

#include <cstring>
#include <string>
#include <iostream>
int main() {
    std::string str1 = "123";
    std::string str2("ADf");

    for (int i = 0; i < str1.length(); ++i) {
        std::cout<<str1[i]<<std::endl;
    }

    //拼接
    std::string str3 = str1 + str2;

    //拼接
    str1.append(str2);

    //删除
    str1.erase(0);//删除

    //遍历删除，删除一个后都会从头开始计算
    for (std::string::iterator it = str1.begin();it < str1.begin()+3;it++) {

    }

    //字符串的替换
    str1.replace(0,0,"");

    //查找，
    int pos = str1.find("find",0);
    int pos1 = str1.rfind("find");

    //大小写转换
    //transform(str1.begin(),str1.end(),tolower);

}
