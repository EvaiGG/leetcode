//
// Created by Tony on 2023/4/11.
//
#include "iostream"
#include <cstdlib>
#include "string"
#include "vector"
#include "algorithm"
#include "map"
#include "stack"

using namespace std;
template<typename t1, typename t2>
class day6_solution {
public:
    t1 first;
    t2 second;

    t1 add(t1 &first );

    //1147
    int longestDecomposition(string text) {
        int len = text.size();
        if (len == 0) return 0;
        for (int i = 0; i <= len/2; ++i) {
            if(text.substr(0,i) == text.substr(len-i)) {
                return 2+ longestDecomposition(text.substr(i, len-i*2));
            }
        }
        return 1;
    }
    vector<vector<int>> minPathMemo;

    //64
    int minPathSum(vector<vector<int>> &grid) {
        int height = grid.size();
        int width = grid[0].size();

        for (int i = 1; i < height; ++i) {
            grid[i][0] += grid[i-1][0];
        }
        for (int i = 1; i < width; ++i) {
            grid[0][i] += grid[0][i-1];
        }

        for (int i = 1; i < height ; ++i) {
            for (int j = 1; j < width; ++j) {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[height-1][width-1];

    }

    //2404
    int mostFrequentEven(vector<int> &nums) {
//        sort(nums.begin(),  nums.end());
        map<int, int> bucket;
//        if(nums[0] %2 == 0) bucket[nums[0]] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] %2 == 0 ) {
                bucket[nums[i]] +=1;
            }
//            if (nums[i] %2 == 0 && bucket.count(nums[i]) == 0){
//                bucket[nums[i]] = 1;
//            }
        }
//        std::stack<int> stk;
//        if (bucket.size() == 0) return -1;
//        stk.push(bucket[0]);
//        for (int i = 1; i < bucket.size(); ++i) {
//            if (bucket[i] >= stk.top()) {
//                stk.push(bucket[i]);
//            }
//        }
//
//        int maxV = stk.top();
//        for (const auto &item : bucket){
//            if (item.second == maxV) return item.first;
//        }
        int res = -1,ct = 0;
        for (const auto &item : bucket){
            if (res == -1 || item.second >ct || item.second == ct && res > item.first) {
                res = item.first;
                ct = item.second;
            }
        }
        return res;
    }

    // 121_maxprofit
    int maxProfit(vector<int>& prices) {
        // 暴力超时
//        vector<int> v;
//        for(int i =0; i<prices.size()-1; i++) {
//            int idx = prices[i];
//            for(int j = i+1; j< prices.size(); j++) {
//                if(prices[j] > idx){
//                    idx = prices[j];
//                }
//            }
//            if(idx != prices[i]) v.push_back(idx - prices[i]);
//        }
//        if(v.size() == 0) return 0;
//        sort(v.begin(), v.end());
//        return v[v.size()-1];
//      遍历时考虑当日与历史最低价格的受益
        int inf = 0x3f3f3f3f;
        int minprice = inf, maxprofix = 0;
        for (int i = 0; i < prices.size(); ++i) {
            maxprofix = max(maxprofix,prices[i] - minprice);
            minprice = min (minprice, prices[i]);
        }
        return maxprofix;
    }
};

template<typename t1, typename t2>
t1 day6_solution<t1, t2>::add(t1 &first) {
    return first;
}

int main () {
    day6_solution<std::string , std::int64_t > solu;
//    solu.first = "sweeter";
//    solu.second = 90;
//    std::string res = solu.add(solu.first);
//    std::cout << res << std::endl;

//    vector<vector<int>> t = {{1,2,3}, {4,5,6}, {7,8,9}};
//    solu.minPathSum(t);

//    vector<int> t {0,1,2,2,4,4,1};
    vector<int> t {7,6,4,3,1};
//    int res = solu.mostFrequentEven(t);
    int res = solu.maxProfit(t);
    cout << res << endl;
}
