#include <vector>
#include <algorithm>
#include <queue>
#include <mutex>

using namespace std;

class f13_solution {
public:

    /**
     * 计算老鼠之间每一块起司的差值 排序
     * 先让鼠二全部吃掉起司， 然后吐出排序好的起司。 让鼠一吃掉 计算累积和
     * @param reward1 鼠一吃掉cheese对应的奖励
     * @param reward2 鼠二吃掉cheese对应的奖励
     * @param k
     * @return
     */
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        int mice_2_eat = 0;
        std::vector<int> gap(n, 0);
        for (int i = 0; i < n ; ++i) {
            gap[i] = reward1[i]-reward2[i];
            mice_2_eat += reward2[i];
        }

        sort(gap.begin(),  gap.end());

        for (int i = 0; i < k; ++i) {
            mice_2_eat += gap[--n];
        }
        return  mice_2_eat;
    }
};




template <class E>
class BlockingQueue {

private:
    queue<E> _queue;
    int capacity = INT_MAX;
    condition_variable takeVariable, putVariable;
    mutable mutex lock;

public:
    BlockingQueue();
    /**
     *
     * @param capacity 队列允许的最大值,在put时size()大于此值时,put方法将会wait
     */
    BlockingQueue(int capacity);
    /**
     * size() == 0 时会阻塞
     * @param e
     * @return -1失败, 0成功
     */
    int take(E &e);
    /**
     * size >= capacity时会阻塞
     * @param e
     * @return
     */
    int put(const E &e);

    bool empty() const;

    unsigned int size() const;

    void pop();

    E back();

    E front();
};

template <class E>
BlockingQueue<E>::BlockingQueue() {
}

template <class E>
BlockingQueue<E>::BlockingQueue(int capacity) : capacity(capacity) {
}

template <class E>
int BlockingQueue<E>::take(E &e) {
    unique_lock<mutex> uniqueLock(lock);
    while (_queue.empty()) {
        takeVariable.wait(uniqueLock);
    }
    if (_queue.empty()) return -1;
    e = _queue.front();
    _queue.pop();
    putVariable.notify_one();
    return 0;
}

template <class E>
int BlockingQueue<E>::put(const E &e) {
    unique_lock<mutex> uniqueLock(lock);
    while (_queue.size() >= capacity) {
        putVariable.wait(uniqueLock);
    }
    if (_queue.size() >= capacity) return -1;
    _queue.push(e);
    takeVariable.notify_one();
    return 0;
}

template <class E>
bool BlockingQueue<E>::empty() const {
    lock_guard<mutex> lockGuard(lock);
    return _queue.empty();
}

template <class E>
unsigned int BlockingQueue<E>::size() const {
    lock_guard<mutex> lockGuard(lock);//利用变量作用域创建加锁,析构自动解锁
    return _queue.size();
}

template <class E>
void BlockingQueue<E>::pop() {
    lock.lock();
    _queue.pop();
    lock.unlock();
}

template <class E>
E BlockingQueue<E>::back() {
    lock_guard<mutex> lockGuard(lock);
    return _queue.back();
}

template <class E>
E BlockingQueue<E>::front() {
    lock_guard<mutex> lockGuard(lock);
    return _queue.front();
}
class FooBar {
private:

    int n=0;
    BlockingQueue<int> fooinput;
    BlockingQueue<int> barinput;


public:
    ~FooBar(){

    }
    FooBar(int n) {
        this->n = n;

    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < n; i++) {
            int res=0;
            barinput.take(res);
            printFoo();
            fooinput.put(0);
        }
    }

    void bar(function<void()> printBar) {

        for (int i = 0; i < n; i++) {


            barinput.put(0);
            int res=0;
            fooinput.take(res);
            printBar();
        }

    }
};


int main(){

}