//
// Created by 海盗的帽子 on 2020/5/30.
//
#include <stdio.h>

int main() {
    //数据类型的本质:一块连续大小的内存空间

    int a;
    int arr[6] = {1, 2, 3, 4, 5, 6};

    //0x80   0x84  0x80  0x98(0x80+0x18(即24))
    printf("%p,%p,%p,%p", arr, arr + 1, &arr, &arr + 1);


    //基本数据类型的别名
//    int16_t -> short
//    int32_t -> int
//    int64_t -> long long
//    int8_t -> signed char

//    u_int16_t -> unsigned short
//    u_int32_t -> unsigned int
//    u_int64_t -> unsigned long long
//    u_int8_t -> unsigned char

//void * 代表任意的数据类型的指针

//变量的本质：固定内存块大小的别名，通过变量可以操作一块内存上的数据


}
