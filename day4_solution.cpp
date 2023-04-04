//
// Created by Tony on 2023/4/4.
//
#include<stdio.h>
#include <stdlib.h>
#include "iostream"
#include <vector>

using namespace std;
class day4_solution{
    static constexpr int inf = 0x3f3f3f3f;
    std::vector<std::vector<std::vector<int>>> memory;
    std::vector<int> sum;
    int k;
public:

    int dfs(int l, int r , int t) {
        // 记忆数组里面有这个值
        if (memory[l][r][t] != -1) return memory[l][r][t];
        // r到l 的数量少于t堆
        if(t > r - l +1) return inf;
        if (t == 1) {
            int temp = dfs(l, r, k);
            // 划分为子问题中 和本次合并的成本
            return  memory[l][r][t] = temp + (sum[r] - (l == 0? 0: sum[l-1]));
        }
        int val = inf;
        // 合并连续的k堆 所以每次p 进k-1 位
        for (int p = l; p < r ; p+=(k-1)) {
            val = min(val, dfs(l,p,1) + dfs(p+1, r, t-1));
        }
        return memory[l][r][t] = val;

    }
    int mergeStones(std::vector<int> stones, int k){
        int n = stones.size();
        if ((n-1) % (k-1) != 0) return -1;
        this -> k = k;
        memory = vector(n, vector(n, vector(k+1, -1)));
        sum = vector <int> (n, 0);

        for (int i = 0, s = 0; i < n ; ++i) {
            memory[i][i][1] = 0;
            s += stones[i];
            sum[i] = s;
        }
        int res = dfs(0, n-1, 1);
        return res;
    }


};





int main() {
    day4_solution solution;
    vector<int> v = {3,5,1,2,6};
    int res = solution.mergeStones(v, 3 );
    cout << res << endl;
}