//
// Created by Tony on 2023/4/6.
//

#include "string"
#include "iostream"
#include "vector"

using namespace std;
class day5_solution{

public:
    string baseNeg2(int n){
        if (n == 0 || n == 1) {
            return to_string(n);
        }
        string res;
        while (n != 0) {
            int remainder =n & 1;
            res.push_back('0' + remainder);
            n -= remainder;
            n /= -2;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    vector<int> numMovesStonesII(vector<int>& stones) {
        int n = stones.size();
        sort(stones.begin(), stones.end());
        if (stones.back() - stones[0] + 1 == n) {
            return {0, 0};
        }
        int ma = max(stones[n - 2] - stones[0] + 1, stones[n - 1] - stones[1] + 1) - (n - 1);
        int mi = n;
        for (int i = 0, j = 0; i < n && j + 1 < n; ++i) {
            while (j + 1 < n && stones[j + 1] - stones[i] + 1 <= n) {
                ++j;
            }
            if (j - i + 1 == n - 1 && stones[j] - stones[i] + 1 == n - 1) {
                mi = min(mi, 2);
            } else {
                mi = min(mi, n - (j - i + 1));
            }
        }
        return {mi, ma};
    }
};



int main() {
    day5_solution *solution = new day5_solution;
    string res = solution->baseNeg2(9);
    cout << res << endl;
}