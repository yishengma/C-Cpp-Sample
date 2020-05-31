//
// Created by 海盗的帽子 on 2020/5/31.
#include <stdarg.h>

void sum(int count, ...) {
    va_list vp;
    va_start(vp, count);
    int number = va_arg(vp,int);
    va_end(vp);
}

int main() {

}
