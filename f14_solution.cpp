#include <vector>
#include <iostream>
#include <numeric>
#include <unordered_set>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

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
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes) {
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
    int unequalTriplets(vector<int> &nums) {
        std::unordered_map<int, std::vector<int>> iMap; // 对于索引i 左边比他小的数的数量 右边比他大的数的数量
        int n = nums.size();
        int result = 0;
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                if (nums[i] != nums[j]) {
                    for (int k = j + 1; k < n; ++k) {
                        if (nums[i] != nums[k] && nums[k] != nums[j]) result++;
                    }
                }
            }
        }

        return result;
    }

    /**
     * 532.数组中的k-diff对数量 k-diff: 数组中两个索引对应元素绝对值为k 则构成一个k-diff 对
     * @param nums
     * @param k
     * @return
     */
    int findPairs(vector<int> &nums, int k) {
//        int n = nums.size();
//        sort(nums.crbegin(),  nums.crend());
//
//        std::vector<int> dpStack;
//        for (int i = n-1; i >1 ; --i) {
//            if (nums[i] != nums[i-1]) {
//                dpStack.push_back(nums[i] - nums[i-1]);
//            }
//        }
//
//        int z = static_cast<int>(dpStack.size());
//        int res = 0;
//        for (int i = 0; i < z; ++i) {
//            int temp = 0;
//            for (int j = i+1; j < z; ++j) {
//                temp += dpStack[j];
//                if(temp > k) {
//                    break;
//                } else if(temp == k) {
//                    res +1;
//                }
//            }
//        }
//
//        return res +1;
        std::unordered_set<int> visited;
        std::unordered_set<int> diff_arr;

        for (const int &num: nums) {
            if (visited.count(num - k))
                diff_arr.emplace(num - k);
            if (visited.count(num + k))
                diff_arr.emplace(num);

            visited.emplace(num);
        }

        return diff_arr.size();
    }


    /**
     * 1254-dfs
     * @param grid
     * @return
     */
    int closedIsland(std::vector<std::vector<int>> &grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();

        function<bool(int, int)> dfs = [&](int x, int y) -> bool {
            if (x < 0 || y < 0 || x >= m || y >= n) {
                return false;
            }

            if (grid[x][y] != 0)
                return true;
            grid[x][y] = -1;
            bool ret1 = dfs(x - 1, y);
            bool ret2 = dfs(x + 1, y);
            bool ret3 = dfs(x, y - 1);
            bool ret4 = dfs(x, y + 1);
            return ret1 && ret2 && ret3 && ret4;
        };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0 && dfs(i, j)) {
                    ans++;
                }
            }
        }
        return ans;
    };


};


std::vector<int> build_next(const char* partern) {
    std::vector<int> next;
    next.push_back(0);

    int prefix_len = 0; //  当前位置最大前缀长度
    int i = 1;
    while (i < strlen(partern)) {
        if (partern[i] == partern[prefix_len]) {
            prefix_len += 1;
            next[i] = prefix_len;
            i += 1;
        } else {
            if (prefix_len == 0) {
                next[i] = 0;
                i += 1;
            } else {
                prefix_len = next[prefix_len - 1];
            }
        }

    }
    return next;
}

/**
 * KMP 匹配字符串
 * @param pattern
 * @param text
 * @return
 */
int kmpSearch(const char* pattern, const char* text) {
    int M = strlen(pattern);
    int N = strlen(text);

    int i = 0, j  = 0;
    std::vector<int> next =  build_next(pattern);
    while (i < N) {
        if (text[i] == pattern[j]) {
            i++, j++;
        } else if (j > 0) {
            j = next[j-1];
        } else {
            i+= 1;
        }
        if( j == M) return i-j;
    }

    return 0;

}

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

//    vector<int> t1({4, 4, 2, 4, 3});
//    vector<int> t2({1, 1, 1, 1, 1});
//
//    int result = solu.unequalTriplets(t1);
//    cout << result << endl;

    std::vector<int> res =  build_next("abcxabcdffffdffff");
    for (const auto &item : res){
        std::cout<< item << "-." ;
    }
}