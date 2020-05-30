//
// Created by 海盗的帽子 on 2020/5/30.
//

#include <cstring>


//不要直接去修改方法传递的指针
void get(const char * str) {

}
int main() {
    char buff[] = {'1','1','1','1','1'};
    char* buff1 = "11111";
    //区别
    //1.char buff[]:会拷贝数据到栈中
    //2.char* 指向其他区域，不拷贝



    int len = strlen(buff);
    int size = sizeof(buff);
}