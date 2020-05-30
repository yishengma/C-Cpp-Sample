//
// Created by 海盗的帽子 on 2020/5/30.
//

//程序运行的流程
//1.操作系统把物理硬盘的代码load到内存
//2.加载到内存后会把c代码分成4个区
//3.然后系统会找到main 函数的入口去执行

//四驱模型
//1.栈区：由编译器自动分配，存放一些局部变量值和函数，这个里面内存是会自动进行回收的
//2.对区：内存手动开辟和释放，malloc free new delete
//3.全局区：静态的一些常量，字符串等
//4.程序代码区：存放函数体的二进制代码

#include <cstring>
#include <cstdlib>

char* getStr1() {
    char* str = "123";//"123" 存放在全局区，str 存放 "123" 的地址
    return str;
}

char* getStr2() {
    char* str2 = "345";
    return str2;
}

char* getStr3() {
    char buffer[128];//buffer 存放的是 "123" 的内容，不是地址，方法结束后释放
    strcpy(buffer,"123");
    return buffer;
}

char* getStr4() {
    char* buff = (char *)malloc(128);//"123" 存放在堆中，buff 存放的是 "123" 首地址
    strcpy(buff,"123");
    return buff;
}

int main() {


}