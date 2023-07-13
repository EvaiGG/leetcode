#include <iostream>
#include <chrono>
#include <thread>

class Repl{
public:
    void asyncOperation(std::function<void()> callback );

};


void Repl::asyncOperation(std::function<void()> callback) {

    std::this_thread::sleep_for(std::chrono::seconds(10));

    callback();
}

void handleAsyncOperation() {
    std::cout<< "异步操作完成" << std::endl;
}

int main(){
    Repl repl;
    repl.asyncOperation([](){
        handleAsyncOperation();
    });

    std::cout<< "主线程执行其它操作" << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(2));
}
