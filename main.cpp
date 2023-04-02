#include <iostream>
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
int main() {
    int a = 5, b  =9;
    swap(a, b);
    cout << a<< endl;
    swapp(&a, &b);
    cout << a << endl;
    return 0;
}
