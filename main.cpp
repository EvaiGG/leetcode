#include <iostream>
#include "stack"
using namespace std;
void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}
void swapp(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool canWinNim(int n) {
    return n%4 != 0;
}
int main() {
//    int a = 5, b  =9;
//    swap(a, b);
//    cout << a<< endl;
//    swapp(&a, &b);
//    cout << a << endl;

    stack<int> stk;
    for (int i = 0; i < 10; ++i) {
        stk.push(i);
    }
    int cnt = 0;
    int proxy;
    while(stk.top() > 5 ) {
        cout << "cnt = " << cnt << endl;
        proxy = stk.top();
        stk.pop();
    }
    return 0;
}
