#include <vector>
#include <iostream>
#include <numeric>
#include <unordered_set>
#include <set>
#include <unordered_map>

using namespace std;

class f14_solution {
public:

    vector<vector<int>> res;
    vector<int> temp;

    vector<vector<int>> combine(int n, int k) {
        dfs(0, 1, n, k);
        return res;
    }
    /**
     * 回溯所有的组合
     * @param begin [1,n] 子字符串开头的数字
     * @param index 子字符串的第index个数字
     * @param n
     * @param k
     */
    void dfs(int begin, int index, int n, int k) {
        if (temp.size() == k) {
            res.push_back(temp);
            return;
        }

        for (int i = index; i <= n; ++i) {
            if (i > begin) {
                temp.push_back(i);
                dfs(i, i + 1, n, k);
                temp.pop_back();
            }
        }
    }

    /**
     * 1052 老板生气会引起顾客生气，反之满意 求最大满意量
     * @param customers  顾客数组 i项表示书店开店第i分钟 进来的人数量
     * @param grumpy 老板的情绪数组  为1时生气
     * @param minutes 可控制老板连续minutes内 不生气
     * @return 客户最大满意量
     */
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int maxS = 0;
        //
        for (int i = 0; i < customers.size(); ++i) {
            if (grumpy[i] == 0) {
                maxS += customers[i];
                customers[i] = 0; // 添加过后 赋值为0 方便后续不添加情绪判断 循环过后就只有老板生气的时刻有顾客
            }
        }

//        // 让minutes这个时间窗口 在customers中滑动 比较每个时间段里面控制情绪挽单最大量
//        if(minutes >= customers.size())
//            return accumulate(customers.begin(),  customers.end(), 0);
        int temp = 0; // minute 区间
        int left = 0;
        int maxV = 0; // 最大区间值

        for (int right = 0; right < customers.size(); ++right) {
            temp += customers[right];
            if (right - left + 1 == minutes) {
                maxV = max(maxV, temp);
                temp -= customers[left++];
            }
        }

        return maxV + maxS;
    }

    /**
     * 2475. 数组中不等三元组的数目

     * @param nums
     * @return
     */
    int unequalTriplets(vector<int>& nums) {
        std::unordered_map<int,std::vector<int>> iMap; // 对于索引i 左边比他小的数的数量 右边比他大的数的数量
        int n = nums.size();
        int result = 0;
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i+1; j < n-1; ++j) {
                if (nums[i] != nums[j]) {
                    for (int k = j+1; k < n; ++k) {
                        if (nums[i] != nums[k] && nums[k] != nums[j] ) result ++;
                    }
                }
            }
        }

        return result;
    }
};


int main() {

    f14_solution solu;
//    auto res =  solu.combine(5,4);
//    for (const auto &vec: res) {
//        for (const auto &item: vec) {
//            cout << item << "\t";
//        }
//        cout << "\n";
//    }
//    vector<int> t({1});
//    vector<int> grumpy({0});
//
//    auto result = solu.maxSatisfied(t, grumpy, 1);
//    cout << result << endl;

    vector<int> t1({4,4,2,4,3});
    vector<int> t2({1,1,1,1,1});

    int result = solu.unequalTriplets(t1);
    cout << result << endl;
}