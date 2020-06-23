//
// Created by 海盗的帽子 on 2020/6/23.
//
#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

//系统理论CAS来保证上面++ -- 操作原子特性就足够
//exchange/swap
std::atomic_int aCount(0);
std::atomic_bool isReady(false);


