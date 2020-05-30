//
// Created by 海盗的帽子 on 2020/5/30.
//

//通过指针赋值的意义

//1.通过方法修改值
//2.间接赋值


#include <cstdlib>

//c和java的方法不同所在，c 可以传对象的地址在方法离里面去赋值，java 一般都是通过返回值
void change_num(int* p) {
    *p = 300;
}

//野指针：访问一个已销毁或者访问受限的内存区域的指针，野指针不能判断是否为NULL来避免
typedef struct Person{

};

int wild_pointer() {
   Person* person = (Person*)malloc(sizeof(Person));

   if (person){
       free(person);
       person = NULL;
   }

    //...
    //如果上面的person没有置为 null
    //就变为野指针
    if (person){
        free(person);
    }
}

//NULL 地址
int void_pointer() {
    char* p = NULL;
    //指针指向 NULL ,表示指针指向0x00000000
    //这个地方并不能操作，是c和c++ 编译器持有的
}

int main() {
    int num = 100;
    num = 200;
    int* p = &num;
    *p = 300;

    change_num(&num);

}