//
// Created by Tony on 2023/6/8.
//

#ifndef LEETCODE_MUTEXDEMO_H
#define LEETCODE_MUTEXDEMO_H

#include <mutex>
#include <thread>
#include <iostream>

class MutexDemo {

public:
   static std::mutex mtx; // 静态互斥锁

   void operator()(const std::string &msg);
};


#endif //LEETCODE_MUTEXDEMO_H
