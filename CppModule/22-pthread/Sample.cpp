//
// Created by 海盗的帽子 on 2020/6/10.
//

#include <pthread.h>
#include <zconf.h>
#include <iostream>

void *thread(void *ptr) {
    for (int i = 0; i < 3; ++i) {
        sleep(1);
        std::cout << "this is a pthread" << std::endl;
    }
}



int main () {
    pthread_t id;//一个线程的标识符
    //第一个参数为指向线程标识符的指针
    //第二个参数用来设置线程属性，
    //第三个参数是线程运行函数的起始地址
    //最后一个参数是运行函数的参数。
    //函数thread不需要参数，所以最后一个参数设为空指针。
    //第二个参数我设为空指针，这样将生成默认属性的线程。
    //对线程属性的设定和修改我们将在下一节阐述。
    //当创建线程成功时，函数返回0，若不为0则说明创建线程失败
    //常见的错误返回代码为EAGAIN和EINVAL。
    // 前者表示系统限制创建新的线程，例如线程数目过多了；
    // 后者表示第二个参数代表的线程属性值非法。
    //
     int ret = pthread_create(&id,NULL,thread,NULL);
    if (ret) {
        std::cout << "Create pthread error" << std::endl;
    }
    for (int i = 0; i < 3; ++i) {
        std::cout << "this is the main process" << std::endl;
    }
    //轻进程可以理解为内核线程，它位于用户层和系统层之间。
    // 系统对线程资源的分配、对线程的控制是通过轻进程来实现的，
    // 一个轻进程可以控制一个或多个线程。默认状况下，
    // 启动多少轻进程、哪些轻进程来控制哪些线程是由系统来控制的，
    // 这种状况即称为非绑定的。绑定状况下，则顾名思义，
    // 即某个线程固定的"绑"在一个轻进程之上。
    // 被绑定的线程具有较高的响应速度，
    // 这是因为CPU时间片的调度是面向轻进程的，
    // 绑定的线程可以保证在需要的时候它总有一个轻进程可用。
    // 通过设置被绑定的轻进程的优先级和调度级可以使得绑定的
    // 线程满足诸如实时反应之类的要求。

    //设置线程绑定状态的函数为pthread_attr_setscope，
    // 它有两个参数，第一个是指向属性结构的指针，第二个是绑定类型，
    // 它有两个取值：PTHREAD_SCOPE_SYSTEM（绑定的）
    // 和PTHREAD_SCOPE_PROCESS（非绑定的）

    pthread_join(id,NULL);
}