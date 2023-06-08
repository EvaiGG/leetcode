//
// Created by Tony on 2023/6/8.
//

#include "MutexDemo.h"


//std::mutex mtx;
std::mutex MutexDemo::mtx;
void MutexDemo::operator()(const std::string &msg) {
    std::lock_guard<std::mutex> lock(mtx); // 开始上锁 确保公共资源自由一个线程访问 这里是io流
    std::cout << msg << std::endl;
    // 离开作用域后自动释放
}

int main() {

    MutexDemo md;

    std::string msg = "hello";
    std::thread t1(md, msg);
    std::thread t2(md, "world");
    t1.join();
    t2.join();

    return 0;
}





