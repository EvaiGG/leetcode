//
// Created by Tony on 2023/4/16.
//

#include "vector"

using namespace std;

class MajorityChecker{

public:
    vector<int> arr;
    int n;

    MajorityChecker(vector<int> &arr){
//        this->arr = arr;
        this->n = arr.size();
        for (int i = 0; i < n; ++i) {
            this->arr.push_back(arr[i]);
        }
    }

    int query(int left, int right, int threshold) {
        int i, j, k;
        j = k = 0;
        for ( i = left; i <= right; i++) {
            if (this->arr[i] == j) {
                k++;
            }
            else if (k) {
                k--;
            }
            else {
                j = this->arr[i];
                k = 1;
            }
        }

        for ( i = left, k = 0; i <= right ; i++) {
            if (k < threshold) j =-1;
        }
        return j;
    }
};
