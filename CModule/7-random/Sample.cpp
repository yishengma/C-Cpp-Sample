//
// Created by 海盗的帽子 on 2020/5/29.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    //随机数每次运行随机数都一样，解决的方式的初始化随机数发生器
    //使用的场景，在c层生层密钥

    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        printf("%d\n", rand() % 100);
    }
}